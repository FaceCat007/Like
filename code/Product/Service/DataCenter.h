/*����FaceCat(����è)��� v1.0
 �Ϻ����è��Ϣ�������޹�˾
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


//�ͻ�����������
class DataCenter{
private:
	static void dprintf(char *format, ...);
	static IXMLDOMDocument* domFromCOM();
public:
	DataCenter();
	virtual ~DataCenter();
	//�����Ƿ��Ծ
	static bool isAppAlive();
	static void setAppAlive(bool appAlive);
	//��ȡ���Ʒ���
	static ALikeService* getALikeService();
	//��ȡ����·��
	static string getAppPath();
	//��ȡ�û��ļ���
	static string getUserPath();
	//��ȡ��Ҫ����
	static UIXmlEx* getMainUI();
	//������Ҫ����
	static void setMainUI(UIXmlEx *mainUI);
public:
	//��������
	static void startService();
};
#endif