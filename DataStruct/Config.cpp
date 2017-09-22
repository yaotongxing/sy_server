#include "Config.h"
#include <cstdio>
#include <string.h>
#include <pthread.h>  

Config* Config::m_pCon = NULL;
pthread_mutex_t mutext = PTHREAD_MUTEX_INITIALIZER;

Config::Config()
{
	m_num = 0;
	memset(m_cBuff,0,sizeof(m_cBuff));

	m_dNum1 = 0;
	m_dNum2 = 0;
	memset(m_cName, 0, sizeof(m_cName));
}


Config::~Config()
{
}

Config* Config::GetInstance()
{
	//双重锁，确保多线程的安全性
	if (!m_pCon)
	{
		pthread_mutex_lock(&mutext);
		if (!m_pCon)
		{
			m_pCon = new Config();
		}		
		pthread_mutex_unlock(&mutext);
	}
		

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
