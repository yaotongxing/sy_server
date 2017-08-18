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
	///��ȡ��Ʒ������ָ��
	Part* m_pPart;
};

