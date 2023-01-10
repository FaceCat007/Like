/*
 * FaceCatͼ��ͨѶ���(�ǿ�Դ)
 * ����Ȩ���:2015SR229355+2020SR0266727
 * �Ϻ����è��Ϣ�������޹�˾
 */

#ifdef __FCHTTPPOSTSERVICE_H__
#else                                                                            
#define __FCHTTPPOSTSERVICE_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "FCClientService.h"

namespace FaceCat{
	/*
	* Post����
	*/
	class __FCHTTPPOSTSERVICE_H__ FCHttpPostService : public FCClientService{
	private:
	    /**
		 * �Ƿ�ͬ������
		 */
		bool m_isSyncSend;
		/*
		* ��
		*/
        FCLock m_lock;
        /**
		 * ��ַ
		 */
		string m_url;
		/**
		 * Timeoutʱ��
		 */
		int m_timeout;
	public:
		/*
		* ��Ϣ
		*/
		ArrayList<FCMessage*> m_messages;
		/**
		 * ����HTTP����
		 */
		FCHttpPostService();
		/*
		* ��������
		*/
		virtual ~FCHttpPostService();
		/**
		 * ��ȡ�Ƿ�ͬ������
		 */
		bool isSyncSend();
		/**
		 * �����Ƿ�ͬ������
		 */
        void setIsSyncSend(bool value);
		/*
		* ��ȡ��
		*/
        FCLock getLock();
        /**
		 * ��ȡTimeoutʱ��
		 */
		int getTimeout();
		/**
		 * ����Timeoutʱ��
		 */
		void setTimeout(int value);
		/**
		 * ��ȡ��ַ
		 */
		string getUrl();
		/**
		 * ���õ�ַ
		 */
		void setUrl(string value);
	public:
	    /**
		 * �첽��������
		 */
		static DWORD WINAPI asynSend(LPVOID lpParam);
	public:
		/**
		* ��������
		* @param  message  ��Ϣ
		*/
		virtual void onReceive(FCMessage *message);
		/**
		* ����POST����
		* @param  url  ��ַ
		* @param  data  ����
		*/
		String post(const String& url);
		/*
		* ����POST����
		*/
		string post(const String& url, char *sendDatas, int sendSize);
		/*
		* ����POST����
		*/
		String post(const String& url, const String &data);
		/*
		* ��������
		*/
		int send(FCMessage *message);
		/**
		* ����POST����
		* @param  message  ��Ϣ
		*/
		int sendRequest(FCMessage *message);
	};
}