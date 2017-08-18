#include "ConcreteBuilder1.h"
#include <iostream>
#include "../ConcretePart/ConcretePart1.h"
#include "../ConcretePart/ConcretePart2.h"
#include "../ConcretePart/IConcreteFactory1.h"
#include "../ConcretePart/IConcreteFactory2.h"

using namespace std;

ConcreteBuilder1::ConcreteBuilder1()
{
}


ConcreteBuilder1::~ConcreteBuilder1()
{
}

void ConcreteBuilder1::BuilderProduct()
{
	cout << "i am builder1:";
	IFactory* pFac1 = new IConcreteFactory1();
	pFac1->CreateOperation()->CreatePart();

	//该处可用状态模式
	IFactory* pFac2 = new IConcreteFactory2();
	pFac2->CreateOperation()->CreatePart();

}
