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
	//���ö˿ں�
	m_gContext->m_pRawSock->SetIport(m_gContext->m_iPort);

	//���÷����
	m_gContext->m_pRawSock->WorkForServer();

	//���Զ��߳�
	printf("ThreadFunction has been excuted!");

	//return 
}

void* Context::Start()
{
	pthread_t tid;
	pthread_create(&tid, NULL, ThreadFunction, NULL);

}

