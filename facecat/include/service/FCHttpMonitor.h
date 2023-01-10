/*
 * FaceCatͼ��ͨѶ���(�ǿ�Դ)
 * ����Ȩ���:2015SR229355+2020SR0266727
 * �Ϻ����è��Ϣ�������޹�˾
 */

#ifdef __FCHTTPMONITOR_H__
#else                                                                            
#define __FCHTTPMONITOR_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "..\\core\\FCBinary.h"
#include <string>
#include <map>
#pragma comment(lib, "ws2_32.lib")
#include "winsock2.h"
#include "FCHttpEasyService.h"
using namespace std;

namespace FaceCat
{
	class FCHttpEasyService;

    /**
	 * Http����
	 */
	class __FCHTTPMONITOR_H__ FCHttpData
	{
	public:
	    /**
		 * �ļ�Http����
		 */
		FCHttpData();
		/*
		* ��������
		*/
		~FCHttpData();
		SOCKADDR_IN m_addr;
		char *m_body;
        bool m_close;
		int m_contentLength;
        String m_contentType;
        String m_method;
		map<String, String> m_parameters;
		String m_remoteIP;
        int m_remotePort;
		char* m_resBytes;
		int m_resBytesLength;
		String m_resStr;
		SOCKET m_socket;
		int m_statusCode;	
        String m_url;
		void *m_tag;
	};

	/*
	* HTTP����
	*/
	class __FCHTTPMONITOR_H__ FCHttpMonitor
	{
	public:
		SOCKADDR_IN m_addr;
		/**
		 * �ļ�����
		 */
		string m_fileName;
		/*
		* �׽���
		*/
		SOCKET m_hSocket;
		/**
		 * ���ݼ���
		 */
		map<int, FCHttpData*> m_httpDatas;
		/**
		 * �ű�����
		 */
		stack<FCScript*> m_scripts;
		/**
		 * ���ű�
		 */
		FCScript *m_script;
		/*
		* ȫ����
		*/
		FCLock m_lock;
		/*
		* HTTP��
		*/
		FCLock m_lockHttpData;
		/**
		 * XML����
		 */
		FCNative *m_native;
		/**
		 * �˿�
		 */
		int m_port;
		/**
		 * �ű�
		 */
		String m_text;
		/**
		 * ʹ�ýű�
		 */
		bool m_useScript;
	public:
		/*
		* ���캯��
		*/
		FCHttpMonitor(string fileName);
		/*
		* ��������
		*/
		virtual ~FCHttpMonitor();
		/*
		* ��Ӽ򵥷���
		*/
		static void addEasyService(const String& name, FCHttpEasyService *easyService);
		/*
		* ��ȡ�򵥷���
		*/
		static FCHttpEasyService* getEasyService(const String& name);
		/**
		 * ��ȡ���ű�
		 */
		FCScript* getScript();
		/**
		 * ��ȡXML����
		 */
		FCNative* getNative();
		/**
		 * ��ȡ�˿�
		 */
		int getPort();
		/**
		 * ���ö˿�
		 */
		void setPort(int value);
		/**
		 * ��ȡ�ű�
		 */
		String getText();
		/**
		 * ���ýű�
		 */
		void setText(String value);
		/*
		* ��ȡ�׽���
		*/
		SOCKET getSocket();
		/**
		 * �Ƿ�ʹ�ýű�
		 */
		bool getUseScript();
		/*
		* ����HTTP����
		*/
		void setHttpData(int socketID, FCHttpData *data);
		/*
		* ����ָ��
		*/
		FCScript* popScript();
	public:
		/*
		* �رշ���
		*/
		int close(int socketID);
		/**
		 * ��������
		 */
		int start();
	};
}