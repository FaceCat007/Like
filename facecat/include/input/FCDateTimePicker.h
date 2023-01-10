/*
 * FaceCatͼ��ͨѶ���(�ǿ�Դ)
 * ����Ȩ���:2015SR229355+2020SR0266727
 * �Ϻ����è��Ϣ�������޹�˾
 */

#ifdef __FCDATETIMEPICKER_H__
#else                                                                            
#define __FCDATETIMEPICKER_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "FCTextBox.h"
#include "..\\btn\\FCButton.h"
#include "..\\div\\FCMenu.h"
#include "..\\div\\FCMenuItem.h"
#include "..\\date\\FCCalendar.h"

namespace FaceCat{
	/*
	* ����ѡ����ͼ
	*/
	class __FCDATETIMEPICKER_H__ FCDateTimePicker : public FCTextBox{
	public:
	    /**
		 * ��ȡ����
		 */
		FCCalendar *m_calendar;
		/**
		 * ���ڸ�ʽ
		 */
		String m_customFormat;
		/**
		 * ������ť
		 */
		FCButton *m_dropDownButton;
		/**
		 * �����˵�
		 */
		FCMenu *m_dropDownMenu;
		/**
		 * �Ƿ���ʾʱ��
		 */
		bool m_showTime;
	public:
		/*
		* ���캯��
		*/
		FCDateTimePicker();
		/*
		* ��������
		*/
		virtual ~FCDateTimePicker();
		/**
		 * ��ȡ����
		 */
		virtual FCCalendar* getCalendar();
		/**
		 * ��ȡ���ڸ�ʽ
		 */
		virtual String getCustomFormat();
		/**
		 * �������ڸ�ʽ
		 */
		virtual void setCustomFormat(const String& value);
		/**
		 * ��ȡ������ť
		 */
		virtual FCButton* getDropDownButton();
		/**
		 * ��ȡ�����˵�
		 */
		virtual FCMenu* getDropDownMenu();
		/**
		 * ��ȡ�Ƿ���ʾʱ��
		 */
		virtual bool showTime();
		/**
		 * �����Ƿ���ʾʱ��
		 */
		virtual void setShowTime(bool value);
	public:
		/*
		* �����¼�
		*/
		virtual void callEvent(String eventName, Object sender, Object invoke);
		/*
		* ���ü����¼�
		*/
		virtual void callTouchEvent(String eventName, Object sender, FCTouchInfo touchInfo, Object invoke);
	    /**
		 * ��ȡ��ͼ����
		 */
		virtual String getViewType();
		/**
		* ��ȡ����ֵ
		* @param  name  ��������
		* @param  value  ��������ֵ
		* @param  type  ������������
		*/
		virtual void getAttribute(const String& name, String *value, String *type);
		/**
		 * ��ȡ���������б�
		 */
		virtual ArrayList<String> getAttributeNames();
		/**
		 * �����˵���ʾ����
		 */
		virtual void onDropDownOpening();
		/**
		 * �����ͼ����
		 */
		virtual void onLoad();
		/**
		 * ��ֵ�ı䷽��
		 */
		virtual void onSelectedTimeChanged();
		/**
		* ��������
		* @param  name  ��������
		* @param  value  ����ֵ
		*/
		virtual void setAttribute(const String& name, const String& value);
		/**
		 * ���²��ַ���
		 */
		virtual void update();
	};
}