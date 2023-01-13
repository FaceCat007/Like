/*基于捂脸猫FaceCat框架 v1.0
上海卷卷猫信息技术有限公司
 */

#ifndef __WINDOWBUTTON_H__
#define __WINDOWBUTTON_H__
#pragma once
#include "..\\..\\stdafx.h"
#include "FCDraw.h"

/*
* 窗体按钮样式
*/
enum WindowButtonStyle{
	/*
	* 关闭
	*/
    WindowButtonStyle_Close,
	/*
	* 最大化
	*/
    WindowButtonStyle_Max,
	/*
	* 最小化
	*/
    WindowButtonStyle_Min,
	/*
	* 恢复
	*/
    WindowButtonStyle_Restore
};

/*
* 窗体按钮
*/
class WindowButton : public FCButton{
private:
	/*
	* 是否圆形
	*/
    bool m_isEllipse;
	/*
	* 样式
	*/
    WindowButtonStyle m_style;
public:
	/*
	* 构造函数
	*/
    WindowButton();
	/*
	* 析构函数
	*/
    virtual ~WindowButton();
	/*
	* 获取或设置是否圆形
	*/
    bool isEllipse();
    void setEllipse(bool isEllipse);
	/*
	* 获取或设置窗体样式
	*/
    WindowButtonStyle getStyle();
    void setStyle(WindowButtonStyle style);
public:
	/*
	* 获取背景颜色
	*/
    virtual Long getPaintingBackColor();
	/*
	* 重绘方法
	* @param paint 绘图对象
	* @param clipRect 裁剪区域
	*/
    virtual void onPaintBackground(FCPaint *paint, const FCRect& clipRect);
	/*
	* 重绘边线方法
	* @param paint 绘图对象
	* @param clipRect 裁剪区域
	*/
    virtual void onPaintBorder(FCPaint *paint, const FCRect& clipRect);
};

#endif
