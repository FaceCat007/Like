/*
 * FaceCatͼ��ͨѶ���(�ǿ�Դ)
 * ����Ȩ���:2015SR229355+2020SR0266727
 * �Ϻ����è��Ϣ�������޹�˾
 */

#ifdef __CROSSLINETIP_H__
#else                                                                            
#define __CROSSLINETIP_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "..\\core\\FCPaint.h"
#include "ChartDiv.h"

namespace FaceCat{
	class ChartDiv;

	/*
	* ʮ������ʾ��
	*/
	class __CROSSLINETIP_H__ CrossLineTip : public FCAttribute{
	public:
	    /**
	     * �Ƿ������û���ͼ
	     */
		bool m_allowUserPaint;
		/**
	     * X����ʾ�򱳾�ɫ
	     */
		Long m_backColor;
		/**
	     * X����ʾ�����ֵ�����
	     */
		FCFont *m_font;
		/**
	     * X����ʾ������ɫ
	     */
		Long m_textColor;
		/**
	     * �Ƿ�ɼ�
	     */
		bool m_visible;
	public:
		/*
		* ������ʾ��
		*/
		CrossLineTip();
		/*
		* ������ʾ��
		*/
		virtual ~CrossLineTip();
		/**
	     * ��ȡ�Ƿ������û���ͼ
	     */
		virtual bool allowUserPaint();
		/**
	     * �����Ƿ������û���ͼ
	     */
		virtual void setAllowUserPaint(bool value);
		/**
	     * ��ȡX����ʾ�򱳾�ɫ
	     */
		virtual Long getBackColor();
		/**
	     * ����X����ʾ�򱳾�ɫ
	     */
		virtual void setBackColor(Long value);
		/**
	     * ��ȡX����ʾ�����ֵ�����
	     */
		virtual FCFont* getFont();
		/**
	     * ����X����ʾ�����ֵ�����
	     */
		virtual void setFont(FCFont *value);
		/**
	     * ��ȡX����ʾ������ɫ
	     */
		virtual Long getTextColor();
		/**
	     * ����X����ʾ������ɫ
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
		virtual void onPaint(FCPaint *paint, ChartDiv *div, const FCRect& rect);
		/**
	     * ��ȡ���������б�
	     */
		virtual void getAttribute(const String& name, String *value, String *type);
	    /**
         * �ػ淽��
         * @param paint  ��ͼ����
         * @param div    ͼ��
         * @param rect   ����
        */
		virtual ArrayList<String> getAttributeNames();
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