#pragma once
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

private:
	Config();
	static Config* m_pCon;

	///����
	int m_num;
	///���տͻ��˷���������Ϣ
	char m_cBuff[4096];
};

