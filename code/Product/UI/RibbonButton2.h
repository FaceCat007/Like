/*��������èFaceCat��� v1.0
�Ϻ����è��Ϣ�������޹�˾
 */

#ifndef __RIBBONBUTTON2_H__
#define __RIBBONBUTTON2_H__
#pragma once
#include "..\\..\\stdafx.h"
#include "FCDraw.h"
#include "GdiPlusPaintEx.h"

//͸����ť
class RibbonButton2 : public FCButton{
public:
	RibbonButton2();
	virtual ~RibbonButton2();
public:
	//�ػ汳��ɫ����
	virtual void onPaint(FCPaint *paint, const FCRect& clipRect);
};
#endif