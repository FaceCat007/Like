/*
 * FaceCat���(�ǿ�Դ)
 * �Ϻ����è��Ϣ�������޹�˾
 */

#ifdef __UISCRIPT_H__
#else                                                                            
#define __UISCRIPT_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "FCUIEvent.h"
#include "FCUIScript.h"

namespace FaceCat{
	class FCUIEvent;
	class FCUIXml;

	/*
	* �ű��ӿ���
	*/
	class __UISCRIPT_H__ FCUIScript{
	private:
		/*
		* xml����
		*/
		FCUIXml* m_xml;
	public:
		/*
		* ���캯��
		*/
		FCUIScript(FCUIXml *xml);
		/*
		* ��������
		*/
		virtual ~FCUIScript();
		/**
		 * ��ȡXML����
		 */
		FCUIXml* getXml();
		/**
		 * ����XML����
		 */
		void setXml(FCUIXml *value);
	public:
	    /**
		 * ���÷���
		 */
		virtual String callFunction(const String& function);
		/**
		 * ���ýű�
		 */
		virtual void setText(const String& text);
	};
}