/*����FaceCat(����è)��� v1.0
 �Ϻ����è��Ϣ�������޹�˾
 */

#ifndef __SECURITYDATAHELPER_H__
#define __SECURITYDATAHELPER_H__
#pragma once
#include "..\\..\\stdafx.h"
#include "Security.h"
#include "DataCenter.h"

/*
* ֤ȯ���ݴ�����
*/
class SecurityDataHelper{
public:
	/*
	* ���캯��
	*/
	SecurityDataHelper();
	/*
	* ��������
	*/
	virtual ~SecurityDataHelper();
public:
	/*
	* ����ʷ����
	* @param chart ͼ��
	* @param dataSource ����Դ
	* @param indicators ָ��
	* @param fields �ֶ�
	* @param historyDatas ��ʷ����
	*/
	static void bindHistoryDatas(FCChart *chart, FCDataTable *dataSource, vector<FCScript*> *indicators, int *fields, vector<SecurityData*> *historyDatas);
	/*
	* �󶨳ɽ����ͳɽ���
	* @param chart ͼ��
	* @param dataSource ����Դ
	* @param fields �ֶ�
	* @param historyDatas ��ʷ����
	*/
	static void bindHistoryVolAndAmountDatas(FCChart *chart, FCDataTable *dataSource, int *fields, vector<SecurityData> *historyDatas);
	/*
	* ��������Դ
	* @param chart ͼ��
	*/
	static void createDataSource(FCChart *chart);
	/*
	* ����ָ��
	* @param chart ͼ��
	* @param dataSource ����Դ
	* @param text �ű�
	* @param parameters ����
	*/
	static FCScript* createIndicator(FCChart *chart, FCDataTable *dataSource, const String& text, const String& parameters);
	/*
	* �ж����ڼ�
	* @param y ��
	* @param m ��
	* @param d ��
	*/
	static int dayOfWeek(int y, int m, int d);
	/*
	* ��������
	* @param chart ͼ��
	* @param dataSource ����Դ
	* @param fields �ֶ�
	* @param securityData ����
	*/
	static int insertData(FCChart *chart, FCDataTable *dataSource, int *fields, SecurityData *securityData);
	/*
	* ������������
	* @param chart ͼ��
	* @param dataSource ����Դ
	* @param indicators ָ��
	* @param fields �ֶ�
	* @param latestData ����
	*/
	static int insertLatestData(FCChart *chart, FCDataTable *dataSource, vector<FCScript*> *indicators, int *fields, SecurityData *latestData);
};

#endif