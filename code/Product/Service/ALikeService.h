/*����FaceCat(����è)��� v1.0
 �Ϻ����è��Ϣ�������޹�˾
 */

#ifndef __ALIKESERVICE_H__
#define __ALIKESERVICE_H__
#pragma once
#include "..\\..\\stdafx.h"
#include <time.h>
#include "Security.h"
#include "MultiThreadWork.h"
#include <wininet.h>
#pragma comment(lib, "wininet.lib")

#define  DOWNHELPER_AGENTNAME         "SECURITY"  
#define  LEN_OF_BUFFER_FOR_QUERYINFO  128  
#define  MAX_DOWNLOAD_REQUEST_TIME    10   

namespace FaceCat{
	/*
	* ��ʷ���ݽṹ
	*/
	class SecurityHistoryData{
	public:
		/*
		* ���ݼ���
		*/
		SecurityData **m_datas;
		/*
		* ���ߵ���ֵ����
		*/
		double *m_datasMa;
		/*
		* �����ʵ���ֵ����
		*/
		double *m_datasRate;
		/*
		* ���ݳ���
		*/
		int m_datasSize;
		/*
		* �����Ϣ
		*/
		Security *m_security;
		/*
		* ��ʼ����
		*/
		int m_startIndex;
	public:
		/*
		* ���캯��
		*/
		SecurityHistoryData();
		/*
		* ��������
		*/
		virtual ~SecurityHistoryData();
	};

	/*
	* ������Ϣ��չ
	*/
	class WorkDataInfoEx : public WorkDataInfo{
	public:
		/*
		* ��ʷ����
		*/
		SecurityHistoryData *m_left;
	public:
		/*
		* ���캯��
		*/
		WorkDataInfoEx();
		/*
		* ��������
		*/
		virtual ~WorkDataInfoEx();
	};

	/*
	* ������Ϣ
	*/
	class LikeDataInfo{
	public:
		/*
		* �������
		*/
		double m_diffRange;
		/*
		* ������
		*/
        String m_leftCode;
		/*
		* ��࿪ʼ����
		*/
        double m_leftStartDate;
		/*
		* ����������
		*/
        double m_leftStopDate;
		/*
		* �Ҳ����
		*/
        String m_rightCode;
		/*
		* �Ҳ࿪ʼ����
		*/
        double m_rightStartDate;
		/*
		* �Ҳ��������
		*/
        double m_rightStopDate;
		/*
		* ���
		*/
        int m_score;
	public:
		/*
		* ���캯��
		*/
		LikeDataInfo();
		/*
		* ��������
		*/
		virtual ~LikeDataInfo();
	};

	/*
	* ɳ����Ϣ
	*/
	class SandBoxInfo{
	public:
		/*
		* �������ֵ
		*/
		double m_rangeMax;
		/*
		* ������Сֵ
		*/
		double m_rangeMin;
		/*
		* �������
		*/
		double m_swingDown;
		/*
		* �������
		*/
		double m_swingUp;
	public:
		/*
		* ���캯��
		*/
		SandBoxInfo();
		/*
		* ��������
		*/
		virtual ~SandBoxInfo();
	};

	/*
	* ���Ʒ���
	*/
	class ALikeService : public BaseWork{
	public:
		/*
		* �Ƿ����
		*/
		bool m_completed;
		/*
		* ��ǰ����
		*/
		int m_curCount;
		/*
		* ��
		*/
		FCLock m_lock;
		/*
		* ����1
		*/
		int m_n;
		/*
		* ����2
		*/
		int m_m;
		/*
		* �����ֵ
		*/
		int m_maxCount;
		/*
		* ������
		*/
		int m_maxScore;
		/*
		* ɳ����Ϣ
		*/
		SandBoxInfo *sandBoxInfo;
		/*
		* ���
		*/
		map<String, Security*> m_securities;
		/*
		* ��������
		*/
		map<String, SecurityLatestData*> m_latestDatas;
	public:
		/*
		* ��ʷ����
		*/
		map<String, SecurityHistoryData*> m_historyDatas;
		/*
		* ������Ϣ
		*/
		map<String, vector<LikeDataInfo>> m_likeDataInfos;
	public:
		/*
		* ��������
		* @param x ��һ������
		* @param y �ڶ�������
		*/
		static bool likeDataInfoScore1Compare(LikeDataInfo x, LikeDataInfo y);
	public:
		/*
		* ���캯��
		*/
		ALikeService();
		/*
		* ��������
		*/
		virtual ~ALikeService();
		/*
		* ��ȡ�Ƿ����
		*/
		bool isCompleted();
		/*
		* ��ȡ��ǰ����
		*/
		int getCurCount();
		/*
		* ��ȡ����������1
		*/
		int getN();
		void setN(int n);
		/*
		* ��ȡ����������2
		*/
		int getM();
		void setM(int m);
		/*
		* ��ȡ�������������
		*/
		int getMaxCount();
		void setMaxCount(int maxCount);
		/*
		* ��ȡ������������
		*/
		int getMaxScore();
		void setMaxScore(int maxScore);
	public:
		/*
		* �����˳�
		* @param dataInfo ������Ϣ
		*/
		virtual void onWorkQuit(WorkDataInfo *dataInfo);
		/*
		* ������ʼ
		* @param dataInfo ������Ϣ
		*/
		virtual void onWorkStart(WorkDataInfo *dataInfo);
		/*
		* ������
		* @param dataInfo ������Ϣ
		*/
		virtual int onWorking(WorkDataInfo *dataInfo);
		/*
		* ��ʼȫ��Ƚ�
		*/
		virtual void start();
		/*
		* ��ʼ����Ƚ�
		* @param ����
		* @param likeDataInfos ����
		*/ 
		virtual void start(const String& code, vector<LikeDataInfo> *likeDataInfos);
		/*
		* ��ʼɳ�бȽ�
		* @param m ����
		* @likeDataInfos ����
		*
		*/ 
		virtual String startSandBox(int m, vector<LikeDataInfo> *likeDataInfos);
	public:
		/*
		* ��ȡ����
		* @param code ����
		* @param likeDataInfos ����
		*/
		bool getData(const String& code, vector<LikeDataInfo> *likeDataInfos);
		/*
		* ��������step1
		*/
		void loadDatas();
		/*
		* ��������step2
		* @param startIndex ����
		*/
		void loadDatas2(int startIndex);
		/*
		* ��������step3
		* @param data ����
		* @param datasSize ���ݳ���
		* @param startIndex ��ʼ����
		*/
		void loadDatas3(SecurityHistoryData *data, int datasSize, int startIndex);
	public:
		/*
		* ���ͼ��
		* @param points ���꼯��
		* @param pointsSize ���ϵĴ�С
		* @param highY ���ֵ
		* @param lowY ��Сֵ
		* @param minCode ����
		* @param minStart ��ʼ
		* @param minEnd ����
		*/
		void checkGraph(FCPoint *points, int pointsSize, int highY, int lowY, String *minCode, int *minStart, int *minEnd);
	public:
		/*
		* Զ�����ݻص�
		* @param hRequest ����
		* @param nMaxTryTimes ����Դ���
		*/
		static BOOL _TryHttpSendRequest(LPVOID hRequest, int nMaxTryTimes); 
		/*
		* Http����
		* @param strUrl ��ַ
		* @param bufferSize �����С
		*/
		static string getHttpWebRequest(string strUrl, int bufferSize);
		/*
		* ���˴���תΪ���ݿ����
		* @param code ����
		*/
		static String convertSinaCodeToDBCode(const String& code);
		/*
		* ���ݿ����תΪ���˴���
		* @param code ����
		*/
		static string convertDBCodeToSinaCode(const string& code);
	};
}

#endif