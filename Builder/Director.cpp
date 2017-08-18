#include "Director.h"
#include "Builder.h"
#include "ConcreteBuilder1.h"
#include "ConcreteBuilder2.h"


Director::Director()
{
}


Director::~Director()
{
	if (m_pBuilder)
		delete m_pBuilder;
}

void Director::BuilderProject1()
{
	//�÷������ƴ����ܺţ��ڲ�����new��һ����������Ҫ�ⲿ����
	Builder* bud1 = new ConcreteBuilder1();
	bud1->BuilderProduct();

	Builder* bud2 = new ConcreteBuilder2();
	bud2->BuilderProduct();
}

void Director::BuilderProject2()
{
	Builder* bud1 = new ConcreteBuilder2();
	bud1->BuilderProduct();

	Builder* bud2 = new ConcreteBuilder1();
	bud2->BuilderProduct();
}
