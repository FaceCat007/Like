/*
 * FaceCatͼ��ͨѶ���(�ǿ�Դ)
 * ����Ȩ���:2015SR229355+2020SR0266727
 * �Ϻ����è��Ϣ�������޹�˾
 */

#ifdef __CBASE_H__
#else                                                                            
#define __CBASE_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include <string>
using namespace std;

namespace FaceCat{
	/*
	* 64λ����
	*/
	class __CBASE_H__ CBase64{  
	private:  
		/*
		* ��������
		*/
		CBase64();
		/*
		* ���ٶ���
		*/
		virtual ~CBase64();  
	public:  
		/*
		* ����
		*/
		static string encode(const unsigned char *Data,int DataByte);  
		/*
		* ����
		*/
		static string decode(const char *Data,int DataByte,int& OutByte);  
	};
}
