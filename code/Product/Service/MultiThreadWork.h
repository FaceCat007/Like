/*基于FaceCat(捂脸猫)框架 v1.0
 上海卷卷猫信息技术有限公司
 */

#ifndef __MULTITHREADWORK_H__
#define __MULTITHREADWORK_H__
#pragma once
#include "..\\..\\stdafx.h"

namespace FaceCat{
	class WorkDataInfo{
	public:
		int m_id;
		int m_pos;
		int m_threadID;
	public:
		WorkDataInfo(){
			m_id = 0;
			m_pos = 0;
			m_threadID = 0;
		}
		virtual ~WorkDataInfo(){}
	};

	typedef void (*StartWorkEventHandler)(WorkDataInfo *dataInfo, void *pInvoke);
	typedef void (*QuitWorkEventHandler)(WorkDataInfo *dataInfo, void *pInvoke);
	typedef int (*WorkingEventHandler)(WorkDataInfo *dataInfo, void *pInvoke);

	class MultiThreadWork{
	public:
		map<int, vector<WorkDataInfo*>*> m_dataInfos;
		bool m_isRunning;
		vector<WorkDataInfo*> m_messages;
		QuitWorkEventHandler m_quitEvent;
		void *m_quitEventInvoke;
		StartWorkEventHandler m_startEvent;
		void *m_startEventInvoke;
		vector<WorkDataInfo*> m_stopPushDatas;
		vector<HANDLE> m_threads;
		WorkingEventHandler m_workEvent;
		void *m_workEventInvoke;
	private:
		FCLock m_lock;
	public:
		MultiThreadWork();
		virtual ~MultiThreadWork();
		bool isRunning();
		void setRunning(bool isRunning);
	public:
		void onWork(int id);
		int quitWork(WorkDataInfo *reqInfo);
		void startWork(WorkDataInfo *dataInfo);
		void startWork(vector<WorkDataInfo*> *dataInfos);
		void registerQuitEvent(QuitWorkEventHandler quitEvent, void *pInvoke);
		void registerRecvEvent(StartWorkEventHandler recvEvent, void *pInvoke);
		void registerWorkEvent(WorkingEventHandler workEvent, void *pInvoke);
		void start(int size);
		void stop();
	};

	class BaseWork{
	private:
		int m_threads;
	public:
		MultiThreadWork *m_workThread;
		static void workQuit(WorkDataInfo *dataInfo, void *pInvoke);
		static void workStart(WorkDataInfo *dataInfo, void *pInvoke);
		static int working(WorkDataInfo *dataInfo, void *pInvoke);
	public:
		BaseWork();
		virtual ~BaseWork();
		bool isRunning();
		int getThreads();
		void setThreads(int threads);
	public:
		virtual void onWorkQuit(WorkDataInfo *dataInfo);
		virtual void onWorkStart(WorkDataInfo *dataInfo);
		virtual int onWorking(WorkDataInfo *dataInfo);
		virtual void start();
		virtual void stop();
	};
}

#endif