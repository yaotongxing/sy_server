#pragma once
class Config
{
public:
	
	~Config();
	static Config* GetInstance();
private:
	Config();
	static Config* m_pCon;

	///����
	int m_num;
};

