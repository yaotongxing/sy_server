#include "ConcreteBuilder2.h"
#include <iostream>
#include "../ConcretePart/ConcretePart1.h"
#include "../ConcretePart/ConcretePart2.h"
#include "../ConcretePart/IConcreteFactory1.h"
#include "../ConcretePart/IConcreteFactory2.h"

using namespace std;


ConcreteBuilder2::ConcreteBuilder2()
{
}


ConcreteBuilder2::~ConcreteBuilder2()
{
}

void ConcreteBuilder2::BuilderProduct()
{
	IFactory* pFac1 = new IConcreteFactory2();
	pFac1->CreateOperation()->CreatePart();

	IFactory* pFac2 = new IConcreteFactory1();
	pFac2->CreateOperation()->CreatePart();
}
