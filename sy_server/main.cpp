#include <cstdio>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <assert.h>

#include "../Builder/Director.h"
#include "../GatewayEngine/Context.h"

using namespace std;

void * thread_function(void *pArg)
{
	assert(pArg);

	
	void* ret = NULL;
	return ret;
}


int main(int argc,char* argv[])
{
	//����ͻ��˷��͹�������Ϣ
	Context* ct = new Context();
	ct->SetIport(atoi(argv[2]));
	ct->Start();

	sleep(20);
	//���̣߳��������ݣ������Ϳͻ�����Ҫ������
	Director* dir = new Director();
	dir->BuilderProject1();
	cout << endl;
	dir->BuilderProject2();

	delete dir;	
    return 0;
}
