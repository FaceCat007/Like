/*
 * FaceCatͼ��ͨѶ���(�ǿ�Դ)
 * ����Ȩ���:2015SR229355+2020SR0266727
 * �Ϻ����è��Ϣ�������޹�˾
 */

#ifdef __FCATTRIBUTE_H__
#else                                                                            
#define __FCATTRIBUTE_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"

namespace FaceCat{
	/*
	* ����
	*/
	class __FCATTRIBUTE_H__ FCAttribute{
	public:
		/**
         * ���÷���
         * @param funcName  ��������
         * @param parameters ����
        */
		virtual String callFunction(const String& funcName, const String& parameters){
			return L"";
		}
	    /**
         * �����������ƻ�ȡ����ֵ
         * @param name  ��������
         * @param value ��������ֵ
         * @param type  ������������
        */
		virtual void getAttribute(const String& name, String *value, String *type){
		}
		/**
		 * ��ȡ���������б�
		 */
		virtual ArrayList<String> getAttributeNames(){
			ArrayList<String> attributeNames;
			return attributeNames;
		}
		/**
         * ��ȡ�����б�
         */
        virtual ArrayList<String> getEventNames(){
            ArrayList<String> eventNames;
            return eventNames;
        }
	    /**
         * ��������ֵ
         * @param name  ��������
         * @param value ����ֵ
        */
		virtual void setAttribute(const String& name, const String& value){
		}
	};
}