/*
 * FaceCatͼ��ͨѶ���(�ǿ�Դ)
 * ����Ȩ���:2015SR229355+2020SR0266727
 * �Ϻ����è��Ϣ�������޹�˾
 */

#ifdef __FCSERVERSERVICE_H__
#else                                                                            
#define __FCSERVERSERVICE_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "..\\core\\FCBinary.h"
#include <string>
#include <map>
using namespace std;

#define  COMPRESSTYPE_NONE			  0
#define  COMPRESSTYPE_GZIP			  1

static int m_requestID = 10000;

namespace FaceCat{	
	/**
	 * ��Ϣ�ṹ
	 */
	struct __FCSERVERSERVICE_H__ FCMessage{
	public:
	    /**
		 * ������Ϣ
		 */
		FCMessage();
		/**
		* ������Ϣ
		* @param  serviceID  ����ID
		* @param  functionID  ����ID
		* @param  requestID  ����ID
		* @param  socketID  ����ID
		* @param  state  ״̬
		* @param  compressType  ѹ������
		* @param  bodyLength  ���峤��
		* @param  body  ����
		*/
		FCMessage(int serviceID, int functionID, int requestID, int socketID, int state, int compressType, int bodyLength, char *body); 
		int m_serviceID;   
		int m_functionID;   
		int m_requestID;   
		int m_socketID; 
		int m_state;
		int m_compressType;
		int m_bodyLength;  
		char *m_body;
		int m_signal;
		/**
		 * ��������
		 */
		void copy(FCMessage *message)
		{
			m_serviceID = message->m_serviceID;
			m_functionID = message->m_functionID;
			m_requestID= message->m_requestID;
			m_socketID = message->m_socketID;
			m_state = message->m_state;
			m_compressType = message->m_compressType;
			m_bodyLength = message->m_bodyLength;
			m_body = message->m_body;
		}
	};

	typedef void (__stdcall *MessageCallBack)(int socketID, int localSID, const char *str, int len);

	typedef void (__stdcall *WriteLogCallBack)(int socketID, int localSID, int state, const char *log);

	/*
	* ������Ϣ
	*/
    class __FCSERVERSERVICE_H__ FCListenerMessageCallBack {
	public:
		virtual void callListenerMessageEvent(Object sender, FCMessage *message, Object invoke){}
    };

	/*
	* ��Ϣ����
	*/
	class __FCSERVERSERVICE_H__ FCMessageListener{
	private:
	    /**
		 * �����ص��б�
		 */
		vector<FCListenerMessageCallBack*> m_callBacks;
		vector<Object> m_callBackInvokes;
	public:
	    /**
		 * ������Ϣ����
		 */
		FCMessageListener();
		/*
		* ���ٶ���
		*/
		virtual ~FCMessageListener();
	public:
	    /**
		 * ��ӻص�
		 */
		void add(FCListenerMessageCallBack *callBack, Object pInvoke);
		/**
		 * �ص�����
		 */
		void callBack(FCMessage *message);
		/**
		 * �������
		 */
		void clear();
		/**
		 * �Ƴ��ص�
		 */
		void remove(FCListenerMessageCallBack *callBack);
	};

	/*
	* ���ݻص�
	*/
	class __FCSERVERSERVICE_H__ FCDataEventCallBack{
	public:
		/*
		* �ص�����
		*/
		virtual bool callDataEvent(int socketID, int localSID, const char *str, int len){return false;}
	};

	/*
	* �׽�����
	*/
	class __FCSERVERSERVICE_H__ FCSocketArray{
	private:
	    /**
		 * �׽���ID��
		 */
		vector<int> m_sockets;
	public:
		/*
		* ��������
		*/
		FCSocketArray();
		/*
		* ���ٶ���
		*/
		virtual ~FCSocketArray();
	public:
	    /**
		 * ����׽���ID
		 */
		void addSocket(int socketID);
		/**
		* ��ȡ�׽����б�
		* @param  socketList  �׽����б�
		*/
		void getSocketList(vector<int> *socketList);
		/**
		 * �Ƴ��׽���ID
		 */
		void removeSocket(int socketID);
	};

	/*
	* �����SOCKET����
	*/
	class __FCSERVERSERVICE_H__ FCServerService{
	public:
		/*
		* ѹ������
		*/
		int m_compressType;
		/**
		 * ѹ�����ͼ���
		 */
		map<int, int> m_compressTypes;
		/**
		 * �����߼���
		 */
		map<int, FCMessageListener*> m_listeners;
		/**
		 * �����ID
		 */
		int m_serviceID;
		/**
		* �׽���ID
		*/
		int m_socketID;
		/**
		 * �ȴ���Ϣ����
		 */
		map<int, FCMessage*> m_waitMessages;
	public:
		/*
		* ��
		*/
		FCLock m_lock;
	public:
		/**
		* �ر�
		* @param  socketID  ����ID
		*/
		static int closeServer(int socketID);
		/**
		* ע��ص�
		* @param  callBack  �ص�����
		*/
		static void registerCallBack(MessageCallBack callBack);
		/**
		* ע����־
		* @param  callBack  �ص�����
		*/
		static void registerLog(WriteLogCallBack callBack);
		/**
		* ������Ϣ
		* @param  socketID  ����ID
		* @param  str  ����
		* @param  len  ����
		*/
		static int sendByServer(int socketID, const char *str, int len);
		/**
		* ����
		* @param  port  �˿�
		*/
		static int startServer(int port, char *token);
	public:
		/*
		* ���캯��
		*/
		FCServerService();
		/*
		* ��������
		*/
		virtual ~FCServerService();
		/**
		 * ��ȡѹ������
		 */
		int getCompressType();
		/**
		 * ����ѹ������
		 */
		void setCompressType(int value);
		/**
		 * ��ȡ��������
		 */
		static Long getDownFlow();
		/**
		 * ������������
		 */
		static void setDownFlow(Long value);
		/**
		 * ��ȡ�����ID
		 */
		int getServiceID();
		/**
		 * ���÷����ID
		 */
		void setServiceID(int value);
		/*
		* ��ȡ�׽���ID
		*/
		int getSocketID();
		/*
		* �����׽���ID
		*/
		void setSocketID(int value);
		/**
		 * ��ȡ�ϴ�����
		 */
		static Long getUpFlow();
		/**
		 * �����ϴ�����
		 */
		static void setUpFlow(Long value);
	public:
		/*
		* ��ӻص�
		*/
		static void addDataCallBack(FCDataEventCallBack *dataCallBack);
		/**
		* ��ӷ���
		* @param  service  ����
		*/
		static void addService(FCServerService *service);
		/*
		* ���ݻص�
		*/
		static void __stdcall callBack(int socketID, int localSID, const char *str, int len);
		/**
		 * ��ȡ����ID
		 */
		static int getRequestID();
		/**
		* ��ȡ���еķ���
		* @param  service  ����
		*/
		static void getServices(vector<FCServerService*> *services);
		/**
		* ���ֻ�Ծ
		* @param  socketID  �׽���ID
		*/
		virtual int keepAlive(int socketID);
		/**
		* �յ���Ϣ
		* @param  br  ��
		* @param  socketID  �׽���ID
		* @param  localSID  �����׽���ID
		* @param  len  ����
		*/
		virtual void onCallBack(FCBinary *binary, int socketID, int localSID, int len);
		/**
		* �ͻ��˹رշ���
		* @param  socketID  ����ID
		* @param  localSID  ��������ID
		*/
		virtual void onClientClose(int socketID, int localSID);
		/*
		* �ͻ������ӷ���
		*/
		virtual void onClientConnect(int socketID, int localSID, String ip);
		/*
		* ��������
		* @param  message  ��Ϣ
		*/
		virtual void onReceive(FCMessage *message);
		/**
		 * �ȴ���Ϣ�Ĵ���
		 */
		virtual void onWaitMessageHandle(FCMessage *message);
		/**
		 * ע�����ݼ���
		 */
		virtual void addListener(int requestID, FCListenerMessageCallBack *callBack, Object pInvoke);
		/**
		 * ע��ȴ�
		 */
		virtual void addWait(int requestID, FCMessage *message);
		/**
		 * ������Ϣ
		 */
		virtual int send(FCMessage *message);
		/**
		 * ���͵�������
		 */
		virtual void sendToListener(FCMessage *message);
		/*
		* �Ƴ��ص�
		*/
		static void removeDataCallBack(FCDataEventCallBack *dataCallBack);
		/**
		 * ȡ��ע�����ݼ���
		 */
		virtual void removeListener(int requestID);
		/**
		 * ȡ��ע�����
		 */
		virtual void removeListener(int requestID, FCListenerMessageCallBack *callBack);
		/**
		 * ȡ��ע��ȴ�
		 */
		virtual void removeWait(int requestID);
		/**
		 * �ȴ���Ϣ
		 */
		virtual int waitMessage(int requestID, int timeout);
		/**
		* д��־
		* @param  socketID  ����ID
		* @param  localSID  ��������ID
		* @param  state  ״̬
		* @param  log  ��־
		*/
		static void __stdcall writeServerLog(int socketID, int localSID, int state, const char *log);
	};
}