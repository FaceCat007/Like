/*����FaceCat(����è)��� v1.0
 �Ϻ����è��Ϣ�������޹�˾
 */
#ifndef __FACECATSCRIPT_H__
#define __FACECATSCRIPT_H__
#pragma once
#include "..\\..\\stdafx.h"
#include "..\\..\\..\\facecat\\include\\xml\\FCUIXml.h"
#include "..\\..\\..\\facecat\\include\\xml\\FCUIScript.h"
#include "..\\..\\..\\facecat\\include\\xml\\FCUIEvent.h"
#include "NFunctionEx.h"

class FaceCatScript : public FCUIScript{
private:
    FCScript *m_script;
    FCUIXml *m_xml;
public:
    FaceCatScript(FCUIXml *xml);
    virtual ~FaceCatScript();
public:
    virtual String callFunction(const String& function);
    String getAttribute(const String& name, const String& propertyName);
    String getSender();
    void setAttribute(const String& name, const String& propertyName, const String& propertyValue);
    virtual void setText(const String& text);
};

#endif
