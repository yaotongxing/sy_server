#include <cstdio>
#include "../Builder/Director.h"
#include <iostream>
using namespace std;
int main()
{
	//开启服务端监听线程，监听端口，收集数据放到config类中

	//主线程，处理数据，并发送客户端需要的数据

	Director* dir = new Director();
	dir->BuilderProject1();
	cout << endl;
	dir->BuilderProject2();

	delete dir;
    return 0;
}