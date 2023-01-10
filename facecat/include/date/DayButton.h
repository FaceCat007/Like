/*
 * FaceCatͼ��ͨѶ���(�ǿ�Դ)
 * ����Ȩ���:2015SR229355+2020SR0266727
 * �Ϻ����è��Ϣ�������޹�˾
 */

#ifdef __DAYBUTTON_H__
#else                                                                            
#define __DAYBUTTON_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "CDay.h"
#include "FCCalendar.h"

namespace FaceCat{
	class FCCalendar;

    /**
	* ���ڰ�ť
	*/
	class __DAYBUTTON_H__ DayButton{
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
		 * ���������
		 */
		CDay *m_day;
		/**
		 * �Ƿ��ڱ���
		 */
		bool m_inThisMonth;
		/**
		 * �Ƿ�ѡ��
		 */
		bool m_selected;
		/**
		 * �Ƿ�ɼ�
		 */
		bool m_visible;
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
		DayButton(FCCalendar *calendar);
		/*
		* ��������
		*/
		virtual ~DayButton();
		/**
		 * ��ȡ��ʾ����
		 */
		virtual FCRect getBounds();
		/**
		 * ������ʾ����
		 */
		virtual void setBounds(const FCRect& value);
		/**
		 * ��ȡ������ͼ
		 */
		virtual FCCalendar* getCalendar();
		/**
		 * ����������ͼ
		 */
		virtual void setCalendar(FCCalendar *value);
		/**
		 * ��ȡ���������
		 */
		virtual CDay* getDay();
		/**
		 * ���ñ��������
		 */
		virtual void setDay(CDay *value);
		/**
		 * ��ȡ�Ƿ��ڱ���
		 */
		virtual bool inThisMonth();
		/**
		 * �����Ƿ��ڱ���
		 */
		virtual void setThisMonth(bool value);
		/**
		 * ��ȡ�Ƿ�ѡ��
		 */
		virtual bool isSelected();
		/**
		 * �����Ƿ�ѡ��
		 */
		virtual void setSelected(bool value);
		/**
		 * ��ȡ�Ƿ�ɼ�
		 */
		virtual bool isVisible();
		/**
		 * �����Ƿ�ɼ�
		 */
		virtual void setVisible(bool value);
	public:
		/**
		* ��������¼�
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