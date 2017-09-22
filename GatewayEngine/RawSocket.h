#pragma once
#include <stdint.h>
#include <pthread.h>

class Worker;
class Context;

typedef struct MySocketInfo {
	int socketfd;
	char *ipaddr;
	uint16_t port;
}_MySocketInfo;


class RawSocket
{
public:
	RawSocket();
	RawSocket(int val);
	~RawSocket();
	/*********************************************************************
	* @brief : �������߳�
	* @author : yaotongxing
	* @date : 2017/9/11 23:59
	* @version : ver 1.0
	* @inparam : 
	* @outparam : 
	**********************************************************************/
	static void* AcceptHandlerThread(void *val);
	/*********************************************************************
	* @brief : ����ͻ�����Ϣ
	* @author : yaotongxing
	* @date : 2017/9/12 14:35
	* @version : ver 1.0
	* @inparam : 
	* @outparam : 
	**********************************************************************/
	static void* HandleRecvMsg(void* aptSocketfd);

	///�߳�׼��
	/*********************************************************************
	* @brief : ���ͻ��˷����
	* @author : yaotongxing
	* @date : 2017/9/1 13:43
	* @version : ver 1.0
	* @inparam : 
	* @outparam : 
	**********************************************************************/
	int WorkServerForSingleCt();

	/*********************************************************************
	* @brief : ��ͻ��˷����
	* @author : yaotongxing
	* @date : 2017/9/11 23:37
	* @version : ver 1.0
	* @inparam : 
	* @outparam : 
	**********************************************************************/
	int WorkServerForMultiCt();

	/*********************************************************************
	* @brief : ����߳��Ƿ�ɱ��
	* @author : yaotongxing
	* @date : 2017/9/12 15:23
	* @version : ver 1.0
	* @inparam : 
	* @outparam : 
	**********************************************************************/
	int CheckThraedIsKilled(pthread_t& val);

	/*********************************************************************
	* @brief : �ͻ���
	* @author : yaotongxing
	* @date : 2017/9/4 14:36
	* @version : ver 1.0
	* @inparam : 
	* @outparam : 
	**********************************************************************/
	int WorkForClient();
	/*********************************************************************
	* @brief : �������̼߳����رգ�ֹͣ�׽�������
	* @author : yaotongxing
	* @date : 2017/9/22 14:42
	* @version : ver 1.0
	* @inparam : 
	* @outparam : 
	**********************************************************************/
	bool Stop();
	


public:
	void SetContext(Context* val) { m_pCt = val; }
	Context* GetContext() { return m_pCt; }
	void SetIp(int val) { m_iIp = val; }
	int GetIp() { return m_iIp; }
	void SetIport(int val) { m_iPort = val; }
	int GetIport() { return m_iPort; }
private:
	///��ȡRawSocket���ָ��
	static RawSocket* m_gRawSocket;
	///��ȡ�ӿڲ���
	Context* m_pCt;
	///ip��ַ
	int m_iIp;
	///�˿ں�
	int m_iPort;
	///��ȡ�������ָ��
	//Worker* m_pWorker;
	///���ӿͻ��˵���Ϣ
	_MySocketInfo m_sClntInfo[10];
	///�ͻ�������
	int m_iClntCount;
	///���տͻ����߳��б�
	pthread_t m_sRecvClntThread[10];
	///�������߳���
	int m_iThreadCount;
	///����listen���׽���
	int m_iListenSocket;
	///accept�׽���
	int m_iAcceptSocket;
};

