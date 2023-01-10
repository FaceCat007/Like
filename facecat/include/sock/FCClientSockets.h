/*
 * FaceCatͼ��ͨѶ���(�ǿ�Դ)
 * ����Ȩ���:2015SR229355+2020SR0266727
 * �Ϻ����è��Ϣ�������޹�˾
 */

#ifdef __FCCLIENTSOCKETS_H__
#else                                                                            
#define __FCCLIENTSOCKETS_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
using namespace std;  

namespace FaceCat{ 
	typedef void (__stdcall *RecvMsg)(int socketID, int localSID, const char *str, int len);

	typedef void (__stdcall *WriteClientLog)(int socketID, int localSID, int state, const char *log);

	/*
	* �ͻ����׽������ӹ���
	*/
	class __FCCLIENTSOCKETS_H__ FCClientSockets{
	public:
		/*
		* ��Ϣ�ص�
		*/
		static void __stdcall recvServerMsg(int socketID, int localSID, const char *str, int len);
		/*
		* ��־�ص�
		*/ 
		static void __stdcall writeLog(int socketID, int localSID, int state, const char *log);
	public:
		/*
		* �ر�����
		*/
		static int close(int socketID);
		/*
		* ����
		*/
		static int connect(int proxyType, const char *ip, int port, const char *proxyIp, int proxyPort, const char *proxyUserName, const char *proxyUserPwd, const char *proxyDomain, int timeout, char *token);
		/*
		* ע����־�ص�
		*/
		static void registerLog(WriteClientLog writeLogCallBack);
		/*
		* ע����Ϣ�ص�
		*/
		static void registerRecv(RecvMsg recvMsgCallBack);
		/*
		* ��������
		*/
		static int send(int socketID, const char *str, int len);
	};
}