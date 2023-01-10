/*
 * FaceCatͼ��ͨѶ���(�ǿ�Դ)
 * ����Ȩ���:2015SR229355+2020SR0266727
 * �Ϻ����è��Ϣ�������޹�˾
 */

#ifdef __YEARDIV_H__
#else                                                                            
#define __YEARDIV_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "YearButton.h"
#include "HeadDiv.h"
#include "TimeDiv.h"

namespace FaceCat{
	class FCCalendar;
	class HeadDiv;
	class YearButton;
	class TimeDiv;

	/*
	* ��Ĳ�
	*/
	class __YEARDIV_H__ YearDiv{
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
		 * ��ʼ���
		 */
		int m_startYear;
	public:
	    /**
		 * �µİ�ť
		 */
		ArrayList<YearButton*> m_yearButtons;
		/**
		 * �µĶ�����ť
		 */
		ArrayList<YearButton*> m_yearButtons_am;
	public:
		/*
		* ���캯��
		*/
		YearDiv(FCCalendar *calendar);
		/*
		* ��������
		*/
		virtual ~YearDiv();
		/**
		 * ��ȡ������ͼ
		 */
		virtual FCCalendar* getCalendar();
		/**
		 * ����������ͼ
		 */
		virtual void setCalendar(FCCalendar *value);
		/**
		 * ��ȡ��ʼ���
		 */
		virtual int getStartYear();
	public:
	    /**
		 * ����
		 */
		void hide();
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
		* ѡ��ʼ���
		* @param  startYear  ��ʼ���
		*/
		void selectStartYear(int startYear);
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