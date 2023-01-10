/*
 * FaceCatͼ��ͨѶ���(�ǿ�Դ)
 * ����Ȩ���:2015SR229355+2020SR0266727
 * �Ϻ����è��Ϣ�������޹�˾
 */

#ifdef __FCHOST_H__
#else                                                                            
#define __FCHOST_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "FCView.h"
#include "FCTran.h"
#include "FCPaint.h"
#include "GdiPaint.h"
#include "GdiPlusPaint.h"
#include "FCNative.h"

namespace FaceCat{
	class FCView;
	class FCNative;

    /**
     * ��ͼ����
     */
	class __FCHOST_H__ FCHost{
	public:
		/*
		* ���캯��
		*/
		FCHost();
		/*
		* ��������
		*/
		virtual ~FCHost();
		/**
		 * ��ȡ������
		 */
		virtual FCNative* getNative();
		/**
		 * ���÷�����
		 */
		virtual void setNative(FCNative *value);
	public:
		/*
		* �����
		*/
		virtual void activeMirror();
		/**
		 * �Ƿ��������
		 */
		virtual bool allowOperate();
		/**
		 * �Ƿ�����ֲ���ͼ
		 */
		virtual bool allowPartialPaint();
		/**
		 * ����ͼ���߳��е��÷���
		 */
		virtual void beginInvoke(FCView *view, Object args);
		/**
		 * �����ı�
		 */
		virtual void copy(string text);
		/**
		 * �����ڲ���ͼ
		 */
		virtual FCView* createInternalView(FCView *parent, const String& clsid);
		/*
		* ��ȡ�����״
		*/
        virtual FCCursors getCursor();
        /**
         * ��ȡ�����ཻ��
         *
         * @param lpDestRect    �ཻ����
         * @param lpSrc1Rect    ����1
         * @param lpSrc2Rect    ����2
         * @returns �Ƿ��ཻ
         */
		virtual int getIntersectRect(LPRECT lpDestRect, const FCRect *lpSrc1Rect, const FCRect *lpSrc2Rect);
        /**
		 * ��ȡ����λ��
		 */
        virtual FCPoint getTouchPoint();
        /**
		 * ��ȡ�ߴ�
		 */
        virtual FCSize getSize();
		/*
		* ��ȡ����������
		*/
		virtual int getUnionRect(LPRECT lpDestRect, const FCRect *lpSrc1Rect, const FCRect *lpSrc2Rect);
		/**
		 * ˢ�»�ͼ
		 */
		virtual void invalidate();
	    /**
         *  ˢ�»�ͼ
         * @param rect ����
         */
        virtual void invalidate(const FCRect& rect);
        /**
         *  ����ͼ���߳��е��÷���
         * @param view ��ͼ
         * @param args  ����
         */
		virtual void invoke(FCView *view, Object args);
		/*
		* �����Ƿ񱻰���
		*/
		virtual bool isKeyPress(char key);
		/**
		 * ��ȡճ���ı�
		 */
		virtual string paste();
		/**
		 * �����Ƿ��������
		 */
		virtual void setAllowOperate(bool allowOperate);
		/**
		 * �����Ƿ�����ֲ���ͼ
		 */
		virtual void setAllowPartialPaint(bool allowPartialPaint);
		/*
		* ���������״
		*/
        virtual void setCursor(FCCursors cursor);
        /**
         *  ��ʾ��ʾ��
         * @param text  ����
         * @param mp    λ��
         */
		virtual void showToolTip(const String& text, const FCPoint& mp);
		/*
		* ���ô���λ��
		*/
		virtual void setTouchPoint(const POINT& point);
	    /**
         *  �������
         * @param timerID   ���ID
         * @param interval  ���
         */
        virtual void startTimer(int timerID, int interval);
        /**
         *  ֹͣ���
         * @param timerID   ���ID
         */
        virtual void stopTimer(int timerID);
	};
}