/*
 * FaceCatͼ��ͨѶ���(�ǿ�Դ)
 * ����Ȩ���:2015SR229355+2020SR0266727
 * �Ϻ����è��Ϣ�������޹�˾
 */

#ifdef __FCCALENDAR_H__
#else                                                                            
#define __FCCALENDAR_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "CDay.h"
#include "CYears.h"
#include "CMonth.h"
#include "ArrowButton.h"
#include "DateTitle.h"
#include "DayButton.h"
#include "DayDiv.h"
#include "HeadDiv.h"
#include "MonthButton.h"
#include "MonthDiv.h"
#include "TimeDiv.h"
#include "YearButton.h"
#include "YearDiv.h"

namespace FaceCat{
	class ArrowButton;
	class DateTitle;
	class DayButton;
	class DayDiv;
	class HeadDiv;
	class MonthButton;
	class MonthDiv;
	class TimeDiv;
	class YearButton;
	class YearDiv;

	/*
	* ����ģʽ
	*/
	enum __FCCALENDAR_H__ FCCalendarMode{
		FCCalendarMode_Day, //ѡ����
		FCCalendarMode_Month, //ѡ����
		FCCalendarMode_Year //ѡ����
	};

	/*
	* ������ͼ
	*/
	class __FCCALENDAR_H__ FCCalendar : public FCView{
	private:
	    /**
		 * ���ID
		 */
		int m_timerID;;
	public:
	    /**
		 * ���ڲ�
		 */
		DayDiv *m_dayDiv;
		/**
		 * ͷ����
		 */
		HeadDiv *m_headDiv;
		/**
		 * ������ģʽ
		 */
		FCCalendarMode m_mode;
		/**
		 * ��ǰ���·�
		 */
		int m_month;
		/**
		 * �·ݲ�
		 */
		MonthDiv *m_monthDiv;
		/**
		 * ѡ������
		 */
		CDay *m_selectedDay;
		/**
		 * ʱ���
		 */
		TimeDiv *m_timeDiv;
		/**
		 * �Ƿ�ʹ�ö���
		 */
		bool m_useAnimation;
		/**
		 * ���
		 */
		int m_year;
		/**
		 * ��ݲ�
		 */
		YearDiv *m_yearDiv;
		/**
		 * ����
		 */
		CYears *m_years;
	public:
		/*
		* ���캯��
		*/
		FCCalendar();
		/*
		* ��������
		*/
		virtual ~FCCalendar();
		/**
		 * ��ȡ���ڲ�
		 */
		virtual DayDiv* getDayDiv();
		/**
		 * �������ڲ�
		 */
		virtual void setDayDiv(DayDiv *value);
		/**
		 * ��ȡͷ����
		 */
		virtual HeadDiv* getHeadDiv();
		/**
		 * ����ͷ����
		 */
		virtual void setHeadDiv(HeadDiv *value);
		/**
		 * ��ȡ������ģʽ
		 */
		virtual FCCalendarMode getMode();
		/**
		 * ����������ģʽ
		 */
		virtual void setMode(FCCalendarMode value);
		/**
		 * ��ȡ�·�
		 */
		virtual CMonth* getMonth();
		/**
		 * �����·�
		 */
		virtual void setMonth(CMonth *value);
		/**
		 * ��ȡ�·ݲ�
		 */
		virtual MonthDiv* getMonthDiv();
		/**
		 * �����·ݲ�
		 */
		virtual void setMonthDiv(MonthDiv *value);
		/**
		 * ��ȡѡ������
		 */
		virtual CDay* getSelectedDay();
		/**
		 * ����ѡ������
		 */
		virtual void setSelectedDay(CDay *value);
		/**
		 * ��ȡʱ���
		 */
		virtual TimeDiv* getTimeDiv();
		/**
		 * ����ʱ���
		 */
		virtual void setTimeDiv(TimeDiv *value);
		/**
		 * ��ȡ�Ƿ�ʹ�ö���
		 */
		virtual bool useAnimation();
		/**
		 * �����Ƿ�ʹ�ö���
		 */
		virtual void setUseAnimation(bool value);
		/**
		 * ��ȡ��ݲ�
		 */
		virtual YearDiv* getYearDiv();
		/**
		 * ������ݲ�
		 */
		virtual void setYearDiv(YearDiv *value);
		/**
		 * ��ȡ����
		 */
		virtual CYears* getYears();
		/**
		 * ��������
		 */
		virtual void setYears(CYears *value);
	public:
		/*
		* ��ȡ����
		*/
		static int dayOfWeek(int y, int m, int d);
		/**
		 * ��ȡ��ͼ����
		 */
		virtual String getViewType();
		/**
		* �������»�ȡ�ϸ���
		* @param  year   ��
		* @param  month   ��
		*/
		CMonth* getLastMonth(int year, int month);
		/**
		* ��ȡ�¸���
		* @param  year   ��
		* @param  month   ��
		*/
		CMonth* getNextMonth(int year, int month);
		/**
		* ��ȡ����ֵ
		* @param  name   ��������
		* @param  value  ����ֵ
		* @param  type   ����
		*/
		virtual void getAttribute(const String& name, String *value, String *type);
		/**
		 * ��ȡ���������б�
		 */
		virtual ArrayList<String> getAttributeNames();
		/**
         * ��ȡ�����б�
         */
        virtual ArrayList<String> getEventNames();
		/**
		 * �ص��ϸ���
		 */
		void goLastMonth();
		/**
		 * ǰ���¸���
		 */
		void goNextMonth();
		/**
		* �����������
		* @param  touchInfo   ������Ϣ
		*/
		virtual void onClick(FCTouchInfo touchInfo);
		/**
		 * ��ͼ������¼�
		 */
		virtual void onLoad();
		/**
		* ���̷���
		* @param  key  ����
		*/
		virtual void onKeyDown(char key);
		/**
		* �ػ汳������
		* @param  paint  ��ͼ����
		* @param  clipRect  �ü�����
		*/
		virtual void onPaintBackground(FCPaint *paint, const FCRect& clipRect);
		/**
		 * ѡ�����ڸ��ķ���
		 */
		virtual void onSelectedTimeChanged();
		/**
		* ����¼�
		* @param  timerID  �����
		*/
		virtual void onTimer(int timerID);
		/**
		* ��������ֵ
		* @param  name  ��������
		* @param  value  ����ֵ
		*/
		virtual void setAttribute(const String& name, const String& value);
		/**
		 * ���²���
		 */
		virtual void update();
public:
		/*
		* ������ͷ��ť
		*/
		virtual ArrowButton* createArrowButton();
		/*
		* ��������
		*/
		virtual DateTitle* createDateTitle();
		/*
		* �����յİ�ť
		*/ 
		virtual DayButton* createDayButton();
		/*
		* �������ڲ�
		*/
		virtual DayDiv* createDayDiv();
		/*
		* ����ͷ����
		*/
		virtual HeadDiv* createHeadDiv();
		/*
		* �����µİ�ť
		*/
		virtual MonthButton* createMonthButton();
		/*
		* �����·ݲ�
		*/
		virtual MonthDiv* createMonthDiv();
		/*
		* ����ʱ���
		*/
		virtual TimeDiv* createTimeDiv();
		/*
		* ������İ�ť
		*/ 
		virtual YearButton* createYearButton();
		/*
		* ������Ĳ�
		*/
		virtual YearDiv* createYearDiv();
	};
}