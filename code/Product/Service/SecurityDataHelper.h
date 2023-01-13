/*基于FaceCat(捂脸猫)框架 v1.0
 上海卷卷猫信息技术有限公司
 */

#ifndef __SECURITYDATAHELPER_H__
#define __SECURITYDATAHELPER_H__
#pragma once
#include "..\\..\\stdafx.h"
#include "Security.h"
#include "DataCenter.h"

/*
* 证券数据处理类
*/
class SecurityDataHelper{
public:
	/*
	* 构造函数
	*/
	SecurityDataHelper();
	/*
	* 析构函数
	*/
	virtual ~SecurityDataHelper();
public:
	/*
	* 绑定历史数据
	* @param chart 图形
	* @param dataSource 数据源
	* @param indicators 指标
	* @param fields 字段
	* @param historyDatas 历史数据
	*/
	static void bindHistoryDatas(FCChart *chart, FCDataTable *dataSource, vector<FCScript*> *indicators, int *fields, vector<SecurityData*> *historyDatas);
	/*
	* 绑定成交量和成交额
	* @param chart 图形
	* @param dataSource 数据源
	* @param fields 字段
	* @param historyDatas 历史数据
	*/
	static void bindHistoryVolAndAmountDatas(FCChart *chart, FCDataTable *dataSource, int *fields, vector<SecurityData> *historyDatas);
	/*
	* 创建数据源
	* @param chart 图形
	*/
	static void createDataSource(FCChart *chart);
	/*
	* 创建指标
	* @param chart 图形
	* @param dataSource 数据源
	* @param text 脚本
	* @param parameters 参数
	*/
	static FCScript* createIndicator(FCChart *chart, FCDataTable *dataSource, const String& text, const String& parameters);
	/*
	* 判断星期几
	* @param y 年
	* @param m 月
	* @param d 日
	*/
	static int dayOfWeek(int y, int m, int d);
	/*
	* 插入数据
	* @param chart 图形
	* @param dataSource 数据源
	* @param fields 字段
	* @param securityData 数据
	*/
	static int insertData(FCChart *chart, FCDataTable *dataSource, int *fields, SecurityData *securityData);
	/*
	* 插入最新数据
	* @param chart 图形
	* @param dataSource 数据源
	* @param indicators 指标
	* @param fields 字段
	* @param latestData 数据
	*/
	static int insertLatestData(FCChart *chart, FCDataTable *dataSource, vector<FCScript*> *indicators, int *fields, SecurityData *latestData);
};

#endif