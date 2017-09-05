#pragma once
#include <vector>
class Worker;
class RawSocket
{
public:
	RawSocket();
	RawSocket(int val);
	~RawSocket();
	///线程准备
	/*********************************************************************
	* @brief : 服务端
	* @author : yaotongxing
	* @date : 2017/9/1 13:43
	* @version : ver 1.0
	* @inparam : 
	* @outparam : 
	**********************************************************************/
	int WorkForServer();

	/*********************************************************************
	* @brief : 客户端
	* @author : yaotongxing
	* @date : 2017/9/4 14:36
	* @version : ver 1.0
	* @inparam : 
	* @outparam : 
	**********************************************************************/
	int WorkForClient();

	


public:
	void SetIp(int val) { m_iIp = val; }
	int GetIp() { return m_iIp; }
	void SetIport(int val) { m_iPort = val; }
	int GetIport() { return m_iPort; }
private:
	///ip地址
	int m_iIp;
	///端口号
	int m_iPort;
	///获取处理类的指针
	Worker* m_pWorker;
	///存储connect_fd，满足多客户端之间的信息发送
	std::vector<int> m_vecConnectFd;
};

