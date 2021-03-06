#pragma once
#include <iostream>
#include <string.h>
#define  MAX_NUM 4096
class Config
{
public:
	
	~Config();
	static Config* GetInstance();

	void SetBuff(char *buff);
	char* GetBuf() { return m_cBuff; }

public:
	void SetNum(int val) { m_num = val; }
	int GetNum() { return m_num; }
	void SetNum1(double& val) { m_dNum1 = val; }
	double GetNum1() { return m_dNum1; }

	void SetNum2(double& val) { m_dNum2 = val; }
	double GetNum2() { return m_dNum2; }

	void SetName(char val[]) { strcpy(m_cName, val); }
	char* GetName() { return m_cName; }
private:
	Config();
	static Config* m_pCon;

	///个数
	int m_num;
	///接收客户端发过来的消息
	char m_cBuff[4096];
	
	///
	double m_dNum1;
	///
	double m_dNum2;
	///
	char m_cName[206];
};

