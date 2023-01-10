/*
 * FaceCatͼ��ͨѶ���(�ǿ�Դ)
 * ����Ȩ���:2015SR229355+2020SR0266727
 * �Ϻ����è��Ϣ�������޹�˾
 */

#ifdef __FCSCROLLBAR_H__
#else                                                                            
#define __FCSCROLLBAR_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "..\\btn\\FCButton.h"

namespace FaceCat{
	/*
	* ������
	*/
	class __FCSCROLLBAR_H__ FCScrollBar:public FCView, public FCEventCallBack, public FCTouchEventCallBack{
	private:
        /**
		 * ���ID
		 */
		int m_timerID;
		/**
		 * ������
		 */
		int m_tick;
	public:
		FCButton *m_addButton;
		/**
		 * ��ǰ�ļ��ٶ�
		 */
		int m_addSpeed;
		/**
		 * ����������ť
		 */
		FCButton *m_backButton;
		/**
		 * ���ݳߴ�
		 */
		int m_contentSize;
		/**
		 * �Ƿ���������
		 */
		bool m_isAdding;
		/**
		 * �Ƿ����ڼ���
		 */
		bool m_isReducing;
		/**
		 * �������гߴ�
		 */
		int m_lineSize;
		/**
		 * ҳ�ĳߴ�
		 */
		int m_pageSize;
		/**
		 * ��������
		 */
		int m_pos;
		/**
		 * ������ť
		 */
		FCButton *m_reduceButton;
		/**
		 * ������ť
		 */
		FCButton *m_scrollButton;
	public:
		/*
		* ���캯��
		*/
		FCScrollBar();
		/*
		* ��������
		*/
		virtual ~FCScrollBar();
		/**
		 * ������ť
		 */
		virtual FCButton* getAddButton();
		/**
		 * ��ȡ��ǰ�ļ��ٶ�
		 */
		virtual int getAddSpeed();
		/**
		 * ���õ�ǰ�ļ��ٶ�
		 */
		virtual void setAddSpeed(int value);
		/**
		 * ��ȡ����������ť
		 */
		virtual FCButton* getBackButton();
		/**
		 * ��ȡ���ݳߴ�
		 */
		virtual int getContentSize();
		/**
		 * �������ݳߴ�
		 */
		virtual void setContentSize(int value);
		/**
		 * ��ȡ�Ƿ���������
		 */
		virtual bool isAdding();
		/**
		 * �����Ƿ���������
		 */
		virtual void setIsAdding(bool value);
		/**
		 * ��ȡ�Ƿ����ڼ���
		 */
		virtual bool isReducing();
		/**
		 * �����Ƿ����ڼ���
		 */
		virtual void setIsReducing(bool value);
		/**
		 * ��ȡÿ�ι������гߴ�
		 */
		virtual int getLineSize();
		/*
		* ����ÿ�ι������гߴ�
		*/
		virtual void setLineSize(int value);
		/**
		 * ��ȡҳ�ĳߴ�
		 */
		virtual int getPageSize();
		/**
		 * ����ҳ�ĳߴ�
		 */
		virtual void setPageSize(int value);
		/**
		 * ��ȡ��������
		 */
		virtual int getPos();
		/**
		 * ���ù�������
		 */
		virtual void setPos(int value);
		/**
		 * ������ť
		 */
		virtual FCButton* getReduceButton();
		/**
		 * ��ȡ������ť
		 */
		virtual FCButton* getScrollButton();
	public:
		/*
		* �����¼�
		*/
		virtual void callEvent(String eventName, Object sender, Object invoke);
		/*
		* ���ü����¼�
		*/
		virtual void callTouchEvent(String eventName, Object sender, FCTouchInfo touchInfo, Object invoke);
		/**
         * ��ȡ�����б�
         */
        virtual ArrayList<String> getEventNames();
	    /**
		 * ��ȡ��ͼ����
		 */
		virtual String getViewType();
		/**
		 * �б�󷽷�
		 */
		virtual void lineAdd();
		/**
		 * �б�С����
		 */
		virtual void lineReduce();
		/**
		* ����������ť�����¼�����
		* @params touchInfo  ������Ϣ
		*/
		virtual void onAddButtonTouchDown(FCTouchInfo touchInfo);
		/**
		 * ����������ţ̌���¼�����
		 */
		virtual void onAddButtonTouchUp(FCTouchInfo touchInfo);
		/**
		 * ���ٹ�������
		 */
		virtual void onAddSpeedScrollEnd();
		/**
		 * �Զ����ٹ�����ʼ
		 */
		virtual void onAddSpeedScrollStart(DWORD startTime, DWORD nowTime, int start, int end);
		/**
		 * �Զ����ٹ�����
		 */
		virtual int onAddSpeedScrolling();
		/**
		 * �϶���������
		 */
		virtual void onDragScroll();
		/**
		 * ��ͼ��ӷ���
		 */
		virtual void onLoad();
		/**
		 * ����������ť�����¼�����
		 */
		virtual void onReduceButtonTouchDown(FCTouchInfo touchInfo);
		/**
		 * ����������ţ̌���¼��ص�����
		 */
		virtual void onReduceButtonTouchUp(FCTouchInfo touchInfo);
		/**
		 * ��������
		 */
		virtual void onScrolled();
		/**
		 * �ɼ�״̬�ı䷽��
		 */
		virtual void onVisibleChanged();
		/**
		 * ҳ��󷽷�
		 */
		virtual void pageAdd();
		/**
		 * ҳ��С����
		 */
		virtual void pageReduce();
		/**
		 * ��������ʼ
		 */
		virtual void scrollToBegin();
		/**
		 * ����������
		 */
		virtual void scrollToEnd();
		/**
		 * ���ص�����
		 */
		virtual void onTimer(int timerID);
	};
}
