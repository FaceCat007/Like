/*
 * FaceCatͼ��ͨѶ���(�ǿ�Դ)
 * ����Ȩ���:2015SR229355+2020SR0266727
 * �Ϻ����è��Ϣ�������޹�˾
 */

#ifdef __HSCALE_H__
#else                                                                            
#define __HSCALE_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "..\\core\\FCPaint.h"
#include "Enums.h"
#include "CrossLineTip.h"
#include "ChartDiv.h"

namespace FaceCat{
	class ChartDiv;
	class CrossLineTip;

	/*
	* ����
	*/
	class __HSCALE_H__ HScale : public FCAttribute{
	public:
	    /**
	     * �Ƿ������û���ͼ
	     */
		bool m_allowUserPaint;
		/**
	     * ʮ���߱�ǩ
	     */
		CrossLineTip *m_crossLineTip;
		/**
	     * �������ֵ���ɫ
	     */
		HashMap<Integer, Long> m_dateColors;
		/**
	     * X�����ֵ�����
	     */
		FCFont *m_font;
		/**
	     * X��ĸ߶�
	     */
		int m_height;
		/**
	     * �������������
	     */
		HScaleType m_hScaleType;
		/**
	     * �������ּ��
	     */
		int m_interval;
		/**
	     * X���������ɫ
	     */
		Long m_scaleColor;
		/**
	     * �̶ȵ�
	     */
		ArrayList<Double> m_scaleSteps;
		/**
	     * �ı���ɫ
	     */
		Long m_textColor;
		/*
		* ����
		*/
		String m_title;
		/**
	     * ���������
	     */
		FCFont *m_titleFont;
		/**
	     * ��ʾX��
	     */
		bool m_visible;
	public:
		/*
		* ����X��
		*/
		HScale();
		/*
		* ����X��
		*/
		virtual ~HScale();
		/**
	     * ��ȡ�Ƿ������û���ͼ
	     */
		virtual bool allowUserPaint();
		/**
	     * �����Ƿ������û���ͼ
	     */
		virtual void setAllowUserPaint(bool value);
		/**
	     * ��ȡʮ���߱�ǩ
	     */
		virtual CrossLineTip* getCrossLineTip();
		/**
	     *  ��ȡ�������ֵ���ɫ
	     */
		virtual Long getDateColor(DateType dateType);
		/**
	     * �����������ֵ���ɫ
	     */
		virtual void setDateColor(DateType dateType, Long color);
		/**
	     * ��ȡX�����ֵ�����
	     */
		virtual FCFont* getFont();
		/**
	     * ����X�����ֵ�����
	     */
		virtual void setFont(FCFont *value);
		/**
	     * ��ȡX��ĸ߶�
	     */
		virtual int getHeight();
		/**
	     * ����X��ĸ߶�
	     */
		virtual void setHeight(int value);
		/**
	     * ��ȡ�������������
	     */
		virtual HScaleType getHScaleType();
		/**
	     * ���ú������������
	     */
		virtual void setHScaleType(HScaleType value);
		/**
	     * ��ȡ�������ּ��
	     */
		virtual int getInterval();
		/**
	     * �����������ּ��
	     */
		virtual void setInterval(int value);
		/**
	     * ��ȡX���������ɫ
	     */
		virtual Long getScaleColor();
		/**
	     * ����X���������ɫ
	     */
		virtual void setScaleColor(Long value);
		/**
	     * ��ȡ�ı���ɫ
	     */
		virtual Long getTextColor();
		/**
	     * �����ı���ɫ
	     */
		virtual void setTextColor(Long value);
		/*
		* ��ȡ����
		*/
		virtual String getTitle();
		/*
		* ���ñ���
		*/
		virtual void setTitle(String value);
		/**
	     * ��ȡ���������
	     */
		virtual FCFont* getTitleFont();
		/**
	     * ���ñ��������
	     */
		virtual void setTitleFont(FCFont *value);
		/**
	     * ��ȡ��ʾX��
	     */
		virtual bool isVisible();
		/**
	     * ������ʾX��
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
	     * ��ȡ�̶ȵ�
	     */
		ArrayList<Double> getScaleSteps();
		/**
	     * �ػ淽��
	     */
		virtual void onPaint(FCPaint *paint, ChartDiv *div, const FCRect& rect);
		/**
	     * �ػ�ǰ����
	     */
		virtual void onPaintBefore(FCPaint *paint, ChartDiv *div, const FCRect& rect);
		/*
		* ��������
		*/
		virtual void onScaling(double scaleFactorX, double scaleFactorY);
		/**
	     * ��������
	     */
		virtual void setAttribute(const String& name, const String& value);
		/**
	     * ���ÿ̶ȵ�
	     */
		void setScaleSteps(ArrayList<Double> scaleSteps);
	};
}