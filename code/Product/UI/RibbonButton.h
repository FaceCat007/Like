/*��������èFaceCat��� v1.0
�Ϻ����è��Ϣ�������޹�˾
 */

#ifndef __RIBBONBUTTON_H__
#define __RIBBONBUTTON_H__
#pragma once
#include "..\\..\\stdafx.h"
#include "FCDraw.h"
#include "GdiPlusPaintEx.h"

//͸����ť
class RibbonButton : public FCButton{
private:
    int m_arrowType;
    bool m_isClose;
    bool m_isTabClose;
    bool m_selected;
public:
    RibbonButton();
    virtual ~RibbonButton();
    //��ͷ��״
    int getArrowType();
    void setArrowType(int arrowType);
    //�Ƿ�رհ�ť
    bool isClose();
    void setClose(bool isClose);
    //�Ƿ��ҳ�еĹرհ�ť
    bool isTabClose();
    void setTabClose(bool isTabClose);
    //�Ƿ�ѡ��
    void setSelected(bool selected);
    bool isSelected();
public:
    //��ȡҪ���Ƶ�ǰ��ɫ
    virtual Long getPaintingTextColor();
    //�ػ汳��ɫ����
    virtual void onPaintBackground(FCPaint *paint, const FCRect& clipRect);
};

#endif