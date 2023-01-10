/*
 * FaceCatͼ��ͨѶ���(�ǿ�Դ)
 * ����Ȩ���:2015SR229355+2020SR0266727
 * �Ϻ����è��Ϣ�������޹�˾
 */

#ifdef __FCGRIDBAND_H__
#else                                                                            
#define __FCGRIDBAND_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "FCGridEnums.h"
#include "FCBandedGrid.h"
#include "FCBandedGridColumn.h"
#include "..\\btn\\FCButton.h"

namespace FaceCat{
	class FCBandedGrid;
	class FCBandedGridColumn;

	/*
	* ����
	*/
	class __FCGRIDBAND_H__ FCGridBand : public FCButton{
	public:
	    /**
		 * �Ƿ���Ե�����С
		 */
		bool m_allowResize;
		/**
		 * ���
		 */
		FCBandedGrid *m_grid;
		/**
		 * ����
		 */
		int m_index;
		/**
		 * ������
		 */
		FCGridBand *m_parentBand;
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
		 * ������С״̬��1:��� 2:�Ҳ�
		 */
		int m_resizeState;
	public:
	    /**
		 * �ӱ���
		 */
		ArrayList<FCGridBand*> m_bands;
		/**
		 * �ӱ����
		 */
		ArrayList<FCBandedGridColumn*> m_columns;
		/*
		* ���캯��
		*/
		FCGridBand();
		/*
		* ��������
		*/
		virtual ~FCGridBand();
		/**
		 * ��ȡ�Ƿ���Ե�����С
		 */
		virtual bool allowResize();
		/**
		 * �����Ƿ���Ե�����С
		 */
		virtual void setAllowResize(bool value);
		/**
		 * ��ȡ���
		 */
		virtual FCBandedGrid* getGrid();
		/**
		 * ���ñ��
		 */
		virtual void setGrid(FCBandedGrid *value);
		/**
		 * ��ȡ����
		 */
		virtual int getIndex();
		/**
		 * ��������
		 */
		virtual void setIndex(int value);
		/**
		 * ��ȡ������
		 */
		virtual FCGridBand* getParentBand();
		/**
		 * ���ø�����
		 */
		virtual void setParentBand(FCGridBand *value);
	public:
	    /**
		 * ��ӱ���
		 */
		void addBand(FCGridBand *band);
		/**
		 * ��ӱ����
		 */
		void addColumn(FCBandedGridColumn *column);
		/**
		 * �������
		 */
		void clearBands();
		/**
		 * �����
		 */
		void clearColumns();
		/**
		 * ��ȡ���е��ӱ����
		 */
		ArrayList<FCBandedGridColumn*> getAllChildColumns();
		/**
		 * ��ȡ�����б�
		 */
		ArrayList<FCGridBand*> getBands();
		/**
		 * ��ȡ��ͷ
		 */
		ArrayList<FCBandedGridColumn*> getColumns();
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
		* @param  index   ����
		* @param  band   ����
		*/
		void insertBand(int index, FCGridBand *band);
		/**
		* ��������
		* @param  index   ����
		* @param  band   ����
		*/
		void insertColumn(int index, FCBandedGridColumn *column);
		/**
		* �������·���
         * @param  touchInfo    ������Ϣ
		*/
		virtual void onTouchDown(FCTouchInfo touchInfo);
		/**
		* �����ƶ�����
         * @param  touchInfo    ������Ϣ
		*/
		virtual void onTouchMove(FCTouchInfo touchInfo);
		/**
		* ����̧�𷽷�
         * @param  touchInfo    ������Ϣ
		*/
		virtual void onTouchUp(FCTouchInfo touchInfo);
		/**
		 * �Ƴ�����
		 */
		void removeBand(FCGridBand *band);
		/**
		 * �Ƴ������
		 */
		void removeColumn(FCBandedGridColumn *column);
		/**
		 * ������ͷ����
		 */
		virtual void resetHeaderLayout();
		/**
		* ��������
		* @param  name  ��������
		* @param  value  ����ֵ
		*/
		virtual void setAttribute(const String& name, const String& value);
	};
}