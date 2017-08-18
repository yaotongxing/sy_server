#pragma once
#include "Builder.h"
class ConcreteBuilder2 :
	public Builder
{
public:
	ConcreteBuilder2();
	~ConcreteBuilder2();

	virtual void BuilderProduct();
};

