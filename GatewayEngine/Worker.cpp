#include "Worker.h"
#include <stdio.h>
#include "../DataStruct/Config.h"

Worker::Worker()
{
}


Worker::~Worker()
{
}

bool Worker::HandleRequest(char* buff)
{
	printf("recv msg from client: %s", buff);

	//存入数据结构config，对数据进行处理，返回处理完的数据
	m_pCon->SetBuff(buff);
	//调用数据库的函数，将处理过的数据存入数据库

}

