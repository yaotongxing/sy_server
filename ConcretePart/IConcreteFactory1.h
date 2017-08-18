#pragma once
#include "IFactory.h"
class IConcreteFactory1 :
	public IFactory
{
public:
	IConcreteFactory1();
	~IConcreteFactory1();
	virtual Part* CreateOperation();
};

