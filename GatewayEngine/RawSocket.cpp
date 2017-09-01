#include "RawSocket.h"
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <pthread.h>

#include "EnumAndDefine.h"
#include "Worker.h"


RawSocket::RawSocket()
{
	m_pWorker = new Worker();
}


RawSocket::~RawSocket()
{
}





int RawSocket::WorkForServer()
{
	const int MAX_LINES = 4906;
	//创建监听socket
	int socket_fd;//描述在一个协议族中，PF_INET标识iPv4协议族
	if (-1 == (socket_fd = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)))
	{
		printf("create socket error: %s(errno: %d)\n", strerror(errno), errno);
		exit(0);
	}

	//初始化ip和iport,并将socket绑定到该ip和端口上
	struct sockaddr_in  serverAddr;
	memset(&serverAddr,0,sizeof(serverAddr));
	serverAddr.sin_family = AF_INET;//适用于iPv4网络协议的地址族
	serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);//IP地址设置成INADDR_ANY,让系统自动获取本机的IP地址
	serverAddr.sin_port = htons(m_iPort);//设置的端口为DEFAULT_PORT,有点问题  
	if (-1 == bind(socket_fd,(struct sockaddr*)&serverAddr,sizeof(serverAddr)))
	{
		printf("bind socket error: %s(errno: %d)\n", strerror(errno), errno);
		exit(0);
	}

	//开始监听服务端的端口
	if (-1 == listen(socket_fd,10))
	{
		printf("listen socket error: %s(errno: %d)\n", strerror(errno), errno);
		exit(0);
	}
	printf("======waiting for client's request======\n");

	//准备接收客户端发过来的请求
	int connect_fd;//连接套接字
	int n;
	char    buff[4096];
	char sendMsg[30] = "hello,you have connected!";
	while (1)
	{
		//进入阻塞状态，等待客户端发送请求
		if (-1 == (connect_fd = accept(socket_fd, (struct sockaddr*)NULL, NULL)))
		{
			printf("accept socket error: %s(errno: %d)", strerror(errno), errno);
			continue;
		}

		//接收客户端传过来的信息
		n = recv(connect_fd, buff, MAX_LINES, 0);

		//向客户端发送回应
		if (!fork())//子进程
		{
			if (-1 == send(connect_fd, sendMsg, sizeof(sendMsg), NULL))
			{
				perror("send error");
				close(connect_fd);
				exit(0);
			}
		}

		buff[n] = '\n';//结束符
		//printf("recv msg from client: %s\n", buff);

		//调用处理类处理数据
		m_pWorker->HandleRequest(buff);

		close(connect_fd);
	}

	close(socket_fd);
}