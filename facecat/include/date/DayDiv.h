/*
 * FaceCatͼ��ͨѶ���(�ǿ�Դ)
 * ����Ȩ���:2015SR229355+2020SR0266727
 * �Ϻ����è��Ϣ�������޹�˾
 */

#ifdef __DAYDIV_H__
#else                                                                            
#define __DAYDIV_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "DayButton.h"
#include "CYears.h"
#include "CMonth.h"
#include "CDay.h"
#include "HeadDiv.h"
#include "TimeDiv.h"

namespace FaceCat{
	class DayButton;
	class HeadDiv;
	class FCCalendar;
	class TimeDiv;
	/**
	 * �������ڲ�
	 */
	class __DAYDIV_H__ DayDiv{
	public:
	    /**
		 * ���ʱ�����µ���
		 */
		int m_am_ClickRowFrom;
		/**
		 * ���ʱ�ĵ��µ���
		 */
		int m_am_ClickRowTo;
		/**
		 * �����ķ���
		 */
		int m_am_Direction;
		/**
		 * ������ǰ֡��
		 */
		int m_am_Tick;
		/**
		 * ������֡��
		 */
		int m_am_TotalTick;
		/**
		 * ������ͼ
		 */
		FCCalendar *m_calendar;
	public:
	    /**
		 * ���ڲ�ļ���
		 */
		ArrayList<DayButton*> m_dayButtons;
		/**
		 * �������ڲ�ļ���
		 */
		ArrayList<DayButton*> m_dayButtons_am;
	public:
		/*
		* ���캯��
		*/
		DayDiv(FCCalendar *calendar);
		/*
		* ��������
		*/
		virtual ~DayDiv();
		/**
		 * ��ȡ������ͼ
		 */
		virtual FCCalendar* getCalendar();
		/**
		 * ����������ͼ
		 */
		virtual void setCalendar(FCCalendar *value);
	public:
	    /**
		 * ����
		 */
		void hide();
		/**
		* ��������¼�
		* @param  touchInfo   ������Ϣ
		*/
		void onClick(FCTouchInfo touchInfo);
		/**
		 * �����ͼ����
		 */
		void onLoad();
		/**
		* �ػ淽��
		* @param  paint   ��ͼ����
		* @param  clipRect   �ü�����
		*/
		void onPaint(FCPaint *paint, const FCRect& clipRect);
		/**
		* ��������ͼ��
		* @param  state  ״̬
		*/
		void onResetDiv(int state);
		/**
		 * ���������
		 */
		void onTimer();
		/**
		* ѡ������
		* @param  selectedDay  ����
		*/
		void selectDay(CDay *selectedDay);
		/**
		 * ��ʾ
		 */
		void show();
		/**
		 * ���²��ַ���
		 */
		void update();
	};
}