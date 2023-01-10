/*
 * FaceCatͼ��ͨѶ���(�ǿ�Դ)
 * ����Ȩ���:2015SR229355+2020SR0266727
 * �Ϻ����è��Ϣ�������޹�˾
 */

#ifdef __FCSERVERSOCKET_H__
#else                                                                            
#define __FCSERVERSOCKET_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#pragma comment(lib, "ws2_32.lib")
#include "winsock2.h"
#include "FCServerSockets.h"
#include "..\\core\\FCLock.h"
#pragma comment (lib,"winmm")

namespace FaceCat{
	typedef enum  {
		RECV_POSTED
	}OPERATION_TYPE;

	typedef struct 
	{
		WSAOVERLAPPED  overlap;
		WSABUF         Buffer;
		char           szMessage[1024];
		DWORD          NumberOfBytesRecvd;
		DWORD          Flags;
		OPERATION_TYPE OperationType;
	}PER_IO_OPERATION_DATA, *LPPER_IO_OPERATION_DATA;

	class __FCSERVERSOCKET_H__ SOCKDATA{
	public:
		SOCKDATA();
		~SOCKDATA();
		char *m_buffer;
		int m_bufferRemain;
		bool m_get;
		int m_head;
		int m_headSize;
		char m_headStr[4];
		int m_index;
		int m_len;
		int m_pos;
		SOCKET m_socket;
		char *m_str;
		int m_strRemain;
		bool m_submit;
		int m_readHead;
	};

	/*
	* ������׽�������
	*/
	class __FCSERVERSOCKET_H__ FCServerSocket{
	public:
		SOCKADDR_IN m_addr;
		HANDLE m_completionPort;
		vector<SOCKDATA*> m_datas;
		SOCKET m_hSocket;
		int m_port;
		RecvMsg m_recvEvent;
		WriteServerLog m_writeLogEvent;
		char m_token[4];
	public:
		/*
		* ���������socket
		*/
		FCServerSocket();
		/*
		* ���ٶ���
		*/
		virtual ~FCServerSocket();
		/*
		* �رշ����
		*/
		int close(int socketID);
		/*
		* �رտͻ���
		*/
		int closeClient(int socketID);
		/*
		* ��������
		*/
		int recv(SOCKDATA *data);
		/*
		* ��������
		*/
		static int send(int socketID, const char *str, int len);
		/*
		* ����TCP
		*/
		int startTCP(int port);
		/*
		* д��־
		*/
		void writeLog(int socketID, int localSID, int state, const char *log);
	public:
		/*
		* ����Socket
		*/
		static void wSStart();
		/*
		* ֹͣSocket
		*/
		static void wSStop();
	public:
        /*
         * �������ļ��
         */
        int m_clearInterval;
        /*
         * ��¼IP�Ļ���
         */
        map<string, int> m_ipCaches;
        /*
         * ��¼�������
         */
        FCLock m_ipCachesLock;
        /*
         * �ϴ��������ʱ��
         */
        double m_lastClearTime;
        /*
         * ��������IP�Ĵ���
         */
        int m_limitTimes;
		/*
         * IP������
         */
        map<string, int> m_blackIPs;
        /*
         * ����������
         */
        FCLock m_blackIPsLock;
        /*
         * ���IP������
         */
        void addBlackIP(string ip);
        /*
         * �Ƴ�IP������
         */
        void removeBlackIP(string ip);
	};
}