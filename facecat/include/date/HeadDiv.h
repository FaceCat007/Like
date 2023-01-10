/*
 * FaceCatͼ��ͨѶ���(�ǿ�Դ)
 * ����Ȩ���:2015SR229355+2020SR0266727
 * �Ϻ����è��Ϣ�������޹�˾
 */

#ifdef __HEADDIV_H__
#else                                                                            
#define __HEADDIV_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "CDay.h"
#include "FCCalendar.h"
#include "DateTitle.h"

namespace FaceCat{
	class ArrowButton;
	class DateTitle;

	/*
	* ͷ����
	*/
	class __HEADDIV_H__ HeadDiv:public FCView{
	public:
	    /**
		 * ����
		 */
		FCCalendar *m_calendar;
		/**
		 * ���ڱ���
		 */
		DateTitle *m_dateTitle;
		/**
		 * �ϸ����ڵİ�ť
		 */
		ArrowButton *m_lastBtn;
		/**
		 * �¸����ڵİ�ť
		 */
		ArrowButton *m_nextBtn;
		/*
		* ��������
		*/
		String m_weekStrings[7];
	public:
		/*
		* ���캯��
		*/
		HeadDiv(FCCalendar *calendar);
		/*
		* ��������
		*/
		virtual ~HeadDiv();
		/**
		 * ��ȡ����
		 */
		virtual FCCalendar* getCalendar();
		/**
		 * ��������
		 */
		virtual void setCalendar(FCCalendar *value);
		/**
		 * ��ȡ���ڱ���
		 */
		virtual DateTitle* getDateTitle();
		/**
		 * �������ڱ���
		 */
		virtual void setDateTitle(DateTitle *value);
		/**
		 * ��ȡ���ϸ����ڵİ�ť
		 */
		virtual ArrowButton* getLastBtn();
		/**
		 * ���õ��ϸ����ڵİ�ť
		 */
		virtual void setLastBtn(ArrowButton *value);
		/**
		 * ��ȡ���¸����ڵİ�ť
		 */
		virtual ArrowButton* getNextBtn();
		/**
		 * ���õ��¸����ڵİ�ť
		 */
		virtual void setNextBtn(ArrowButton *value);
	public:
	    /**
		 * ��ȡ��ͼ����
		 */
		virtual String getViewType();
		/**
		 * �����ͼ����
		 */
		virtual void onLoad();
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
		/**
		 * ���ָ��·���
		 */
		virtual void update();
	};
}
