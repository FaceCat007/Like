/*
 * FaceCatͼ��ͨѶ���(�ǿ�Դ)
 * ����Ȩ���:2015SR229355+2020SR0266727
 * �Ϻ����è��Ϣ�������޹�˾
 */

#ifdef __CFUNCTIONEX_H__
#else                                                                            
#define __CFUNCTIONEX_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "FCHttpMonitor.h"

namespace FaceCat{
	/*
	* HTTP�Ŀ�
	*/
	class __CFUNCTIONEX_H__ CFunctionEx : public CFunction{
	private:
	    /**
		 * ָ��
		 */
		FCScript *m_script;
		/**
		 * XML����
		 */
		FCNative *m_native;
	public:
		/**
		* ��������
		* @param  script  ָ��
		* @param  id  ID
		* @param  name  ����
		* @param  native  XML����
		*/
		CFunctionEx(FCScript *script, int cid, const String& name, FCNative *native);
		/*
		* ��������
		*/
		virtual ~CFunctionEx();
	public:
		/*
		* �����ű�
		*/
		static FCScript* createScript(const String& text, FCNative *native, FCHttpMonitor *monitor);
		/**
		* ����
		* @param  var  ����
		*/
		virtual double onCalculate(CVariable *var);
	};
}

