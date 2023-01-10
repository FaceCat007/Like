/*
 * FaceCatͼ��ͨѶ���(�ǿ�Դ)
 * ����Ȩ���:2015SR229355+2020SR0266727
 * �Ϻ����è��Ϣ�������޹�˾
 */

#ifdef __FCLINKLABEL_H__
#else                                                                            
#define __FCLINKLABEL_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "FCLabel.h"

namespace FaceCat{
    /**
	 * ��������ͼ��Ϊ
	 */
	enum __FCLINKLABEL_H__ FCLinkBehavior{
	    /**
		 * ������ʾ�»���
		 */
		LinkBehaviorA_AlwaysUnderLine,
		/**
		 * ������ͣʱ��ʾ�»���
		 */
		LinkBehaviorA_HoverUnderLine,
		/**
		 * ���ǲ���ʾ�»���
		 */
		LinkBehaviorA_NeverUnderLine
	};

	class FCLabel;

	/*
	* ���ӱ�ǩ
	*/
	class __FCLINKLABEL_H__ FCLinkLabel : public FCLabel{
	public:
	    /**
		 * ����������ʱ����ɫ
		 */
		Long m_activeLinkColor;
		/**
		 * �����ӱ�����ʱ����ɫ
		 */
		Long m_disabledLinkColor;
		/**
		 * �»��ߵ���ʾ��ʽ
		 */
		FCLinkBehavior m_linkBehavior;
		/**
		 * �����Ӵ���Ĭ��ʱ����ɫ
		 */
		Long m_linkColor;
		/**
		 * �Ƿ����ѷ��ʵ���ʽ��ʾ��������ɫ
		 */
		bool m_linkVisited;
		/**
		 * �Ƿ��ѷ���
		 */
		bool m_visited;
		/**
		 * �ѷ��ʵĳ����ӵ���ɫ
		 */
		Long m_visitedLinkColor;
	public:
	    /**
		 * ��ȡҪ���Ƶĳ�������ɫ
		 */
		virtual Long getPaintingLinkColor();
	public:
		/*
		* ���캯��
		*/
		FCLinkLabel();
		/*
		* ��������
		*/
		virtual ~FCLinkLabel();
		/**
		 * ��ȡ����������ʱ����ɫ
		 */
		virtual Long getActiveLinkColor();
		/**
		 * ���õ���������ʱ����ɫ
		 */
		virtual void setActiveLinkColor(Long value);
		/**
		 * ��ȡ�����ӱ�����ʱ����ɫ
		 */
		virtual Long getDisabledLinkColor();
		/**
		 * ���ó����ӱ�����ʱ����ɫ
		 */
		virtual void setDisabledLinkColor(Long value);
		/**
		 * ��ȡ�»��ߵ���ʾ��ʽ
		 */
		virtual FCLinkBehavior getLinkBehavior();
		/**
		 * �����»��ߵ���ʾ��ʽ
		 */
		virtual void setLinkBehavior(FCLinkBehavior value);
		/**
		 * ��ȡ�����Ӵ���Ĭ��ʱ����ɫ
		 */
		virtual Long getLinkColor();
		/**
		 * ���ó����Ӵ���Ĭ��ʱ����ɫ
		 */
		virtual void setLinkColor(Long value);
		/**
		 * ��ȡ�Ƿ����ѷ��ʵ���ʽ��ʾ��������ɫ
		 */
		virtual bool isLinkVisited();
		/**
		 * �����Ƿ����ѷ��ʵ���ʽ��ʾ��������ɫ
		 */
		virtual void setLinkVisited(bool value);
		/**
		 * ��ȡ�ĳ����ӵ���ɫ
		 */
		virtual Long getVisitedLinkColor();
		/**
		 * ���ʵĳ����ӵ���ɫ
		 */
		virtual void setVisitedLinkColor(Long value);
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
		 * �����������
		 */
		virtual void onClick(FCTouchInfo touchInfo);
		/**
		 * �������·���
		 */
		virtual void onTouchDown(FCTouchInfo touchInfo);
		/**
		 * �������뷽��
		 */
		virtual void onTouchEnter(FCTouchInfo touchInfo);
		/**
		 * �����뿪����
		 */
		virtual void onTouchLeave(FCTouchInfo touchInfo);
		/**
		 * ����̧�𷽷�
		 */
		virtual void onTouchUp(FCTouchInfo touchInfo);
		/**
		 * �ػ�ǰ������
		 */
		virtual void onPaintForeground(FCPaint *paint, const FCRect& clipRect);
		/**
		* ��������
		* @param  name  ��������
		* @param  value  ����ֵ
		*/
		virtual void setAttribute(const String& name, const String& value);
	};
}