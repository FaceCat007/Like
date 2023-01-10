/*
 * FaceCatͼ��ͨѶ���(�ǿ�Դ)
 * ����Ȩ���:2015SR229355+2020SR0266727
 * �Ϻ����è��Ϣ�������޹�˾
 */

#ifdef __CROSSLINE_H__
#else                                                                            
#define __CROSSLINE_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "Enums.h"
#include "ChartDiv.h"

namespace FaceCat{
	class ChartDiv;
	/**
     * ʮ����
     */
	class __CROSSLINE_H__ CrossLine : public FCAttribute{
	public:
	    /**
	     * �Ƿ������û���ͼ
	     */
		bool m_allowUserPaint;
		/**
	     * �Ƿ�����˫������
	     */
		bool m_allowDoubleClick;
		/**
	     * ���������ỹ������
	     */
		AttachVScale m_attachVScale;
		/**
	     * ʮ���ߵ���ɫ
	     */
		Long m_lineColor;
	public:
		/*
		* ���캯��
		*/
		CrossLine();
		/*
		* ��������
		*/
		virtual ~CrossLine();
		/**
	     * ��ȡ�Ƿ�����˫������
	     */
		virtual bool allowDoubleClick();
		/**
	     * �����Ƿ�����˫������
	     */
		virtual void setAllowDoubleClick(bool value);
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
		/**
	     * ��ȡʮ���ߵ���ɫ
	     */
		virtual Long getLineColor();
		/**
	     * ����ʮ���ߵ���ɫ
	     */
		virtual void setLineColor(Long value);
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