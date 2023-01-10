/*
 * FaceCatͼ��ͨѶ���(�ǿ�Դ)
 * ����Ȩ���:2015SR229355+2020SR0266727
 * �Ϻ����è��Ϣ�������޹�˾
 */

#ifdef __FCLINE2D_H__
#else                                                                            
#define __FCLINE2D_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "..\\core\\FCTran.h"

namespace FaceCat{
	/**
     * ����ͼ
     */
	class __FCLINE2D_H__ FCLine2D : public FCView{
	public:
		/*
		* �Ƿ�ر�
		*/
		bool m_close;
		/**
	     * �ߵĿ��
	     */
		float m_lineWidth;
		/**
	     * ��ȡ�����õ�
	     */
		String m_points;
	public:
		/*
		* ���캯��
		*/
		FCLine2D();
		/*
		* ��������
		*/
		virtual ~FCLine2D();
		/*
		* ��ȡ�Ƿ�ر�
		*/
        virtual bool isClose();
		/*
		* �����Ƿ�ر�
		*/
        virtual void setClose(bool value);
		/*
		* ��ȡ�ߵĿ��
		*/
        virtual float getLineWidth();
        /*
		* �����ߵĿ��
		*/
        virtual void setLineWidth(float value);
		/*
		* ��ȡ��
		*/
        virtual String getPoints();
		/*
		* ���õ�
		*/
        virtual void setPoints(String value);
	public:
	    /**
	     * ��ȡ��ͼ����
	     */
		virtual String getViewType();
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
         * �ػ汳������
         * @param paint    ��ͼ����
         * @param clipRect �ü�����
         */
		virtual void onPaint(FCPaint *paint, const FCRect& clipRect);
	    /**
         * �ػ���߷���
         * @param paint    ��ͼ����
         * @param clipRect �ü�����
         */
		virtual void onPaintBorder(FCPaint *paint, const FCRect& clipRect);
	    /**
         * ��������
         * @param name    ��������
         * @param value   ����ֵ
        */
		virtual void setAttribute(const String& name, const String& value);
	};
}
