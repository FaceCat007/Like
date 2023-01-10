/*
 * FaceCatͼ��ͨѶ���(�ǿ�Դ)
 * ����Ȩ���:2015SR229355+2020SR0266727
 * �Ϻ����è��Ϣ�������޹�˾
 */

#ifdef __CHARTDIV_H__
#else                                                                            
#define __CHARTDIV_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "..\\core\\FCPaint.h"
#include "Enums.h"
#include "CrossLine.h"
#include "ScaleGrid.h"
#include "FCChart.h"
#include "VScale.h"
#include "SelectArea.h"
#include "ChartToolTip.h"
#include "ChartTitleBar.h"
#include "HScale.h"
#include "FCPlot.h"
#include "BaseShape.h"

namespace FaceCat{

	class FCChart;
	class CrossLine;
	class ChartToolTip;
	class FCPlot;
	class BaseShape;
	class HScale;
	class VScale;
	class FCNative;
	class ChartTitleBar;
	class SelectArea;
	class ScaleGrid;

	/*
	* ͼ�㣬�������������ᣬͼ�Σ����߹��ߣ�ָ������ݡ�
	*/
	class __CHARTDIV_H__ ChartDiv : public FCAttribute{
	public:
		/*
		* �Ƿ������û���ͼ
		*/
		bool m_allowUserPaint;
		/*
		* ����ɫ
		*/
		Long m_backColor;
		/*
		* ����ɫ
		*/
		Long m_borderColor;
		/*
		* K��ͼ
		*/
		FCChart *m_chart;
		/*
		* ʮ����
		*/
		CrossLine *m_crossLine;
		/*
		* ����
		*/
		FCFont *m_font;
		/*
		* ����������
		*/
		ScaleGrid *m_hGrid;
		/*
		* ����
		*/
		HScale *m_hScale;
		/*
		* ��������
		*/
		VScale *m_leftVScale;
		/*
		* λ��
		*/
		FCPoint m_location;
		/*
		* ����
		*/
		String m_name;
		/*
		* ���߹���
		*/
		ArrayList<FCPlot*> m_plots;
		/*
		* �Ҳ������
		*/
		VScale *m_rightVScale;
		/*
		* ѡ������
		*/
		SelectArea *m_selectArea;
		/*
		* �Ƿ�ѡ��
		*/
		bool m_selected;
		/*
		* ͼ��
		*/
		ArrayList<BaseShape*> m_shapes;
		/*
		* ��ʾѡ��
		*/
		bool m_showSelect;
		/*
		* ��С
		*/
		FCSize m_size;
		/*
		* ������
		*/
		ChartTitleBar *m_title;
		/*
		* ��ʾ��ǩ
		*/
		ChartToolTip *m_toolTip;
		/*
		* ����ٷֱ�
		*/
		int m_verticalPercent;
		/*
		* ����������
		*/
		ScaleGrid *m_vGrid;
		/*
		* �������ĸ߶�
		*/
		int m_workingAreaHeight;
	public:
		/*
		* ͼ������
		*/
		static bool shapesAsc(BaseShape *x, BaseShape *y);
		/*
		* ͼ�ν���
		*/
		static bool shapesDesc(BaseShape *x, BaseShape *y);
		/*
		* ���߹�������
		*/
		static bool plotsAsc(FCPlot *x, FCPlot *y);
		/*
		* ���߹��߽���
		*/
		static bool plotsDesc(FCPlot *x, FCPlot *y);
	public:
		/*
		* ����ͼ��
		*/
		ChartDiv();
		/*
		* ��������
		*/
		virtual ~ChartDiv();
		/*
		* ��ȡ�Ƿ������û���ͼ
		*/
		virtual bool allowUserPaint();
		/*
		* �����Ƿ������û���ͼ
		*/
		virtual void setAllowUserPaint(bool value);
		/*
		* ��ȡ����ɫ
		*/
		virtual Long getBackColor();
		/*
		* ���ñ���ɫ
		*/
		virtual void setBackColor(Long value);
		/*
		* ��ȡ����ɫ
		*/
		virtual Long getBorderColor();
		/*
		* ���ñ���ɫ
		*/
		virtual void setBorderColor(Long value);
		/*
		* ��ȡ�����²��λ��
		*/
		virtual int getBottom();
		/*
		* ��ȡ�������
		*/
		virtual FCRect getBounds();
		/*
		* ���ò������
		*/
		virtual void setBounds(FCRect value);
		/*
		* ��ȡʮ����
		*/
		virtual CrossLine* getCrossLine();
		/*
		* ����ʮ����
		*/
		virtual void setCrossLine(CrossLine *value);
		/*
		* ��ȡ����
		*/
		virtual FCFont* getFont();
		/*
		* ��������
		*/
		virtual void setFont(FCFont *value);
		/*
		* ��ȡ�߶�
		*/
		virtual int getHeight();
		/*
		* ��ȡ����������
		*/
		virtual ScaleGrid* getHGrid();
		/*
		* ���ú���������
		*/
		virtual void setHGrid(ScaleGrid *value);
		/*
		* ��ȡ����
		*/
		virtual HScale* getHScale();
		/*
		* ���ú���
		*/
		virtual void setHScale(HScale *value);
		/*
		* ��ȡK��ͼ
		*/
		virtual FCChart* getChart();
		/*
		* ����K��ͼ
		*/
		virtual void setChart(FCChart *value);
		/*
		* ��ȡ���ľ���
		*/
		virtual int getLeft();
		/*
		* ��ȡ��������
		*/
		virtual VScale* getLeftVScale();
		/*
		* ������������
		*/
		virtual void setLeftVScale(VScale *value);
		/*
		* ��ȡλ��
		*/
		virtual FCPoint getLocation();
		/*
		* ��ȡ����
		*/
		virtual String getName();
		/*
		* ��������
		*/ 
		virtual void setName(String value);
		/*
		* ��ȡ�����Ҳ�ľ���
		*/
		virtual int getRight();
		/*
		* ��ȡ�Ҳ������
		*/
		virtual VScale* getRightVScale();
		/*
		* �����Ҳ������
		*/
		virtual void setRightVScale(VScale *value);
		/*
		* ��ȡѡ������
		*/
		virtual SelectArea* getSelectArea();
		/*
		* ����ѡ������
		*/
		virtual void setSelectArea(SelectArea *value);
		/*
		* ��ȡ�Ƿ�ѡ��
		*/
		virtual bool isSelected();
		/*
		* �����Ƿ�ѡ��
		*/
		virtual void setSelected(bool value);
		/*
		* ��ȡ�Ƿ�Ҫ��ʾѡ��
		*/
		virtual bool isShowSelect();
		/*
		* �����Ƿ�Ҫ��ʾѡ��
		*/
		virtual void setShowSelect(bool value);
		/*
		* ��ȡ������
		*/
		virtual ChartTitleBar* getTitleBar();
		/*
		* ���ñ�����
		*/
		virtual void setTitleBar(ChartTitleBar *value);
		/*
		* ��ȡ��ʾ��ǩ
		*/
		virtual ChartToolTip* getToolTip();
		/*
		* ������ʾ��ǩ
		*/
		virtual void setToolTip(ChartToolTip *value);
		/*
		* ��ȡ���붥���ľ���
		*/
		virtual int getTop();
		/*
		* ��ȡ����ٷֱ�
		*/
		virtual int getVerticalPercent();
		/*
		* ��������ٷֱ�
		*/
		virtual void setVerticalPercent(int value);
		/*
		* ��ȡ����������
		*/
		virtual ScaleGrid* getVGrid();
		/*
		* ��������������
		*/
		virtual void setVGrid(ScaleGrid *value);
		/*
		* ��ȡ���
		*/
		virtual int getWidth();
		/*
		* ��ȡ�������ĸ߶�
		*/
		virtual int getWorkingAreaHeight();
		/*
		* ���ù������ĸ߶�
		*/
		virtual void setWorkingAreaHeight(int value);
	public:
		/**
         * ��ӻ���
         * @param plot ����
        */
		void addPlot(FCPlot *plot);
		/**
         * ���ͼ��
         * @param shape ͼ��
        */
		void addShape(BaseShape *shape);
		/**
         * �Ƿ����ͼ��
         * @param shape ͼ��
        */
		bool containsShape(BaseShape *shape);
		/**
         * ��ȡ���ߵļ���
         * @param sortType ��������
        */
		ArrayList<FCPlot*> getPlots(SortType sortType);
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
		/*
		* �������ƻ�ȡͼ��
		*/
		virtual BaseShape* getShape(String name);
		/**
         * ��ȡͼ�εļ���
         * @param sortType ��������
        */
		virtual ArrayList<BaseShape*> getShapes(SortType sortType);
		/**
         * ��ȡ����
         * @param attachVScale �����Ҳ�
        */
		virtual VScale* getVScale(AttachVScale attachVScale);
		/**
         * �ػ淽��
         * @param paint  ��ͼ����
         * @param rect ����
        */
		virtual void onPaint(FCPaint *paint, const FCRect& rect);
		/*
		* ��������
		*/
		virtual void onScaling(double scaleFactorX, double scaleFactorY);
		/**
		 * �Ƴ�����
		 * @param plot ����
        */
		void removePlot(FCPlot *plot);
		/**
         * �Ƴ�ͼ��
         * @param shape ͼ��
        */
		void removeShape(BaseShape *shape);
		/**
         * ��������
         * @param name  ��������
         * @param value ����ֵ
        */
		virtual void setAttribute(const String& name, const String& value);
	};
}