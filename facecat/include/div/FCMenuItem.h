/*
 * FaceCatͼ��ͨѶ���(�ǿ�Դ)
 * ����Ȩ���:2015SR229355+2020SR0266727
 * �Ϻ����è��Ϣ�������޹�˾
 */

#ifdef __FCMENUITEM_H__
#else                                                                            
#define __FCMENUITEM_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "..\\btn\\FCButton.h"
#include "FCMenu.h"

namespace FaceCat{
	class FCMenu;

	/*
	* �˵���
	*/
	class __FCMENUITEM_H__ FCMenuItem : public FCButton{
	public:
	    /**
		 * �Ƿ�ѡ��
		 */
		bool m_checked;
		/**
		 * �������
		 */
		FCMenu *m_dropDownMenu;
		/**
		 * ���˵���
		 */
		FCMenuItem *m_parentItem;
		/**
		 * ���ڲ˵�
		 */
		FCMenu *m_parentMenu;
		/**
		 * ֵ
		 */
		String m_value;
	public:
	    /**
		 * ���в˵���
		 */
		ArrayList<FCMenuItem*> m_items;
		/*
		* ���캯��
		*/
		FCMenuItem();
		/*
		* ���캯��
		*/
		FCMenuItem(const String& value);
		/*
		* ��������
		*/
		virtual ~FCMenuItem();
		/**
		 * ��ȡ�Ƿ�ѡ��
		 */
		bool isChecked();
		/**
		 * �����Ƿ�ѡ��
		 */
		void setChecked(bool value);
		/**
		 * ��ȡ�������
		 */
		FCMenu* getDropDownMenu();
		/**
		 * �����������
		 */
		void setDropDownMenu(FCMenu *value);
		/**
		 * ��ȡ���˵���
		 */
		FCMenuItem* getParentItem();
		/**
		 * ���ø��˵���
		 */
		void setParentItem(FCMenuItem *value);
		/**
		 * ��ȡ�����ڲ˵�
		 */
		FCMenu* getParentMenu();
		/**
		 * �������ڲ˵�
		 */
		void setParentMenu(FCMenu *value);
		/**
		 * ��ȡֵ
		 */
		String getValue();
		/**
		 * ����ֵ
		 */
		void setValue(const String& value);
	public:
		/**
		* ����Ӳ˵���
		* @param  item  �˵���
		*/
		void addItem(FCMenuItem *item);
		/**
		 * ������е���
		 */
		void clearItems();
		/**
		 * ��ȡ��ͼ����
		 */
		virtual String getViewType();
		/**
		 * ��ȡ���е���
		 */
		ArrayList<FCMenuItem*> getItems();
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
		* ������
		* @param  index  ����
		* @param  item  �˵���
		*/
		void insertItem(int index, FCMenuItem *item);
		/**
		* �����
		* @param  index  ������
		*/
		virtual void onAddingItem(int index);
		/**
		* �������
		* @param  touchInfo  ������Ϣ
		*/
		virtual void onClick(FCTouchInfo touchInfo);
		/**
		* �����ƶ�����
		* @param  touchInfo  ������Ϣ
		*/
		virtual void onTouchMove(FCTouchInfo touchInfo);
		/**
		* �ػ�ǰ������
		* @param  paint  ��ͼ����
		* @param  clipRect  �ü�����
		*/
		virtual void onPaintForeground(FCPaint *paint, const FCRect& clipRect);
		/**
		 * �Ƴ����
		 */
		virtual void onRemovingItem();
		/**
		* �Ƴ��Ӳ˵���
		* @param  item   �Ӳ˵���
		*/
		void removeItem(FCMenuItem *item);
		/**
		* ��������
		* @param  name   ������
		* @param  value   ����ֵ
		*/
		virtual void setAttribute(const String& name, const String& value);
	};
}