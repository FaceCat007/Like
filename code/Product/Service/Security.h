/*基于FaceCat(捂脸猫)框架 v1.0
 上海卷卷猫信息技术有限公司
 */

#ifndef __SECURITY_H__
#define __SECURITY_H__
#pragma once
#include "..\\..\\stdafx.h"

static String CLOSE = L"CLOSE";
static String OPEN = L"OPEN";
static String HIGH = L"HIGH";
static String LOW = L"LOW";
static String VOL = L"VOL";
static String AMOUNT = L"AMOUNT";
static String AVGPRICE = L"AVGPRICE";
static int CLOSE_INDEX = 0;
static int OPEN_INDEX = 1;
static int HIGH_INDEX = 2;
static int LOW_INDEX = 3;
static int VOL_INDEX = 4;
static int AMOUNT_INDEX = 5;

/*
* 码表
*/
class Security{
public:
	Security();
	String m_code; .//代码
	String m_name; //名称
	String m_pingyin; //拼音
	int m_status; //状态
	string m_sCode;  //代码扩展
	int m_type; //类型
};

/*
* 历史数据
*/
class SecurityData{
public:
	SecurityData();
	double m_date; //日期
	double m_open; //开盘价
	double m_high; //最高价
	double m_low; //最低价
	double m_close; //收盘价
	double m_volume; //成交量
	double m_amount; //成交额
	void copy(SecurityData *data){
		m_date = data->m_date;
		m_open = data->m_open;
		m_high = data->m_high;
		m_low = data->m_low;
		m_close = data->m_close;
		m_volume = data->m_volume;
		m_amount = data->m_amount;
	}
};


/*
* 最新数据
*/
class SecurityLatestData{
public:
	SecurityLatestData();
	double m_amount; //成交额
    int m_buyVolume1; //买一量
    int m_buyVolume2; //买二量
    int m_buyVolume3; //买三量
    int m_buyVolume4; //买四量
    int m_buyVolume5; //买五量
    double m_buyPrice1; //买一价
    double m_buyPrice2; //买二价
    double m_buyPrice3; //买三价
    double m_buyPrice4; //买四价
    double m_buyPrice5; //买五价
    double m_close; //收盘价
    double m_date; //日期
    double m_high; //最高价
	int m_innerVol; //内盘
    double m_lastClose; //上次收盘价
    double m_low; //最低价
    double m_open; //开盘价
	double m_openInterest; //持仓量
	int m_outerVol; //外盘
    String m_securityCode; //代码
    int m_sellVolume1; //卖一量
    int m_sellVolume2; //卖二量
    int m_sellVolume3; //卖三量
    int m_sellVolume4; //卖四量
    int m_sellVolume5; //卖五量
    double m_sellPrice1; //卖一价
    double m_sellPrice2; //卖二价
    double m_sellPrice3; //卖三价
    double m_sellPrice4; //卖四价
    double m_sellPrice5; //卖五价
	double m_settlePrice; //结算价
	double m_turnoverRate; //换手率
    double m_volume; //成交量

	/*
	* 拷贝数据
	* @param data 数据
	*/
	void copy(SecurityLatestData *data){
		if (!data) return;
        m_amount = data->m_amount;
        m_buyVolume1 = data->m_buyVolume1;
        m_buyVolume2 = data->m_buyVolume2;
        m_buyVolume3 = data->m_buyVolume3;
        m_buyVolume4 = data->m_buyVolume4;
        m_buyVolume5 = data->m_buyVolume5;
        m_buyPrice1 = data->m_buyPrice1;
        m_buyPrice2 = data->m_buyPrice2;
        m_buyPrice3 = data->m_buyPrice3;
        m_buyPrice4 = data->m_buyPrice4;
        m_buyPrice5 = data->m_buyPrice5;
        m_close = data->m_close;
        m_date = data->m_date;
        m_high = data->m_high;
        m_innerVol = data->m_innerVol;
        m_lastClose = data->m_lastClose;
        m_low = data->m_low;
        m_open = data->m_open;
		m_openInterest = data->m_openInterest;
		m_outerVol = data->m_outerVol;
        m_securityCode = data->m_securityCode;
        m_sellVolume1 = data->m_sellVolume1;
        m_sellVolume2 = data->m_sellVolume2;
        m_sellVolume3 = data->m_sellVolume3;
        m_sellVolume4 = data->m_sellVolume4;
        m_sellVolume5 = data->m_sellVolume5;
        m_sellPrice1 = data->m_sellPrice1;
        m_sellPrice2 = data->m_sellPrice2;
        m_sellPrice3 = data->m_sellPrice3;
        m_sellPrice4 = data->m_sellPrice4;
        m_sellPrice5 = data->m_sellPrice5;
		m_settlePrice = data->m_settlePrice;
		m_turnoverRate = data->m_turnoverRate;
        m_volume = data->m_volume;
	}

	/*
	* 数据是否相等
	* @param data 数据
	*/
	bool equal(SecurityLatestData *data){
		if (!data) return false;
        if (m_amount == data->m_amount
        && m_buyVolume1 == data->m_buyVolume1
        && m_buyVolume2 == data->m_buyVolume2
        && m_buyVolume3 == data->m_buyVolume3
        && m_buyVolume4 == data->m_buyVolume4
        && m_buyVolume5 == data->m_buyVolume5
        && m_buyPrice1 == data->m_buyPrice1
        && m_buyPrice2 == data->m_buyPrice2
        && m_buyPrice3 == data->m_buyPrice3
        && m_buyPrice4 == data->m_buyPrice4
        && m_buyPrice5 == data->m_buyPrice5
        && m_close == data->m_close
        && m_date == data->m_date
        && m_high == data->m_high
        && m_innerVol == data->m_innerVol
        && m_lastClose == data->m_lastClose
        && m_low == data->m_low
        && m_open == data->m_open
		&& m_openInterest == data->m_openInterest
		&& m_outerVol == data->m_outerVol
        && m_securityCode == data->m_securityCode
        && m_sellVolume1 == data->m_sellVolume1
        && m_sellVolume2 == data->m_sellVolume2
        && m_sellVolume3 == data->m_sellVolume3
        && m_sellVolume4 == data->m_sellVolume4
        && m_sellVolume5 == data->m_sellVolume5
        && m_sellPrice1 == data->m_sellPrice1
        && m_sellPrice2 == data->m_sellPrice2
        && m_sellPrice3 == data->m_sellPrice3
        && m_sellPrice4 == data->m_sellPrice4
        && m_sellPrice5 == data->m_sellPrice5
		&& m_settlePrice == data->m_settlePrice
		&& m_turnoverRate == data->m_turnoverRate
        && m_volume == data->m_volume){
            return true;
        }
		return false;
	}
};
#endif