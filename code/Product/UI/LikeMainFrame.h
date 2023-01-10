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

//���׿ؼ�
class LikeMainFrame : public UIXmlEx, public FCTouchEventCallBack, public FCGridCellTouchEventCallBack, public FCTimerEventCallBack, public FCEventCallBack, public FCPaintEventCallBack{
public:
	//���ͼ��
	FCChart *m_chartLeft;
	//�Ҳ�ͼ��
	FCChart *m_chartRight;
	//����ͼ��
	FCChart *m_chartScope;
	//����ͼ��
	FCDiv *m_divGraph;
	//ͼ������
	vector<SecurityData*> m_graphDatas;
	//�豸��Ϣ
	WinHost *m_host;
	//���
	HWND m_hWnd;
	//������Ϣ
	vector<LikeDataInfo> m_likeDataInfos;
	//�ƶ���λ��Ϣ
	vector<FCPoint> m_movePoints;
	//������Ϣ
	double m_scaleFactor;
	//��ʼ����
	bool m_startPen;
	//������
	FCGrid *m_tableCodes;
	//������2
	FCGrid *m_tableCodes2;
	//������
	FCGrid *m_tableResults;
	//���ID
	int m_timerID;
	//���������
	FCTextBox *m_txtCode;
	//���������2
	FCTextBox *m_txtCode2;
private:
	//ѡ�иı��¼�
	virtual void callEvent(String eventName, Object sender, Object invoke);
	//��ť�������
	virtual void callTouchEvent(String eventName, Object sender, FCTouchInfo touchInfo, Object invoke);
	//��Ԫ�����¼�
	virtual void callGridCellTouchEvent(String eventName, Object sender, FCGridCell *cell, FCTouchInfo touchInfo, Object invoke);
	//ע���¼�
	void registerEvents(FCView *control);
	//�ػ淽��
	virtual bool callPaintEvent(String eventName, Object sender, FCPaint *paint, const FCRect& clipRect, Object invoke);
	//����¼�
	virtual void callTimerEvent(String eventName, Object sender, int timerID, Object invoke);
public:
	LikeMainFrame(HWND hWnd);
	virtual ~LikeMainFrame();
	//��ȡ��������������
	double getScaleFactor();
	void setScaleFactor(double scaleFactor);
public:
	//�˳�
	void exit();
	//�����Ƿ�������ʾ
	bool isWindowShowing();
	//����Xml
	void load(const String& xmlPath);
	//��������
	virtual void loadData();
	//�������Ŵ�С
	void resetScaleSize(FCSize clientSize);
	//��ʾ��ʾ��
	int showMessageBox(const String& text, const String& caption, UINT uType);
	//��Ϣѭ��
	int wndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
public:
	//����ʷ����
	void bindHistoryDatas(const String& code, int index);
	//�󶨽����
	void bindResultTable(const String& code);
	//��ģ�����
	void bindSandBoxTable(vector<LikeDataInfo> *likeDataInfos);
	//��������
	String exportData(bool writeFile);
	//��ʼ��ͼ��
	void initChart(FCChart *chart);
	//ѡ�иı��¼�
	void onCheckedChangedEvent(void *sender);
	//��Ԫ�����¼�
	void onGridCellClickEvent(void *sender, FCGridCell *cell, FCTouchInfo touchInfo);
	//��ҳ��ѡ�иı䷽��
	void onSelectedTabPageChangedEvent();
	//�ı��ı��¼�
	void onTextChangedEvent(void *sender);
	//����¼�
	void onTimerEvent(void *sender, int timerID);
	//��ʼ����
	void start();
	//��ʼ����
	void startSearch();
public:
	//��ʼ����
	void startPen();
	//��ʼ�ƶ�����
	void movePen();
	//ֹͣ����
	void stopPen();
};
#endif