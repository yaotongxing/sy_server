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
#include "Context.h"

#define  DEFAULT_PORT 8000

using namespace std;
RawSocket::RawSocket()
{
}


RawSocket::RawSocket(int val):m_iPort(val)
{
}

RawSocket::~RawSocket()
{
}





int RawSocket::WorkForServer()
{
	const int MAX_LINES = 4906;

	//��������socket
	int socket_fd;//������һ��Э�����У�PF_INET��ʶiPv4Э����
	if (-1 == (socket_fd = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)))
	{
		printf("create socket error: %s(errno: %d)\n", strerror(errno), errno);
		exit(0);
	}

	//��ʼ��ip��iport,����socket�󶨵���ip�Ͷ˿���
	struct sockaddr_in  serverAddr;
	memset(&serverAddr,0,sizeof(serverAddr));
	serverAddr.sin_family = AF_INET;//������iPv4����Э��ĵ�ַ��
	serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);//IP��ַ���ó�INADDR_ANY,��ϵͳ�Զ���ȡ������IP��ַ
	serverAddr.sin_port = htons(DEFAULT_PORT);//���õĶ˿�ΪDEFAULT_PORT,�е�����  
	if (-1 == bind(socket_fd,(struct sockaddr*)&serverAddr,sizeof(serverAddr)))
	{
		printf("bind socket error: %s(errno: %d)\n", strerror(errno), errno);
		exit(0);
	}

	//��ʼ��������˵Ķ˿�
	if (-1 == listen(socket_fd,10))
	{
		printf("listen socket error: %s(errno: %d)\n", strerror(errno), errno);
		exit(0);
	}
	printf("======waiting for client's request======\n");

	//׼�����տͻ��˷�����������
	int connect_fd;//�����׽���
	int n;
	char    buff[4096];
	char sendMsg[30] = "hello,you have connected!\n";


	while (1)
	{
		//��������״̬���ȴ��ͻ��˷�������
		if (-1 == (connect_fd = accept(socket_fd, (struct sockaddr*)NULL, NULL)))
		{
			//��connect_fd�������
			m_vecConnectFd.push_back(connect_fd);
			printf("accept socket error: %s(errno: %d)", strerror(errno), errno);
			continue;
		}


		//���տͻ��˴���������Ϣ
		n = recv(connect_fd, buff, MAX_LINES, 0);


		//��ͻ��˷��ͻ�Ӧ
		if (!fork())//�ӽ���
		{
			if (-1 == send(connect_fd, sendMsg, sizeof(sendMsg), NULL))
			{
				perror("send error");
				close(connect_fd);
				exit(0);
			}
		}

		
		//���ô����ദ������
		m_pCt->GetWorker()->HandleRequest(buff);

		close(connect_fd);
	}

	close(socket_fd);

	printf("WorkForServer has been excuted!");
}

int RawSocket::WorkForClient()
{

}
