/*
 * FaceCatͼ��ͨѶ���(�ǿ�Դ)
 * ����Ȩ���:2015SR229355+2020SR0266727
 * �Ϻ����è��Ϣ�������޹�˾
 */

#ifdef __FCELLIPSE2D_H__
#else                                                                            
#define __FCELLIPSE2D_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "..\\core\\FCTran.h"

namespace FaceCat{
	/**
     * ��Բ��ͼ
     */
	class __FCELLIPSE2D_H__ FCEllipse2D : public FCView{
	public:
		/*
		* ���캯��
		*/
		FCEllipse2D();
		/*
		* ��������
		*/
		virtual ~FCEllipse2D();
	public:
	    /**
	     * ��ȡ��ͼ����
	     */
		virtual String getViewType();
	    /**
         * �ػ汳������
         * @param paint    ��ͼ����
         * @param clipRect �ü�����
         */
		virtual void onPaint(FCPaint *paint, const FCRect& clipRect);
	    /**
         * �ػ���߷���
         * @param paint    ��ͼ����
         * @param clipRect �ü�����
         */
		virtual void onPaintBorder(FCPaint *paint, const FCRect& clipRect);
	};
}
