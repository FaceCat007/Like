/*
 * FaceCatͼ��ͨѶ���(�ǿ�Դ)
 * ����Ȩ���:2015SR229355+2020SR0266727
 * �Ϻ����è��Ϣ�������޹�˾
 */

#ifdef __FCRECT2D_H__
#else                                                                            
#define __FCRECT2D_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "..\\core\\FCTran.h"

namespace FaceCat{
    /**
     * ������ͼ
     */
	class __FCRECT2D_H__ FCRect2D : public FCView{
	public:
		/*
		* ���캯��
		*/
		FCRect2D();
		/*
		* ��������
		*/
		virtual ~FCRect2D();
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