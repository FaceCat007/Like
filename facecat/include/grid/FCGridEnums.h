/*
 * FaceCatͼ��ͨѶ���(�ǿ�Դ)
 * ����Ȩ���:2015SR229355+2020SR0266727
 * �Ϻ����è��Ϣ�������޹�˾
 */

#ifdef __FCGRIDENUMS_H__
#else                                                                            
#define __FCGRIDENUMS_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"

namespace FaceCat{
    /**
	 * ���������ʽ
	 */
	enum __FCGRIDENUMS_H__ FCGridColumnSortMode{
		/**
		 * ����
		 */
		FCGridColumnSortMode_Asc,
		/**
		 * ����
		 */
		FCGridColumnSortMode_Desc,
		/**
		 * ������
		 */
		FCGridColumnSortMode_None
	};

    /**
	 * ���ѡ��ģʽ
	 */
	enum __FCGRIDENUMS_H__ FCGridSelectionMode{
	    /**
		 * ѡ�е�Ԫ��
		 */
		FCGridSelectionMode_SelectCell,
		/**
		 * ѡ������
		 */
		FCGridSelectionMode_SelectFullColumn,
		/**
		 * ѡ������
		 */
		FCGridSelectionMode_SelectFullRow,
		/**
		 * ��ѡ��
		 */
		FCGridSelectionMode_SelectNone
	};

    /**
	 * ��Ԫ��༭ģʽ
	 */
	enum __FCGRIDENUMS_H__ FCGridCellEditMode{
	    /**
		 * ˫��
		 */
        FCGridCellEditMode_DoubleClick,
        /**
		 * ��Ч
		 */
        FCGridCellEditMode_None,
        /**
		 * ����
		 */
        FCGridCellEditMode_SingleClick
	};
}
