/*基于捂脸猫FaceCat框架 v1.0 https://github.com/FaceCat007/facecat.git
 1.创始人-矿洞程序员-上海卷卷猫信息技术有限公司-脉脉KOL-陶德 (微信号:suade1984);
 2.联合创始人-上海卷卷猫信息技术有限公司-周淋霞;
 3.该程序不开源，需要得到授权才能使用。
 */

#ifndef __ANIMAINFRAME_H__
#define __ANIMAINFRAME_H__
#pragma once
#include "..\\..\\stdafx.h"
#include "GdiPlusPaintEx.h"
#include "UIXmlEx.h"
#include "WinHostEx.h"

using namespace FaceCat;
//交易控件
class AniMainFrame : public UIXmlEx{
public:
	WinHost *m_host;
	HWND m_hWnd;
	double m_scaleFactor;
	int m_timerID;
private:
	//按钮点击方法
	static void clickButton(void *sender, FCTouchInfo touchInfo, void *pInvoke);	
	//注册事件
	void registerEvents(FCView *control);
	//秒表事件
	static void timerEvent(void *sender, int timerID, void *pInvoke);
public:
	AniMainFrame(HWND hWnd);
	virtual ~AniMainFrame();
	//缩放因子
	double getScaleFactor();
	void setScaleFactor(double scaleFactor);
public:
	//退出
	void exit();
	//窗体是否正在显示
	bool isWindowShowing();
	//加载Xml
	void load(const String& xmlPath);
	//加载数据
	virtual void loadData();
	//调整缩放大小
	void resetScaleSize(FCSize clientSize);
	//显示提示框
	int showMessageBox(const String& text, const String& caption, UINT uType);
	//消息循环
	int wndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
public:
	//秒表事件
	void onTimerEvent(void *sender, int timerID);
};
#endif