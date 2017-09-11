#pragma once
class Builder;
class Config;
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
	void SetCon(Config* val) { m_pCon = val; }
	Config* GetCon() { return m_pCon; }
private:
	Builder* m_pBuilder;
	///数据结构指针
	Config* m_pCon;
};

