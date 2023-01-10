/*��������èFaceCat��� v1.0
�Ϻ����è��Ϣ�������޹�˾
 */

#ifndef __WINDOWBUTTON_H__
#define __WINDOWBUTTON_H__
#pragma once
#include "..\\..\\stdafx.h"
#include "FCDraw.h"

enum WindowButtonStyle{
    WindowButtonStyle_Close,
    WindowButtonStyle_Max,
    WindowButtonStyle_Min,
    WindowButtonStyle_Restore
};

class WindowButton : public FCButton{
private:
    bool m_isEllipse;
    WindowButtonStyle m_style;
public:
    WindowButton();
    virtual ~WindowButton();
    bool isEllipse();
    void setEllipse(bool isEllipse);
    WindowButtonStyle getStyle();
    void setStyle(WindowButtonStyle style);
public:
    virtual Long getPaintingBackColor();
    virtual void onPaintBackground(FCPaint *paint, const FCRect& clipRect);
    virtual void onPaintBorder(FCPaint *paint, const FCRect& clipRect);
};

#endif
