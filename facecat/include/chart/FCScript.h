/*
 * FaceCatͼ��ͨѶ���(�ǿ�Դ)
 * ����Ȩ���:2015SR229355+2020SR0266727
 * �Ϻ����è��Ϣ�������޹�˾
 */

#ifdef __FCSCRIPT_H__
#else                                                                            
#define __FCSCRIPT_H__ _declspec(dllexport) 
#endif
#pragma once
#define FUNCTIONID_CHUNK 40
#define FUNCTIONID_FUNCVAR 10
#define FUNCTIONID_FUNCTION 9
#define FUNCTIONID_VAR 82

#include "..\\..\\stdafx.h"
#include "..\\core\\FCTran.h"
#include "Enums.h"
#include "FCDataTable.h"
#include "ChartDiv.h"
#include "BaseShape.h"

namespace FaceCat{
	class FCScript;
	class CMathElement;

	/*
	* ��������
	*/
	struct __FCSCRIPT_H__ LPDATA
	{
	public:
		/*
		* ��������
		*/
		LPDATA()
		{
		};
		/*
		* ���һ��ֵ
		*/
		double lastvalue;
		/*
		* ��һ��ֵ
		*/
		double first_value;
		/*
		* ģʽ
		*/
		int mode;
		/*
		* ��
		*/
		double sum;
	};

	/*
	* ����
	*/
	class __FCSCRIPT_H__ CVariable{
	public:
	    /**
         * ����
         */
		CVariable();
		/*
		* ���캯��
		*/
		virtual ~CVariable();
		/**
	     * ��״ͼ
	     */
		BarShape *m_barShape;
		/**
	     * K��
	     */
		CandleShape *m_candleShape;
		/**
	     * ���ʽ
	     */
		String m_expression;
		/**
	     * �ֶ�
	     */
		int m_field;
		/**
	     * �ֶε�����
	     */
		int m_fieldIndex;
		/**
	     * ��ʾ�ֶ�
	     */
		String m_fieldText;
		/**
	     * �����ı��
	     */
		int m_functionID;
		/**
	     * ��������
	     */
		String m_funcName;
		/**
	     * ָ��
	     */
		FCScript *m_script;
		/**
	     * ����
	     */
		int m_line;
		/**
	     * ����ͼ
	     */
		PolylineShape *m_polylineShape;
		/**
	     * ��ֵ
	     */
		String m_name;
		/**
	     * ����
	     */
		CVariable **m_parameters;
		/*
		* ��������
		*/
		int m_parametersLength;
		/**
	     * �ָ��ı��ʽ
	     */
		CMathElement **m_splitExpression;
		/*
		* ���ʽ����
		*/
		int m_splitExpressionLength;
		/**
	     * ��ʱ�ֶ�
	     */
		int *m_tempFields;
		/*
		* ��ʱ�ֶγ���
		*/ 
		int m_tempFieldsLength;
		/**
	     * ����ʱ�ֶε�����
	     */
		int *m_tempFieldsIndex;
		/*
		* ����ʱ�ֶεĳ���
		*/
		int m_tempFieldsIndexLength;
		/**
	     * ����
	     */
		TextShape *m_textShape;
		/**
	     * ����
	     */
		int m_type;
		/**
	     * ������ֵ
	     */
		double m_value;
		/**
	     * �����յ��ֶ�
	     */
		void createTempFields(int count);
	};

	/*
	* ������Ԫ
	*/
	class __FCSCRIPT_H__ CMathElement{
	public:
	    /*
         * ���캯��
         */
		CMathElement();
	    /*
         * ���캯��
         */
		CMathElement(int type, double value);
	    /*
         * ��������
         */
		virtual ~CMathElement();
		/**
	     * ����
	     */
		int m_type;
		/**
	     * ������ֵ
	     */
		double m_value;
		/**
	     * ����
	     */
		CVariable *m_var;
	};

	/*
	* ������Ԫ��չ
	*/
	class __FCSCRIPT_H__ CMathElementEx : public CMathElement{
	public:
		/*
		* �¸���Ԫ
		*/
		CMathElementEx *m_next;
		/*
		* ���캯��
		*/
		CMathElementEx(int type, double value):CMathElement(type, value){
			m_next = 0;
		}
		/*
		* ��������
		*/
		virtual ~CMathElementEx(){
			if(m_next){
				delete m_next;
				m_next = 0;
			}
		}
	};

	/*
	* ����
	*/
	class __FCSCRIPT_H__ CFunction{
	public:
		/*
		* ���캯��
		*/
		CFunction();
		/*
		* ���캯��
		*/
		CFunction(int id, String name);
		/*
		* ��������
		*/
		virtual ~CFunction();
		/*
		* ID
		*/
		int m_ID;
		/*
		* ����
		*/
		String m_name;
		/*
		* ����
		*/ 
		int m_type;
	public:
		/*
		* �����
		*/
		virtual double onCalculate(CVariable *var);
	};

    /*
     * ��ʱ����
     */
	class __FCSCRIPT_H__ CVar{
	public:
		/*
		* �Ƿ�̬����
		*/
		bool m_isStatic;
	    /**
	     * �б�
	     */
        ArrayList<String> *m_list;
        /**
	     * ��ϣ��
	     */
        HashMap<String, String> *m_map;
        /**
	     * ��ֵ
	     */
        double m_num;
        /**
	     * �ַ���
	     */
        String m_str;
        /**
	     * ����
	     */
        int m_type;
        /**
	     * �ϼ�����
	     */
        CVar *m_parent;
	public:
		/*
		* ���캯��
		*/
        CVar(){
			m_isStatic = false;
			m_list = 0;
			m_map = 0;
			m_parent = 0;
        }
		/*
		* ��������
		*/
        virtual ~CVar(){
			if (m_list){
                delete m_list;
				m_list = 0;
            }
            if (m_map){
                delete m_map;
				m_map = 0;
            }
            m_parent = 0;
        }
	public:
	    /**
         * ��ȡ����
         * @param script   ָ��
         * @param name        ����
         * @returns ��ֵ
        */
        virtual String getText(FCScript *script, CVariable *name);
        /**
         * ��ȡֵ
         * @param script   ָ��
         * @param name        ����
         * @returns ��ֵ
        */
		virtual double getValue(FCScript *script, CVariable *name);
	    /**
         * ��������
         * @param script   ָ��
         * @param name        ����
         * @param value       ֵ
        */
		virtual double onCreate(FCScript *script, CVariable *name, CVariable *value);
	    /**
         * ����ֵ
         * @param script   ָ��
         * @param name        ����
         * @param value       ֵ
        */
		virtual void setValue(FCScript *script, CVariable *name, CVariable *value);
    };

    /*
     * ��ʱ��������
     */
	class __FCSCRIPT_H__ CVarFactory{
	public:
	    /**
         * ��������
         * @returns ����
        */
		virtual CVar* createVar(){
			return new CVar;
		}
	};

	/*
	* �ű�
	*/
	class __FCSCRIPT_H__ FCScript{
	public:
		String KEYWORD_LIST;
        String KEYWORD_MAP;
        String KEYWORD_TRUE;
        String KEYWORD_FALSE;
        String KEYWORD_FUNCTION;
        String KEYWORD_CONST;
        String KEYWORD_EQ;
        String KEYWORD_MH;
        String KEYWORD_MHE;
        String KEYWORD_FUNCVAR;
        String KEYWORD_REF;
        String KEYWORD_VAR2;
        String KEYWORD_CHUNK;
        String KEYWORD_AND;
        String KEYWORD_OR;
        String KEYWORD_ELSE;
        String KEYWORD_ELSEIF;
        String KEYWORD_RETURN;
        String KEYWORD_VAR;
        String KEYWORD_SET;
        String KEYWORD_STATIC;
        String KEYWORD_BREAK;
        String KEYWORD_CONTINUE;
        String KEYWORD_FOR;
        String KEYWORD_WHILE;
        String KEYWORD_DOTIMES;
        char CHAR_MH;
        char CHAR_EQ;
        char CHAR_ADD;
        char CHAR_SUB;
        char CHAR_NEQ;
        String KEYWORD_GTE;
        String KEYWORD_LTE;
        String KEYWORD_NE1;
        String KEYWORD_NE2;
        String KEYWORD_ADD;
        String KEYWORD_MULTIPLY;
        String KEYWORD_DIVIDE;
        String KEYWORD_E;
        String KEYWORD_GT;
        String KEYWORD_LT;
        String KEYWORD_MOD;
	public:
		CRITICAL_SECTION _csLock;
		/**
	     * �����б�
	     */
		HashMap<String,double> m_defineParams;
		/**
	     * �����б�
	     */
		HashMap<String,CFunction*> m_functions;
		/**
	     * �����Ĺ�ϣ��
	     */
		HashMap<Integer, CFunction*> m_functionsMap;
		/**
	     * ��ǰ���ڼ��������
	     */
		int m_index;
		/**
	     * ��伯��
	     */
		ArrayList<CVariable*> m_lines;
		/**
	     * ϵͳ��ɫ
	     */
		ArrayList<Long> m_systemColors;
		/**
	     * TAGֵ
	     */
		Object m_tag;
		/**
	     * ����������
	     */
		HashMap<String, CVariable*> m_tempFunctions;
		/**
	     * ������
	     */
        HashMap<String, CVariable*> m_tempVariables;
        /**
	     * ��������
	     */
		ArrayList<CVariable*> m_variables;
		/**
	     * ��ʱ��������
	     */
		CVarFactory *m_varFactory;
		/**
	     * ������ʶ�ַ���
	     */
		String VARIABLE;
		/**
	     * ��ʶ�ַ���2
	     */
		String VARIABLE2;
		/**
	     * ��ʶ�ַ���3
	     */
		String VARIABLE3;
	public:
	    /**
	     * �����������
	     */
		AttachVScale m_attachVScale;
		/**
	     * ������ʶ
	     */
		int m_break;
		/**
	     * ����Դ
	     */
		FCDataTable *m_dataSource;
		/**
	     * ͼ��
	     */
		ChartDiv *m_div;
		/**
	     * ����
	     */
		String m_name;
		/**
	     * ���
	     */
		double m_result;
		/*
		* �ű�
		*/
		String m_script;
		/**
	     * ���Ͻ��
	     */
		CVar m_resultVar;
		/*
		* ��Tab��ʾ�����
		*/
		bool m_isTabBrick;
		/*
		* �Ƿ�ִֹͣ��
		*/
		bool m_stop;
	public:
		Long m_downColor;
		Long m_midColor;
		Long m_upColor;
	public:
	    /**
	     * ��������а����ķ����ͱ���
	     */
		void FCScript::analysisVariables(String *sentence, int line, String funcName, String fieldText, bool isFunction);
	    /**
         * ���ؽű���
         * @param line  �ű���
        */
		void analysisScriptLine(String line);
	    /**
         * �Ա��ʽ������ֵ����ֵ֮ǰ���Ƚ����﷨У��
         * @param expr      Ҫ��ֵ�ı��ʽ
         * @returns ��ֵ���
        */
		double calculate(CMathElement **expr, int exprLength);
	    /**
         * ���÷���
         * @param var   ����
         * @returns ���
        */
		double callFunction(CVariable *var);
	    /**
         * ɾ����ʱ����
         * @param var  ����
        */
		void deleteTempVars();
	    /**
         * ɾ����ʱ����
         * @param var  ����
        */
		void deleteTempVars(CVariable *var, int index);
	    /**
         * �����ַ�����ȡ��ɫ
         * @param strColor  �ַ���
         * @returns ��ɫ
        */
		Long getColor(const String& strColor);
	    /**
         * ������Դ�л�ȡ����ָ����Ҫ��MATH_STRUCT�ṹ
         * @param   fieldIndex   �ֶ�
         * @param   mafieldIndex  ����MAֵ�ֶ�
         * @param   index    ��������
         * @param   n        ����
         * @returns MATH_STRUCT�ṹ
        */
		LPDATA getDatas(int fieldIndex, int mafieldIndex, int index, int n, int mode);
	    /**
         * ��ȡ�ߵĿ��
         * @param strLine  �ߵ�����
         * @returns �߿�
        */
		float getLineWidth(const String& strLine);
	    /**
         * ��ȡ�м�ű�
         * @param script   �ű�
         * @param lines    ��
        */
		int getMiddleScript(const String& script, ArrayList<String> *lines);
	    /**
         * ��ȡ��������
         * @param   op    �ַ���
         * @returns ��������
        */
		int getOperator(const String& op);
		/*
		* �Ƿ�����
		*/
		bool isNumeric(const String& str);
	    /**
         * �滻�����ͱ���
         * @param  parameter  ����
         * @returns �滻�����
        */
		String replace(const String& parameter);
	    /**
         * �ѱ��ʽ��ֳ��ַ������飬���ں���ļ�����ֵ
         * @param expression  ���ʽ
         * @returns  �����ҷ��ش��±�0��ʼ���ַ�������
        */
		CMathElement** splitExpression(const String& expression, int *sLength);
	    /**
         * �ѱ��ʽ��ֳ��ַ������飬���ں���ļ�����ֵ
         * @param expression  ���ʽ
         * @returns  �����ҷ��ش��±�0��ʼ���ַ�������
        */
		String* splitExpression2(const String& expression, int *sLength);
	public:
		/*
		* ���캯��
		*/
		FCScript();
		/*
		* ��������
		*/
		virtual ~FCScript();
		/**
	     * ��Ҫ����
	     */
		HashMap<String ,CVariable*> m_mainVariables;
		/**
	     * ��ʱ����
	     */
		HashMap<Integer, CVar*> m_tempVars;
		/**
	     * ��ȡ�����������
	     */
		virtual AttachVScale getAttachVScale();
		/**
	     * ���������������
	     */
		virtual void setAttachVScale(AttachVScale value);
		/**
	     * ��ȡ����Դ
	     */
		virtual FCDataTable* getDataSource();
		/**
	     * ��������Դ
	     */
		virtual void setDataSource(FCDataTable *value);
		/**
	     * ��ȡͼ��
	     */
		virtual ChartDiv* getDiv();
		/**
	     * ����ͼ��
	     */
		virtual void setDiv(ChartDiv *value);
		/**
	     * ��ȡ��ǰ���ڼ��������
	     */
		virtual int getIndex();
		/**
	     * ��ȡ����
	     */
		virtual String getName();
		/**
	     * ��������
	     */
		virtual void setName(const String& value);
		/**
	     * ��ȡ�ű�
	     */
		virtual double getResult();
		/*
		* ��ȡ�ű�
		*/
		virtual String getScript();
		/**
	     * ���ýű�
	     */
		virtual void setScript(const String& value);
		/**
	     * ��ȡϵͳ��ɫ
	     */
		virtual ArrayList<Long> getSystemColors();
		/**
	     * ����ϵͳ��ɫ
	     */
		virtual void setSystemColors(ArrayList<Long> value);
		/*
		* �Ƿ���Tab��ʾ�����
		*/
		bool isTabBrick();
		/*
		* �����Ƿ���Tab��ʾ�����
		*/ 
		void setTabBrick(bool value);
		/**
	     * ��ȡTAGֵ
	     */
		virtual Object getTag();
		/**
	     * ����TAGֵ
	     */
		virtual void setTag(Object value);
		/**
	     * ��ȡ��ʱ��������
	     */
		virtual CVarFactory* getVarFactory();
		/**
	     * ������ʱ��������
	     */
		virtual void setVarFactory(CVarFactory *value);
	public:
	    /**
         * ��ӷ���
         * @param function  ����
        */
		void addFunction(CFunction *function);
	    /**
         * ���÷���
         * @param fieldName  ��������
         * @returns ����ֵ
        */
		double callFunction(String funcName);
		/*
		* �������
		*/
		void clear();
		/**
	     * ��ȡ���еķ���
	     */
		ArrayList<CFunction*> getFunctions();
		/**
	     * ��ȡ���е�ͼ��
	     */
		ArrayList<BaseShape*> getShapes();
	    /**
         * ��ȡ�ı�
         * @param   var   ����
         * @returns �ı�
        */
		String getText(CVariable *var);
	    /**
         * ��ȡ��ֵ
         * @param   var   ����
         * @returns  ������
        */
		double getValue(CVariable *var);
	    /**
         * ��ȡ����
         * @param  name  ����
         * @returns ����
        */
		CVariable* getVariable(const String& name);
		/*
		* ��
		*/
		void lock();
	    /**
         * ����ָ��
         * @param  index   ����
         * @returns  �Ƿ����ɹ�
        */
		void onCalculate(int index);
	    /**
         * �Ƴ�����
         * @param function  ����
        */
		void removeFunction(CFunction *function);
	    /**
         * ��������Դ�ֶ�
         * @param key   ��
         * @param value  ֵ
        */
		void setSourceField(const String& key, int value);
	    /**
         * ��������Դֵ
         * @param key   ��
         * @param value  ֵ
        */
		void setSourceValue(int index, const String& key, double value);
	    /**
         * ���ñ�����ֵ
         * @param variable  ����
         * @param parameter  ֵ
         * @returns  ���
        */
		void setVariable(CVariable *variable, CVariable *parameter);
		 /*
         * ����
         */
		void unLock();
	public:
	    /**
         * �������ֵ
         * @param var   ����
         * @returns  ����ֵ
        */
		double ABS2(CVariable *var);
	    /**
         * ��������Ӧ����ֵ
         * @param var   ����
         * @returns  ����Ӧ����ֵ
        */
		double AMA(CVariable *var);
	    /**
         * ���㷴����ֵ
         * @param var   ����
         * @returns  ������ֵ
        */
		double ACOS(CVariable *var);
	    /**
         * ���㷴����ֵ
         * @param var   ����
         * @returns  ������ֵ
        */
		double ASIN(CVariable *var);
	    /**
         * ���㷴����ֵ
         * @param var   ����
         * @returns  ������ֵ
        */
		double ATAN(CVariable *var);
	    /**
         * ����ƽ������ƫ��
         * @param var   ����
         * @returns  ƽ������ƫ��
        */
		double AVEDEV(CVariable *var);
	    /**
         * ����������Ŀ
         * @param var   ����
         * @returns  ������Ŀ
        */
		int BARSCOUNT(CVariable *var);
	    /**
         * ������һ��������������ǰ��������
         * @param var   ����
         * @returns  ������
        */
		int BARSLAST(CVariable *var);
		/**
         * ��һ��������������ǰ��������
         * @param var   ����
         * @returns  ������
        */
		int BARSSINCE(CVariable *var);
		/**
         * N�����ڵ�һ��������������ǰ��������
         * @param var   ����
         * @returns  ������
        */
		int BARSSINCEN(CVariable *var);
	    /**
         * �жϱ��ʽ
         * @param var   ����
         * @returns  ���
        */
		int BETWEEN(CVariable *var);
	    /**
         * ����ѭ��
         * @param var   ����
         * @returns  ���
        */
		int BREAK(CVariable *var);
	    /**
         * �������Ͻӽ�������
         * @param var   ����
         * @returns  ���Ͻӽ�������
        */
		double CEILING(CVariable *var);
	    /**
         * ִ�д����
         * @param var   ����
         * @returns  ����ֵ
        */
		double CHUNK(CVariable *var);
		/**
         * ȡA����ֵ(������ֵ)תΪ�ַ���,С��λ��N
         * @param var   ����
         * @returns  ����ֵ
        */
		int CON2STR(CVariable *var);
	    /**
         * ����ѭ��
         * @param var   ����
         * @returns  ���
        */
		int CONTINUE(CVariable *var);
	    /**
         * ��������ֵ
         * @param var   ����
         * @returns  ����ֵ
        */
		double COS(CVariable *var);
		/**
         * Э����
         * @param var   ����
         * @returns  ���
        */
		double COVAR(CVariable *var);
	    /**
         * ͳ������������������
         * @param var   ����
         * @returns  ������
        */
		int COUNT(CVariable *var);
	    /**
         * �ж��Ƿ�Խ
         * @param var   ����
         * @returns  ��Խ:1 ����Խ:0
        */
		int CROSS(CVariable *var);
	    /**
         * ��ȡ��ǰ��������
         * @param var   ����
         * @returns  ��������
        */
		int CURRBARSCOUNT(CVariable *var);
	    /**
         * ȡ�ø����ڴ�1900�����ĵ�������.
         * @param var   ����
         * @returns  ������
        */
		int DATE(CVariable *var);
	    /**
         * ��������
         * @param var   ����
         * @returns  ����
        */
		int DAY(CVariable *var);
	    /**
         * ɾ������
         * @param var   ����
         * @returns  ���
        */
		int DELETE2(CVariable *var);
		/*
		* ��������ƫ��ƽ����
         * @param var   ����
         * @returns  ���
		*/
		double DEVSQ(CVariable *var);
	    /**
         * ���㶯̬�ƶ�ƽ��
         * @param var   ����
         * @returns  ��̬�ƶ�ƽ��
        */
		double DMA(CVariable *var);
	    /**
         * ѭ��ִ��һ������
         * @param var   ����
         * @returns  ״̬
        */
		int DOTIMES(CVariable *var);
	    /**
         * ִ��DOWHILEѭ��
         * @param var   ����
         * @returns  ״̬
        */
		int DOWHILE(CVariable *var);
	    /**
         * �����Ƿ�����������
         * @param var   ����
         * @returns  �Ƿ�����������
        */
		int DOWNNDAY(CVariable *var);
	    /**
         * ���Ƶ�ͼ
         * @param var   ����
         * @returns  0
        */
		double DRAWICON(CVariable *var);
	    /**
         * ����K��
         * @param var   ����
         * @returns  0
        */
		double DRAWKLINE(CVariable *var);
	    /**
         * ������Ч��
         * @param var   ����
         * @returns  ��Ч��
        */
		double DRAWNULL(CVariable *var);
	    /**
         * ��������
         * @param var   ����
         * @returns  0
        */
		double DRAWTEXT(CVariable *var);
	    /**
         * �ж��Ƿ����
         * @param var   �Ƿ����
         * @returns  0
        */
		int EXIST(CVariable *var);
		/**
         * �ж��Ƿ����
         * @param var   �Ƿ����
         * @returns  0
        */
		int EXISTR(CVariable *var);
	    /**
         * ����ָ���ƶ�ƽ��
         * @param var   �Ƿ����
         * @returns  ָ���ƶ�ƽ��
        */
		double EMA(CVariable *var);
	    /**
         * �ж��Ƿ�һֱ����
         * @param var   �Ƿ����
         * @returns  �Ƿ�һֱ����
        */
		int EVERY(CVariable *var);
	    /**
         * ����ָ��ƽ���ƶ�ƽ��
         * @param var   �Ƿ����
         * @returns  ָ��ƽ���ƶ�ƽ��
        */
		double EXPMEMA(CVariable *var);
	    /**
         * ����e��X����
         * @param var ����
         * @returns e��X����
        */
		double EXP(CVariable *var);
		/**
         * �ַ�������
         * @param var ����
         * @returns ״̬
        */
		int FINDSTR(CVariable *var);
	    /**
         * �������½ӽ�������
         * @param var  ����
         * @returns ���½ӽ�������
        */
		double FLOOR(CVariable *var);
	    /**
         * ִ��FORѭ��
         * @param var ����
         * @returns ״̬
        */
		int FOR(CVariable *var);
		/**
         * ���Իع�Ԥ��ֵ
         * @param var ����
         * @returns ״̬
        */
		int FORCAST(CVariable *var);
	    /**
         * ִ�з���
         * @param var  ����
         * @returns ����ֵ
        */
		double FUNCTION(CVariable *var);
	    /**
         * �������
         * @param var  ����
         * @returns ��ֵ
        */
		double FUNCVAR(CVariable *var);
	    /**
         * ����ָ���ֶ�һ�������ڵ����ֵ
         * @param var  ����
         * @returns ��ֵ
        */
		double GET(CVariable *var);
	    /**
         * ����ָ���ֶ�һ�������ڵ����ֵ
         * @param var  ����
         * @returns ���ֵ
        */
		double HHV(CVariable *var);
	    /**
         * ����ָ���ֶ�һ�������ڵ����ֵ����������
         * @param var  ����
         * @returns ����
        */
		double HHVBARS(CVariable *var);
		/**
         * ���ֵ����
         * @param var  ����
         * @returns ����
        */
		int HOD(CVariable *var);
	    /**
         * ����Сʱ
         * @param var  ����
         * @returns Сʱ
        */
		int HOUR(CVariable *var);
	    /**
         * ѡ����
         * @param var  ����
         * @returns ���
        */
		double IF(CVariable *var);
	    /**
         * ��ѡ����
         * @param var  ����
         * @returns ��ѡ����
        */
		double IFN(CVariable *var);
	    /**
         * ������X����ֵ��С������ӽ�������
         * @param var  ����
         * @returns ��ӽ�������
        */
		double INTPART(CVariable *var);
	    /**
         * �ж��Ƿ��������
         * @param var  ����
         * @returns �Ƿ��������
        */
		int LAST(CVariable *var);
		/**
         * ����Ȼ����
         * @param var  ����
         * @returns ��Ȼ����
        */
		double LN(CVariable *var);
	    /**
         * ����ָ���ֶ�һ�������ڵ���Сֵ
         * @param var  ����
         * @returns ��Сֵ
        */
		double LLV(CVariable *var);
	    /**
         * ����ָ���ֶ�һ�������ڵ���Сֵ������������
         * @param var  ����
         * @returns ����
        */
		double LLVBARS(CVariable *var);
		/**
         * ���ֵ����
         * @param var  ����
         * @returns ����
        */
		int LOD(CVariable *var);
	    /**
         * ���㳣�ö���
         * @param var  ����
         * @returns ���ö���
        */
		double LOG(CVariable *var);
		/**
         * ������ά��һ�����ں󽻲�
         * @param var  ����
         * @returns ��ֵ
        */
		int LONGCROSS(CVariable *var);
	    /**
         * ������ƶ�ƽ��
         * @param var  ����
         * @returns ���ƶ�ƽ��
        */
		double MA(CVariable *var);
		/**
         * ��ǰϵͳ������
         * @param var  ����
         * @returns ֵ
        */
		int MACHINEDATE(CVariable *var);
		/**
         * ��ǰϵͳ��ʱ��
         * @param var  ����
         * @returns ֵ
        */
		int MACHINETIME(CVariable *var);
		/**
         * ��ǰϵͳ����
         * @param var  ����
         * @returns ֵ
        */
		int MACHINEWEEK(CVariable *var);
	    /**
         * �������ֵ
         * @param var  ����
         * @returns ���ֵ
        */
		double MAX2(CVariable *var);
		/**
         * �������ֵ
         * @param var  ����
         * @returns ���ֵ
        */
		double MAX6(CVariable *var);
	    /**
         * ����ָ���ƶ�ƽ��
         * @param var  ����
         * @returns ָ���ƶ�ƽ��
        */
		double MEMA(CVariable *var);
	    /**
         * ������Сֵ
         * @param var  ����
         * @returns ��С�ٻ�ֵ
        */
		double MIN2(CVariable *var);
		/**
         * ������Сֵ
         * @param var  ����
         * @returns ��С�ٻ�ֵ
        */
		double MIN6(CVariable *var);
	    /**
         * ���ط���
         * @param var  ����
         * @returns ����
        */
		int MINUTE(CVariable *var);
	    /**
         * ����ģ
         * @param var  ����
         * @returns ģ
        */
		double MOD(CVariable *var);
	    /**
         * �����·�
         * @param var  ����
         * @returns �·�
        */
		int MONTH(CVariable *var);
		/**
         * �����۳�
         * @param var  ����
         * @returns �۳�
        */
		double MULAR(CVariable *var);
	    /**
         * �����Ƿ��������X>Y
         * @param var  ����
         * @returns �Ƿ����
        */
		int NDAY(CVariable *var);
	    /**
         * ��ֵΪ0ʱ����1,���򷵻�0
         * @param var  ����
         * @returns 1��0
        */
		int NOT(CVariable *var);
	    /**
         * �������
         * @param var  ����
         * @returns 0
        */
		double POLYLINE(CVariable *var);
	    /**
         * �������
         * @param var  ����
         * @returns ����
        */
		double POW(CVariable *var);
		/**
		* A��B��C��Χ֮��,B<A<C
         * @param var  ����
         * @returns 0
		*/
		int RANGE(CVariable *var);
	    /**
         * ��ȡ�����
         * @param var  ����
         * @returns �����
        */
		int RAND(CVariable *var);
	    /**
         * ��ȡǰ��������ֵ
         * @param var  ����
         * @returns ǰ��������ֵ
        */
		double REF(CVariable *var);
	    /**
         * ����ֵ
         * @param var  ����
         * @returns ֵ
        */
		double RETURN(CVariable *var);
	    /**
         * ȡ��
         * @param var  ����
         * @returns ��ֵ
        */
		double REVERSE(CVariable *var);
	    /**
         * ������������
         * @param var  ����
         * @returns ��������ֵ
        */
		double ROUND(CVariable *var);
	    /**
         * ����������ָ��
         * @param var  ����
         * @returns ������ָ��
        */
		double SAR(CVariable *var);
		/**
         * ����ת���
         * @param var  ����
         * @returns ��ֵ
        */
		double SARTURN(CVariable *var);
		/**
         * ��0ʱ����������ʲôʱ��
         * @param var  ����
         * @returns ״̬
        */
		int SECTOTIME(CVariable *var);
	    /**
         * ���ñ�����ֵ
         * @param var  ����
         * @returns ״̬
        */
		double SET(CVariable *var);
	    /**
         * �������0�򷵻�1,���С��0�򷵻أ�1�����򷵻�0
         * @param var  ����
         * @returns 1,0,-1
        */
		int SGN(CVariable *var);
	    /**
         * ��������ֵ
         * @param var  ����
         * @returns ����ֵ
        */
		double SIN(CVariable *var);
		/**
         * ���Իع�б��
         * @param var  ����
         * @returns ���
        */
		double SLOPE(CVariable *var);
	    /**
         * �����ƶ�ƽ��
         * @param var  ����
         * @returns �ƶ�ƽ��
        */
		double SMA(CVariable *var);
	    /**
         * ����ƽ����
         * @param var  ����
         * @returns ƽ����
        */
		double SQRT(CVariable *var);
	    /**
         * ����ƽ��
         * @param var  ����
         * @returns ƽ��
        */
		double SQUARE(CVariable *var);
	    /**
         * ���徲̬����
         * @param var  ����
         * @returns ��ֵ
        */
		double STATIC(CVariable *var);
	    /**
         * �����׼��
         * @param var  ����
         * @returns ��׼��
        */
		double STDDEV(CVariable *var);
		/**
         * ������Ʊ�׼��
         * @param var  ����
         * @returns ��׼��
        */
		double STD(CVariable *var);
		/**
         * �����״ͼ
         * @param var  ����
         * @returns 0
        */
		double STICK(CVariable *var);
	    /**
         * �����״ͼ
         * @param var  ����
         * @returns 0
        */
		double STICKLINE(CVariable *var);
		/*
		* �ַ���ת��Ϊ����
		* @param var  ����
         * @returns ��ֵ
		*/
		double STR2CON(CVariable *var);
		/*
		* �������ַ���A,B(�����л�)��ӳ�һ���ַ���C.
		* @param var  ����
         * @returns ��ֵ
		*/
		int STRCAT(CVariable *var);
		/*
		* �ַ�������һ�ո�
		* @param var  ����
         * @returns ��ֵ
		*/
		int STRSPACE(CVariable *var);
		/*
		* �Ƚ������ַ���A,B�Ƿ����.
		* @param var  ����
         * @returns ��ֵ
		*/
		int STRCMP(CVariable *var);
	    /**
         * �������
         * @param var  ����
         * @returns ��
        */
		double SUM(CVariable *var);
	    /**
         * ��������ֵ
         * @param var  ����
         * @returns ����ֵ
        */
		double TAN(CVariable *var);
	    /**
         * ȡ�ø����ڵ�ʱ��,������������������
         * @param var  ����
         * @returns ʱ��
        */
		int TIME(CVariable *var);
	    /**
         * ȡ�ø����ڵ�ʱ��,������������������
         * @param var  ����
         * @returns ʱ����
        */
		int TIME2(CVariable *var);
		/**
         * ��ָ��ʱ�̾�0ʱ�ж೤ʱ��
         * @param var  ����
         * @returns ��ֵ
		*/
		int TIMETOSEC(CVariable *var);
	    /**
         * ����ݹ��ƶ�ƽ��
         * @param var  ����
         * @returns �ݹ��ƶ�ƽ��
        */
		double TMA(CVariable *var);
		/*
		* ������ʵ����
		* @param var  ����
         * @returns ��ֵ
		*/
		double TR(CVariable *var);
	    /**
         * �����Ƿ�����������
         * @param var  ����
         * @returns �Ƿ�����������
        */
		int UPNDAY(CVariable *var);
	    /**
         * ����������ʱ,ȡ��ǰֵ,����ȡ�ϸ�ֵ
         * @param var  ����
         * @returns ��ֵ
        */
		double VALUEWHEN(CVariable *var);
		/**
         * ������������
         * @param var  ����
         * @returns ��ֵ
        */
		double VARP(CVariable *var);
		/**
         * ������������
         * @param var  ����
         * @returns ��ֵ
        */
		double VAR(CVariable *var);
	    /**
         * �������
         * @param var  ����
         * @returns ��ֵ
        */
		double VAR2(CVariable *var);
		/**
         * �����״ͼ
         * @param var  ����
         * @returns 0
        */
		double VOLSTICK(CVariable *var);
		/**
		* ȡ�ø��������ڵڼ�����
         * @param var  ����
         * @returns ��ֵ
		*/
		int WEEKOFYEAR(CVariable *var);
		/**
		* ȡ�ø����ڵ�������
         * @param var  ����
         * @returns ��ֵ
		*/
		int WEEKDAY(CVariable *var);
	    /**
         * ִ��WHILEѭ��
         * @param var  ����
         * @returns ״̬
        */
		int WHILE(CVariable *var);
	    /**
         * �����Ȩ�ƶ�ƽ����
         * @param var  ����
         * @returns ��Ȩ�ƶ�ƽ��
        */
		double WMA(CVariable *var);
	    /**
         * �������
         * @param var  ����
         * @returns ���
        */
		int YEAR(CVariable *var);
	    /**
         * ����֮�ַ�ת
         * @param var  ����
         * @returns ֮�ַ�ת
        */
		double ZIG(CVariable *var);
	public:
	    /**
         * �����ַ���
         * @param var  ����
         * @returns ���
        */
		int STR_CONTACT(CVariable *var);
	    /**
         * �Ƚ��ַ����Ƿ����
         * @param var  ����
         * @returns λ��
        */
		int STR_EQUALS(CVariable *var);
	    /**
         * �����ַ����г������ֵ�λ��
         * @param var  ����
         * @returns λ��
        */
		int STR_FIND(CVariable *var);
	    /**
         * �����ַ��������������ֵ�λ��
         * @param var  ����
         * @returns λ��
        */
		int STR_FINDLAST(CVariable *var);
	    /**
         * ��ȡ�ַ����ĳ���
         * @param var  ����
         * @returns ����
        */
		int STR_LENGTH(CVariable *var);
	    /**
         * ��ȡ�ַ���
         * @param var  ����
         * @returns ���
        */
		int STR_SUBSTR(CVariable *var);
	    /**
         * �滻�ַ���
         * @param var  ����
         * @returns ���
        */
		int STR_REPLACE(CVariable *var);
	    /**
         * �и��ַ���
         * @param var  ����
         * @returns ���
        */
		int STR_SPLIT(CVariable *var);
	    /**
         * �ַ���ת��ΪСд
         * @param var  ����
         * @returns ���
        */
		int STR_TOLOWER(CVariable *var);
	    /**
         * �ַ���ת��Ϊ��д
         * @param var  ����
         * @returns ���
        */
		int STR_TOUPPER(CVariable *var);
	    /**
         * ������ݵ�����
         * @param var  ����
         * @returns ���
        */
		int LIST_ADD(CVariable *var);
	    /**
         * �������
         * @param var  ����
         * @returns ���
        */
		int LIST_CLEAR(CVariable *var);
	    /**
         * �Ӽ����л�ȡ����
         * @param var  ����
         * @returns ���
        */
		int LIST_GET(CVariable *var);
	    /**
         * �򼯺��в�������
         * @param var  ����
         * @returns ���
        */
		int LIST_INSERT(CVariable *var);
	    /**
         * �Ӽ������Ƴ�����
         * @param var  ����
         * @returns ���
        */
		int LIST_REMOVE(CVariable *var);
	    /**
         * ��ȡ���ϵĴ�С
         * @param var  ����
         * @returns ���
        */
		int LIST_SIZE(CVariable *var);
	    /**
         * �����ϣ��
         * @param var  ����
         * @returns ���
        */
		int MAP_CLEAR(CVariable *var);
	    /**
         * ��ϣ���Ƿ������
         * @param var  ����
         * @returns ���
        */
		int MAP_CONTAINSKEY(CVariable *var);
	    /**
         * ��ȡ��ϣ���ֵ
         * @param var  ����
         * @returns ���
        */
		int MAP_GET(CVariable *var);
	    /**
         * ��ȡ��ϣ��ļ�
         * @param var  ����
         * @returns ���
        */
		int MAP_GETKEYS(CVariable *var);
	    /**
         * �ӹ�ϣ�����Ƴ�
         * @param var  ����
         * @returns ���
        */
		int MAP_REMOVE(CVariable *var);
	    /**
         * ���ϣ�����������
         * @param var  ����
         * @returns ���
        */
		int MAP_SET(CVariable *var);
	    /**
         * ��ȡ��ϣ��ĳߴ�
         * @param var  ����
         * @returns ���
        */
		int MAP_SIZE(CVariable *var);
	public:
		/*
		* Avedev
		*/
		static double avedev(double value, double *listForAvedev, int listForAvedev_length, double avg);
		/*
		* ƽ��ֵ
		*/
        static double avgValue(double *list, int length);
		/*
		* Э����
		*/
		double covar(double *list1, int length1, double avg1, double *list2, int length2, double avg2);
		/*
		* ����ƫ��ƽ����
		*/
        static double devsq(double *list, int length, double avg);
		/*
		* ָ���ƶ�ƽ��ƽ��
		*/
        static double exponentialMovingAverage(int n, double value, double lastEMA);
		/*
		* 쳲�����
		*/
        static int fibonacciValue(int index);
		/*
		* ���Իع�
		*/
        static void linearRegressionEquation(double *list, int length, float *k, float *b);
		/*
		* ���ֵ
		*/
        static double maxValue(double *list, int length);
		/*
		* ��Сֵ
		*/
        static double minValue(double *list, int length);
		/*
		* ƽ��ֵ
		*/
        static double movingAverage(int index, int n, double value, struct LPDATA last_MA);
		/*
		* ���Ʊ�׼��
		*/
        static double standardDeviation(double *list, int length, double avg, double standardDeviation);
		/*
		* ��׼��
		*/
        static double standardDeviationDev(double *list, int length, double avg, double standardDeviation);
		/*
		* ������������
		*/
		double standardVar(double *list, int length, double avg);
		/*
		* ������������
		*/
		double standardVarDev(double *list, int length, double avg);
		/*
		* ���ƶ�ƽ��
		*/
        static double simpleMovingAverage(double close, double lastSma, int n, int m);
		/*
		* ���
		*/
        static double sumilationValue(int index, int n, double value, struct LPDATA last_SUM);
		/*
		* ���
		*/
        static double sumValue(double *list, int length);
        /*
		* ��Ȩ�ƶ�ƽ��
		*/
		static double weightMovingAverage(int n, int weight, double value, double lastWMA);
	};
}