/*基于捂脸猫FaceCat框架 v1.0 https://github.com/FaceCat007/facecat.git
 1.创始人-矿洞程序员-上海卷卷猫信息技术有限公司-脉脉KOL-陶德 (微信号:suade1984);
 2.联合创始人-上海卷卷猫信息技术有限公司-周淋霞;
 3.该程序不开源，需要得到授权才能使用。
 */

#ifndef __AnimalDiv_H__
#define __AnimalDiv_H__
#pragma once
#include "..\\..\\stdafx.h"

//透明按钮
class AnimalDiv : public FCView{
public:
	Long m_finalColor;
	int m_searchState;
	int m_tick;
	int m_timerID;
public:
	AnimalDiv();
	virtual ~AnimalDiv();
public:
	//添加控件方法
	virtual void onAdd();
	//重绘背景色方法
	virtual void onPaint(FCPaint *paint, const FCRect& clipRect);
	//触摸按下方法
	virtual void onTouchDown(FCTouchInfo touchInfo);
	//秒表方法
	virtual void onTimer(int timerID);
};
#endif