/*
 * FaceCatͼ��ͨѶ���(�ǿ�Դ)
 * ����Ȩ���:2015SR229355+2020SR0266727
 * �Ϻ����è��Ϣ�������޹�˾
 */

#ifdef __CHARTTOOLTIP_H__
#else                                                                            
#define __CHARTTOOLTIP_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "..\\core\\FCPaint.h"
#include "ChartDiv.h"

namespace FaceCat{
	class ChartDiv;

	/*
	* ��ʾ��
	*/
	class __CHARTTOOLTIP_H__ ChartToolTip : public FCAttribute{
	public:
	    /**
	     * �Ƿ������û���ͼ
	     */
		bool m_allowUserPaint;
		/**
	     * ��ʾ��ı���ɫ
	     */
		Long m_backColor;
		/**
	     * ���ߵ���ɫ
	     */
		Long m_borderColor;
		/**
	     * ��ʾ�������
	     */
		FCFont *m_font;
		/**
	     * ��ʾ���������ɫ
	     */
		Long m_textColor;
	public:
		ChartToolTip();
		/*
		* ��������
		*/
		virtual ~ChartToolTip();
		/**
	     * ��ȡ�Ƿ������û���ͼ
	     */
		virtual bool allowUserPaint();
		/**
	     * �����Ƿ������û���ͼ
	     */
		virtual void setAllowUserPaint(bool value);
		/**
	     * ��ȡ��ʾ��ı���ɫ
	     */
		virtual Long getBackColor();
		/**
	     * ������ʾ��ı���ɫ
	     */
		virtual void setBackColor(Long value);
		/**
	     * ��ȡ���ߵ���ɫ
	     */
		virtual Long getBorderColor();
		/**
	     * ���ñ��ߵ���ɫ
	     */
		virtual void setBorderColor(Long value);
		/**
	     * ��ȡ��ʾ�������
	     */
		virtual FCFont* getFont();
		/**
	     * ������ʾ�������
	     */
		virtual void setFont(FCFont *value);
		/**
	     * ��ȡ��ʾ���������ɫ
	     */
		virtual Long getTextColor();
		/**
	     * ������ʾ���������ɫ
	     */
		virtual void setTextColor(Long value);
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