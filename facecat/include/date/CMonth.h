/*
 * FaceCatͼ��ͨѶ���(�ǿ�Դ)
 * ����Ȩ���:2015SR229355+2020SR0266727
 * �Ϻ����è��Ϣ�������޹�˾
 */

#ifdef __CMONTH_H__
#else                                                                            
#define __CMONTH_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "CDay.h"

namespace FaceCat{
	/*
	* ��
	*/
	class __CMONTH_H__ CMonth{
	public:
	    /**
		 * ������
		 */
		int m_month;
		/**
		 * ������
		 */
		int m_year;
		/*
		* ��������
		*/
		void createDays();
	public:
		/**
		* ������
		* @param  year   ��
		* @param  month  ��
		*/
		CMonth(int year, int month);
		/*
		* ��������
		*/
		virtual ~CMonth();
		/*
		* �յļ���
		*/
		HashMap<int, CDay*> m_days;
		/**
		 * ��ȡ�µ�����
		 */
		int getDaysInMonth();
		/**
		 * ��ȡ���µĵ�һ��
		 */
		CDay* getFirstDay();
		/**
		 * ��ȡ���µ����һ��
		 */
		CDay* getLastDay();
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