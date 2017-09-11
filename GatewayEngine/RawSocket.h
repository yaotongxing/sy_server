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
	void SetContext(Context* val) { m_pCt = val; }
	Context* GetContext() { return m_pCt; }
	void SetIp(int val) { m_iIp = val; }
	int GetIp() { return m_iIp; }
	void SetIport(int val) { m_iPort = val; }
	int GetIport() { return m_iPort; }
private:
	///获取接口参数
	Context* m_pCt;

	///ip地址
	int m_iIp;
	///端口号
	int m_iPort;
	///获取处理类的指针
	//Worker* m_pWorker;
	///存储connect_fd，满足多客户端之间的信息发送
	std::vector<int> m_vecConnectFd;
};

