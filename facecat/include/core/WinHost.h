/*
 * FaceCatͼ��ͨѶ���(�ǿ�Դ)
 * ����Ȩ���:2015SR229355+2020SR0266727
 * �Ϻ����è��Ϣ�������޹�˾
 */

#ifdef __WINHOST_H__
#else                                                                            
#define __WINHOST_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "FCView.h"
#include "FCTran.h"
#include "FCPaint.h"
#include "GdiPaint.h"
#include "GdiPlusPaint.h"
#include "FCNative.h"
#include "FCHost.h"

namespace FaceCat{
	class FCView;
	class FCNative;

	/*
	* Windows�豸��
	*/
	class __WINHOST_H__ WinHost : public FCHost{
	public:
		CRITICAL_SECTION _csLock;
		/**
		 * �Ƿ���Բ���
		 */
		bool m_allowOperate;
		/**
		 * �Ƿ�֧�־ֲ���ͼ
		 */
		bool m_allowPartialPaint;
		/*
		* ���뷨���
		*/
		HIMC m_hImc;
		/**
		 * ͼ����ͼ
		 */
		HWND m_hWnd;
		/**
		 * ������ͼ�̷߳�������ˮ��
		 */
		int m_invokeSerialID;
		/**
		 * ������ͼ�̷߳����Ĳ���
		 */
		map<int, Object> m_invokeArgs;
		/**
		 * ������ͼ�̷߳�������ͼ
		 */
		map<int, FCView*> m_invokeViews;
		/**
		 * ������
		 */
		FCNative *m_native;
		/**
		 * �����̷߳�������ϢID
		 */
		int m_pInvokeMsgID;
		/**
		 * ��ʾ��
		 */
		FCView *m_toolTip;
		/*
		* ����λ��
		*/
		FCPoint m_touchPoint;
	public:
	    /**
		 * ��ȡ�ͻ��˵Ĵ�С
		 */
		FCSize getClientSize();
	public:
	    /**
		 * ������ͼ����
		 */
		WinHost();
		virtual ~WinHost();
		/**
		 * ��ȡ������ͼ����
		 */
		HWND getHWnd();
		/**
		 * ���ô�����ͼ����
		 */
		void setHWnd(HWND hWnd);
		/*
		* ��ȡ������
		*/
		virtual FCNative* getNative();
		/*
		* ���ÿ�����
		*/
		virtual void setNative(FCNative *value);
		/*
		* ��ȡInvoke����Ϣ��
		*/
		int getPInvokeMsgID();
		/*
		* ����Invoke����Ϣ��
		*/
		void setPInvokeMsgID(int value);
		/*
		* ��ȡ��ʾ��
		*/
		FCView* getToolTip();
		/*
		* ������ʾ��
		*/
		void setToolTip(FCView *value);
	public:
	    /**
		 * �����
		 */
		virtual void activeMirror();
		/**
		 * ��ȡ�������Ƿ��������
		 */
		virtual bool allowOperate();
		/**
		 * ��ȡ�������Ƿ�����ֲ���ͼ
		 */
		virtual bool allowPartialPaint();
		/**
		*����ͼ���߳��е��÷���
		* @param view ��ͼ
		* @param args ����
		*/
		virtual void beginInvoke(FCView *view, Object args);
		/**
		 * �����ı�
		 */
		virtual void copy(string text);
		/**
		*�����ڲ���ͼ
		* @param parent ����ͼ
		* @param clsid ����ID
		*/
		virtual FCView* createInternalView(FCView *parent, const String& clsid);
		/**
		 * ��ȡ�����·��
		 */
		static string getAppPath();
		/**
		 * ȡ����
		 */
		virtual FCCursors getCursor();
		/**
		*��ȡ�����ཻ��
		* @param lpDestRect �ཻ����
		* @param lpSrc1Rect ����1
		* @param lpSrc2Rect ����2
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
		/**
		*��ȡ���β�����
		* @param lpDestRect ��������
		* @param lpSrc1Rect ����1
		* @param lpSrc2Rect ����2
		*/
		virtual int getUnionRect(LPRECT lpDestRect, const FCRect *lpSrc1Rect, const FCRect *lpSrc2Rect);
		/*
		* ��
		*/
		void lock();
		/**
		 * ˢ�»�ͼ
		 */
		virtual void invalidate();
		/**
		* ˢ�»�ͼ
		* @param rect  ����
		*/
        virtual void invalidate(const FCRect& rect);
		/**
		* ����ͼ���߳��е��÷���
		* @param view   ��ͼ
		* @param args      ����
		*/
		virtual void invoke(FCView *view, Object args);
		/**
		* ��ȡ������״̬
		* @param key   ����
		*/
		virtual bool isKeyPress(char key);
		/**
		* ������ͼ�̵߳ķ���
		* @param invokeSerialID   ��ϢID
		*/
		void onInvoke(int invokeSerialID);
		/**
		* ��Ϣ����
		* @param m  ��Ϣ
		*/
		int onMessage(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
		/**
		* �ػ淽��
		* @param clipRect  �ü�����
		*/
		void onPaint(HDC hDC, const FCRect& rect);
		/**
		 * ��ȡճ���ı�
		 */
		virtual string paste();
		/*
		* �����Ƿ��������
		*/
		virtual void setAllowOperate(bool allowOperate);
		/*
		* �����Ƿ�����ֲ���ͼ
		*/
		virtual void setAllowPartialPaint(bool allowPartialPaint);
		/**
		* ���ù��
		* @param cursor  ���
		*/
        virtual void setCursor(FCCursors cursor);
		/**
		* ��ʾ��ʾ��
		* @param text  ����
		* @param mp  λ��
		*/
		virtual void showToolTip(const String& text, const FCPoint& mp);
		/*
		* ���ô���λ��
		*/
		virtual void setTouchPoint(const POINT& point);
		/**
		* �������
		* @param timerID  ���ID
		* @param interval  ���
		*/
        virtual void startTimer(int timerID, int interval);
		/**
		* ֹͣ���
		* @param timerID  ���ID
		*/
        virtual void stopTimer(int timerID);
		/*
		* ����
		*/
		void unLock();
	};
}