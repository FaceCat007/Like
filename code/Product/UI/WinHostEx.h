/*基于捂脸猫FaceCat框架 v1.0
上海卷卷猫信息技术有限公司
 */

#ifndef __WINHOSTEX_H__
#define __WINHOSTEX_H__
#pragma once
#include "..\\..\\stdafx.h"
#include "RibbonButton.h"
#include "GdiPlusPaintEx.h"

/*
* 滚动按钮
*/
class ScrollButtonM : public FCButton{
public:
	/*
	* 箭头类型
	*/
	int m_arrowType;
public:
	/*
	* 构造函数
	*/
    ScrollButtonM();
	/*
	* 析构函数
	*/
    virtual ~ScrollButtonM();
	/*
	* 重绘方法
	* @param paint 绘图对象
	* @param clipRect 裁剪区域
	*/
    virtual void onPaint(FCPaint *paint, const FCRect& clipRect);
	/*
	* 重绘边线方法
	* @param paint 绘图对象
	* @param clipRect 裁剪区域
	*/
    virtual void onPaintBorder(FCPaint *paint, const FCRect& clipRect);
};

//设备中心
class WinHostEx : public WinHost{
public:
	bool m_loadMainFrame;
public:
	/*
	* 构造函数
	*/
	WinHostEx();
	/*
	* 析构函数
	*/
	virtual ~WinHostEx();
public:
	/*
	* 创建内部控件
	* @param parent 父视图
	* @param clsid 唯一编号
	*/
	virtual FCView* createInternalView(FCView *parent, const String& clsid);
public:
	HashMap<int, int> m_timeIDs;
	/*
	* 重启秒表
	*/
	virtual void reStartTimers();
	/**
	* 开启秒表
	* @param timerID  秒表ID
	* @param interval  间隔
	*/
    virtual void startTimer(int timerID, int interval);
	/**
	* 停止秒表
	* @param timerID  秒表ID
	*/
    virtual void stopTimer(int timerID);
};
#endif