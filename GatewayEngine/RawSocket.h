#pragma once
class Worker;
class RawSocket
{
public:
	RawSocket();
	~RawSocket();
	///线程准备
	/*********************************************************************
	* @brief : 客户端
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
	///ip地址
	
	///端口号
	int m_iPort;

	///获取处理类的指针
	Worker* m_pWorker;
};

