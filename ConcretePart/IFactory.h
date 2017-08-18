#pragma once

class Part;

class IFactory
{
public:
	IFactory();
	~IFactory();

	virtual Part* CreateOperation() = 0;


public:
	void SetPart(Part* val) { m_pPart = val; }
	Part* GetPart() { return m_pPart; }
	
protected:
	///获取产品部件类指针
	Part* m_pPart;
};

