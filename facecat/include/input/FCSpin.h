/*
 * FaceCatͼ��ͨѶ���(�ǿ�Դ)
 * ����Ȩ���:2015SR229355+2020SR0266727
 * �Ϻ����è��Ϣ�������޹�˾
 */

#ifdef __FCSPIN_H__
#else                                                                            
#define __FCSPIN_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "..\\core\\FCTran.h"
#include "FCTextBox.h"
#include "..\\btn\\FCButton.h"

namespace FaceCat{
	/*
	* ��ֵѡ��
	*/
	class __FCSPIN_H__ FCSpin : public FCTextBox{
	private:
	    /**
		 * ���ID
		 */
		int m_timerID;
		/**
		 * TICKֵ
		 */
		int m_tick;
	public:
	    /**
		 * �Ƿ��Զ���ʽ��
		 */
		bool m_autoFormat;
		/**
         * �Ƿ��Զ���ʽ������
         */
        bool m_autoFormatInput;
		/**
		 * ����С����λ��
		 */
		int m_digit;
		/**
		 * ���°�ť
		 */
		FCButton *m_downButton;
		/**
		 * �Ƿ���������
		 */
		bool m_isAdding;
		/**
		 * �Ƿ����ڼ���
		 */
		bool m_isReducing;
		/**
		 * ���ֵ
		 */
		double m_maximum;
		/**
		 * ��Сֵ
		 */
		double m_minimum;
		/**
		 * �Ƿ���ʾǧ��λ
		 */
		bool m_showThousands;
		/**
		 * ��ֵ��������
		 */
		double m_step;
		/**
		 * ��ȡ���ϰ�ť
		 */
		FCButton *m_upButton;
	public:
		/*
		* ���캯��
		*/
		FCSpin();
		/*
		* ��������
		*/
		virtual ~FCSpin();
		/**
		 * ��ȡ�Ƿ��Զ���ʽ��
		 */
		virtual bool autoFormat();
		/**
		 * �����Ƿ��Զ���ʽ��
		 */
		virtual void setAutoFormat(bool value);
		/**
         * ��ȡ�Ƿ��Զ���ʽ������
         */
        virtual bool autoFormatInput();
        /**
         * �����Ƿ��Զ���ʽ������
         */
        virtual void setAutoFormatInput(bool value);
		/**
		 * ��ȡ����С����λ��
		 */
		virtual int getDigit();
		/**
		 * ���ñ���С����λ��
		 */
		virtual void setDigit(int value);
		/**
		 * ��ȡ���°�ť
		 */
		virtual FCButton* getDownButton();
		/**
		 * ��ȡ�Ƿ���������
		 */
		virtual bool isAdding();
		/**
		 * �����Ƿ���������
		 */
		virtual void setIsAdding(bool value);
		/**
		 * ��ȡ�Ƿ����ڼ���
		 */
		virtual bool isReducing();
		/**
		 * �����Ƿ����ڼ���
		 */
		virtual void setIsReducing(bool value);
		/**
		 * ��ȡ���ֵ
		 */
		virtual double getMaximum();
		/**
		 * �������ֵ
		 */
		virtual void setMaximum(double value);
		/**
		 * ��ȡ��Сֵ
		 */
		virtual double getMinimum();
		/**
		 * ������Сֵ
		 */
		virtual void setMinimum(double value);
		/**
		 * ��ȡ�Ƿ���ʾǧ��λ
		 */
		virtual bool showThousands();
		/**
		 * �����Ƿ���ʾǧ��λ
		 */
		virtual void setShowThousands(bool value);
		/**
		 * ��ȡ��ֵ��������
		 */
		virtual double getStep();
		/**
		 * ������ֵ��������
		 */
		virtual void setStep(double value);
		/**
		 * �����ı�
		 */
		virtual void setText(const String& value);
		/**
		 * ��ȡ���ϰ�ť
		 */
		virtual FCButton* getUpButton();
		/**
		 * ��ȡ������ֵ
		 */
		virtual double getValue();
		/**
		 * ���õ�����ֵ
		 */
		virtual void setValue(double value);
	public:
	    /**
		 *
		 * ����ָ�����ȵ���ֵ
		 */
		virtual void add();
		/*
		* �����¼�
		*/
		virtual void callTouchEvent(String eventName, Object sender, FCTouchInfo touchInfo, Object invoke);
		/**
		 * ���ı�ת��Ϊǧ��λ��ʾ
		 */
		virtual String formatNum(String inputText);
		/**
         * ��ȡ�����б�
         */
        virtual ArrayList<String> getEventNames();
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
		 * �������ַ���
		 */
		virtual void onChar(wchar_t ch);
		/**
		 * ���̰��·���
		 */
		virtual void onKeyDown(char key);
		/*
         * ��ʧ���㷽��
         */
        virtual void onLostFocus();
		/**
		 * �����ͼ����
		 */
		virtual void onLoad();
		/**
		 * ������������
		 */
		virtual void onTouchWheel(FCTouchInfo touchInfo);
		/**
		 * ճ������
		 */
		virtual void onPaste();
		/**
		 * ����¼�
		 */
		virtual void onTimer(int timerID);
		/**
		 * ��ֵ�ı䷽��
		 */
		virtual void onValueChanged();
		/**
		 * ����ָ�����ȵ���ֵ
		 */
		virtual void reduce();
		/**
		* ��������
		* @param  name  ��������
		* @param  value  ����ֵ
		*/
		virtual void setAttribute(const String& name, const String& value);
		/**
		 * ��������
		 */
		virtual void setRegion();
		/**
		 * ���²��ַ���
		 */
		virtual void update();
	};
}
