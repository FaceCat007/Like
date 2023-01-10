/*
 * FaceCatͼ��ͨѶ���(�ǿ�Դ)
 * ����Ȩ���:2015SR229355+2020SR0266727
 * �Ϻ����è��Ϣ�������޹�˾
 */

#ifdef __FCCHECKBOX_H__
#else                                                                            
#define __FCCHECKBOX_H__ _declspec(dllexport) 
#endif

#pragma once
#include "..\\..\\stdafx.h"
#include "..\\core\\FCTran.h"
#include "FCButton.h"

namespace FaceCat{
	/**
     * ��ѡ����ͼ
     */
	class __FCCHECKBOX_H__ FCCheckBox : public FCButton{
	public:
		/**
	     * ��ȡ���������ݵĺ���������ʽ
	     */
		FCHorizontalAlign m_buttonAlign;
		/**
	     * ��ȡ�����ð�ť�ı���ɫ
	     */
		Long m_buttonBackColor;
		/**
	     * ��ȡ�����ð�ť�ı�����ɫ
	     */
		Long m_buttonBorderColor;
		/**
	     * ��ȡ�����ð�ť�ĳߴ�
	     */
		FCSize m_buttonSize;
		/**
	     * ��ȡ�������Ƿ�ѡ��
	     */
		bool m_checked;
		/**
	     * ��ȡ������ѡ��ʱ�ı���ͼ
	     */
		String m_checkedBackImage;
		/**
	     * ��ȡ�����ô�����ͣ��ѡ��ʱ�ı���ͼƬ
	     */
		String m_checkHoveredBackImage;
		/**
	     * ��ȡ�����ô���������ѡ��ʱ�ı���ͼƬ
	     */
		String m_checkPushedBackImage;
		/**
	     * ��ȡ�����ò�����ʱ��ѡ�б���ͼƬ
	     */
		String m_disableCheckedBackImage;
	public:
	    /**
	     * ��ȡ�����õı���ɫ
	     */
		virtual Long getPaintingBackColor();
		/**
	     * ��ȡҪ���Ƶİ�ť�ı���ɫ
	     */
		virtual Long getPaintingButtonBackColor();
		/**
	     * ��ȡҪ���Ƶİ�ť������ɫ
	     */
		virtual Long getPaintingButtonBorderColor();
		/**
	     * ��ȡ���ڻ��Ƶı���ͼƬ
	     */
		virtual String getPaintingBackImage();
	public:
		/*
		* ���캯��
		*/
		FCCheckBox();
		/*
		* ��������
		*/
		virtual ~FCCheckBox();
		/**
	     * ��ȡ���ݵĺ���������ʽ
	     */
		virtual FCHorizontalAlign getButtonAlign();
		/**
	     * �������ݵĺ���������ʽ
	     */
		virtual void setButtonAlign(FCHorizontalAlign value);
		/**
	     * ��ȡ��ť�ı���ɫ
	     */
		virtual Long getButtonBackColor();
		/**
	     * ���ð�ť�ı���ɫ
	     */
		virtual void setButtonBackColor(Long value);
		/**
	     * ��ȡ��ť�ı�����ɫ
	     */
		virtual Long getButtonBorderColor();
		/**
	     * ���ð�ť�ı�����ɫ
	     */
		virtual void setButtonBorderColor(Long value);
		/**
	     * ��ȡ��ť�ĳߴ�
	     */
		virtual FCSize getButtonSize();
		/**
	     * ���ð�ť�ĳߴ�
	     */
		virtual void setButtonSize(FCSize value);
		/**
	     * ��ȡ�Ƿ�ѡ��
	     */
		virtual bool isChecked();
		/**
	     * �����Ƿ�ѡ��
	     */
		virtual void setChecked(bool value);
		/**
	     * ��ȡѡ��ʱ�ı���ͼ
	     */
		virtual String getCheckedBackImage();
		/**
	     * ����ѡ��ʱ�ı���ͼ
	     */
		virtual void setCheckedBackImage(const String& value);
		/**
	     * ��ȡ������ͣ��ѡ��ʱ�ı���ͼƬ
	     */
		virtual String getCheckHoveredBackImage();
		/**
	     * ���ô�����ͣ��ѡ��ʱ�ı���ͼƬ
	     */
		virtual void setCheckHoveredBackImage(const String& value);
		/**
	     * ��ȡ����������ѡ��ʱ�ı���ͼƬ
	     */
		virtual String getCheckPushedBackImage();
		/**
	     * ���ô���������ѡ��ʱ�ı���ͼƬ
	     */
		virtual void setCheckPushedBackImage(const String& value);
		/**
	     * ��ȡ������ʱ��ѡ�б���ͼƬ
	     */
		virtual String getDisableCheckedBackImage();
		/**
	     * ���ò�����ʱ��ѡ�б���ͼƬ
	     */
		virtual void setDisableCheckedBackImage(const String& value);
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
         * ��ȡ�����б�
         */
        virtual ArrayList<String> getEventNames();
		/**
	      * ѡ�иı䷽��
	     */
		virtual void onCheckedChanged();
	    /**
         * �������
         * @param touchInfo ������Ϣ
        */
		virtual void onClick(FCTouchInfo touchInfo);
	    /**
         * �ػ汳������
         * @param paint    ��ͼ����
         * @param clipRect �ü�����
        */
		virtual void onPaintBackground(FCPaint *paint, const FCRect& clipRect);
	    /**
         * �ػ�ѡ�а�ť����
         * @param paint    ��ͼ����
         * @param clipRect �ü�����
        */
		virtual void onPaintCheckButton(FCPaint *paint, const FCRect& clipRect);
	    /**
         * �ػ�ǰ������
         * @param paint    ��ͼ����
         * @param clipRect �ü�����
        */
		virtual void onPaintForeground(FCPaint *paint, const FCRect& clipRect);
		/*
		* ��������
		*/
		virtual void onScaling(double scaleFactorX, double scaleFactorY);
	    /**
         * ��������
         * @param name    ��������
         * @param value   ����ֵ
        */
		virtual void setAttribute(const String& name, const String& value);
	};
}
