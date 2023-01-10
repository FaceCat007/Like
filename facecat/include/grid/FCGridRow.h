/*
 * FaceCatͼ��ͨѶ���(�ǿ�Դ)
 * ����Ȩ���:2015SR229355+2020SR0266727
 * �Ϻ����è��Ϣ�������޹�˾
 */

#ifdef __FCGRIDROW_H__
#else                                                                            
#define __FCGRIDROW_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "..\\core\\FCAttribute.h"
#include "FCGridCell.h"
#include "FCGrid.h"
#include "FCGridColumn.h"

namespace FaceCat{
	class FCGridCell;
	class FCGrid;
	class FCGridColumn;

	/*
	* ����е�����
	*/
	class __FCGRIDROW_H__ FCGridRowStyle{
	public:
	    /**
		 * ����е���ʽ
		 */
		Long m_backColor;
		/**
		 * ����
		 */
		FCFont *m_font;
		/**
		 * ������ͣ�еı���ɫ
		 */
		Long m_hoveredBackColor;
		/**
		 * ������ͣ�е�ǰ��ɫ
		 */
		Long m_hoveredTextColor;
		/**
		 * ѡ���еı���ɫ
		 */
		Long m_selectedBackColor;
		/**
		 * ѡ���е�ǰ��ɫ
		 */
		Long m_selectedTextColor;
		/**
		 * ǰ��ɫ
		 */
		Long m_textColor;
	public:
		/*
		* ���캯��
		*/
		FCGridRowStyle();
		/*
		* ��������
		*/
		virtual ~FCGridRowStyle();
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
		/**
		 * ��ȡ������ͣ�еı���ɫ
		 */
		virtual Long getHoveredBackColor();
		/**
		 * ���ô�����ͣ�еı���ɫ
		 */
		virtual void setHoveredBackColor(Long value);
		/**
		 * ��ȡ������ͣ�е�ǰ��ɫ
		 */
		virtual Long getHoveredTextColor();
		/**
		 * ���ô�����ͣ�е�ǰ��ɫ
		 */
		virtual void setHoveredTextColor(Long value);
		/**
		 * ��ȡѡ���еı���ɫ
		 */
		virtual Long getSelectedBackColor();
		/**
		 * ����ѡ���еı���ɫ
		 */
		virtual void setSelectedBackColor(Long value);
		/**
		 * ��ȡѡ���е�ǰ��ɫ
		 */
		virtual Long getSelectedTextColor();
		/**
		 * ����ѡ���е�ǰ��ɫ
		 */
		virtual void setSelectedTextColor(Long value);
	public:
		/*
		* ��������
		*/
		void copy(FCGridRowStyle *style);
	};

	/*
	* �����
	*/
	class __FCGRIDROW_H__ FCGridRow : public FCAttribute{
	public:
	    /**
		 * �Ƿ�����༭
		 */
		bool m_allowEdit;
		/**
		 * ��ʾ����
		 */
		FCRect m_bounds;
		/**
		 * �༭��ť
		 */
		FCView *m_editButton;
		/**
		 * ���ڱ��
		 */
		FCGrid *m_grid;
		int m_height;
		/**
		 * �����������
		 */
		int m_horizontalOffset;
		/**
		 * ����
		 */
		int m_index;
		/**
		 * TAGֵ
		 */
		Object m_tag;
		/**
		 * �Ƿ�ɼ�
		 */
		bool m_visible;
		/**
		 * �ɼ�����
		 */
		int m_visibleIndex;
	public:
		/*
		* ��Ԫ��
		*/
		ArrayList<FCGridCell*> m_cells;
		/*
		* �༭״̬
		*/
		int m_editState;
		/*
		* ���캯��
		*/
		FCGridRow();
		/*
		* ��������
		*/
		virtual ~FCGridRow();
		/**
		 * ��ȡ�Ƿ�����༭
		 */
		virtual bool allowEdit();
		/**
		 * �����Ƿ�����༭
		 */
		virtual void setAllowEdit(bool value);
		/**
		 * ��ȡ��ʾ����
		 */
		virtual FCRect getBounds();
		/**
		 * ������ʾ����
		 */
		virtual void setBounds(FCRect value);
		/**
		 * ��ȡ�༭��ť
		 */
		virtual FCView* getEditButton();
		/**
		 * ���ñ༭��ť
		 */
		virtual void setEditButton(FCView *value);
		/**
		 * ��ȡ���ڱ��
		 */
		virtual FCGrid* getGrid();
		/**
		 * �������ڱ��
		 */
		virtual void setGrid(FCGrid *value);
		/**
		 * ��ȡ�и�
		 */
		virtual int getHeight();
		/**
		 * �����и�
		 */
		virtual void setHeight(int value);
		/**
		 * ��ȡ�����������
		 */
		virtual int getHorizontalOffset();
		/**
		 * ���ú����������
		 */
		virtual void setHorizontalOffset(int value);
		/**
		 * ��ȡ����
		 */
		virtual int getIndex();
		/**
		 * ��������
		 */
		virtual void setIndex(int value);
		/**
		 * ��ȡTAGֵ
		 */
		virtual Object getTag();
		/**
		 * ����TAGֵ
		 */
		virtual void setTag(Object value);
		/**
		 * ��ȡ�Ƿ�ɼ�
		 */
		virtual bool isVisible();
		/**
		 * �����Ƿ�ɼ�
		 */
		virtual void setVisible(bool value);
		/**
		 * ��ȡ�ɼ�����
		 */
		virtual int getVisibleIndex();
		/**
		 * ���ÿɼ�����
		 */
		virtual void setVisibleIndex(int value);
	public:
	    /**
		 * ��ӵ�Ԫ��
		 */
		void addCell(FCGridColumn *column, FCGridCell *cell);
		/**
		 * ��ӵ�Ԫ��
		 */
		void addCell(int columnIndex, FCGridCell *cell);
		/**
		 * ��ӵ�Ԫ��
		 */
		void addCell(const String& columnName, FCGridCell *cell);
		/**
		 * �����Ԫ��
		 */
		void clearCells();
		/**
		 * ��ȡ���е�Ԫ��
		 */
		ArrayList<FCGridCell*> getCells();
		/**
		 * �����е����ƻ�ȡ��Ԫ��
		 */
		FCGridCell* getCell(FCGridColumn *column);
		/**
		 * �����е�������ȡ��Ԫ��
		 */
		FCGridCell* getCell(int columnIndex);
		/**
		 * �����е����ƻ�ȡ��Ԫ��
		 */
		FCGridCell* getCell(const String& columnName);
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
		 * ����з���
		 */
		virtual void onAdd();
		/**
		 * �ػ淽��
		 */
		virtual void onPaint(FCPaint *paint, const FCRect& clipRect, bool isAlternate);
		/**
		 * �ػ���߷���
		 */
		virtual void onPaintBorder(FCPaint *paint, const FCRect& clipRect, bool isAlternate);
		/**
		 * �Ƴ��з���
		 */
		virtual void onRemove();
		/*
		* ��������
		*/
		virtual void onScaling(double scaleFactorX, double scaleFactorY);
		/**
		 * �Ƴ���Ԫ��
		 */
		void removeCell(FCGridColumn *column);
		/**
		 * �Ƴ���Ԫ��
		 */
		void removeCell(int columnIndex);
		/**
		 * �Ƴ���Ԫ��
		 */
		void removeCell(const String& columnName);
		/**
		* ��������
		* @param  name  ��������
		* @param  value  ����ֵ
		*/
		virtual void setAttribute(const String& name, const String& value);
	};
}
