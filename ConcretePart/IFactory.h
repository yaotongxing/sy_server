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
	///获取产品部件类指针
	Part* m_pPart;
	///获取数据结构指针
	Config* m_pFacCon;
};

