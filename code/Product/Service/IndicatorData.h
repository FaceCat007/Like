/*基于FaceCat(捂脸猫)框架 v1.0
 上海卷卷猫信息技术有限公司
 */
#ifndef __INDICATORDATA__H__
#define __INDICATORDATA__H__
#pragma once

/*
* 指标数据
*/
class IndicatorData{
public:
	/*
	* 参数
	*/
    String m_parameters;
	/*
	* 脚本
	*/
    String m_script;
public:
	/*
	* 构造函数
	*/
    IndicatorData(){
        m_parameters = L"";
        m_script = L"";
    }
	/*
	* 析构函数
	*/
    virtual ~IndicatorData(){
        
    }
};

#endif
