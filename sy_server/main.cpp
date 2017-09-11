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
	//全局数据结构开辟空间
	Config* pCon = Config::GetInstance();

	//处理客户端发送过来的信息
	Context* ct = new Context();
	ct->SetIport(atoi(argv[2]));
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
    return 0;
}
