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

	//�������ݽṹconfig�������ݽ��д������ش����������
	m_pCon->SetBuff(buff);
	//�������ݿ�ĺ�����������������ݴ������ݿ�

}

