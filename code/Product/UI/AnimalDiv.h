/*��������èFaceCat��� v1.0 https://github.com/FaceCat007/facecat.git
 1.��ʼ��-�󶴳���Ա-�Ϻ����è��Ϣ�������޹�˾-����KOL-�յ� (΢�ź�:suade1984);
 2.���ϴ�ʼ��-�Ϻ����è��Ϣ�������޹�˾-����ϼ;
 3.�ó��򲻿�Դ����Ҫ�õ���Ȩ����ʹ�á�
 */

#ifndef __AnimalDiv_H__
#define __AnimalDiv_H__
#pragma once
#include "..\\..\\stdafx.h"

//͸����ť
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
	//��ӿؼ�����
	virtual void onAdd();
	//�ػ汳��ɫ����
	virtual void onPaint(FCPaint *paint, const FCRect& clipRect);
	//�������·���
	virtual void onTouchDown(FCTouchInfo touchInfo);
	//�����
	virtual void onTimer(int timerID);
};
#endif