/*����FaceCat(����è)��� v1.0
 �Ϻ����è��Ϣ�������޹�˾
 */
#ifndef __INDICATORDATA__H__
#define __INDICATORDATA__H__
#pragma once

/*
* ָ������
*/
class IndicatorData{
public:
	/*
	* ����
	*/
    String m_parameters;
	/*
	* �ű�
	*/
    String m_script;
public:
	/*
	* ���캯��
	*/
    IndicatorData(){
        m_parameters = L"";
        m_script = L"";
    }
	/*
	* ��������
	*/
    virtual ~IndicatorData(){
        
    }
};

#endif
