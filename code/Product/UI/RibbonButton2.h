/*基于捂脸猫FaceCat框架 v1.0
上海卷卷猫信息技术有限公司
 */

#ifndef __RIBBONBUTTON2_H__
#define __RIBBONBUTTON2_H__
#pragma once
#include "..\\..\\stdafx.h"
#include "FCDraw.h"
#include "GdiPlusPaintEx.h"

//透明按钮
class RibbonButton2 : public FCButton{
public:
	RibbonButton2();
	virtual ~RibbonButton2();
public:
	//重绘背景色方法
	virtual void onPaint(FCPaint *paint, const FCRect& clipRect);
};
#endif