/*
 * FaceCatͼ��ͨѶ���(�ǿ�Դ)
 * ����Ȩ���:2015SR229355+2020SR0266727
 * �Ϻ����è��Ϣ�������޹�˾
 */

#ifdef __FCSERVERSOCKETS_H__
#else                                                                            
#define __FCSERVERSOCKETS_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"

namespace FaceCat
{
	typedef void (__stdcall *RecvMsg)(int socketID, int localSID, const char *str, int len);

	typedef void (__stdcall *WriteServerLog)(int socketID, int localSID, int state, const char *str);

	/*
	* ������׽������ӹ���
	*/
	class __FCSERVERSOCKETS_H__ FCServerSockets
	{
	public:
		/*
		* ��Ϣ�ص�
		*/
		static void __stdcall recvClientMsg(int socketID, int localSID, const char *str, int len);
		/*
		* ��־�ص�
		*/
		static void __stdcall writeLog(int socketID, int localSID, int state, const char *log);
	public:
		/*
		* �رշ���
		*/
		static int close(int socketID);
		/*
		* �رտͻ���
		*/
		static int closeClient(int socketID, int clientSocketID);
		/*
		* ע����־�ص�
		*/
		static void registerLog(WriteServerLog writeLogCallBack);
		/*
		* ע����Ϣ�ص�
		*/
		static void registerRecv(RecvMsg recvMsgCallBack);
		/*
		* ������Ϣ
		*/
		static int send(int socketID, const char *str, int len);
		/*
		* ���������
		*/
		static int start(int port, char *token);
		/*
         * ��������
         */
        static int setLimit(int socketID, int limitTimes, int interval);
		/*
         * ��Ӻ�����
         */
        static int addBlackIP(int socketID, string ip);
        /*
         * �Ƴ�������
         */
        static int removeBlackIP(int socketID, string ip);
	};
}