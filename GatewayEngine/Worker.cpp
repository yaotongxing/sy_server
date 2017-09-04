#include "Worker.h"
#include <stdio.h>


Worker::Worker()
{
}


Worker::~Worker()
{
}

bool Worker::HandleRequest(char* buff)
{
	printf("recv msg from client: %s\n", buff);

	//存入数据结构config，对数据进行处理，返回处理完的数据

	//调用数据库的函数，将处理过的数据存入数据库

}

