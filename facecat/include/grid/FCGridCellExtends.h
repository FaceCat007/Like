/*
 * FaceCatͼ��ͨѶ���(�ǿ�Դ)
 * ����Ȩ���:2015SR229355+2020SR0266727
 * �Ϻ����è��Ϣ�������޹�˾
 */

#ifdef __FCGRIDCELLEXTENDS_H__
#else                                                                            
#define __FCGRIDCELLEXTENDS_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "FCGridCell.h"
#include "FCGridColumn.h"
#include "FCGridRow.h"
#include "FCGrid.h"

namespace FaceCat{
	class FCGridCell;
	class FCGridColumn;
	class FCGridRow;
	class FCGrid;
	class FCButton;
	class FCCheckBox;
	class FCComboBox;
	class FCDateTimePicker;
	class FCLabel;
	class FCSpin;
	class FCRadioButton;
	class FCTextBox;

	/*
	* �����͵�Ԫ��
	*/
	class __FCGRIDCELLEXTENDS_H__ FCGridBoolCell : public FCGridCell{
	public:
	    /**
		 * ��ֵ
		 */
		bool m_value;
	public:
		FCGridBoolCell();
		FCGridBoolCell(bool value);
		virtual ~FCGridBoolCell();
	public:
	    /**
		 * ��Ԫ���С�Ƚϣ���������
		 */
		virtual int compareTo(FCGridCell *cell);
		/**
		 * ��ȡ��������ֵ
		 */
		virtual bool getBool();
		/**
		 * ��ȡ˫���ȸ���ֵ
		 */
		virtual double getDouble();
		/**
		 * ��ȡ�����ȸ���ֵ
		 */
		virtual float getFloat();
		/**
		 * ��ȡ������ֵ
		 */
		virtual int getInt();
		/**
		 * ��ȡ��������ֵ
		 */
		virtual Long getLong();
		/**
		 * ��ȡ�ַ�����ֵ
		 */
		virtual String getString();
		/**
		 * ���ò�������ֵ
		 */
	    virtual void setBool(bool value);
	    /**
		 * ����˫���ȸ���ֵ
		 */
        virtual void setDouble(double value);
        /**
		 * ���õ����ȸ���ֵ
		 */
        virtual void setFloat(float value);
        /**
		 * ����������ֵ
		 */
        virtual void setInt(int value);
        /**
		 * ���ó�������ֵ
		 */
        virtual void setLong(Long value);
        /**
		 * �����ַ�����ֵ
		 */
        virtual void setString(const String& value);
	};

	/*
	* ��ť�͵�Ԫ��
	*/
	class __FCGRIDCELLEXTENDS_H__ FCGridButtonCell: public FCGridViewCell{
	public:
		FCGridButtonCell();
		virtual ~FCGridButtonCell();
		FCButton* getButton();
	};

	/*
	* ��ѡ���͵�Ԫ��
	*/
	class __FCGRIDCELLEXTENDS_H__ FCGridCheckBoxCell : public FCGridViewCell{
	public:
	public:
		FCGridCheckBoxCell();
		virtual ~FCGridCheckBoxCell();
		FCCheckBox* getCheckBox();
	public:
	    /**
		 * ��ȡ��������ֵ
		 */
		virtual bool getBool();
		/**
		 * ��ȡ˫���ȸ���ֵ
		 */
		virtual double getDouble();
		/**
		 * ��ȡ�����ȸ���ֵ
		 */
		virtual float getFloat();
		/**
		 * ��ȡ������ֵ
		 */
		virtual int getInt();
		/**
		 * ��ȡ��������ֵ
		 */
		virtual Long getLong();
		/**
		 * ��ȡ��������ֵ
		 */
		virtual String getString();
		/**
		 * ���ò�������ֵ
		 */
		virtual void setBool(bool value);
		/**
		 * ����˫���ȸ���ֵ
		 */
		virtual void setDouble(double value);
		/**
		 * ���õ����ȸ���ֵ
		 */
        virtual void setFloat(float value);
        /**
		 * ����������ֵ
		 */
        virtual void setInt(int value);
        /**
		 * ���ó�������ֵ
		 */
        virtual void setLong(Long value);
        /**
		 * �����ַ�����ֵ
		 */
        virtual void setString(const String& value);
	};

	/*
	* �����б�Ԫ��
	*/
	class __FCGRIDCELLEXTENDS_H__ FCGridComboBoxCell : public FCGridViewCell{
	public:
		FCGridComboBoxCell();
		virtual ~FCGridComboBoxCell();
		FCComboBox* getComboBox();
	public:
		virtual bool getBool();
		virtual double getDouble();
		virtual float getFloat();
		virtual int getInt();
		virtual Long getLong();
		virtual String getString();
		virtual void setBool(bool value);
		virtual void setDouble(double value);
        virtual void setFloat(float value);
        virtual void setInt(int value);
        virtual void setLong(Long value);
        virtual void setString(const String& value);
	};

	/*
	* ����ʱ��ѡ��Ԫ��
	*/
	class __FCGRIDCELLEXTENDS_H__ FCGridDateTimePickerCell : public FCGridViewCell{
	public:
		FCGridDateTimePickerCell();
		virtual ~FCGridDateTimePickerCell();
		FCDateTimePicker* getDatePicker();
	};

	/*
	* ͼ�㵥Ԫ��
	*/
	class __FCGRIDCELLEXTENDS_H__ FCGridDivCell : public FCGridViewCell{
	public:
		FCGridDivCell();
		virtual ~FCGridDivCell();
		FCDiv* getDiv();
	};

	/*
	* ˫���ȵ�Ԫ��
	*/
	class __FCGRIDCELLEXTENDS_H__ FCGridDoubleCell : public FCGridCell{
	public:
		int m_digit;
		double m_value;
	public:
		FCGridDoubleCell();
		FCGridDoubleCell(double value);
		virtual ~FCGridDoubleCell();
		virtual int getDigit();
		virtual void setDigit(int value);
	public:
		virtual int compareTo(FCGridCell *cell);
		virtual bool getBool();
		virtual double getDouble();
		virtual float getFloat();
		virtual int getInt();
		virtual Long getLong();
		virtual String getString();
		virtual String getPaintText();
		virtual void setBool(bool value);
        virtual void setDouble(double value);
        virtual void setFloat(float value);
        virtual void setInt(int value);
        virtual void setLong(Long value);
        virtual void setString(const String& value);
	};

	/*
	* �����ȵ�Ԫ��
	*/
	class __FCGRIDCELLEXTENDS_H__ FCGridFloatCell : public FCGridCell{
	public:
		float m_value;
	public:
		FCGridFloatCell();
		FCGridFloatCell(float value);
		virtual ~FCGridFloatCell();
	public:
		virtual int compareTo(FCGridCell *cell);
		virtual bool getBool();
		virtual double getDouble();
		virtual float getFloat();
		virtual int getInt();
		virtual Long getLong();
		virtual String getString();
		virtual void setBool(bool value);
        virtual void setDouble(double value);
        virtual void setFloat(float value);
        virtual void setInt(int value);
        virtual void setLong(Long value);
        virtual void setString(const String& value);
	};

	/*
	* ���͵�Ԫ��
	*/
	class __FCGRIDCELLEXTENDS_H__ FCGridIntCell : public FCGridCell{
	public:
		int m_value;
	public:
		FCGridIntCell();
		FCGridIntCell(int value);
		virtual ~FCGridIntCell();
	public:
		virtual int compareTo(FCGridCell *cell);
		virtual bool getBool();
		virtual double getDouble();
		virtual float getFloat();
		virtual int getInt();
		virtual Long getLong();
		virtual String getString();
		virtual void setBool(bool value);
        virtual void setDouble(double value);
        virtual void setFloat(float value);
        virtual void setInt(int value);
        virtual void setLong(Long value);
        virtual void setString(const String& value);
	};

	/*
	* ��ǩ��Ԫ��
	*/
	class __FCGRIDCELLEXTENDS_H__ FCGridLabelCell : public FCGridViewCell{
	public:
		FCGridLabelCell();
		virtual ~FCGridLabelCell();
		FCLabel* getLabel();
	};

	/*
	* �����͵�Ԫ��
	*/
	class __FCGRIDCELLEXTENDS_H__ FCGridLongCell : public FCGridCell{
	public:
		Long m_value;
	public:
		FCGridLongCell();
		FCGridLongCell(Long value);
		virtual ~FCGridLongCell();
	public:
		virtual int compareTo(FCGridCell *cell);
		virtual bool getBool();
		virtual double getDouble();
		virtual float getFloat();
		virtual int getInt();
		virtual Long getLong();
		virtual String getString();
		virtual void setBool(bool value);
        virtual void setDouble(double value);
        virtual void setFloat(float value);
        virtual void setInt(int value);
        virtual void setLong(Long value);
        virtual void setString(const String& value);
	};

	/*
	* ��ѡ��Ԫ��
	*/
	class __FCGRIDCELLEXTENDS_H__ FCGridRadioButtonCell : public FCGridViewCell{
	public:
		FCGridRadioButtonCell();
		virtual ~FCGridRadioButtonCell();
		FCRadioButton* getRadioButton();
	public:
		virtual bool getBool();
		virtual double getDouble();
		virtual float getFloat();
		virtual int getInt();
		virtual Long getLong();
		virtual String getString();
		virtual void setBool(bool value);
		virtual void setDouble(double value);
        virtual void setFloat(float value);
        virtual void setInt(int value);
        virtual void setLong(Long value);
        virtual void setString(const String& value);
	};

	/*
	* ��ֵ�ı���Ԫ��
	*/
	class __FCGRIDCELLEXTENDS_H__ FCGridSpinCell : public FCGridViewCell{
	public:
		FCGridSpinCell();
		virtual ~FCGridSpinCell();
		FCSpin* getSpin();
	public:
		virtual bool getBool();
		virtual double getDouble();
		virtual float getFloat();
		virtual int getInt();
		virtual Long getLong();
		virtual void setBool(bool value);
		virtual void setDouble(double value);
        virtual void setFloat(float value);
        virtual void setInt(int value);
        virtual void setLong(Long value);
	};

	/*
	* �ַ�����Ԫ��
	*/
	class __FCGRIDCELLEXTENDS_H__ FCGridStringCell : public FCGridCell{
	public:
		String m_value;
	public:
		FCGridStringCell();
		FCGridStringCell(const String& value);
		virtual ~FCGridStringCell();
	public:
		virtual int compareTo(FCGridCell *cell);
		virtual bool getBool();
		virtual double getDouble();
		virtual float getFloat();
		virtual int getInt();
		virtual Long getLong();
		virtual String getString();
		virtual void setString(const String& value);
	};

	/*
	* ���뵥Ԫ��
	*/
	class __FCGRIDCELLEXTENDS_H__ FCGridPasswordCell : public FCGridStringCell{
	public:
		FCGridPasswordCell();
		virtual ~FCGridPasswordCell();
	public:
		virtual String getPaintText();
	};

	/*
	* �ı���Ԫ��
	*/
	class __FCGRIDCELLEXTENDS_H__ FCGridTextBoxCell: public FCGridViewCell{
	public:
		FCGridTextBoxCell();
		virtual ~FCGridTextBoxCell();
		FCTextBox* getTextBox();
	};

	/*
	* С�������ı���
	*/
	class __FCGRIDCELLEXTENDS_H__ FCGridPercentCell : public FCGridDoubleCell{
	public:
		FCGridPercentCell();
		FCGridPercentCell(double value);
	public:
		virtual String getPaintText();
	};
}