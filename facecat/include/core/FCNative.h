/*
 * FaceCatͼ��ͨѶ���(�ǿ�Դ)
 * ����Ȩ���:2015SR229355+2020SR0266727
 * �Ϻ����è��Ϣ�������޹�˾
 */

#ifdef __FCNATIVE_H__
#else                                                                            
#define __FCNATIVE_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "FCView.h"
#include "FCTran.h"
#include "FCPaint.h"
#include "GdiPaint.h"
#include "GdiPlusPaint.h"
#include "FCHost.h"
#include "WinHost.h"

namespace FaceCat{
	enum _declspec(dllexport) SortType{
		SortType_None,
		SortType_Asc,
		SortType_Desc
	};

	class FCView;
	class FCHost;
	class WinHost;
	/*
	* ������
	*/
	class __FCNATIVE_H__ FCNative{
	public:
	    /**
		 * �Ƿ�����ʹ�����ųߴ�
		 */
		bool m_allowScaleSize;
		/*
		* ��ʼ��ͼ�ĵ�
		*/
		FCPoint m_drawBeginPoint;
		/**
		 * �϶���ʼʱ������
		 */
		FCRect m_dragBeginRect;
		/**
		 * ���Կ�ʼ�϶���ƫ��������
		 */
		FCPoint m_dragStartOffset;
		/*
		* Ҫ����ͼƬ����ͼ
		*/
		FCView *m_exportingView;
		/**
		 * ��ͼ������
		 */
		FCHost *m_host;
		/*
		* �Ƿ���������
		*/
		bool m_lockUpdate;
		/*
		* ��������
		*/
		FCNative *m_mirrorHost;
		/*
		* ����ģʽ
		*/
		FCMirrorMode m_mirrorMode;
		/**
		 * ͸����
		 */
		float m_opacity;
		/**
		 * ��ͼ��
		 */
		FCPaint *m_paint;
		/**
		 * ��������ʱ������
		 */
		FCPoint m_touchDownPoint;
		/**
		 * ��Դ�ļ���·��
		 */
		String m_resourcePath;
		/**
		 * ��ת�Ƕ�
		 */
		int m_rotateAngle;
		/**
		 * ʹ�����ųߴ�
		 */
		FCSize m_scaleSize;
		/**
		 * ��ʾ����
		 */
		FCSize m_size;
		/*
		* ���
		*/
		map<int, FCView*> m_timers;
	    /**
         * ���ݴ���λ�û�ȡ��ͼ
         * @param mp    ����
         * @param view ��ͼ
         * @returns ��ͼ����
        */
		FCView* findView(const FCPoint& mp, ArrayList<FCView*> *views);
	    /**
         * �������Ʋ�����ͼ
         * @param name  ����
         * @param views  ��ͼ����
         * @returns ��ͼ
        */
		FCView* findView(const String& name, ArrayList<FCView*> *views);
	    /**
         * ������ͼ����Ԥ�����¼�����ͼ
         * @param view   ��ͼ
         * @returns ��ͼ
        */
		FCView* findPreviewsView(FCView *view);
	    /**
         * ������ͼ���Ҵ���
         * @param view   ��ͼ
         * @returns ����
        */
		FCView* findWindow(FCView *view);
	    /**
         * ��ȡ���Ƶ�͸����
         * @param view   ��ͼ
         * @returns ͸����
        */
		float getPaintingOpacity(FCView *view);
	    /**
         * ��ȡ��������ͼ����
         * @param parent    ����ͼ
         * @param sortedViews   ��������ͼ
         * @returns ״̬
        */
		bool getSortedViews(FCView *parent, ArrayList<FCView*> *sortedViews);
		/*
		* ��ȡ����Tab������ͼ
		*/
		void getTabStopViews(FCView *view, ArrayList<FCView*> *tabStopViews);
	    /**
         * �ж��Ƿ���ƿ���״̬
         * @param view   ��ͼ
         * @returns �Ƿ���ƿ���״̬
        */
		bool isPaintEnabled(FCView *view);
	    /**
         * ������ͼ
         * @param   rect ����
         * @param   views ��ͼ����
         * @param   opacity ͸����
        */
		void renderViews(const FCRect& rect, ArrayList<FCView*> *views, float opacity);
		 /**
         * ������ͼ
         * @param   rect ����
         * @param   views ��ͼ����
         * @param   opacity ͸����
        */
		void renderView(const FCRect& rect, FCView *views, float opacity);
		/*
		* ���ù��
		*/
		void setCursor(FCView *view);
	    /**
         * ���û�ͼ����
         * @param offsetX  ����ƫ��
         * @param offsetY  ����ƫ��
         * @param clipRect  �ü�����
         * @param resourcePath  ��Դ·��
         * @param opacity  ͸����
        */
		void setPaint(int offsetX, int offsetY, const FCRect& clipRect, float opacity);
	public:
	    /**
		 * �����϶�����ͼ
		 */
		FCView *m_draggingView;
		/*
		* �����������ͼ
		*/
		FCView *m_focusedView;
		/**
		 * �����������µ���ͼ
		 */
		FCView *m_touchDownView;
		/**
		 * �����������Ϸ��ƶ�����ͼ
		 */
		FCView *m_touchMoveView;
	public:
	    /**
		 * ��ͼ
		 */
		ArrayList<FCView*> m_views;
		/*
		* ����
		*/
		vector<FCNative*> m_mirrors;
		/*
		* ���캯��
		*/
		FCNative();
		/*
		* ��������
		*/
		virtual ~FCNative();
		/**
		 * ��ȡ�Ƿ�����ʹ�����ųߴ�
		 */
		bool allowScaleSize();
		/**
		 * �����Ƿ�����ʹ�����ųߴ�
		 */
		void setAllowScaleSize(bool value);
		/*
		* ��ȡ������״
		*/
		FCCursors getCursor();
		/*
		* ����������״
		*/
		void setCursor(FCCursors value);
		/**
		 * ��ȡѡ�е���ͼ
		 */
		FCView* getFocusedView();
		/**
		 * ����ѡ�е���ͼ
		 */
		void setFocusedView(FCView *value);
		/**
		 * ��ȡ��ͼ������
		 */
		FCHost* getHost();
		/**
		 * ������ͼ������
		 */
		void setHost(FCHost *value);
		/**
		 * ��ȡ������ͣ����ͼ
		 */
		FCView* getHoveredView();
		/*
		* ��ȡ��������
		*/
		FCNative* getMirrorHost();
		/*
		* ��ȡ����ģʽ
		*/
		FCMirrorMode getMirrorMode();
		/*
		* ���þ���ģʽ
		*/
		void setMirrorMode(FCMirrorMode value);
		/**
		 * ��ȡ������ʵ��λ��
		 */
		FCPoint getTouchPoint();
		/**
		 * ��ȡ͸����
		 */
		float getOpacity();
		/**
		 * ����͸����
		 */
		void setOpacity(float value);
		/**
		 * ���ͼ��
		 */
		FCPaint* getPaint();
		/**
		 * ȡ��ͼ��
		 */
		void setPaint(FCPaint *value);
		/**
		 * ��ȡ������ס����ͼ
		 */
		FCView* getPushedView();
		/**
		 * ��ȡ��Դ�ļ���·��
		 */
		String getResourcePath();
		/**
		 * ������Դ�ļ���·��
		 */
		void setResourcePath(const String& value);
		/**
		 * ��ȡ��ת�Ƕ�
		 */
		int getRotateAngle();
		/**
		 * ������ת�Ƕ�
		 */
		void setRotateAngle(int value);
		/**
		 * ��ȡʹ�����ųߴ�
		 */
		FCSize getScaleSize();
		/**
		 * ����ʹ�����ųߴ�
		 */
		void setScaleSize(FCSize value);
		/**
		 * ��ȡ��ʾ����
		 */
		FCSize getSize();
		/**
		 * ������ʾ����
		 */
		void setSize(FCSize value);
	public:
	    /**
         * �����ͼ
         * @param view ��ͼ
        */
		void addView(FCView *view);
		/*
		* ��Ӿ���
		*/
		void addMirror(FCNative *mirrorHost, FCView *view);
	    /**
         * ����ͼ�ŵ���ǰ��ʾ
         * @param view ��ͼ
        */
		void bringToFront(FCView *view);
		/**
		 * �˳��϶�
		 */
		void cancelDragging();
		/**
		 * ������е���ͼ
		 */
		void clearViews();
	    /**
         * ��ȡ��ͼ�ľ��Ժ�����
         * @param view ��ͼ
        */
		int clientX(FCView *view);
	    /**
         * ��ȡ��ͼ�ľ���������
         * @param view ��ͼ
         * @returns ����
        */
		int clientY(FCView *view);
		/*
         * ��ȡ�ؼ��ľ�������
         */
        virtual FCPoint clientPoint(FCView *view);
	    /**
         * �Ƿ������ͼ
         * @param view ��ͼ
         * @returns �Ƿ����
        */
		bool containsView(FCView *view);
		/*
		* ����ΪͼƬ
		*/
        void exportToImage(const String& exportPath);
		/*
		* ����ΪͼƬ
		*/
        void exportToImage(const String& exportPath, FCView *view);
        /**
         * ���ݴ���λ�û�ȡ��ͼ
         * @param mp    ����
        */
		FCView* findView(const FCPoint& mp);
	    /**
         * ������������ͼ�в�����ͼ
         * @param mp    ����
         * @param parent    ����ͼ
         * @returns ��ͼ
        */
		FCView* findView(const FCPoint& mp, FCView *parent);
	    /**
         * �������Ʋ�����ͼ
         * @param name  ����
         * @returns ��ͼ
        */
		FCView* findView(const String& name);
		/**
		 * ��ȡ��ͼ���ϵĿ���
		 */
		ArrayList<FCView*> getViews();
	    /**
         * ������ͼ
         * @param index ����
         * @param view   ��ͼ
         */
		void insertView(int index, FCView *view);
		/**
		 * ʹ�û������ͼ�󣬲����¼����ͼ�ṹ
		 */
		void invalidate();
	    /**
         * �ֲ���ͼ
         * @param view   ��ͼ
         */
		void invalidate(FCView *view);
	    /**
         * �ֲ���ͼ
         * @param rect  ����
         */
		void invalidate(const FCRect& rect);
		/**
         * ��������
         */
		bool onChar(wchar_t key);
	    /**
         * ˫��
         */
		void onDoubleClick(FCTouchInfo touchInfo);
		/**
         * ���̰���
         */
		void onKeyDown(char key);
		/**
         * ����̧��
         */
		void onKeyUp(char key);
		/**
         * ��������
         */
		void onTouchDown(FCTouchInfo touchInfo);
		/**
         * �����뿪
         */
		void onTouchLeave(FCTouchInfo touchInfo);
	    /**
         * �����ƶ��¼�
         * @param   ouchInfo    ������Ϣ
        */
		void onTouchMove(FCTouchInfo touchInfo);
		/**
         * ����̧��
         */
		void onTouchUp(FCTouchInfo touchInfo);
		/**
         * ��������
         */
		void onTouchWheel(FCTouchInfo touchInfo);
	    /**
         * ��ͼ����
         * @param clipRect  ��������
        */
		void onPaint(const FCRect& rect);
		/*
		* ����Ԥ����
		*/
		bool onPreviewsKeyEvent(String eventName, char key);
		/*
		* ����Ԥ����
		*/
		bool onPreviewsTouchEvent(String eventName, FCView *view, FCTouchInfo touchInfo);
		/**
		 * ����ߴ�ı�
		 */
		void onResize();
		/*
		* ��������
		*/
		virtual void onScaling(double scaleFactorX, double scaleFactorY);
	    /**
         * �������
         * @param   timerID ���ID
        */
		void onTimer(int timerID);
		/**
		 * �Ƴ���ͼ
		 */
		void removeView(FCView *view);
		/*
		* �Ƴ�����
		*/
		void removeMirror(FCView *view);
		/**
		 * ����ͼ�ŵ���������ʾ
		 */
		void sendToBack(FCView *view);
		/**
		 * ��������
		 */
		void setAlign(ArrayList<FCView*> *views);
		/*
		* ����ê����Ϣ
		*/
		void setAnchor(ArrayList<FCView*> *views, FCSize oldSize);
		/*
		* ���ð󶨱�Ե
		*/
		void setDock(ArrayList<FCView*> *views);
	    /**
         * �������
         * @param view  ��ͼ
         * @param timerID  �����
         * @param interval ���
        */
		void startTimer(FCView *view, int timerID, int interval);
		/**
		 * ֹͣ���
		 */
		void stopTimer(int timerID);
		/**
		 * ���²���
		 */
		void update();
	public:
        static void addChangeID();
        static int getChangeID();

	};
}