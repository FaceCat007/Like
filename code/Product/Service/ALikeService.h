/*基于FaceCat(捂脸猫)框架 v1.0
 上海卷卷猫信息技术有限公司
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
	//历史数据结构
	class SecurityHistoryData{
	public:
		//数据集合
		SecurityData **m_datas;
		//均线的数值集合
		double *m_datasMa;
		//波动率的数值集合
		double *m_datasRate;
		//数据长度
		int m_datasSize;
		//码表信息
		Security *m_security;
		//开始索引
		int m_startIndex;
	public:
		SecurityHistoryData();
		virtual ~SecurityHistoryData();
	};

	class WorkDataInfoEx : public WorkDataInfo{
	public:
		SecurityHistoryData *m_left;
	public:
		WorkDataInfoEx();
		virtual ~WorkDataInfoEx();
	};

	//相似信息
	class LikeDataInfo{
	public:
		//区别比例
		double m_diffRange;
		//左侧代码
        String m_leftCode;
		//左侧开始日期
        double m_leftStartDate;
		//左侧结束日期
        double m_leftStopDate;
		//右侧代码
        String m_rightCode;
		//右侧开始日期
        double m_rightStartDate;
		//右侧结束日期
        double m_rightStopDate;
		//打分
        int m_score;
	public:
		LikeDataInfo();
		virtual ~LikeDataInfo();
	};

	//沙盒信息
	class SandBoxInfo{
	public:
		//区间最大值
		double m_rangeMax;
		//区间最小值
		double m_rangeMin;
		//振幅下限
		double m_swingDown;
		//振幅上限
		double m_swingUp;
	public:
		SandBoxInfo();
		virtual ~SandBoxInfo();
	};

	//相似服务
	class ALikeService : public BaseWork{
	public:
		//是否完成
		bool m_completed;
		//当前数量
		int m_curCount;
		//锁
		FCLock m_lock;
		//周期1
		int m_n;
		//周期2
		int m_m;
		//最大数值
		int m_maxCount;
		//最大分数
		int m_maxScore;
		//沙盒信息
		SandBoxInfo *sandBoxInfo;
		//码表
		map<String, Security*> m_securities;
		//最新数据
		map<String, SecurityLatestData*> m_latestDatas;
	public:
		//历史数据
		map<String, SecurityHistoryData*> m_historyDatas;
		//相似信息
		map<String, vector<LikeDataInfo>> m_likeDataInfos;
	public:
		//分数排序
		static bool likeDataInfoScore1Compare(LikeDataInfo x, LikeDataInfo y);
	public:
		ALikeService();
		virtual ~ALikeService();
		//获取是否完成
		bool isCompleted();
		//获取当前数量
		int getCurCount();
		//获取或设置周期1
		int getN();
		void setN(int n);
		//获取或设置周期2
		int getM();
		void setM(int m);
		//获取或设置最大数量
		int getMaxCount();
		void setMaxCount(int maxCount);
		//获取或设置最大分数
		int getMaxScore();
		void setMaxScore(int maxScore);
	public:
		//工作退出
		virtual void onWorkQuit(WorkDataInfo *dataInfo);
		//工作开始
		virtual void onWorkStart(WorkDataInfo *dataInfo);
		//工作中
		virtual int onWorking(WorkDataInfo *dataInfo);
		//开始全面比较
		virtual void start();
		//开始个别比较
		virtual void start(const String& code, vector<LikeDataInfo> *likeDataInfos);
		//开始沙盒比较
		virtual String startSandBox(int m, vector<LikeDataInfo> *likeDataInfos);
	public:
		//获取数据
		bool getData(const String& code, vector<LikeDataInfo> *likeDataInfos);
		//加载数据step1
		void loadDatas();
		//加载数据step2
		void loadDatas2(int startIndex);
		//加载数据step3
		void loadDatas3(SecurityHistoryData *data, int datasSize, int startIndex);
	public:
		//检查图形
		void checkGraph(FCPoint *points, int pointsSize, int highY, int lowY, String *minCode, int *minStart, int *minEnd);
	public:
		static BOOL _TryHttpSendRequest(LPVOID hRequest, int nMaxTryTimes); 
		static string getHttpWebRequest(string strUrl, int bufferSize);
	};
}

#endif