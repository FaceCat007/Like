/*
 * FaceCatͼ��ͨѶ���(�ǿ�Դ)
 * ����Ȩ���:2015SR229355+2020SR0266727
 * �Ϻ����è��Ϣ�������޹�˾
 */

#ifdef __CYEARS_H__
#else                                                                            
#define __CYEARS_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "CYear.h"

namespace FaceCat{
	/*
	* ��ļ���
	*/
	class __CYEARS_H__ CYears{
	public:
	    /**
		 * ����
		 */
		CYears();
		virtual ~CYears();
		/**
		 * ��ļ���
		 */
		HashMap<Integer,CYear*> Years;
		/**
		* ��ȡ��
		* @param  year ���
		*/
		CYear* getYear(int year);
	};
}
