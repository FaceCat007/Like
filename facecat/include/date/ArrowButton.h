/*
 * FaceCatͼ��ͨѶ���(�ǿ�Դ)
 * ����Ȩ���:2015SR229355+2020SR0266727
 * �Ϻ����è��Ϣ�������޹�˾
 */

#ifdef __ARROWBUTTON_H__
#else                                                                            
#define __ARROWBUTTON_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "..\\btn\\FCButton.h"
#include "FCCalendar.h"
#include "YearDiv.h"

namespace FaceCat{
	class FCCalendar;

	/*
	* ��ͷ��ť
	*/
	class __ARROWBUTTON_H__ ArrowButton:public FCButton{
	public:
	    /**
		 * ������ͼ
		 */
		FCCalendar *m_calendar;
		/**
		 * �Ƿ�ǰ���ϸ���
		 */
		bool m_toLast;
	public:
		/*
		* ���캯��
		*/
		ArrowButton(FCCalendar *calendar);
		/*
		* ��������
		*/
		virtual ~ArrowButton();
		/**
		 * ��ȡ������ͼ
		 */
		virtual FCCalendar* getCalendar();
		/**
		 * ����������ͼ
		 */
		virtual void setCalendar(FCCalendar *value);
		/**
		 * ��ȡ�Ƿ�ǰ���ϸ���
		 */
		virtual bool isToLast();
		/**
		 * �����Ƿ�ǰ���ϸ���
		 */
		virtual void setToLast(bool value);
	public:
	    /**
		 * ��ȡ��ͼ����
		 */
		virtual String getViewType();
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
		virtual void onPaintForeground(FCPaint *paint, const FCRect& clipRect);
	};
}