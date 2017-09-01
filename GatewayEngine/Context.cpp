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
	//设置端口号
	m_pRawSock->SetIport(m_iPort);

	//调用服务端
	m_pRawSock->WorkForServer();

}

