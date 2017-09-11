#pragma once
#include <vector>
class Worker;
class Context;

class RawSocket
{
public:
	RawSocket();
	RawSocket(int val);
	~RawSocket();
	///�߳�׼��
	/*********************************************************************
	* @brief : �����
	* @author : yaotongxing
	* @date : 2017/9/1 13:43
	* @version : ver 1.0
	* @inparam : 
	* @outparam : 
	**********************************************************************/
	int WorkForServer();

	/*********************************************************************
	* @brief : �ͻ���
	* @author : yaotongxing
	* @date : 2017/9/4 14:36
	* @version : ver 1.0
	* @inparam : 
	* @outparam : 
	**********************************************************************/
	int WorkForClient();

	


public:
	void SetContext(Context* val) { m_pCt = val; }
	Context* GetContext() { return m_pCt; }
	void SetIp(int val) { m_iIp = val; }
	int GetIp() { return m_iIp; }
	void SetIport(int val) { m_iPort = val; }
	int GetIport() { return m_iPort; }
private:
	///��ȡ�ӿڲ���
	Context* m_pCt;

	///ip��ַ
	int m_iIp;
	///�˿ں�
	int m_iPort;
	///��ȡ�������ָ��
	//Worker* m_pWorker;
	///�洢connect_fd�������ͻ���֮�����Ϣ����
	std::vector<int> m_vecConnectFd;
};

