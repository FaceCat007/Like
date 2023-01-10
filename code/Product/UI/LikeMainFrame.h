/*基于FaceCat(捂脸猫)框架 v1.0
 上海卷卷猫信息技术有限公司
 */

#ifndef __FUTURE_H__
#define __FUTURE_H__
#pragma once
#include "..\\..\\stdafx.h"
#include "GdiPlusPaintEx.h"
#include "UIXmlEx.h"
#include "WinHostEx.h"
#include "..\\Service\\ALikeService.h"

using namespace FaceCat;

class LikeChart : public FCChart{
	/**
     * 绘制K线
     * @param paint 绘图对象
     * @param div   要绘制的层
     * @param cs    K线
    */
	virtual void onPaintCandle(FCPaint *paint, ChartDiv *div, CandleShape *cs);
	/**
     * 绘制成交量
     * @param paint 绘图对象
     * @param div   要绘制的层
     * @param bs    线条对象
    */
	virtual void onPaintBar(FCPaint *paint, ChartDiv *div, BarShape *bs);
};

//交易控件
class LikeMainFrame : public UIXmlEx, public FCTouchEventCallBack, public FCGridCellTouchEventCallBack, public FCTimerEventCallBack, public FCEventCallBack, public FCPaintEventCallBack{
public:
	//左侧图形
	FCChart *m_chartLeft;
	//右侧图形
	FCChart *m_chartRight;
	//区域图形
	FCChart *m_chartScope;
	//画笔图形
	FCDiv *m_divGraph;
	//图形数据
	vector<SecurityData*> m_graphDatas;
	//设备信息
	WinHost *m_host;
	//句柄
	HWND m_hWnd;
	//相似信息
	vector<LikeDataInfo> m_likeDataInfos;
	//移动点位信息
	vector<FCPoint> m_movePoints;
	//缩放信息
	double m_scaleFactor;
	//开始画笔
	bool m_startPen;
	//代码表格
	FCGrid *m_tableCodes;
	//代码表格2
	FCGrid *m_tableCodes2;
	//结果表格
	FCGrid *m_tableResults;
	//秒表ID
	int m_timerID;
	//代码输入框
	FCTextBox *m_txtCode;
	//代码输入框2
	FCTextBox *m_txtCode2;
private:
	//选中改变事件
	virtual void callEvent(String eventName, Object sender, Object invoke);
	//按钮点击方法
	virtual void callTouchEvent(String eventName, Object sender, FCTouchInfo touchInfo, Object invoke);
	//单元格点击事件
	virtual void callGridCellTouchEvent(String eventName, Object sender, FCGridCell *cell, FCTouchInfo touchInfo, Object invoke);
	//注册事件
	void registerEvents(FCView *control);
	//重绘方法
	virtual bool callPaintEvent(String eventName, Object sender, FCPaint *paint, const FCRect& clipRect, Object invoke);
	//秒表事件
	virtual void callTimerEvent(String eventName, Object sender, int timerID, Object invoke);
public:
	LikeMainFrame(HWND hWnd);
	virtual ~LikeMainFrame();
	//获取或设置缩放因子
	double getScaleFactor();
	void setScaleFactor(double scaleFactor);
public:
	//退出
	void exit();
	//窗体是否正在显示
	bool isWindowShowing();
	//加载Xml
	void load(const String& xmlPath);
	//加载数据
	virtual void loadData();
	//调整缩放大小
	void resetScaleSize(FCSize clientSize);
	//显示提示框
	int showMessageBox(const String& text, const String& caption, UINT uType);
	//消息循环
	int wndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
public:
	//绑定历史数据
	void bindHistoryDatas(const String& code, int index);
	//绑定结果表
	void bindResultTable(const String& code);
	//绑定模拟码表
	void bindSandBoxTable(vector<LikeDataInfo> *likeDataInfos);
	//导出数据
	String exportData(bool writeFile);
	//初始化图形
	void initChart(FCChart *chart);
	//选中改变事件
	void onCheckedChangedEvent(void *sender);
	//单元格点击事件
	void onGridCellClickEvent(void *sender, FCGridCell *cell, FCTouchInfo touchInfo);
	//多页夹选中改变方法
	void onSelectedTabPageChangedEvent();
	//文本改变事件
	void onTextChangedEvent(void *sender);
	//秒表事件
	void onTimerEvent(void *sender, int timerID);
	//开始方法
	void start();
	//开始搜索
	void startSearch();
public:
	//开始画笔
	void startPen();
	//开始移动画笔
	void movePen();
	//停止画笔
	void stopPen();
};
#endif