/*
 * FaceCat���(�ǿ�Դ)
 * �Ϻ����è��Ϣ�������޹�˾
 */

#ifdef __UIEVENT_H__
#else                                                                            
#define __UIEVENT_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "FCUIScript.h"
#include "FCUIXml.h"
#include "..\\core\\FCLib.h"

namespace FaceCat{
	class FCUIScript;
	class FCUIXml;

	/*
	* �¼���Ϣ
	*/
	class __UIEVENT_H__ FCEventInfo{
	private:
	    /**
		 * ����
		 */
		HashMap<String, String> m_functions;
	public:
		/*
		* ���캯��
		*/
		FCEventInfo();
		/*
		* ��������
		*/
		virtual ~FCEventInfo();
	public:
		/**
		* ����¼�
		* @params eventName  �¼�ID
		* @params function  ����
		*/
		void addEvent(String eventName, const String& function);
		/**
		 * ��ȡ����
		 */
		String getFunction(String eventName);
		/**
		 * �Ƴ��¼�
		 */
		void removeEvent(String eventName);
	};

	/*
	* �¼�
	*/
	class __UIEVENT_H__ FCUIEvent : public FCEventCallBack, public FCTouchEventCallBack, public FCInvokeEventCallBack, 
        public FCKeyEventCallBack, public FCPaintEventCallBack, public FCTimerEventCallBack, 
        public FCGridCellEventCallBack, public FCGridCellTouchEventCallBack, 
        public FCMenuItemTouchEventCallBack, public FCWindowClosingEventCallBack{
	private:
	    /**
		 * �ű�
		 */
		FCUIScript *m_script;
		/**
		 * ������
		 */
		String m_sender;
		/*
         * �������
         */
        FCTouchInfo m_touchInfo;
		/**
		 * XML����
		 */
		FCUIXml *m_xml;
	public:
	    /**
		 * �¼�����
		 */
		map<FCView*, FCEventInfo*> m_events;
	public:
	    /**
		 * �����¼�
		 */
		FCUIEvent(FCUIXml *xml);
		/*
		* ��������
		*/
		virtual ~FCUIEvent();
		/**
		 * ��ȡ�ű�
		 */
		FCUIScript* getScript();
		/**
		 * ���ýű�
		 */
		void setScript(FCUIScript *value);
		/**
		 * ��ȡ������
		 */
		String getSender();
		/**
		 * ���÷�����
		 */
		void setSender(const String& value);
		/*
         * ��ȡ�����ĵ����Ϣ
         */
        FCTouchInfo getTouchInfo();
        /*
         * ���ô����ĵ����Ϣ
         */
        void setTouchInfo(FCTouchInfo value);
		/**
		 * ��ȡXML����
		 */
		FCUIXml* getXml();
		/**
		 * ����XML����
		 */
		void setXml(FCUIXml *value);
	public:
		/*
		* ���÷���
		*/
        static String callFunction(Object sender, String eventName, Object pInvoke);
		/*
		* �����¼�
		*/
		void callEvent(String eventName, Object sender, Object invoke) {
            callFunction(sender, eventName, invoke);
		}
		/*
		* ���ÿ��߳��¼�
		*/
        void callInvokeEvent(String eventName, Object sender, Object args, Object invoke) {
            callFunction(sender, eventName, invoke);
        }
		/*
		* ���ü����¼�
		*/
        void callKeyEvent(String eventName, Object sender, char key, Object invoke) {
            callFunction(sender, eventName, invoke);
        }
		/*
		* ���ô����¼�
		*/
        void callTouchEvent(String eventName, Object sender, FCTouchInfo touchInfo, Object invoke) {
			m_touchInfo = touchInfo;
            callFunction(sender, eventName, invoke);
        }
		/*
		* ���û�ͼ�¼�
		*/
        bool callPaintEvent(String eventName, Object sender, FCPaint *paint, const FCRect& clipRect, Object invoke) {
            callFunction(sender, eventName, invoke);
            return false;
        }
		/*
		* ��������¼�
		*/
        void callTimerEvent(String eventName, Object sender, int timerID, Object invoke) {
            callFunction(sender, eventName, invoke);
        }
		/*
		* ���õ�Ԫ���¼�
		*/
        void callGridCellEvent(String eventName, Object sender, FCGridCell *cell, Object invoke) {
            callFunction(sender, eventName, invoke);
        }
		/*
		* ���õ�Ԫ�����¼�
		*/
        void callGridCellTouchEvent(String eventName, Object sender, FCGridCell *cell, FCTouchInfo touchInfo, Object invoke) {
            callFunction(sender, eventName, invoke);
        }
		/*
		* ���ò˵������¼�
		*/
        void callMenuItemTouchEvent(String eventName, Object sender, FCMenuItem *item, FCTouchInfo touchInfo, Object invoke) {
            callFunction(sender, eventName, invoke);
        }
		/*
		* ���ô���ر��¼�
		*/
        void callWindowClosingEvent(String eventName, Object sender, bool *cancel, Object invoke) {
            callFunction(sender, eventName, invoke);
        }
		/**
		 * ����¼�
		 */
		virtual void addEvent(FCView *view, const String& eventName, const String& function);
	};
}