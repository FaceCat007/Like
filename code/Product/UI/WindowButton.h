/*��������èFaceCat��� v1.0
�Ϻ����è��Ϣ�������޹�˾
 */

#ifndef __WINDOWBUTTON_H__
#define __WINDOWBUTTON_H__
#pragma once
#include "..\\..\\stdafx.h"
#include "FCDraw.h"

/*
* ���尴ť��ʽ
*/
enum WindowButtonStyle{
	/*
	* �ر�
	*/
    WindowButtonStyle_Close,
	/*
	* ���
	*/
    WindowButtonStyle_Max,
	/*
	* ��С��
	*/
    WindowButtonStyle_Min,
	/*
	* �ָ�
	*/
    WindowButtonStyle_Restore
};

/*
* ���尴ť
*/
class WindowButton : public FCButton{
private:
	/*
	* �Ƿ�Բ��
	*/
    bool m_isEllipse;
	/*
	* ��ʽ
	*/
    WindowButtonStyle m_style;
public:
	/*
	* ���캯��
	*/
    WindowButton();
	/*
	* ��������
	*/
    virtual ~WindowButton();
	/*
	* ��ȡ�������Ƿ�Բ��
	*/
    bool isEllipse();
    void setEllipse(bool isEllipse);
	/*
	* ��ȡ�����ô�����ʽ
	*/
    WindowButtonStyle getStyle();
    void setStyle(WindowButtonStyle style);
public:
	/*
	* ��ȡ������ɫ
	*/
    virtual Long getPaintingBackColor();
	/*
	* �ػ淽��
	* @param paint ��ͼ����
	* @param clipRect �ü�����
	*/
    virtual void onPaintBackground(FCPaint *paint, const FCRect& clipRect);
	/*
	* �ػ���߷���
	* @param paint ��ͼ����
	* @param clipRect �ü�����
	*/
    virtual void onPaintBorder(FCPaint *paint, const FCRect& clipRect);
};

#endif
