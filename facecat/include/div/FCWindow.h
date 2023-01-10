/*
 * FaceCatͼ��ͨѶ���(�ǿ�Դ)
 * ����Ȩ���:2015SR229355+2020SR0266727
 * �Ϻ����è��Ϣ�������޹�˾
 */

#ifdef __FCWINDOW_H__
#else                                                                            
#define __FCWINDOW_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "..\\btn\\FCButton.h"
#include "FCWindowFrame.h"

namespace FaceCat{
	class FCWindowFrame;

	/*
	* �رմ����¼�
	*/
    class __FCWINDOW_H__ FCWindowClosingEventCallBack
    {
	public:
		FCWindowClosingEventCallBack(){}
		virtual ~FCWindowClosingEventCallBack(){}
		virtual void callWindowClosingEvent(String eventName, Object sender, bool *cancel, Object invoke){}
    };

	/*
	* ����
	*/
	class __FCWINDOW_H__ FCWindow : public FCView{
	public:
		int m_borderWidth;
		/**
		 * �Ƿ���Ե����ߴ�
		 */
		bool m_canResize;
		/**
		 * �������ĸ߶�
		 */
		int m_captionHeight;
		/**
		 * �����
		 */
		FCWindowFrame *m_frame;
		/**
		 * �Ƿ�Ự����
		 */
		bool m_isDialog;
		/**
         * �ϴ�����
         */
        FCPoint m_oldLocation;
		/**
		 * �����ߴ�ĵ�
		 */
		int m_resizePoint;
		/**
		 * ��Ӱ����ɫ
		 */
		Long m_shadowColor;
		/**
		 * ��Ӱ�Ĵ�С
		 */
		int m_shadowSize;
		/**
		 * �ƶ���ʼ��
		 */
		FCPoint m_startTouchPoint;
		/**
		 * �ƶ���ʼʱ����ͼ����
		 */
		FCRect m_startRect;
		/**
		 * �Ƿ�ʹ�ÿ��
		 */
		bool m_useFrame;
	public:
		/**
		* �����¼�
		* @param  eventName  �¼�ID
		* @param  cancel   �Ƿ��˳�
		*/
		void callWindowClosingEvents(String eventName, bool *cancel);
		/**
		* ��ȡ����״̬
		* @param  state  ״ֵ̬
		*/
		FCCursors getResizeCursor(int state);
		/**
		 * ��ȡ�����ߴ�ĵ�
		 */
		ArrayList<FCRect> getResizePoints();
		/**
		 * ��ȡ�����ߴ��״̬
		 */
		int getResizeState();
	public:
		FCWindow();
		virtual ~FCWindow();
		/**
		 * ��ȡ�߿�Ŀ��
		 */
		virtual int getBorderWidth();
		/**
		 * ���ñ߿�Ŀ��
		 */
		virtual void setBorderWidth(int value);
		/**
		 * ��ȡ�������ĸ߶�
		 */
		virtual int getCaptionHeight();
		/**
		 * ���ñ������ĸ߶�
		 */
		virtual void setCaptionHeight(int value);
		/**
		 * ��ȡ�Ƿ���Ե����ߴ�
		 */
		virtual bool canResize();
		/**
		 * �����Ƿ���Ե����ߴ�
		 */
		virtual void setCanResize(bool value);
		/**
		 * ��ȡ�����
		 */
		virtual FCWindowFrame* getFrame();
		/**
		 * ���ô����
		 */
		virtual void setFrame(FCWindowFrame *value);
		/**
		 * ��ȡ�Ƿ�Ự����
		 */
		virtual bool isDialog();
		/**
         * ���ÿؼ���λ��
         */
        virtual void setLocation(const FCPoint& value);
		/**
		 * ��ȡ��Ӱ����ɫ
		 */
		virtual Long getShadowColor();
		/**
		 * ������Ӱ����ɫ
		 */
		virtual void setShadowColor(Long value);
		/**
		 * ��ȡ��Ӱ�Ĵ�С
		 */
		virtual int getShadowSize();
		/**
		 * ������Ӱ�Ĵ�С
		 */
		virtual void setShadowSize(int value);
		/**
		 * �Ƿ�ʹ�ÿ��
		 */
		virtual bool useFrame();
		/**
		 * �Ƿ�ʹ�ÿ��
		 */
		virtual void setUseFrame(bool value);
	public:
	    /**
		 * ����ͼ�ŵ���ǰ��ʾ
		 */
		virtual void bringToFront();
		/**
		 * �رմ���
		 */
		virtual void close();
		/**
		 * ��ȡ��ͼ����
		 */
		virtual String getViewType();
		/**
		 * ��ȡ��̬��ͼ����
		 */
		FCRect getDynamicPaintRect();
		/**
		* ��ȡ����ֵ
		* @param  name   ��������
		* @param  value   ��������ֵ
		* @param  type   ������������
		*/
		virtual void getAttribute(const String& name, String *value, String *type);
		/**
		 * ��ȡ�����б�
		 */
		virtual ArrayList<String> getAttributeNames();
		/**
         * ��ȡ�����б�
         */
        virtual ArrayList<String> getEventNames();
		/**
		 * ������ʼ����
		 */
		virtual bool onDragBegin();
		/**
		* �϶�׼������
		* @param  startOffset  �����϶���ƫ��������
		*/
		virtual void onDragReady(FCPoint *startOffset);
		/**
		* �������·���
         * @param  touchInfo  ������Ϣ
		*/
		virtual void onTouchDown(FCTouchInfo touchInfo);
		/**
		* �����ƶ�����
         * @param  touchInfo  ������Ϣ
		*/
		virtual void onTouchMove(FCTouchInfo touchInfo);
		/**
		* ����̧�𷽷�
         * @param  touchInfo  ������Ϣ
		*/
		virtual void onTouchUp(FCTouchInfo touchInfo);
		/**
		* ����ǰ������
		* @param  paint   ��ͼ����
		* @param  clipRect  �ü�����
		*/
		virtual void onPaintForeground(FCPaint *paint, const FCRect& clipRect);
		/**
		 * �ɼ�״̬�ı䷽��
		 */
		virtual void onVisibleChanged();
		/**
		* �������ڹرշ���
		* @param  cancel  �Ƿ��˳�
		*/
		virtual void onWindowClosing(bool *cancel);
		/**
		 * ����رշ���
		 */
		virtual void onWindowClosed();
		/**
		 * ����ͼ�ŵ���������ʾ
		 */
		virtual void sendToBack();
		/**
		* ��������ֵ
		* @param  name   ��������
		* @param  value   ����ֵ
		*/
		virtual void setAttribute(const String& name, const String& value);
		/**
		 * �ԻỰ��ʽ��ʾ
		 */
		virtual void showDialog();
		/*
         * ���²��ַ���
         */
        virtual void update();
	};
}