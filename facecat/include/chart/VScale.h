/*
 * FaceCatͼ��ͨѶ���(�ǿ�Դ)
 * ����Ȩ���:2015SR229355+2020SR0266727
 * �Ϻ����è��Ϣ�������޹�˾
 */

#ifdef __VSCALE_H__
#else                                                                            
#define __VSCALE_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "..\\core\\FCPaint.h"
#include "Enums.h"
#include "FCDataTable.h"
#include "CrossLineTip.h"
#include "ChartDiv.h"

namespace FaceCat{
	class ChartDiv;
	class CrossLineTip;

	/*
	* ��չ����
	*/
	class __VSCALE_H__ FCExValue
    {
	public:
        /*
		* ����
		*/
        String m_title;

        /*
		* ����
		*/
        ArrayList<double> m_values;
	public:
		/*
		* ���캯��
		*/
		FCExValue(){
		}
		/*
		* ��������
		*/
		virtual ~FCExValue(){
			m_values.clear();
		}
    };


    /**
     * Y��
     */
	class __VSCALE_H__ VScale : public FCAttribute{
	public:
		/*
		* ��չ��ɫ�ֶ�
		*/
		ArrayList<Long> m_extendColors;
		/*
		* ��չ�ֶ�
		*/
		ArrayList<FCExValue> m_extendValues;
	public:
	    /**
	     * �Ƿ������û���ͼ
	     */
		bool m_allowUserPaint;
		/**
	     * ���ֵ����Сֵ�Ƿ��Զ�����
	     */
		bool m_autoMaxMin;
		/**
	     * �����ֶ�
	     */
		int m_baseField;
		/**
	     * ʮ���߱�ǩ
	     */
		CrossLineTip *m_crossLineTip;
		/**
	     * �����ʾ��ֵ����С����λ��
	     */
		int m_digit;
		/*
		* �µ�����ɫ
		*/
		Long m_downColor;
		/**
	     * ���Y�����ֵ�����
	     */
		FCFont *m_font;
		/*
		* �ϴ����̼�
		*/
		double m_lastClose;
		/**
		* ��ʱ�����ֵ
		*/
		double m_minuteLineMaxValue;
		/*
		* ��ʱ����Сֵ
		*/
		double m_minuteLineMinValue;
		/**
	     * ����
	     */
		int m_magnitude;
		/**
	     * �����������м�ֵ
	     */
		double m_midValue;
		/**
	     * ��������
	     */
		NumberStyle m_numberStyle;
		/**
	     * ��Сֵ�Ϸ��ļ�϶����
	     */
		int m_paddingBottom;
		/**
	     * ���ֵ�Ϸ��ļ�϶����
	     */
		int m_paddingTop;
		/**
	     * �Ƿ�ת
	     */
		bool m_reverse;
		/**
	     * ������Ļ���
	     */
		Long m_scaleColor;
		/*
		* ����̶�
		*/
		ArrayList<Double> m_scaleSteps;
		/*
		* �Ƿ���ʾ��ʱ��
		*/
		bool m_showMinuteLine;
		/**
	     * ����ϵ������
	     */
		VScaleSystem m_system;
		/**
	     * Y�����ֵ���ɫ
	     */
	    Long m_textColor;
		/**
	     * Y�����ֵ���ɫ2
	     */
		Long m_textColor2;
		/*
		* ����
		*/
		String m_title;
		/**
	     * ���������
	     */
		FCFont *m_titleFont;

		/**
	     * �����������
	     */
		VScaleType m_type;
		/*
		* ���ǵ���ɫ
		*/
		Long m_upColor;
		/**
	     * ����ֵ�ɼ����ֵ����ֵ
	     */
		double m_visibleMax;
		/**
	     * ����ֵ�ɼ����ֵ���Сֵ
	     */
		double m_visibleMin;
	public:
		/*
		* ���캯��
		*/
		VScale();
		/*
		* ��������
		*/
		virtual ~VScale();
		/**
	     * ��ȡ�Ƿ������û���ͼ
	     */
		virtual bool allowUserPaint();
		/**
	     * �����Ƿ������û���ͼ
	     */
		virtual void setAllowUserPaint(bool value);
		/**
	     * ��ȡ���ֵ����Сֵ�Ƿ��Զ�����
	     */
		virtual bool autoMaxMin();
		/**
	     * �������ֵ����Сֵ�Ƿ��Զ�����
	     */
		virtual void setAutoMaxMin(bool value);
		/**
	     * ��ȡ�����ֶ�
	     */
		virtual int getBaseField();
		/**
	     * ���û����ֶ�
	     */
		virtual void setBaseField(int value);
		/**
	     * ��ȡʮ���߱�ǩ
	     */
		virtual CrossLineTip* getCrossLineTip();
		/**
	     * ��ȡ�����ʾ��ֵ����С����λ��
	     */
		virtual int getDigit();
		/**
	     * ���������ʾ��ֵ����С����λ��
	     */
		virtual void setDigit(int value);
		/*
		* ��ȡ�µ�����ɫ
		*/
		virtual Long getDownColor();
		/*
		* �����µ�����ɫ
		*/
		virtual void setDownColor(Long value);
		/**
	     * ��ȡ���Y�����ֵ�����
	     */
		virtual FCFont* getFont();
		/**
	     * ��ȡ���Y�����ֵ�����
	     */
		virtual void setFont(FCFont *value);
		/*
		* ��ȡ�ϴ����̼�
		*/
		virtual double getLastClose();
		/*
		* �����ϴ����̼�
		*/
		virtual void setLastClose(double value);
		/*
		* ��ȡ��ʱ�����ֵ
		*/
		virtual double getMinuteLineMaxValue();
		/*
		* ���÷�ʱ�����ֵ
		*/
		virtual void setMinuteLineMaxValue(double value);
		/*
		* ��ȡ��ʱ����Сֵ
		*/
		virtual double getMinuteLineMinValue();
		/*
		* ���÷�ʱ����Сֵ
		*/
		virtual void setMinuteLineMinValue(double value);
		/**
	     * ��ȡ����
	     */
		virtual int getMagnitude();
		/**
	     * ��������
	     */
		virtual void setMagnitude(int value);
		/**
	     * ��ȡ�����������м�ֵ
	     */
		virtual double getMidValue();
		/**
	     * ���������������м�ֵ
	     */
		virtual void setMidValue(double value);
		/**
	     * ��ȡ��������
	     */
		virtual NumberStyle getNumberStyle();
		/**
	     * ������������
	     */
		virtual void setNumberStyle(NumberStyle value);
		/**
	     * ��ȡ��Сֵ�Ϸ��ļ�϶����
	     */
		virtual int getPaddingBottom();
		/**
	     * ������Сֵ�Ϸ��ļ�϶����
	     */
		virtual void setPaddingBottom(int value);
		/**
	     * ��ȡ���ֵ�Ϸ��ļ�϶����
	     */
		virtual int getPaddingTop();
		/**
	     * �������ֵ�Ϸ��ļ�϶����
	     */
		virtual void setPaddingTop(int value);
		/**
	     * ��ȡ�Ƿ�ת
	     */
		virtual bool isReverse();
		/**
	     * �����Ƿ�ת
	     */
		virtual void setReverse(bool value);
		/**
	     * ��ȡ������Ļ���
	     */
		virtual Long getScaleColor();
		/**
	     * ����������Ļ���
	     */
		virtual void setScaleColor(Long value);
		/*
		* ��ȡ�Ƿ���ʾ��ʱ��
		*/
		bool showMinuteLine();
		/*
		* �����Ƿ���ʾ��ʱ��
		*/
		void setShowMinuteLine(bool value);
		/**
	     * ��ȡ����ϵ������
	     */
		virtual VScaleSystem getSystem();
		/**
	     * ��������ϵ������
	     */
		virtual void setSystem(VScaleSystem value);
		/**
	     * ��ȡY�����ֵ���ɫ
	     */
	    virtual Long getTextColor();
	    /**
	     * ����Y�����ֵ���ɫ
	     */
		virtual void setTextColor(Long value);
		/**
	     * ��ȡY�����ֵ���ɫ2
	     */
		virtual Long getTextColor2();
		/**
	     * ����Y�����ֵ���ɫ2
	     */
		virtual void setTextColor2(Long value);
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
	     * ��ȡ�����������
	     */
		virtual VScaleType getType();
		/**
	     * ���������������
	     */
		virtual void setType(VScaleType value);
		/*
		* ��ȡ���ǵ���ɫ
		*/
		virtual Long getUpColor();
		/*
		* �������ǵ���ɫ
		*/
		virtual void setUpColor(Long value);
		/**
	     * ��ȡ����ֵ�ɼ����ֵ����ֵ
	     */
		virtual double getVisibleMax();
		/**
	     * ��������ֵ�ɼ����ֵ����ֵ
	     */
		virtual void setVisibleMax(double value);
		/**
	     * ��ȡ����ֵ�ɼ����ֵ���Сֵ
	     */
		virtual double getVisibleMin();
		/**
	     * ��������ֵ�ɼ����ֵ���Сֵ
	     */
		virtual void setVisibleMin(double value);
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
	     * ��ȡ���������б�
	     */
		ArrayList<Double> getScaleSteps();
	    /**
         * �ػ淽��
         * @param paint  ��ͼ����
         * @param div    ͼ��
         * @param rect   ����
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
         * ��������ֵ
         * @param name  ��������
         * @param value ����ֵ
        */
		virtual void setAttribute(const String& name, const String& value);
		/**
	     * ���ÿ̶ȵ�
	     */
		void setScaleSteps(ArrayList<Double> scaleSteps);
	};
}