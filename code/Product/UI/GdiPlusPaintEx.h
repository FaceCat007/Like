/*����FaceCat(����è)��� v1.0
 �Ϻ����è��Ϣ�������޹�˾
 */

#ifndef __GDIPLUSPAINTEX_H__
#define __GDIPLUSPAINTEX_H__
#pragma once
#include "..\\..\\stdafx.h"
#include "FCDraw.h"

class CloudInfo {
public:
    String m_type;
    String m_color;
    String m_font;
    float m_lineWidth;
    int m_param1;
    int m_param2;
    int m_param3;
    int m_param4;
    String m_str;
public:
	CloudInfo(){
		m_lineWidth = 1;
		m_param1 = 0;
		m_param2 = 0;
		m_param3 = 0;
		m_param4 = 0;
	}
};

class GdiPlusPaintEx : public FCPaint {
public:
	Bitmap *m_bitmap;
	SolidBrush *m_brush;
	Long m_brushColor;
	StringFormat *m_emptyStringFormat;
	int m_endLineCap;
	wstring m_exportPath;
	Graphics *m_g;
	HDC m_hDC;
	map<wstring, Bitmap*> m_images;
	MyColor *m_myColor;
	int m_offsetX;
	int m_offsetY;
	float m_opacity;
	GraphicsPath *m_path;
	Pen *m_pen;
	FCRect m_pRect;
	Long m_penColor;
	float m_penWidth;
	int m_penStyle;
	wstring m_resourcePath;
	int m_rotateAngle;
	double m_scaleFactorX;
	double m_scaleFactorY;
	int m_startLineCap;
	FCRect m_wRect;
protected:
	void affectScaleFactor(Rect *gdiplusRect);
	void affectScaleFactor(RectF *gdiplusRect);
	SolidBrush* getBrush(Long dwPenColor);
	Color getGdiPlusColor(Long dwPenColor);
	int getEncoderClsid(const WCHAR *format, CLSID *pClsid);
	Gdiplus::Font* getFont(FCFont *font);
	Pen* getPen(Long dwPenColor, float width, int style);
	GraphicsPath* getRoundRectPath(Rect gdiPlusRect, int cornerRadius);
public:
	GdiPlusPaintEx();
	virtual ~GdiPlusPaintEx();
	vector<CloudInfo> m_cloudInfos;
	DWORD m_startTime;
	bool m_useCloud;
public:
	virtual void addArc(const FCRect& rect, float startAngle, float sweepAngle);
	virtual void addBezier(FCPoint *apt, int cpt);
	virtual void addCurve(FCPoint *apt, int cpt);
	virtual void addEllipse(const FCRect& rect);
	virtual void addLine(int x1, int y1, int x2, int y2);
	virtual void addRect(const FCRect& rect);
	virtual void addPie(const FCRect& rect, float startAngle, float sweepAngle);
	virtual void addText(String strText, FCFont *font, const FCRect& rect, int width);
	virtual void beginExport(const wstring& exportPath, const FCRect& rect);
	virtual void beginPaint(HDC hDC, const FCRect& wRect, const FCRect& pRect);
	virtual void beginPath();
	virtual void clipPath();
	virtual void clearCaches();
	virtual void closeFigure();
	virtual void closePath();
	virtual void drawArc(Long dwPenColor, float width, int style, const FCRect& rect, float startAngle, float sweepAngle);
	virtual void drawBezier(Long dwPenColor, float width, int style, FCPoint *apt, int cpt);
	virtual void drawCurve(Long dwPenColor, float width, int style, FCPoint *apt, int cpt);
	virtual void drawDotLine(Long dwPenColor, const FCPoint& p1, const FCPoint& p2);
	virtual void drawDotLine(Long dwPenColor, int x1, int y1, int x2, int y2);
	virtual void drawEllipse(Long dwPenColor, float width, int style, const FCRect& rect);
	virtual void drawEllipse(Long dwPenColor, float width, int style, int left, int top, int right, int bottom);
	virtual void drawImage(String imagePath, const FCRect& rect);
	virtual void drawLine(Long dwPenColor, float width, int style, const FCPoint& x, const FCPoint& y);
	virtual void drawLine(Long dwPenColor, float width, int style, int x1, int y1, int x2, int y2);
	virtual void drawPath(Long dwPenColor, float width, int style);
	virtual void drawPie(Long dwPenColor, float width, int style, const FCRect& rect, float startAngle, float sweepAngle);
	virtual void drawPolygon(Long dwPenColor, float width, int style, FCPoint *apt, int cpt);
	virtual void drawPolyline(Long dwPenColor, float width, int style, FCPoint *apt, int cpt);
	virtual void drawRect(Long dwPenColor, float width, int style, int left, int top, int right, int bottom);
	virtual void drawRect(Long dwPenColor, float width, int style, const FCRect& rect);
	virtual void drawRoundRect(Long dwPenColor, float width, int style, const FCRect& rect, int cornerRadius);
	virtual void drawText(String strText, Long dwPenColor, FCFont *font, const FCRect& rect, int width);
	virtual void drawText(String strText, Long dwPenColor, FCFont *font, const FCRectF& rect, int width);
	//�����е�Ӱ������
	virtual void drawTextEx(String strText, Long dwPenColor, FCFont *font, const FCRect& rect, int width);
	virtual void drawTextAutoEllipsis(String strText, Long dwPenColor, FCFont *font, const FCRect& rect);
	virtual void endExport();
	virtual void endPaint();
	virtual void excludeClipPath();
	virtual void fillEllipse(Long dwPenColor, const FCRect& rect);
	virtual void fillGradientEllipse(Long dwFirst, Long dwSecond, const FCRect& rect, int angle);
	virtual void fillGradientPath(Long dwFirst, Long dwSecond, const FCRect& rect, int angle);
	virtual void fillGradientPolygon(Long dwFirst, Long dwSecond, FCPoint *apt, int cpt, int angle);
	virtual void fillGradientRect(Long dwFirst, Long dwSecond, const FCRect& rect, int cornerRadius, int angle);
	virtual void fillPath(Long dwPenColor);
	virtual void fillPie(Long dwPenColor, const FCRect& rect, float startAngle, float sweepAngle);
	virtual void fillPolygon(Long dwPenColor, FCPoint *apt, int cpt);
	virtual void fillRect(Long dwPenColor, const FCRect& rect);
	virtual void fillRect(Long dwPenColor, int left, int top, int right, int bottom);
	virtual void fillRoundRect(Long dwPenColor, const FCRect& rect, int cornerRadius);
	virtual Long getColor(Long dwPenColor);
	virtual Long getPaintColor(Long dwPenColor);
	virtual FCPoint getOffset();
	virtual void getScaleFactor(double *scaleFactorX, double *scaleFactorY);
	virtual FCPoint rotate(const FCPoint& op, const FCPoint& mp, int angle);
	virtual void setClip(const FCRect& rect);
	virtual void setLineCap(int startLineCap, int endLineCap);
	virtual void setOffset(const FCPoint& offset);
	virtual void setOpacity(float opacity);
    virtual void setResourcePath(const wstring& resourcePath);
	virtual void setRotateAngle(int rotateAngle);
	virtual void setScaleFactor(double scaleFactorX, double scaleFactorY);
	virtual bool supportTransparent();
	virtual FCSize textSize(String strText, FCFont *font, int width);
	virtual FCSizeF textSizeF(String strText, FCFont *font, int width);
};
#endif