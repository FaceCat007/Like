/*
 * FaceCatͼ��ͨѶ���(�ǿ�Դ)
 * ����Ȩ���:2015SR229355+2020SR0266727
 * �Ϻ����è��Ϣ�������޹�˾
 */

#ifdef __FCTABLELAYOUTDIV_H__
#else                                                                            
#define __FCTABLELAYOUTDIV_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "FCDiv.h"

namespace FaceCat{
    /**
	 * ������С������
	 */
	enum __FCTABLELAYOUTDIV_H__ FCSizeType{
	    /**
		 * ���Դ�С
		 */
		FCSizeType_AbsoluteSize,
		/**
		 * �Զ����
		 */
		FCSizeType_AutoFill,
		/**
		 * �ٷֱȴ�С
		 */
		FCSizeType_PercentSize
	};

	/*
	* �е���ʽ
	*/
	class __FCTABLELAYOUTDIV_H__ FCColumnStyle : public FCAttribute{
	public:
	    /**
		 * ������С������
		 */
		FCSizeType m_sizeType;
		/**
		 * ���
		 */
		float m_width;
	public:
		/*
		* ���캯��
		*/
		FCColumnStyle();
		/*
		* ���캯��
		*/
		FCColumnStyle(FCSizeType sizeType, float width);
		/*
		* ��������
		*/
		virtual ~FCColumnStyle();
		/**
		 * ��ȡ������С������
		 */
		virtual FCSizeType getSizeType();
		/**
		 * ���õ�����С������
		 */
		virtual void setSizeTypeA(FCSizeType value);
		/**
		 * ��ȡ���
		 */
		virtual float getWidth();
		/**
		 * ���ÿ��
		 */
		virtual void setWidth(float value);
	public:
		/**
		* ��ȡ����ֵ
		* @param  name   ��������
		* @param  value   ��������ֵ
		* @param  type   ������������
		*/
		virtual void getAttribute(const String& name, String *value, String *type);
		/**
		 * ��ȡ���������б�
		 */
		virtual ArrayList<String> getAttributeNames();
		/**
		* ��������ֵ
		* @param  name   ��������
		* @param  value   ����ֵ
		*/
		virtual void setAttribute(const String& name, const String& value);
	};

	/*
	* �е���ʽ
	*/
	class __FCTABLELAYOUTDIV_H__ FCRowStyle : public FCAttribute{
	public:
	    /**
		 * ���
		 */
		float m_height;
		/**
		 * ������С������
		 */
		FCSizeType m_sizeType;
	public:
		/*
		* ���캯��
		*/
		FCRowStyle();
		/*
		* ���캯��
		*/
		FCRowStyle(FCSizeType sizeType, float height);
		/*
		* ��������
		*/
		virtual ~FCRowStyle();
		/**
		 * ��ȡ���
		 */
		virtual float getHeight();
		/**
		 * ���ÿ��
		 */
		virtual void setHeight(float value);
		/**
		 * ��ȡ������С������
		 */
		virtual FCSizeType getSizeType();
		/**
		 * ���õ�����С������
		 */
		virtual void setSizeTypeA(FCSizeType value);
	public:
		/**
		* ��ȡ����ֵ
		* @param  name   ��������
		* @param  value   ��������ֵ
		* @param  type   ������������
		*/
		virtual void getAttribute(const String& name, String *value, String *type);
		/**
		 * ��ȡ���������б�
		 */
		virtual ArrayList<String> getAttributeNames();
		/**
		* ��������ֵ
		* @param  name   ��������
		* @param  value   ����ֵ
		*/
		virtual void setAttribute(const String& name, const String& value);
	};

	/*
	* ����
	*/
	class __FCTABLELAYOUTDIV_H__ FCTableLayoutDiv : public FCDiv{
	public:
	    /**
		 * �еļ���
		 */
		ArrayList<Integer> m_columns;
		/**
		 * �е�����
		 */
		int m_columnsCount;
		/**
		 * �еļ���
		 */
		ArrayList<Integer> m_rows;
		/**
		 * �е�����
		 */
		int m_rowsCount;
		/**
		 * �����ͼ
		 */
		ArrayList<FCView*> m_tableViews;
	public:
	    /**
		 * �е���ʽ
		 */
		ArrayList<FCColumnStyle> m_columnStyles;
		/**
		 * �е���ʽ
		 */
		ArrayList<FCRowStyle> m_rowStyles;
		/*
		* ���캯��
		*/
		FCTableLayoutDiv();
		/*
		* ��������
		*/
		virtual ~FCTableLayoutDiv();
		/**
		 * ��ȡ�е�����
		 */
		virtual int getColumnsCount();
		/**
		 * �����е�����
		 */
		virtual void setColumnsCount(int value);
		/**
		 * ��ȡ�е�����
		 */
		virtual int getRowsCount();
		/**
		 * �����е�����
		 */
		virtual void setRowsCount(int value);
	public:
		/**
		* �����ͼ
		* @param  view   ��ͼ
		*/
		virtual void addView(FCView *view);
		/**
		* �����ͼ
		* @param  view   ��ͼ
		* @param  column   ��
		* @param  row   ��
		*/
		virtual void addView(FCView *view, int column, int row);
		/**
		 * ��ȡ��ͼ����
		 */
		virtual String getViewType();
		/**
		* ��ȡ����ֵ
		* @param  name   ��������
		* @param  value   ��������ֵ
		* @param  type   ������������
		*/
		virtual void getAttribute(const String& name, String *value, String *type);
		/**
		 * ��ȡ���������б�
		 */
		virtual ArrayList<String> getAttributeNames();
		/**
		 * ���ò���
		 */
		virtual bool onResetLayout();
		/**
		* �Ƴ���ͼ
		* @param  view   ��ͼ
		*/
		virtual void removeView(FCView *view);
		/**
		* ��������ֵ
		* @param  name   ��������
		* @param  value   ����ֵ
		*/
		virtual void setAttribute(const String& name, const String& value);
		/**
		 * ���ָ��·���
		 */
		virtual void update();
	};
}
