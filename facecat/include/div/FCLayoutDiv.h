/*
 * FaceCatͼ��ͨѶ���(�ǿ�Դ)
 * ����Ȩ���:2015SR229355+2020SR0266727
 * �Ϻ����è��Ϣ�������޹�˾
 */

#ifdef __FCLAYOUTDIV_H__
#else                                                                            
#define __FCLAYOUTDIV_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "..\\btn\\FCButton.h"
#include "FCDiv.h"

namespace FaceCat{
	/**
	 * ������ͼ
	 */
	class __FCLAYOUTDIV_H__ FCLayoutDiv : public FCDiv{
	public:
	    /**
		 * �Ƿ��Զ�����
		 */
		bool m_autoWrap;
		/**
		 * ����ģʽ
		 */
		FCLayoutStyle m_layoutStyle;
	public:
		/*
		* ���캯��
		*/
		FCLayoutDiv();
		/*
		* ��������
		*/
		virtual ~FCLayoutDiv();
		/**
		 * ��ȡ�Ƿ��Զ�����
		 */
		virtual bool autoWrap();
		/**
		 * �����Ƿ��Զ�����
		 */
		virtual void setAutoWrap(bool value);
		/**
		 * ��ȡ����ģʽ
		 */
		virtual FCLayoutStyle getLayoutStyle();
		/**
		 * ��������ģʽ
		 */
		virtual void setLayoutStyle(FCLayoutStyle value);
	public:
	    /**
		 * ��ȡ��ͼ����
		 */
		virtual String getViewType();
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
		 * ���ò���
		 */
		virtual bool onResetLayout();
		/**
		* ��������
		* @param  name   ��������
		* @param  value   ��������ֵ
		*/
		virtual void setAttribute(const String& name, const String& value);
		/**
		 * ���ָ��·���
		 */
		virtual void update();
	};
}
