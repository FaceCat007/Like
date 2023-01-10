/*
 * FaceCatͼ��ͨѶ���(�ǿ�Դ)
 * ����Ȩ���:2015SR229355+2020SR0266727
 * �Ϻ����è��Ϣ�������޹�˾
 */

#ifdef __GDIPAINT_H__
#else                                                                            
#define __GDIPAINT_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include <comdef.h>
#pragma comment(lib, "gdiplus.lib")
#include "gdiplus.h"
using namespace Gdiplus;
#include "FCPaint.h"

namespace FaceCat{
	/*
	* GDI��ͼ
	*/
	class __GDIPAINT_H__ GdiPaint:public FCPaint{
	public:
		Graphics *m_g;
		HDC m_hDC;
		HRGN m_hRgn;
		map<String, Bitmap*> m_images;
		int m_offsetX;
		int m_offsetY;
		FCRect m_pRect;
		HBITMAP m_memBM;
		String m_resourcePath;
		int m_rotateAngle;
		double m_scaleFactorX;
		double m_scaleFactorY;
		HDC m_wndHDC;
		FCRect m_wRect;
		/*
		* ��������
		*/
		void affectScaleFactor(FCRect *rect);
	public:
		/*
		* ���캯��
		*/ 
		GdiPaint();
		/*
		* ��������
		*/
		virtual ~GdiPaint();
	public:
	    /**
         * �������
         * @param  rect ��������
         * @param startAngle �� x �ᵽ���ߵ���ʼ����˳ʱ�뷽������Ľǣ��Զ�Ϊ��λ��
         * @param sweepAngle �� startAngle ���������ߵĽ�������˳ʱ�뷽������Ľǣ��Զ�Ϊ��λ��
        */
		virtual void addArc(const FCRect& rect, float startAngle, float sweepAngle);
        /**
         * ��ӱ���������
         * @param  point1  ����1
         * @param  point2  ����2
         * @param  point3  ����3
         * @param  point4  ����4
        */
		virtual void addBezier(FCPoint *apt, int cpt);
	    /**
         * �������
         * @param  points  ����
        */
		virtual void addCurve(FCPoint *apt, int cpt);
	    /**
         * �����Բ
         * @param  rect ����
        */
		virtual void addEllipse(const FCRect& rect);
	    /**
         * ���ֱ��
         * @param  x1 ��һ����ĺ�����
         * @param  y1 ��һ�����������
         * @param  x2 �ڶ�����ĺ�����
         * @param  y2 �ڶ������������
        */
		virtual void addLine(int x1, int y1, int x2, int y2);
	    /**
         * ��Ӿ���
         * @param  rect ����
        */
		virtual void addRect(const FCRect& rect);
	    /**
         * �������
         * @param  rect ��������
         * @param startAngle �� x �ᵽ���ߵ���ʼ����˳ʱ�뷽������Ľǣ��Զ�Ϊ��λ��
         * @param sweepAngle �� startAngle ���������ߵĽ�������˳ʱ�뷽������Ľǣ��Զ�Ϊ��λ��
        */
		virtual void addPie(const FCRect& rect, float startAngle, float sweepAngle);
	    /**
         * �������
         * @param  text ����
         * @param  font ����
         * @param  rect ����
        */
		virtual void addText(String strText, FCFont *font, const FCRect& rect, int width);
		/*
		* ��ʼ����
		*/
		virtual void beginExport(const String& exportPath, const FCRect& rect);
	    /**
         * ��ʼ��ͼ
         * @param hdc  HDC
         * @param wRect ��������
         * @param pRect ˢ������
        */
		virtual void beginPaint(HDC hDC, const FCRect& wRect, const FCRect& pRect);
		/**
		 * ��ʼһ��·��
		 */
		virtual void beginPath();
		/**
		 * �������
		 */
		virtual void clearCaches();
		/**
		 * �ü�·��
		 */
		virtual void clipPath();
		/**
		 * �պ�·��
		 */
		virtual void closeFigure();
		/**
		 * ����һ��·��
		 */
		virtual void closePath();
	    /**
         * ���ƻ���
         * @param  dwPenColor ��ɫ
         * @param  width  ���
         * @param  style  ��ʽ
         * @param  rect   ��������
         * @param  startAngle  �� x �ᵽ���ߵ���ʼ����˳ʱ�뷽������Ľǣ��Զ�Ϊ��λ��
         * @param sweepAngle   �� startAngle ���������ߵĽ�������˳ʱ�뷽������Ľǣ��Զ�Ϊ��λ��
        */
		virtual void drawArc(Long dwPenColor, float width, int style, const FCRect& rect, float startAngle, float sweepAngle);
	    /**
         * ���ñ���������
         * @param  dwPenColor ��ɫ
         * @param  width  ���
         * @param  style  ��ʽ
         * @param points  ������
        */
		virtual void drawBezier(Long dwPenColor, float width, int style, FCPoint *apt, int cpt);
	    /**
         * ��������
         * @param  dwPenColor ��ɫ
         * @param  width  ���
         * @param  style  ��ʽ
         * @param points  ������
        */
		virtual void drawCurve(Long dwPenColor, float width, int style, FCPoint *apt, int cpt);
	    /**
         * ���ƾ���
         * @param  dwPenColor ��ɫ
         * @param  width  ���
         * @param  style  ��ʽ
         * @param  rect   ��������
        */
		virtual void drawEllipse(Long dwPenColor, float width, int style, const FCRect& rect);
	    /**
         * ���ƾ���
         * @param  dwPenColor ��ɫ
         * @param  width  ���
         * @param  style  ��ʽ
         * @param  left �������
         * @param  top  �������
         * @param  right �Ҳ�����
         * @param  bottom  �ײ�����
        */
		virtual void drawEllipse(Long dwPenColor, float width, int style, int left, int top, int right, int bottom);
	    /**
         * ����ͼƬ
         * @param  imagePath  ͼƬ·��
         * @param  rect   ��������
        */
		virtual void drawImage(String imagePath, const FCRect& rect);
	    /**
         * ����ֱ��
         * @param  dwPenColor ��ɫ
         * @param  width  ���
         * @param  style  ��ʽ
         * @param  x1 ��һ����ĺ�����
         * @param  y1 ��һ�����������
         * @param  x2 �ڶ�����ĺ�����
         * @param  y2 �ڶ������������
        */
		virtual void drawLine(Long dwPenColor, float width, int style, const FCPoint& x, const FCPoint& y);
	    /**
         * ����ֱ��
         * @param  dwPenColor ��ɫ
         * @param  width  ���
         * @param  style  ��ʽ
         * @param  x ��һ��������
         * @param  y �ڶ����������
        */
		virtual void drawLine(Long dwPenColor, float width, int style, int x1, int y1, int x2, int y2);
	    /**
         * ����·��
         * @param  dwPenColor ��ɫ
         * @param  width  ���
         * @param  style  ��ʽ
        */
		virtual void drawPath(Long dwPenColor, float width, int style);
	    /**
         * ���ƻ���
         * @param  dwPenColor ��ɫ
         * @param  width  ���
         * @param  style  ��ʽ
         * @param  rect   ��������
         * @param  startAngle  �� x �ᵽ���ߵ���ʼ����˳ʱ�뷽������Ľǣ��Զ�Ϊ��λ��
         * @param sweepAngle   �� startAngle ���������ߵĽ�������˳ʱ�뷽������Ľǣ��Զ�Ϊ��λ��
        */
		virtual void drawPie(Long dwPenColor, float width, int style, const FCRect& rect, float startAngle, float sweepAngle);
	    /**
         * ���ƶ����
         * @param  dwPenColor ��ɫ
         * @param  width  ���
         * @param  style  ��ʽ
         * @param  points  �������
        */
		virtual void drawPolygon(Long dwPenColor, float width, int style, FCPoint *apt, int cpt);
	    /**
         * ���ƴ���ֱ��
         * @param  dwPenColor ��ɫ
         * @param  width  ���
         * @param  style  ��ʽ
         * @param  points  �㼯
        */
		virtual void drawPolyline(Long dwPenColor, float width, int style, FCPoint *apt, int cpt);
	    /**
         * ���ƾ���
         * @param  dwPenColor ��ɫ
         * @param  width  ���
         * @param  style  ��ʽ
         * @param  rect   ��������
        */
		virtual void drawRect(Long dwPenColor, float width, int style, int left, int top, int right, int bottom);
	    /**
         * ���ƾ���
         * @param  dwPenColor ��ɫ
         * @param  width  ���
         * @param  style  ��ʽ
         * @param  left �������
         * @param  top  �������
         * @param  right �Ҳ�����
         * @param  bottom  �ײ�����
        */
		virtual void drawRect(Long dwPenColor, float width, int style, const FCRect& rect);
	    /**
         * ����Բ�Ǿ���
         * @param  dwPenColor ��ɫ
         * @param  width  ���
         * @param  style  ��ʽ
         * @param  rect   ��������
         * @param  cornerRadius �߽ǰ뾶
        */
		virtual void drawRoundRect(Long dwPenColor, float width, int style, const FCRect& rect, int cornerRadius);
	    /**
         * ���ƾ���
         * @param  text   ����
         * @param  dwPenColor ��ɫ
         * @param  font   ����
         * @param  rect   ��������
        */
		virtual void drawText(String strText, Long dwPenColor, FCFont *font, const FCRect& rect, int width);
	    /**
         * ���ƾ���
         * @param  text   ����
         * @param  dwPenColor ��ɫ
         * @param  font   ����
         * @param  rect   ��������
        */
		virtual void drawText(String strText, Long dwPenColor, FCFont *font, const FCRectF& rect, int width);
	    /**
         * �����Զ�ʡ�Խ�β������
         * @param  text   ����
         * @param  dwPenColor ��ɫ
         * @param  font   ����
         * @param  rect   ��������
        */
		virtual void drawTextAutoEllipsis(String strText, Long dwPenColor, FCFont *font, const FCRect& rect);
		/*
		* ��������
		*/
		virtual void endExport();
		/**
		 * ��������
		 */
		virtual void endPaint();
		/**
		 * ������ͼ
		 */
		virtual void excludeClipPath();
	    /**
         * �����Բ
         * @param  dwPenColor ��ɫ
         * @param  rect   ��������
        */
		virtual void fillEllipse(Long dwPenColor, const FCRect& rect);
	    /**
         * ���ƽ�����Բ
         * @param  dwFirst  ��ʼ��ɫ
         * @param  dwSecond ������ɫ
         * @param  rect     ����
         * @param  angle    �Ƕ�
        */
		virtual void fillGradientEllipse(Long dwFirst, Long dwSecond, const FCRect& rect, int angle);
	    /**
         * ��佥��·��
         * @param  dwFirst  ��ʼ��ɫ
         * @param  dwSecond ������ɫ
         * @param  points   ��ļ���
         * @param  angle    �Ƕ�
        */
		virtual void fillGradientPath(Long dwFirst, Long dwSecond, const FCRect& rect, int angle);
	    /**
         * ���ƽ���Ķ����
         * @param  dwFirst  ��ʼ��ɫ
         * @param  dwSecond ������ɫ
         * @param  points   ��ļ���
         * @param  angle    �Ƕ�
        */
		virtual void fillGradientPolygon(Long dwFirst, Long dwSecond, FCPoint *apt, int cpt, int angle);
	    /**
         * ���ƽ������
         * @param  dwFirst  ��ʼ��ɫ
         * @param  dwSecond ������ɫ
         * @param  rect     ����
         * @param  cornerRadius     Բ�ǰ뾶
         * @param  angle    �Ƕ�
        */
		virtual void fillGradientRect(Long dwFirst, Long dwSecond, const FCRect& rect, int cornerRadius, int angle);
	    /**
         * ���·��
         * @param  dwPenColor ��ɫ
        */
		virtual void fillPath(Long dwPenColor);
	    /**
         * ��������
         * @param  dwPenColor ��ɫ
         * @param  rect   ��������
         * @param  startAngle  �� x �ᵽ���ߵ���ʼ����˳ʱ�뷽������Ľǣ��Զ�Ϊ��λ��
         * @param sweepAngle   �� startAngle ���������ߵĽ�������˳ʱ�뷽������Ľǣ��Զ�Ϊ��λ��
        */
		virtual void fillPie(Long dwPenColor, const FCRect& rect, float startAngle, float sweepAngle);
	    /**
         * �����Բ
         * @param  dwPenColor ��ɫ
         * @param  points     �������
        */
		virtual void fillPolygon(Long dwPenColor, FCPoint *apt, int cpt);
	    /**
         * ������
         * @param  dwPenColor ��ɫ
         * @param  rect   ��������
        */
		virtual void fillRect(Long dwPenColor, const FCRect& rect);
	    /**
         * ������
         * @param  text   ����
         * @param  dwPenColor ��ɫ
         * @param  font   ����
         * @param  rect   ��������
        */
		virtual void fillRect(Long dwPenColor, int left, int top, int right, int bottom);
	    /**
         * ���Բ�Ǿ���
         * @param  dwPenColor ��ɫ
         * @param  rect   ��������
         * @param  cornerRadius �߽ǰ뾶
        */
		virtual void fillRoundRect(Long dwPenColor, const FCRect& rect, int cornerRadius);
	    /**
         * ��ȡ��ɫ
         * @param  dwPenColor ������ɫ
         * @returns   �����ɫ
        */
		virtual Long getColor(Long dwPenColor);
	    /**
         * ��ȡҪ���Ƶ���ɫ
         * @param  dwPenColor ������ɫ
         * @returns   �����ɫ
        */
		virtual Long getPaintColor(Long dwPenColor);
		/**
		 * ��ȡƫ��
		 */
		virtual FCPoint getOffset();
		/**
		* ��ȡ���ű���
		* @param scaleFactorX �������ű���
		* @param scaleFactorY �������ű���
		*/
		virtual void getScaleFactor(double *scaleFactorX, double *scaleFactorY);
	    /**
         * ��ת�Ƕ�
         * @param  op   Բ������
         * @param  mp   �������
         * @param  angle  �Ƕ�
         * @returns  �������
        */
		virtual FCPoint rotate(const FCPoint& op, const FCPoint& mp, int angle);
	    /**
         * ���òü�����
         * @param  rect   ����
        */
		virtual void setClip(const FCRect& rect);
	    /**
         * ����ֱ�����˵���ʽ
         * @param  startLineCap  ��ʼ����ʽ
         * @param  endLineCap  ��������ʽ
        */
		virtual void setLineCap(int startLineCap, int endLineCap);
	    /**
         * ����ƫ��
         * @param  mp  ƫ������
        */
		virtual void setOffset(const FCPoint& offset);
	    /**
         * ����͸����
         * @param  opacity  ͸����
        */
		virtual void setOpacity(float opacity);
	    /**
         * ������Դ��·��
         * @param  resourcePath  ��Դ��·��
        */
        virtual void setResourcePath(const String& resourcePath);
        /**
         * ������ת�Ƕ�
         * @param  rotateAngle  ��ת�Ƕ�
        */
		virtual void setRotateAngle(int rotateAngle);
	    /**
         * ������������
         * @param  scaleFactorX   ��������
         * @param  scaleFactorY   ��������
        */
		virtual void setScaleFactor(double scaleFactorX, double scaleFactorY);
	    /**
         * �����Ƿ�֧��͸��ɫ
         * @returns  �Ƿ�֧��
        */
		virtual bool supportTransparent();
	    /**
         * ��ȡ���ִ�С
         * @param  text   ����
         * @param  font   ����
		 * @param  width   �ַ������
         * @returns  �����С
        */
		virtual FCSize textSize(String strText, FCFont *font, int width);
	    /**
         * ��ȡ���ִ�С
         * @param  text   ����
         * @param  font   ����
		 * @param  width   �ַ������
         * @returns  �����С
        */
		virtual FCSizeF textSizeF(String strText, FCFont *font, int width);
	};
}