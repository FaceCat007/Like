/*
 * FaceCatͼ��ͨѶ���(�ǿ�Դ)
 * ����Ȩ���:2015SR229355+2020SR0266727
 * �Ϻ����è��Ϣ�������޹�˾
 */

#ifdef __ENUMS_H__
#else                                                                            
#define __ENUMS_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"

namespace FaceCat{
	/*
	* ��������
	*/
	enum _declspec(dllexport) ActionType{
		ActionType_AT1 = 1, //��һ����Ķ���
		ActionType_AT2 = 2, //�ڶ�����Ķ���
		ActionType_AT3 = 3, //��������Ķ���
		ActionType_AT4 = 4, //���ĸ���Ķ���
		ActionType_MOVE = 0, //�ƶ�
		ActionType_NO = -1 //���ƶ�
	};

	/*
	* ���������
	*/
	enum _declspec(dllexport) AttachVScale{
		AttachVScale_Left, //����
		AttachVScale_Right //����
	};

	/*
	* ��״ͼ��ʽ
	*/
	enum _declspec(dllexport) BarStyle{
		BarStyle_Line, //����
		BarStyle_Rect //����
	};

	/*
	* �ߵ���ʽ
	*/
	enum _declspec(dllexport) CandleStyle{
		CandleStyle_American, //������
		CandleStyle_CloseLine, //������
		CandleStyle_Rect, //����
		CandleStyle_Tower //������
	};

	/*
	* ʮ���ߵ��ƶ���ʽ
	*/
	enum _declspec(dllexport) CrossLineMoveMode{
		CrossLineMoveMode_AfterClick, //����������ƶ�
		CrossLineMoveMode_FollowTouch //���津��
	};

	/*
	* ���ڵ�����
	*/
	enum _declspec(dllexport) DateType{
		DateType_Day = 2, //��
		DateType_Hour = 3, //Сʱ
		DateType_Millisecond = 6, //����
		DateType_Minute = 4, //����
		DateType_Month = 1, //��
		DateType_Second = 5, //��
		DateType_Year = 0 //��
	};

	/*
	* X�������
	*/
	enum _declspec(dllexport) HScaleType{
		HScaleType_Date, //����
		HScaleType_Number //����
	};

	/*
	* ���ֵ���ʽ
	*/
	enum _declspec(dllexport) NumberStyle{
		NumberStyle_Standard, //��׼
		NumberStyle_Underline //���»�������
	};

	/*
	* ���ߵ���ʽ
	*/
	enum _declspec(dllexport) PolylineStyle{
		PolylineStyle_Cycle, //ԲȦ
		PolylineStyle_DashLine, //����
		PolylineStyle_DotLine, //ϸ��ͼ
		PolylineStyle_SolidLine //ʵ��
	};

	/*
	* ��������
	*/
	enum _declspec(dllexport) ScrollType{
		ScrollType_None, //��
		ScrollType_Left, //����
		ScrollType_Right, //����
		ScrollType_ZoomIn, //��С
		ScrollType_ZoomOut //�Ŵ�
	};

	/*
	* ѡ�е���ʽ
	*/
	enum _declspec(dllexport) SelectPoint{
		SelectPoint_Ellipse, //Բ
		SelectPoint_Rect //����
	};

	/*
	* ͼ�α����ģʽ
	*/
	enum _declspec(dllexport) TextMode{
		TextMode_Field, //��ʾ�ֶ�
		TextMode_Full, //��ʾ����
		TextMode_None, //����ʾ
		TextMode_Value //��ʾֵ
	};

	/*
	* ��������ϵ
	*/
	enum _declspec(dllexport) VScaleSystem{
		VScaleSystem_Logarithmic, //��������
		VScaleSystem_Standard //��׼
	};

	/*
	* ������������
	*/
	enum _declspec(dllexport) VScaleType{
		VScaleType_Divide, //�ȷ�
		VScaleType_EqualDiff, //�Ȳ�
		VScaleType_EqualRatio, //�ȱ�
		VScaleType_GoldenRatio, //�ƽ�ָ�
		VScaleType_Percent //�ƽ�ָ�
	};
}