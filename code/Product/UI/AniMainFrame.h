/*��������èFaceCat��� v1.0 https://github.com/FaceCat007/facecat.git
 1.��ʼ��-�󶴳���Ա-�Ϻ����è��Ϣ�������޹�˾-����KOL-�յ� (΢�ź�:suade1984);
 2.���ϴ�ʼ��-�Ϻ����è��Ϣ�������޹�˾-����ϼ;
 3.�ó��򲻿�Դ����Ҫ�õ���Ȩ����ʹ�á�
 */

#ifndef __ANIMAINFRAME_H__
#define __ANIMAINFRAME_H__
#pragma once
#include "..\\..\\stdafx.h"
#include "GdiPlusPaintEx.h"
#include "UIXmlEx.h"
#include "WinHostEx.h"

using namespace FaceCat;
//���׿ؼ�
class AniMainFrame : public UIXmlEx{
public:
	WinHost *m_host;
	HWND m_hWnd;
	double m_scaleFactor;
	int m_timerID;
private:
	//��ť�������
	static void clickButton(void *sender, FCTouchInfo touchInfo, void *pInvoke);	
	//ע���¼�
	void registerEvents(FCView *control);
	//����¼�
	static void timerEvent(void *sender, int timerID, void *pInvoke);
public:
	AniMainFrame(HWND hWnd);
	virtual ~AniMainFrame();
	//��������
	double getScaleFactor();
	void setScaleFactor(double scaleFactor);
public:
	//�˳�
	void exit();
	//�����Ƿ�������ʾ
	bool isWindowShowing();
	//����Xml
	void load(const String& xmlPath);
	//��������
	virtual void loadData();
	//�������Ŵ�С
	void resetScaleSize(FCSize clientSize);
	//��ʾ��ʾ��
	int showMessageBox(const String& text, const String& caption, UINT uType);
	//��Ϣѭ��
	int wndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
public:
	//����¼�
	void onTimerEvent(void *sender, int timerID);
};
#endif