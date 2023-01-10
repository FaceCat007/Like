/*
 * FaceCatͼ��ͨѶ���(�ǿ�Դ)
 * ����Ȩ���:2015SR229355+2020SR0266727
 * �Ϻ����è��Ϣ�������޹�˾
 */

#ifdef __FCTREE_H__
#else                                                                            
#define __FCTREE_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "..\\grid\\FCGrid.h"
#include "..\\grid\\FCGridColumn.h"
#include "..\\grid\\FCGridRow.h"
#include "..\\grid\\FCGridCell.h"
#include "..\\grid\\FCGridCellExtends.h"
#include "FCTreeNode.h"

namespace FaceCat{
	class FCTreeNode;

	/*
	* ����ͼ
	*/
	class __FCTREE_H__ FCTree:public FCGrid{
	public:
	    /**
		 * �Ƿ��ڽڵ�����ʾ��ѡ��
		 */
		bool m_checkBoxes;
		/**
		 * ��ѡ��Ĵ�С
		 */
		FCSize m_checkBoxSize;
		/**
		 * ѡ��ѡ��ʱ��ͼƬ
		 */
		String m_checkedImage;
		/**
		 * �۵��ڵ��ͼƬ
		 */
		String m_collapsedNodeImage;
		/**
		 * չ���ڵ��ͼƬ
		 */
		String m_expendedNodeImage;
		/**
		 * �����ƶ��Ľڵ�
		 */
		FCTreeNode *m_movingNode;
		/**
		 * �ڵ�Ĵ�С
		 */
		FCSize m_nodeSize;
		/**
		 * ��ѡ��δѡ��ʱ��ͼƬ
		 */
		String m_unCheckedImage;
	public:
		/*
		* �ڵ�
		*/
		ArrayList<FCTreeNode*> m_nodes;
		/*
		* ���캯��
		*/
		FCTree();
		/*
		* ��������
		*/
		virtual ~FCTree();
		/**
		 * ��ȡ�Ƿ��ڽڵ�����ʾ��ѡ��
		 */
		virtual bool hasCheckBoxes();
		/**
		 * �����Ƿ��ڽڵ�����ʾ��ѡ��
		 */
		virtual void setCheckBoxes(bool value);
		/**
		 * ��ȡ��ѡ��Ĵ�С
		 */
		virtual FCSize getCheckBoxSize();
		/**
		 * ���ø�ѡ��Ĵ�С
		 */
		virtual void setCheckBoxSize(FCSize value);
		/**
		 * ��ȡ��ѡ��ѡ��ʱ��ͼƬ
		 */
		virtual String getCheckedImage();
		/**
		 * ���ø�ѡ��ѡ��ʱ��ͼƬ
		 */
		virtual void setCheckedImage(const String& value);
		/**
		 * ��ȡ�۵��ڵ��ͼƬ
		 */
		virtual String getCollapsedNodeImage();
		/**
		 * �����۵��ڵ��ͼƬ
		 */
		virtual void setCollapsedNodeImage(const String& value);
		/**
		 * ��ȡչ���ڵ��ͼƬ
		 */
		virtual String getExpendedNodeImage();
		/**
		 * ����չ���ڵ��ͼƬ
		 */
		virtual void setExpendedNodeImage(const String& value);
		/**
		 * ��ȡ�ڵ�Ĵ�С
		 */
		virtual FCSize getNodeSize();
		/**
		 * ���ýڵ�Ĵ�С
		 */
		virtual void setNodeSize(FCSize value);
		/**
		 * ��ȡѡ�еĽڵ�
		 */
		virtual ArrayList<FCTreeNode*> getSelectedNodes();
		/**
		 * ����ѡ�еĽڵ�
		 */
		virtual void setSelectedNodes(ArrayList<FCTreeNode*> value);
		/**
		 * ��ȡ��ѡ��δѡ��ʱ��ͼƬ
		 */
		virtual String getUnCheckedImage();
		/**
		 * ���ø�ѡ��δѡ��ʱ��ͼƬ
		 */
		virtual void setUnCheckedImage(const String& value);
	public:
	    /**
		 * ��ӽڵ�
		 */
		void appendNode(FCTreeNode *node);
		/**
		 * ������нڵ�
		 */
		void clearNodes();
		/**
		 * �۵��ڵ�
		 */
		void collapse();
		/**
		 * �۵����нڵ�
		 */
		void collapseAll();
		/**
		 * չ���ڵ�
		 */
		void expend();
		/**
		 * չ�����нڵ�
		 */
		void expendAll();
		/**
		 * ��ȡ�ӽڵ�
		 */
		ArrayList<FCTreeNode*> getChildNodes();
		/**
		 * ��ȡ��ͼ����
		 */
		virtual String getViewType();
		/**
		 * ��ȡ�ڵ������
		 */
		int getNodeIndex(FCTreeNode *node);
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
		 * ����ڵ�
		 */
		void insertNode(int index, FCTreeNode *node);
		/**
		 * ��Ԫ�������·���
		 */
		virtual void onCellTouchDown(FCGridCell *cell, FCTouchInfo touchInfo);
		/**
		 * ��Ԫ�����ƶ�����
		 */
		virtual void onCellTouchMove(FCGridCell *cell, FCTouchInfo touchInfo);
		/**
		 * ��Ԫ����̧�𷽷�
		 */
		virtual void onCellTouchUp(FCGridCell *cell, FCTouchInfo touchInfo);
		/**
		 * �ػ�ǰ������
		 */
		virtual void onPaintForeground(FCPaint *paint, const FCRect& clipRect);
		/**
		 * ���Ʊ༭�ı���
		 */
		virtual void onPaintEditTextBox(FCGridCell *cell, FCPaint *paint, const FCRect& rect, const FCRect& clipRect);
		/**
		 * �Ƴ��ڵ�
		 */
		void removeNode(FCTreeNode *node);
		/**
		 * ��������
		 */
		virtual void setAttribute(const String& name, const String& value);
	};
}
