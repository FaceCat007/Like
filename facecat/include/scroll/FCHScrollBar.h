/*
 * FaceCatͼ��ͨѶ���(�ǿ�Դ)
 * ����Ȩ���:2015SR229355+2020SR0266727
 * �Ϻ����è��Ϣ�������޹�˾
 */

#ifdef __FCHSCROLLBAR_H__
#else                                                                            
#define __FCHSCROLLBAR_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "FCScrollBar.h"

/*
* ���������
*/
namespace FaceCat{
	class __FCHSCROLLBAR_H__ FCHScrollBar:public FCScrollBar{
	public:
		/*
		* ���캯��
		*/
		FCHScrollBar();
		/*
		* ��������
		*/
		virtual ~FCHScrollBar();
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
