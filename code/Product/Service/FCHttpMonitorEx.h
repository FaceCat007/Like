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
		/*
		* 地址信息
		*/
		SOCKADDR_IN m_addr;
		/*
		* 包
		*/
		char *m_body;
		/*
		* 是否关闭
		*/
        bool m_close;
		/*
		* 内容长度
		*/
		int m_contentLength;
		/*
		* 内容类型
		*/
        String m_contentType;
		/*
		* 方法
		*/
        String m_method;
		/*
		* 参数
		*/
		map<String, String> m_parameters;
		/*
		* 远程ID
		*/
		String m_remoteIP;
		/*
		* 远程端口
		*/
        int m_remotePort;
		/*
		* 返回数据
		*/
		char* m_resBytes;
		/*
		* 返回数据的长度
		*/
		int m_resBytesLength;
		/*
		* 返回字符
		*/
		String m_resStr;
		/*
		* 套接字ID
		*/
		SOCKET m_socket;
		/*
		* 状态码
		*/
		int m_statusCode;	
		/*
		* 地址
		*/
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
		* @param socketID 套接字ID
		*/
		int close(int socketID);
		/**
		 * 启动监听
		 */
		int start();
	};
}

#endif