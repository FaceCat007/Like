/*
 * FaceCatͼ��ͨѶ���(�ǿ�Դ)
 * ����Ȩ���:2015SR229355+2020SR0266727
 * �Ϻ����è��Ϣ�������޹�˾
 */

#ifdef __CYEAR_H__
#else                                                                            
#define __CYEAR_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "CMonth.h"

namespace FaceCat{
	/**
		* ������
		* @param  year   ���
	*/
	class __CYEAR_H__ CYear{
	public:
	    /**
		 * ���
		 */
		int m_year;
		void createMonths();
	public:
	    /**
		 * ��ȡ���
		 */
		CYear(int year);
		/*
		* ��������
		*/
		virtual ~CYear();
		/**
		 * ��ȡ�������µļ���
		 */
		HashMap<Integer,CMonth*> Months;
	};
}
