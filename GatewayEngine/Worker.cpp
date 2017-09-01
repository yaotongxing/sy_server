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
}

