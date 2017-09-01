#pragma once
class RawSocket;

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

private:


private:
	///
	RawSocket* m_pRawSock;

	///
	int m_iPort;

};