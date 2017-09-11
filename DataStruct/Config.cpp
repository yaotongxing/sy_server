#include "Config.h"
#include <cstdio>
#include <string.h>

Config* Config::m_pCon = NULL;

Config::Config()
{
	m_num = 0;
	memset(m_cBuff,0,sizeof(m_cBuff));
}


Config::~Config()
{
}

Config* Config::GetInstance()
{
	if (!m_pCon)
		m_pCon = new Config();

	return m_pCon;
}

void Config::SetBuff(char *buff)
{
	printf("yes, config has been execude1!\n");
	int iter = 0;
	while (buff[iter] != NULL)
	{
		m_cBuff[iter] = buff[iter];
		iter++;
	}
}
