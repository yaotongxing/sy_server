#include "Context.h"
#include <pthread.h>
#include <stdio.h>

#include "../DataStruct/Config.h"
#include "Worker.h"

#include "RawSocket.h"
#include "EnumAndDefine.h"

Context::Context()
{
	m_gContext = this;
	m_iPort = 0;
	m_pRawSock = new RawSocket(m_iPort);
	m_pWorker = new Worker();
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
	m_gContext->m_pRawSock->SetContext(m_gContext);

	//调用服务端
	m_gContext->m_pRawSock->WorkForServer();

	//测试多线程
	printf("ThreadFunction has been excuted!\n");

	//return 
}

void* Context::Start()
{
	//参数设置
	m_pWorker->SetCon(m_pCon);

	//开启线程
	pthread_t tid;
	pthread_create(&tid, NULL, ThreadFunction, NULL);

	//test
	//void *ptr;
	//ThreadFunction(ptr);

}

