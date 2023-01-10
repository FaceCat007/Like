/*基于FaceCat(捂脸猫)框架 v1.0
 上海卷卷猫信息技术有限公司
 */

#ifndef __FCSTRA_H__
#define __FCSTRA_H__
#pragma once
#include "stdafx.h"
#include "objbase.h"
#pragma comment(lib,"ole32.lib") 

/*
* 字符串处理
*/
class FCStrEx{
public:
	//转化为千分位
	static String convertThousands(double value, int digit);
	//数据库代码转为文件名
	static string convertDBCodeToFileName(const string& code);
	//数据库代码转为新浪代码
	static string convertDBCodeToSinaCode(const string& code);
	//数据库代码转为腾讯代码
	static string convertDBCodeToTencentCode(const string& code);
	//新浪代码转为数据库代码
	static String convertSinaCodeToDBCode(const String& code);
	//腾讯代码转为数据库代码
	static String convertTencentCodeToDBCode(const String& code);
	//获取数据库字符串
	static String getDBString(const String& strSrc);
	//获取唯一标识
	static string getGuid();
	//获取格式化日期
	static void getFormatDate(double date, wchar_t *str);
	//获取格式化日期
	static String getFormatDate(const String& format, int year, int month, int day, int hour, int minute, int second);
	//获取格式化日期
	static String getFormatDate(const String& format, int year, int month, int day, int hour, int minute, int second, int msec);
	//获取字符串的空间
	static int getStringCapacity(const string& str);
	//获取宽字符串的空间
	static int getWStringCapacity(const String& str);
};
#endif