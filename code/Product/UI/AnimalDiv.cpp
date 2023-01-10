#include "..\\..\\stdafx.h"
#include "AnimalDiv.h"
#include "..\\..\\CurlHttp.h"
#include "..\\..\\json\\json.h"
#include "..\\Service\\DataCenter.h"
#include "GdiPlusPaintEx.h"

static const std::string base64_chars =
"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
"abcdefghijklmnopqrstuvwxyz"
"0123456789+/";

static inline bool is_base64(const char c)
{
    return (isalnum(c) || (c == '+') || (c == '/'));
}

std::string base64_encode(const char * bytes_to_encode, unsigned int in_len)
{
    std::string ret;
    int i = 0;
    int j = 0;
    unsigned char char_array_3[3];
    unsigned char char_array_4[4];
    
    while (in_len--)
    {
        char_array_3[i++] = *(bytes_to_encode++);
        if(i == 3)
        {
            char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
            char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
            char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
            char_array_4[3] = char_array_3[2] & 0x3f;     
            for(i = 0; (i <4) ; i++)
            {
                ret += base64_chars[char_array_4[i]];
            }
            i = 0;
        }
    }
    if(i)
    {
        for(j = i; j < 3; j++)
        {
            char_array_3[j] = '\0';
        }
        
        char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
        char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
        char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
        char_array_4[3] = char_array_3[2] & 0x3f;
        
        for(j = 0; (j < i + 1); j++)
        {
            ret += base64_chars[char_array_4[j]];
        }
        
        while((i++ < 3))
        {
            ret += '=';
        }
        
    }
    return ret;
}

std::string base64_decode(std::string const & encoded_string)
{
    int in_len = (int) encoded_string.size();
    int i = 0;
    int j = 0;
    int in_ = 0;
    unsigned char char_array_4[4], char_array_3[3];
    std::string ret;
    
    while (in_len-- && ( encoded_string[in_] != '=') && is_base64(encoded_string[in_])) {
        char_array_4[i++] = encoded_string[in_]; in_++;
        if (i ==4) {
            for (i = 0; i <4; i++)
                char_array_4[i] = base64_chars.find(char_array_4[i]);
            
            char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
            char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
            char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];
            
            for (i = 0; (i < 3); i++)
                ret += char_array_3[i];
            i = 0;
        }
    }
    if (i) {
        for (j = i; j <4; j++)
            char_array_4[j] = 0;
        
        for (j = 0; j <4; j++)
            char_array_4[j] = base64_chars.find(char_array_4[j]);
        
        char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
        char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);  
        char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];  
        
        for (j = 0; (j < i - 1); j++) ret += char_array_3[j];  
    }  
    return ret;  
}

// libcurl库下载链接：https://curl.haxx.se/download.html
// jsoncpp库下载链接：https://github.com/open-source-parsers/jsoncpp/
// 获取access_token所需要的url
const std::string access_token_url = "https://aip.baidubce.com/oauth/2.0/token?grant_type=client_credentials";
// 回调函数获取到的access_token存放变量
// static std::string access_token_result;
/**
 * curl发送http请求调用的回调函数，回调函数中对返回的json格式的body进行了解析，解析结果储存在result中
 * @param 参数定义见libcurl库文档
 * @return 返回值定义见libcurl库文档
 */
static size_t callback2(void *ptr, size_t size, size_t nmemb, void *stream) {
    // 获取到的body存放在ptr中，先将其转换为string格式
    std::string s((char *) ptr, size * nmemb);
    // 开始获取json中的access token项目
    Json::Reader reader;
    Json::Value root;
    // 使用boost库解析json
    reader.parse(s,root);
    std::string* access_token_result = static_cast<std::string*>(stream);
    *access_token_result = root["access_token"].asString();
    return size * nmemb;
}

/**
 * 用以获取access_token的函数，使用时需要先在百度云控制台申请相应功能的应用，获得对应的API Key和Secret Key
 * @param access_token 获取得到的access token，调用函数时需传入该参数
 * @param AK 应用的API key
 * @param SK 应用的Secret key
 * @return 返回0代表获取access token成功，其他返回值代表获取失败
 */
int get_access_token(std::string &access_token, const std::string &AK, const std::string &SK) {
    CURL *curl;
    CURLcode result_code;
    int error_code = 0;
    curl = curl_easy_init();
    if (curl) {
        std::string url = access_token_url + "&client_id=" + AK + "&client_secret=" + SK;
        curl_easy_setopt(curl, CURLOPT_URL, url.data());
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0);
        std::string access_token_result;
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &access_token_result);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, callback2);
        result_code = curl_easy_perform(curl);
        if (result_code != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(result_code));
            return 1;
        }
        access_token = access_token_result;
        curl_easy_cleanup(curl);
        error_code = 0;
    } else {
        fprintf(stderr, "curl_easy_init() failed.");
        error_code = 1;
    }
    return error_code;
}

const static std::string request_url = "https://aip.baidubce.com/rest/2.0/image-classify/v1/animal";
static std::string animal_result;

/**
 * curl发送http请求调用的回调函数，回调函数中对返回的json格式的body进行了解析，解析结果储存在全局的静态变量当中
 * @param 参数定义见libcurl文档
 * @return 返回值定义见libcurl文档
 */
static size_t callback(void *ptr, size_t size, size_t nmemb, void *stream) {
    // 获取到的body存放在ptr中，先将其转换为string格式
    animal_result = std::string((char *) ptr, size * nmemb);
    return size * nmemb;
}

/**
 * 动物识别
 * @return 调用成功返回0，发生错误返回其他错误码
 */
int animal(std::string &json_result, const std::string &access_token) {
    std::string url = request_url + "?access_token=" + access_token;
    CURL *curl = NULL;
    CURLcode result_code;
    int is_success;
    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.data());
        curl_easy_setopt(curl, CURLOPT_POST, 1);
		curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0);
        curl_httppost *post = NULL;
        curl_httppost *last = NULL;
				string imgPath = DataCenter::getAppPath() + "\\cat.jpg";
		HANDLE hFile = CreateFile(FCTran::stringToString(imgPath).c_str(), GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

		if (hFile == INVALID_HANDLE_VALUE)
		{
			return false;
		}

		DWORD dFileSize = GetFileSize(hFile, NULL);
		char * pBuffer = new char[dFileSize + 1];

		if(pBuffer == NULL){
			return false;
		}

		memset(pBuffer, 0, dFileSize);

		DWORD dReadSize(0);
		if (!ReadFile(hFile, pBuffer, dFileSize, &dReadSize, NULL))
		{
			delete[]pBuffer;
			CloseHandle(hFile);
			return false;
		}

		string imgBase64 = base64_encode((const char*)pBuffer, dReadSize);

		delete[]pBuffer;
	    CloseHandle(hFile);
		
		curl_formadd(&post, &last, CURLFORM_COPYNAME, "image", CURLFORM_COPYCONTENTS, imgBase64.c_str(), CURLFORM_END);

        curl_easy_setopt(curl, CURLOPT_HTTPPOST, post);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, callback);
        result_code = curl_easy_perform(curl);
        if (result_code != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(result_code));
            is_success = 1;
            return is_success;
        }
        json_result = animal_result;
        curl_easy_cleanup(curl);
        is_success = 0;
    } else {
        fprintf(stderr, "curl_easy_init() failed.");
        is_success = 1;
    }
    return is_success;
}

// libcurl库下载链接：https://curl.haxx.se/download.html
// jsoncpp库下载链接：https://github.com/open-source-parsers/jsoncpp/
const static std::string request_url3 = "https://aip.baidubce.com/rest/2.0/image-classify/v1/body_analysis";
static std::string body_analysis_result;
/**
 * curl发送http请求调用的回调函数，回调函数中对返回的json格式的body进行了解析，解析结果储存在全局的静态变量当中
 * @param 参数定义见libcurl文档
 * @return 返回值定义见libcurl文档
 */
static size_t callback3(void *ptr, size_t size, size_t nmemb, void *stream) {
    // 获取到的body存放在ptr中，先将其转换为string格式
    body_analysis_result = std::string((char *) ptr, size * nmemb);
    return size * nmemb;
}
/**
 * 人体关键点识别
 * @return 调用成功返回0，发生错误返回其他错误码
 */
int body_analysis(std::string &json_result, const std::string &access_token) {
    std::string url = request_url3 + "?access_token=" + access_token;
    CURL *curl = NULL;
    CURLcode result_code;
    int is_success;
    curl = curl_easy_init();
    if (curl) {
		curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0);
        curl_easy_setopt(curl, CURLOPT_URL, url.data());
        curl_easy_setopt(curl, CURLOPT_POST, 1);

        curl_httppost *post = NULL;
        curl_httppost *last = NULL;
		string imgPath = DataCenter::getAppPath() + "\\cat.jpg";
		HANDLE hFile = CreateFile(FCTran::stringToString(imgPath).c_str(), GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

		if (hFile == INVALID_HANDLE_VALUE)
		{
			return false;
		}

		DWORD dFileSize = GetFileSize(hFile, NULL);
		char * pBuffer = new char[dFileSize + 1];

		if(pBuffer == NULL){
			return false;
		}

		memset(pBuffer, 0, dFileSize);

		DWORD dReadSize(0);
		if (!ReadFile(hFile, pBuffer, dFileSize, &dReadSize, NULL))
		{
			delete[]pBuffer;
			CloseHandle(hFile);
			return false;
		}

		string imgBase64 = base64_encode((const char*)pBuffer, dReadSize);

		delete[]pBuffer;
	    CloseHandle(hFile);
		
        curl_formadd(&post, &last, CURLFORM_COPYNAME, "image", CURLFORM_COPYCONTENTS, imgBase64.c_str(), CURLFORM_END);

        curl_easy_setopt(curl, CURLOPT_HTTPPOST, post);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, callback3);
        result_code = curl_easy_perform(curl);
        if (result_code != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(result_code));
            is_success = 1;
            return is_success;
        }
        json_result = body_analysis_result;
        curl_easy_cleanup(curl);
        is_success = 0;
    } else {
        fprintf(stderr, "curl_easy_init() failed.");
        is_success = 1;
    }
    return is_success;
}

DWORD WINAPI startSearch(LPVOID lpParam){
	AnimalDiv *animalDiv = (AnimalDiv*)lpParam;
	/*string accesstoken;
	string jsonResult;
	get_access_token(accesstoken, "DzwGZxIqln5qklWbiHYW0Fnz", "lD1NO0ETGzYIoERGp6V0AYr3urZshGnU");  
	body_analysis(jsonResult, accesstoken);
	vector<FCPoint> points;
	int idx = jsonResult.find("\"y\":");
	while(true){
		int nIndex = jsonResult.find(",", idx);
		FCPoint point;
		string strY = jsonResult.substr(idx + 4, nIndex - idx - 4);
		nIndex = jsonResult.find(",", nIndex + 1);
		idx = jsonResult.find("\"x\":");
		string strX = jsonResult.substr(idx + 4, nIndex - idx - 4);
		int b = 0;
	}*/
	::Sleep(3000);
	animalDiv->m_searchState = 2;
	return 0;
}

AnimalDiv::AnimalDiv(){
	setBorderColor(FCColor_None);
	m_searchState = 0;
	m_tick = 0;
	m_timerID = FCView::getNewTimerID();
}

AnimalDiv::~AnimalDiv(){
}

void AnimalDiv::onAdd(){
	string appPath = FCTran::getAppPath();
	String wAppPath = FCTran::stringToString(appPath);
	setResourcePath(wAppPath);
	getNative()->getPaint()->setSmoothMode(1);
	getNative()->getPaint()->setTextQuality(1);
	startTimer(m_timerID, 10);
}

void AnimalDiv::onPaint(FCPaint *paint, const FCRect& clipRect){
	GdiPlusPaintEx *gdiPlusPaintEx = (GdiPlusPaintEx*)paint;
	FCNative *native = getNative();
	int width = getWidth(), height = getHeight();
	FCRect drawRect = {0, 0, width, height};
	paint->drawImage(L"cats\\cat5.jpg", drawRect);
	if(m_searchState < 2){
		int nSize = 150, nTop = 100;
		String str = L"开始识别";
		int r = 80, g = 255, b = 80;
		if(m_searchState == 1){
			str = L"识别中...";
			r = 255, g = 80, b = 80;
		}
		FCRect eRect = {(width - nSize) / 2, height - nSize - 50, (width + nSize) / 2, height - 50};
		paint->fillGradientEllipse(FCColor::rgba(r, g, b, 150), FCColor::rgba(255, 255, 255, 100), eRect, 45);
		paint->drawEllipse(FCColor::rgba(r, g, b, 200), 1, 0, eRect);
		FCFont tFont(L"微软雅黑", 30, true, false, false);
		FCSize tSize = paint->textSize(str, &tFont, -1);
		FCRect tRect = {0};
		tRect.left = eRect.left + (nSize - tSize.cx) / 2;
		tRect.top = eRect.top + (nSize - tSize.cy) / 2;
		tRect.right = tRect.left + tSize.cx;
		tRect.bottom = tRect.top + tSize.cy;
		paint->drawText(str, FCColor::rgba(255, 255, 255, 255), &tFont, tRect, -1);
		if(m_searchState == 1){
			paint->fillPie(FCColor::rgba(r, g, b, 100), eRect, m_tick % 60 * 6, 30);
		}
	}else{
		String str = L"短毛家猫";
		FCFont tFont(L"微软雅黑", 40, true, false, false);
		
		FCSize tSize = paint->textSize(str, &tFont, -1);
		FCRect tRect = {0};
		tRect.left = (width - tSize.cx) / 2;
		tRect.top = 50;
		tRect.right = tRect.left + tSize.cx;
		tRect.bottom = tRect.top + tSize.cy;
		FCRect tRect2 = tRect;
		tRect2.left -= 4;
		tRect2.top -= 4;
		tRect2.right += 4;
		tRect2.bottom += 4;
		int a = 0, r = 0, g = 0, b = 0;
		FCColor::toRgba(paint, m_finalColor, &r, &g, &b, &a);
		paint->fillRoundRect(FCColor::rgba(r, g, b, 200), tRect2, 4);
		paint->drawRoundRect(FCColor::rgba(255, 255, 255, 100), 1, 0, tRect, 4);
		paint->drawRoundRect(FCColor::rgba(255, 255, 255, 100), 1, 0, tRect2, 4);
		paint->drawText(str, FCColor::rgba(255, 255, 255, 255), &tFont, tRect, -1);

		FCSize sSize = {0};
		FCFont sFont(L"微软雅黑", 24, true, false, false);
		FCRect hRect4 = {-50, height * 2 / 3 - 200, width + 100, height * 2 / 3 + 40 - 200};
		gdiPlusPaintEx->m_g->RotateTransform(45);
		gdiPlusPaintEx->m_g->TranslateTransform(100, 0);
		paint->fillRect(FCColor::rgba(r, g, b, 200), hRect4);
		String sText3 = L"价格1000-3000元";
		sSize = paint->textSize(sText3, &sFont, -1);
		FCRect sRect4 = {hRect4.left + (width - sSize.cx) / 2 + 120, hRect4.top + (40 - sSize.cy) / 2, hRect4.left + (width + sSize.cx) / 2 + 120, hRect4.top + (40 + sSize.cy) / 2};
		paint->drawText(sText3, FCColor::rgba(255, 255, 255, 255), &sFont, sRect4, -1);
		gdiPlusPaintEx->m_g->ResetTransform();
	}
}

void AnimalDiv::onTouchDown(FCTouchInfo touchInfo){
	m_searchState = 1;
	HANDLE hThread = ::CreateThread(0, 0, startSearch, (LPVOID)this, 0, NULL);
	CloseHandle(hThread);
	Long colors[6] = {0};
	colors[0] = FCColor::rgba(246, 187, 67, 200);
	colors[1] = FCColor::rgba(140, 192, 81, 200);
	colors[2] = FCColor::rgba(150, 123, 220, 200);
	colors[3] = FCColor::rgba(75, 137, 220, 200);
	colors[4] = FCColor::rgba(170, 178, 189, 200);
	colors[5] = FCColor::rgba(59, 174, 218, 200);
	m_finalColor = colors[3];
}

void AnimalDiv::onTimer(int timerID){
	if(m_timerID == timerID){
		if(m_searchState > 0){
			invalidate();
		}
		m_tick++;
		if(m_tick > 100000){
			m_tick = 0;
		}
	}
}