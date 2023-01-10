/*基于FaceCat(捂脸猫)框架 v1.0
 上海卷卷猫信息技术有限公司
 */

#ifndef __UIXMLEX_H__
#define __UIXMLEX_H__
#pragma once
#include "..\\..\\stdafx.h"
#include "..\\..\\..\\facecat\\include\\xml\\FCUIXml.h"
#include <atlstr.h>  
#import <msxml3.dll>
#include "WindowEx.h"

namespace FaceCat{
	#define hRCALL(a, errmsg) \
	do{ \
		hr = (a); \
		if (FAILED(hr)){ \
			dprintf( "%s:%d  HRCALL Failed: %s\n  0x%.8x = %s\n", \
					__FILE__, __LINE__, errmsg, hr, #a ); \
			goto clean; \
		} \
	} while (0)

	class UIXmlEx : public FCUIXml{	
	protected:
		map<String, FCView*> m_controlsMap;
		map<String, FCTabPage*> m_tempTabPages;
	public:
		UIXmlEx();
		virtual ~UIXmlEx();
		double m_scaleFactor;
	public:
		//自动选中第一行
		void autoSelectFirstRow(FCGrid *grid);
		//自动选中最后一行
		void autoSelectLastRow(FCGrid *grid);
		//创建控件
		virtual FCView* createView(IXMLDOMNode *node, const String& type);
		//查找控件
		virtual FCView* findView(const String& name);
		//获取列的索引
		int getColumnsIndex(FCGrid *grid, map<int, FCGridColumn*> *columnsIndex);
		//加载数据
		virtual void loadData();
		//加载文件
		virtual void loadFile(const String& fileName, FCView *control);
		//控件被添加方法
		virtual void onAddView(FCView *control, IXMLDOMNode *node);
		//移除控件
		void removeTempControls();
		double getScaleFactor();
		void setScaleFactor(double scaleFactor);
		void resetScaleSize(FCSize clientSize);
	};

	class WinForm;

    class WindowXmlEx : public UIXmlEx, public FCInvokeEventCallBack, public FCTouchEventCallBack{
    public:
		bool m_isClosing;
		bool m_isWinForm;
        WindowEx *m_window;
		WinForm *m_winForm;
    private:
        virtual void callTouchEvent(String eventName, Object sender, FCTouchInfo touchInfo, Object invoke);
        virtual void callInvokeEvent(String eventName, Object sender, Object args, Object invoke);
	public:
		WindowXmlEx();
		virtual ~WindowXmlEx();
		bool isWinForm();
		void setIsWinForm(bool isWinForm);
        WindowEx* getWindow();
	public:
		virtual void close();
        virtual void load(FCNative *native, String xmlName, String windowName);
        void onInvoke(void *args);
		virtual void show();
		virtual void showDialog();
	};

	class FCGridRowEx:public FCGridRow{
	public:
		virtual void onPaint(FCPaint *paint, const FCRect& clipRect, bool isAlternate);
		virtual void onPaintBorder(FCPaint *paint, const FCRect& clipRect, bool isAlternate);
	};

}
#endif