/*
 * FaceCatͼ��ͨѶ���(�ǿ�Դ)
 * ����Ȩ���:2015SR229355+2020SR0266727
 * �Ϻ����è��Ϣ�������޹�˾
 */

#ifdef __FCBANDEDGRIDCOLUMN_H__
#else                                                                            
#define __FCBANDEDGRIDCOLUMN_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "FCGridEnums.h"
#include "FCBandedGrid.h"
#include "FCGridColumn.h"
#include "FCGridBand.h"

namespace FaceCat{
	class FCBandedGrid;
	class FCGridColumn;
	class FCGridBand;

	/*
	* ����ͷ�����
	*/
	class __FCBANDEDGRIDCOLUMN_H__ FCBandedGridColumn : public FCGridColumn{
	public:
	    /**
		 * ����
		 */
		FCGridBand *m_band;
	public:
		/*
		* ���캯��
		*/
		FCBandedGridColumn();
		/*
		* ��������
		*/
		virtual ~FCBandedGridColumn();
		/**
		 * ��ȡ����
		 */
		virtual FCGridBand* getBand();
		/**
		 * ���ñ���
		 */
		virtual void setBand(FCGridBand *value);
	public:
	    /**
		 * ��ȡ��ͼ����
		 */
		virtual String getViewType();
		/**
		 * �϶���ʼ����
		 */
		virtual bool onDragBegin();
		/**
		* �������·���
         * @param  touchInfo   ������Ϣ
		*/
		virtual void onTouchDown(FCTouchInfo touchInfo);
		/**
		* �����ƶ�����
         * @param  touchInfo   ������Ϣ
		*/
		virtual void onTouchMove(FCTouchInfo touchInfo);
	};
}
