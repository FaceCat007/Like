/*
 * FaceCatͼ��ͨѶ���(�ǿ�Դ)
 * ����Ȩ���:2015SR229355+2020SR0266727
 * �Ϻ����è��Ϣ�������޹�˾
 */

#ifdef __FCHTTPGETSERVICE_H__
#else                                                                            
#define __FCHTTPGETSERVICE_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
namespace FaceCat{
    /**
	 * HTTP��GET����
	 */
    class __FCHTTPGETSERVICE_H__ FCHttpGetService{
    public:
		static BOOL _TryHttpSendRequest(LPVOID hRequest, int nMaxTryTimes);
		static string GetHttpWebRequest(string strUrl, int bufferSize);
		/**
		* ��ȡ��ҳ����
		* @param  url  ��ַ
		*/
        static string get(const string url);
    };
}
