/*
 * FaceCatͼ��ͨѶ���(�ǿ�Դ)
 * ����Ȩ���:2015SR229355+2020SR0266727
 * �Ϻ����è��Ϣ�������޹�˾
 */

#ifdef __CFUNCTIONHTTP_H__
#else                                                                            
#define __CFUNCTIONHTTP_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "FCHttpMonitor.h"
#include "FCHttpEasyService.h"

namespace FaceCat{
	/*
	* HTTP��
	*/
	class __CFUNCTIONHTTP_H__ CFunctionHttp : public CFunction{
	private:
	    /**
		 * HTTP����
		 */
		FCHttpData *m_data;
		/*
		* ������
		*/
		FCHttpMonitor *m_monitor;
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
		CFunctionHttp(FCScript *script, int cid, const String& name, FCHttpMonitor *monitor);
		/*
		* ��������
		*/
		virtual ~CFunctionHttp();
		/**
		 * ��ȡHTTP����
		 */
		FCHttpData* getHttpData();
		/**
		 * ����HTTP����
		 */
		void setHttpData(FCHttpData *data);
	public:
		/**
		* ��ӷ���
		* @param  script  ������
		*/
		static void addFunctions(FCScript *script, FCHttpMonitor *monitor);
		/**
		* ����
		* @param  var  ����
		*/
		virtual double onCalculate(CVariable *var);
	public:
	    /**
		 * ���ǰ׺
		 */
		double HTTP_ADDPORT(CVariable *var);
		/**
		 * ���ű�
		 */
		double HTTP_CHECKSCRIPT(CVariable *var);
		/**
		 * HTTP�ر�
		 */
		double HTTP_CLOSE(CVariable *var);
		/**
		 * ����GET����
		 */
		double HTTP_EASYREQUEST(CVariable *var);
		/**
		 * ��ȡ�������ͷ���
		 */
		double HTTP_GETCONTENTTYPE(CVariable *var);
		/**
		 * ��ȡIP
		 */
		double HTTP_GETREMOTEIP(CVariable *var);
		/**
		 * ��ȡPort
		 */
		double HTTP_GETREMOTEPORT(CVariable *var);
		/**
		 * ��ȡ���󷽷�
		 */
		double HTTP_GETREQUESTMETHOD(CVariable *var);
		/**
		 * ��ȡ����URL
		 */
		double HTTP_GETREQUESTURL(CVariable *var);
		/**
		 * ��ȡ��������
		 */
		double HTTP_GETSERVICENAME(CVariable *var);
		/**
		 * ����������
		 */
		double HTTP_HARDREQUEST(CVariable *var);
		/**
		 * ����������
		 */
		double HTTP_POSTREQUEST(CVariable *var);
		/**
		 * HTTP��ȡPOST����Ĳ���
		 */
		double HTTP_POSTSTRING(CVariable *var);
		/**
		 * HTTP��ȡGET����Ĳ���
		 */
		double HTTP_QUERYSTRING(CVariable *var);
		/**
		 * ������Ӧ״̬��
		 */
		double HTTP_SETSTATUSCODE(CVariable *var);
		/**
		 * HTTP��Ӧд��
		 */
		double HTTP_WRITE(CVariable *var);
	};
}

