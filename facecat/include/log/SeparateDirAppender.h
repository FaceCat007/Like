/*
 * FaceCatͼ��ͨѶ���(�ǿ�Դ)
 * ����Ȩ���:2015SR229355+2020SR0266727
 * �Ϻ����è��Ϣ�������޹�˾
 */

#ifdef __SEPARATEDIRAPPENDER_H__
#else                                                                            
#define __SEPARATEDIRAPPENDER_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "FileAppender.h"
#include "RollingFileAppenderConfig.h"

namespace FaceCat{
    /*
	* �������ڷ�Ŀ¼�������־
	*/
    class __SEPARATEDIRAPPENDER_H__ SeparateDirAppender : public FileAppender{
	public:
		/*
		* ���캯��
		*/
        SeparateDirAppender();
        /*
		* ���캯��
		*/
        SeparateDirAppender(RollingFileAppenderConfig *fileAppenderConfig);
        /*
		* ���캯��
		*/
        SeparateDirAppender(const String &configPath);
        /*
		* ��������
		*/
        virtual ~SeparateDirAppender();
	private:
        /*
		* ��־�ļ�����
		*/
        String m_baseLogFileName;
		/*
		* �����ļ�
		*/
        RollingFileAppenderConfig *m_fileAppenderConfig;
	public:
		/*
		* ���ߴ�
		*/
        long m_maxFileSize;
	public:
        /*
		* ������־�ļ��Ĵ�С
		*/
        virtual void calculateLogFileSize();
	private:
        /*
		* ��ȡ��ǰ��־�ļ�������
		* @param curFileName ��ǰ�ļ�
		*/
        int getBackUpIndex(const String &curFileName);
		/*
		* ��ȡ�ļ���
		* @param filePath �ļ���
		*/
		String getFileNameFromFilePath(const String &filePath);
		/*
		* ���ļ�����ȡ��index
		* @param curFileName ��ǰ�ļ�
		* @param baseFileName �����ļ���
		* @param index ��������
		*/
		bool getIndexFromFileName(const String &curFileName, const String &baseFileName, int *index);
	public:
		/*
		* �����־
		* @param logType ��־����
		* @param message ��Ϣ
		*/
        void log(int logType, const String &message);
	};
}