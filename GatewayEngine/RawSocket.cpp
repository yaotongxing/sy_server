#include "RawSocket.h"
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <pthread.h>
#include<signal.h>

#include "EnumAndDefine.h"
#include "Worker.h"
#include "Context.h"

#define  DEFAULT_PORT 8001
#define  CLIENT_NUM 10
#define  BUFFER_SIZE 30
#define  MAX_LINES 4096

using namespace std;
RawSocket::RawSocket()
{
	m_gRawSocket = this;
	m_gRawSocket = 0;
	
	memset(m_sClntInfo, 0, sizeof(m_sClntInfo) * 10);
	m_iClntCount = 0;

	memset(m_sRecvClntThread, 0, sizeof(m_sRecvClntThread) * 10);
	m_iThreadCount = 0;

	m_iListenSocket = 0;
	m_iAcceptSocket = 0;
}


RawSocket::RawSocket(int val):m_iPort(val)
{
	m_gRawSocket = this;
	m_gRawSocket = 0;
	
	memset(m_sClntInfo,0,sizeof(m_sClntInfo)*10);
	m_iClntCount = 0;

	memset(m_sRecvClntThread, 0, sizeof(m_sRecvClntThread) * 10);
	m_iThreadCount = 0;

	m_iListenSocket = 0;
	m_iAcceptSocket = 0;
}

RawSocket::~RawSocket()
{
}


RawSocket* RawSocket::m_gRawSocket = NULL;

void* RawSocket::AcceptHandlerThread(void *lisSocketfd)
{
	//���ռ���,�����Ҫ��ֲѭ����������Ϊ�ͻ��˵���ֹ��ֹͣ
	while (1)
	{
		int _lisSocketfd = *((int*)lisSocketfd);
		struct sockaddr_in client_addr;
		int client_addr_size = sizeof(client_addr);
		int aptSocketfd = accept(_lisSocketfd,(struct sockaddr*)&client_addr, (socklen_t *)(&client_addr_size));
		if (-1 == aptSocketfd)
		{
			printf("����ʧ��\n");
		}
		else
		{
			printf("���ӳɹ� ip: %s:%d\r\n", inet_ntoa(client_addr.sin_addr), client_addr.sin_port);
		}
		printf("�����׽���Ϊ��%d\n", aptSocketfd);

		///�洢�ͻ��˵���Ϣ����Ϊÿ���ͻ��˵�socket��ip��iport��һ��������洢
		_MySocketInfo singleClntInfo;		
		singleClntInfo.socketfd = aptSocketfd;
		singleClntInfo.ipaddr = inet_ntoa(client_addr.sin_addr);
		singleClntInfo.port = client_addr.sin_port;
		m_gRawSocket->m_sClntInfo[m_gRawSocket->m_iClntCount] = singleClntInfo;//������
		m_gRawSocket->m_iClntCount++;
		printf("%d users have been connected!",m_gRawSocket->m_iClntCount);

		///�������̴߳��������ӿͻ�������,�洢������Ϣ
		pthread_t threadReceive = 0;
		pthread_create(&threadReceive,NULL, HandleRecvMsg,&aptSocketfd);
		m_gRawSocket->m_sRecvClntThread[m_gRawSocket->m_iThreadCount] = threadReceive;
		m_gRawSocket->m_iThreadCount++;

		//�ý�����Ϣ0.5s
		sleep(0.5);
	}

	char *s = "exit process safely!";
	pthread_exit(s);
}



void* RawSocket::HandleRecvMsg(void* aptSocketfd)
{
	char sendMsg[30] = "have recv msg:";
	char buffer[BUFFER_SIZE];
	int buffer_length = 0;
	int _aptSocketfd = 0;
	while (1)
	{
		bzero(&buffer, sizeof(buffer));
		_aptSocketfd = *((int*)aptSocketfd);

		sleep(0.1);
		buffer_length = recv(_aptSocketfd, buffer, MAX_LINES, 0);

		if (0 == buffer_length)
		{
			printf("%d interupt!", _aptSocketfd);//�����Ͽ�����
			m_gRawSocket->m_iClntCount--;
			break;
		}
		else if(-1 == buffer_length)
		{
			printf("%d client closed!", _aptSocketfd);//�ͻ��˹ر�
			break;
		}

		buffer[buffer_length] = '\0';//������

		//��ͻ��˷��ͻ�Ӧ
		if (!fork())//�ӽ���
		{
			if (-1 == send(_aptSocketfd, sendMsg, sizeof(sendMsg), NULL))
			{
				perror("send error");
				close(_aptSocketfd);
				exit(0);
			}
		}

		//���ô����ദ������
		m_gRawSocket->m_pCt->GetWorker()->HandleRequest(buffer);
		sleep(0.2);
	}
	printf("recv msg have been finished!");
	return NULL;
}


int RawSocket::WorkServerForSingleCt()
{
	//��������socket
	//socket_fd������һ��Э�����У�PF_INET��ʶiPv4Э����
	int socket_fd = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	m_iListenSocket = socket_fd;
	if (-1 == m_iListenSocket)
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
	if (-1 == bind(m_iListenSocket,(struct sockaddr*)&serverAddr,sizeof(serverAddr)))
	{
		printf("bind socket error: %s(errno: %d)\n", strerror(errno), errno);
		exit(0);
	}

	//��ʼ��������˵Ķ˿�
	if (-1 == listen(m_iListenSocket,10))
	{
		printf("listen socket error: %s(errno: %d)\n", strerror(errno), errno);
		exit(0);
	}
	printf("======waiting for client's request======\n");

	//׼�����տͻ��˷�����������
	//int connect_fd;//�����׽���
	int n;
	char    buff[4096];
	char sendMsg[30] = "hello,you have connected!\n";


	while (1)
	{
		//��������״̬���ȴ��ͻ��˷�������

		if (-1 == (m_iAcceptSocket = accept(m_iListenSocket, (struct sockaddr*)NULL, NULL)))
		{
			printf("accept socket error: %s(errno: %d)", strerror(errno), errno);
			continue;
		}

		//���տͻ��˴���������Ϣ
		n = recv(m_iAcceptSocket, buff, MAX_LINES, 0);
		buff[n] = '\0';//������
		printf("recv client messsage:\n",buff);
		//��ͻ��˷��ͻ�Ӧ
		if (!fork())//�ӽ���
		{
			if (-1 == send(m_iAcceptSocket, sendMsg, sizeof(sendMsg), NULL))
			{
				perror("send error");
				close(m_iAcceptSocket);
				exit(0);
			}
		}

		
		//���ô����ദ������
		m_pCt->GetWorker()->HandleRequest(buff);

		close(m_iAcceptSocket);
	}

	close(m_iListenSocket);

	printf("WorkForServer has been excuted!\n");
}

int RawSocket::WorkServerForMultiCt()
{
	///bind
	int lis_socket_fd = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (-1 == lis_socket_fd)
	{
		printf("create socket error: %s(errno: %d)\n", strerror(errno), errno);
		exit(0);
	}

	struct sockaddr_in  serverAddr;
	memset(&serverAddr, 0, sizeof(serverAddr));
	serverAddr.sin_family = AF_INET;//������iPv4����Э��ĵ�ַ��
	serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);//IP��ַ���ó�INADDR_ANY,��ϵͳ�Զ���ȡ������IP��ַ
	serverAddr.sin_port = htons(DEFAULT_PORT);//�̶��˿�Ϊ8000
	if (-1 == bind(lis_socket_fd, (struct sockaddr*)&serverAddr, sizeof(serverAddr)))
	{
		printf("listen socket error: %s(errno: %d)\n", strerror(errno), errno);
		exit(0);
	}

	///listen
	if (-1 == listen(lis_socket_fd, CLIENT_NUM))
	{
		printf("listen socket error: %s(errno: %d)\n", strerror(errno), errno);
		exit(0);
	}

	///accept
	pthread_t thrAccept;
	pthread_create(&thrAccept, NULL, AcceptHandlerThread, &lis_socket_fd);

	///send msg
	while (1)
	{
		//�жϴ����߳�
		for (int i=0;i<m_iThreadCount;i++)
		{
			if (1==CheckThraedIsKilled(m_sRecvClntThread[i]))
			{
				printf("%d is died! ",m_sRecvClntThread[i]);
				m_iThreadCount--;
			}
		}

		// ����¼���û�����ѡ���������Ӧ����  
		char userStr[30] = { '0' };
		scanf("%s", userStr);
		if (strcmp(userStr, "q") == 0) {
			printf("�û�ѡ���˳���\n");
			break;
		}

		//������̷߳�����Ϣ
		if (m_iClntCount<=0)
		{
			printf("no client!");
		}
		else
		{
			for (int i=0;i<m_iClntCount;i++)
			{
				int sendMsg_len = send(m_sClntInfo[i].socketfd,userStr,30,NULL);//userStr�������Ҳ��ܳ���30�ֽ�
				if (sendMsg_len>0)
				{
					printf("��%s:%d���ͳɹ���\n", m_sClntInfo[i].ipaddr, m_sClntInfo[i].port);
				}
				else
				{
					printf("��%s:%d����ʧ�ܣ�\n",m_sClntInfo[i].ipaddr,m_sClntInfo[i].port);
				}
			}
		}

		sleep(0.5);
	}

	///waiting for  child_thread exit
	printf("waiting for  child_thread exit��\n");
	//char *message;
	pthread_join(thrAccept,NULL);
	//printf("%s\n",message);

	return 0;
}


int RawSocket::CheckThraedIsKilled(pthread_t& val)
{
	int res = 1;
	int res_kill = pthread_kill(val,0);
	if (0==res_kill)
	{
		res = 0;
	}
	return res;
}


int RawSocket::WorkForClient()
{

}

bool RawSocket::Stop()
{
	bool isSuccess = false;

	char sendMsg[40] = "I am sorry,i will be killed!bye..." ;
	send(m_iAcceptSocket, sendMsg, sizeof(sendMsg), NULL);
	if (m_iAcceptSocket || m_iListenSocket)
	{
		if (m_iAcceptSocket)
			close(m_iAcceptSocket);
		if(m_iListenSocket)		
			close(m_iListenSocket);		

		isSuccess = true;
	}

	return isSuccess;
}

