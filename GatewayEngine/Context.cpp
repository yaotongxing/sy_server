#include "Context.h"


#include "RawSocket.h"
#include "EnumAndDefine.h"

Context::Context()
{
	m_iPort = 0;
	m_pRawSock = new RawSocket();
}


Context::~Context()
{
	if (m_pRawSock)
	{
		delete m_pRawSock;
	}
}

void* Context::Start()
{
	bool isSuccess = false;
	//���ö˿ں�
	m_pRawSock->SetIport(m_iPort);

	//���÷����
	m_pRawSock->WorkForServer();

}

