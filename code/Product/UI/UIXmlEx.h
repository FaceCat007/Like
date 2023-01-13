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

	/*
	* Xml������չ
	*/
	class UIXmlEx : public FCUIXml{	
	protected:
		map<String, FCView*> m_controlsMap;
		map<String, FCTabPage*> m_tempTabPages;
	public:
		/*
		* ���캯��
		*/
		UIXmlEx();
		/*
		* ��������
		*/
		virtual ~UIXmlEx();
		double m_scaleFactor;
	public:
		/*
		* �Զ�ѡ�е�һ��
		* @param grid ���
		*/
		void autoSelectFirstRow(FCGrid *grid);
		/*
		* �Զ�ѡ�����һ��
		* @param grid ���
		*/
		void autoSelectLastRow(FCGrid *grid);
		/*
		* �����ؼ�
		* @param node �ڵ�
		* @param type ����
		*/
		virtual FCView* createView(IXMLDOMNode *node, const String& type);
		/*
		* ���ҿؼ�
		* @param name ����
		*/
		virtual FCView* findView(const String& name);
		/*
		* ��ȡ�е�����
		* @param grid ���
		* @param columnsIndex �е�����
		*/
		int getColumnsIndex(FCGrid *grid, map<int, FCGridColumn*> *columnsIndex);
		/*
		* ��������
		*/
		virtual void loadData();
		/*
		* �����ļ�
		* @param fileName �ļ���
		* @param control �ؼ�
		*/
		virtual void loadFile(const String& fileName, FCView *control);
		/*
		* �ؼ�����ӷ���
		* @param control �ؼ�
		* @param node �ڵ�
		*/
		virtual void onAddView(FCView *control, IXMLDOMNode *node);
		/*
		* �Ƴ��ؼ�
		*/
		void removeTempControls();
		/*
		* ��ȡ���������ű���
		*/
		double getScaleFactor();
		void setScaleFactor(double scaleFactor);
		/*
		* ���ô�С
		* @param clientSize �ͻ��˴�С
		*/
		void resetScaleSize(FCSize clientSize);
	};

	/*
	* ����е���չ
	*/
	class FCGridRowEx:public FCGridRow{
	public:
		/*
		* �ػ淽��
		* @param paint ��ͼ����
		* @param clipRect �ü�����
		* @param isAlternate �Ƿ���
		*/
		virtual void onPaint(FCPaint *paint, const FCRect& clipRect, bool isAlternate);
		/*
		* �ػ���߷���
		* @param paint ��ͼ����
		* @param clipRect �ü�����
		* @param isAlternate �Ƿ���
		*/
		virtual void onPaintBorder(FCPaint *paint, const FCRect& clipRect, bool isAlternate);
	};

}
#endif