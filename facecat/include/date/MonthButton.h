/*
 * FaceCatͼ��ͨѶ���(�ǿ�Դ)
 * ����Ȩ���:2015SR229355+2020SR0266727
 * �Ϻ����è��Ϣ�������޹�˾
 */

#ifdef __MONTHBUTTON_H__
#else                                                                            
#define __MONTHBUTTON_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "..\\btn\\FCButton.h"
#include "FCCalendar.h"

namespace FaceCat{
	class FCCalendar;

	/*
	* �µİ�ť
	*/
	class __MONTHBUTTON_H__ MonthButton:public FCButton{
	public:
	    /**
		 * ��ʾ����
		 */
		FCRect m_bounds;
		/**
		 * ������ͼ
		 */
		FCCalendar *m_calendar;
		/**
		 * ��
		 */
		int m_month;
		/**
		 * �Ƿ�ɼ�
		 */
		bool m_visible;
		/**
		 * ��
		 */
		int m_year;
	public:
	    /**
		 * ��ȡ���Ƶı���ɫ
		 */
		virtual Long getPaintingBackColor();
		/**
		 * ��ȡ���Ƶı�����ɫ
		 */
		virtual Long getPaintingBorderColor();
		/**
		 * ��ȡҪ���Ƶ�ǰ��ɫ
		 */
		virtual Long getPaintingTextColor();
	public:
		/*
		* ���캯��
		*/
		MonthButton(FCCalendar *calendar);
		/*
		* ��������
		*/
		virtual ~MonthButton();
		/**
		 * ��ȡ������ͼ
		 */
		virtual FCCalendar* getCalendar();
		/**
		 * ����������ͼ
		 */
		virtual void setCalendar(FCCalendar *value);
		/**
		 * ��ȡ��ʾ����
		 */
		virtual FCRect getBounds();
		/**
		 * ������ʾ����
		 */
		virtual void setBounds(const FCRect& value);
		/**
		 * ��ȡ��
		 */
		virtual int getMonth();
		/**
		 * ������
		 */
		virtual void setMonth(int value);
		/**
		 * ��ȡ�Ƿ�ɼ�
		 */
		virtual bool isVisible();
		/**
		 * �����Ƿ�ɼ�
		 */
		virtual void setVisible(bool value);
		/**
		 * ��ȡ��
		 */
		virtual int getYear();
		/**
		 * ������
		 */
		virtual void setYear(int value);
	public:
	    /**
		 * ��ȡ�µ�����
		 */
		virtual String getMonthStr();
		/**
		* �����������
		* @param  touchInfo   ������Ϣ
		*/
		virtual void onClick(FCTouchInfo touchInfo);
		/**
		* �ػ汳������
		* @param  paint   ��ͼ����
		* @param  clipRect   �ü�����
		*/
		virtual void onPaintBackground(FCPaint *paint, const FCRect& clipRect);
		/**
		* �ػ���߷���
		* @param  paint   ��ͼ����
		* @param  clipRect   �ü�����
		*/
		virtual void onPaintBorder(FCPaint *paint, const FCRect& clipRect);
		/**
		* �ػ�ǰ������
		* @param  paint   ��ͼ����
		* @param  clipRect   �ü�����
		*/
		virtual void onPaintForeground(FCPaint *paint, const FCRect& clipRect);
	};
}