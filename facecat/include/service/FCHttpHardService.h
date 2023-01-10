/*
 * FaceCatͼ��ͨѶ���(�ǿ�Դ)
 * ����Ȩ���:2015SR229355+2020SR0266727
 * �Ϻ����è��Ϣ�������޹�˾
 */

#ifdef __FCHTTPHARDSERVICE_H__
#else                                                                            
#define __FCHTTPHARDSERVICE_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include <string>
#include <map>
#include "FCServerService.h"
#include "FCHttpMonitor.h"

#define SERVICEID_HTTPHARD 20
#define FUNCTIONID_HTTPHARD_TEST 0

namespace FaceCat{
    /**
	 * HTTP����
	 */
	class __FCHTTPHARDSERVICE_H__ FCHttpHardService:public FCServerService{
	private:
		/*
		* ������
		*/
		FCHttpMonitor *m_monitor;
	public:
	    /**
		 * ����HTTP����
		 */
		FCHttpHardService();
		/*
		* ��������
		*/
		virtual ~FCHttpHardService();
		/*
		* ��ȡ������
		*/
		virtual FCHttpMonitor* getMonitor();
		/*
		* ���ü�����
		*/
		virtual void setMonitor(FCHttpMonitor *value);
	public:
		/**
		* ��������
		* @param  message  ��Ϣ
		*/
		virtual void onReceive(FCMessage *message);
		/**
		* ������Ϣ
		* @param  message  ��Ϣ
		*/
		virtual int send(FCMessage *message);
	};
}
