#pragma once
class Worker;
class RawSocket
{
public:
	RawSocket();
	~RawSocket();
	///�߳�׼��
	/*********************************************************************
	* @brief : �ͻ���
	* @author : yaotongxing
	* @date : 2017/9/1 13:43
	* @version : ver 1.0
	* @inparam : 
	* @outparam : 
	**********************************************************************/
	int WorkForServer();


	


public:
	void SetIport(int val) { m_iPort = val; }
	int GetIport() { return m_iPort; }
private:
	///ip��ַ
	
	///�˿ں�
	int m_iPort;

	///��ȡ�������ָ��
	Worker* m_pWorker;
};

