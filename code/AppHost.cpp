#include "stdafx.h"
#include "Product\\UI\\WinHostEx.h"
#include "Product\\UI\\LikeMainFrame.h"
#include "Product\\UI\\GdiPlusPaintEx.h"
#include "Product\\UI\\UIXmlEx.h"
#include "Product\\UI\\WindowEx.h"
#include "Product\\Script\FaceCatScript.h"
#include "Product\\Service\\DataCenter.h"

LikeMainFrame *m_xml2 = 0;
WinHostEx *m_host2 = 0;
HWND m_hWnd2 = 0;
FCNative *m_native2 = 0;

double m_scaleFator = 1.0;

extern "C" __declspec(dllexport) int setScaleFactor(double scaleFactor){
	m_scaleFator = scaleFactor;
	return 1;
}

FCSize getClientSize2()
{
	FCRect rect;
	::GetClientRect(m_hWnd2, &rect);
	FCSize size = {rect.right - rect.left, rect.bottom - rect.top};
	return size;
}

extern "C" __declspec(dllexport) int createNative(HWND hWnd){

	DataCenter::startService();
	if(!m_native2){
		m_native2 = new FCNative;
		m_hWnd2 = hWnd;
		m_xml2 = new LikeMainFrame(m_hWnd2);
		m_xml2->setNative(m_native2);
		m_native2 = m_xml2->getNative();
		m_native2->setResourcePath(FCTran::stringToString(FCTran::getAppPath()) + L"\\config\\like");
		GdiPlusPaintEx *gdiPlusPaint = new GdiPlusPaintEx;
		m_native2->setPaint(gdiPlusPaint);

		WinHostEx *host = new WinHostEx;
		host->setNative(m_native2);
		m_native2->setHost(host);
		host->setHWnd(hWnd);
		m_native2->setAllowScaleSize(true);
		m_host2 = host;
		m_xml2->setScaleFactor(m_scaleFator);
		m_xml2->resetScaleSize(getClientSize2());
		m_native2->update();

		m_xml2->load(FCTran::stringToString(FCTran::getAppPath()) + L"\\config\\like\\MainFrameAlike.xml");
	}else{
		m_hWnd2 = hWnd;
		m_host2->setHWnd(hWnd);
		m_host2->reStartTimers();
		m_native2->update();
	}
	return 0;
}

extern "C" __declspec(dllexport) int onMessage(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam){
	if(hWnd != m_hWnd2){
		m_hWnd2 = hWnd;
		if(m_host2){
			m_host2->setHWnd(hWnd);
		}
	}
	if(message == WM_MOUSEWHEEL)
	{
		int delta = (int)wParam;
		if (m_host2->isKeyPress(VK_CONTROL))
		{
			double scaleFactor = m_xml2->getScaleFactor();
			if (delta > 0)
			{
				if (scaleFactor > 0.3)
				{
					scaleFactor -= 0.05;
				}
			}
			else if (delta < 0)
			{
				if (scaleFactor < 5)
				{
					scaleFactor += 0.05;
				}
			}
			m_xml2->setScaleFactor(scaleFactor);
			m_xml2->resetScaleSize(getClientSize2());
			::UpdateWindow(hWnd);
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
	}
	else if(message == WM_SETCURSOR)
	{
		if((int)lParam == 33554433)
		{
			return 1;
		}
	}
	switch (message)
	{
	case WM_SIZE:
		{    
			if (m_xml2)
            {
				FCSize clientSize = getClientSize2();
				m_xml2->resetScaleSize(clientSize);
				::UpdateWindow(hWnd);
            }
			break;
		}
	default:
		int handle = 0;
		if(m_xml2)
		{
			handle = m_xml2->wndProc(hWnd, message, wParam, lParam);
		}
		return handle;
	}
	return 0;
}

extern "C" __declspec(dllexport) int exportToImage(const char *path){
	m_native2->exportToImage(FCTran::stringToString(path));
	return 0;
}

extern "C" __declspec(dllexport) int callFunction(const char *cmd){
	String strCmd = FCTran::stringToString(cmd);
	if(strCmd.find(L"setstyle:") == 0){
		GdiPlusPaintEx *gdiPlusPaintEx = (GdiPlusPaintEx*)m_native2->getPaint();
		int style = FCTran::strToInt(strCmd.substr(strCmd.find(L":") + 1));
		gdiPlusPaintEx->m_myColor->setStyle(style);
		m_native2->update();
		m_native2->invalidate();
	}else if(strCmd.find(L"reversecolor:") == 0){
		int reverseColor = FCTran::strToInt(strCmd.substr(strCmd.find(L":") + 1));
		MyColor::setReverseColor(reverseColor);
		m_native2->update();
		m_native2->invalidate();
	}else if(strCmd.find(L"setzoom:") == 0){
		int delta = FCTran::strToInt(strCmd.substr(strCmd.find(L":") + 1));
		double scaleFactor = m_xml2->getScaleFactor();
		if (delta > 0)
		{
			if (scaleFactor > 0.3)
			{
				scaleFactor -= 0.05;
			}
		}
		else if (delta < 0)
		{
			if (scaleFactor < 5)
			{
				scaleFactor += 0.05;
			}
		}
		m_xml2->setScaleFactor(scaleFactor);
		m_xml2->resetScaleSize(getClientSize2());
	}else if(strCmd.find(L"setfont:") == 0){
		String sysFont = strCmd.substr(strCmd.find(L":") + 1);
		MyColor::setSystemFont(sysFont);
		FCNative::addChangeID();
		m_native2->update();
		m_native2->invalidate();
	}
	return 0;
}

extern "C" __declspec(dllexport) int startCloudPaint(){
	GdiPlusPaintEx *gdiPlusPaintEx = (GdiPlusPaintEx*)m_native2->getPaint();
	gdiPlusPaintEx->m_useCloud = true;
	gdiPlusPaintEx->m_cloudInfos.clear();
	gdiPlusPaintEx->m_startTime = ::GetTickCount();
	m_host2->setAllowPartialPaint(false);
	string cachePath = FCTran::getAppPath() + "\\data\\cache\\temp.nss";
	if(FCFile::isFileExist(cachePath.c_str())){
		FCFile::removeFile(cachePath.c_str());
	}
	return 0;
}

extern "C" __declspec(dllexport) int endCloudPaint(){
	GdiPlusPaintEx *gdiPlusPaintEx = (GdiPlusPaintEx*)m_native2->getPaint();
	String lastStr;
	String cachePath = FCTran::stringToString(FCTran::getAppPath() + "\\data\\cache\\temp.nss");
	for(int i = 0; i < (int)gdiPlusPaintEx->m_cloudInfos.size(); i++){
		CloudInfo &ci = gdiPlusPaintEx->m_cloudInfos[i];
		String str = ci.m_type + L"¡ò" + ci.m_color + L"¡ò" + ci.m_font + L"¡ò" +
			ci.m_str + L"¡ò"+ FCTran::intToStr(ci.m_lineWidth) + L"¡ò" + 
			FCTran::intToStr(ci.m_param1) + L"¡ò" + FCTran::intToStr(ci.m_param2)
			+ L"¡ò" + FCTran::intToStr(ci.m_param3) + L"¡ò" + FCTran::intToStr(ci.m_param4) + L"¨‘";
		if(lastStr != str){
			FCFile::append(cachePath.c_str(), str);
		}
		lastStr = str;
	}
	m_host2->setAllowPartialPaint(true);
	gdiPlusPaintEx->m_useCloud = false;
	gdiPlusPaintEx->m_cloudInfos.clear();
	return 0;
}

