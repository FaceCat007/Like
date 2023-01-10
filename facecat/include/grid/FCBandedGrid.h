/*
 * FaceCatͼ��ͨѶ���(�ǿ�Դ)
 * ����Ȩ���:2015SR229355+2020SR0266727
 * �Ϻ����è��Ϣ�������޹�˾
 */

#ifdef __FCBANDEDGRID_H__
#else                                                                            
#define __FCBANDEDGRID_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "FCGridEnums.h"
#include "FCBandedGridColumn.h"
#include "FCGridBand.h"
#include "FCGrid.h"

namespace FaceCat{
	class FCBandedGridColumn;
	class FCGridBand;

	/*
	* ��״���
	*/
	class __FCBANDEDGRID_H__ FCBandedGrid : public FCGrid{
	public:
	    /**
		 * ��ȡ���пɼ����Ŀ��
		 */
		int getAllVisibleBandsWidth();
	public:
	    /**
		 * ����
		 */
		ArrayList<FCGridBand*> m_bands;
		/*
		* ���캯��
		*/
		FCBandedGrid();
		/*
		* ��������
		*/
		virtual ~FCBandedGrid();
	public:
		/**
		* ��ӱ���
		* @param  band  ����
		*/
		void addBand(FCGridBand *band);
		/**
		* �����
		* @param  column  ��
		*/
		virtual void addColumn(FCGridColumn *column);
		/**
		 * �������
		 */
		void clearBands();
		/**
		 * ������е���
		 */
		virtual void clearColumns();
        /**
		 * ��ȡ�����б�
		 */
		ArrayList<FCGridBand*> getBands();
		/**
		 * ��ȡ���ݵĿ��
		 */
		virtual int getContentWidth();
		/**
		 * ��ȡ��ͼ����
		 */
		virtual String getViewType();
		/**
		* �������
		* @param  index  ����
		* @param  band  ����
		*/
		void insertBand(int index, FCGridBand *band);
		/**
		 * ������ͼ���ɼ�����
		 */
		virtual void onSetEmptyClipRegion();
		/**
		* �Ƴ�����
		* @param  band  ����
		*/
		void removeBand(FCGridBand *band);
		/**
		* �Ƴ���ͷ
		* @param  column  ��ͷ
		*/
		virtual void removeColumn(FCGridColumn *column);
		/**
		 * ������ͷ����
		 */
		virtual void resetHeaderLayout();
		/**
		 * ���²���
		 */
		virtual void update();
	};
}
