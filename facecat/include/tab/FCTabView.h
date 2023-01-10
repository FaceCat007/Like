/*
 * FaceCatͼ��ͨѶ���(�ǿ�Դ)
 * ����Ȩ���:2015SR229355+2020SR0266727
 * �Ϻ����è��Ϣ�������޹�˾
 */
#ifdef __FCTABVIEW_H__
#else                                                                            
#define __FCTABVIEW_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "..\\core\\FCTran.h"
#include "..\\div\\FCDiv.h"
#include "FCTabPage.h"

namespace FaceCat{
    /**
	* ҳ�Ĳ���λ��
	*/
	enum __FCTABVIEW_H__ FCTabPageLayout{
	    /**
		 * �·�
		 */
		FCTabPageLayout_Bottom,
		/**
		 * ���
		 */
		FCTabPageLayout_Left,
		/**
		 * �Ҳ�
		 */
		FCTabPageLayout_Right,
		/**
		 * ����
		 */
		FCTabPageLayout_Top
	};
	
	class FCTabPage;

	/*
	* ��ҳ����ͼ
	*/
	class __FCTABVIEW_H__ FCTabView:public FCDiv{
	private:
	    /**
		 * ���ID
		 */
		int m_timerID;
	public:
	    /**
		 * ����״̬
		 */
		int m_animationState;
		/**
		 * ҳ�Ĳ���λ��
		 */
		FCTabPageLayout m_layout;
		/**
		 * ѡ�е�����
		 */
		int m_selectedIndex;
		/**
		 * �Ƿ�ʹ�ö���
		 */
		bool m_useAnimation;
		/**
		 * �����ƶ�
		 */
		void drawMoving();
		/*
		* ��ȡ����
		*/
		int getTabPageIndex(FCTabPage *tabPage);
	public:
	    /**
		 * ����ҳ
		 */
		ArrayList<FCTabPage*> m_tabPages;
		/* 
		* ������ҳ��
		*/
		FCTabView();
		/*
		* ɾ����ҳ��
		*/
		virtual ~FCTabView();
		/**
		 * ��ȡҳ�Ĳ���λ��
		 */
		virtual FCTabPageLayout getLayout();
		/**
		 * ����ҳ�Ĳ���λ��
		 */
		virtual void setLayout(FCTabPageLayout value);
		/**
		 * ��ȡѡ�е�����
		 */
		virtual int getSelectedIndex();
		/**
		 * ����ѡ�е�����
		 */
		virtual void setSelectedIndex(int value);
		/**
		 * ��ȡѡ�е�ҳ
		 */
		virtual FCTabPage* getSelectedTabPage();
		/**
		 * ����ѡ�е�ҳ
		 */
		virtual void setSelectedTabPage(FCTabPage *value);
		/**
		 * ��ȡ�Ƿ�ʹ�ö���
		 */
		virtual bool useAnimation();
		/**
		 * �����Ƿ�ʹ�ö���
		 */
		virtual void setUseAnimation(bool value);
	public:
	    /**
		 * �����ͼ����
		 */
		virtual void addView(FCView *view);
		/**
		 * ��ȡ��ͼ����
		 */
		virtual String getViewType();
		/**
		 * �����ͼ
		 */
		virtual void clearViews();
		/**
		* ��ȡ����ֵ
		* @param  name  ��������
		* @param  value  ��������ֵ
		* @param  type  ������������
		*/
		virtual void getAttribute(const String& name, String *value, String *type);
		/**
		 * ��ȡ���������б�
		 */
		virtual ArrayList<String> getAttributeNames();
		/**
         * ��ȡ�����б�
         */
        virtual ArrayList<String> getEventNames();
		/**
		* ������ͼ
		* @param  index  ����
		* @param  view  ��ͼ
		*/
		virtual void insertView(int index, FCView *view);
		/**
		 * ��ʼ�϶�ҳͷ
		 */
        virtual void onDragTabHeaderBegin(FCTabPage *tabPage);
        /**
		 * �����϶�ҳͷ
		 */
        virtual void onDragTabHeaderEnd(FCTabPage *tabPage);
        /**
		 * ҳͷ�϶���
		 */
        virtual void onDraggingTabHeader(FCTabPage *tabPage);
        /**
		 * �����ͼ����
		 */
		virtual void onLoad();
		/**
		 * ҳ�ı䷽��
		 */
		virtual void onSelectedTabPageChanged();
		/**
		 * �����
		 */
		virtual void onTimer(int timerID);
		/**
		 * �Ƴ���ͼ
		 */
		virtual void removeView(FCView *view);
		/**
		* ��������
		* @param  name  ��������
		* @param  value  ����ֵ
		*/
		virtual void setAttribute(const String& name, const String& value);
		/**
		 * ���²���
		 */
		virtual void update();
	};
}
