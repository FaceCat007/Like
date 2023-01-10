/*
 * FaceCatͼ��ͨѶ���(�ǿ�Դ)
 * ����Ȩ���:2015SR229355+2020SR0266727
 * �Ϻ����è��Ϣ�������޹�˾
 */

#ifdef __FCBUTTON_H__
#else                                                                            
#define __FCBUTTON_H__ _declspec(dllexport) 
#endif

#pragma once
#include "..\\..\\stdafx.h"
#include "..\\core\\FCTran.h"

namespace FaceCat{
	/**
     * ��ť��ͼ
     */
	class __FCBUTTON_H__ FCButton : public FCView{
	public:
		/**
		* ������ʱ�ı���ͼƬ
		*/
		String m_disabledBackImage;
		/**
		* ������ͣʱ�ı���ͼƬ
		*/
		String m_hoveredBackImage;
		/**
		* ��������ʱ�ı���ͼƬ
		*/
		String m_pushedBackImage;
		/**
		* �������з�ʽ
		*/
		FCContentAlignment m_textAlign;
	public:
	    /**
	     * ��ȡҪ���Ƶı���ɫ
	     */
		virtual Long getPaintingBackColor();
		/**
	     * ��ȡ���ڻ��Ƶı���ͼƬ
	     */
		virtual String getPaintingBackImage();
	public:
		/*
		* ���캯��
		*/
		FCButton();
		/*
		* ��������
		*/
		virtual ~FCButton();
		/**
	     * ��ȡ������ʱ�ı���ͼƬ
	     */
		virtual String getDisabledBackImage();
		/**
	     * ���ò�����ʱ�ı���ͼƬ
	     */
		virtual void setDisabledBackImage(const String& value);
		/**
	     * ��ȡ������ͣʱ�ı���ͼƬ
	     */
		virtual String getHoveredBackImage();
		/**
	     * ���ô�����ͣʱ�ı���ͼƬ
	     */
		virtual void setHoveredBackImage(const String& value);
		/**
	     * ��ȡ��������ʱ�ı���ͼƬ
	     */
		virtual String getPushedBackImage();
		/**
	     * ���ô�������ʱ�ı���ͼƬ
	     */
		virtual void setPushedBackImage(const String& value);
		/**
	     * ��ȡ���ֵĲ��ַ�ʽ
	     */
		virtual FCContentAlignment getTextAlign();
		/**
	     * �������ֵĲ��ַ�ʽ
	     */
		virtual void setTextAlign(FCContentAlignment value);
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
         * �������·���
         * @param touchInfo ������Ϣ
         */
		virtual void onTouchDown(FCTouchInfo touchInfo);
	    /**
         * �������뷽��
         * @param touchInfo ������Ϣ
         */
		virtual void onTouchEnter(FCTouchInfo touchInfo);
	    /**
         * �����뿪����
         * @param touchInfo ������Ϣ
         */
		virtual void onTouchLeave(FCTouchInfo touchInfo);
	    /**
         * ����̧�𷽷�
         * @param touchInfo ������Ϣ
         */
		virtual void onTouchUp(FCTouchInfo touchInfo);
	    /**
         * �ػ�ǰ������
         * @param paint    ��ͼ����
         * @param clipRect �ü�����
         */
		virtual void onPaintForeground(FCPaint *paint, const FCRect& clipRect);
	    /**
         * ��������
         * @param name  ��������
         * @param value ����ֵ
         */
		virtual void setAttribute(const String& name, const String& value);
	};
}
