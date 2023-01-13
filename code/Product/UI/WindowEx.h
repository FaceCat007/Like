/*基于捂脸猫FaceCat框架 v1.0
上海卷卷猫信息技术有限公司
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
* 自定义窗体
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
	* 构造函数
	*/
    WindowEx();
	/*
	* 析构函数
	*/
    virtual ~WindowEx();
    /*
	*是否动画
	*/
    bool isAnimateMoving();
    /*
	* 关闭按钮
	*/
    WindowButton* getCloseButton();
    void setCloseButton(WindowButton* closeButton);
    /*
	* 是否子窗体
	*/
    bool isChildWindow();
    void setChildWindow(bool isChildWindow);
    /*
	* 最大化按钮
	*/
    WindowButton* getMaxOrRestoreButton();
    void setMaxOrRestoreButton(WindowButton *maxOrRestoreButton);
    /*
	* 最小化按钮
	*/ 
    WindowButton* getMinButton();
    void setMinButton(WindowButton *minButton);
	/*
	* 是否使用动画
	*/
	bool useAnimation();
	void setUseAnimation(bool useAnimation);
    /*
	* 窗体状态
	*/
    WindowStateA getWindowState();
    void setWindowState(WindowStateA windowState);
public:
    /*
	* 动画显示
	* @param showDialog 是否显示模态
	*/
    void animateShow(bool showDialog);
    /*
	* 最大化
	*/
    void maxOrRestore();
    /*
	* 最小化
	*/
    void minWindow();
    /*
	* 控件添加方法
	*/
    virtual void onAdd();
    /*
	* 拖动控件开始方法
	* @param startOffset 偏移量
	*/
    virtual void onDragReady(FCPoint *startOffset);
    /*
	* 重绘背景方法
	* @param paint 绘图对象
	* @param clipRect 裁剪区域
	*/
    virtual void onPaintBackground(FCPaint *paint, const FCRect& clipRect);
	/*
	* 秒表方法
	*/
	virtual void onTimer(int timerID);
    /*
	*控件布局更新方法
	*/
    virtual void update();
};
#endif
