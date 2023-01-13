/*基于捂脸猫FaceCat框架 v1.0
上海卷卷猫信息技术有限公司
 */

#ifndef __RIBBONBUTTON2_H__
#define __RIBBONBUTTON2_H__
#pragma once
#include "..\\..\\stdafx.h"
#include "FCDraw.h"
#include "GdiPlusPaintEx.h"

/*
*透明按钮
*/
class RibbonButton2 : public FCButton{
public:
	/*
	* 构造函数
	*/
	RibbonButton2();
	/*
	* 析构函数
	*/
	virtual ~RibbonButton2();
public:
	/*
	* 重绘方法
	* @param paint 绘图对象
	* @param clipRect 裁剪区域
	*/
	virtual void onPaint(FCPaint *paint, const FCRect& clipRect);
};
#endif