/*基于FaceCat(捂脸猫)框架 v1.0
 上海卷卷猫信息技术有限公司
 */

#ifndef __SECURITYDATAHELPER_H__
#define __SECURITYDATAHELPER_H__
#pragma once
#include "..\\..\\stdafx.h"
#include "Security.h"
#include "DataCenter.h"


class SecurityDataHelper{
public:
	SecurityDataHelper();
	virtual ~SecurityDataHelper();
public:
	static void bindHistoryDatas(FCChart *chart, FCDataTable *dataSource, vector<FCScript*> *indicators, int *fields, vector<SecurityData*> *historyDatas);
	static void bindHistoryVolAndAmountDatas(FCChart *chart, FCDataTable *dataSource, int *fields, vector<SecurityData> *historyDatas);
	static void createDataSource(FCChart *chart);
	static FCScript* createIndicator(FCChart *chart, FCDataTable *dataSource, const String& text, const String& parameters);
	static int dayOfWeek(int y, int m, int d);
	static int insertData(FCChart *chart, FCDataTable *dataSource, int *fields, SecurityData *securityData);
	static int insertLatestData(FCChart *chart, FCDataTable *dataSource, vector<FCScript*> *indicators, int *fields, SecurityData *latestData);
};

#endif