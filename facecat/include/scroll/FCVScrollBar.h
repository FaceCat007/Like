/*
 * FaceCatͼ��ͨѶ���(�ǿ�Դ)
 * ����Ȩ���:2015SR229355+2020SR0266727
 * �Ϻ����è��Ϣ�������޹�˾
 */

#ifdef __FCVSCROLLBAR_H__
#else                                                                            
#define __FCVSCROLLBAR_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "FCScrollBar.h"

namespace FaceCat{
	/*
	* ���������
	*/
	class __FCVSCROLLBAR_H__ FCVScrollBar:public FCScrollBar{
	public:
		/*
		* ���캯��
		*/
		FCVScrollBar();
		/*
		* ��������
		*/
		virtual ~FCVScrollBar();
		/*
		* �����¼�
		*/
		virtual void callTouchEvent(String eventName, Object sender, FCTouchInfo touchInfo, Object invoke);
		/**
		 * ��ȡ��ͼ����
		 */
		virtual String getViewType();
		/**
		 * ������������ť�������»ص�����
		 */
		virtual void onBackButtonTouchDown(FCTouchInfo touchInfo);
		/**
		 * ������������ť����̧�𷽷�
		 */
		virtual void onBackButtonTouchUp(FCTouchInfo touchInfo);
		/**
		 * �϶���������
		 */
		virtual void onDragScroll();
		/**
		 * �����ͼ����
		 */
		virtual void onLoad();
		/**
		 * ���²��ַ���
		 */
		virtual void update();
	};
}
