/*
 * FaceCatͼ��ͨѶ���(�ǿ�Դ)
 * ����Ȩ���:2015SR229355+2020SR0266727
 * �Ϻ����è��Ϣ�������޹�˾
 */

#ifdef __FCTEXTBOX_H__
#else                                                                            
#define __FCTEXTBOX_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "..\\scroll\\FCHScrollBar.h"
#include "..\\scroll\\FCVScrollBar.h"
#include "..\\div\\FCDiv.h"
#include <stack>

namespace FaceCat{
	/*
	* ��
	*/
	struct __FCTEXTBOX_H__ FCWordLine{
	public:
	    /**
		 * ��������
		 */
		int m_end;
		/**
		 * ��ʼ����
		 */
		int m_start;
		/*
         * �к�
         */
        int m_line;
		FCWordLine(int start, int end){
			m_start = start;
			m_end = end;
			m_line = 0;
		}
	};

	/*
	* �����ظ���Ϣ
	*/
	class __FCTEXTBOX_H__ FCRedoUndoInfo
    {
	public:
		/*
		* ѡ�п�ʼλ��
		*/
        int m_selectionStart;

        /*
		* ѡ�г���
		*/
        int m_selectionLength;

        /*
		* ����
		*/
        String m_text;

        /*
		* ������Ϣ
		*/
        FCRedoUndoInfo(String text, int selectionStart, int selectionLength)
        {
            m_text = text;
            m_selectionStart = selectionStart;
            m_selectionLength = selectionLength;
        }
    };

	/*
	* �ı���
	*/
	class __FCTEXTBOX_H__ FCTextBox : public FCDiv{
	private:
		/*
		* TICKֵ
		*/
		int m_tick;
		/**
		 * ���ID
		 */
		int m_timerID;
	public:
		/*
         * �ı�ID
         */
        int m_changeID;
		/*
		* ��������
		*/
		FCPoint m_cursorPoint;
		/*
		* �Ƿ����ڸ���
		*/
		bool m_isCopy;
	    /**
		 * �����Ƿ���
		 */
		bool m_isKeyDown;
		/**
		 * �Ƿ�������
		 */
		bool m_isTouchDown;
		/**
		 * �и�
		 */
		int m_lineHeight;
		/**
		 * ����
		 */
		vector<FCWordLine> m_lines;
		/**
		 * �Ƿ������ʾ
		 */
		bool m_multiline;
		/**
		 * ����ƫ����
		 */
		int m_offsetX;
		/**
		 * �����ַ�
		 */
		wchar_t m_passwordChar;
		/**
		 * ���־��η�Χ
		 */
		vector<FCRectF> m_ranges;
		/**
		 * ����ջ
		 */
		stack<FCRedoUndoInfo> m_redoStack;
		/**
		 * �Ƿ�ֻ��
		 */
		bool m_readOnly;
		/**
		 * �Ƿ�����������
		 */
		bool m_rightToLeft;
		/**
		 * ѡ�еı���ɫ
		 */
		Long m_selectionBackColor;
		/**
		 * ѡ�е�ǰ��ɫ
		 */
		Long m_selectionTextColor;
		/**
		 * ѡ�г���
		 */
		int m_selectionLength;
		/**
		 * ѡ�п�ʼλ��
		 */
		int m_selectionStart;
		/**
		 * �Ƿ���ʾ���
		 */
		bool m_showCursor;
		/**
		 * ��ʼ�ƶ�������
		 */
		int m_startMovingIndex;
		/**
		 * �����ƶ�������
		 */
		int m_stopMovingIndex;
		/**
		 * ��ʱ����
		 */
		String m_tempText;
		/**
		 * ��ʱ���ֵ���ɫ
		 */
		Long m_tempTextColor;
		/**
		 * ���ݵĺ���������ʽ
		 */
		FCHorizontalAlign m_textAlign;
		/**
		 * �����Ƿ�ı�
		 */
		bool m_textChanged;
		/**
		 * �����˸Ƶ��
		 */
		int TICK;
		/**
		 * ����ջ
		 */
		stack<FCRedoUndoInfo> m_undoStack;
		/**
		 * ���ִ�С
		 */
		vector<FCSizeF> m_wordsSize;
		/**
		 * ���б༭��ͼ�Ƿ���������
		 */
		bool m_wordWrap;
		/**
		 * ��������ƶ�
		 */
		virtual void cursorDown();
		/**
		 * ����ƶ������Ҷ�
		 */
		virtual void cursorEnd();
		/**
		 * ����ƶ��������
		 */
		virtual void cursorHome();
		/**
		 * ��������ƶ�
		 */
		virtual void cursorLeft();
		/**
		 * ��������ƶ�
		 */
		virtual void cursorRight();
		/**
		 * ��������ƶ�
		 */
		virtual void cursorUp();
		/**
		 * ɾ���ַ�
		 */
		virtual void deleteWord();
		/**
		 * �����ַ�
		 */
		virtual void insertWord(const String& str);
		/**
		 * �ж��ַ������������Ƿ�ɼ�
		 */
		virtual bool isLineVisible(int indexTop, int indexBottom, int cell, int floor, int lineHeight, double visiblePercent);
		/*
		* �ж��ַ������������Ƿ�ɼ�
		*/
		virtual bool isLineVisible(int index, double visiblePercent);
		/**
		 * �����ƶ�����
		 */
		virtual void setMovingIndex(int sIndex, int eIndex);
	public:
		/*
		* ���캯��
		*/
		FCTextBox();
		/*
		* ��������
		*/
		virtual ~FCTextBox();
		/*
		* ��ȡ��������
		*/
		virtual FCPoint getCursorPoint();
		/*
		* ���ù�������
		*/
		virtual void setCursorPoint(const FCPoint& value);
		/**
		 * ��ȡ����
		 */
		virtual int getLinesCount();
		/**
		 * ��ȡ�и�
		 */
		virtual int getLineHeight();
		/**
		 * �����и�
		 */
		virtual void setLineHeight(int value);
		/**
		 * ��ȡ����
		 */
		virtual vector<FCWordLine> getLines();
		/**
		 * ��ȡ�Ƿ������ʾ
		 */
		virtual bool isMultiline();
		/**
		 * �����Ƿ������ʾ
		 */
		virtual void setMultiline(bool value);
		/**
		 * ��ȡ�����ַ�
		 */
		virtual wchar_t getPasswordChar();
		/**
		 * ���������ַ�
		 */
		virtual void setPasswordChar(wchar_t value);
		/**
		 * ��ȡ�Ƿ�ֻ��
		 */
		virtual bool isReadOnly();
		/**
		 * �����Ƿ�ֻ��
		 */
		virtual void setReadOnly(bool value);
		/**
		 * ��ȡ�Ƿ�����������
		 */
		virtual bool isRightToLeft();
		/**
		 * �����Ƿ�����������
		 */
		virtual void setRightToLeft(bool value);
		/**
		 * ��ȡѡ�еı���ɫ
		 */
		virtual Long getSelectionBackColor();
		/**
		 * ����ѡ�еı���ɫ
		 */
		virtual void setSelectionBackColor(Long value);
		/**
		 * ��ȡѡ�е�ǰ��ɫ
		 */
		virtual Long getSelectionTextColor();
		/**
		 * ����ѡ�е�ǰ��ɫ
		 */
		void setSelectionTextColor(Long value);
		/**
		 * ��ȡѡ�г���
		 */
		virtual int getSelectionLength();
		/**
		 * ����ѡ�г���
		 */
		virtual void setSelectionLength(int value);
		/**
		 * ��ȡѡ�п�ʼλ��
		 */
		virtual int getSelectionStart();
		/**
		 * ����ѡ�п�ʼλ��
		 */
		virtual void setSelectionStart(int value);
		/**
		 * ��ȡ��ʱ����
		 */
		virtual String getTempText();
		/**
		 * ������ʱ����
		 */
		virtual void setTempText(const String& value);
		/**
		 * ��ȡ��ʱ���ֵ���ɫ
		 */
		virtual Long getTempTextColor();
		/**
		 * ������ʱ���ֵ���ɫ
		 */
		virtual void setTempTextColor(Long value);
		/**
		 * ��ȡ���ݵĺ���������ʽ
		 */
		virtual FCHorizontalAlign getTextAlign();
		/**
		 * �������ݵĺ���������ʽ
		 */
		virtual void setTextAlign(FCHorizontalAlign value);
		/**
		 * ��ȡ���б༭��ͼ�Ƿ���������
		 */
		virtual bool isWordWrap();
		/**
		 * ���ö��б༭��ͼ�Ƿ���������
		 */
		virtual void setWordWrap(bool value);
	public:
	    /**
		 * �ж��Ƿ�����ظ�
		 */
		virtual bool canRedo();
		/**
		 * �ж��Ƿ���Գ���
		 */
		virtual bool canUndo();
		/**
		 * ����
		 */
		virtual void clearRedoUndo();
		/**
		 * ��ȡ���ݵĸ߶�
		 */
		virtual int getContentHeight();
		/**
		 * ��ȡ���ݵĿ��
		 */
		virtual int getContentWidth();
		/**
		 * ��ȡ��ͼ����
		 */
		virtual String getViewType();
		/**
		* ��ȡ����ֵ
		* @param  name  ��������
		* @param  value  ��������ֵ
		* @param  type  ������������
		*/
		virtual void getAttribute(const String& name, String *value, String *type);
		/**
		 * ��ȡ���������б�
		 */
		virtual ArrayList<String> getAttributeNames();
		/**
		 * ��ȡѡ�е�����
		 */
		virtual String getSelectionText();
		/**
		 * �ı����뷽��
		 */
		virtual void onChar(wchar_t ch);
		/**
		 * ��������
		 */
		virtual void onCopy();
		/**
		 * ����
		 */
		virtual void onCut();
		/**
		 * ��ȡ���㷽��
		 */
		virtual void onGotFocus();
		/**
		 * ���̷���
		 */
		virtual void onKeyDown(char key);
		/**
		 * ����̧�𷽷�
		 */
		virtual void onKeyUp(char key);
		/**
		 * ��ʧ���㷽��
		 */
		virtual void onLostFocus();
		/**
		 * �������·���
		 */
		virtual void onTouchDown(FCTouchInfo touchInfo);
		/**
		 * �����ƶ�����
		 */
		virtual void onTouchMove(FCTouchInfo touchInfo);
		/**
		 * ����̧�𷽷�
		 */
		virtual void onTouchUp(FCTouchInfo touchInfo);
		/**
		 * �ػ�ǰ������
		 */
		virtual void onPaintForeground(FCPaint *paint, const FCRect& clipRect);
		/**
		 * ճ������
		 */
		virtual void onPaste();
		/**
		 * ���ֳߴ�ı��¼�
		 */
		virtual void onSizeChanged();
		/**
		 * ��ʹ��TAB�л�����
		 */
		virtual void onTabStop();
		/**
		 * ���ָı䷽��
		 */
		virtual void onTextChanged();
		/**
		 * ���ص�����
		 */
		virtual void onTimer(int timerID);
		/**
		 * �ظ�
		 */
		virtual void redo();
		/**
		 * ȫѡ
		 */
		virtual void selectAll();
		/**
		* ��������
		* @param  name  ��������
		* @param  value  ����ֵ
		*/
		virtual void setAttribute(const String& name, const String& value);
		/**
		 * ����
		 */
		virtual void undo();
		/**
		 * ���²��ַ���
		 */
		virtual void update();
	};
}