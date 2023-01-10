/*
 * FaceCatͼ��ͨѶ���(�ǿ�Դ)
 * ����Ȩ���:2015SR229355+2020SR0266727
 * �Ϻ����è��Ϣ�������޹�˾
 */

#ifdef __FCGRIDCELL_H__
#else                                                                            
#define __FCGRIDCELL_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "..\\core\\FCAttribute.h"
#include "FCGridColumn.h"
#include "FCGridRow.h"
#include "FCGrid.h"

namespace FaceCat{
	class FCGridColumn;
	class FCGridRow;
	class FCGrid;

	/*
	* ��Ԫ����ʽ
	*/
	class __FCGRIDCELL_H__ FCGridCellStyle{
	public:
		FCHorizontalAlign m_align;
		/**
		 * �Ƿ������ֳ�����Χʱ�ڽ�β��ʾʡ�Ժ�
		 */
		bool m_autoEllipsis;
		/**
		 * ��ȡ
		 */
		Long m_backColor;
		/**
		 * ����
		 */
		FCFont *m_font;
		/**
		 * ǰ��ɫ
		 */
		Long m_textColor;
	public:
		/*
		* ���캯��
		*/
		FCGridCellStyle();
		/*
		* ��������
		*/
		virtual ~FCGridCellStyle();
		/**
		 * ��ȡ���ݵĺ���������ʽ
		 */
		virtual FCHorizontalAlign getAlign();
		/**
		 * �������ݵĺ���������ʽ
		 */
		virtual void setAlign(FCHorizontalAlign value);
		/**
		 * ��ȡ�Ƿ������ֳ�����Χʱ�ڽ�β��ʾʡ�Ժ�
		 */
		virtual bool autoEllipsis();
		/**
		 * �����Ƿ������ֳ�����Χʱ�ڽ�β��ʾʡ�Ժ�
		 */
		virtual void setAutoEllipsis(bool value);
		/*
		* ��ȡ����ɫ
		*/
		virtual Long getBackColor();
		/*
		* ���ñ���ɫ
		*/
		virtual void setBackColor(Long value);
		/**
		 * ��ȡ����
		 */
		virtual FCFont* getFont();
		/**
		 * ��������
		 */
		virtual void setFont(FCFont *value);
		/**
		 * ��ȡǰ��ɫ
		 */
		virtual Long getTextColor();
		/**
		 * ����ǰ��ɫ
		 */
		virtual void setTextColor(Long value);
	public:
		/*
		* ����
		*/
		void copy(FCGridCellStyle *style);
	};

	/*
	* ��Ԫ��
	*/
	class __FCGRIDCELL_H__ FCGridCell : public FCAttribute{
	public:
	    /**
		 * �Ƿ�ɱ༭
		 */
		bool m_allowEdit;
		/*
		* �еĿ��
		*/
		int m_colSpan;
		/**
		 * ������
		 */
		FCGridColumn *m_column;
		/**
		 * ���
		 */
		FCGrid *m_grid;
		/**
		 * ����
		 */
		String m_name;
		/**
		 * ������
		 */
		FCGridRow *m_row;
		/*
		* �еĿ��
		*/
		int m_rowSpan;
		/**
		 * ��ʽ
		 */
		FCGridCellStyle *m_style;
		/**
		 * TAGֵ
		 */
		Object m_tag;
	public:
		/*
		* ���캯��
		*/
		FCGridCell();
		/*
		* ��������
		*/
		virtual ~FCGridCell();
		/**
		 * ��ȡ�Ƿ�ɱ༭
		 */
		virtual bool allowEdit();
		/**
		 * �����Ƿ�ɱ༭
		 */
		virtual void setAllowEdit(bool value);
		/**
		 * ��ȡ��Խ������
		 */
		virtual int getColSpan();
		/**
		 *���ÿ�Խ������
		 */
		virtual void setColSpan(int value);
		/**
		 * ��ȡ������
		 */
		virtual FCGridColumn* getColumn();
		/**
		 * ����������
		 */
		virtual void setColumn(FCGridColumn *value);
		/**
		 * ��ȡ���
		 */
		virtual FCGrid* getGrid();
		/**
		 * ���ñ��
		 */
		virtual void setGrid(FCGrid *value);
		/**
		 * ��ȡ����
		 */
		virtual String getName();
		/**
		 * ��������
		 */
		virtual void setName(const String& value);
		/**
		 * ��ȡ������
		 */
		virtual FCGridRow* getRow();
		/**
		 * ����������
		 */
		virtual void setRow(FCGridRow *value);
		/**
		 * ��ȡ��Խ������
		 */
		virtual int getRowSpan();
		/**
		 * ���ÿ�Խ������
		 */
		virtual void setRowSpan(int value);
		/**
		 * ��ȡ��ʽ
		 */
		virtual FCGridCellStyle* getStyle();
		/**
		 * ������ʽ
		 */
		virtual void setStyle(FCGridCellStyle *value);
		/**
		 * ��ȡTAGֵ
		 */
		virtual Object getTag();
		/**
		 * ����TAGֵ
		 */
		virtual void setTag(Object value);
		/**
		 * ��ȡ����
		 */
		virtual String getText();
		/**
		 * ��������
		 */
		virtual void setText(const String& value);
	public:
	    /**
		 * ��Ԫ���С�Ƚϣ���������
		 */
		virtual int compareTo(FCGridCell *cell);
		/**
		 * ��ȡ��������ֵ
		 */
		virtual bool getBool();
		/**
		 * ��ȡ˫���ȸ���ֵ
		 */
		virtual double getDouble();
		/**
		 * ��ȡ�����ȸ���ֵ
		 */
		virtual float getFloat();
		/**
		 * ��ȡ������ֵ
		 */
		virtual int getInt();
		/**
		 * ��ȡ��������ֵ
		 */
		virtual Long getLong();
		/**
		 * ��ȡҪ���Ƶ�����
		 */
		virtual String getPaintText();
		/**
		* ��ȡ����ֵ
		* @param  name  ��������
		* @param  value  ��������ֵ
		* @param  type  ������������
		*/
		virtual void getAttribute(const String& name, String *value, String *type);
		/**
		 * ��ȡ���������б�
		 */
		virtual ArrayList<String> getAttributeNames();
		/**
		 * ��ȡ�ַ�����ֵ
		 */
		virtual String getString();
		/**
		 * ��ӵ�Ԫ�񷽷�
		 */
		virtual void onAdd();
		/**
		* �ػ淽��
		* @param  paint  ��ͼ����
		* @param  rect  ����
		* @param  clipRect  �ü�����
		* @param  isAlternate  �Ƿ�����
		*/
		virtual void onPaint(FCPaint *paint, const FCRect& rect, const FCRect& clipRect, bool isAlternate);
		/**
		 * �Ƴ���Ԫ�񷽷�
		 */
		virtual void onRemove();
		/*
		* ��������
		*/
		virtual void onScaling(double scaleFactorX, double scaleFactorY);
		/**
		 * ���ò�������ֵ
		 */
        virtual void setBool(bool value);
        /**
		 * ����˫���ȸ���ֵ
		 */
        virtual void setDouble(double value);
        /**
		 * ���õ����ȸ���ֵ
		 */
        virtual void setFloat(float value);
        /**
		 * ����������ֵ
		 */
        virtual void setInt(int value);
        /**
		 * ���ó�������ֵ
		 */
        virtual void setLong(Long value);
		/**
		* ��������
		* @param  name  ��������
		* @param  value  ����ֵ
		*/
		virtual void setAttribute(const String& name, const String& value);
		/**
		 * �����ַ�����ֵ
		 */
        virtual void setString(const String& value);
	};

	/*
	* ��ͼ�͵�Ԫ��
	*/
	class __FCGRIDCELL_H__ FCGridViewCell : public FCGridCell, public FCTouchEventCallBack{
	public:
		FCView *m_view;
	public:
		/*
		* ���캯��
		*/
		FCGridViewCell();
		/*
		* ��������
		*/
		virtual ~FCGridViewCell();
		/**
		 * ��ȡ��ͼ
		 */
		FCView* getView();
		/**
		 * ������ͼ
		 */
		void setView(FCView *value);
		/**
		 * ��ȡ�ַ�����ֵ
		 */
		virtual String getString();
		/**
		 * ��ȡҪ���Ƶ�����
		 */
		virtual String getPaintText();
	public:
		/*
		* �����¼�
		*/
		virtual void callTouchEvent(String eventName, Object sender, FCTouchInfo touchInfo, Object invoke);
		/**
		 * ��ӵ�Ԫ�񷽷�
		 */
		virtual void onAdd();
		/**
		 * ��ͼ�������·���
		 */
		virtual void onViewTouchDown(FCTouchInfo touchInfo);
		/**
		 * ��ͼ�����ƶ��¼�
		 */
		virtual void onViewTouchMove(FCTouchInfo touchInfo);
		/**
		 * ��ͼ����̧���¼�
		 */
		virtual void onViewTouchUp(FCTouchInfo touchInfo);
		/**
		 * ��ͼ�������ֹ����¼�
		 */
		virtual void onViewTouchWheel(FCTouchInfo touchInfo);
		/**
		 * �ػ淽��
		 */
		virtual void onPaint(FCPaint *paint, const FCRect& rect, const FCRect& clipRect, bool isAlternate);
		/*
		* �ػ���ͼ
		*/
		virtual void onPaintView(FCPaint *paint, const FCRect& rect, const FCRect& clipRect);
		/**
		 * �Ƴ���Ԫ�񷽷�
		 */
		virtual void onRemove();
		/**
		 * �����ַ�����ֵs
		 */
		virtual void setString(const String& value);
	};
}