#include <cstdio>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include <pthread.h>

#include "../Builder/Director.h"
#include "../GatewayEngine/Context.h"

using namespace std;
int main(int argc,char* argv[])
{
	//����ͻ��˷��͹�������Ϣ����������˼����̣߳������˿ڣ��ռ����ݷŵ�config����
	Context* ct = new Context();
	ct->SetIport(atoi(argv[2]));

	pthread_t tid;
	pthread_create(&tid, NULL, ct->Start, NULL);//ȱ��ѭ��
	
	//���̣߳��������ݣ������Ϳͻ�����Ҫ������
	Director* dir = new Director();
	dir->BuilderProject1();
	cout << endl;
	dir->BuilderProject2();

	delete dir;
	pthread_detach(tid);//ֹͣ�߳�
    return 0;
}
