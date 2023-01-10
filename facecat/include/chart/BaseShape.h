/*
 * FaceCatͼ��ͨѶ���(�ǿ�Դ)
 * ����Ȩ���:2015SR229355+2020SR0266727
 * �Ϻ����è��Ϣ�������޹�˾
 */

#ifdef __BASESHAPE_H__
#else                                                                            
#define __BASESHAPE_H__ _declspec(dllexport) 
#endif

#pragma once
#include "..\\..\\stdafx.h"
#include "..\\core\\FCPaint.h"
#include "Enums.h"
#include "FCChart.h"
#include "ChartDiv.h"
#include "FCDataTable.h"

namespace FaceCat{
	class ChartDiv;
	class FCChart;
	/**
     * ���������ĸ���
     */
	class __BASESHAPE_H__ BaseShape : public FCAttribute{
	public:
		/*
		* ��չ��ɫ�ֶ�
		*/
		ArrayList<Long> m_extendColors;
		/*
		* ��չ�ֶ�
		*/
		ArrayList<int> m_extendFields;
	public:
		/*
		*�Ƿ������û���ͼ
		*/
		bool m_allowUserPaint;
		/*
		*���������ỹ������
		*/
		AttachVScale m_attachVScale;
		/*
		*�Ƿ������Y��
		*/
		bool m_fillVScale;
		/*
		* ����
		*/
		String m_name;
		/*
		*�Ƿ�ѡ��
		*/
		bool m_selected;
		/*
		* ����
		*/
		String m_title;
		/*
		*�Ƿ�ɼ�
		*/
		bool m_visible;
		/*
		*��ͼ˳��
		*/
		int m_zOrder;
	public:
		/*
		* ���캯��
		*/
		BaseShape();
		/*
		* ��������
		*/
		virtual ~BaseShape();
		/**
	     * ��ȡ�Ƿ������û���ͼ
	     */
		virtual bool allowUserPaint();
		/**
	     * �����Ƿ������û���ͼ
	     */
		virtual void setAllowUserPaint(bool value);
		/**
	     * ��ȡ���������ỹ������
	     */
		virtual AttachVScale getAttachVScale();
		/**
	     * �������������ỹ������
	     */
		virtual void setAttachVScale(AttachVScale value);
		/*
		* ��ȡ�Ƿ������Y��
		*/
		virtual bool fillVScale();
		/*
		* �����Ƿ������Y��
		*/
		virtual void setFillVScale(bool value);
		/*
		* ��ȡ����
		*/
		virtual String getName();
		/*
		* ��������
		*/ 
		virtual void setName(String value);
		/**
	     *  ��ȡ�Ƿ�ѡ��
	     */
		virtual bool isSelected();
		/**
	     *  �����Ƿ�ѡ��
	     */
		virtual void setSelected(bool value);
		/**
	     *  ��ȡ�Ƿ�ѡ��
	     */
		virtual String getTitle();
		/**
	     *  �����Ƿ�ѡ��
	     */
		virtual void setTitle(String value);

		/**
	     * ��ȡͼ���Ƿ�ɼ�
	     */
		virtual bool isVisible();
		/**
	     * ����ͼ���Ƿ�ɼ�
	     */
		virtual void setVisible(bool value);
		/**
	     * ��ȡ��ͼ˳��
	     */
		virtual int getZOrder();
		/**
	     * ���û�ͼ˳��
	     */
		virtual void setZOrder(int value);
	public:
	    /**
	     * ��ȡ�����ֶ�
	     */
		virtual int getBaseField();
	    /**
        * ���ֶ����ƻ�ȡ�ֶα���
        * @param fieldName  �ֶ�����
        * @returns �ֶα���
        */
		virtual String getFieldText(int fieldName);
		/**
	     * ��ȡ�����ֶ�
	     */
		virtual int* getFields(int *length);
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
	     * ��ȡѡ�е����ɫ
	     */
		virtual Long getSelectedColor();
	    /**
        * �ػ淽��
        * @param paint  ��ͼ����
        * @param div    ͼ��
        * @param rect   ����
        */
		virtual void onPaint(FCPaint *paint, ChartDiv *div, const FCRect& rect);
	    /**
        * ��������ֵ
        * @param name  ��������
        * @param value ����ֵ
        */
		virtual void setAttribute(const String& name, const String& value);
	};

	/*
	* K��
	*/
	class __BASESHAPE_H__ CandleShape : public BaseShape{
	public:
		/**
	     * ���̼��ֶ�
	     */
		int m_closeField;
		/**
	     * ���̼۵���ʾ����
	     */
		String m_closeFieldText;
		/**
	     * ��ɫ���ֶ�
	     */
		int m_colorField;
		/**
	     * ���ߵ���ɫ
	     */
		Long m_downColor;
		/**
	     * ��߼��ֶ�
	     */
		int m_highField;
		/**
	     * ��߼۵���ʾ����
	     */
		String m_highFieldText;
		/**
	     * ��ͼ��ֶ�
	     */
		int m_lowField;
		/**
	     * ��ͼ۵���ʾ����
	     */
		String m_lowFieldText;
		/*
		* �м����ɫ
		*/
		Long m_midColor;
		/**
	     * ���̼��ֶ�
	     */
		int m_openField;
		/**
	     * ���̼۵���ʾ����
	     */
		String m_openFieldText;
		/**
	     * �Ƿ���ʾ�����Сֵ
	     */
		bool m_showMaxMin;
		/*
		* ��ʽ
		*/
		CandleStyle m_style;
		/**
	     * ��ʽ�ֶ�
	     */
		int m_styleField;
		/**
	     * �����Сֵ��ǩ����ɫ
	     */
		Long m_tagColor;
		/**
	     * ������ɫ
	     */
		Long m_upColor;
	public:
		/*
		* ���캯��
		*/
		CandleShape();
		/**
	     *  ��ȡ��ɫ���ֶ�
	     */
		int getCloseField();
		/**
	     *  ������ɫ���ֶ�
	     */
		void setCloseField(int value);
		/**
	     * ��ȡ���̼۵���ʾ����
	     */
		String getCloseFieldText();
		/**
	     * �������̼۵���ʾ����
	     */
		void setCloseFieldText(const String& value);
		/**
	     *  ��ȡ��ɫ���ֶ�
	     */
		int getColorField();
		/**
	     *  ������ɫ���ֶ�
	     */
		void setColorField(int value);
		/**
	     * ��ȡ���ߵ���ɫ
	     */
		Long getDownColor();
		/**
	     * �������ߵ���ɫ
	     */
		void setDownColor(Long value);
		/**
	     * ��ȡ��߼��ֶ�
	     */
		int getHighField();
		/**
	     * ������߼��ֶ�
	     */
		void setHighField(int value);
		/**
	     * ��ȡ��߼۵���ʾ����
	     */
		String getHighFieldText();
		/**
	     * ������߼۵���ʾ����
	     */
		void setHighFieldText(const String& value);
		/**
	     * ��ȡ��ͼ��ֶ�
	     */
		int getLowField();
		/**
	     * ������ͼ��ֶ�
	     */
		void setLowField(int value);
		/**
	     * ��ȡ��ͼ۵���ʾ����
	     */
		String getLowFieldText();
		/**
	     * ������ͼ۵���ʾ����
	     */
		void setLowFieldText(const String& value);
		/*
		* ��ȡ�м����ɫ
		*/
		Long getMidColor();
		/*
		* �����м����ɫ
		*/
		void setMidColor(Long value);
		/**
	     * ��ȡ���̼��ֶ�
	     */
		int getOpenField();
		/**
	     * ���ÿ��̼��ֶ�
	     */
		void setOpenField(int value);
		/**
	     * ��ȡ���̼۵���ʾ����
	     */
		String getOpenFieldText();
		/**
	     * ���ÿ��̼۵���ʾ����
	     */
		void setOpenFieldText(const String& value);
		/**
	     * ��ȡ�Ƿ���ʾ�����Сֵ
	     */
		bool getShowMaxMin();
		/**
	     * �����Ƿ���ʾ�����Сֵ
	     */
		void setShowMaxMin(bool value);
		/**
	     * ��ȡ����������
	     */
		CandleStyle getStyle();
		/**
	     * ��������������
	     */
		void setStyle(CandleStyle value);
		/**
	     * ��ȡ��ʽ�ֶ�
	     */
		int getStyleField();
		/**
	     * ������ʽ�ֶ�
	     */
		void setStyleField(int value);
		/**
	     * ��ȡ�����Сֵ��ǩ����ɫ
	     */
		Long getTagColor();
		/**
	     * ���������Сֵ��ǩ����ɫ
	     */
		void setTagColor(Long value);
		/**
	     * ��ȡ������ɫ
	     */
		Long getUpColor();
		/**
	     * ����������ɫ
	     */
		void setUpColor(Long value);
	public:
	    /**
	     * ��ȡ�����ֶ�
	     */
		virtual int getBaseField();
	    /**
         * ���ֶ����ƻ�ȡ�ֶα���
         * @param fieldName  �ֶ�����
         * @returns �ֶα���
        */
		virtual String getFieldText(int fieldName);
		/**
	     * ��ȡ�����ֶ�
	     */
		virtual int* getFields(int *length);
	    /**
         * ��������ֵ
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
        *��ȡѡ�е����ɫ
        * @returns ��ɫ
        */
		virtual Long getSelectedColor();
	    /**
         * ��ȡ����ֵ
         * @param name  ��������
         * @param value ����ֵ
        */
		virtual void setAttribute(const String& name, const String& value);
	};

	/*
	* ��״ͼ
	*/
	class __BASESHAPE_H__ BarShape : public BaseShape{
	public:
	    /**
	     * ��ɫ���ֶ�
	     */
		int m_colorField;
		/**
	     * ���ߵ���ɫ
	     */
		Long m_downColor;
		/**
	     * �ֶ�����
	     */
		int m_fieldName;
		/**
	     * �ֶ�����2
	     */
		int m_fieldName2;
		/**
	     * ��ʾ�ı�������
	     */
		String m_fieldText;
		/**
	     * ��ʾ�ı�������2
	     */
		String m_fieldText2;
		/**
	     * �ߵĿ��
	     */
		float m_lineWidth;
		/**
	     * ������ʽ
	     */
		BarStyle m_style;
		/**
	     * ��ʽ�ֶ�
	     */
		int m_styleField;
		/**
	     * ���ߵ���ɫ
	     */
		Long m_upColor;
	public:
		/*
		* ���캯��
		*/
		BarShape();
		/**
	     * ��ȡ��ɫ���ֶ�
	     */
		int getColorField();
		/**
	     * ������ɫ���ֶ�
	     */
		void setColorField(int value);
		/**
	     * ��ȡ���ߵ���ɫ
	     */
		Long getDownColor();
		/**
	     * �������ߵ���ɫ
	     */
		void setDownColor(Long value);
		/**
	     * ��ȡ�ֶ�����
	     */
		int getFieldName();
		/**
	     * �����ֶ�����
	     */
		void setFieldName(int value);
		/**
	     * ��ȡ�ֶ�����2
	     */
		int getFieldName2();
		/**
	     * �����ֶ�����2
	     */
		void setFieldName2(int value);
		/**
	     *  ��ȡ��ʾ�ı�������
	     */
		String getFieldText();
		/**
	     *  ������ʾ�ı�������
	     */
		void setFieldText(const String& value);
		/**
	     * ��ȡ��ʾ�ı�������2
	     */
		String getFieldText2();
		/**
	     * ������ʾ�ı�������2
	     */
		void setFieldText2(const String& value);
		/**
	     * ��ȡ�ߵĿ��
	     */
		float getLineWidth();
		/**
	     * �����ߵĿ��
	     */
		void setLineWidth(float value);
		/**
	     * ��ȡ��������ʽ
	     */
		BarStyle getStyle();
		/**
	     * ������������ʽ
	     */
		void setStyle(BarStyle value);
		/**
	     * ��ȡ��ʽ�ֶ�
	     */
		int getStyleField();
		/**
	     * ������ʽ�ֶ�
	     */
		void setStyleField(int value);
		/**
	     * ��ȡ���ߵ���ɫ
	     */
		Long getUpColor();
		/**
	     * �������ߵ���ɫ
	     */
		void setUpColor(Long value);
	public:
	    /**
	     * ��ȡ�����ֶ�
	     */
		virtual int getBaseField();
	    /**
		 * ���ֶ����ƻ�ȡ�ֶα���
		 * @param fieldName  �ֶ�����
		 * @returns �ֶα���
        */
		virtual String getFieldText(int fieldName);
		/**
	     * ��ȡ�����ֶ�
	     */
		virtual int* getFields(int *length);
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
        *��ȡѡ�е����ɫ
        * @returns ��ɫ
        */
		virtual Long getSelectedColor();
	    /**
		 * ��������ֵ
		 * @param name  ��������
		 * @param value ����ֵ
        */
		virtual void setAttribute(const String& name, const String& value);
	};

	/*
	* ����
	*/
	class __BASESHAPE_H__ PolylineShape : public BaseShape{
	public:
	    /**
	     * �ߵ���ɫ
	     */
		Long m_color;
		/**
	     * ��ɫ���ֶ�
	     */
		int m_colorField;
		/**
	     * �ֶ�����
	     */
		int m_fieldName;
		/**
	     * ��ʾ�ı�������
	     */
		String m_fieldText;
		/**
	     * ���ɫ
	     */
		Long m_fillColor;
		/**
	     * ��ʽ
	     */
		PolylineStyle m_style;
		/**
	     * �ߵĿ��
	     */
		float m_width;
	public:
		/*
		* ���캯��
		*/
		PolylineShape();
		/**
	     * ��ȡ�ߵ���ɫ
	     */
		Long getColor();
		/**
	     * �����ߵ���ɫ
	     */
		void setColor(Long color);
		/**
	     * ��ȡ��ɫ���ֶ�
	     */
		int getColorField();
		/**
	     * ������ɫ���ֶ�
	     */
		void setColorField(int colorField);
		/**
	     * ��ȡ�ֶ�����
	     */
		int getFieldName();
		/**
	     * �����ֶ�����
		 * @param fieldName �ֶ�����
	     */
		void setFieldName(int fieldName);
		/**
	     * ��ȡ��ʾ�ı�������
	     */
		String getFieldText();
		/**
	     * ������ʾ�ı�������
		 * @param fieldText ��������
	     */
		void setFieldText(const String& fieldText);
		/**
	     * ��ȡ���ɫ
	     */
		Long getFillColor();
		/**
	     * �������ɫ
	     */
		void setFillColor(Long fillColor);
		/**
	     * ��ȡ��ʽ
	     */
		PolylineStyle getStyle();
		/**
	     * ������ʽ
	     */
		void setStyle(PolylineStyle style);
		/**
	     * ��ȡ�ߵĿ��
	     */
		float getWidth();
		/**
	     * �����ߵĿ��
	     */
		void setWidth(float width);
	public:
	    /**
	     * ��ȡ�����ֶ�
	     */
		virtual int getBaseField();
		/**
	     * ���ֶ����ƻ�ȡ�ֶα���
	     */
		virtual String getFieldText(int fieldName);
		/**
	     * ��ȡ�����ֶ�
	     */
		virtual int* getFields(int *length);
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
	     * ��ȡѡ�е����ɫ
	     */
		virtual Long getSelectedColor();
		/**
	     * ��������
	     */
		virtual void setAttribute(const String& name, const String& value);
	};

	/*
	* ����
	*/
	class __BASESHAPE_H__ TextShape:public BaseShape{
	public:
	    /**
	     * ��ɫ�ֶ�
	     */
		int m_colorField;
		/**
	     * �ֶ�
	     */
		int m_fieldName;
		/**
	     * ����
	     */
		FCFont *m_font;
		/**
	     * ��ʽ�ֶ�
	     */
		int m_styleField;
		/**
	     * ���Ƶ�����
	     */
		String m_text;
		/**
	     * ���Ƶ�����
	     */
		Long m_textColor;
	public:
		/*
		* ���캯��
		*/
		TextShape();
		/**
	     * ��������
	     */
		virtual ~TextShape();
		/**
	     * ��ȡ��ɫ�ֶ�
	     */
		int getColorField();
		/**
	     * ������ɫ�ֶ�
	     */
		void setColorField(int colorField);
		/**
	     * ��ȡ�ֶ�
	     */
		int getFieldName();
		/**
	     * �����ֶ�
	     */
		void setFieldName(int fieldName);
		/**
	     * ��ȡ����
	     */
		FCFont* getFont();
		/**
	     * ��������
	     */
		void setFont(FCFont *font);
		/**
	     * ��ȡ��ʽ�ֶ�
	     */
		int getStyleField();
		/**
	     * ������ʽ�ֶ�
	     */
		void setStyleField(int styleField);
		/**
	     * ��ȡ���Ƶ�����
	     */
		String getText();
		/**
	     * ���û��Ƶ�����
	     */
		void setText(const String& text);
		/**
	     * ��ȡǰ��ɫ
	     */
		Long getTextColor();
		/**
	     * ����ǰ��ɫ
	     */
		void setTextColor(Long textColor);
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