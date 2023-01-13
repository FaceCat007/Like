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

	/*
	* Xml解析扩展
	*/
	class UIXmlEx : public FCUIXml{	
	protected:
		map<String, FCView*> m_controlsMap;
		map<String, FCTabPage*> m_tempTabPages;
	public:
		/*
		* 构造函数
		*/
		UIXmlEx();
		/*
		* 析构函数
		*/
		virtual ~UIXmlEx();
		double m_scaleFactor;
	public:
		/*
		* 自动选中第一行
		* @param grid 表格
		*/
		void autoSelectFirstRow(FCGrid *grid);
		/*
		* 自动选中最后一行
		* @param grid 表格
		*/
		void autoSelectLastRow(FCGrid *grid);
		/*
		* 创建控件
		* @param node 节点
		* @param type 类型
		*/
		virtual FCView* createView(IXMLDOMNode *node, const String& type);
		/*
		* 查找控件
		* @param name 名称
		*/
		virtual FCView* findView(const String& name);
		/*
		* 获取列的索引
		* @param grid 表格
		* @param columnsIndex 列的索引
		*/
		int getColumnsIndex(FCGrid *grid, map<int, FCGridColumn*> *columnsIndex);
		/*
		* 加载数据
		*/
		virtual void loadData();
		/*
		* 加载文件
		* @param fileName 文件名
		* @param control 控件
		*/
		virtual void loadFile(const String& fileName, FCView *control);
		/*
		* 控件被添加方法
		* @param control 控件
		* @param node 节点
		*/
		virtual void onAddView(FCView *control, IXMLDOMNode *node);
		/*
		* 移除控件
		*/
		void removeTempControls();
		/*
		* 获取或设置缩放比例
		*/
		double getScaleFactor();
		void setScaleFactor(double scaleFactor);
		/*
		* 重置大小
		* @param clientSize 客户端大小
		*/
		void resetScaleSize(FCSize clientSize);
	};

	/*
	* 表格行的扩展
	*/
	class FCGridRowEx:public FCGridRow{
	public:
		/*
		* 重绘方法
		* @param paint 绘图对象
		* @param clipRect 裁剪区域
		* @param isAlternate 是否交替
		*/
		virtual void onPaint(FCPaint *paint, const FCRect& clipRect, bool isAlternate);
		/*
		* 重绘边线方法
		* @param paint 绘图对象
		* @param clipRect 裁剪区域
		* @param isAlternate 是否交替
		*/
		virtual void onPaintBorder(FCPaint *paint, const FCRect& clipRect, bool isAlternate);
	};

}
#endif