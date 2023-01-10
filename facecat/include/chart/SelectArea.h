/*
 * FaceCatͼ��ͨѶ���(�ǿ�Դ)
 * ����Ȩ���:2015SR229355+2020SR0266727
 * �Ϻ����è��Ϣ�������޹�˾
 */


#ifdef __SELECTAREA_H__
#else                                                                            
#define __SELECTAREA_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "ChartDiv.h"

namespace FaceCat{
	class ChartDiv;

    /**
     * ѡ������
     */
	class __SELECTAREA_H__ SelectArea : public FCAttribute{
	public:
	    /**
	     * �Ƿ������û���ͼ
	     */
		bool m_allowUserPaint;
		/**
	     * ����ɫ
	     */
		Long m_backColor;
		/**
	     * ѡ�п������
	     */
		FCRect m_bounds;
		/**
	     * �Ƿ���Ըı�ѡ�п�Ĵ�С
	     */
		bool m_canResize;
		/**
	     * �Ƿ���Գ���ѡ�п�
	     */
		bool m_enabled;
		/**
	     * ѡ�п����ɫ
	     */
		Long m_lineColor;
		/**
	     * �Ƿ���ʾѡ�п�
	     */
		bool m_visible;
	public:
		/*
		* ���캯��
		*/
		SelectArea();
		/*
		* ��������
		*/
		virtual ~SelectArea();
		/**
	     * ��ȡ�Ƿ������û���ͼ
	     */
		virtual bool allowUserPaint();
		/**
	     * �����Ƿ������û���ͼ
	     */
		virtual void setAllowUserPaint(bool value);
		/**
	     * ��ȡ����ɫ
	     */
		virtual Long getBackColor();
		/**
	     * ���ñ���ɫ
	     */
		virtual void setBackColor(Long value);
		/**
	     * ��ȡѡ�п������
	     */
		virtual FCRect getBounds();
		/**
	     * ����ѡ�п������
	     */
		virtual void setBounds(FCRect value);
		/**
	     * ��ȡ�Ƿ���Ըı�ѡ�п�Ĵ�С
	     */
		virtual bool canResize();
		/**
	     * �����Ƿ���Ըı�ѡ�п�Ĵ�С
	     */
		virtual void setCanResize(bool value);
		/**
	     * ��ȡ�Ƿ���Գ���ѡ�п�
	     */
		virtual bool isEnabled();
		/**
	     * �����Ƿ���Գ���ѡ�п�
	     */
		virtual void setEnabled(bool value);
		/**
	     * ��ȡѡ�п����ɫ
	     */
		virtual Long getLineColor();
		/**
	     * ����ѡ�п����ɫ
	     */
		virtual void setLineColor(Long value);
		/**
	     * ��ȡ�Ƿ���ʾѡ�п�
	     */
		virtual bool isVisible();
		/**
	     * �����Ƿ���ʾѡ�п�
	     */
		virtual void setVisible(bool value);
	public:
	    /**
	     * �ر�
	     */
		void close();
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
	    /**
         * ��������ֵ
         * @param name  ��������
         * @param value ����ֵ
        */
		virtual void setAttribute(const String& name, const String& value);

	};
}