/*
 * FaceCatͼ��ͨѶ���(�ǿ�Դ)
 * ����Ȩ���:2015SR229355+2020SR0266727
 * �Ϻ����è��Ϣ�������޹�˾
 */

#ifdef __PEXTEND_H__
#else                                                                            
#define __PEXTEND_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "FCPlot.h"
#include "FCPlot.h"

namespace FaceCat{
	class FCPlot;

	/**
     * ����³˹�ɲݲ�
     */
	class __PEXTEND_H__ AndrewSpitchfork : public FCPlot{
	public:
	    /**
	     * ����³˹�ɲݲ�
	     */
		AndrewSpitchfork();
		/**
	     * ��ȡ��������
	     */
		virtual ActionType getAction();
		/**
	     * ��ʼ������
	     */
		virtual bool onCreate(const FCPoint& mp);
		/**
	     * ��ʼ�ƶ����߹���
	     */
		virtual void onMoveStart();
		/**
	     * ����ͼ��ķ���
	     */
		virtual void onPaint(FCPaint *paint, HashMap<Integer,PlotMark*> *pList, Long lineColor);
	};

	class __PEXTEND_H__ AngleLine : public FCPlot{
	public:
	    /**
	     * �����Ƕ���
	     */
		AngleLine();
		/**
	     * ��ȡ��������
	     */
		virtual ActionType getAction();
		/**
	     * ��ʼ������
	     */
		virtual bool onCreate(const FCPoint& mp);
		/**
	     * ��ʼ�ƶ����߹���
	     */
		virtual void onMoveStart();
		/**
	     * ����ͼ��ķ���
	     */
		virtual void onPaint(FCPaint *paint, HashMap<Integer,PlotMark*> *pList, Long lineColor);
	};

	/**
     * ���Բ
     */
	class __PEXTEND_H__ CircumCircle:public FCPlot{
	public:
	    /**
	     * ���Բ
	     */
		CircumCircle();
		/**
	     * ��ȡ��������
	     */
		virtual ActionType getAction();
		/**
	     * ��ʼ������
	     */
		virtual bool onCreate(const FCPoint& mp);
		/**
	     * ��ʼ�ƶ����߹���
	     */
		virtual void onMoveStart();
		/**
	     * ����ͼ��ķ���
	     */
		virtual void onPaint(FCPaint *paint, HashMap<Integer,PlotMark*> *pList, Long lineColor);
	};

	/**
     * ��ͷ�߶�
     */
	class __PEXTEND_H__ ArrowSegment : public FCPlot{
	public:
	    /**
	     * ������ͷ�߶�
	     */
		ArrowSegment();
		/**
	     * ��ȡ��������
	     */
		virtual ActionType getAction();
		/**
	     * ��ʼ������
	     */
		virtual bool onCreate(const FCPoint& mp);
		/**
	     * ��ʼ�ƶ����߹���
	     */
		virtual void onMoveStart();
		/**
	     * ����ͼ��ķ���
	     */
		virtual void onPaint(FCPaint *paint, HashMap<Integer,PlotMark*> *pList, Long lineColor);
	};

	/**
     * �µ���ͷ
     */
	class __PEXTEND_H__ DownArrow:public FCPlot{
	public:
		/*
		* ��ȡ�µ���ͷ����
		*/
		FCRect getDownArrowRect(float x, float y, float width);
	public:
	    /**
	     * �����µ���ͷ
	     */
		DownArrow();
		/**
	     * ��ȡ��������
	     */
		virtual ActionType getAction();
		/**
	     * ��ʼ������
	     */
		virtual bool onCreate(const FCPoint& mp);
		/**
	     * ��ʼ�ƶ����߹���
	     */
		virtual void onMoveStart();
		/**
	     * ����ͼ��ķ���
	     */
		virtual void onPaint(FCPaint *paint, HashMap<Integer,PlotMark*> *pList, Long lineColor);
	};

	/**
     * �½�45����
     */
	class __PEXTEND_H__ DropLine : public FCPlot{
	public:
	    /**
	     *��ȡ����
	     */
		float* getDropLineParams(HashMap<Integer, PlotMark*> *pList);
	public:
	    /**
	     * �����½�45����
	     */
		DropLine();
		/**
	     * ��ȡ��������
	     */
		virtual ActionType getAction();
		/**
	     * ��ʼ������
	     */
		virtual bool onCreate(const FCPoint& mp);
		/**
	     * ��ʼ�ƶ����߹���
	     */
		virtual void onMoveStart();
		/**
	     * ����ͼ��ķ���
	     */
		virtual void onPaint(FCPaint *paint, HashMap<Integer,PlotMark*> *pList, Long lineColor);
	};

	/**
     * ��Բ
     */
	class __PEXTEND_H__ Ellipse:public FCPlot{
	public:
	    /**
	     * ��Բ
	     */
		Ellipse();
		/**
	     * ��ȡ��������
	     */
		virtual ActionType getAction();
		/**
	     * ��ʼ������
	     */
		virtual bool onCreate(const FCPoint& mp);
		/**
	     * ��ʼ�ƶ����߹���
	     */
		virtual void onMoveStart();
		/**
	     * ����ͼ��ķ���
	     */
		virtual void onPaint(FCPaint *paint, HashMap<Integer,PlotMark*> *pList, Long lineColor);
	};

	/**
     * 쳲�Բ
     */
	class __PEXTEND_H__ FiboEllipse:public FCPlot{
	public:
		ArrayList<float> m_values;
	public:
	    /**
	     * 쳲�Բ�Ĳ���
	     */
		float* fibonacciEllipseParam(HashMap<Integer, PlotMark*> *pList, int *length);
	public:
	    /**
	     * ����쳲�Բ
	     */
		FiboEllipse();
		/**
	     * ��ȡ��������
	     */
		virtual ActionType getAction();
		/**
	     * ��ʼ��ͼ��
	     */
		virtual bool onCreate(const FCPoint& mp);
		/**
	     * ��ʼ�ƶ����߹���
	     */
		virtual void onMoveStart();
		/**
	     * ����ͼ��Ĳ�Ӱ
	     */
		virtual void onPaintGhost(FCPaint *paint);
		/**
	     * ����ͼ��ķ���
	     */
		virtual void onPaint(FCPaint *paint, HashMap<Integer,PlotMark*> *pList, Long lineColor);
	};

	/**
     * 쳲�����
     */
	class __PEXTEND_H__ FiboFanline:public FCPlot{
	public:
	    /**
	     * 쳲�����
	     */
		FiboFanline();
		/**
	     * ��ȡ��������
	     */
		virtual ActionType getAction();
		/**
	     * ��ʼ������
	     */
		virtual bool onCreate(const FCPoint& mp);
		/**
	     * ��ʼ�ƶ����߹���
	     */
		virtual void onMoveStart();
		/**
	     * ����ͼ��Ĳ�Ӱ
	     */
		virtual void onPaintGhost(FCPaint *paint);
		/**
	     * ����ͼ��ķ���
	     */
		virtual void onPaint(FCPaint *paint, HashMap<Integer,PlotMark*> *pList, Long lineColor);
	};

	/**
     * 쳲�������
     */
	class __PEXTEND_H__ FiboTimeZone : public FCPlot{
	public:
	    /**
	     * ��ȡ쳲������ߵĲ���
	     */
		ArrayList<Integer> getFibonacciTimeZonesParam(HashMap<Integer,PlotMark*> *pList);
	public:
	    /**
	     * ����쳲�������
	     */
		FiboTimeZone();
		/**
	     * ��ȡ��������
	     */
		virtual ActionType getAction();
		/**
	     * ��ʼ������
	     */
		virtual bool onCreate(const FCPoint& mp);
		/**
	     * ��ʼ�ƶ����߹���
	     */
		virtual void onMoveStart();
		/**
	     * ����ͼ��ķ���
	     */
		virtual void onPaint(FCPaint *paint, HashMap<Integer,PlotMark*> *pList, Long lineColor);
	};

	/**
     * ������
     */
	class __PEXTEND_H__ GannBox : public FCPlot{
	public:
		FCPoint m_oppositePoint;
	public:
	    /**
	     * ������
	     */
		GannBox();
		/**
	     * ��ȡ��������
	     */
		virtual ActionType getAction();
		/**
	     * ��ȡѡ��״̬
	     */
		ActionType getClickStatus();
		/**
	     * ��ȡ���������Ҫ��
	     */
		FCPoint* getGannBoxPoints(float x1, float y1, float x2, float y2);
		/**
	     * ��ʼ������
	     */
		virtual bool onCreate(const FCPoint& mp);
		/**
	     * ��ʼ�ƶ����߹���
	     */
		virtual void onMoveStart();
		/**
	     * �ƶ�����
	     */
		virtual void onMoving();
		/**
	     * ����ͼ��Ĳ�Ӱ
	     */
		virtual void onPaintGhost(FCPaint *paint);
		/**
	     * ����ͼ��ķ���
	     */
		virtual void onPaint(FCPaint *paint, HashMap<Integer,PlotMark*> *pList, Long lineColor);
	};

	/**
     * ������
     */
	class __PEXTEND_H__ GannLine : public FCPlot{
	public:
	    /**
	     * ����������
	     */
		GannLine();
		/**
	     * ��ȡ��������
	     */
		virtual ActionType getAction();
		/**
	     * ��ʼ������
	     */
		virtual bool onCreate(const FCPoint& mp);
		/**
	     * ��ʼ�ƶ����߹���
	     */
		virtual void onMoveStart();
		/**
	     * ����ͼ��Ĳ�Ӱ
	     */
		virtual void onPaintGhost(FCPaint *paint);
		/**
	     * ����ͼ��ķ���
	     */
		virtual void onPaint(FCPaint *paint, HashMap<Integer,PlotMark*> *pList, Long lineColor);
	};

	/**
     * �ƽ�ָ���
     */
	class __PEXTEND_H__ GoldenRatio : public FCPlot{
	public:
		ArrayList<float> m_values;
	public:
	    /**
	     * �ƽ�ָ���
	     */
		GoldenRatio();
		/**
	     * ��ȡ��������
	     */
		virtual ActionType getAction();
		/**
		* ��ȡ�ƽ�ָ��ߵ�ֱ�߲���
		*/
		float* goldenRatioParams(double value1, double value2, int *length);
		/**
	     * ��ʼ������
	     */
		virtual bool onCreate(const FCPoint& mp);
		/**
	     * ��ʼ�ƶ����߹���
	     */
		virtual void onMoveStart();
		/*
		* �ƶ�����
		*/
		virtual void onMoving();
		/**
	     * ����ͼ��Ĳ�Ӱ
	     */
		virtual void onPaintGhost(FCPaint *paint);
		/**
	     * ����ͼ��ķ���
	     */
		virtual void onPaint(FCPaint *paint, HashMap<Integer,PlotMark*> *pList, Long lineColor);
	};

	class __PEXTEND_H__ HLine : public FCPlot{
	public:
	    /**
	     * ����ˮƽ��
	     */
		HLine();
		/**
	     * ��ȡ��������
	     */
		virtual ActionType getAction();
		/**
	     * ��ʼ������
	     */
		virtual bool onCreate(const FCPoint& mp);
		/**
	     * ��ʼ�ƶ����߹���
	     */
		virtual void onMoveStart();
		/**
	     * �ƶ�����
	     */
		virtual void onMoving();
		/**
	     * ����ͼ��ķ���
	     */
		virtual void onPaint(FCPaint *paint, HashMap<Integer,PlotMark*> *pList, Long lineColor);
	};

	/**
     * �ߵ��Ƶ�
     */
	class __PEXTEND_H__ LevelGrading : public FCPlot{
	public:
	    /**
	     * ��ȡ�ߵ��Ƶ���ֱ�߲���
	     */
		float* levelGradingParams(double value1, double value2);
	public:
	    /**
	     * �����ߵ��Ƶ�
	     */
		LevelGrading();
		/**
	     * ��ȡ��������
	     */
		virtual ActionType getAction();
		/**
	     * ��ʼ������
	     */
		virtual bool onCreate(const FCPoint& mp);
		/**
	     * ��ʼ�ƶ����߹���
	     */
		virtual void onMoveStart();
		/**
	     * �ƶ�����
	     */
		virtual void onMoving();
		/**
	     * ����ͼ��Ĳ�Ӱ
	     */
		virtual void onPaintGhost(FCPaint *paint);
		/**
	     * ����ͼ��ķ���
	     */
		virtual void onPaint(FCPaint *paint, HashMap<Integer,PlotMark*> *pList, Long lineColor);
	};

	/**
     * ֱ��
     */
	class __PEXTEND_H__ Line : public FCPlot{
	public:
	    /**
	     * ����ֱ��
	     */
		Line();
		/**
	     * ��ȡ��������
	     */
		virtual ActionType getAction();
		/**
	     * ��ʼ������
	     */
		virtual bool onCreate(const FCPoint& mp);
		/**
	     * ��ʼ�ƶ����߹���
	     */
		virtual void onMoveStart();
		/**
	     * ����ͼ��ķ���
	     */
		virtual void onPaint(FCPaint *paint, HashMap<Integer,PlotMark*> *pList, Long lineColor);
	};

	/**
     * ���Իع��
     */
	class __PEXTEND_H__ LrBand : public FCPlot{
	public:
	    /**
	     * �������Իع��
	     */
		LrBand();
		/**
	     * ��ȡ��������
	     */
		virtual ActionType getAction();
		/**
	     * ��ʼ������
	     */
		virtual bool onCreate(const FCPoint& mp);
		/**
	     * ��ʼ�ƶ����߹���
	     */
		virtual void onMoveStart();
		/**
	     * �ƶ�����
	     */
		virtual void onMoving();
		/**
	     * ����ͼ��ķ���
	     */
		virtual void onPaint(FCPaint *paint, HashMap<Integer,PlotMark*> *pList, Long lineColor);
	};

	 /**
     * �ع�ͨ��
     */
	class __PEXTEND_H__ LrChannel : public FCPlot{
	public:
	    /**
	     * �����ع�ͨ��
	     */
		LrChannel();
		/**
	     * ��ȡ��������
	     */
		virtual ActionType getAction();
		/**
	     * ��ʼ������
	     */
		virtual bool onCreate(const FCPoint& mp);
		/**
	     * ��ʼ�ƶ����߹���
	     */
		virtual void onMoveStart();
		/**
	     * �ƶ�����
	     */
		virtual void onMoving();
		/**
	     * ����ͼ��ķ���
	     */
		virtual void onPaint(FCPaint *paint, HashMap<Integer,PlotMark*> *pList, Long lineColor);
	};

	/**
     * ���Իع�
     */
	class __PEXTEND_H__ LrLine : public FCPlot{
	public:
	    /**
	     * �������Իع�
	     */
		LrLine();
		/**
	     * ��ȡ��������
	     */
		virtual ActionType getAction();
		/**
	     * ��ʼ������
	     */
		virtual bool onCreate(const FCPoint& mp);
		/**
	     * ��ʼ�ƶ����߹���
	     */
		virtual void onMoveStart();
		/**
	     * �ƶ�����
	     */
		virtual void onMoving();
		/**
	     * ����ͼ��ķ���
	     */
		virtual void onPaint(FCPaint *paint, HashMap<Integer,PlotMark*> *pList, Long lineColor);
	};

	/**
     * ������
     */
	class __PEXTEND_H__ NullPoint : public FCPlot{
	public:
	    /**
	     * ����������
	     */
		void nullPoint(float x1, float y1, float x2, float y2, float *nullX, float *nullY);
		/**
	     * ��ȡ������Ĳ���
	     */
		double* getNullPointParams(HashMap<Integer,PlotMark*> *pList);
	public:
	    /**
	     * ����������
	     */
		NullPoint();
		/**
	     * ��ȡ��������
	     */
		virtual ActionType getAction();
		/**
	     * ��ʼ������
	     */
		virtual bool onCreate(const FCPoint& mp);
		/**
	     * ��ʼ�ƶ����߹���
	     */
		virtual void onMoveStart();
		/**
	     * ����ͼ��ķ���
	     */
		virtual void onPaint(FCPaint *paint, HashMap<Integer,PlotMark*> *pList, Long lineColor);
	};

	/**
     * ƽ����
     */
	class __PEXTEND_H__ Parallel:public FCPlot{
	public:
	    /**
	     * ��ȡƽ��ֱ�ߵĲ���
	     */
		float* getParallelParams(HashMap<Integer,PlotMark*> *pList);
	public:
	    /**
	     * ����ƽ����
	     */
		Parallel();
		/**
	     * ��ȡ��������
	     */
		virtual ActionType getAction();
		/**
	     * ��ʼ������
	     */
		virtual bool onCreate(const FCPoint& mp);
		/**
	     * ��ʼ�ƶ����߹���
	     */
		virtual void onMoveStart();
		/**
	     * ����ͼ��ķ���
	     */
		virtual void onPaint(FCPaint *paint, HashMap<Integer,PlotMark*> *pList, Long lineColor);
	};

	/**
     * �ٷֱ���
     */
	class __PEXTEND_H__ Percent : public FCPlot{
	public:
		float* getPercentParams(double value1, double value2);
	public:
	    /**
	     * �����ٷֱ���
	     */
		Percent();
		/**
	     * ��ȡ��������
	     */
		virtual ActionType getAction();
		/**
	     * ��ʼ������
	     */
		virtual bool onCreate(const FCPoint& mp);
		/**
	     * ��ʼ�ƶ����߹���
	     */
		virtual void onMoveStart();
		/**
	     * �ƶ�����
	     */
		virtual void onMoving();
		/**
	     * ����ͼ��Ĳ�Ӱ
	     */
		virtual void onPaintGhost(FCPaint *paint);
		/**
	     * ����ͼ��ķ���
	     */
		virtual void onPaint(FCPaint *paint, HashMap<Integer,PlotMark*> *pList, Long lineColor);
	};

	/**
     * ������
     */
	class __PEXTEND_H__ Periodic : public FCPlot{
	public:
		int m_period;
		int m_beginPeriod;
	public:
	    /**
	     * ����������
	     */
		Periodic();
		/**
	     * ��ȡ��������
	     */
		virtual ActionType getAction();
		ArrayList<Double> getPLParams(HashMap<Integer,PlotMark*> *pList);
		/**
	     * ��ʼ������
	     */
		virtual bool onCreate(const FCPoint& mp);
		/**
	     * ��ʼ�ƶ����߹���
	     */
		virtual void onMoveStart();
		/**
	     * �ƶ�����
	     */
		virtual void onMoving();
		/**
	     * ����ͼ��ķ���
	     */
		virtual void onPaint(FCPaint *paint, HashMap<Integer,PlotMark*> *pList, Long lineColor);
	};

	/**
     * �۸�ǩ��
     */
	class __PEXTEND_H__ Price : public FCPlot{
	public:
		FCSize m_textSize;
	public:
	    /**
	     * �����۸�ǩ��
	     */
		Price();
		/**
	     * ��ȡ��������
	     */
		virtual ActionType getAction();
		/**
	     * ��ʼ������
	     */
		virtual bool onCreate(const FCPoint& mp);
		/**
	     * ��ʼ�ƶ����߹���
	     */
		virtual void onMoveStart();
		/**
	     * ����ͼ��ķ���
	     */
		virtual void onPaint(FCPaint *paint, HashMap<Integer,PlotMark*> *pList, Long lineColor);
	};


	/**
     * ����ǩ��
     */
	class __PEXTEND_H__ TextTip : public FCPlot{
	public:
		FCSize m_textSize;
	public:
	    /**
	     * �����۸�ǩ��
	     */
		TextTip();
		/**
	     * ��ȡ��������
	     */
		virtual ActionType getAction();
		/**
	     * ��ʼ������
	     */
		virtual bool onCreate(const FCPoint& mp);
		/**
	     * ��ʼ�ƶ����߹���
	     */
		virtual void onMoveStart();
		/**
	     * ����ͼ��ķ���
	     */
		virtual void onPaint(FCPaint *paint, HashMap<Integer,PlotMark*> *pList, Long lineColor);
	};


	/**
     * ���ȳ�
     */
	class __PEXTEND_H__ RangeRuler : public FCPlot{
	public:
	    /**
	     * �������ȳ�
	     */
		RangeRuler();
		/**
	     * ��ȡ��������
	     */
		virtual ActionType getAction();
		/**
	     * ��ʼ������
	     */
		virtual bool onCreate(const FCPoint& mp);
		/**
	     * ��ʼ�ƶ����߹���
	     */
		virtual void onMoveStart();
		/**
	     * ����ͼ��ķ���
	     */
		virtual void onPaint(FCPaint *paint, HashMap<Integer,PlotMark*> *pList, Long lineColor);
	};

	/**
     * ����45����
     */
	class __PEXTEND_H__ RaseLine : public FCPlot{
	public:
	    /**
	     * ��������45����
	     */
		RaseLine();
		float* getRaseLineParams(HashMap<Integer,PlotMark*> *pList);
		/**
	     * ��ȡ��������
	     */
		virtual ActionType getAction();
		/**
	     * ��ʼ������
	     */
		virtual bool onCreate(const FCPoint& mp);
		/**
	     * ��ʼ�ƶ����߹���
	     */
		virtual void onMoveStart();
		/**
	     * ����ͼ��ķ���
	     */
		virtual void onPaint(FCPaint *paint, HashMap<Integer,PlotMark*> *pList, Long lineColor);
	};

	/**
     * ����
     */
	class __PEXTEND_H__ Ray : public FCPlot{
	public:
	    /**
	     * ��������
	     */
		Ray();
		/**
	     * ��ȡ��������
	     */
		virtual ActionType getAction();
		/**
	     * ��ʼ������
	     */
		virtual bool onCreate(const FCPoint& mp);
		/**
	     * ��ʼ�ƶ����߹���
	     */
		virtual void onMoveStart();
		/**
	     * ����ͼ��ķ���
	     */
		virtual void onPaint(FCPaint *paint, HashMap<Integer,PlotMark*> *pList, Long lineColor);
	};

	/*
	* ������
	*/
	class __PEXTEND_H__ RectLine : public FCPlot{
	public:
		FCPoint m_oppositePoint;
	public:
		/*
		* ����������
		*/
		RectLine();
		/**
	     * ��ȡ��������
	     */
		virtual ActionType getAction();
		/**
	     * ��ʼ������
	     */
		virtual bool onCreate(const FCPoint& mp);
		/**
	     * ��ʼ�ƶ����߹���
	     */
		virtual void onMoveStart();
		/**
	     * �ƶ�����
	     */
		virtual void onMoving();
		/**
	     * ����ͼ��Ĳ�Ӱ
	     */
		virtual void onPaintGhost(FCPaint *paint);
		/**
	     * ����ͼ��ķ���
	     */
		virtual void onPaint(FCPaint *paint, HashMap<Integer,PlotMark*> *pList, Long lineColor);
	};

	/**
     * �߶�
     */
	class __PEXTEND_H__ Segment : public FCPlot{
	public:
	    /**
	     * �����߶�
	     */
		Segment();
		/**
	     * ��ȡ��������
	     */
		virtual ActionType getAction();
		/**
	     * ��ʼ������
	     */
		virtual bool onCreate(const FCPoint& mp);
		/**
	     * ��ʼ�ƶ����߹���
	     */
		virtual void onMoveStart();
		/**
	     * ����ͼ��ķ���
	     */
		virtual void onPaint(FCPaint *paint, HashMap<Integer,PlotMark*> *pList, Long lineColor);
	};

	/**
     * ������
     */
	class __PEXTEND_H__ Sine:public FCPlot{
	public:
	    /**
	     * ����������
	     */
		Sine();
		/**
	     * ��ȡ��������
	     */
		virtual ActionType getAction();
		/**
	     * ��ʼ������
	     */
		virtual bool onCreate(const FCPoint& mp);
		/**
	     * ��ʼ�ƶ����߹���
	     */
		virtual void onMoveStart();
		/**
	     * �ƶ�����
	     */
		virtual void onMoving();
		/**
	     * ����ͼ��ķ���
	     */
		virtual void onPaint(FCPaint *paint, HashMap<Integer,PlotMark*> *pList, Long lineColor);
	};

	/**
     * ������
     */
	class __PEXTEND_H__ SpeedResist : public FCPlot{
	public:
	    /**
	     * ����������
	     */
		SpeedResist();
		/**
	     * ��ȡ��������
	     */
		virtual ActionType getAction();
		/**
	     * ��ʼ������
	     */
		virtual bool onCreate(const FCPoint& mp);
		/**
	     * ��ʼ�ƶ����߹���
	     */
		virtual void onMoveStart();
		/**
	     * ����ͼ��Ĳ�Ӱ
	     */
		virtual void onPaintGhost(FCPaint *paint);
		/**
	     * ����ͼ��ķ���
	     */
		virtual void onPaint(FCPaint *paint, HashMap<Integer,PlotMark*> *pList, Long lineColor);
	};

	/**
     * ��׼���ͨ��
     */
	class __PEXTEND_H__ SeChannel : public FCPlot{
	public:
		double getSEChannelSD(HashMap<Integer,PlotMark*> *pList);
	public:
	    /**
	     * ������׼���ͨ��
	     */
		SeChannel();
		/**
	     * ��ȡ��������
	     */
		virtual ActionType getAction();
		/**
	     * ��ʼ������
	     */
		virtual bool onCreate(const FCPoint& mp);
		/**
	     * ��ʼ�ƶ����߹���
	     */
		virtual void onMoveStart();
		/**
	     * �ƶ�����
	     */
		virtual void onMoving();
		/**
	     * ����ͼ��ķ���
	     */
		virtual void onPaint(FCPaint *paint, HashMap<Integer,PlotMark*> *pList, Long lineColor);
	};

	/**
     * �Գ���
     */
	class __PEXTEND_H__ SymmetricLine : public FCPlot{
	public:
	    /**
	     * �����Գ���
	     */
		SymmetricLine();
		/**
	     * ��ȡ��������
	     */
		virtual ActionType getAction();
		/**
	     * ��ʼ������
	     */
		virtual bool onCreate(const FCPoint& mp);
		/**
	     * ��ʼ�ƶ����߹���
	     */
		virtual void onMoveStart();
		/**
	     * ����ͼ��ķ���
	     */
		virtual void onPaint(FCPaint *paint, HashMap<Integer,PlotMark*> *pList, Long lineColor);
	};

	/*
	* �Գ�������
	*/ 
	class __PEXTEND_H__ SymmetricTriangle : public FCPlot{
	public:
		float* getSymmetricTriangleParams(HashMap<Integer,PlotMark*> *pList);
	public:
		/*
		* �����Գ�������
		*/
		SymmetricTriangle();
		/**
	     * ��ȡ��������
	     */
		virtual ActionType getAction();
		/**
	     * ��ʼ������
	     */
		virtual bool onCreate(const FCPoint& mp);
		/**
	     * ��ʼ�ƶ����߹���
	     */
		virtual void onMoveStart();
		/**
	     * ����ͼ��ķ���
	     */
		virtual void onPaint(FCPaint *paint, HashMap<Integer,PlotMark*> *pList, Long lineColor);
	};

	/**
     * ʱ���
     */
	class __PEXTEND_H__ TimeRuler : public FCPlot{
	public:
		double* getTimeRulerParams(HashMap<Integer,PlotMark*> *pList);
	public:
	    /**
	     * ����ʱ���
	     */
		TimeRuler();
		/**
	     * ��ȡ��������
	     */
		virtual ActionType getAction();
		/**
	     * ��ʼ������
	     */
		virtual bool onCreate(const FCPoint& mp);
		/**
	     * ��ʼ�ƶ����߹���
	     */
		virtual void onMoveStart(); 
		/**
	     * �ƶ�����
	     */
		virtual void onMoving();
		/**
	     * ����ͼ��ķ���
	     */
		virtual void onPaint(FCPaint *paint, HashMap<Integer,PlotMark*> *pList, Long lineColor);
	};

	/**
     * ������
     */
	class __PEXTEND_H__ Triangle : public FCPlot{
	public:
	    /**
	     * ����������
	     */
		Triangle();
		/**
	     * ��ȡ��������
	     */
		virtual ActionType getAction();
		/**
	     * ��ʼ������
	     */
		virtual bool onCreate(const FCPoint& mp);
		/**
	     * ��ʼ�ƶ����߹���
	     */
		virtual void onMoveStart();
		/**
	     * ����ͼ��Ĳ�Ӱ
	     */
		virtual void onPaintGhost(FCPaint *paint);
		/**
	     * ����ͼ��ķ���
	     */
		virtual void onPaint(FCPaint *paint, HashMap<Integer,PlotMark*> *pList, Long lineColor);
	};

	 /**
     * ���Ǽ�ͷ
     */
	class __PEXTEND_H__ UpArrow:public FCPlot{
	public:
		FCRect getUpArrowRect(float x, float y, float width);
	public:
	    /**
	     * �������Ǽ�ͷ
	     */
		UpArrow();
		/**
	     * ��ȡ��������
	     */
		virtual ActionType getAction();
		/**
	     * ��ʼ������
	     */
		virtual bool onCreate(const FCPoint& mp);
		/**
	     * ��ʼ�ƶ����߹���
	     */
		virtual void onMoveStart();
		/**
	     * ����ͼ��ķ���
	     */
		virtual void onPaint(FCPaint *paint, HashMap<Integer,PlotMark*> *pList, Long lineColor);
	};

	 /**
     * ��ֱ��
     */
	class __PEXTEND_H__ VLine:public FCPlot{
	public:
	    /**
	     * ������ֱ��
	     */
		VLine();
		/**
	     * ��ȡ��������
	     */
		virtual ActionType getAction();
		/**
	     * ��ʼ������
	     */
		virtual bool onCreate(const FCPoint& mp);
		/**
	     * ��ʼ�ƶ����߹���
	     */
		virtual void onMoveStart();
		/**
	     * ����ͼ��ķ���
	     */
		virtual void onPaint(FCPaint *paint, HashMap<Integer,PlotMark*> *pList, Long lineColor);
	};

	/**
     * ���˳�
     */
	class __PEXTEND_H__ WaveRuler:public FCPlot{
	public:
		float* getWaveRulerParams(double value1, double value2);
	public:
	    /**
	     * �������˳�
	     */
		WaveRuler();
		/**
	     * ��ȡ��������
	     */
		virtual ActionType getAction();
		/**
	     * ��ʼ������
	     */
		virtual bool onCreate(const FCPoint& mp);
		/**
	     * ��ʼ�ƶ����߹���
	     */
		virtual void onMoveStart();
		/**
	     * ����ͼ��Ĳ�Ӱ
	     */
		virtual void onPaintGhost(FCPaint *paint);
		/**
	     * ����ͼ��ķ���
	     */
		virtual void onPaint(FCPaint *paint, HashMap<Integer,PlotMark*> *pList, Long lineColor);
	};

	/**
     * ̩��ˮƽ��
     */
	class __PEXTEND_H__ TironeLevels:public FCPlot{
	public:
		double* getTironelLevelsParams(HashMap<Integer,PlotMark*> *pList);
	public:
	    /**
	     * ����̩��ˮƽ��
	     */
		TironeLevels();
		/**
	     * ��ȡ��������
	     */
		virtual ActionType getAction();
		/**
	     * ��ʼ������
	     */
		virtual bool onCreate(const FCPoint& mp);
		/**
	     * ��ʼ�ƶ����߹���
	     */
		virtual void onMoveStart();
		/**
	     * ����ͼ��ķ���
	     */
		virtual void onPaint(FCPaint *paint, HashMap<Integer,PlotMark*> *pList, Long lineColor);
	};

	/**
     * �����ع�ͨ��
     */
	class __PEXTEND_H__ RaffChannel:public FCPlot{
	public:
		double getRRCRange(HashMap<Integer,PlotMark*> *pList, float *param);
	public:
	    /**
	     * ���������ع�ͨ��
	     */
		RaffChannel();
		/**
	     * ��ȡ��������
	     */
		virtual ActionType getAction();
		/**
	     * ��ʼ������
	     */
		virtual bool onCreate(const FCPoint& mp);
		/**
	     * ��ʼ�ƶ����߹���
	     */
		virtual void onMoveStart();
		/*
		* �ƶ�����
		*/
		virtual void onMoving();
		/**
	     * ����ͼ��ķ���
	     */
		virtual void onPaint(FCPaint *paint, HashMap<Integer,PlotMark*> *pList, Long lineColor);
	};

	/**
     * �ĵȷ���
     */
	class __PEXTEND_H__ QuadrantLines:public Percent{
	public:
	    /**
	     * �����ĵȷ���
	     */
		QuadrantLines();
		/**
	     * ��ȡ��������
	     */
		virtual ActionType getAction();
		/**
	     * ��ʼ������
	     */
		virtual bool onCreate(const FCPoint& mp);
		/**
	     * ��ʼ�ƶ����߹���
	     */
		virtual void onMoveStart();
		/**
	     * �ƶ�����
	     */
		virtual void onMoving();
		/**
	     * ����ͼ��ķ���
	     */
		virtual void onPaint(FCPaint *paint, HashMap<Integer,PlotMark*> *pList, Long lineColor);
	};

	/**
     * ������
     */
	class __PEXTEND_H__ BoxLine:public RectLine{
	public:
		/**
	     * ��ȡ��������
	     */
		ActionType getAction(const FCPoint& mp);
	public:
	    /**
	     * ����������
	     */
		BoxLine();
		/**
	     * ��ȡ��������
	     */
		virtual ActionType getAction();
		/**
	     * ��ʼ������
	     */
		virtual bool onCreate(const FCPoint& mp);
		/**
	     * ��ʼ�ƶ����߹���
	     */
		virtual void onMoveStart();
		/**
	     * �ƶ�����
	     */
		virtual void onMoving();
		/**
	     * ����ͼ��ķ���
	     */
		virtual void onPaint(FCPaint *paint, HashMap<Integer,PlotMark*> *pList, Long lineColor);
	};

	/*
	* ƽ����
	*/
	class __PEXTEND_H__ ParallelGram : public FCPlot{
	public:
		/*
		* ����ƽ����
		*/
		ParallelGram();
		/**
	     * ��ȡ��������
	     */
		virtual ActionType getAction();
		FCPoint* getPLPoints(HashMap<Integer,PlotMark*> *pList);
		/**
	     * ��ʼ������
	     */
		virtual bool onCreate(const FCPoint& mp);
		/**
	     * ��ʼ�ƶ����߹���
	     */
		virtual void onMoveStart();
		/**
	     * ����ͼ��Ĳ�Ӱ
	     */
		virtual void onPaintGhost(FCPaint *paint);
		/**
	     * ����ͼ��ķ���
	     */
		virtual void onPaint(FCPaint *paint, HashMap<Integer,PlotMark*> *pList, Long lineColor);
	};

	/**
     * Բ
     */
	class __PEXTEND_H__ Circle : public FCPlot{
	public:
	    /**
	     * ����Բ
	     */
		Circle();
		/**
	     * ��ȡ��������
	     */
		virtual ActionType getAction();
		/**
	     * ��ʼ������
	     */
		virtual bool onCreate(const FCPoint& mp);
		/**
	     * ��ʼ�ƶ����߹���
	     */
		virtual void onMoveStart();
		/**
	     * ����ͼ��ķ���
	     */
		virtual void onPaint(FCPaint *paint, HashMap<Integer,PlotMark*> *pList, Long lineColor);
	};

	/**
     * �۸�ͨ����
     */
	class __PEXTEND_H__ PriceChannel:public Parallel{
	public:
		void getLine3Params(HashMap<Integer,PlotMark*> *pList, float *k, float *d, float *x4);
		void paintEx(FCPaint *paint, HashMap<Integer,PlotMark*> *pList,Long lineColor);
	public:
	    /**
	     * �����۸�ͨ����
	     */
		PriceChannel();
		/**
	     * ��ȡ��������
	     */
		virtual ActionType getAction();
		/**
		* ��ȡ�ƽ�ָ��ߵ�ֱ�߲���
		*/
		float* goldenRatioParams(double value1, double value2, int *length);
		/**
	     * ��ʼ�ƶ����߹���
	     */
		virtual void onMoveStart();
		/**
	     * ����ͼ��ķ���
	     */
		virtual void onPaint(FCPaint *paint);
		/**
	     * ����ͼ��Ĳ�Ӱ
	     */
        virtual void onPaintGhost(FCPaint *paint);
	};

	/**
     * �ƽ�ָ��λ��
     */
	class __PEXTEND_H__ Gp:public FCPlot{
	public:
		ArrayList<float> m_values;
	public:
	    /**
	     * �����ƽ�ָ��λ��
	     */
		Gp();
		/**
	     * ��ȡ��������
	     */
		virtual ActionType getAction();
		/**
	     * ��ʼ������
	     */
		virtual bool onCreate(const FCPoint& mp);
		/**
	     * ��ʼ�ƶ����߹���
	     */
		virtual void onMoveStart();
		/*
		* �ƶ�����
		*/
		virtual void onMoving();
		/**
	     * ����ͼ��ķ���
	     */
		virtual void onPaint(FCPaint *paint, HashMap<Integer,PlotMark*> *pList, Long lineColor);
	};

	/**
     * �ƽ�ָ�Ŀ����
     */
	class __PEXTEND_H__ Ga:public Triangle{
	public:
		ArrayList<float> m_values;
	public:
		float* getGoldenRatioAimParams(HashMap<Integer,PlotMark*> *pList, int *length);
		/**
		* ��ȡ�ƽ�ָ��ߵ�ֱ�߲���
		*/
		float* goldenRatioParams(double value1, double value2, int *length);
	public:
	    /**
	     * �����ƽ�ָ�Ŀ����
	     */
		Ga();
		/**
	     * ��ȡ��������
	     */
		virtual ActionType getAction();
		/**
	     * ��ʼ�ƶ����߹���
	     */
		virtual void onMoveStart();
		/**
	     * ����ͼ��ķ���
	     */
		virtual void onPaint(FCPaint *paint, HashMap<Integer,PlotMark*> *pList, Long lineColor);
	};

	/*
	* ��������
	*/
	class __PEXTEND_H__ PFactory{
	public:
		/*
		* ��������
		*/
		static FCPlot* createPlot(const String& plotType);
	};
}