/*
 * FaceCatͼ��ͨѶ���(�ǿ�Դ)
 * ����Ȩ���:2015SR229355+2020SR0266727
 * �Ϻ����è��Ϣ�������޹�˾
 */
#ifdef __FCVIEW_H__
#else                                                                            
#define __FCVIEW_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "FCNative.h"
#include "FCPaint.h"
#include "FCTran.h"
#include "FCAttribute.h"
#include "FCHost.h"

namespace FaceCat{
	static int timerID = 0;
	class FCNative;
	class FCView;

	/*
	* ��ͼ�¼�
	*/
    class __FCVIEW_H__ FCEventCallBack{
	public:
		FCEventCallBack(){}
		virtual ~FCEventCallBack(){}
		virtual void callEvent(String eventName, Object sender, Object invoke){}
    };

    /*
	* ���߳��е��÷����¼�
	*/
    class __FCVIEW_H__ FCInvokeEventCallBack {
	public:
		FCInvokeEventCallBack(){}
		virtual ~FCInvokeEventCallBack(){}
        virtual void callInvokeEvent(String eventName, Object sender, Object args, Object invoke){}
    };

    /*
	* �����¼�
	*/
    class __FCVIEW_H__ FCKeyEventCallBack {
	public:
		FCKeyEventCallBack(){}
		virtual ~FCKeyEventCallBack(){}
        virtual void callKeyEvent(String eventName, Object sender, char key, Object invoke){}
    };
    
    /*
	* Ԥ�����¼�
	*/
    class __FCVIEW_H__ FCPreviewsKeyEventCallBack {
	public:
		FCPreviewsKeyEventCallBack(){}
		virtual ~FCPreviewsKeyEventCallBack(){}
        virtual bool callPreviewsKeyEvent(String eventName, String tEventID, Object sender, char key, Object invoke){return false;}
    };

    /*
	* ��ͼ�����¼�
	*/
    class __FCVIEW_H__ FCTouchEventCallBack {
	public:
		FCTouchEventCallBack(){}
		virtual ~FCTouchEventCallBack(){}
        virtual void callTouchEvent(String eventName, Object sender, FCTouchInfo touchInfo, Object invoke){}
    };

    /*
	* ��ͼԤ�����¼�
	*/ 
    class __FCVIEW_H__ FCPreviewsTouchEventCallBack {
	public:
		FCPreviewsTouchEventCallBack(){}
		virtual ~FCPreviewsTouchEventCallBack(){}
        virtual bool callPreviewsTouchEvent(String eventName, String tEventID, Object sender, FCTouchInfo touchInfo, Object invoke){return false;}
    };

    /*
	* ��ͼ�ػ��¼�
	*/
    class __FCVIEW_H__ FCPaintEventCallBack {
	public:
		FCPaintEventCallBack(){}
		virtual ~FCPaintEventCallBack(){}
        virtual bool callPaintEvent(String eventName, Object sender, FCPaint *paint, const FCRect& clipRect, Object invoke){return false;}
    };

	/*
	* ����¼�
	*/
	class __FCVIEW_H__ FCTimerEventCallBack{
	public:
		FCTimerEventCallBack(){}
		virtual ~FCTimerEventCallBack(){}
		virtual void callTimerEvent(String eventName, Object sender, int timerID, Object invoke){}
	};

	#define FCEventID_Add L"onadd";
    #define FCEventID_AutoSizeChanged L"onautosizechanged"
    #define FCEventID_BackColorChanged L"onbackcolorchanged" 
    #define FCEventID_BackImageChanged L"onbackimagechanged" 
    #define FCEventID_Char L"onchar" 
    #define FCEventID_Click L"onclick" 
    #define FCEventID_Copy L"oncopy" 
    #define FCEventID_Cut L"oncut" 
    #define FCEventID_DockChanged L"ondockchanged" 
    #define FCEventID_DoubleClick L"ondoubleclick" 
    #define FCEventID_DragBegin L"ondragbegin" 
    #define FCEventID_DragEnd L"ondragend" 
    #define FCEventID_Dragging L"ondragging" 
    #define FCEventID_EnableChanged L"onenablechanged" 
    #define FCEventID_FontChanged L"onfontchanged" 
    #define FCEventID_TextColorChanged L"ontextcolorchanged" 
    #define FCEventID_GotFocus L"ongotfocus" 
    #define FCEventID_Invoke L"oninvoke" 
    #define FCEventID_KeyDown L"onkeydown" 
    #define FCEventID_KeyUp L"onkeyup" 
    #define FCEventID_Load L"onload" 
    #define FCEventID_LocationChanged L"onlocationchanged" 
    #define FCEventID_LostFocus L"onlostfocus" 
    #define FCEventID_MarginChanged L"onmarginchanged" 
    #define FCEventID_TouchDown L"ontouchdown" 
    #define FCEventID_TouchEnter L"ontouchenter" 
    #define FCEventID_TouchLeave L"ontouchleave" 
    #define FCEventID_TouchMove L"ontouchmove" 
    #define FCEventID_TouchUp L"ontouchup" 
    #define FCEventID_TouchWheel L"ontouchwheel" 
    #define FCEventID_PaddingChanged L"onpaddingchanged" 
    #define FCEventID_ParentChanged L"onparentchanged" 
    #define FCEventID_Paint L"onpaint" 
    #define FCEventID_PaintBorder L"onpaintborder" 
    #define FCEventID_Paste L"onpaste" 
    #define FCEventID_RegionChanged L"onregionchanged" 
    #define FCEventID_Remove L"onremove" 
    #define FCEventID_SizeChanged L"onsizechanged" 
    #define FCEventID_TabStop L"ontabstop" 
    #define FCEventID_TabStopChanged L"ontabstopchanged" 
    #define FCEventID_TextChanged L"ontextchanged" 
    #define FCEventID_Timer L"ontimer" 
    #define FCEventID_VisibleChanged L"onvisiblechanged" 
    #define FCEventID_CheckedChanged L"oncheckedchanged" 
    #define FCEventID_SelectedTimeChanged L"onselectedtimechanged" 
    #define FCEventID_GridCellClick L"ongridcellclick" 
    #define FCEventID_GridCellEditBegin L"ongridcelleditbegin" 
    #define FCEventID_GridCellEditEnd L"ongridcelleditend" 
    #define FCEventID_GridCellTouchDown L"ongridcelltouchdown" 
    #define FCEventID_GridCellTouchEnter L"ongridcelltouchenter" 
    #define FCEventID_GridCellTouchLeave L"ongridcelltouchleave" 
    #define FCEventID_GridCellTouchMove L"ongridcelltouchmove" 
    #define FCEventID_GridCellTouchUp L"ongridcelltouchup" 
	#define FCEventID_GridRowDraged L"ongridrowdraged"
    #define FCEventID_GridSelectedCellsChanged L"ongridselectedcellschanged" 
    #define FCEventID_GridSelectedColumnsChanged L"ongridselectedcolumnschanged" 
    #define FCEventID_GridSelectedRowsChanged L"ongridselectedrowschanged" 
    #define FCEventID_MenuItemClick L"onmenuitemclick" 
    #define FCEventID_SelectedIndexChanged L"onselectedindexchanged" 
    #define FCEventID_SelectedTabPageChanged L"onselectedtabpagechanged" 
    #define FCEventID_Scrolled L"onscrolled" 
    #define FCEventID_ValueChanged L"onvaluechanged" 
    #define FCEventID_WindowClosed L"onwindowclosed" 
    #define FCEventID_WindowClosing L"onwindowclosing" 
    #define FCEventID_PreviewsKeyEvent L"onpreviewskeyevent" 
    #define FCEventID_PreviewsTouchEvent L"onpreviewstouchevent" 

	class __FCVIEW_H__ FCAtrEx{
    public:
        FCAtrEx();
        virtual ~FCAtrEx();
    public:
        /**
         * ê����Ϣ
         */
        FCAnchor m_anchor;
        /**
         * ��߾�
         */
        FCPadding m_margin;
        /**
         * �ؼ������ߴ�
         */
        FCSize m_maximumSize;
        /**
         * �ؼ�����С�ߴ�
         */
        FCSize m_minimumSize;
        /**
         * �ٷֱ�λ��
         */
        FCPointF *m_percentLocation;
        /**
         * �ٷֱȳߴ�
         */
        FCSizeF *m_percentSize;
        /*
         * ����
         */
        FCRect m_region;
        /**
         * �Ƿ����òü�
         */
        bool m_useRegion;
        /**
         * �¼�����
         */
        map<String, vector<Object>*> m_events;
        /*
         * �����߼���
         */
        map<String, vector<Object>*> m_invokes;
        /**
         * �ڱ߾�
         */
        FCPadding m_padding;
		 /**
         * �Ƿ�����϶�λ��
         */
        bool m_allowDrag;
        /**
         * �Ƿ�����Ԥ�����¼�
         */
        bool m_allowPreviewsEvent;
        /**
         * �Ƿ������ֳ�����Χʱ�ڽ�β��ʾʡ�Ժ�
         */
        bool m_autoEllipsis;
        /**
         * �Ƿ��Զ������ߴ�
         */
        bool m_autoSize;
        /**
         * Բ�ǽǶ�
         */
        int m_cornerRadius;
        /*
         * �����״
         */
        FCCursors m_cursor;
        /**
         * �Ƿ�����ƫ����ʾ
         */
        bool m_displayOffset;
        /**
         * �������Ƿ������϶�
         */
        bool m_isDragging;
        /**
         * �Ƿ�Ϊ����
         */
        bool m_isWindow;
        /*
         * Tab����
         */
        int m_tabIndex;
        /*
         * �Ƿ�֧��Tab
         */
        bool m_tabStop;
        /**
         * TAGֵ
         */
        Object m_tag;
        /**
         * ����ͼƬ
         */
        String m_backImage;
        /**
         * �󶨱�Ե����
         */
        FCDockStyle m_dock;
		/*
         * �Ƿ������ý���
         */
        bool m_canFocus;
    };

	/*
	* ��ͼ�Ļ���
	*/
	class __FCVIEW_H__ FCView : public FCAttribute{
	public:
		FCAtrEx *m_atrEx;
	    /**
		 * �������з�ʽ
		 */
		FCHorizontalAlign m_align;
		/**
		 * ����ɫ
		 */
		Long m_backColor;
		/**
		 * ���ߵ���ɫ
		 */
		Long m_borderColor;
		/**
		 * ��ͼ�Ƿ����
		 */
		bool m_enabled;
		/**
		 * ����
		 */
		FCFont *m_font;
		/**
		 * ��ͼ��λ��
		 */
		FCPoint m_location;
		/**
		 * ��ͼ��Ψһ��ʶ����
		 */
		String m_name;
		/**
		 * ��ť���ڵ�ͼ�νӿ�
		 */
		FCNative *m_native;
		/**
		 * �ϴγߴ�
		 */
		FCSize m_oldSize;
		/**
		 * ͸����
		 */
		float m_opacity;
		/**
		 * ����ͼ
		 */
		FCView *m_parent;
		/**
		 * �ߴ�
		 */
		FCSize m_size;
		/**
		 * ����
		 */
		String m_text;
		/**
		 * ǰ��ɫ
		 */
		Long m_textColor;
		/**
		 * �Ƿ��ö���ʾ
		 */
		bool m_topMost;
		/**
		 * �������з�ʽ
		 */
		FCVerticalAlign m_verticalAlign;
		/**
		 * ��ͼ�Ƿ�ɼ�
		 */
		bool m_visible;
	public:
	    /**
         * �����¼�
         * @param eventName  �¼�ID
        */
		void callEvents(String eventName);
	    /**
         * ������ͼ�̷߳����¼�
         * @param eventName  �¼�ID
         * @param args     ����
        */
		void callInvokeEvents(String eventName, Object args);
		void callKeyEvents(String eventName, char key);
	    /**
         * ���ü����¼�
         * @param eventName  �¼�ID
         * @param key      ����
        */
		void callTouchEvents(String eventName, FCTouchInfo touchInfo);
	    /**
         * �����ػ��¼�
         * @param eventName  �¼�ID
         * @param paint    ��ͼ����
         * @param clipRect �ü�����
        */
		bool callPaintEvents(String eventName, FCPaint *paint, const FCRect& clipRect);
		/*
		* ����Ԥ�����¼�
		*/
		bool callPreviewsKeyEvent(String eventName, String tEventID, char key);
	    /**
         * �����ػ��¼�
         * @param eventName  �¼�ID
         * @param tEventID �¼�ID2
         * @param touchInfo   ������Ϣ
        */
		bool callPreviewsTouchEvent(String eventName, String tEventID, FCTouchInfo touchInfo);
	    /**
         * ��������¼�
         * @param eventName  �¼�ID
         * @param timerID  �����
        */
		void callTimerEvents(String eventName, int timerID);
	    /**
         * ��ȡ�����õı���ɫ
         * @returns ����ɫ
        */
        virtual Long getPaintingBackColor();
        /**
         * ��ȡҪ���Ƶı���ͼƬ
         * @returns ����ͼƬ
        */
        virtual String getPaintingBackImage();
        /**
         * ��ȡҪ���Ƶı�����ɫ
         * @returns ������ɫ
        */
        virtual Long getPaintingBorderColor();
        /**
         * ��ȡҪ���Ƶ�ǰ��ɫ
         * @returns ǰ��ɫ
        */
        virtual Long getPaintingTextColor();
	public:
		/*
		* ������ͼ
		*/
		ArrayList<FCView*> m_views;
		/*
		* ���캯��
		*/
		FCView();
		/*
		* ��������
		*/
		virtual ~FCView();
		/**
		 * ��ȡ�������з�ʽ
		 */
		virtual FCHorizontalAlign getAlign();
		/**
		 * ���ú������з�ʽ
		 */
		virtual void setAlign(FCHorizontalAlign value);
		/**
		 * ��ȡ�Ƿ�����϶�λ��
		 */
		virtual bool allowDrag();
		/**
		 * �����Ƿ�����϶�λ��
		 */
		virtual void setAllowDrag(bool value);
		/**
		 * ��ȡ�Ƿ�����Ԥ�����¼�
		 */
		virtual bool allowPreviewsEvent();
		/**
		 * �����Ƿ�����Ԥ�����¼�
		 */
		virtual void setAllowPreviewsEvent(bool value);
		/**
		 * ��ȡê����Ϣ
		 */
		virtual FCAnchor getAnchor();
		/**
		 * ����ê����Ϣ
		 */
		virtual void setAnchor(const FCAnchor& value);
		/**
		 * ��ȡ�Ƿ������ֳ�����Χʱ�ڽ�β��ʾʡ�Ժ�
		 */
		virtual bool autoEllipsis();
		/**
		 * �����Ƿ������ֳ�����Χʱ�ڽ�β��ʾʡ�Ժ�
		 */
		virtual void setAutoEllipsis(bool value);
		/**
		 * ��ȡ�Ƿ��Զ������ߴ�
		 */
		virtual bool autoSize();
		/**
		 * �����Ƿ��Զ������ߴ�
		 */
		virtual void setAutoSize(bool value);
		/**
		 * ��ȡ����ɫ
		 */
		virtual Long getBackColor();
		/**
		 * ���ñ���ɫ
		 */
		virtual void setBackColor(Long value);
		/**
		 * ��ȡ����ͼƬ
		 */
		virtual String getBackImage();
		/**
		 * ���ñ���ͼƬ
		 */
		virtual void setBackImage(const String& value);
		/**
		 * ��ȡ���ߵ���ɫ
		 */
		virtual Long getBorderColor();
		/**
		 * ���ñ��ߵ���ɫ
		 */
		virtual void setBorderColor(Long value);
		/**
		 * ��ȡ�����²��λ��
		 */
		virtual int getBottom();
		/**
		 * ��ȡ��ͼ����������
		 */
		virtual FCRect getBounds();
		/**
		 * ������ͼ����������
		 */
		virtual void setBounds(const FCRect& value);
		/**
         * ���ÿؼ�����������
         */
        virtual void setBounds2(const FCRect& value);
		/*
         * ��ȡ�Ƿ��ý���
         */
        virtual bool canFocus();
        /*
         * �����Ƿ������ý���
         */
        virtual void setCanFocus(bool value);
		/**
		 * ��ȡ�Ƿ񱻴�������
		 */
		virtual bool isCapture();
		/**
		 * ��ȡԲ�ǽǶ�
		 */
		virtual int getCornerRadius();
		/**
		 * ����Բ�ǽǶ�
		 */
		virtual void setCornerRadius(int value);
		/*
		* ��ȡ�����״
		*/
		virtual FCCursors getCursor();
		/*
		* ���������״
		*/
		virtual void setCursor(FCCursors value);
		/**
		 * ��ȡ�Ƿ�����ƫ����ʾ
		 */
		virtual bool displayOffset();
		/**
		 * �����Ƿ�����ƫ����ʾ
		 */
		virtual void setDisplayOffset(bool value);
		/**
		 * ��ȡ������ʾ������
		 */
		virtual FCRect getDisplayRect();
		/**
		 * ��ȡ�󶨱�Ե����
		 */
		virtual FCDockStyle getDock();
		/**
		 * ���ð󶨱�Ե����
		 */
		virtual void setDock(FCDockStyle value);
		/**
		 * ��ȡ��ͼ�Ƿ����
		 */
		virtual bool isEnabled();
		/**
		 * ������ͼ�Ƿ����
		 */
		virtual void setEnabled(bool value);
		/**
		 * ��ȡ�Ƿ���н���
		 */
		virtual bool isFocused();
		/**
		 * �����Ƿ���н���
		 */
		virtual void setFocused(bool value);
		/**
		 * ��ȡ����
		 */
		virtual FCFont* getFont();
		/**
		 * ��������
		 */
		virtual void setFont(FCFont *value);
		/**
		 * ��ȡ��ͼ�ĸ߶�
		 */
		virtual int getHeight();
		/**
		 * ������ͼ�ĸ߶�
		 */
		virtual void setHeight(int value);
		/**
		 * ��ȡ�������Ƿ������϶�
		 */
		virtual bool isDragging();
		/**
		 * ��ȡ�Ƿ�Ϊ����
		 */
		virtual bool isWindow();
		/**
		 * �����Ƿ�Ϊ����
		 */
		virtual void setWindow(bool value);
		/**
		 * ��ȡ��������λ��
		 */
		virtual int getLeft();
		/**
		 * ���þ�������λ��
		 */
		virtual void setLeft(int value);
		/**
		 * ��ȡ��ͼ��λ��
		 */
		virtual FCPoint getLocation();
		/**
		 * ������ͼ��λ��
		 */
		virtual void setLocation(const FCPoint& value);
		/**
		 * ��ȡ��߾�
		 */
		virtual FCPadding getMargin();
		/**
		 * ������߾�
		 */
		virtual void setMargin(const FCPadding& value);
		/**
		 * ��ȡ��ͼ�����ߴ�
		 */
		virtual FCSize getMaximumSize();
		/**
		 * ������ͼ�����ߴ�
		 */
		virtual void setMaximumSize(FCSize value);
		/**
		 * ��ȡ��ͼ����С�ߴ�
		 */
		virtual FCSize getMinimumSize();
		/**
		 * ������ͼ����С�ߴ�
		 */
		virtual void setMinimumSize(FCSize value);
		/*
		* ��ȡ�����ĵ�
		*/
		virtual FCPoint getTouchPoint();
		/*
		* ��ȡ����
		*/
		virtual String getName();
		/*
		* ��������
		*/
		virtual void setName(const String& value);
		/**
		 * ��ȡ������
		 */
		virtual FCNative* getNative();
		/*
		* ���ÿ�����
		*/
		void setNative(FCNative *value);
		/**
		 * ��ȡ͸����
		 */
		virtual float getOpacity();
		/**
		 * ����͸����
		 */
		virtual void setOpacity(float value);
		/**
		 * ��ȡ�ڱ߾�
		 */
		virtual FCPadding getPadding();
		/**
		 * �����ڱ߾�
		 */
		virtual void setPadding(const FCPadding& value);
		/**
		 * ��ȡ����ͼ
		 */
		virtual FCView* getParent();
		/**
		 * ���ø���ͼ
		 */
		virtual void setParent(FCView *value);
		/**
		 * ��ȡ�ü�����
		 */
		virtual FCRect getRegion();
		/**
		 * ���òü�����
		 */
		virtual void setRegion(const FCRect& value);
		/**
		 * ��ȡ�����Ҳ�ľ���
		 */
		virtual int getRight();
		/**
		 * ��ȡ�ߴ�
		 */
		virtual FCSize getSize();
		/**
		 * ���óߴ�
		 */
		virtual void setSize(const FCSize& value);
		/*
		* ��ȡTab����
		*/
		virtual int getTabIndex();
		/*
		* ����Tab����
		*/
		virtual void setTabIndex(int value);
		/*
		* �Ƿ�֧��Tab��
		*/
		virtual bool isTabStop();
		/*
		* �����Ƿ�֧��Tab��
		*/
		virtual void setTabStop(bool value);
		/**
		 * ��ȡTAGֵ
		 */
		virtual Object getTag();
		/**
		 * ����TAGֵ
		 */
		virtual void setTag(Object value);
		/**
		 * ��ȡ����
		 */
		virtual String getText();
		/**
		 * ��������
		 */
		virtual void setText(const String& value);
		/**
		 * ��ȡǰ��ɫ
		 */
		virtual Long getTextColor();
		/**
		 * ����ǰ��ɫ
		 */
		virtual void setTextColor(Long value);
		/**
		 * ��ȡ�����ϲ��λ��
		 */
		virtual int getTop();
		/**
		 * ���þ����ϲ��λ��
		 */
		virtual void setTop(int value);
		/**
		 * ��ȡ�Ƿ��ö���ʾ
		 */
		virtual bool isTopMost();
		/**
		 * ��ȡ�Ƿ��ö���ʾ
		 */
		virtual void setTopMost(bool value);
		/**
		 * ��ȡ�������Ƿ����òü�
		 */
		virtual bool useRegion();
		/**
		 * ��ȡ�������з�ʽ
		 */
		virtual FCVerticalAlign getVerticalAlign();
		/**
		 * �����������з�ʽ
		 */
		virtual void setVerticalAlign(FCVerticalAlign value);
		/**
		 * ��ȡ��ͼ�Ƿ�ɼ�
		 */
		virtual bool isVisible();
		/**
		 * ������ͼ�Ƿ�ɼ�
		 */
		virtual void setVisible(bool value);
		/**
		 * ��ȡ��ͼ�Ŀ��
		 */
		virtual int getWidth();
		/**
		 * ������ͼ�Ŀ��
		 */
		virtual void setWidth(int value);
	public:
	    /**
         * �����ͼ
         * @param view  ��ͼ
        */
		virtual void addView(FCView *view);
		 /**
         * ����ͼ�߳��е��÷���
         * @param args  ����
        */
		virtual void addEvent(Object func, const String& eventName, Object pInvoke);
	    /**
         * ����ͼ�߳��е��÷���
         * @param args  ����
        */
		virtual void beginInvoke(Object args);
	    /**
         * ������ͼ������ǰ
         * @param childView  ����ͼ
        */
		virtual void bringChildToFront(FCView *childView);
		/**
		 * ����ͼ�ŵ���ǰ��ʾ
		 */
		virtual void bringToFront();
		/**
		 * ���������ͼ
		 */
		virtual void clearViews();
	    /**
         * �Ƿ������ͼ
         * @param view   ��ͼ
         * @returns  �Ƿ����
        */
		virtual bool containsView(FCView *view);
	    /**
         * �Ƿ������ͼ
         * @param point   ����
         * @returns  �Ƿ����
        */
		virtual bool containsPoint(const FCPoint& mp);
		/**
		 * ���ý���
		 */
		virtual void focus();
	    /**
         * ��ȡ��ͼ���ϵĿ���
         * @returns ��ͼ����
        */
		virtual ArrayList<FCView*> getViews();
	    /**
         * ��ȡ��ͼ����
         * @returns ��ͼ����
        */
		virtual String getViewType();
	    /**
         * ��ȡ��ʾƫ������
         * @returns ����
        */
		virtual FCPoint getDisplayOffset();
	    /**
         * ��ȡ�µ������
         * @returns �±��
        */
		static int getNewTimerID();
		/**
         * ��ȡ����ֵ
		 */
		virtual String getAttribute(const String& name);
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
         * �ж��Ƿ��������ͼ
         * @returns  �Ƿ��������ͼ
        */
		virtual bool hasChildren();
		/**
		 * ������ͼ
		 */
		virtual void hide();
	    /**
         * ������ͼ
         * @param index  ����
         * @param view  ��ͼ
        */
		virtual void insertView(int index, FCView *view);
		/**
		 * ��������
		 */
		virtual void invalidate();
	    /**
         * ����ͼ�߳��е��÷���
         * @param args  ����
        */
		virtual void invoke(Object args);
	    /**
         * �ж��Ƿ���ƿ���״̬
         * @param view   ��ͼ
         * @returns  �Ƿ���ƿ���״̬
        */
		bool isPaintEnabled(FCView *view);
	    /**
         * �ж��Ƿ��ͼʱ�ɼ�
         * @param view   ��ͼ
         * @returns  �Ƿ�ɼ�
        */
		bool isPaintVisible(FCView *view);
		/**
		 * �����ͼ����
		 */
		virtual void onAdd();
		/**
		 * �Զ����óߴ����Ըı䷽��
		 */
		virtual void onAutoSizeChanged();
		/*
		* ����ɫ�仯����
		*/
		virtual void onBackColorChanged();
		/**
		 * ����ɫ�ı䷽��
		 */
		virtual void onBackImageChanged();
		/*
		* ���뷽��
		*/
		virtual void onChar(wchar_t ch);
		/**
		 * �ַ�����
		 */
		virtual void onClick(FCTouchInfo touchInfo);
		/**
		 * ����
		 */
		virtual void onCopy();
		/**
		 * ����
		 */
		virtual void onCut();
		/**
		 * ��ͣ�ı䷽��
		 */
		virtual void onDockChanged();
	    /**
         * ����˫������
         * @param touchInfo  ������Ϣ
        */
		virtual void onDoubleClick(FCTouchInfo touchInfo);
	    /**
         *  �϶���ʼ����
         * @returns  �Ƿ��϶�
        */
		virtual bool onDragBegin();
		/**
		 * �϶���������
		 */
		virtual void onDragEnd();
		/**
		 * �����϶�����
		 */
		virtual void onDragging();
		/*
         * �ļ����뷽��
         */
        virtual void onDragInFiles(ArrayList<String> *files);
	    /**
         * �϶�׼������
         * @param startOffset  �����϶���ƫ��������
        */
		virtual void onDragReady(FCPoint *startOffset);
		/**
		 * ���øı䷽��
		 */
		virtual void onEnableChanged();
		/**
		 * ����ı䷽��
		 */
		virtual void onFontChanged();
		/**
		 * ��ý��㷽��
		 */
		virtual void onGotFocus();
	    /**
         * ����ͼ�߳��е��÷���
         * @param args  ����
        */
		virtual void onInvoke(Object args);
		/**
		 * ��ͼ���ط���
		 */
		virtual void onLoad();
		/**
		 * λ�øı䷽��
		 */
		virtual void onLocationChanged();
		/**
		 * ��ʧ���㷽��
		 */
		virtual void onLostFocus();
		/*
		* ���̰��·���
		*/
		virtual void onKeyDown(char key);
		/*
		* ����̧�𷽷�
		*/
		virtual void onKeyUp(char key);
		/**
		 * ��߾�ı䷽��
		 */
		virtual void onMarginChanged();
		/*
		* ��������
		*/
		virtual void onScaling(double scaleFactorX, double scaleFactorY);
	    /**
         * �������·���
         * @param touchInfo  ������Ϣ
        */
		virtual void onTouchDown(FCTouchInfo touchInfo);
	    /**
         * �������뷽��
         * @param touchInfo  ������Ϣ
        */
		virtual void onTouchEnter(FCTouchInfo touchInfo);
	    /**
         * �����뿪����
         * @param touchInfo  ������Ϣ
        */
		virtual void onTouchLeave(FCTouchInfo touchInfo);
	    /**
         * �����ƶ����÷���
         * @param touchInfo  ������Ϣ
        */
		virtual void onTouchMove(FCTouchInfo touchInfo);
	    /**
         * ����̧�𷽷�
         * @param touchInfo  ������Ϣ
        */
		virtual void onTouchUp(FCTouchInfo touchInfo);
		/*
		* ������������
		*/
		virtual void onTouchWheel(FCTouchInfo touchInfo);
		/**
		 * �ڱ߾�ı䷽��
		 */
		virtual void onPaddingChanged();
	    /**
         * �ػ淽��
         * @param paint  ��ͼ����
         * @param clipRect   �ü�����
        */
		virtual void onPaint(FCPaint *paint, const FCRect& clipRect);
	    /**
         * �ػ汳������
         * @param paint  ��ͼ����
         * @param clipRect   �ü�����
        */
		virtual void onPaintBackground(FCPaint *paint, const FCRect& clipRect);
	    /**
         * �ػ���߷���
         * @param paint  ��ͼ����
         * @param clipRect   �ü�����
        */
		virtual void onPaintBorder(FCPaint *paint, const FCRect& clipRect);
	    /**
         * �ػ�ǰ������
         * @param paint  ��ͼ����
         * @param clipRect   �ü�����
        */
		virtual void onPaintForeground(FCPaint *paint, const FCRect& clipRect);
		/**
		 * �������ı䷽��
		 */
		virtual void onParentChanged();
		/**
		 * ����
		 */
		virtual void onPaste();
	    /**
         * Ԥ��ͼ����
         * @param paint  ��ͼ����
         * @param clipRect   �ü�����
        */
		virtual bool onPrePaint(FCPaint *paint, const FCRect& clipRect);
		/*
		* ����Ԥ�����¼�
		*/
		virtual bool onPreviewsKeyEvent(String eventName, char key);
	    /**
         * �����°�����
         * @param eventName  �¼�ID
         * @param key      ����
         * @returns     ״̬
        */
		virtual bool onPreviewsTouchEvent(String eventName, FCTouchInfo touchInfo);
		/**
		 * �ü�����ı䷽��
		 */
		virtual void onRegionChanged();
		/**
		 * �Ƴ���ͼ����
		 */
		virtual void onRemove();
		/**
		 * �ߴ�ı䷽��
		 */
		virtual void onSizeChanged();
		/**
		 * TAB�����ı䷽��
		 */
		virtual void onTabIndexChanged();
		/**
		 * ��ʹ��TAB�л�����
		 */
		virtual void onTabStop();
		/**
		 * �Ƿ���TAB�л��ı䷽��
		 */
		virtual void onTabStopChanged();
		/**
		 * �ı��ı䷽��
		 */
		virtual void onTextChanged();
		/**
		 * ǰ��ɫ�ı䷽��
		 */
		virtual void onTextColorChanged();
	    /**
         * ���ص�����
         * @param timerID  ���
        */
		virtual void onTimer(int timerID);
		/**
		 * �ɼ�״̬�ı䷽��
		 */
		virtual void onVisibleChanged();
		/*
		 * תΪ�������
		 */
		virtual FCPoint pointToView(const FCPoint& mp);
	    /**
         * ��ȡ�������ͼ���������
         * @param point  ����
         * @returns  �������
        */
		virtual FCPoint pointToNative(const FCPoint& mp);
	    /**
         * �Ƴ���ͼ
         * @param view ��ͼ
        */
		virtual void removeView(FCView *view);
		/**
         * ȡ��ע���¼�
         * @param func  ����ָ��
         * @param eventName  �¼�����
        */
		virtual void removeEvent(Object func, const String& eventName);
	    /**
         * ��������
         * @param name  ��������
         * @param value ����ֵ
        */
		virtual void setAttribute(const String& name, const String& value);
		/**
		 * ��ʾ��ͼ
		 */
		virtual void show();
		/*
		* �ھ���������ʾ
		*/
		virtual bool showOutOfMirror();
	    /**
         * ��ʼ���
         * @param timerID  ���
         * @param interval ���
        */
		virtual void startTimer(int timerID, int interval);
	    /**
         * ֹͣ���
         * @param timerID  ���
        */
		virtual void stopTimer(int timerID);
	    /**
         * ����ͼ�������
         * @param childView  ����ͼ
        */
		virtual void sendChildToBack(FCView *childView);
		/**
		 * ����ͼ�ŵ���������ʾ
		 */
		virtual void sendToBack();
		/**
		 * ���½���
		 */
		virtual void update();
	};
}