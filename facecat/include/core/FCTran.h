/*
 * FaceCatͼ��ͨѶ���(�ǿ�Դ)
 * ����Ȩ���:2015SR229355+2020SR0266727
 * �Ϻ����è��Ϣ�������޹�˾
 */

#ifdef __FCTRAN_H__
#else                                                                            
#define __FCTRAN_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include <tchar.h>
#include "FCPaint.h"
#include "FCView.h"

namespace FaceCat{
	/*
	* �ַ���ת��
	*/
	class __FCTRAN_H__ CodeConvert_Win{
	public:
		CodeConvert_Win(const char* input, unsigned int fromCodePage, unsigned int toCodePage);
		~CodeConvert_Win(){
			delete [] wcharBuf;        
			delete [] charBuf;    
			};    
			const char * toString(){    
				return charBuf;    
			};
	private:    
		  wchar_t * wcharBuf;    
		  char * charBuf;
	};

	class __FCTRAN_H__ StrCoding
	{
	public:
		StrCoding();
		~StrCoding();
		static std::string UrlGB2312(const std::string &str);						//urlgb2312����
		static std::string UrlUTF8(const std::string &str);						//urlutf8 ����
		static std::string UrlUTF8Decode(const std::string &str);					//urlutf8����
		static std::string UrlGB2312Decode(const std::string &str);				//urlgb2312����
		static void UTF_8ToGB2312(std::string &sOut, const std::string &str);	//utf_8תΪgb2312
		static void GB2312ToUTF_8(std::string &sOut, const std::string &str);	//gb2312 תutf_8
	private:
		static void Gb2312ToUnicode(wchar_t* pOut, const char *gbBuffer);
		static void UTF_8ToUnicode(wchar_t* pOut, const char *pText);
		static void UnicodeToUTF_8(char *pOut, wchar_t* pText);
		static void UnicodeToGB2312(char *pOut, wchar_t uData);
		static char  CharToInt(char ch);
		static char StrToBin(char *str);
	};

	/*
	* �ַ�������
	*/
	class __FCTRAN_H__ FCTran{
	public:
		static double round(double x); 
	public:
		/*
		* ����ת��
		*/
		static void ANSCToUnicode(string& out, const char* inSrc);
	    /**
         * ê����Ϣת��Ϊ�ַ�
         * @param anchor  ê����Ϣ
         * @returns �ַ�
        */
		static String anchorToStr(const FCAnchor& anchor);
	    /**
         * ��������ֵת��Ϊ�ַ�
         * @param value   ��ֵ
         * @returns �ַ�
        */
		static String boolToStr(bool value);
	    /**
         * ��ɫת��Ϊ�ַ�
         * @param color  ��ɫ
         * @returns �ַ�
        */
		static String colorToStr(Long color);
	    /**
         * ���ݲ���ת�ַ���
         * @param contentAlignment  ���ݲ���
         * @returns �ַ���
        */
		static String contentAlignmentToStr(FCContentAlignment contentAlignment);
		/*
		* �����״תΪ�ַ���
		*/
		static String cursorToStr(FCCursors cursor);
	    /**
         * ˫���ȸ�������ֵת��Ϊ�ַ�
         * @param value  ��ֵ
         * @returns �ַ�
        */
		static String doubleToStr(double value);
	    /**
         * ����Ϣת��Ϊ�ַ�
         * @param dock  ����Ϣ
         * @returns �ַ�
        */
		static String dockToStr(FCDockStyle dock);
	    /**
         * �����ȸ���������ֵת��Ϊ�ַ�
         * @param value  ��ֵ
         * @returns �ַ�
        */
		static String floatToStr(float value);
	    /**
         * ����ת��Ϊ�ַ�
         * @param font  ����
         * @returns �ַ�
        */
		static String fontToStr(FCFont *font);
	    /**
         * �������з�ʽת��Ϊ�ַ�
         * @param horizontalAlign  �������з�ʽ
         * @returns �ַ�
        */
		static String horizontalAlignToStr(FCHorizontalAlign horizontalAlign);
	    /**
         * ������ֵת��Ϊ�ַ�
         * @param value  ��ֵ
         * @returns �ַ�
        */
		static String intToStr(int value);
	    /**
         * ������ʽת��Ϊ�ַ�
         * @param layoutStyle  ������ʽת
         * @returns ������ʽ
        */
		static String layoutStyleToStr(FCLayoutStyle layoutStyle);
	    /**
         * ��������ֵת��Ϊ�ַ�
         * @param value   ��ֵ
         * @returns �ַ���
        */
		static String longToStr(Long value);
	    /**
         * �߾�ת��Ϊ�ַ�
         * @param padding  �߾�
         * @returns �ַ�
        */
		static String paddingToStr(const FCPadding& padding);
	    /**
         * ����ת��Ϊ�ַ�
         * @param point  ����
         * @returns �ַ�
        */
		static String pointToStr(const FCPoint& mp);
	    /**
         * ����ת��Ϊ�ַ�
         * @param rect  ����
         * @returns �ַ�
        */
		static String rectToStr(const FCRect& rect);
	    /**
         * ��Сת��Ϊ�ַ�
         * @param size  ��С
         * @returns �ַ�
        */
		static String sizeToStr(const FCSize& size);
	    /**
         * �ַ�ת��Ϊê����Ϣ
         * @param str  �ַ�
         * @returns ê����Ϣ
        */
		static FCAnchor strToAnchor(const String& str);
	    /**
         * �ַ�ת��Ϊ������
         * @param str  �ַ�
         * @returns ��ֵ
        */
		static bool strToBool(const String& str);
	    /**
         * �ַ�ת��Ϊ��ɫ
         * @param str  �ַ�
         * @returns ��ɫ
        */
		static Long strToColor(const String& str);
	    /**
         * �ַ���ת���ݲ���
         * @param str  �ַ�
         * @returns �ַ���
        */
		static FCContentAlignment strToContentAlignment(const String& str);
		/*
		* �ַ���תΪ�����״
 		*/
		static FCCursors strToCursor(const String& str);
	    /**
         * �ַ�ת��Ϊ����Ϣ
         * @param str  �ַ�
         * @returns ����Ϣ
        */
		static FCDockStyle strToDock(const String& str);
	    /**
         * �ַ�ת��Ϊ˫���ȸ�������ֵ
         * @param str  �ַ�
         * @returns ��ֵ
        */
		static double strToDouble(const String& str);
		/*
		* �ַ�ת��Ϊ˫���ȸ�������ֵ
		*/
		static double strToDouble(const wchar_t *str);
	    /**
         * �ַ�ת��Ϊ�����ȸ�������ֵ
         * @param str  �ַ�
         * @returns ��ֵ
        */
		static float strToFloat(const String& str);
	    /**
         * �ַ�ת��Ϊ����
         * @param str  �ַ�
         * @returns ����
        */
		static FCFont strToFont(const String& str);
	    /**
         * �ַ�ת��Ϊ�������з�ʽ
         * @param str  �ַ�
         * @returns �ַ�
        */
		static FCHorizontalAlign strToHorizontalAlign(const String& str);
	    /**
         * �ַ�ת��Ϊ������ֵ
         * @param str  �ַ�
         * @returns ��ֵ
        */
		static int strToInt(const String& str);
		/**
         * �ַ�ת��Ϊ������ֵ
         * @param str  �ַ�
         * @returns ��ֵ
        */
		static int strToInt(const wchar_t *str);
	    /**
         * ������ʽת��Ϊ�ַ�
         * @param str  �ַ�
         * @returns ������ʽ
        */
		static FCLayoutStyle strToLayoutStyle(const String& str);
	    /**
         * �ַ�ת��λ��������ֵ
         * @param str  �ַ���
         * @returns ������
        */
		static Long strToLong(const String& str);
		/*
		* �ַ�ת��λ��������ֵ
		*/
		static Long strToLong(const wchar_t *str);
	    /**
         * �ַ�ת��Ϊ�߾�
         * @param str  �ַ�
         * @returns �߾�
        */
		static FCPadding strToPadding(const String& str);
	    /**
         * �ַ�ת��Ϊ����
         * @param str  �ַ�
         * @returns ����
        */
		static FCPoint strToPoint(const String& str);
	    /**
         * �ַ�ת��Ϊ����
         * @param str  �ַ�
         * @returns ����
        */
		static FCRect strToRect(const String& str);
	    /**
         * �ַ�ת��Ϊ��С
         * @param str  �ַ�
         * @returns ��С
        */
		static FCSize strToSize(const String& str);
	    /**
         * �ַ�ת��Ϊ�������з�ʽ
         * @param str  �ַ�
         * @returns �ַ�
        */
		static FCVerticalAlign strToVerticalAlign(const String& str);
	    /**
         * �������з�ʽת��Ϊ�ַ�
         * @param verticalAlign  �������з�ʽ
         * @returns �ַ�
        */
		static String verticalAlignToStr(FCVerticalAlign verticalAlign);
		/*
		* ��ȡ����·��
		*/
		static string getAppPath();
		/*
		* ��ȡ���ڵ���ֵ
		*/
		static double getDateNum(int tm_year, int tm_mon, int tm_mday, int tm_hour, int tm_min, int tm_sec, int tm_msec);
		/*
		* ������ֵ��ȡ����
		*/
        static void getDateByNum(double num, int *tm_year, int *tm_mon, int *tm_mday, int *tm_hour, int *tm_min, int *tm_sec, int *tm_msec);
	    /**
         * ��ȡGuid
         * @returns  Guid
        */
		static string getGuid();
		/*
		* ��ȡ��ʽ���������
		*/
		static String getFormatDate(double date);
		/*
		* ��ȡ��ʽ���������
		*/
		static String getFormatDate(const String& format, int year, int month, int day, int hour, int minute, int second);
	    /**
         * ���ݱ���С����λ�ý�double��ת��ΪString��
         * @param value  ֵ
         * @param digit ����С����
         * @returns  ��ֵ�ַ�
        */
		static String getValueByDigit(double value, int digit);
		/*
		* ʮ������תʮ����
		*/
		static int hexToDec(const char *str);
		/*
		* �滻�ַ���
		*/
		static string replace(const string& str, const string& src, const string& dest);
		/*
		* �滻�ַ���
		*/
		static String replace(const String& str, const String& src, const String& dest);
	    /**
         * ��ȫ��DoubleתFloat
         * @param value  ֵ
         * @param digit ����С��λ��
         * @returns  Float
        */
		static float safeDoubleToFloat(double value, int digit);
		/*
		* �ָ��ַ���
		*/
		static ArrayList<String> split(const String& str, const String& pattern);
		/*
		* ���ַ���ת���ַ���
		*/
		static String stringToString(const string& strSrc);
		/*
		* תΪСд
		*/
		static String toLower(const String& str);
		/*
		* תΪ��д
		*/
		static String toUpper(const String& str);
		/*
		* �ַ��������ʽת��
		*/
		static void unicodeToANSC(string& out, const char* inSrc);
		/*
		* ���ַ���ת���ַ���
		*/
		static string StringTostring(const String& strSrc);
	};
}