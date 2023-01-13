/*����FaceCat(����è)��� v1.0
 �Ϻ����è��Ϣ�������޹�˾
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
     * ����K��
     * @param paint ��ͼ����
     * @param div   Ҫ���ƵĲ�
     * @param cs    K��
    */
	virtual void onPaintCandle(FCPaint *paint, ChartDiv *div, CandleShape *cs);
	/**
     * ���Ƴɽ���
     * @param paint ��ͼ����
     * @param div   Ҫ���ƵĲ�
     * @param bs    ��������
    */
	virtual void onPaintBar(FCPaint *paint, ChartDiv *div, BarShape *bs);
};

/*
*����ͼ
*/
class LikeMainFrame : public UIXmlEx, public FCTouchEventCallBack, public FCGridCellTouchEventCallBack, public FCTimerEventCallBack, public FCEventCallBack, public FCPaintEventCallBack{
public:
	/*
	* ���ͼ��
	*/
	FCChart *m_chartLeft;
	/*
	* �Ҳ�ͼ��
	*/
	FCChart *m_chartRight;
	/*
	* ����ͼ��
	*/
	FCChart *m_chartScope;
	/*
	* ����ͼ��
	*/
	FCDiv *m_divGraph;
	/*
	* ͼ������
	*/
	vector<SecurityData*> m_graphDatas;
	/*
	* �豸��Ϣ
	*/
	WinHost *m_host;
	/*
	* ���
	*/
	HWND m_hWnd;
	/*
	* ������Ϣ
	*/
	vector<LikeDataInfo> m_likeDataInfos;
	/*
	* �ƶ���λ��Ϣ
	*/
	vector<FCPoint> m_movePoints;
	/*
	* ������Ϣ
	*/
	double m_scaleFactor;
	/*
	* ��ʼ����
	*/
	bool m_startPen;
	/*
	* ������
	*/
	FCGrid *m_tableCodes;
	/*
	* ������2
	*/
	FCGrid *m_tableCodes2;
	/*
	* ������
	*/
	FCGrid *m_tableResults;
	/*
	* ���ID
	*/
	int m_timerID;
	/*
	* ���������
	*/
	FCTextBox *m_txtCode;
	/*
	* ���������2
	*/
	FCTextBox *m_txtCode2;
private:
	/*
	* �����¼�
	* @param eventName �¼�����
	* @param sender ������
	* @param invoke ������
	*/
	virtual void callEvent(String eventName, Object sender, Object invoke);
	/*
	* �����¼�
	* @param eventName �¼�����
	* @param sender ������
	* @param touchInfo ������Ϣ
	* @param invoke ������
	*/
	virtual void callTouchEvent(String eventName, Object sender, FCTouchInfo touchInfo, Object invoke);
	/*
	* ������Ԫ���¼�
	* @param eventName �¼�����
	* @param sender ������
	* @param cell ��Ԫ��
	* @param touchInfo ������Ϣ
	* @param invoke ������
	*/
	virtual void callGridCellTouchEvent(String eventName, Object sender, FCGridCell *cell, FCTouchInfo touchInfo, Object invoke);
	/*
	* ע���¼�
	* @param control �ռ�
	*/
	void registerEvents(FCView *control);
	/*
	* �ػ��¼�
	* @param eventName �¼�����
	* @param sender ������
	* @param paint ��ͼ����
	* @param clipRect �ü�����
	* @param invoke ������
	*/
	virtual bool callPaintEvent(String eventName, Object sender, FCPaint *paint, const FCRect& clipRect, Object invoke);
	/*
	* ����¼�
	* @param eventName �¼�����
	* @param sender ������
	* @param timerID ���ID
	* @param invoke ������
	*/
	virtual void callTimerEvent(String eventName, Object sender, int timerID, Object invoke);
public:
	/*
	* ���캯��
	*/
	LikeMainFrame(HWND hWnd);
	/*
	* ��������
	*/
	virtual ~LikeMainFrame();
	/*
	* ��ȡ��������������
	*/
	double getScaleFactor();
	void setScaleFactor(double scaleFactor);
public:
	/*
	* �˳�
	*/
	void exit();
	/*
	* �����Ƿ�������ʾ
	*/
	bool isWindowShowing();
	/*
	* ����Xml
	* @param xmlPath ·��
	*/
	void load(const String& xmlPath);
	/*
	* ��������
	*/
	virtual void loadData();
	/*
	* �������Ŵ�С
	* @param clientSize �ͻ��˴�С
	*/
	void resetScaleSize(FCSize clientSize);
	/*
	* ��ʾ��ʾ��
	* @param text ����
	* @param caption ����
	* @param uType ����
	*/
	int showMessageBox(const String& text, const String& caption, UINT uType);
	/*
	* ��Ϣѭ��
	*/
	int wndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
public:
	/*
	* ����ʷ����
	* @param code ����
	* @param index ����
	*/
	void bindHistoryDatas(const String& code, int index);
	/*
	* �󶨽����
	* @param code ����
	*/
	void bindResultTable(const String& code);
	/*
	* ��ģ�����
	* @param likeDataInfos ����
	*/
	void bindSandBoxTable(vector<LikeDataInfo> *likeDataInfos);
	/*
	* ��������
	* @param writeFile �ļ�·��
	*/
	String exportData(bool writeFile);
	/*
	* ��ʼ��ͼ��
	* @param chart ͼ��
	*/
	void initChart(FCChart *chart);
	/*
	* ѡ�иı��¼�
	* @param sender ������
	*/
	void onCheckedChangedEvent(void *sender);
	/*
	* ��Ԫ�����¼�
	* @param sender ������
	* @param cell ��Ԫ��
	* @param touchInfo ������Ϣ
	*/
	void onGridCellClickEvent(void *sender, FCGridCell *cell, FCTouchInfo touchInfo);
	/*
	* ��ҳ��ѡ�иı䷽��
	*/
	void onSelectedTabPageChangedEvent();
	/*
	* �ı��ı��¼�
	* @param sender ������
	*/
	void onTextChangedEvent(void *sender);
	/*
	* ����¼�
	* @param sender ������
	* @param timerID ���ID
	*/
	void onTimerEvent(void *sender, int timerID);
	/*
	* ��ʼ����
	*/
	void start();
	/*
	* ��ʼ����
	*/
	void startSearch();
public:
	/*
	* ��ʼ����
	*/
	void startPen();
	/*
	* ��ʼ�ƶ�����
	*/
	void movePen();
	/*
	* ֹͣ����
	*/
	void stopPen();
};
#endif