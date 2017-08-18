#pragma once
#include "IFactory.h"
class IConcreteFactory2 :
	public IFactory
{
public:
	IConcreteFactory2();
	~IConcreteFactory2();

	virtual Part* CreateOperation();
};

