/*
 * FaceCatͼ��ͨѶ���(�ǿ�Դ)
 * ����Ȩ���:2015SR229355+2020SR0266727
 * �Ϻ����è��Ϣ�������޹�˾
 */

#ifdef __FCWINDOWFRAME_H__
#else                                                                            
#define __FCWINDOWFRAME_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "FCWindow.h"

namespace FaceCat
{
	/*
	* ����߽�
	*/
	class __FCWINDOWFRAME_H__ FCWindowFrame : public FCView{
	public:
	    /**
		 * ������ͼ�߽�
		 */
		FCWindowFrame();
		/*
		* ��������
		*/
		virtual ~FCWindowFrame();
	public:
		/**
		* �Ƿ��������
		* @param  point  ����
		*/
		virtual bool containsPoint(const FCPoint& point);
		/**
		 * ��ȡ��ͼ����
		 */
		virtual String getViewType();
		/**
		 * �ػ淽��
		 */
		virtual void invalidate();
		/**
		* ���Ʊ�������
		* @param  paint ��ͼ����
		* @param  clipRect   �ü�����
		*/
		virtual void onPaintBackground(FCPaint *paint, const FCRect& clipRect);
	};
}