#include "Context.h"
//#include <pthread.h>
#include<signal.h>
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

	/////调用服务端
	//单客户端
	m_gContext->m_pRawSock->WorkServerForSingleCt();

	//多客户单
	//m_gContext->m_pRawSock->WorkServerForMultiCt();

	//测试多线程
	//printf("ThreadFunction has been excuted!\n");

}

void* Context::Start()
{
	//参数设置
	m_pWorker->SetCon(m_pCon);

	//开启线程
	pthread_create(&m_pThread, NULL, ThreadFunction, NULL);

	//不开线程
	//void *ptr;
	//ThreadFunction(ptr);

}

bool Context::Stop()
{
	bool isSuccess = true;
	//将线程终止,并且要将套接字关闭
	m_pRawSock->Stop();
	if (!pthread_kill(m_pThread, 0))
	{
		isSuccess = true;
	}

	return isSuccess;
}

