/*
 * FaceCatͼ��ͨѶ���(�ǿ�Դ)
 * ����Ȩ���:2015SR229355+2020SR0266727
 * �Ϻ����è��Ϣ�������޹�˾
 */

#ifdef __FCRADIOBUTTON_H__
#else                                                                            
#define __FCRADIOBUTTON_H__ _declspec(dllexport) 
#endif

#pragma once
#include "..\\..\\stdafx.h"
#include "..\\core\\FCTran.h"
#include "FCCheckBox.h"

namespace FaceCat{
    /**
     * ��ѡ����ͼ
     */
	class __FCRADIOBUTTON_H__ FCRadioButton:public FCCheckBox{
	public:
		/*
		* ������
		*/
		String m_groupName;
	public:
		/*
		* ���캯��
		*/
		FCRadioButton();
		/*
		* ��������
		*/
		virtual ~FCRadioButton();
		/**
	     * ��ȡ����
	     */
		virtual String getGroupName();
		/**
	     * ��������
	     */
		virtual void setGroupName(const String& value);
	public:
	    /**
	     * ��ȡ��ͼ����
	     */
		virtual String getViewType();
	    /**
         * ��ȡ����ֵ
         * @param name  ��������
         * @param value ��������ֵ
         * @param type  ������������
        */
		virtual void getAttribute(const String& name, String *value, String *type);
		/**
	     * ��ȡ���������б�
	     */
		virtual ArrayList<String> getAttributeNames();
		/**
	     * �������
	     */
		virtual void onClick(FCTouchInfo touchInfo);
	    /**
         * �ػ�ѡ�а�ť����
         * @param paint    ��ͼ����
         * @param clipRect �ü�����
        */
		virtual void onPaintCheckButton(FCPaint *paint, const FCRect& clipRect);
	    /**
         * ��������
         * @param name    ��������
         * @param value   ����ֵ
        */
		virtual void setAttribute(const String& name, const String& value);
		/**
	     * ���²��ַ���
	     */
		virtual void update();
	};
}

