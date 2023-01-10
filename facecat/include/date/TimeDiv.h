/*
 * FaceCatͼ��ͨѶ���(�ǿ�Դ)
 * ����Ȩ���:2015SR229355+2020SR0266727
 * �Ϻ����è��Ϣ�������޹�˾
 */

#ifdef __TIMEDIV_H__
#else                                                                            
#define __TIMEDIV_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "FCCalendar.h"
#include "..\\input\\FCSpin.h"

namespace FaceCat{
	class FCCalendar;

	/*
	* ʱ���
	*/
	class __TIMEDIV_H__ TimeDiv : public FCEventCallBack{
	public:
	    /**
		 * ������ͼ
		 */
		FCCalendar *m_calendar;
		/**
		 * �߶�
		 */
		int m_height;
		/**
		 * Сʱ
		 */
		FCSpin *m_spinHour;
		/**
		 * ����
		 */
		FCSpin *m_spinMinute;
		/**
		 * ��
		 */
		FCSpin *m_spinSecond;
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
		TimeDiv(FCCalendar *calendar);
		/*
		* ��������
		*/
		virtual ~TimeDiv();
		/**
		 * ��ȡ������ͼ
		 */
		virtual FCCalendar* getCalendar();
		/**
		 * ����������ͼ
		 */
		virtual void setCalendar(FCCalendar *value);
		/**
		 * ��ȡ�����ø߶�
		 */
		virtual int getHeight();
		/**
		 * ��ȡ�����ø߶�
		 */
		virtual void setHeight(int value);
		/**
		 * ��ȡ������Сʱ
		 */
		virtual int getHour();
		/**
		 * ��ȡ������Сʱ
		 */
		virtual void setHour(int value);
		/**
		 * ��ȡ�����÷���
		 */
		virtual int getMinute();
		/**
		 * ��ȡ�����÷���
		 */
		virtual void setMinute(int value);
		/**
		 *��ȡ��
		 */
		virtual int getSecond();
		/**
		 * ������
		 */
		virtual void setSecond(int value);
	public:
		virtual void callEvent(String eventName, Object sender, Object invoke);
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
		 * ��ֵ�޸��¼�
		 */
		void onSelectedTimeChanged();
		/**
		 * ���������
		 */
		void onTimer();
		/**
		 * ���²��ַ���
		 */
		void update();
	};
}