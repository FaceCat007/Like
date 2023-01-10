/*基于FaceCat(捂脸猫)框架 v1.0
 上海卷卷猫信息技术有限公司
 */
#ifndef __CFUNCTIONBASE_H__
#define __CFUNCTIONBASE_H__
#pragma once
#include "..\\..\\stdafx.h"
#include "..\\..\\..\\facecat\\include\\xml\\FCUIXml.h"
#include "..\\..\\..\\facecat\\include\\xml\\FCUIScript.h"
#include "..\\..\\..\\facecat\\include\\xml\\FCUIEvent.h"

class NFunctionBase : public CFunction{
private:
    FCScript *m_indicator;
public:
    NFunctionBase(FCScript *indicator, int cid, const String& name);
    virtual ~NFunctionBase();
public:
    static void addFunctions(FCScript *indicator);
    virtual double onCalculate(CVariable *var);
public:
	double EXECUTE(CVariable *var);
    double INPUT(CVariable *var);
    double OUTPUT(CVariable *var);
    double SLEEP(CVariable *var);
};

#endif

