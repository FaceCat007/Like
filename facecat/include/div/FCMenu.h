/*
 * FaceCatͼ��ͨѶ���(�ǿ�Դ)
 * ����Ȩ���:2015SR229355+2020SR0266727
 * �Ϻ����è��Ϣ�������޹�˾
 */

#ifdef __FCMENU_H__
#else                                                                            
#define __FCMENU_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "..\\div\\FCLayoutDiv.h"
#include "FCMenuItem.h"

namespace FaceCat{
	class __FCMENU_H__ FCMenuItem;
	/*
	* ����˵��¼�
	*/
    class __FCMENU_H__ FCMenuItemTouchEventCallBack {
	public:
		FCMenuItemTouchEventCallBack(){}
		virtual ~FCMenuItemTouchEventCallBack(){}
		virtual void callMenuItemTouchEvent(String eventName, Object sender, FCMenuItem *item, FCTouchInfo touchInfo, Object invoke){}
    };
	/*
	* �˵�
	*/
	class __FCMENU_H__ FCMenu : public FCLayoutDiv{
	private:
	    /**
		 * �����
		 */
		int m_timerID;
	public:
	    /**
		 * �Ƿ��Զ�����
		 */
		bool m_autoHide;
		/**
		 * ���˵���
		 */
		FCMenuItem *m_parentItem;
		/**
		 * �Ƿ񵯳�
		 */
		bool m_popup;
		/**
		* �Զ���Ӧλ�úʹ�С
		* @param  menu  �˵�
		*/
		virtual void adjust(FCMenu *menu);
		/**
		* ���ͼ���Ƿ���н���
		* @param  items  ��ͼ����
		*/
		virtual bool checkDivFocused(ArrayList<FCMenuItem*> items);
		/**
		* ��齹��
		* @param  view  ��ͼ
		*/
		virtual bool checkFocused(FCView *view);
		/**
		* �ر�������ͼ
		* @param  items  �˵�����
		*/
		virtual bool closeMenus(ArrayList<FCMenuItem*> items);
	public:
		/**
		* ���ò˵��Ĵ����¼�
		* @param  eventName   �¼�ID
		* @param  item   �˵���
         * @param  touchInfo   ������Ϣ
        */
		void callMenuItemTouchEvent(String eventName, FCMenuItem *item, FCTouchInfo touchInfo);
	public:
	    /**
		 * �˵���
		 */
		ArrayList<FCMenuItem*> m_items;
		/*
		* ���캯��
		*/
		FCMenu();
		/*
		* ��������
		*/
		virtual ~FCMenu();
		/**
		 * ��ȡ�Ƿ��Զ�����
		 */
		virtual bool autoHide();
		/**
		 * �����Ƿ��Զ�����
		 */
		virtual void setAutoHide(bool value);
		/**
		 * ��ȡ���˵���
		 */
		virtual FCMenuItem* getParentItem();
		/**
		 * ���ø��˵���
		 */
		virtual void setParentItem(FCMenuItem *value);
		/**
		 * ��ȡ�Ƿ񵯳�
		 */
		virtual bool canPopup();
		/**
		 * �����Ƿ񵯳�
		 */
		virtual void setPopup(bool value);
	public:
		/**
		* �����
		* @param  item  �˵���
		*/
		virtual void addItem(FCMenuItem *item);
		/**
		 * ������е���
		 */
		virtual void clearItems();
		/**
		 * �����˵�
		 */
		virtual FCMenu* createDropDownMenu();
		/**
		 * ��ȡ��ͼ����
		 */
		virtual String getViewType();
		/**
		 * ��ȡ���еĲ˵���
		 */
		virtual ArrayList<FCMenuItem*> getItems();
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
         * ��ȡ�����б�
         */
        virtual ArrayList<String> getEventNames();
		/**
		* ������
		* @param  index  ����
		* @param  item   �˵���
		*/
		virtual void insertItem(int index, FCMenuItem *item);
		/**
		 * �Ƿ񲻴����Զ�����
		 */
		virtual bool onAutoHide();
		/*
		* ���ط���
		*/
		virtual void onLoad();
		/**
		* �˵��������
		* @param  item   �˵���
         * @param  touchInfo   ������Ϣ
        */
		virtual void onMenuItemClick(FCMenuItem *item, FCTouchInfo touchInfo);
		/**
		* �˵������ƶ�����
		* @param  item   �˵���
         * @param  touchInfo   ������Ϣ
        */
		virtual void onMenuItemTouchMove(FCMenuItem *item, FCTouchInfo touchInfo);
		/**
        * �����������
        * @param  touchInfo   ������Ϣ
        */
		virtual void onTouchDown(FCTouchInfo touchInfo);
		/**
		* �����
		* @param  timerID   ���ID
        */
		virtual void onTimer(int timerID);
		/**
		 * �ɼ�״̬�ı䷽��
		 */
		virtual void onVisibleChanged();
		/**
		* �Ƴ��˵���
		* @param  item   �˵���
        */
		virtual void removeItem(FCMenuItem *item);
		/**
		* ��������ֵ
		* @param  name   ��������
		* @param  value   ����ֵ
		*/
		virtual void setAttribute(const String& name, const String& value);
		/*
		* �ھ���������ʾ
		*/
		virtual bool showOutOfMirror();
	};
}
