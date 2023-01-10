/*
 * FaceCatͼ��ͨѶ���(�ǿ�Դ)
 * ����Ȩ���:2015SR229355+2020SR0266727
 * �Ϻ����è��Ϣ�������޹�˾
 */

#ifdef __MONTHDIV_H__
#else                                                                            
#define __MONTHDIV_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "MonthButton.h"
#include "HeadDiv.h"
#include "TimeDiv.h"
#include "FCCalendar.h"

namespace FaceCat{
	class MonthButton;
	class HeadDiv;
	class FCCalendar;
	class TimeDiv;

	/*
	* �µĲ�
	*/
	class __MONTHDIV_H__ MonthDiv{
	public:
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
		/**
		 * ���
		 */
		int m_year;
	public:
	    /**
		 * �µİ�ť
		 */
		ArrayList<MonthButton*> m_monthButtons;
		/**
		 * �µĶ�����ť
		 */
		ArrayList<MonthButton*> m_monthButtons_am;
	public:
		/*
		* ���캯��
		*/
		MonthDiv(FCCalendar *calendar);
		/*
		* ��������
		*/
		virtual ~MonthDiv();
		/**
		 * ��ȡ������ͼ
		 */
		virtual FCCalendar* getCalendar();
		/**
		 * ����������ͼ
		 */
		virtual void setCalendar(FCCalendar *value);
		/**
		 * ��ȡ���
		 */
		virtual int getYear();
	public:
	    /**
		 * ����
		 */
		virtual void hide();
		/**
		* �����������
		* @param  mp   ����
		* @param  button   ��ť
		* @param  clicks   �������
		* @param  delta   ������
		*/
		void onClick(FCTouchInfo touchInfo);
		/**
		 * �����ͼ����
		 */
		virtual void onLoad();
		/**
		* �ػ淽��
		* @param  paint   ��ͼ����
		* @param  clipRect   �ü�����
		*/
		void onPaint(FCPaint *paint, const FCRect& clipRect);
		/**
		* ��������ͼ��
		* @param  state   ״̬
		*/
		void onResetDiv(int state);
		/**
		 * ���������
		 */
		virtual void onTimer();
		/**
		* ѡ�����
		* @param  year   ���
		*/
		virtual void selectYear(int year);
		/**
		 * ��ʾ
		 */
		virtual void show();
		/**
		 * ���²��ַ���
		 */
		void update();
	};
}