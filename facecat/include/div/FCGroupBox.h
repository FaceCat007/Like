/*
 * FaceCatͼ��ͨѶ���(�ǿ�Դ)
 * ����Ȩ���:2015SR229355+2020SR0266727
 * �Ϻ����è��Ϣ�������޹�˾
 */

#ifdef __FCGROUPBOX_H__
#else                                                                            
#define __FCGROUPBOX_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "FCDiv.h"

namespace FaceCat{
    /**
	 * ����ͼ
	 */
	class __FCGROUPBOX_H__ FCGroupBox : public FCDiv{
	public:
	    /**
		 * ��������ͼ
		 */
		FCGroupBox();
		virtual ~FCGroupBox();
	public:
	    /**
		 * ��ȡ��ͼ����
		 */
		virtual String getViewType();
		/**
		* �ػ���߷���
		* @param  paint   ��ͼ����
		* @param  clipRect   �ü�����
		*/
		virtual void onPaintBorder(FCPaint *paint, const FCRect& clipRect);
		/**
		* �ػ�ǰ������
		* @param  paint   ��ͼ����
		* @param  clipRect   �ü�����
		*/
		virtual void onPaintForeground(FCPaint *paint, const FCRect& clipRect);
	};
}