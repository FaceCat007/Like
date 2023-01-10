/*
 * FaceCatͼ��ͨѶ���(�ǿ�Դ)
 * ����Ȩ���:2015SR229355+2020SR0266727
 * �Ϻ����è��Ϣ�������޹�˾
 */

#ifdef __SCALEGRID_H__
#else                                                                            
#define __SCALEGRID_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "ChartDiv.h"

namespace FaceCat{
	class ChartDiv;

    /**
     * ������
     */
	class __SCALEGRID_H__ ScaleGrid : public FCAttribute{
	public:
	    /**
	     * �Ƿ������û���ͼ
	     */
		bool m_allowUserPaint;
		/**
	     * ����
	     */
		int m_distance;
		/**
	     * �����ߵ���ɫ
	     */
		Long m_gridColor;
		/**
	     * ��ȡ�����ú��������ߵ���ʽ
	     */
		int m_lineStyle;
		/**
	     * �Ƿ�ɼ�
	     */
		bool m_visible;
	public:
		/*
		* ���캯��
		*/
		ScaleGrid();
		/*
		* ��������
		*/
		virtual ~ScaleGrid();
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
		virtual int getDistance();
		/**
	     * ���þ���
	     */
		virtual void setDistance(int value);
		/**
	     * ��ȡ�����ߵ���ɫ
	     */
		virtual Long getGridColor();
		/**
	     * ���������ߵ���ɫ
	     */
		virtual void setGridColor(Long value);
		/**
	     * ��ȡ���������ߵ���ʽ
	     */
		virtual int getLineStyle();
		/**
	     * ���ú��������ߵ���ʽ
	     */
		virtual void setLineStyle(int value);
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