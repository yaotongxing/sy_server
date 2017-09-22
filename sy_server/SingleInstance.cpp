#include "SingleInstance.h"
#include <iostream>
#include <unistd.h>
#include <iostream>
#include <stdio.h>

#include "../Builder/Director.h"
#include "../GatewayEngine/Context.h"
#include "../DataStruct/Config.h"

using namespace std;

SingleInstance* SingleInstance::m_pS = NULL;

SingleInstance::SingleInstance()
{
	m_dNum1 = 0;
	m_dNum2 = 0;
	memset(m_cName, 0, sizeof(m_cName));

	Start();
}


SingleInstance* SingleInstance::GetInstance()
{
	//增加多线程的判断
	if (NULL == m_pS)
	{
		m_pS = new SingleInstance();
	}

	return m_pS;
}

SingleInstance::~SingleInstance()
{
}

bool SingleInstance::Start()
{
	bool isSuccess = true;

	//全局数据结构开辟空间
	Config* pCon = Config::GetInstance();

	//处理客户端发送过来的信息
	Context* ct = new Context();

	m_pCt = ct;
	ct->SetIport(8001);
	ct->SetConfig(pCon);
	ct->Start();

	sleep(20);

	printf("thread has been exceuted!");
	//主线程，处理数据，并发送客户端需要的数据
	Director* dir = new Director();
	dir->SetCon(pCon);
	dir->BuilderProject1();
	cout << endl;
	dir->BuilderProject2();
	delete dir;

	return isSuccess;
}

bool SingleInstance::Stop()
{
	bool isSuccess = false;

	if (m_pCt->Stop())
		isSuccess = true;

	return isSuccess;
}
