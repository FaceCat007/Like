/*
 * FaceCatͼ��ͨѶ���(�ǿ�Դ)
 * ����Ȩ���:2015SR229355+2020SR0266727
 * �Ϻ����è��Ϣ�������޹�˾
 */

#ifdef __FCGRID_H__
#else                                                                            
#define __FCGRID_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "FCGridColumn.h"
#include "FCGridRow.h"
#include "FCGridCell.h"
#include "..\\scroll\\FCHScrollBar.h"
#include "..\\scroll\\FCVScrollBar.h"
#include "..\\div\\FCDiv.h"
#include "..\\input\\FCTextBox.h"

namespace FaceCat{
	class FCGridCell;
	class FCGridColumn;
	class FCGridRow;
	class FCGridRowStyle;

	/*
	* ��Ԫ���¼�
	*/
    class __FCGRID_H__ FCGridCellEventCallBack {
	public:
		FCGridCellEventCallBack(){}
		virtual ~FCGridCellEventCallBack(){}
		virtual void callGridCellEvent(String eventName, Object sender, FCGridCell *cell, Object invoke){}
    };

    /*
	* ��Ԫ�����¼�ί��
	*/
    class __FCGRID_H__ FCGridCellTouchEventCallBack {
	public:
		FCGridCellTouchEventCallBack(){}
		virtual ~FCGridCellTouchEventCallBack(){}
		virtual void callGridCellTouchEvent(String eventName, Object sender, FCGridCell *cell, FCTouchInfo touchInfo, Object invoke){}
    };

	/*
	* �жԱ�
	*/
	class __FCGRID_H__ GridRowCompare{
	public:
	    /**
		 * ������
		 */
		int m_columnIndex;
		/**
		 * ����
		 */
		int m_type;
	public:
		/*
		* ���캯��
		*/
		GridRowCompare();
		/*
		* ��������
		*/
		virtual ~GridRowCompare();
		/*
		* �Ա�
		*/
		bool operator()(FCGridRow *x, FCGridRow *y);
	};

	class FCGrid;

	/*
	* ����
	*/
	class __FCGRID_H__ FCGridSort{
	public:
		/*
		* ���캯��
		*/
		FCGridSort();
		/*
		* ��������
		*/
		virtual ~FCGridSort();
	public:
		/**
		* ����
		* @param  grid   ���
		* @param  column   ��
		* @param  sortMode  ����ʽ
		*/
		virtual void sortColumn(FCGrid *grid, FCGridColumn *column, FCGridColumnSortMode sortMode);
	};

	/*
	* ���
	*/
	class __FCGRID_H__ FCGrid:public FCDiv{
	private:
	    /**
		 * ���ID
		 */
		int m_timerID;
	public:
	    /**
		 * �Ƿ������϶���
		 */
		bool m_allowDragRow;
		/**
		 * �Ƿ�������ͣ��
		 */
		bool m_allowHoveredRow;
		/**
		 * �����е���ʽ
		 */
		FCGridRowStyle *m_alternateRowStyle;
		/**
		 * ��Ԫ��༭ģʽ
		 */
		FCGridCellEditMode m_cellEditMode;
		/**
		 * ���ڱ༭�ĵ�Ԫ��
		 */
		FCGridCell *m_editingCell;
		/**
		 * �༭�ı���ʧ�����¼�
		 */
		FCTextBox *m_editTextBox;
		/**
		 * �����ߵ���ɫ
		 */
		Long m_gridLineColor;
		/**
		 * �Ƿ�������ɼ���
		 */
		bool m_hasUnVisibleRow;
		/**
		 * ����ͷ�Ƿ�ɼ�
		 */
		bool m_headerVisible;
		/**
		 * ����ͷ�ĸ߶�
		 */
		int m_headerHeight;
		/**
		 * �����������
		 */
		int m_horizontalOffset;
		/**
		 * ������ͣ�ĵ�Ԫ��
		 */
		FCGridCell *m_hoveredCell;
		/**
		 * ��ͣ����
		 */
		FCGridRow *m_hoveredRow;
		/**
		 * ��������ʱ��λ��
		 */
		FCPoint m_touchDownPoint;
		/**
		 * �Ƿ��ѡ
		 */
		bool m_multiSelect;
		/**
		 * �е���ʽ
		 */
		FCGridRowStyle *m_rowStyle;
		/**
		 * ѡ��ģʽ
		 */
		FCGridSelectionMode m_selectionMode;
		/**
		 * ��������
		 */
		FCGridSort *m_sort;
		/**
		 * �Ƿ�ʹ�ö���
		 */
		bool m_useAnimation;
		/**
		 * �����������
		 */
		int m_verticalOffset;
		/**
		* ���õ�Ԫ���¼�
		* @param  eventName  �¼�ID
		* @param  cell   ��Ԫ��
		*/
		virtual void callCellEvents(String eventName, FCGridCell *cell);
		/**
		* ���õ�Ԫ�����¼�
		* @param  eventName  �¼�ID
		* @param  cell   ��Ԫ��
		* @param  touchInfo   ������Ϣ
		*/
		virtual void callCellTouchEvents(String eventName, FCGridCell *cell, FCTouchInfo touchInfo);
		/**
		* �����¼�
		* @param  touchInfo  ������Ϣ
		*/
		virtual void touchEvent(FCTouchInfo touchInfo, int state);
	public:
	    /**
		 * �Ƿ������������
		 */
		bool m_lockUpdate;
		/**
		 * ѡ�еĵ�Ԫ��
		 */
		ArrayList<FCGridCell*> m_selectedCells;
		/**
		 * ѡ�е���
		 */
		ArrayList<FCGridColumn*> m_selectedColumns;
		/**
		 * ѡ����
		 */
		ArrayList<FCGridRow*> m_selectedRows;
		/*
		* ��ȡ�ɼ��еĿ�� 
		*/
		int getAllVisibleColumnsWidth();
		/*
		* ��ȡ�ɼ��еĸ߶�
		*/
		int getAllVisibleRowsHeight();
	public:
	    /**
		 * ������ӵ���
		 */
		ArrayList<FCGridRow*> m_animateAddRows;
		/**
		 * �����Ƴ�����
		 */
		ArrayList<FCGridRow*> m_animateRemoveRows;
		/**
		 * �еļ���
		 */
		ArrayList<FCGridColumn*> m_columns;
		/**
		 * ���ڱ༭����
		 */
		FCGridRow *m_editingRow;
		/**
		 * �еļ���
		 */
		ArrayList<FCGridRow*> m_rows;
		/*
		* ���캯��
		*/
		FCGrid();
		/*
		* ��������
		*/
		virtual ~FCGrid();
		/**
		 * ��ȡ�Ƿ������϶���
		 */
		virtual bool allowDragRow();
		/**
		 * �����Ƿ������϶���
		 */
		virtual void setAllowDragRow(bool value);
		/**
		 * ��ȡ�Ƿ�������ͣ��
		 */
		virtual bool allowHoveredRow();
		/**
		 * �����Ƿ�������ͣ��
		 */
		virtual void setAllowHoveredRow(bool value);
		/**
		 * ��ȡ�����е���ʽ
		 */
		virtual FCGridRowStyle* getAlternateRowStyle();
		/**
		 * ���ý����е���ʽ
		 */
		virtual void setAlternateRowStyle(FCGridRowStyle *value);
		/**
		 * ��ȡ��Ԫ��༭ģʽ
		 */
		virtual FCGridCellEditMode getCellEditMode();
		/**
		 * ���õ�Ԫ��༭ģʽ
		 */
		virtual void setCellEditMode(FCGridCellEditMode value);
		/**
		 * ��ȡ�ı���
		 */
		virtual FCTextBox* getEditTextBox();
		/**
		 * �༭�ı���
		 */
		virtual Long getGridLineColor();
		/**
		 * ��ȡ�����ߵ���ɫ
		 */
		virtual void setGridLineColor(Long value);
		/**
		 * ���������ߵ���ɫ
		 */
		virtual bool isHeaderVisible();
		/**
		 * ��ȡ����ͷ�Ƿ�ɼ�
		 */
		virtual void setHeaderVisible(bool value);
		/**
		 * ���ñ���ͷ�Ƿ�ɼ�
		 */
		virtual int getHeaderHeight();
		/**
		 * ��ȡ����ͷ�ĸ߶�
		 */
		virtual void setHeaderHeight(int value);
		/**
		 * ���ñ���ͷ�ĸ߶�
		 */
		virtual int getHorizontalOffset();
		/**
		 * ��ȡ�����������
		 */
		virtual void setHorizontalOffset(int value);
		/**
		 * ���ú����������
		 */
		virtual FCGridCell* getHoveredCell();
		/**
		 * ��ȡ������ͣ����
		 */
		virtual FCGridRow* getHoveredRow();
		/**
		 * ��ȡ�Ƿ��ѡ
		 */
		virtual bool isMultiSelect();
		/**
		 * �����Ƿ��ѡ
		 */
		virtual void setMultiSelect(bool value);
		/**
		 * ��ȡ�е���ʽ
		 */
		virtual FCGridRowStyle* getRowStyle();
		/**
		 * �����е���ʽ
		 */
		virtual void setRowStyle(FCGridRowStyle *value);
		/**
		 * ��ȡѡ�еĵ�Ԫ��
		 */
		virtual ArrayList<FCGridCell*> getSelectedCells();
		/**
		 * ����ѡ�еĵ�Ԫ��
		 */
		virtual void setSelectedCells(ArrayList<FCGridCell*> value);
		/**
		 * ��ȡѡ�е���
		 */
		virtual ArrayList<FCGridColumn*> getSelectedColumns();
		/**
		 * ����ѡ�е���
		 */
		virtual void setSelectedColumns(ArrayList<FCGridColumn*> value);
		/**
		 * ��ȡѡ����
		 */
		virtual ArrayList<FCGridRow*> getSelectedRows();
		/**
		 * ����ѡ����
		 */
		virtual void setSelectedRows(ArrayList<FCGridRow*> value);
		/**
		 * ѡ��ģʽ
		 */
		virtual FCGridSelectionMode getSelectionMode();
		/*
		* ����ѡ��ģʽ
		*/
		virtual void setSelectionMode(FCGridSelectionMode value);
		/**
		 * ��ȡ��������
		 */
		virtual FCGridSort* getSort();
		/**
		 * ������������
		 */
		virtual void setSort(FCGridSort *value);
		/**
		 * ��ȡ�Ƿ�ʹ�ö���
		 */
		virtual bool useAnimation();
		/**
		 * �����Ƿ�ʹ�ö���
		 */
		virtual void setUseAnimation(bool value);
		/**
		 * ��ȡ�����������
		 */
		virtual int getVerticalOffset();
		/**
		 * ���������������
		 */
		virtual void setVerticalOffset(int value);
	public:
		/**
		* �����
		* @param  column  ��
		*/
		virtual void addColumn(FCGridColumn *column);
		/**
		* �����
		* @param  row  ��
		*/
		virtual void addRow(FCGridRow *row);
		/**
		* ���������
		* @param  row  ��
		*/
		virtual void animateAddRow(FCGridRow *row);
		/**
		* �����Ƴ���
		* @param  row  ��
		*/
		virtual void animateRemoveRow(FCGridRow *row);
		/**
		 * ��ʼ����
		 */
		virtual void beginUpdate();
		/*
		* �����¼�
		*/
		virtual void callEvent(String eventName, Object sender, Object invoke);
		/*
		* ���ü����¼�
		*/
		virtual void callKeyEvent(String eventName, Object sender, char key, Object invoke);
		/**
		 * �������
		 */
		virtual void clear();
		/**
		 * ���������
		 */
		virtual void clearColumns();
		/**
		 * ���������
		 */
		virtual void clearRows();
		/**
		 * ��������
		 */
		virtual void endUpdate();
		/**
		* ��ȡ�����
		* @param  columnIndex  �е�����
		*/
		FCGridColumn* getColumn(int columnIndex);
		/**
		* ��ȡ�����
		* @param  columnName  ����
		*/
		FCGridColumn* getColumn(const String& columnName);
		/**
		 * ��ȡ���е���
		 */
		ArrayList<FCGridColumn*> getColumns();
		/**
		 * ��ȡ���ݵĸ߶�
		 */
		virtual int getContentHeight();
		/**
		 * ��ȡ���ݵĿ��
		 */
		virtual int getContentWidth();
		/**
		 * ��ȡ��ͼ����
		 */
		virtual String getViewType();
		/**
		 * ��ȡ��ʾƫ������
		 */
		virtual FCPoint getDisplayOffset();
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
         * ��ȡ�����б�
         */
        virtual ArrayList<String> getEventNames();
		/**
		* ���������ȡ��
		* @param  mp   ����
		*/
		FCGridRow* getRow(const FCPoint& mp);
		/**
		* ��ȡ�����
		* @param  rowIndex   �е�����
		*/
		FCGridRow* getRow(int rowIndex);
		/**
		 * ��ȡ���е���
		 */
		ArrayList<FCGridRow*> getRows();
		/**
		* ��ȡ�ɼ���������
		* @param  visiblePercent   �ɼ��ٷֱ�
		* @param  firstVisibleRowIndex  ���ȿɼ���������
		* @param  lastVisibleRowIndex  ���ɼ���������
		*/
		void getVisibleRowsIndex(double visiblePercent, int *firstVisibleRowIndex, int *lastVisibleRowIndex);
		/**
		* ������
		* @param  index  ����
		* @param  row  ��
		*/
		void insertRow(int index, FCGridRow *row);
		/**
		* �ж����Ƿ�ɼ�
		* @param  row  ��
		* @param  visiblePercent  �ɼ��ٷֱ�
		*/
		bool isRowVisible(FCRect *bounds, int rowHeight, int scrollV, double visiblePercent, int cell, int floor);
		/*
		* �ж����Ƿ�ɼ�
		*/
		bool isRowVisible(FCGridRow *row, double visiblePercent);
		/**
		* �ƶ���
		* @param  oldIndex  ����
		* @param  newIndex  ����
		*/
		void moveRow(int oldIndex, int newIndex);
		/**
		* ��Ԫ�����������
		* @param  cell    ��Ԫ��
		* @param  touchInfo  ������Ϣ
		*/
		virtual void onCellClick(FCGridCell *cell, FCTouchInfo touchInfo);
		/**
		* ��Ԫ��༭��ʼ
		* @param  cell    ��Ԫ��
		*/
		virtual void onCellEditBegin(FCGridCell *cell);
		/**
		* ��Ԫ��༭����
		* @param  cell    ��Ԫ��
		*/
		virtual void onCellEditEnd(FCGridCell *cell);
		/**
		* ��Ԫ�������·���
		* @param  cell    ��Ԫ��
		* @param  touchInfo  ������Ϣ
		*/
		virtual void onCellTouchDown(FCGridCell *cell, FCTouchInfo touchInfo);
		/**
		* ��Ԫ�������뷽��
		* @param  cell    ��Ԫ��
		* @param  touchInfo  ������Ϣ
		*/
		virtual void onCellTouchEnter(FCGridCell *cell, FCTouchInfo touchInfo);
		/**
		* ��Ԫ�����Ƴ�����
		* @param  cell    ��Ԫ��
		* @param  touchInfo  ������Ϣ
		*/
		virtual void onCellTouchLeave(FCGridCell *cell, FCTouchInfo touchInfo);
		/**
		* ��Ԫ�����ƶ�����
		* @param  cell    ��Ԫ��
		* @param  touchInfo  ������Ϣ
		*/
		virtual void onCellTouchMove(FCGridCell *cell, FCTouchInfo touchInfo);
		/**
		* ��Ԫ����̧�𷽷�
		* @param  cell    ��Ԫ��
		* @param  touchInfo  ������Ϣ
		*/
		virtual void onCellTouchUp(FCGridCell *cell, FCTouchInfo touchInfo);
		/**
		 * ��������
		 */
		virtual void onCopy();
		/**
		 * �϶�������ɼ��
		 */
		virtual bool onDragScrollPermit();
		/*
		* ���϶������¼�
		*/
		virtual void onRowDraged();
		/**
		* ���̷���
		* @param  key  ���̲���
		*/
		virtual void onKeyDown(char key);
		/**
		 * ��ͼ��ӷ���
		 */
		virtual void onLoad();
		/**
		 * ��ʧ���㷽��
		 */
		virtual void onLostFocus();
		/**
		* �������·���
		* @param  touchInfo  ������Ϣ
		*/
		virtual void onTouchDown(FCTouchInfo touchInfo);
		/**
		* �����뿪����
		* @param  touchInfo  ������Ϣ
		*/
		virtual void onTouchLeave(FCTouchInfo touchInfo);
		/**
		* �����ƶ�����
		* @param  touchInfo  ������Ϣ
		*/
		virtual void onTouchMove(FCTouchInfo touchInfo);
		/**
		* ����̧�𷽷�
		* @param  touchInfo  ������Ϣ
		*/
		virtual void onTouchUp(FCTouchInfo touchInfo);
		/**
		* �ػ�ǰ������
		* @param  paint  ��ͼ����
		* @param  clipRect  �ü�����
		*/
		virtual void onPaintForeground(FCPaint *paint, const FCRect& clipRect);
		/**
		* ���Ʊ༭�ı���
		* @param  cell  ��Ԫ��
		* @param  paint  ��ͼ����
		* @param  rect  ����
		* @param  clipRect  �ü�����
		*/
		virtual void onPaintEditTextBox(FCGridCell *cell, FCPaint *paint, const FCRect& rect, const FCRect& clipRect);
		/**
		* �б༭��ʼ
		* @param  row  ��
		*/
		virtual void onRowEditBegin(FCGridRow *row);
		/**
		 * �б༭����
		 */
		virtual void onRowEditEnd();
		/*
		* ��������
		*/
		virtual void onScaling(double scaleFactorX, double scaleFactorY);
		/**
		 * ѡ�е�Ԫ��ı䷽��
		 */
		virtual void onSelectedCellsChanged();
		/**
		 * ѡ���иı䷽��
		 */
		virtual void onSelectedColumnsChanged();
		/**
		 * ѡ���иı䷽��
		 */
		virtual void onSelectedRowsChanged();
		/**
		 * ������ͼ���ɼ�����
		 */
		virtual void onSetEmptyClipRegion();
		/**
		* �����
		* @param  timerID  ���ID
		*/
		virtual void onTimer(int timerID);
		/**
		 * �ɼ�״̬�ı䷽��
		 */
		virtual void onVisibleChanged();
		/**
		* �Ƴ���
		* @param  column  ��
		*/
		virtual void removeColumn(FCGridColumn *column);
		/**
		* �Ƴ���
		* @param  row  ��
		*/
		void removeRow(FCGridRow *row);
		/**
		 * �����еĲ���
		 */
		virtual void resetHeaderLayout();
		/**
		 * ѡ����һ��
		 */
		FCGridRow* selectFrontRow();
		/*
		* ѡ�е�һ��
		*/
		FCGridRow* selectFirstRow();
		/*
		* ѡ�е�һ��
		*/
		FCGridRow* selectLastRow();
		/**
		 * ѡ����һ��
		 */
		FCGridRow* selectNextRow();
		/**
		* ��������
		* @param  name  ��������
		* @param  value  ����ֵ
		*/
		virtual void setAttribute(const String& name, const String& value);
		/**
		* ����
		* @param  grid  ���
		* @param  column  ��
		* @param  sortMode  ����ʽ
		*/
		virtual void sortColumn(FCGrid *grid, FCGridColumn *column, FCGridColumnSortMode sortMode);
		/**
		 * ���²���
		 */
		virtual void update();
		/**
		 * ����������
		 */
		void updateSortColumn();
	};
}
