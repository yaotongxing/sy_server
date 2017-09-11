#pragma once

class Config;
class RawSocket;
class Worker;

/********************************************************************
* @brief : 该类为网关工程的接口类，外部数据交互都是调用该类的函数
* @author : yaotongxing
* @date : 2017/9/1 10:47
* @version : ver 1.0
*********************************************************************/
class Context
{
public:
	Context();
	~Context();

public:
	/*********************************************************************
	* @brief : 开启线程
	* @author : yaotongxing
	* @date : 2017/9/5 14:12
	* @version : ver 1.0
	* @inparam :
	* @outparam :
	**********************************************************************/
	static void* ThreadFunction(void *);

	/*********************************************************************
	* @brief : 分配端口，准备监听
	* @author : yaotongxing
	* @date : 2017/9/1 10:49
	* @version : ver 1.0
	* @inparam : 
	* @outparam : 
	**********************************************************************/
	void* Start();


public:
	void SetIport(int val) { m_iPort = val; }
	int GetIport() { return m_iPort; }

	void SetConfig(Config* val) { m_pCon = val; }
	Config* GetConfig() { return m_pCon; }

	void SetWorkor(Worker* val) { m_pWorker = val; }
	Worker* GetWorker() { return m_pWorker; }

private:
	///将类变成单例模式，从而使得静态函数可以调用类成员变量
	static Context* m_gContext;
	///获取socket类的指针
	RawSocket* m_pRawSock;	
	///设置端口
	int m_iPort;
	///设置ip值
	///
	Config* m_pCon;
	///
	Worker* m_pWorker;
};