#include "ConcretePart2.h"
#include <iostream>
#include <stdio.h>

#include "../DataStruct/Config.h"

using namespace std;


ConcretePart2::ConcretePart2()
{
}


ConcretePart2::~ConcretePart2()
{
}

void ConcretePart2::CreatePart()
{
	cout << "This is Part2!"<<endl;

	//��ӡ�ͻ��˷��͵���Ϣ
	if (m_pCon)
	{
		printf("Part2 recieve message:%s\n", m_pCon->GetBuf());
	}
	else
	{
		printf("Part2 recieve message is null!\n");
	}
	
}
