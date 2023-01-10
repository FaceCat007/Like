/*
 * FaceCatͼ��ͨѶ���(�ǿ�Դ)
 * ����Ȩ���:2015SR229355+2020SR0266727
 * �Ϻ����è��Ϣ�������޹�˾
 */

#ifdef __FCDIV_H__
#else                                                                            
#define __FCDIV_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "..\\core\\FCView.h"
#include "..\\scroll\\FCScrollBar.h"
#include "..\\scroll\\FCHScrollBar.h"
#include "..\\scroll\\FCVScrollBar.h"

namespace FaceCat{
	class FCHScrollBar;
	class FCVScrollBar;

	/*
	* ͼ��
	*/
	class __FCDIV_H__ FCDiv : public FCView, public FCEventCallBack, public FCKeyEventCallBack, public FCTouchEventCallBack{
	public:
	    /**
		 * �Ƿ������϶�����
		 */
		bool m_allowDragScroll;
		/**
		 * ���������
		 */
		FCHScrollBar *m_hScrollBar;
		/**
		 * �Ƿ����ڱ��϶�
		 */
		bool m_isDragScrolling;
		/**
		 * �Ƿ����ڹ���2
		 */
		bool m_isDragScrolling2;
		/*
		* �Ƿ�������
		*/
		bool m_mustUpdate;
		/**
		 * �Ƿ�׼���϶�����
		 */
		bool m_readyToDragScroll;
		/**
		 * �Ƿ���ʾ���������
		 */
		bool m_showHScrollBar;
		/**
		 * �Ƿ���ʾ���������
		 */
		bool m_showVScrollBar;
		/**
		 * ��ʼ�ƶ���λ��
		 */
		FCPoint m_startMovePoint;
		/**
		 * ��ʼ�ƶ��ĺ���λ��
		 */
		int m_startMovePosX;
		/**
		 * ��ʼ�ƶ�������λ��
		 */
		int m_startMovePosY;
		/**
		 * ��ʼ�ƶ�ʱ��
		 */
		DWORD m_startMoveTime;
		/**
		 * ���������
		 */
		FCVScrollBar *m_vScrollBar;
	public:
		/*
		* ���캯��
		*/
		FCDiv();
		/*
		* ��������
		*/
		virtual ~FCDiv();
		/**
		 * ��ȡ�Ƿ������϶�����
		 */
		virtual bool allowDragScroll();
		/**
		 * �����Ƿ������϶�����
		 */
		virtual void setAllowDragScroll(bool value);
		/**
		 * ��ȡ���������
		 */
		FCHScrollBar* getHScrollBar();
		/**
		 * ��ȡ�Ƿ���ʾ���������
		 */
		virtual bool showHScrollBar();
		/**
		 * �����Ƿ���ʾ���������
		 */
		virtual void setShowHScrollBar(bool value);
		/**
		 * ��ȡ�Ƿ����ڱ��϶�
		 */
		virtual bool isDragScrolling();
		/**
		 * ��ȡ�Ƿ���ʾ���������
		 */
		virtual bool showVScrollBar();
		/**
		 * �����Ƿ���ʾ���������
		 */
		virtual void setShowVScrollBar(bool value);
		/**
		 * ��ȡ���������
		 */
		virtual FCVScrollBar* getVScrollBar();
	public:
		/*
		* �����¼�
		*/
		virtual void callEvent(String eventName, Object sender, Object invoke);
		/*
		* ������ť���̰����¼�
		*/
		virtual void callKeyEvent(String eventName, Object sender, char key, Object invoke);
		/*
		* ������ť���������¼�
		*/
		virtual void callTouchEvent(String eventName, Object sender, FCTouchInfo touchInfo, Object invoke);
		/**
		 * ���������ͼ
		 */
		virtual void clearChildViews();
	    /**
		 * ��ȡ���ݵĸ߶�
		 */
		virtual int getContentHeight();
		/**
		 * ��ȡ���ݵĿ��
		 */
		virtual int getContentWidth();
		/**
		 * ��ȡ��ͼ����
		 */
		virtual String getViewType();
		/**
		 * ��ȡ��ʾƫ������
		 */
		virtual FCPoint getDisplayOffset();
		/**
		* ��ȡ����ֵ
		* @param  name   ��������
		* @param  value   ��������ֵ
		* @param  type   ������������
		*/
		virtual void getAttribute(const String& name, String *value, String *type);
		/**
		 * ��ȡ���������б�
		 */
		virtual ArrayList<String> getAttributeNames();
		/**
		 * ���¹���һ��
		 */
		virtual void lineDown();
		/**
		 * �������һ��
		 */
		virtual void lineLeft();
		/**
		 * ���ҹ���һ��
		 */
		virtual void lineRight();
		/**
		 * ���Ϲ���һ��
		 */
		virtual void lineUp();
		/**
		* �϶�׼������
		* @param  startOffset  �����϶���ƫ��������
		*/
		virtual void onDragReady(FCPoint *startOffset);
		/**
		 * �϶���������
		 */
		virtual void onDragScrollEnd();
		/**
		 * �϶�������
		 */
		virtual void onDragScrolling();
		/**
		 * �϶�������ɼ��
		 */
		virtual bool onDragScrollPermit();
		/**
		 * �϶�������ʼ
		 */
		virtual void onDragScrollStart();
		/**
		* ���̰��·���
		* @param  key  ����
		*/
		virtual void onKeyDown(char key);
		/**
		* �����������
		* @param  touchInfo   ������Ϣ
		*/
		virtual void onTouchDown(FCTouchInfo touchInfo);
		/**
		* �����ƶ�����
		* @param  touchInfo   ������Ϣ
		*/
		virtual void onTouchMove(FCTouchInfo touchInfo);
		/**
		* ����̧�𷽷�
		* @param  touchInfo   ������Ϣ
		*/
		virtual void onTouchUp(FCTouchInfo touchInfo);
		/**
		* ������������
		* @param  touchInfo   ������Ϣ
		*/
		virtual void onTouchWheel(FCTouchInfo touchInfo);
		/**
		* Ԥ�������¼�
		* @param  eventName   �¼�ID
		* @param  touchInfo   ������Ϣ
		*/
		virtual bool onPreviewsTouchEvent(String eventName, FCTouchInfo touchInfo);
		/**
		 * ���·�һҳ
		 */
		virtual void pageDown();
		/**
		 * ����һҳ
		 */
		virtual void pageLeft();
		/**
		 * ���ҷ�һҳ
		 */
		virtual void pageRight();
		/**
		 * ���Ϸ�һҳ
		 */
		virtual void pageUp();
		/**
		* ��������ֵ
		* @param  name   ��������
		* @param  value   ����ֵ
		*/
		virtual void setAttribute(const String& name, const String& value);
		/**
		 * ���²��ַ���
		 */
		virtual void update();
		/**
		 * ���¹������Ĳ���
		 */
		virtual void updateScrollBar();
	};
}
