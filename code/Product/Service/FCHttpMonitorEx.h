/*基于FaceCat(捂脸猫)框架 v1.0
 上海卷卷猫信息技术有限公司
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
	 * Http数据
	 */
	class FCHttpDataEx
	{
	public:
	    /**
		 * 文件Http服务
		 */
		FCHttpDataEx();
		/*
		* 析构函数
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
	* HTTP监听
	*/
	class FCHttpMonitorEx
	{
	public:
		SOCKADDR_IN m_addr;
		/*
		* 套接字
		*/
		SOCKET m_hSocket;
		/*
		* 全局锁
		*/
		FCLock m_lock;
		/*
		* HTTP锁
		*/
		FCLock m_lockHttpData;
		/**
		 * XML对象
		 */
		FCNative *m_native;
		/**
		 * 端口
		 */
		int m_port;
	public:
		/*
		* 构造函数
		*/
		FCHttpMonitorEx();
		/*
		* 析构函数
		*/
		virtual ~FCHttpMonitorEx();
		/**
		 * 获取主监视器
		 */
		static FCHttpMonitorEx* getMainMonitor();
		/**
		 * 获取XML对象
		 */
		FCNative* getNative();
		/**
		 * 获取端口
		 */
		int getPort();
		/**
		 * 设置端口
		 */
		void setPort(int port);
		/*
		* 获取套接字
		*/
		SOCKET getSocket();
	public:
		/*
		* 关闭服务
		*/
		int close(int socketID);
		/**
		 * 启动监听
		 */
		int start();
	};
}

#endif