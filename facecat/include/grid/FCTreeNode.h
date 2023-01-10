/*
 * FaceCatͼ��ͨѶ���(�ǿ�Դ)
 * ����Ȩ���:2015SR229355+2020SR0266727
 * �Ϻ����è��Ϣ�������޹�˾
 */

#ifdef __FCTREENODE_H__
#else                                                                            
#define __FCTREENODE_H__ _declspec(dllexport) 
#endif
#pragma once
#include "..\\..\\stdafx.h"
#include "..\\grid\\FCGrid.h"
#include "..\\grid\\FCGridRow.h"
#include "..\\grid\\FCGridCell.h"
#include "..\\btn\\FCCheckBox.h"
#include "FCTree.h"

namespace FaceCat{
	class FCTree;

	/*
	* ���ڵ�
	*/
	class __FCTREENODE_H__ FCTreeNode : public FCGridViewCell{
	public:
	    /**
		 * �Ƿ��������ڵ�
		 */
		bool m_allowDragIn;
		/**
		 * �Ƿ�����ϳ��ڵ�
		 */
		bool m_allowDragOut;
		/**
		 * ��ѡ���Ƿ�ѡ��
		 */
		bool m_checked;
		/**
		 * �ӽڵ�
		 */
		ArrayList<FCTreeNode*> m_nodes;
		/**
		 * �Ƿ�չ���ڵ�
		 */
		bool m_expended;
		/**
		 * ������������
		 */
		int m_indent;
		/**
		 * ���ڵ�
		 */
		FCTreeNode *m_parent;
		/**
		 * Ŀ����
		 */
		FCGridColumn *m_targetColumn;
		/**
		 * ����
		 */
		String m_text;
		/**
		 * ����ͼ
		 */
		FCTree *m_tree;
		/**
		 * ֵ
		 */
		String m_value;
		/**
		 * ѡ�������ӽڵ�
		 */
		void checkChildNodes(ArrayList<FCTreeNode*> nodes, bool isChecked);
		/**
		 * �۵��ӽڵ�
		 */
		void collapseChildNodes(ArrayList<FCTreeNode*> nodes, bool collapseAll);
		/**
		 * չ�����еĽڵ�
		 */
		void expendChildNodes(ArrayList<FCTreeNode*> nodes, bool parentExpened, bool expendAll);
		/**
		 * ��ȡ���ڵ������
		 */
		FCTreeNode* getLastNode(ArrayList<FCTreeNode*> nodes);
	public:
		/*
		* ���캯��
		*/
		FCTreeNode();
		/*
		* ��������
		*/
		virtual ~FCTreeNode();
		/**
		 * ��ȡ�Ƿ��������ڵ�
		 */
		virtual bool allowDragIn();
		/**
		 * �����Ƿ��������ڵ�
		 */
		virtual void setAllowDragIn(bool value);
		/**
		 * ��ȡ�Ƿ�����ϳ��ڵ�
		 */
		virtual bool allowDragOut();
		/**
		 * �����Ƿ�����ϳ��ڵ�
		 */
		virtual void setAllowDragOut(bool value);
		/**
		 * ��ȡ��ѡ���Ƿ�ѡ��
		 */
		virtual bool isChecked();
		/**
		 * ���ø�ѡ���Ƿ�ѡ��
		 */
		virtual void setChecked(bool value);
		/**
		 * ��ȡ�Ƿ�չ���ڵ�
		 */
		virtual bool isExpended();
		/**
		 * �����Ƿ�չ���ڵ�
		 */
		virtual void setExpended(bool value);
		/**
		 * ��ȡ������������
		 */
		virtual int getIndent();
		/**
		 * ��ȡ���ڵ�
		 */
		virtual FCTreeNode* getParent();
		/**
		 * ���ø��ڵ�
		 */
		virtual void setParent(FCTreeNode *value);
		/**
		 * ��ȡĿ����
		 */
		virtual FCGridColumn* getTargetColumn();
		/**
		 * ����Ŀ����
		 */
		virtual void setTargetColumn(FCGridColumn *value);
		/**
		 * ��ȡ����ͼ
		 */
		virtual FCTree* getTree();
		/**
		 * ��������ͼ
		 */
		virtual void setTree(FCTree *value);
		/**
		 * ��ȡֵ
		 */
		virtual String getValue();
		/**
		 * ����ֵ
		 */
		virtual void setValue(const String& value);
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
		 * ��ȡ�ڵ������
		 */
		int getNodeIndex(FCTreeNode *node);
		/**
		 * ��ȡҪ���Ƶ��ı�
		 */
		virtual String getPaintText();
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
		 * ��ȡ�ַ�����ֵ
		 */
		virtual String getString();
		/**
		 * ����ڵ�
		 */
		void insertNode(int index, FCTreeNode *node);
		/**
		 * ���ڵ��Ƿ�ɼ�
		 */
		bool isNodeVisible(FCTreeNode *node);
		/**
		 * ��ӽڵ�
		 */
		virtual void onAddingNode(int index);
		/**
		 * ���Ƹ�ѡ��
		 */
		virtual void onPaintCheckBox(FCPaint *paint, const FCRect& rect);
		/**
		 * ���ƽڵ�
		 */
		virtual void onPaintNode(FCPaint *paint, const FCRect& rect);
		/**
		 * �ػ淽��
		 */
		virtual void onPaint(FCPaint *paint, const FCRect& rect, const FCRect& clipRect, bool isAlternate);
		/**
		 * �Ƴ��ڵ㷽��
		 */
		virtual void onRemovingNode();
		/**
		 * �Ƴ��ڵ�
		 */
		void removeNode(FCTreeNode *node);
		/**
		* ��������
		* @param  name  ��������
		* @param  value  ����ֵ
		*/
		virtual void setAttribute(const String& name, const String& value);
		/**
		 * �����ַ�����ֵ
		 */
		virtual void setString(const String& value);
	};
}
