/*
 * FaceCatͼ��ͨѶ���(�ǿ�Դ)
 * ����Ȩ���:2015SR229355+2020SR0266727
 * �Ϻ����è��Ϣ�������޹�˾
 */

#ifdef __FCLABEL_H__
#else                                                                            
#define __FCLABEL_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"

namespace FaceCat{
	/*
	* ��ǩ
	*/
	class __FCLABEL_H__ FCLabel : public FCView{
	public:
		FCContentAlignment m_textAlign;
	public:
		/*
		* ���캯��
		*/ 
		FCLabel();
		/*
		* ��������
		*/
		virtual ~FCLabel();
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
		 * �ػ�ǰ������
		 */
		virtual void onPaintForeground(FCPaint *paint, const FCRect& clipRect);
		/*
		* Ԥ��ͼ����
		*/
		virtual bool onPrePaint(FCPaint *paint, const FCRect& clipRect);
		/**
		* ��������
		* @param  name  ��������
		* @param  value  ����ֵ
		*/
		virtual void setAttribute(const String& name, const String& value);
	};
}