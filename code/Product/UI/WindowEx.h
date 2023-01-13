/*��������èFaceCat��� v1.0
�Ϻ����è��Ϣ�������޹�˾
 */

#ifndef __WINDOWEX_H__
#define __WINDOWEX_H__
#pragma once
#include "..\\..\\stdafx.h"
#include "FCDraw.h"
#include "WindowButton.h"

enum WindowStateA{
    WindowStateA_Max,
    WindowStateA_Min,
    WindowStateA_Normal
};

/*
* �Զ��崰��
*/
class WindowEx : public FCWindow, public FCTouchEventCallBack{
private:
    int m_animateDirection;
    bool m_animateMoving;
    int m_animateType;
    WindowButton *m_closeButton;
    bool m_isChildWindow;
    WindowButton *m_maxOrRestoreButton;
    WindowButton *m_minButton;
    FCPoint m_normalLocation;
    FCSize m_normalSize;
	int m_tick;
    int m_timerID;
	bool m_useAnimation;
    WindowStateA m_windowState;
private:
    virtual void callTouchEvent(String eventName, Object sender, FCTouchInfo touchInfo, Object invoke);
public:
	/*
	* ���캯��
	*/
    WindowEx();
	/*
	* ��������
	*/
    virtual ~WindowEx();
    /*
	*�Ƿ񶯻�
	*/
    bool isAnimateMoving();
    /*
	* �رհ�ť
	*/
    WindowButton* getCloseButton();
    void setCloseButton(WindowButton* closeButton);
    /*
	* �Ƿ��Ӵ���
	*/
    bool isChildWindow();
    void setChildWindow(bool isChildWindow);
    /*
	* ��󻯰�ť
	*/
    WindowButton* getMaxOrRestoreButton();
    void setMaxOrRestoreButton(WindowButton *maxOrRestoreButton);
    /*
	* ��С����ť
	*/ 
    WindowButton* getMinButton();
    void setMinButton(WindowButton *minButton);
	/*
	* �Ƿ�ʹ�ö���
	*/
	bool useAnimation();
	void setUseAnimation(bool useAnimation);
    /*
	* ����״̬
	*/
    WindowStateA getWindowState();
    void setWindowState(WindowStateA windowState);
public:
    /*
	* ������ʾ
	* @param showDialog �Ƿ���ʾģ̬
	*/
    void animateShow(bool showDialog);
    /*
	* ���
	*/
    void maxOrRestore();
    /*
	* ��С��
	*/
    void minWindow();
    /*
	* �ؼ���ӷ���
	*/
    virtual void onAdd();
    /*
	* �϶��ؼ���ʼ����
	* @param startOffset ƫ����
	*/
    virtual void onDragReady(FCPoint *startOffset);
    /*
	* �ػ汳������
	* @param paint ��ͼ����
	* @param clipRect �ü�����
	*/
    virtual void onPaintBackground(FCPaint *paint, const FCRect& clipRect);
	/*
	* �����
	*/
	virtual void onTimer(int timerID);
    /*
	*�ؼ����ָ��·���
	*/
    virtual void update();
};
#endif
