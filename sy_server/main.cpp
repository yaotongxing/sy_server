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
#include "../DataStruct/Config.h"
using namespace std;

int main(int argc,char* argv[])
{
	//ȫ�����ݽṹ���ٿռ�
	Config* pCon = Config::GetInstance();

	//����ͻ��˷��͹�������Ϣ
	Context* ct = new Context();
	ct->SetIport(atoi(argv[2]));
	ct->SetConfig(pCon);
	ct->Start();

	sleep(20);

	printf("thread has been exceuted!");
	//���̣߳��������ݣ������Ϳͻ�����Ҫ������
	Director* dir = new Director();
	dir->SetCon(pCon);
	dir->BuilderProject1();
	cout << endl;
	dir->BuilderProject2();

	delete dir;	
    return 0;
}
