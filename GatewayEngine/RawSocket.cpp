#include "RawSocket.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>


#include "EnumAndDefine.h"


RawSocket::RawSocket()
{
	m_iSocket = 0;
}


RawSocket::~RawSocket()
{
}

int RawSocket::Create()
{
	//创建套接字
	if (m_iSocket != 0)//已经开启
		Close();

	m_iSocket = socket(PF_INET,SOCK_STREAM, IPPROTO_TCP);
}

int RawSocket::Connent()
{

}

int RawSocket::Close()
{

}

int RawSocket::Bind(const char* ip, int iPort)
{
	if (iPort < 0)
		return ERROR_INVALID_PARAM;

	//分配IP地址和端口号
	struct sockaddr_in serv_addr;

	int serv_sock;
	//serv_sock = socket(PF_INET,SOCK_STREAM, IPPROTO_TCP);
	serv_sock = m_iSocket;
	if (-1 == serv_sock)
	{
		return ERROR_INVALID_PARAM;
	}

	memset(&serv_addr,0,sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	if (!ip && strlen(ip)==0)
	{
		serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	}
	else
	{
		serv_addr.sin_addr.s_addr = inet_addr(ip);
	}
	serv_addr.sin_port=htons(iPort);

	if (bind(serv_sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1)
	{
		return ERROR_BIND_FAIL;
	}

	return RETURN_SUCCEED;
}

int RawSocket::Listen(const int iNum)
{
	if (-1 == listen(m_iSocket,iNum))
	{
		return ERROR_LISTEN_FAIL;
	}

	return RETURN_SUCCEED;
}

int RawSocket::Accept(char* pIp, int& iPort)
{
	if (!pIp)
	{
		return ERROR_INVALID_PARAM;
	}

	//获取客户端的ip和port
	struct sockaddr_in clnt_addr;
	socklen_t clnt_addr_sz;//与windows不同
	
	int iSockfd = accept(m_iSocket, (struct sockaddr*)&clnt_addr,&clnt_addr_sz);

	if (-1 == iSockfd)
	{
		return ERROR_ACCEPT_FAIL;
	}

	strcpy(pIp, inet_ntoa(clnt_addr.sin_addr));
	iPort = clnt_addr.sin_port;

	return RETURN_SUCCEED;
}

int RawSocket::Receive(void *pData, int *pLen,unsigned int iFlag)
{
	if ( !pData || !pLen)
	{
		return ERROR_INVALID_PARAM;
	}

	int iRet = recv(m_iSocket, (char*)pData, *pLen, iFlag);

	*pLen = iRet;
	return iRet;//返回字节数
}

int RawSocket::Send(const void* pData, int iLen, unsigned int uiFlag)
{
	if (!pData)
	{
		return ERROR_INVALID_PARAM;
	}

	int iRet = send(m_iSocket, (char*)pData, iLen,uiFlag);

	if (-1 == iRet)
	{
		return ERROR_SEND_FAIL;
	}

	return iRet;//返回发送出去数据的长度
}