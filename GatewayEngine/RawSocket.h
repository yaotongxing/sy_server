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
	* @brief : 开启多线程
	* @author : yaotongxing
	* @date : 2017/9/11 23:59
	* @version : ver 1.0
	* @inparam : 
	* @outparam : 
	**********************************************************************/
	static void* AcceptHandlerThread(void *val);
	/*********************************************************************
	* @brief : 处理客户端信息
	* @author : yaotongxing
	* @date : 2017/9/12 14:35
	* @version : ver 1.0
	* @inparam : 
	* @outparam : 
	**********************************************************************/
	static void* HandleRecvMsg(void* aptSocketfd);

	///线程准备
	/*********************************************************************
	* @brief : 单客户端服务端
	* @author : yaotongxing
	* @date : 2017/9/1 13:43
	* @version : ver 1.0
	* @inparam : 
	* @outparam : 
	**********************************************************************/
	int WorkServerForSingleCt();

	/*********************************************************************
	* @brief : 多客户端服务端
	* @author : yaotongxing
	* @date : 2017/9/11 23:37
	* @version : ver 1.0
	* @inparam : 
	* @outparam : 
	**********************************************************************/
	int WorkServerForMultiCt();

	/*********************************************************************
	* @brief : 检查线程是否杀死
	* @author : yaotongxing
	* @date : 2017/9/12 15:23
	* @version : ver 1.0
	* @inparam : 
	* @outparam : 
	**********************************************************************/
	int CheckThraedIsKilled(pthread_t& val);

	/*********************************************************************
	* @brief : 客户端
	* @author : yaotongxing
	* @date : 2017/9/4 14:36
	* @version : ver 1.0
	* @inparam : 
	* @outparam : 
	**********************************************************************/
	int WorkForClient();
	/*********************************************************************
	* @brief : 由于主线程即将关闭，停止套接字连接
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
	///获取RawSocket类的指针
	static RawSocket* m_gRawSocket;
	///获取接口参数
	Context* m_pCt;
	///ip地址
	int m_iIp;
	///端口号
	int m_iPort;
	///获取处理类的指针
	//Worker* m_pWorker;
	///连接客户端的信息
	_MySocketInfo m_sClntInfo[10];
	///客户端数量
	int m_iClntCount;
	///接收客户端线程列表
	pthread_t m_sRecvClntThread[10];
	///开启的线程数
	int m_iThreadCount;
	///监听listen的套接字
	int m_iListenSocket;
	///accept套接字
	int m_iAcceptSocket;
};

