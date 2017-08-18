#include "IConcreteFactory1.h"
#include "ConcretePart1.h"



IConcreteFactory1::IConcreteFactory1()
{
}


IConcreteFactory1::~IConcreteFactory1()
{
}

Part* IConcreteFactory1::CreateOperation()
{
	Part* part = new ConcretePart1();
	return part;
}
