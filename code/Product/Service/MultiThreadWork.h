/*基于FaceCat(捂脸猫)框架 v1.0
 上海卷卷猫信息技术有限公司
 */

#ifndef __MULTITHREADWORK_H__
#define __MULTITHREADWORK_H__
#pragma once
#include "..\\..\\stdafx.h"

namespace FaceCat{
	/*
	* 多线程工作信息
	*/
	class WorkDataInfo{
	public:
		/*
		* 编号
		*/
		int m_id;
		/*
		* 位置
		*/
		int m_pos;
		/*
		* 线程ID
		*/
		int m_threadID;
	public:
		/*
		* 构造函数
		*/
		WorkDataInfo(){
			m_id = 0;
			m_pos = 0;
			m_threadID = 0;
		}
		/*
		* 析构函数
		*/
		virtual ~WorkDataInfo(){}
	};

	typedef void (*StartWorkEventHandler)(WorkDataInfo *dataInfo, void *pInvoke);
	typedef void (*QuitWorkEventHandler)(WorkDataInfo *dataInfo, void *pInvoke);
	typedef int (*WorkingEventHandler)(WorkDataInfo *dataInfo, void *pInvoke);

	/*
	* 多线程任务
	*/
	class MultiThreadWork{
	public:
		/*
		* 工作信息
		*/
		map<int, vector<WorkDataInfo*>*> m_dataInfos;
		/*
		* 是否正在运行
		*/
		bool m_isRunning;
		/*
		* 要处理的消息
		*/
		vector<WorkDataInfo*> m_messages;
		/*
		* 退出事件
		*/
		QuitWorkEventHandler m_quitEvent;
		/*
		* 退出事件的调用者
		*/
		void *m_quitEventInvoke;
		/*
		* 启动事件
		*/
		StartWorkEventHandler m_startEvent;
		/*
		* 启动事件的调用者
		*/
		void *m_startEventInvoke;
		/*
		* 停止信息
		*/
		vector<WorkDataInfo*> m_stopPushDatas;
		/*
		* 所有线程
		*/
		vector<HANDLE> m_threads;
		/*
		* 工作事件
		*/
		WorkingEventHandler m_workEvent;
		/*
		* 工作事件的调用者
		*/
		void *m_workEventInvoke;
	private:
		/*
		* 锁
		*/
		FCLock m_lock;
	public:
		/*
		* 构造函数
		*/
		MultiThreadWork();
		/*
		* 析构函数
		*/
		virtual ~MultiThreadWork();
		/*
		* 获取或设置是否正在运行
		*/
		bool isRunning();
		void setRunning(bool isRunning);
	public:
		/*
		* 工作回调
		* @param id 编号
		*/
		void onWork(int id);
		/*
		* 退出工作
		* @param reqInfo 请求信息
		*/
		int quitWork(WorkDataInfo *reqInfo);
		/*
		* 启动工作
		* @param dataInfo 工作信息
		*/
		void startWork(WorkDataInfo *dataInfo);
		/*
		* 启动工作
		* @param dataInfos 工作信息集合
		*/
		void startWork(vector<WorkDataInfo*> *dataInfos);
		/*
		* 注册退出事件
		* @param quitEvent 退出事件
		* @param pInvoke 调用者
		*/
		void registerQuitEvent(QuitWorkEventHandler quitEvent, void *pInvoke);
		/*
		* 注册接收事件
		* @param quitEvent 接收事件
		* @param pInvoke 调用者
		*/
		void registerRecvEvent(StartWorkEventHandler recvEvent, void *pInvoke);
		/*
		* 注册工作事件
		* @param workEvent 工作事件
		* @param pInvoke 调用者
		*/
		void registerWorkEvent(WorkingEventHandler workEvent, void *pInvoke);
		/*
		* 启动
		* @param size 大小
		*/
		void start(int size);
		/*
		* 停止
		*/
		void stop();
	};

	/*
	* 基础工作
	*/
	class BaseWork{
	private:
		/*
		* 线程数
		*/
		int m_threads;
	public:
		/*
		* 多线程工作
		*/
		MultiThreadWork *m_workThread;
		/*
		* 退出工作
		* @param dataInfo 工作信息
		* @param pInvoke 调用信息
		*/
		static void workQuit(WorkDataInfo *dataInfo, void *pInvoke);
		/*
		* 启动工作
		* @param dataInfo 工作信息
		* @param pInvoke 调用信息
		*/
		static void workStart(WorkDataInfo *dataInfo, void *pInvoke);
		/*
		* 工作中
		* @param dataInfo 工作信息
		* @param pInvoke 调用信息
		*/
		static int working(WorkDataInfo *dataInfo, void *pInvoke);
	public:
		/*
		* 构造函数
		*/
		BaseWork();
		/*
		* 析构函数
		*/
		virtual ~BaseWork();
		/*
		* 是否正在运行
		*/
		bool isRunning();
		/*
		* 获取或设置线程数
		*/
		int getThreads();
		void setThreads(int threads);
	public:
		/*
		* 退出工作回调
		* @param dataInfo工作信息
		*/
		virtual void onWorkQuit(WorkDataInfo *dataInfo);
		/*
		* 启动工作回调
		* @param dataInfo工作信息
		*/
		virtual void onWorkStart(WorkDataInfo *dataInfo);
		/*
		* 工作中回调
		* @param dataInfo工作信息
		*/
		virtual int onWorking(WorkDataInfo *dataInfo);
		/*
		* 启动
		*/
		virtual void start();
		/*
		* 停止
		*/
		virtual void stop();
	};
}

#endif