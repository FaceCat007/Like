/*
 * FaceCatͼ��ͨѶ���(�ǿ�Դ)
 * ����Ȩ���:2015SR229355+2020SR0266727
 * �Ϻ����è��Ϣ�������޹�˾
 */


#ifdef __CHARTTITLEBAR_H__
#else                                                                            
#define __CHARTTITLEBAR_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "..\\core\\FCPaint.h"
#include "FCDataTable.h"
#include "Enums.h"
#include "ChartDiv.h"

namespace FaceCat{
	class ChartDiv;

	/*
	* ������
	*/
	class __CHARTTITLEBAR_H__ ChartTitle : public FCAttribute{
	public:
	    /**
	     * ����С����λ��
	     */
		int m_digit;
		/**
	     * �ֶ�����
	     */
		int m_fieldName;
		/**
	     * �ֶ�����
	     */
		String m_fieldText;
		/**
	     * ������ʾģʽ
	     */
		TextMode m_fieldTextMode;
		/**
	     * ����ķָ���
	     */
		String m_fieldTextSeparator;
		/**
	     * ���ֵ���ɫ
	     */
		Long m_textColor;
		/**
	     * �Ƿ�ɼ�
	     */
		bool m_visible;
	public:
		/**
          * ��������
         */
		ChartTitle(){}
	     /**
          * ��������
          * @param  fieldName  �ֶ�����
          * @param  fieldText  �ֶ�����
          * @param  textColor  ������ɫ
          * @param  digit      ����С��λ��
          * @param  visible    �Ƿ�ɼ�
         */
		ChartTitle(int fieldName, const String& fieldText, Long color, int digit, bool visible);
		/**
	     * ��ȡ����С����λ��
	     */
		virtual int getDigit();
		/**
	     * ���ñ���С����λ��
	     */
		virtual void setDigit(int value);
		/**
	     * ��ȡ�ֶ�����
	     */
		virtual int getFieldName();
		/**
	     * �����ֶ�����
	     */
		virtual void setFieldName(int value);
		/**
	     * ��ȡ�ֶ�����
	     */
		virtual String getFieldText();
		/**
	     * �����ֶ�����
	     */
		virtual void setFieldText(const String& value);
		/**
	     * ��ȡ������ʾģʽ
	     */
		virtual TextMode getFieldTextMode();
		/**
	     * ���ñ�����ʾģʽ
	     */
		virtual void setFieldTextMode(TextMode value);
		/**
	     * ��ȡ����ķָ���
	     */
		virtual String getFieldTextSeparator();
		/**
	     * ���ñ���ķָ���
	     */
		virtual void setFieldTextSeparator(const String& value);
		/**
	     * ��ȡ���ֵ���ɫ
	     */
		virtual Long getTextColor();
		/**
	     * �������ֵ���ɫ
	     */
		virtual void setTextColor(Long value);
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
         * ��ȡ����ֵ
         * @param name  ��������
         * @param value ��������ֵ
         * @param type  ������������
         */
		virtual void getAttribute(const String& name, String *value, String *type);
		/**
	     * ��ȡ���������б�
	     */
		virtual ArrayList<String> getAttributeNames();
	    /**
		  * ��������ֵ
		  * @param name  ��������
		  * @param value ����ֵ
        */
		virtual void setAttribute(const String& name, const String& value);
	};

	/*
	* ������
	*/
	class __CHARTTITLEBAR_H__ ChartTitleBar : public FCAttribute{
	public:
	    /**
	     * �Ƿ������û���ͼ
	     */
		bool m_allowUserPaint;
		/**
	     * ����
	     */
		FCFont *m_font;
		/*
		* ������ɫ
		*/
		Long m_textColor;
		/**
	     * ����߶�
	     */
		int m_height;
		/**
	     * ����������
	     */
		int m_maxLine;
		/**
	     * �Ƿ���ʾ�����������
	     */
		bool m_showUnderLine;
		/**
	     * ��ı���
	     */
		String m_text;
		/**
	     * �Ƿ���ʾ����������ߵ���ɫ
	     */
		Long m_underLineColor;
		/**
	     * �Ƿ���ʾ����
	     */
		bool m_visible;
	public:
	    /**
         * ͼ�������
         */
		ChartTitleBar();
		/*
		* ��������
		*/
		virtual ~ChartTitleBar();
		/*
		* ���б���
		*/
		ArrayList<ChartTitle*> m_titles;
		/**
	     * ��ȡ�Ƿ������û���ͼ
	     */
		virtual bool allowUserPaint();
		/**
	     * �����Ƿ������û���ͼ
	     */
		virtual void setAllowUserPaint(bool value);
		/**
	     * ��ȡ����
	     */
		virtual FCFont* getFont();
		/**
	     * ��������
	     */
		virtual void setFont(FCFont *value);
		/**
	     * ��ȡ����߶�
	     */
		virtual int getHeight();
		/**
	     * ���ñ���߶�
	     */
		virtual void setHeight(int value);
		/**
	     * ��ȡ����������
	     */
		virtual int getMaxLine();
		/**
	     * ��������������
	     */
		virtual void setMaxLine(int value);
		/**
	     * ��ȡ�Ƿ���ʾ�����������
	     */
		virtual bool showUnderLine();
		/**
	     * �����Ƿ���ʾ�����������
	     */
		virtual void setShowUnderLine(bool value);
		/**
	     * ��ȡ��ı���
	     */
		virtual String getText();
		/**
	     * ���ò�ı���
	     */
		virtual void setText(const String& value);
		/**
	     * ��ȡ�����������ɫ
	     */
		virtual Long getTextColor();
		/**
	     * ���ñ����������ɫ
	     */
		virtual void setTextColor(Long value);
		/**
	     * ��ȡ�Ƿ���ʾ����������ߵ���ɫ
	     */
		virtual Long getUnderLineColor();
		/**
	     * �����Ƿ���ʾ����������ߵ���ɫ
	     */
		virtual void setUnderLineColor(Long value);
		/**
	     * ��ȡ�Ƿ���ʾ����
	     */
		virtual bool isVisible();
		/**
	     * �����Ƿ���ʾ����
	     */
		virtual void setVisible(bool value);
	public:
	    /**
         * ��ȡ����ֵ
         * @param name  ��������
         * @param value ��������ֵ
         * @param type  ������������
        */
		virtual void getAttribute(const String& name, String *value, String *type);
		/**
	     * ��ȡ���������б�
	     */
		virtual ArrayList<String> getAttributeNames();
	    /**
         * �ػ淽��
         * @param paint  ��ͼ����
         * @param div    ͼ��
         * @param rect   ����
        */
		virtual void onPaint(FCPaint *paint, ChartDiv *div, const FCRect& rect);
		/*
		* ��������
		*/
		virtual void onScaling(double scaleFactorX, double scaleFactorY);
	    /**
         * ��������ֵ
         * @param name  ��������
         * @param value ����ֵ
        */
		virtual void setAttribute(const String& name, const String& value);
	};
}