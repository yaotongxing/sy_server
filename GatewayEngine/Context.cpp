#include "Context.h"
#include <pthread.h>
#include <stdio.h>

#include "RawSocket.h"
#include "EnumAndDefine.h"

Context::Context()
{
	m_gContext = this;
	m_iPort = 0;
	m_pRawSock = new RawSocket(m_iPort);
}


Context::~Context()
{
	if (m_pRawSock)
	{
		delete m_pRawSock;
	}
}

Context* Context::m_gContext = NULL;


void* Context::ThreadFunction(void *)
{
	//设置端口号
	m_gContext->m_pRawSock->SetIport(m_gContext->m_iPort);

	//调用服务端
	m_gContext->m_pRawSock->WorkForServer();

	//测试多线程
	printf("ThreadFunction has been excuted!");

	//return 
}

void* Context::Start()
{
	pthread_t tid;
	pthread_create(&tid, NULL, ThreadFunction, NULL);

}

