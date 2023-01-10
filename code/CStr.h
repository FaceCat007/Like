/*����FaceCat(����è)��� v1.0
 �Ϻ����è��Ϣ�������޹�˾
 */

#ifndef __FCSTRA_H__
#define __FCSTRA_H__
#pragma once
#include "stdafx.h"
#include "objbase.h"
#pragma comment(lib,"ole32.lib") 

/*
* �ַ�������
*/
class FCStrEx{
public:
	//ת��Ϊǧ��λ
	static String convertThousands(double value, int digit);
	//���ݿ����תΪ�ļ���
	static string convertDBCodeToFileName(const string& code);
	//���ݿ����תΪ���˴���
	static string convertDBCodeToSinaCode(const string& code);
	//���ݿ����תΪ��Ѷ����
	static string convertDBCodeToTencentCode(const string& code);
	//���˴���תΪ���ݿ����
	static String convertSinaCodeToDBCode(const String& code);
	//��Ѷ����תΪ���ݿ����
	static String convertTencentCodeToDBCode(const String& code);
	//��ȡ���ݿ��ַ���
	static String getDBString(const String& strSrc);
	//��ȡΨһ��ʶ
	static string getGuid();
	//��ȡ��ʽ������
	static void getFormatDate(double date, wchar_t *str);
	//��ȡ��ʽ������
	static String getFormatDate(const String& format, int year, int month, int day, int hour, int minute, int second);
	//��ȡ��ʽ������
	static String getFormatDate(const String& format, int year, int month, int day, int hour, int minute, int second, int msec);
	//��ȡ�ַ����Ŀռ�
	static int getStringCapacity(const string& str);
	//��ȡ���ַ����Ŀռ�
	static int getWStringCapacity(const String& str);
};
#endif