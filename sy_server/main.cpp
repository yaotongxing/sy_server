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
	//处理客户端发送过来的信息，开启服务端监听线程，监听端口，收集数据放到config类中
	Context* ct = new Context();
	ct->SetIport(atoi(argv[2]));

	pthread_t tid;
	pthread_create(&tid, NULL, ct->Start, NULL);//缺少循环
	
	//主线程，处理数据，并发送客户端需要的数据
	Director* dir = new Director();
	dir->BuilderProject1();
	cout << endl;
	dir->BuilderProject2();

	delete dir;
	pthread_detach(tid);//停止线程
    return 0;
}
