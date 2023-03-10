#include "stdafx.h"
#include "resource.h"
#include "Product\\UI\\WinHostEx.h"
#include "Product\\UI\\LikeMainFrame.h"
#include "Product\\UI\\GdiPlusPaintEx.h"
#include "Product\\UI\\UIXmlEx.h"
#include "Product\\UI\\WindowEx.h"
#include "Product\\Service\\DataCenter.h"
//#include "Product\\Service\\UpdateService.h"
//#ifndef ULONG_PTR  
//#define ULONG_PTR unsigned long
//#endif
#include "gdiplus.h"
#pragma comment(lib, "gdiplus.lib")
using namespace Gdiplus;

//AniMainFrame *m_aniMainFrame = 0;
LikeMainFrame *m_mainFrame = 0;
FCHost *m_host = 0;
HWND m_hWnd = 0;
FCNative *m_native = 0;
int m_type = 0;

HINSTANCE hInst;					     //实例句柄
// 此代码模块中包含的函数的前向声明:
ATOM			   MyRegisterClass(HINSTANCE hInstance);                 //注册窗口类
BOOL			   InitInstance(HINSTANCE, int);		         //初始化窗口各种控件
LRESULT CALLBACK   WndProc(HWND, UINT, WPARAM, LPARAM);                          //主窗口回调函数

//程序入口
int APIENTRY _tWinMain(HINSTANCE hInstance,
					   HINSTANCE hPrevInstance,
					   LPTSTR    lpCmdLine,
					   int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);
	std::locale::global(std::locale(""));
	MSG msg;
	CoInitialize(0);
	GdiplusStartupInput gdiplusStartupInput;
	ULONG_PTR gdiplusToken;
	GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, 0);
	MyRegisterClass(hInstance);
	// 执行应用程序初始化:
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}
	// 主消息循环:
	while (GetMessage(&msg, 0, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, 0, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
	CoUninitialize();
	GdiplusShutdown(gdiplusToken);
	return 0;
}

//注册窗口类
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(wcex);

	wcex.style			= CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;
	wcex.lpfnWndProc	= WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON1));
	wcex.hCursor		= LoadCursor(0, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName	= 0;
	wcex.lpszClassName  = L"iLike";
	wcex.hIconSm		= 0;

	return RegisterClassEx(&wcex);
}

FCSize GetClientSize()
{
	FCRect rect;
	::GetClientRect(m_hWnd, &rect);
	FCSize size = {rect.right - rect.left, rect.bottom - rect.top};
	return size;
}

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	HWND hWnd;
	hInst = hInstance; // 将实例句柄存储在全局变量中
	if(m_type == 0){
		hWnd = CreateWindow(L"iLike", L"AI+K线", WS_OVERLAPPEDWINDOW,
		  CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, 0, 0, hInstance, NULL);
	}else if(m_type == 1){
		hWnd = CreateWindow(L"iLike", L"AI+K线", WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, 450, 600, 0, 0, hInstance, NULL);
	}
	if (!hWnd)
	{
		return FALSE;
	}
	//CUpdate *cUpdate = new CUpdate;
	//cUpdate->run();
	m_hWnd = hWnd;
	if(m_type == 0){
		m_mainFrame = new LikeMainFrame(hWnd);
		m_mainFrame->createNative();
		m_native = m_mainFrame->getNative();
	}else if(m_type == 1){
		//m_aniMainFrame = new AniMainFrame(hWnd);
		//m_aniMainFrame->createNative();
		//m_native = m_aniMainFrame->getNative();
	}
	GdiPlusPaintEx *gdiPlusPaint = new GdiPlusPaintEx;
	m_native->setPaint(gdiPlusPaint);
	WinHost *host = new WinHostEx;
	host->setNative(m_native);
	m_native->setHost(host);
	host->setHWnd(hWnd);
	m_native->setAllowScaleSize(true);
	m_host = host;
	if(m_type == 0){
		m_mainFrame->resetScaleSize(GetClientSize());
	}else if(m_type == 1){
		//m_aniMainFrame->resetScaleSize(GetClientSize());
	}
	::UpdateWindow(m_hWnd);
	if(m_type == 0){
		string filePath = DataCenter::getAppPath() + "\\config\\like\\MainFrameAlike.xml";
		String wFilePath = FCTran::stringToString(filePath);
		m_mainFrame->load(wFilePath);
	}else if(m_type == 1){
		//string filePath = DataCenter::getAppPath() + "\\config\\LikeMainFrame.xml";
		//String wFilePath = FCTran::stringToString(filePath);
		//m_aniMainFrame->load(wFilePath);
	}
	ShowWindow(hWnd, SW_MAXIMIZE);
	UpdateWindow(hWnd);
	m_native->update();
	return TRUE;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	if(message == WM_MOUSEWHEEL)
	{
		int delta = (int)wParam;
		if (m_host->isKeyPress(VK_CONTROL))
		{
			double scaleFactor = m_mainFrame->getScaleFactor();
			if (delta > 0)
			{
				if (scaleFactor > 0.3)
				{
					scaleFactor -= 0.1;
				}
			}
			else if (delta < 0)
			{
				if (scaleFactor < 5)
				{
					scaleFactor += 0.1;
				}
			}
			if(m_type == 0){
				m_mainFrame->setScaleFactor(scaleFactor);
				m_mainFrame->resetScaleSize(GetClientSize());
			}else if(m_type == 1){
				//m_aniMainFrame->setScaleFactor(scaleFactor);
				//m_aniMainFrame->resetScaleSize(GetClientSize());
			}
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
		//处理关闭窗口的消息
	case WM_CLOSE:
		{
			m_mainFrame->exit();
			DataCenter::setAppAlive(false);
			DestroyWindow(hWnd);
			PostQuitMessage(0);
			break;
		}
	case WM_SIZE:
		{    
			if (m_host)
            {
				if(m_type == 0){
					m_mainFrame->resetScaleSize(GetClientSize());
				}else if(m_type == 1){
					//m_aniMainFrame->resetScaleSize(GetClientSize());
				}
				::UpdateWindow(hWnd);
            }
			break;
		}
	default:
		int handle = 0;
		if(m_type == 0){
			if(m_mainFrame)
			{
				handle = m_mainFrame->wndProc(hWnd, message, wParam, lParam);
			}
		}else if(m_type == 1){
			//if(m_aniMainFrame)
			//{
			//	handle = m_aniMainFrame->wndProc(hWnd, message, wParam, lParam);
			//}
		}
		if(handle == 0)
		{
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		else
		{
			return 1;
		}
	}
	return 0;
}