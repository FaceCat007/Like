/*基于FaceCat(捂脸猫)框架 v1.0
 上海卷卷猫信息技术有限公司
 */
#ifndef __INDICATORDATA__H__
#define __INDICATORDATA__H__
#pragma once

class IndicatorData{
public:
    String m_parameters;
    String m_script;
public:
    IndicatorData(){
        m_parameters = L"";
        m_script = L"";
    }
    virtual ~IndicatorData(){
        
    }
};

#endif
