/*
 * FaceCatͼ��ͨѶ���(�ǿ�Դ)
 * ����Ȩ���:2015SR229355+2020SR0266727
 * �Ϻ����è��Ϣ�������޹�˾
 */

#ifdef __FCTOOLTIP_H__
#else                                                                            
#define __FCTOOLTIP_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "..\\Label\\FCLabel.h"

namespace FaceCat{
	/*
	* ��ʾ��
	*/
	class __FCTOOLTIP_H__ FCToolTip : public FCLabel{
	private:
	    /**
		 * ���ID
		 */
		int m_timerID;
	public:
	    /**
		 * ��ʾ��ʱ�䳤��
		 */
		int m_autoPopDelay;
		/**
		 * ������ֹʱ�ӳ���ʾ�ĺ�����
		 */
		int m_initialDelay;
		/**
		 * ��һ�δ�����λ��
		 */
		FCPoint m_lastTouchPoint;
		/**
		 * �Ƿ�������ʾ
		 */
		bool m_showAlways;
		/**
		 * �Ƿ�����ʾ����ʱʹ�ö���
		 */
		bool m_useAnimation;
	public:
	    /**
		 * ʣ�ౣ����ʾ������
		 */
		int m_remainAutoPopDelay;
		/**
		 * ʣ���ӳ���ʾ������
		 */
		int m_remainInitialDelay;
	public:
		/*
		* ���캯��
		*/
		FCToolTip();
		/*
		* ��������
		*/
		virtual ~FCToolTip();
		/**
		 * ��ʾ��ʾ��ʱ�䳤��
		 */
		virtual int getAutoPopDelay();
		/**
		 * ������ʾ��ʱ�䳤��
		 */
		virtual void setAutoPopDelay(int value);
		/**
		 * ��ȡ������ֹʱ�ӳ���ʾ�ĺ�����
		 */
		virtual int getInitialDelay();
		/**
		 * ���ô�����ֹʱ�ӳ���ʾ�ĺ�����
		 */
		virtual void setInitialDelay(int value);
		/**
		 * ��ȡ�Ƿ�������ʾ
		 */
		virtual bool showAlways();
		/**
		 * �����Ƿ�������ʾ
		 */
		virtual void setShowAlways(bool value);
		/**
		 * ��ȡ�Ƿ�����ʾ����ʱʹ�ö���
		 */
		virtual bool useAnimation();
		/**
		 * �����Ƿ�����ʾ����ʱʹ�ö���
		 */
		virtual void setUseAnimation(bool value);
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
		 * ������ͼ
		 */
		virtual void hide();
		/**
		 * �����ͼ����
		 */
		virtual void onLoad();
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
		 * ��ʾ��ͼ
		 */
		virtual void show();
		/**
		* ��������ֵ
		* @param  name   ��������
		* @param  value   ����ֵ
		*/
		virtual void setAttribute(const String& name, const String& value);
	};
}