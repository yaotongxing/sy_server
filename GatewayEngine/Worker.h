#pragma once
class Worker
{
public:
	Worker();
	~Worker();

	/*********************************************************************
	* @brief : 处理客户端数据
	* @author : yaotongxing
	* @date : 2017/9/1 20:22
	* @version : ver 1.0
	* @inparam : 
	* @outparam : 
	**********************************************************************/
	bool HandleRequest(char* buff);
};

