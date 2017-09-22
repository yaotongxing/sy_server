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
	//���ö˿ں�
	m_gContext->m_pRawSock->SetIport(m_gContext->m_iPort);
	m_gContext->m_pRawSock->SetContext(m_gContext);

	/////���÷����
	//���ͻ���
	m_gContext->m_pRawSock->WorkServerForSingleCt();

	//��ͻ���
	//m_gContext->m_pRawSock->WorkServerForMultiCt();

	//���Զ��߳�
	//printf("ThreadFunction has been excuted!\n");

}

void* Context::Start()
{
	//��������
	m_pWorker->SetCon(m_pCon);

	//�����߳�
	pthread_create(&m_pThread, NULL, ThreadFunction, NULL);

	//�����߳�
	//void *ptr;
	//ThreadFunction(ptr);

}

bool Context::Stop()
{
	bool isSuccess = true;
	//���߳���ֹ,����Ҫ���׽��ֹر�
	m_pRawSock->Stop();
	if (!pthread_kill(m_pThread, 0))
	{
		isSuccess = true;
	}

	return isSuccess;
}

