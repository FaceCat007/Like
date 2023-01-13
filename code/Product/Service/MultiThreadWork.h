/*����FaceCat(����è)��� v1.0
 �Ϻ����è��Ϣ�������޹�˾
 */

#ifndef __MULTITHREADWORK_H__
#define __MULTITHREADWORK_H__
#pragma once
#include "..\\..\\stdafx.h"

namespace FaceCat{
	/*
	* ���̹߳�����Ϣ
	*/
	class WorkDataInfo{
	public:
		/*
		* ���
		*/
		int m_id;
		/*
		* λ��
		*/
		int m_pos;
		/*
		* �߳�ID
		*/
		int m_threadID;
	public:
		/*
		* ���캯��
		*/
		WorkDataInfo(){
			m_id = 0;
			m_pos = 0;
			m_threadID = 0;
		}
		/*
		* ��������
		*/
		virtual ~WorkDataInfo(){}
	};

	typedef void (*StartWorkEventHandler)(WorkDataInfo *dataInfo, void *pInvoke);
	typedef void (*QuitWorkEventHandler)(WorkDataInfo *dataInfo, void *pInvoke);
	typedef int (*WorkingEventHandler)(WorkDataInfo *dataInfo, void *pInvoke);

	/*
	* ���߳�����
	*/
	class MultiThreadWork{
	public:
		/*
		* ������Ϣ
		*/
		map<int, vector<WorkDataInfo*>*> m_dataInfos;
		/*
		* �Ƿ���������
		*/
		bool m_isRunning;
		/*
		* Ҫ�������Ϣ
		*/
		vector<WorkDataInfo*> m_messages;
		/*
		* �˳��¼�
		*/
		QuitWorkEventHandler m_quitEvent;
		/*
		* �˳��¼��ĵ�����
		*/
		void *m_quitEventInvoke;
		/*
		* �����¼�
		*/
		StartWorkEventHandler m_startEvent;
		/*
		* �����¼��ĵ�����
		*/
		void *m_startEventInvoke;
		/*
		* ֹͣ��Ϣ
		*/
		vector<WorkDataInfo*> m_stopPushDatas;
		/*
		* �����߳�
		*/
		vector<HANDLE> m_threads;
		/*
		* �����¼�
		*/
		WorkingEventHandler m_workEvent;
		/*
		* �����¼��ĵ�����
		*/
		void *m_workEventInvoke;
	private:
		/*
		* ��
		*/
		FCLock m_lock;
	public:
		/*
		* ���캯��
		*/
		MultiThreadWork();
		/*
		* ��������
		*/
		virtual ~MultiThreadWork();
		/*
		* ��ȡ�������Ƿ���������
		*/
		bool isRunning();
		void setRunning(bool isRunning);
	public:
		/*
		* �����ص�
		* @param id ���
		*/
		void onWork(int id);
		/*
		* �˳�����
		* @param reqInfo ������Ϣ
		*/
		int quitWork(WorkDataInfo *reqInfo);
		/*
		* ��������
		* @param dataInfo ������Ϣ
		*/
		void startWork(WorkDataInfo *dataInfo);
		/*
		* ��������
		* @param dataInfos ������Ϣ����
		*/
		void startWork(vector<WorkDataInfo*> *dataInfos);
		/*
		* ע���˳��¼�
		* @param quitEvent �˳��¼�
		* @param pInvoke ������
		*/
		void registerQuitEvent(QuitWorkEventHandler quitEvent, void *pInvoke);
		/*
		* ע������¼�
		* @param quitEvent �����¼�
		* @param pInvoke ������
		*/
		void registerRecvEvent(StartWorkEventHandler recvEvent, void *pInvoke);
		/*
		* ע�Ṥ���¼�
		* @param workEvent �����¼�
		* @param pInvoke ������
		*/
		void registerWorkEvent(WorkingEventHandler workEvent, void *pInvoke);
		/*
		* ����
		* @param size ��С
		*/
		void start(int size);
		/*
		* ֹͣ
		*/
		void stop();
	};

	/*
	* ��������
	*/
	class BaseWork{
	private:
		/*
		* �߳���
		*/
		int m_threads;
	public:
		/*
		* ���̹߳���
		*/
		MultiThreadWork *m_workThread;
		/*
		* �˳�����
		* @param dataInfo ������Ϣ
		* @param pInvoke ������Ϣ
		*/
		static void workQuit(WorkDataInfo *dataInfo, void *pInvoke);
		/*
		* ��������
		* @param dataInfo ������Ϣ
		* @param pInvoke ������Ϣ
		*/
		static void workStart(WorkDataInfo *dataInfo, void *pInvoke);
		/*
		* ������
		* @param dataInfo ������Ϣ
		* @param pInvoke ������Ϣ
		*/
		static int working(WorkDataInfo *dataInfo, void *pInvoke);
	public:
		/*
		* ���캯��
		*/
		BaseWork();
		/*
		* ��������
		*/
		virtual ~BaseWork();
		/*
		* �Ƿ���������
		*/
		bool isRunning();
		/*
		* ��ȡ�������߳���
		*/
		int getThreads();
		void setThreads(int threads);
	public:
		/*
		* �˳������ص�
		* @param dataInfo������Ϣ
		*/
		virtual void onWorkQuit(WorkDataInfo *dataInfo);
		/*
		* ���������ص�
		* @param dataInfo������Ϣ
		*/
		virtual void onWorkStart(WorkDataInfo *dataInfo);
		/*
		* �����лص�
		* @param dataInfo������Ϣ
		*/
		virtual int onWorking(WorkDataInfo *dataInfo);
		/*
		* ����
		*/
		virtual void start();
		/*
		* ֹͣ
		*/
		virtual void stop();
	};
}

#endif