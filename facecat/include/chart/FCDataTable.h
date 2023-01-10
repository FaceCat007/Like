/*
 * FaceCatͼ��ͨѶ���(�ǿ�Դ)
 * ����Ȩ���:2015SR229355+2020SR0266727
 * �Ϻ����è��Ϣ�������޹�˾
 */

#ifdef __FCDATATABLE_H__
#else                                                                            
#define __FCDATATABLE_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"

namespace FaceCat{
	class FCDataTable;

    /**
     *  ������
     */
	class __FCDATATABLE_H__ FCDataRow{
	public:
		FCDataTable *m_table;
		/**
	     * ֵ����
	     */
		ArrayList<Double> m_values;
	public:
	    /**
	     * ������
	     */
		FCDataRow(FCDataTable *table);
	    /**
         * ������
         * @param capacity  ����
         * @param step  ����
        */
		FCDataRow(FCDataTable *table, int capacity, int step);
	    /**
         * ������
         * @param ary     ����
         * @param size    ����
        */
		FCDataRow(FCDataTable *table, double *ary, int size);
		/*
		* ������
		*/
		virtual ~FCDataRow();
	    /**
         * ���ռ�
         * @param columns   ����
        */
		void fillEmpty(int columns);
	    /**
         *  ��ȡ��ֵ
         * @param index   ����
         *  @returns ��ֵ
        */
		double get(int index);
	    /**
          * �Ƴ�
          * @param index   ����
        */
		void remove(int index);
	    /**
		 * ����ֵ
		 * @param index   ����
		 * @param value   ֵ
        */
		void set(int index, double value);
	};

    /**
     * �Զ�������Դ
     */
	class __FCDATATABLE_H__ FCDataTable{
	public:
	    /**
	     * �Զ��ֶ�
	     */
		int m_autoField;
		/**
	     * �е�����
	     */
		int m_colsCapacity;
		/**
	     * �е���������
	     */
		int m_colsStep;
		/**
	     * ������
	     */
		ArrayList<Integer*> m_columns;
		/**
	     * ��ֵ��
	     */
		ArrayList<Double> m_keys;
		/**
	     * ������
	     */
		ArrayList<FCDataRow*> m_rows;
		/**
	     * �����ֵ����
	     */
		FCDataRow* addKey(double num);
		/**
	     * ���հ�
	     */
		void fillEmpty();
	public:
		/*
		* ��ֵ
		*/
		double NaN;
		/*
		* ��������Դ
		*/
		FCDataTable();
		/*
		* ��������Դ
		*/
		virtual ~FCDataTable();
		/*
		* ��ȡ�Զ��ֶ�
		*/
		int AUTOFIELD();
		/*
		* ���ֶ�
		*/
		static inline int NULLFIELD(){
			return -1;
		}
		/**
	     * �����
	     */
		void addColumn(int colName);
		/**
	     * ֱ�Ӳ���������
	     */
		void addRow(double pk, double *ary, int size);
		/**
	     * ����
	     */
		int getColumnsCount();
		/**
	     * �������
	     */
		void clear();
		/**
	     * ��ȡ�е�����
	     */
		int getColumnIndex(int colName);
		/**
	     * ��ȡ����
	     */
		int getRowIndex(double key);
		/**
	     * ��ȡX���ֵ
	     */
		double getXValue(int rowIndex);
		/**
	     * ��ȡ����
	     */
		double get(double pk, int colName);
		/**
	     * ����������������ȡ����
	     */
		double get2(int rowIndex, int colName);
		/**
	     * ��������������������ȡ����
	     */
		double get3(int rowIndex, int colIndex);
		/*
		* �Ƿ��ֵ
		*/
		static inline bool isNaN(double value){
			return ((*(((long long*) &value)) & 0x7fffffffffffffffL) > 0x7ff0000000000000L);
		}
		/**
	     * �Ƴ�ָ������������
	     */
		void removeAt(int rowIndex);
		/**
	     * �Ƴ���
	     */
		void removeColumn(int name);
		/**
	     * ��ȡ����
	     */
		int getRowsCount();
		/**
	     * ������ݣ�����Ϊ����
	     */
		void set(double pk, int colName, double value);
		/**
	     * ���������������
	     */
		void set2(int rowIndex, int colName, double value);
		/**
	     * ������������������������
	     */
		void set3(int rowIndex, int colIndex, double value);
		/**
	     * �����е�����
	     */
		void setColsCapacity(int capacity);
		/**
	     * �����е���������
	     */
		void setColsGrowStep(int step);
		/**
	     * �����е�����
	     */
		void setRowsCapacity(int capacity);
		/**
	     * �����е���������
	     */
		void setRowsGrowStep(int step);
		/**
	     * ������Դ�л�ȡ֮ǰ��һ�����ݵ�����
	     */
		double* DATA_ARRAY(int colName, int rowIndex, int n, int *length);
	};
}