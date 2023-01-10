/*
 * FaceCatͼ��ͨѶ���(�ǿ�Դ)
 * ����Ȩ���:2015SR229355+2020SR0266727
 * �Ϻ����è��Ϣ�������޹�˾
 */

#ifdef __DATETITLE_H__
#else                                                                            
#define __DATETITLE_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "..\\btn\\FCButton.h"
#include "FCCalendar.h"

namespace FaceCat{
	class FCCalendar;

	/*
	* ����������
	*/
	class __DATETITLE_H__ DateTitle : public FCButton{
	public:
		FCCalendar *m_calendar;
	public:
		/**
		 * ���ڱ���
		 */
		DateTitle(FCCalendar *calendar);
		/*
		* ��������
		*/
		virtual ~DateTitle();
		/**
		 * ��ȡ����
		 */
		virtual FCCalendar* getCalendar();
		/**
		 * ��������
		 */
		virtual void setCalendar(FCCalendar *value);
	public:
	    /**
		 * ��ȡ��ͼ����
		 */
		virtual String getViewType();
		/**
		* �����������
		* @param  mp   ����
		* @param  button   ������ť
		* @param  clicks   �������
		* @param  delta   ����ֵ
		*/
		virtual void onClick(FCTouchInfo touchInfo);
		/**
		* �ػ�ǰ������
		* @param  paint ��ͼ����
		* @param  clipRect  	�ü�����
		*/
		virtual void onPaintForeground(FCPaint *paint, const FCRect& clipRect);
	};
}