#include "stdafx.h"
#include "CStr.h"

String FCStrEx::convertThousands(double value, int digit){
	if(digit == 0){
		double newValue = FCTran::round(value);
		if(abs(newValue - value) < 1){
			value = newValue;
		}
	}
	wchar_t szValue[100] = {0};
	_stprintf_s(szValue, 99, L"%I64d", (Long)abs(value));
	String str = szValue;
	int strSize = (int)str.size();
	String result = L"";
	for(int i = 0; i < strSize; i++){
		result = str[strSize - i - 1] + result;
		if(i != strSize - 1 && (i > 0 && (i + 1) % 3 == 0)){
			result = L"," + result;
		}
	}
	if(value < 0){
		result = L"-" + result;
	}
	if(digit > 0){
		String dszValue = FCTran::getValueByDigit(value, digit);
		if((int)dszValue.find(L".") != -1){
			result += L"." + dszValue.substr((int)dszValue.find(L".") + 1);
		}
	}
	return result;
}

string FCStrEx::convertDBCodeToFileName(const string& code){
	string fileName = code;
	if (fileName.find(".") != -1){
        fileName = fileName.substr(fileName.find('.') + 1) + fileName.substr(0, fileName.find('.'));
    }
	fileName += ".txt";
	return fileName;
}

string FCStrEx::convertDBCodeToSinaCode(const string& code){
	string securityCode = code;
	int index = (int)securityCode.find(".SH");
    if (index > 0){
        securityCode = "sh" + securityCode.substr(0, securityCode.find("."));
    }
    else{
        securityCode = "sz" + securityCode.substr(0, securityCode.find("."));
    }
	return securityCode;
}

string FCStrEx::convertDBCodeToTencentCode(const string& code){
	string securityCode = code;
	int index = (int)securityCode.find(".");
	if(index > 0){
		index = (int)securityCode.find(".SH");
		if (index > 0){
			securityCode = "sh" + securityCode.substr(0, securityCode.find("."));
		}
		else{
			securityCode = "sz" + securityCode.substr(0, securityCode.find("."));
		}
	}
	return securityCode;
}

String FCStrEx::convertSinaCodeToDBCode(const String& code){
	int equalIndex = (int)code.find(L"=");
	int startIndex = (int)code.find(L"var hq_str_") + 11;
	String securityCode = equalIndex > 0 ?code.substr(startIndex, equalIndex - startIndex) : code;
	if ((int)securityCode.find(L"sh") == 0 || (int)securityCode.find(L"SH") == 0){
		securityCode = securityCode.substr(2) + L".SH";
	}
	else if ((int)securityCode.find(L"sz") == 0 || (int)securityCode.find(L"SZ") == 0){
		securityCode = securityCode.substr(2) + L".SZ";
	}
	return securityCode;
}

String FCStrEx::convertTencentCodeToDBCode(const String& code){
	int equalIndex = (int)code.find(L'=');
	String securityCode = equalIndex > 0 ? code.substr(0, equalIndex) : code;
	if ((int)securityCode.find(L"v_sh") == 0){
		securityCode = securityCode.substr(4) + L".SH";
	}
	else if ((int)securityCode.find(L"v_sz") == 0){
		securityCode = securityCode.substr(4) + L".SZ";
	}
	return securityCode;
}

String FCStrEx::getDBString(const String& strSrc){
	String str = FCTran::replace(strSrc, L"'", L"''");
	return str;
}

string FCStrEx::getGuid(){
	static char buf[64] = {0};
	GUID guid;
	if (S_OK == ::CoCreateGuid(&guid)){
		_snprintf(buf, sizeof(buf)
			, "{%08X-%04X-%04x-%02X%02X-%02X%02X%02X%02X%02X%02X}"
			, guid.Data1
			, guid.Data2
			, guid.Data3
			, guid.Data4[0], guid.Data4[1]
		, guid.Data4[2], guid.Data4[3], guid.Data4[4], guid.Data4[5]
		, guid.Data4[6], guid.Data4[7]
		);
	}
	return buf;
}

void FCStrEx::getFormatDate(double date, wchar_t *str){

	int year = 0,month = 0,day = 0,hour = 0,minute = 0,second = 0,msecond = 0;
	FCTran::getDateByNum(date, &year, &month, &day, &hour, &minute, &second, &msecond);
	_stprintf_s(str, 99, L"%d/%d/%d", year, month, day);
}

String FCStrEx::getFormatDate(const String& format, int year, int month, int day, int hour, int minute, int second){
	static wchar_t str[100] = {0};
	_stprintf_s(str, 99, format.c_str(), year, month, day, hour, minute, second);
	return str;
}

String FCStrEx::getFormatDate(const String& format, int year, int month, int day, int hour, int minute, int second, int msec){
	static wchar_t str[100] = {0};
	_stprintf_s(str, 99, format.c_str(), year, month, day, hour, minute, second, msec);
	return str;
}

int FCStrEx::getStringCapacity(const string& str){
	return (int)str.length() + 1 + sizeof(Long);
}

int FCStrEx::getWStringCapacity(const String& str){
	return ((int)str.length() + 1) * 2 + sizeof(Long);
}
