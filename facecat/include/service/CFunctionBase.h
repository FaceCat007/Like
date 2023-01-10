/*
 * FaceCatͼ��ͨѶ���(�ǿ�Դ)
 * ����Ȩ���:2015SR229355+2020SR0266727
 * �Ϻ����è��Ϣ�������޹�˾
 */

#ifdef __NFUNCTIONBASE_H__
#else                                                                            
#define __NFUNCTIONBASE_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"

namespace FaceCat{
	/*
	* ����������
	*/
	class __NFUNCTIONBASE_H__ NFunctionBase : public CFunction{
	private:
	    /**
		 * ָ��
		 */
		FCScript *m_script;
	public:
		/**
		* ��������
		* @param  script  ָ��
		* @param  id  ID
		* @param  name  ����
		*/
		NFunctionBase(FCScript *script, int cid, const String& name);
		/*
		* ��������
		*/
		virtual ~NFunctionBase();
	public:
		/**
		* ��ӷ���
		* @param  script  ������
		*/
		static void addFunctions(FCScript *script);
		/**
		* ����
		* @param  var  ����
		*/
		virtual double onCalculate(CVariable *var);
	public:
		/**
		* ���뺯��
		* @param  var  ����
		*/
		double INPUT(CVariable *var);
		/**
		* �������
		* @param  var  ����
		*/
		double OUTPUT(CVariable *var);
		/**
		* ˯��
		* @param  var  ����
		*/
		double SLEEP(CVariable *var);
	};
}


