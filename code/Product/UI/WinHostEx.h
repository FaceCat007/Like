/*��������èFaceCat��� v1.0
�Ϻ����è��Ϣ�������޹�˾
 */

#ifndef __WINHOSTEX_H__
#define __WINHOSTEX_H__
#pragma once
#include "..\\..\\stdafx.h"
#include "RibbonButton.h"
#include "GdiPlusPaintEx.h"

/*
* ������ť
*/
class ScrollButtonM : public FCButton{
public:
	/*
	* ��ͷ����
	*/
	int m_arrowType;
public:
	/*
	* ���캯��
	*/
    ScrollButtonM();
	/*
	* ��������
	*/
    virtual ~ScrollButtonM();
	/*
	* �ػ淽��
	* @param paint ��ͼ����
	* @param clipRect �ü�����
	*/
    virtual void onPaint(FCPaint *paint, const FCRect& clipRect);
	/*
	* �ػ���߷���
	* @param paint ��ͼ����
	* @param clipRect �ü�����
	*/
    virtual void onPaintBorder(FCPaint *paint, const FCRect& clipRect);
};

//�豸����
class WinHostEx : public WinHost{
public:
	bool m_loadMainFrame;
public:
	/*
	* ���캯��
	*/
	WinHostEx();
	/*
	* ��������
	*/
	virtual ~WinHostEx();
public:
	/*
	* �����ڲ��ؼ�
	* @param parent ����ͼ
	* @param clsid Ψһ���
	*/
	virtual FCView* createInternalView(FCView *parent, const String& clsid);
public:
	HashMap<int, int> m_timeIDs;
	/*
	* �������
	*/
	virtual void reStartTimers();
	/**
	* �������
	* @param timerID  ���ID
	* @param interval  ���
	*/
    virtual void startTimer(int timerID, int interval);
	/**
	* ֹͣ���
	* @param timerID  ���ID
	*/
    virtual void stopTimer(int timerID);
};
#endif