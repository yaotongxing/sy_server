#include <cstdio>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <assert.h>
#include <errno.h>

#include <arpa/inet.h>
#include <sys/socket.h>

#include "SingleInstance.h"

using namespace std;

#define  DEFAULT_PORT 8000
#define  MAX_LINES 4096

#define LENGTH_OF_LISTEN_QUEUE 20
#define BUFFER_SIZE 206


typedef struct DataS 
{
	double a;
	double b;
	char name[260];
}DATA,*PDATA;



int main(int argc,char* argv[])
{
	

	struct sockaddr_in server_addr;
	int server_socket;
	int opt = 1;

	bzero(&server_addr, sizeof(server_addr)); // ���ֽ��ַ���ǰn���ֽ�Ϊ0������'\0'
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = htons(INADDR_ANY); // תС��,INADDR_ANY����ָ����ַΪ0.0.0.0�ĵ�ַ
	server_addr.sin_port = htons(DEFAULT_PORT);

	// ����һ��Socket
	server_socket = socket(PF_INET, SOCK_STREAM, 0);

	if (server_socket < 0)
	{
		printf("Create Socket Failed!\n");
		exit(1);
	}
	
	// bind a socket
	setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
	if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)))
	{
		printf("Server Bind Port: %d Failed!\n", DEFAULT_PORT);
		exit(1);
	}

	// ����Socket
	if (listen(server_socket, LENGTH_OF_LISTEN_QUEUE))
	{
		printf("Server Listen Failed!\n");
		exit(1);
	}
	printf("===========wait for client===========\n");
	DATA ds;

	char temp[206];
	memset(temp, 0, sizeof(temp));
	bool iFlag=true;
	while (iFlag)
	{

		struct sockaddr_in client_addr;
		int client_socket;
		socklen_t length;
		char Buffer[BUFFER_SIZE];

		// ���ӿͻ���Socket
		length = sizeof(client_addr);
		client_socket = accept(server_socket, (struct sockaddr*)&client_addr, &length);
		if (client_socket < 0)
		{
			printf("Server Accept Failed!\n");
			break;
		}

		// �ӿͻ��˽�������
		while (1)
		{
			bzero(Buffer, BUFFER_SIZE);
			length = recv(client_socket, Buffer, BUFFER_SIZE, 0);

			//��������
			memcpy(&ds, Buffer, BUFFER_SIZE);

			//�������̹߳���
			SingleInstance* pSI = SingleInstance::GetInstance();

			//ֹͣ������
			if (!strcmp(ds.name,"q") || !strcmp(ds.name,"Q"))
			{
				iFlag = false;
				
				printf("iFlag is setted.\n");
				//��ֹ�����̵߳Ĺ���
				if (pSI->Stop())
				{
					printf("work is stop.\n");
					break;
				}					
				else
					printf("work process is not kill!");
			}

			//��������			
			pSI->SetNum1(ds.a);
			pSI->SetNum2(ds.b);
			pSI->SetName(ds.name);
						
			//��ʾ�ͻ��˴�����������
			if (pSI)
			{				
				printf("process has been start!\n");
				printf("ds.a is:%f\n", ds.a);
				printf("ds.b is:%f\n", ds.b);
				printf("ds.name is:%s\n", ds.name);
			}
			
			if (length < 0)
			{
				printf("Server Recieve Data Failed!\n");
				break;
			}

			if ('q' == Buffer[0])
			{
				printf("Quit!\n");
				break;
			}

			printf("%s\n", Buffer);
			break;

		}

		close(client_socket);
	}

	if (!iFlag)
	{
		printf("iFlag is false!\n");
	}

	close(server_socket);


    return 0;
}
