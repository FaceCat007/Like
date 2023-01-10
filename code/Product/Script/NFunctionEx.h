/*����FaceCat(����è)��� v1.0
 �Ϻ����è��Ϣ�������޹�˾
 */

#ifndef __CFUNCTIONEX_H__
#define __CFUNCTIONEX_H__
#pragma once
#include "..\\..\\stdafx.h"
#include "..\\..\\..\\facecat\\include\\xml\\FCUIXml.h"
#include "..\\..\\..\\facecat\\include\\xml\\FCUIScript.h"
#include "..\\..\\..\\facecat\\include\\xml\\FCUIEvent.h"

class NFunctionEx : public CFunction{
private:
    FCScript *m_indicator;
    FCUIXml *m_xml;
public:
    NFunctionEx(FCScript *indicator, int cid, const String& name, FCUIXml *xml);
    virtual ~NFunctionEx();
public:
    static FCScript* createIndicator(const String& script, FCUIXml *xml);
    virtual double onCalculate(CVariable *var);
};

#endif

