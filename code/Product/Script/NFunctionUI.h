/*基于FaceCat(捂脸猫)框架 v1.0
 上海卷卷猫信息技术有限公司
 */

#ifndef __CFUNCTIONUI_H__
#define __CFUNCTIONUI_H__
#pragma once
#include "..\\..\\stdafx.h"
#include "..\\..\\..\\facecat\\include\\xml\\FCUIXml.h"
#include "..\\..\\..\\facecat\\include\\xml\\FCUIScript.h"
#include "..\\..\\..\\facecat\\include\\xml\\FCUIEvent.h"

class NFunctionUI : public CFunction{
private:
    FCScript *m_indicator;
    FCUIXml *m_xml;
public:
    NFunctionUI(FCScript *indicator, int cid, const String& name, FCUIXml *xml);
    virtual ~NFunctionUI();
public:
    static void addFunctions(FCScript *indicator, FCUIXml *xml);
    virtual double onCalculate(CVariable *var);
public:
	double ADDBARRAGE(CVariable *var);
	double ALERT(CVariable *var);
	double CLOSEWINDOW(CVariable *var);
	double GETCOOKIE(CVariable *var);
    double GETPROPERTY(CVariable *var);
    double GETSENDER(CVariable *var);
    double INVALIDATE(CVariable *var);
	double SETCOOKIE(CVariable *var);
	double SETPROPERTY(CVariable *var);
	double SHOWRIGHTMENU(CVariable *var);
    double SHOWWINDOW(CVariable *var);
    double STARTTIMER(CVariable *var);
	double STOPTIMER(CVariable *var);
};

#endif

