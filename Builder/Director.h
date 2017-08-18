#pragma once
class Builder;

class Director
{
public:
	Director();
	~Director();

	void BuilderProject1();
	void BuilderProject2();

public:
	void SetBuilder(Builder* val) { m_pBuilder = val; }
	Builder* GetBuilder() { return m_pBuilder; }
private:
	Builder* m_pBuilder;
};

