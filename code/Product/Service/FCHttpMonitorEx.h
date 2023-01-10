/*����FaceCat(����è)��� v1.0
 �Ϻ����è��Ϣ�������޹�˾
 */

#ifndef __FCHTTPMONITOREX_H__
#define __FCHTTPMONITOREX_H__
#pragma once
#include "..\\..\\stdafx.h"
#include <string>
#include <map>
#pragma comment(lib, "ws2_32.lib")
#include "winsock2.h"
using namespace std;

namespace FaceCat
{
	 /**
	 * Http����
	 */
	class FCHttpDataEx
	{
	public:
	    /**
		 * �ļ�Http����
		 */
		FCHttpDataEx();
		/*
		* ��������
		*/
		~FCHttpDataEx();
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
	};

	/*
	* HTTP����
	*/
	class FCHttpMonitorEx
	{
	public:
		SOCKADDR_IN m_addr;
		/*
		* �׽���
		*/
		SOCKET m_hSocket;
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
	public:
		/*
		* ���캯��
		*/
		FCHttpMonitorEx();
		/*
		* ��������
		*/
		virtual ~FCHttpMonitorEx();
		/**
		 * ��ȡ��������
		 */
		static FCHttpMonitorEx* getMainMonitor();
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
		void setPort(int port);
		/*
		* ��ȡ�׽���
		*/
		SOCKET getSocket();
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

#endif