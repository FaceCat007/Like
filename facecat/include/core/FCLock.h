/*
 * FaceCatͼ��ͨѶ���(�ǿ�Դ)
 * ����Ȩ���:2015SR229355+2020SR0266727
 * �Ϻ����è��Ϣ�������޹�˾
 */

#ifdef __FCLOCK__H__
#else                                                                            
#define __FCLOCK__H__ _declspec(dllexport) 
#endif
#pragma once

namespace FaceCat
{
	/*
	* ͬ����
	*/
	class __FCLOCK__H__ FCLock
	{
	public:
		/*
		* ���캯��
		*/
		FCLock();
		/*
		* ��������
		*/
		~FCLock();
		/*
		* ��
		*/
		void lock();
		/*
		* ����
		*/
		void unLock();
	private:
		CRITICAL_SECTION m_cs;
	};
}

