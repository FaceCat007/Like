/*
 * FaceCatͼ��ͨѶ���(�ǿ�Դ)
 * ����Ȩ���:2015SR229355+2020SR0266727
 * �Ϻ����è��Ϣ�������޹�˾
 */

#ifdef __FCHTTPEASYSERVICE_H__
#else                                                                            
#define __FCHTTPEASYSERVICE_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "FCHttpMonitor.h"

using namespace std;

namespace FaceCat{
	class FCHttpData;

	/*
	* �򵥵�HTTP����
	*/
	class __FCHTTPEASYSERVICE_H__ FCHttpEasyService{
	public:
	    /**
		 * HTTP��GET����
		 */
		FCHttpEasyService();
		/*
		* ɾ������
		*/
		virtual ~FCHttpEasyService();
	public:
		/**
		* ��������
		* @param  data  ��������
		*/
		virtual void onReceive(FCHttpData* data);
	};
}
