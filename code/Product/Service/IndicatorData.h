/*����FaceCat(����è)��� v1.0
 �Ϻ����è��Ϣ�������޹�˾
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
