#include "IConcreteFactory2.h"
#include "ConcretePart2.h"


IConcreteFactory2::IConcreteFactory2()
{
}


IConcreteFactory2::~IConcreteFactory2()
{
}

Part* IConcreteFactory2::CreateOperation()
{
	Part* part = new ConcretePart2();
	return part;
}
