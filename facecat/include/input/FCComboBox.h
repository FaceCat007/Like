/*
 * FaceCatͼ��ͨѶ���(�ǿ�Դ)
 * ����Ȩ���:2015SR229355+2020SR0266727
 * �Ϻ����è��Ϣ�������޹�˾
 */

#ifdef __FCCOMBOBOX_H__
#else                                                                            
#define __FCCOMBOBOX_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "FCTextBox.h"
#include "..\\btn\\FCButton.h"
#include "..\\div\\FCMenu.h"
#include "..\\div\\FCMenuItem.h"

namespace FaceCat{
	class FCComboBox;

	/*
	* �����б�Ĳ˵�
	*/
	class __FCCOMBOBOX_H__ FCComboBoxMenu : public FCMenu{
	public:
	    /**
		 * �б���ͼ
		 */
		FCComboBox *m_comboBox;
	public:
		/*
		* ���캯��
		*/
		FCComboBoxMenu();
		/*
		* ��������
		*/
		virtual ~FCComboBoxMenu();
		/**
		 * ��ȡ�б���ͼ
		 */
		FCComboBox* getComboBox();
		/**
		 * �����б���ͼ
		 */
		void setComboBox(FCComboBox *value);
		/**
		 * �Ƿ��Զ�����
		 */
		virtual bool onAutoHide();
	};

	/*
	* �����б�
	*/
	class __FCCOMBOBOX_H__ FCComboBox : public FCTextBox, public FCMenuItemTouchEventCallBack{
	public:
		/*
		* ������ť
		*/
		FCButton* m_dropDownButton;
		/*
		* �����˵�
		*/
		FCComboBoxMenu* m_dropDownMenu;
	public:
		/*
		* ���캯��
		*/
		FCComboBox();
		/*
		* ��������
		*/
		virtual ~FCComboBox();
		/**
		 * ��ȡ������ť
		 */
		virtual FCButton* getDropDownButton();
		/**
		 * ��ȡ�����˵�
		 */
		virtual FCComboBoxMenu* getDropDownMenu();
		/**
		 * ��ȡѡ�е�����
		 */
		virtual int getSelectedIndex();
		/**
		 * ����ѡ�е�����
		 */
		virtual void setSelectedIndex(int value);
		/**
		 * ��ȡѡ�е�����
		 */
		virtual String getSelectedText();
		/**
		 * ����ѡ�е�����
		 */
		virtual void setSelectedText(const String& value);
		/**
		 * ��ȡѡ�е�ֵ
		 */
		virtual String getSelectedValue();
		/**
		 * ����ѡ�е�ֵ
		 */
		virtual void setSelectedValue(const String& value);
	public:
	    /**
		 * ��Ӳ˵���
		 */
		void addItem(FCMenuItem *item);
		/*
		* �����¼�
		*/
		virtual void callTouchEvent(String eventName, Object sender, FCTouchInfo touchInfo, Object invoke);
		/*
		* �����˵����¼�
		*/
		virtual void callMenuItemTouchEvent(String eventName, Object sender, FCMenuItem *item, FCTouchInfo touchInfo, Object invoke);
		/*
		* ���ü����¼�
		*/
		virtual void callKeyEvent(String eventName, Object sender, char key, Object invoke);
		/**
		 * ������в˵���
		 */
		void clearItems();
		/**
		 * ��ȡ��ͼ����
		 */
		virtual String getViewType();
		/**
         * ��ȡ�����б�
         */
        virtual ArrayList<String> getEventNames();
		/**
		 * ��ȡ�˵���
		 */
		ArrayList<FCMenuItem*> getItems();
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
		 * ����˵���
		 */
		virtual void insertItem(int index, FCMenuItem *item);
		/**
		 * �˵���������
		 */
		virtual void onDropDownOpening();
		/**
		 * ���̰��·���
		 */
		virtual void onKeyDown(char key);
		/**
		 * �����ͼ����
		 */
		virtual void onLoad();
		/**
		 * ѡ�������ı䷽��
		 */
		virtual void onSelectedIndexChanged();
		/**
		 * �������ַ���
		 */
		virtual void onTouchWheel(FCTouchInfo touchInfo);
		/**
		 * �Ƴ��˵���
		 */
		virtual void removeItem(FCMenuItem *item);
		/**
		* ��������
		* @param  name  ��������
		* @param  value  ����ֵ
		*/
		virtual void setAttribute(const String& name, const String& value);
		/**
		 * ���²��ַ���
		 */
		virtual void update();
	};
}