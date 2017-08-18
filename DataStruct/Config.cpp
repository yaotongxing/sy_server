#include "Config.h"
#include <cstdio>

Config* Config::m_pCon = NULL;

Config::Config()
{
	m_num = 0;
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
