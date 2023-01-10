/*
 * FaceCatͼ��ͨѶ���(�ǿ�Դ)
 * ����Ȩ���:2015SR229355+2020SR0266727
 * �Ϻ����è��Ϣ�������޹�˾
 */

#ifdef __FCCLIENTSERVICE_H__
#else                                                                            
#define __FCCLIENTSERVICE_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "..\\core\\FCBinary.h"
#include "FCServerService.h"
#include <string>
#include <map>
using namespace std;

#define  DOWNHELPER_AGENTNAME         "SECURITY"  
#define  LEN_OF_BUFFER_FOR_QUERYINFO  128  
#define  MAX_DOWNLOAD_REQUEST_TIME    10   

namespace FaceCat{
	/*
	* �ͻ���SOCKET����
	*/
	class __FCCLIENTSERVICE_H__ FCClientService{
	private:
		/*
		* ��
		*/
		FCLock m_lock;
		/**
		 * ѹ������
		 */
		int m_compressType;
		/**
		 * �����߼���
		 */
		map<int, FCMessageListener*> m_listeners;
		/**
		 * �����ID
		 */
		int m_serviceID;
		/**
		 * �ȴ���Ϣ����
		 */
		map<int, FCMessage*> m_waitMessages;
	public:
		/**
		* �ر�
		* @param  socketID  ����ID
		*/
		static int closeClient(int socketID);
		/**
		* ����
		* @param  proxyType  ��������
		* @param  ip  ��ַ
		* @param  port  �˿�
		* @param  proxyIp  �����ַ
		* @param  proxyPort  ����˿�
		* @param  proxyUserName  ��������
		* @param  proxyUserPwd  ��������
		* @param  proxyDomain  ������
		* @param  timeout  ��ʱ
		*/
		static int connectToServer(int proxyType, const char *ip, int port, const char *proxyIp, int proxyPort, const char *proxyUserName, const char *proxyUserPwd, const char *proxyDomain, int timeout, char *token);
		/**
		 * ע��ص�
		 */
		static void registerCallBack(MessageCallBack callBack);
		/**
		 * ע����־
		 */
		static void registerLog(WriteLogCallBack callBack);
		/**
		* ������Ϣ
		* @param  socketID  ����ID
		* @param  str   ����
		* @param  len  ����
		*/
		static int sendByClient(int socketID, const char *str, int len);
	public:
		/*
		* ���캯��
		*/
		FCClientService();
		/*
		* ��������
		*/
		virtual ~FCClientService();
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
		static void addService(FCClientService *service);
		/**
		* �ص�����
		* @param  socketID  ����ID
		* @param  localSID  ��������ID
		* @param  str  ����
		* @param  len  ����
		*/
		static void __stdcall callBack(int socketID, int localSID, const char *str, int len);
		/**
		 * ��ȡ����ID
		 */
		static int getRequestID();
		/**
		 * ��ȡ���еķ���
		 */
		static void getServices(vector<FCClientService*> *services);
		/**
		 * ���ֻ�Ծ
		 */
		int keepAlive(int socketID);
		/**
		 * �յ���Ϣ
		 */
		virtual void onCallBack(FCBinary *binary, int socketID, int localSID, int len);
		/**
		* �ͻ��˶Ͽ�����
		*/
		virtual void onClientClose(int socketID, int localSID);
		/**
		* �ͻ������ӷ���
		*/
		virtual void onClientConnect(int socketID, int localSID);
		/**
		 * ��������
		 */
		virtual void onReceive(FCMessage *message);
		/**
		 * �ȴ���Ϣ�Ĵ���
		 */
		virtual void onWaitMessageHandle(FCMessage *message);
		/**
		* ע�����ݼ���
		* @param  requestID ����ID
		* @param  callBack  �ص�����
		*/
		void addListener(int requestID, FCListenerMessageCallBack *callBack, Object pInvoke);
		/**
		 * ע��ȴ�
		 */
		void addWait(int requestID, FCMessage *message);
		/**
		 * ������Ϣ
		 */
		virtual int send(FCMessage *message);
		/**
		 * ���͵�������
		 */
		void sendToListener(FCMessage *message);
		/*
		* �Ƴ��ص�
		*/
		static void removeDataCallBack(FCDataEventCallBack *dataCallBack);
		/**
		 * ȡ��ע�����ݼ���
		 */
		void removeListener(int requestID);
		/**
		 * ȡ��ע�����
		 */
		void removeListener(int requestID, FCListenerMessageCallBack *callBack);
		/**
		 * ȡ��ע��ȴ�
		 */
		void removeWait(int requestID);
		/**
		 * �ȴ���Ϣ
		 */
		int waitMessage(int requestID, int timeout);
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