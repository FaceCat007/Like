/*
 * FaceCatͼ��ͨѶ���(�ǿ�Դ)
 * ����Ȩ���:2015SR229355+2020SR0266727
 * �Ϻ����è��Ϣ�������޹�˾
 */

#ifdef __FCGRIDCOLUMN_H__
#else                                                                            
#define __FCGRIDCOLUMN_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "FCGridEnums.h"
#include "FCGrid.h"
#include "..\\btn\\FCButton.h"

namespace FaceCat{
	class FCGrid;

	/*
	* �����
	*/
	class __FCGRIDCOLUMN_H__ FCGridColumn : public FCButton{
	public:
		/**
		 * �Ƿ�����϶���
		 */
		bool m_allowDragRow;
	    /**
		 * �Ƿ��������
		 */
		bool m_allowSort;
		/**
		 * �Ƿ���Ե�����С
		 */
		bool m_allowResize;
		/**
		 * ���ݵĺ���������ʽ
		 */
		FCHorizontalAlign m_cellAlign;
		/**
		 * �е�����
		 */
		String m_columnType;
		/**
		 * �Ƿ񶳽�
		 */
		bool m_frozen;
		/**
		 * ���
		 */
		FCGrid *m_grid;
		/**
		 * ͷ���ľ���
		 */
		FCRect m_headerRect;
		/**
		 * ����
		 */
		int m_index;
		/**
		 * ����״̬
		 */
		FCGridColumnSortMode m_sortMode;
	public:
	    /**
		 * ��ʼ���
		 */
		int m_beginWidth;
		/**
		 * ��������ʱ������
		 */
        FCPoint m_touchDownPoint;
        /**
		 * ������С״̬
		 */
		int m_resizeState;
	public:
		/*
		* ���캯��
		*/
		FCGridColumn();
		/*
		* ���캯��
		*/
		FCGridColumn(const String& text);
		/*
		* ��������
		*/
		virtual ~FCGridColumn();
		/*
		* ��ȡ�Ƿ�����϶���
		*/
		virtual bool allowDragRow();
		/*
		* �����Ƿ�����϶���
		*/ 
		virtual void setAllowDragRow(bool value);
		/**
		 * ��ȡ�Ƿ���Ե�����С
		 */
		virtual bool allowResize();
		/**
		 * �������Ƿ���Ե�����С
		 */
		virtual void setAllowResize(bool value);
		/**
		 * ��ȡ�Ƿ��������
		 */
		virtual bool allowSort();
		/**
		 * �����Ƿ��������
		 */
		virtual void setAllowSort(bool value);
		/**
		 * ��ȡ���ݵĺ���������ʽ
		 */
		virtual FCHorizontalAlign getCellAlign();
		/**
		 * �������ݵĺ���������ʽ
		 */
		virtual void setCellAlign(FCHorizontalAlign value);
		/**
		 * ��ȡ�е�����
		 */
		virtual String getColumnType();
		/**
		 * �����е�����
		 */
		virtual void setColumnType(String value);
		/**
		 * ��ȡ�Ƿ񶳽�
		 */
		virtual bool isFrozen();
		/**
		 * �����Ƿ񶳽�
		 */
		virtual void setFrozen(bool value);
		/**
		 * ��ȡ���
		 */
		virtual FCGrid* getGrid();
		/**
		 * ���ñ��
		 */
		virtual void setGrid(FCGrid *value);
		/**
		 * ��ȡͷ���ľ���
		 */
		virtual FCRect getHeaderRect();
		/**
		 * ����ͷ���ľ���
		 */
		virtual void setHeaderRect(FCRect value);
		/**
		 * ��ȡ����
		 */
		virtual int getIndex();
		/**
		 * ��������
		 */
		virtual void setIndex(int value);
		/**
		 * ��ȡ����״̬��0:������ 1:���� 2:����
		 */
		virtual FCGridColumnSortMode getSortMode();
		/**
		 * ��������״̬��0:������ 1:���� 2:����
		 */
		virtual void setSortMode(FCGridColumnSortMode value);
	public:
	    /**
		 * ��ȡ��ͼ����
		 */
		virtual String getViewType();
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
		 * �������
		 */
		virtual void onClick(FCTouchInfo touchInfo);
		/**
		 * �϶���ʼ����
		 */
		virtual bool onDragBegin();
		/**
		 * �϶��з���
		 */
		virtual void onDragging();
		/**
		 * �������·���
		 */
		virtual void onTouchDown(FCTouchInfo touchInfo);
		/**
		 * �����ƶ�����
		 */
		virtual void onTouchMove(FCTouchInfo touchInfo);
		/**
		 * ����̧�𷽷�
		 */
		virtual void onTouchUp(FCTouchInfo touchInfo);
		/**
		 * �ػ�ǰ������
		 */
		virtual void onPaintForeground(FCPaint *paint, const FCRect& clipRect);
		/**
		* ��������
		* @param  name  ��������
		* @param  value  ����ֵ
		*/
		virtual void setAttribute(const String& name, const String& value);
	};
}