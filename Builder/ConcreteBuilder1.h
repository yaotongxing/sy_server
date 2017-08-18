#pragma once
#include "Builder.h"
class ConcreteBuilder1 :
	public Builder
{
public:
	ConcreteBuilder1();
	~ConcreteBuilder1();

	virtual void BuilderProduct();
};

