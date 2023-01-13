/*基于FaceCat(捂脸猫)框架 v1.0
 上海卷卷猫信息技术有限公司
 */

#ifndef __DATACENTERCT_H__
#define __DATACENTERCT_H__
#pragma once
#include "..\\..\\stdafx.h" 
#include <atlstr.h>  
#import <msxml3.dll>
#include "..\\UI\\UIXmlEx.h"
#include "ALikeService.h"

#define hRCALL(a, errmsg) \
do{ \
    hr = (a); \
    if (FAILED(hr)){ \
        dprintf( "%s:%d  HRCALL Failed: %s\n  0x%.8x = %s\n", \
                __FILE__, __LINE__, errmsg, hr, #a ); \
        goto clean; \
    } \
} while (0)


/*
* 客户端数据中心
*/
class DataCenter{
private:
	static void dprintf(char *format, ...);
	static IXMLDOMDocument* domFromCOM();
public:
	/*
	* 程序是否活跃
	*/
	static bool isAppAlive();
	static void setAppAlive(bool appAlive);
	/*
	* 获取相似服务
	*/
	static ALikeService* getALikeService();
	/*
	* 获取启动路径
	*/
	static string getAppPath();
	/*
	* 获取用户文件夹
	*/
	static string getUserPath();
	/*
	* 获取主要界面
	*/
	static UIXmlEx* getMainUI();
	/*
	* 设置主要界面
	*/
	static void setMainUI(UIXmlEx *mainUI);
public:
	/*
	* 启动服务
	*/
	static void startService();
};
#endif