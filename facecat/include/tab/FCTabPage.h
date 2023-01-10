/*
 * FaceCatͼ��ͨѶ���(�ǿ�Դ)
 * ����Ȩ���:2015SR229355+2020SR0266727
 * �Ϻ����è��Ϣ�������޹�˾
 */

#ifdef __FCTABPAGE_H__
#else                                                                            
#define __FCTABPAGE_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "..\\div\\FCDiv.h"
#include "..\\btn\\FCButton.h"
#include "FCTabView.h"

namespace FaceCat{
	class FCTabView;
    /**
	 * ��ҳ����ͼ
	 */
	class __FCTABPAGE_H__ FCTabPage:public FCDiv{
	public:
        /**
		 * ��ȡ������ҳͷ��ť
		 */
		FCButton *m_headerButton;
		/**
		 * ��ȡ������ͷ����λ��
		 */
		FCPoint m_headerLocation;
		/**
		 * ��ҳ����ͼ
		 */
		FCTabView *m_tabView;
	public:
		/*
		* ����ҳ
		*/
		FCTabPage();
		/*
		* ɾ��ҳ
		*/
		virtual ~FCTabPage();
		/**
		 * ��ȡҳͷ��ť
		 */
		virtual FCButton* getHeaderButton();
		/**
		 * ����ҳͷ��ť
		 */
		virtual void setHeaderButton(FCButton *value);
		/**
		 * ��ȡͷ����λ��
		 */
		virtual FCPoint getHeaderLocation();
		/**
		 * ����ͷ����λ��
		 */
		virtual void setHeaderLocation(FCPoint value);
		/**
		 * ��ȡͷ���Ƿ�ɼ�
		 */
		virtual bool isHeaderVisible();
		/**
		 * ����ͷ���Ƿ�ɼ�
		 */
		virtual void setHeaderVisible(bool value);
		/**
		 * ��ȡ��ҳ����ͼ
		 */
		virtual FCTabView* getTabView();
		/**
		 * ���ö�ҳ����ͼ
		 */
		virtual void setTabView(FCTabView *value);
	public:
		/*
		* �����¼�
		*/
		virtual void callEvent(String eventName, Object sender, Object invoke);
		/*
		* �����¼�
		*/
		virtual void callTouchEvent(String eventName, Object sender, FCTouchInfo touchInfo, Object invoke);
	    /**
		 * ��ȡ��ͼ����
		 */
		virtual String getViewType();
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
		 * �����ͼ����
		 */
		virtual void onLoad();
		/**
		 * ���ָı䷽��
		 */
		virtual void onTextChanged();
		/**
		* ��������
		* @param  name  ��������
		* @param  value  ����ֵ
		*/
		virtual void setAttribute(const String& name, const String& value);
	};
}
