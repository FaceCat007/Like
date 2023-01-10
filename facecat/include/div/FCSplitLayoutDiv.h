/*
 * FaceCatͼ��ͨѶ���(�ǿ�Դ)
 * ����Ȩ���:2015SR229355+2020SR0266727
 * �Ϻ����è��Ϣ�������޹�˾
 */

#ifdef __FCSPLITLAYOUTDIV_H__
#else                                                                            
#define __FCSPLITLAYOUTDIV_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "..\\btn\\FCButton.h"
#include "FCDiv.h"
#include "FCLayoutDiv.h"
#include "FCTableLayoutDiv.h"

namespace FaceCat{
	/*
	* �ָ��
	*/
	class __FCSPLITLAYOUTDIV_H__ FCSplitLayoutDiv : public FCLayoutDiv{
	public:
	    /**
		 * ��һ����ͼ
		 */
		FCView *m_firstView;
		/**
		 * �ڶ�����ͼ
		 */
		FCView *m_secondView;
		/*
		* ��׼�ߴ�
		*/
		FCSize m_datumSize;
		/**
		 * �ָ�ģʽ
		 */
		FCSizeType m_splitMode;
		/**
		 * �ָ�ٷֱ�
		 */
		float m_splitPercent;
		/**
		 * �ָť
		 */
		FCButton *m_splitter;
	public:
		/*
		* ���캯��
		*/
		FCSplitLayoutDiv();
		/*
		* ��������
		*/
		virtual ~FCSplitLayoutDiv();
		/*
		* ��ȡ��׼�ߴ�
		*/
		virtual FCSize getDatumSize();
		/*
		* ���û�׼�ߴ�
		*/
		virtual void setDatumSize(FCSize value);
		/**
		 * ��ȡ��һ����ͼ
		 */
		virtual FCView* getFirstView();
		/**
		 * ���õ�һ����ͼ
		 */
		virtual void setFirstView(FCView *value);
		/**
		 * ��ȡ�ڶ�����ͼ
		 */
		virtual FCView* getSecondView();
		/**
		 * ���õڶ�����ͼ
		 */
		virtual void setSecondView(FCView *value);
		/**
		 * ��ȡ�ָ�ģʽ
		 */
		virtual FCSizeType getSplitMode();
		/**
		 * ���÷ָ�ģʽ
		 */
		virtual void setSplitMode(FCSizeType value);
		/**
		 * ��ȡ�ָť
		 */
		virtual FCButton* getSplitter();
	public:
		/*
		* �����¼�
		*/
		virtual void callEvent(String eventName, Object sender, Object invoke);
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
		 * �����ͼ����
		 */
		virtual void onLoad();
		/**
		 * ���ò���
		 */
		virtual bool onResetLayout();
		/**
		 * ���ָ��·���
		 */
		virtual void update();
		/**
		* ��������
		* @param  name   ��������
		* @param  value   ��������ֵ
		*/
		virtual void setAttribute(const String& name, const String& value);
	};
}
