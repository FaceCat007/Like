/*
 * FaceCatͼ��ͨѶ���(�ǿ�Դ)
 * ����Ȩ���:2015SR229355+2020SR0266727
 * �Ϻ����è��Ϣ�������޹�˾
 */

#ifdef __CDAY_H__
#else                                                                            
#define __CDAY_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"

namespace FaceCat{
	/**
		* ������
		* @param  year   ��
		* @param  month   ��
		* @param  day   ��
	*/
	class __CDAY_H__ CDay{
	public:
		int m_day;
		int m_month;
		int m_year;
	public:
		/*
		* ���캯��
		*/
		CDay(int year, int month, int day);
		/*
		* ��������
		*/
		virtual ~CDay();
		/**
		 * ��ȡ��
		 */
		int getDay();
		/**
		 * ��ȡ��
		 */
		int getMonth();
		/**
		 * ��ȡ��
		 */
		int getYear();
	};
}