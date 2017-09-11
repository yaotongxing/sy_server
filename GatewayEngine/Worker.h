#pragma once
class Config;

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

public:
	void SetCon(Config* val) { m_pCon = val; }
	Config* GetCon() { return m_pCon; }
private:
	Config* m_pCon;
};

