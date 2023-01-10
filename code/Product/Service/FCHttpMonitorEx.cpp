#include "..\\..\\stdafx.h"
#include "FCHttpMonitorEx.h"
#include "..\\UI\\LikeMainFrame.h"
#include "..\\UI\\UIXmlEx.h"
#include "DataCenter.h"

namespace FaceCat{	
	FCHttpDataEx::FCHttpDataEx(){
		m_body = 0;
		m_close = false;
		m_contentLength = 0;
		m_contentType = L"";
		m_method = L"";
		m_parameters.clear();	
		m_resBytes = 0;
		m_resBytesLength = 0;
		m_resStr = L"";	
		m_remoteIP = L"";
        m_remotePort = 0;
		m_socket = 0;
		m_statusCode = 200;
		m_url = L"";
	}

	FCHttpDataEx::~FCHttpDataEx(){
		m_parameters.clear();
		if(m_body){
			delete m_body;
			m_body = 0;
		}
		if(m_resBytes){
			delete m_resBytes;
			m_resBytes = 0;
		}
	}

	FCHttpMonitorEx::FCHttpMonitorEx(){
		m_hSocket = 0;
		m_native = 0;
		m_port = 17000;
	}

	FCHttpMonitorEx::~FCHttpMonitorEx(){
		m_native = 0;
	}

	static FCHttpMonitorEx *m_mainMonitor = 0;

	FCHttpMonitorEx* FCHttpMonitorEx::getMainMonitor(){
		return m_mainMonitor;
	}

	FCNative* FCHttpMonitorEx::getNative(){
		return m_native;
	}

	int FCHttpMonitorEx::getPort(){
		return m_port;
	}

	void FCHttpMonitorEx::setPort(int port){
		m_port = port;
	}

	SOCKET FCHttpMonitorEx::getSocket(){
		return m_hSocket;
	}

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////

	DWORD WINAPI receiveHandle2(LPVOID lpParam){
		FCHttpDataEx *data = (FCHttpDataEx*)lpParam;
		if(!data) return 0;		
		SOCKADDR_IN addr = data->m_addr;	
		const int bufLen = 102400;
		char buffer[bufLen];
		memset(buffer, '\0', bufLen);
        String parameters = L"";
		int contentLength = 0;
		int copyLen = recv(data->m_socket, buffer, bufLen, 0);
		if(copyLen == 0 || copyLen == SOCKET_ERROR) {
			return 0;
		}		
		strstream os(buffer, copyLen);
		while(true){
			char bufferline[bufLen];
			memset(bufferline, '\0', bufLen);
			os.getline(bufferline, bufLen);
			string requestHeader(bufferline);
			int headLen = requestHeader.length();
			if(headLen == 0 || (headLen == 1 && requestHeader[0] == '\r')){
				break;
			}
			int keyLength = 0;
			int begin = 5;
			if(requestHeader.find("GET") == 0){
				int end = (int)requestHeader.find("HTTP/");
				data->m_method = L"GET";
				parameters = FCTran::stringToString(requestHeader.substr(begin, end - 6));
			}
			else if(requestHeader.find("POST") == 0){
				int end = (int)requestHeader.find("HTTP/");
				data->m_method = L"POST";
				parameters = FCTran::stringToString(requestHeader.substr(begin, end - 6));
			}
			else if(requestHeader.find("Accept:") == 0){
				int acceptIndex = 0;
				keyLength = (int)strlen("Accept:");
				begin = acceptIndex + keyLength;
				data->m_contentType = FCTran::stringToString(requestHeader.substr(begin, requestHeader.find(',', begin) - begin));
			}
			else if (requestHeader.find("Host:") == 0){
				int hostIndex = 0;
				keyLength = (int)strlen("Host:");
				begin = hostIndex + keyLength;
				data->m_url = FCTran::stringToString(requestHeader.substr(begin, requestHeader.find("\r\n", begin) - begin));
			}
			else if (requestHeader.find("Content-Length:") == 0){
				int contentIndex = 0;
				keyLength = (int)strlen("Content-Length:");
				begin = contentIndex + keyLength;
				string postParamterLength = FCTran::replace(requestHeader.substr(begin), " ", "");;
				contentLength = atoi(postParamterLength.c_str());
			}
		}		
        if (contentLength > 0){
            int idx = 0, ide = 0;
            data->m_body = new char[contentLength];
            while (idx < contentLength){
				int recvData = os.get();
                if (recvData != -1){
                    if (recvData != 0){
                        ide++;
                    }
                    idx++;
                }
                else{
                    break;
                }
            }
            if (ide == 0){
                recv(data->m_socket, data->m_body, contentLength, 0);
            }
            else{
                for (int i = 0; i < contentLength; i++){
                    data->m_body[i] = buffer[copyLen - contentLength + i];
                }
            }
            data->m_contentLength = contentLength;
        }
		if ((int)data->m_method.length() == 0){
			closesocket(data->m_socket);
			delete data;
            return 0;
        }
		int cindex = (int)parameters.find('?');
        if (cindex != -1){
            data->m_url = data->m_url + L"/" + parameters;
			parameters = parameters.substr(cindex + 1);
			ArrayList<String> strParameters = FCTran::split(parameters, L"&");
			int strsSize = (int)strParameters.size();
            for (int i = 0; i < strsSize; i++){
				ArrayList<String> subStrs = FCTran::split(strParameters.get(i), L"=");
				if((int)subStrs.size() > 1){
					string value = FCTran::StringTostring(subStrs.get(1));
					//value = FCTran::urlDecode(value);
					String wValue = FCTran::stringToString(value);
					String wPara = subStrs.get(0);
					data->m_parameters.insert(make_pair(wPara, wValue));
				}
            }
        }
        else{
            data->m_url += L"/" + parameters;
        }		
		if(data->m_method == L"GET"){
			LikeMainFrame *mainFrame = (LikeMainFrame*)DataCenter::getMainUI();
			data->m_resStr = mainFrame->exportData(false);
		}
        if (data->m_close){
			closesocket(data->m_socket);
			delete data;
            return 0;
        }
		int resContentLength = 0;
        if (data->m_resBytes){
            resContentLength = data->m_resBytesLength;
        }
        else{
			string str = FCTran::StringTostring(data->m_resStr);
            resContentLength = (int)str.length() + 1;
        }
		string retMessage = "";
		char statusCode[10]; 		
		sprintf_s(statusCode, 9, "%d", data->m_statusCode);
		char szContentLength[10]; 		
		sprintf_s(szContentLength, 9, "%d", resContentLength);
		retMessage = retMessage.append("HTTP/1.0 ");
		retMessage = retMessage.append(statusCode);
		retMessage = retMessage.append(" OK\r\n");
		retMessage = retMessage.append("Content-Length:");
		retMessage = retMessage.append(szContentLength);
		retMessage = retMessage.append("\r\n");
		retMessage = retMessage.append("Connection: close\r\n\r\n");
		if (data->m_resBytes){
			int retLength = (int)strlen(retMessage.c_str());
			int ret = send(data->m_socket, retMessage.c_str(), retLength, 0);
			ret = send(data->m_socket, data->m_resBytes, data->m_resBytesLength, 0);
        }
        else{
			string str = FCTran::StringTostring(data->m_resStr);
			retMessage = retMessage.append(str);
			int ret = send(data->m_socket, retMessage.c_str(), (int)retMessage.length() + 1, 0);
        }
		closesocket(data->m_socket);
		delete data;
		return 0;
	}

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	int FCHttpMonitorEx::close(int socketID){
		SOCKET socket = (SOCKET)socketID;
		int ret = 0;
		if(socket){
			ret = closesocket(socket);
		}
		return ret;
	}

	int FCHttpMonitorEx::start(){		
		int ret = 0;
		m_hSocket = socket(AF_INET, SOCK_STREAM, 0);
		m_addr.sin_addr.S_un.S_addr = INADDR_ANY;
		m_addr.sin_family = AF_INET;
		m_addr.sin_port = htons(m_port);
		ret = bind(m_hSocket, (SOCKADDR*)&m_addr, sizeof(SOCKADDR));
		if(ret != SOCKET_ERROR){
			ret = listen(m_hSocket, 2);
			if(ret != SOCKET_ERROR){
				while(true){
					SOCKADDR_IN addr;
					int addrlen = sizeof(addr);
					SOCKET socket = accept(m_hSocket, (LPSOCKADDR)&addr, &addrlen);
					if(socket == SOCKET_ERROR){
						::Sleep(1);
						continue;
					}
					FCHttpDataEx *data = new FCHttpDataEx;
					data->m_addr = addr;
					data->m_socket = socket;
					HANDLE hThread = ::CreateThread(NULL, 0, receiveHandle2, (LPVOID)data, 0, 0);
					::CloseHandle(hThread);
				}
			}
		}
		if(m_hSocket){
			ret = closesocket(m_hSocket);
		}
		return ret;
	}
}