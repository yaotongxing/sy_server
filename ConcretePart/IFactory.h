#pragma once

class Part;
class Config;

class IFactory
{
public:
	IFactory();
	~IFactory();

	virtual Part* CreateOperation() = 0;


public:
	void SetPart(Part* val) { m_pPart = val; }
	Part* GetPart() { return m_pPart; }
	void SetConfig(Config* val) { m_pFacCon = val; }
	Config* GetConfig() { return m_pFacCon; }
	
protected:
	///��ȡ��Ʒ������ָ��
	Part* m_pPart;
	///��ȡ���ݽṹָ��
	Config* m_pFacCon;
};

