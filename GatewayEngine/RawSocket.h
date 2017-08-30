#pragma once
class RawSocket
{
public:
	RawSocket();
	~RawSocket();

	////作客户端
	/*********************************************************************
	* @brief : 创建连接
	* @author : yaotongxing
	* @date : 2017/8/30 20:12
	* @version : ver 1.0
	* @inparam : 
	* @outparam : 
	**********************************************************************/
	int Create();

	/*********************************************************************
	* @brief : 启动连接
	* @author : yaotongxing
	* @date : 2017/8/30 20:14
	* @version : ver 1.0
	* @inparam : 
	* @outparam : 
	**********************************************************************/
	int Connent();

	/*********************************************************************
	* @brief : 断开连接
	* @author : yaotongxing
	* @date : 2017/8/30 20:15
	* @version : ver 1.0
	* @inparam : 
	* @outparam : 
	**********************************************************************/
	int Close();


	////作服务端
	/*********************************************************************
	* @brief : 分配套接字地址
	* @author : yaotongxing
	* @date : 2017/8/30 20:15
	* @version : ver 1.0
	* @inparam : 
	* @outparam : 
	**********************************************************************/
	int Bind(const char* ip,int iPort);

	/*********************************************************************
	* @brief : 开启监听
	* @author : yaotongxing
	* @date : 2017/8/30 21:18
	* @version : ver 1.0
	* @inparam : 
	* @outparam : 
	**********************************************************************/
	int Listen(const int iNum);
	/*********************************************************************
	* @brief : 接收信息,获得被监听客户端的ip和port
	* @author : yaotongxing
	* @date : 2017/8/30 23:10
	* @version : ver 1.0
	* @inparam : 
	* @outparam : 
	**********************************************************************/
	int Accept(char* pIp,int& iPort);
	/*********************************************************************
	* @brief : 获取客户端/服务端的信息
	* @author : yaotongxing
	* @date : 2017/8/30 23:52
	* @version : ver 1.0
	* @inparam : 数据指针的地址；数据长度的地址；接收选项
	* @outparam : 
	**********************************************************************/
	int Receive(void *pData,int *pLen,unsigned int iFlag);
	/*********************************************************************
	* @brief : 发送消息到客户端、服务端
	* @author : yaotongxing
	* @date : 2017/8/31 0:11
	* @version : ver 1.0
	* @inparam : 
	* @outparam : 
	**********************************************************************/
	int Send(const void* pData,int iLen, unsigned int uiFlag);


public:
	void SetSocket(int val) { m_iSocket = val; }
	int GetSocket() { return m_iSocket; }
private:
	///socket句柄
	int m_iSocket;
};

