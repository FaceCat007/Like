/*����FaceCat(����è)��� v1.0
 �Ϻ����è��Ϣ�������޹�˾
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
		//�Զ�ѡ�е�һ��
		void autoSelectFirstRow(FCGrid *grid);
		//�Զ�ѡ�����һ��
		void autoSelectLastRow(FCGrid *grid);
		//�����ؼ�
		virtual FCView* createView(IXMLDOMNode *node, const String& type);
		//���ҿؼ�
		virtual FCView* findView(const String& name);
		//��ȡ�е�����
		int getColumnsIndex(FCGrid *grid, map<int, FCGridColumn*> *columnsIndex);
		//��������
		virtual void loadData();
		//�����ļ�
		virtual void loadFile(const String& fileName, FCView *control);
		//�ؼ�����ӷ���
		virtual void onAddView(FCView *control, IXMLDOMNode *node);
		//�Ƴ��ؼ�
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