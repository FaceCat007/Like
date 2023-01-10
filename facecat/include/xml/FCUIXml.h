/*
 * FaceCat���(�ǿ�Դ)
 * �Ϻ����è��Ϣ�������޹�˾
 */

#ifdef __UIXML_H__
#else                                                                            
#define __UIXML_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "FCUIEvent.h"
#include "FCUIScript.h"
#include <atlstr.h>  
#import <msxml3.dll>
#include "..\\core\\FCLib.h"

namespace FaceCat{
	#define HRCALL(a, errmsg) \
	do { \
		hr = (a); \
		if (FAILED(hr)) { \
			dprintf( "%s:%d  HRCALL Failed: %s\n  0x%.8x = %s\n", \
					__FILE__, __LINE__, errmsg, hr, #a ); \
			goto clean; \
		} \
	} while (0)

	class FCUIEvent;
	class FCUIScript;

	/*
	* XML����
	*/
	class __UIXML_H__ FCUIXml{
	public:
		/*
		* �Ƿ���������
		*/
		bool m_allowName;
		/*
		* ����
		*/
		String m_name;
	    /**
		 * ��ͼ�б�
		 */
		ArrayList<FCView*> m_views;
		/**
		 * �¼�
		 */
		FCUIEvent *m_event;
		/**
		 * ������
		 */
		FCNative *m_native;
		/**
		 * �ű�
		 */
		FCUIScript *m_script;
		/**
		 * CSS��ʽ
		 */
		HashMap<String, String> m_styles;
		/*
		* ����FCGridBand
		*/
		virtual void createBandedGridBands(IXMLDOMNode *node, FCView *view);
		/*
		 * ���������
		 */
		virtual void createBandedGridColumns(IXMLDOMNode *node, FCView *view);
		/*
		 * ����ͼ�ε������� 
		 */
		virtual void createChartSubAttribute(IXMLDOMNode *node, FCChart *chart);
		/**
		 * �����˵���
		 */
		virtual void createMenuItem(IXMLDOMNode *node, FCMenu *menu, FCMenuItem *parentItem);
		/*
		 * ���������
		 */
		virtual void createGridColumns(IXMLDOMNode *node, FCView *view);
		/*
		 * ���������
		 */
		virtual void createGridRow(IXMLDOMNode *node, FCView *view);
		/*
		 * ���������
		 */
		virtual void createGridRows(IXMLDOMNode *node, FCView *view);
		/**
		 * �����ָ����ͼ
		 */
		virtual void createSplitLayoutSubAttribute(IXMLDOMNode *node, FCSplitLayoutDiv *splitLayoutDiv);
		/**
		 * ������ͼ
		 */
		virtual void createTableLayoutSubAttribute(IXMLDOMNode *node, FCTableLayoutDiv *tableLayoutDiv);
		/**
		 * ������ҳ�е�ҳ
		 */
		virtual void createTabPage(IXMLDOMNode *node, FCView *view);
		/**
		 * �������Ľڵ�
		 */
		virtual void createTreeNode(IXMLDOMNode *node, FCView *view, FCTreeNode *treeNode);
		/**
		 * �������Ľڵ�
		 */
		virtual void createTreeNodes(IXMLDOMNode *node, FCView *view);
		/**
		 * �����û���ͼ
		 */
		virtual FCView* createCustomView(IXMLDOMNode *node);
		static void dprintf(char *format, ...);
		static IXMLDOMDocument* domFromCOM();	
	public:
		/*
		* ���캯��
		*/
		FCUIXml();
		/*
		* ��������
		*/
		virtual ~FCUIXml();
		/**
		 * ��ȡ�¼�
		 */
		virtual FCUIEvent* getEvent();
		/**
		 * �����¼�
		 */
		virtual void setEvent(FCUIEvent *value);
		/**
		 * ��ȡ������
		 */
		virtual FCNative* getNative();
		/**
		 * ���÷�����
		 */
		virtual void setNative(FCNative *value);
		/**
		 * ��ȡ�ű�
		 */
		virtual FCUIScript* getScript();
		/**
		 * ���ýű�
		 */
		virtual void setScript(FCUIScript *value);
		/*
		 * ��ȡXML��·��
		 */
		String getXmlPath();
	public:
		/**
		* ��ȡ��ť
		* @params name   ��ͼ����
		*/
		virtual FCButton* getButton(const String& name);
		/**
		 * ��ȡͼ����ͼ
		 */
		virtual FCChart* getChart(const String& name);
		/**
		 * ��ȡ��ѡ��
		 */
		virtual FCCheckBox* getCheckBox(const String& name);
		/**
		 * ��ȡ������ͼ
		 */
		virtual FCComboBox* getComboBox(const String& name);
		/*
		 * ��ȡ����ʱ����ͼ
		 */
		virtual FCDateTimePicker* getDateTimePicker(const String& name);
		/**
		 * ��ȡͼ��
		 */
		virtual FCDiv* getDiv(const String& name);
		/**
		 * ��ȡ���
		 */
		virtual FCGrid* getGrid(const String& name);
		/**
		 * ��ȡ����ͼ
		 */
		virtual FCGroupBox* getGroupBox(const String& name);
		/**
		 * ��ȡ��ǩ
		 */
		virtual FCLabel* getLabel(const String& name);
		/**
		 * ��ȡ���ֲ�
		 */
		virtual FCLayoutDiv* getLayoutDiv(const String& name);
		/**
		 * ��ȡ����������ͼ
		 */
		virtual ArrayList<FCView*> getLikeViews(const String& name);
		/**
		 * ��ȡ�˵���ͼ
		 */
		virtual FCMenu* getMenu(const String& name);
		/**
		 * ��ȡ�˵�����ͼ
		 */
		virtual FCMenuItem* getMenuItem(const String& name);
		/**
		 * ��ȡ��ѡ��ť
		 */
		virtual FCRadioButton* getRadioButton(const String& name);
		/**
		 * ��ȡ��ֵ��ͼ
		 */
		virtual FCSpin* getSpin(const String& name);
		/**
		 * ��ȡ�ָ��
		 */
		virtual FCSplitLayoutDiv* getSplitLayoutDiv(const String& name);
		/**
		 * ��ȡ��ҳ����ͼ
		 */
		virtual FCTabView* getTabView(const String& name);
		/**
		 * ��ȡ����
		 */
		virtual FCTableLayoutDiv* getTableLayoutDiv(const String& name);
		/**
		 * ��ȡ����ͼ
		 */
		virtual FCTabPage* getTabPage(const String& name);
		/**
		 * ��ȡ�ı���
		 */
		virtual FCTextBox* getTextBox(const String& name);
		/**
		 * ��ȡ����ͼ
		 */
		virtual FCTree* getTree(const String& name);
		/**
		 * ��ȡ����
		 */
		virtual FCWindow* getWindow(const String& name);
		/*
		* ��ȡ������Xml����
		*/
		static FCUIXml* getNameXml(const String& name);
	public:
		/**
		* �Ƿ������ͼ
		* @params view  ��ͼ
		* @params node  �ڵ�
		*/
		virtual bool containsView(FCView *view);
		/**
		 * ������ͼ
		 */
		virtual FCView* createView(IXMLDOMNode *node, const String& type);
		/**
		 * ������ͼ���
		 */
		virtual void createNative();
		/**
		 * ����������
		 */
		virtual void createSubAttribute(IXMLDOMNode *node, FCView *view);
		/**
		 * ������ͼ
		 */
		virtual FCView* findView(const String& name);
		/**
		 * ��ȡ����
		 */
		virtual HashMap<String, String> getAttributes(IXMLDOMNode *node);
		/**
		 * ��ȡ���е���ͼ
		 */
		virtual ArrayList<FCView*> getViews();
		/**
		 * �ж��Ƿ����������
		 */
		virtual bool isAfterSetingAttribute(const String& name);
		/**
		 * ��ȡ�ļ������ص���ͼ��
		 */
		virtual void loadFile(const String& fileName, FCView *view);
		/**
		 * �����ͼ
		 */
		virtual void onAddView(FCView *view, IXMLDOMNode *node);
		/**
		 * ��ȡ�ļ���
		 */
		virtual void readBody(IXMLDOMNode *node, FCView *view);
		/**
		 * ��ȡ�ӽڵ�
		 */
		virtual void readChildNodes(IXMLDOMNode *node, FCView *view);
		/**
		 * ��ȡͷ��
		 */
		virtual void readHead(IXMLDOMNode *node, FCView *view);
		/**
		 * ��ȡXML
		 */
		virtual FCView* readNode(IXMLDOMNode *node, FCView* parent);
		/**
		 * ��ȡ��ʽ
		 */
		virtual void readStyle(IXMLDOMNode *node, FCView *view);
		/**
		 * ����������
		 */
		virtual void setAttributesAfter(IXMLDOMNode *node, FCAttribute *view);
		/**
		 * ǰ��������
		 */
		virtual void setAttributesBefore(IXMLDOMNode *node, FCAttribute *view);
		/**
		 * �����¼�
		 */
		virtual void setEvents(IXMLDOMNode *node, FCAttribute *view);
		/**
		 * ����CSS��ʽ
		 */
		virtual void setStyle(const String& style, FCAttribute *view);
	};
}