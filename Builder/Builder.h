#pragma once
class IFactory;
class Part;
class Config;


class Builder
{
public:
	Builder();
	~Builder();

	virtual void BuilderProduct()=0;

public:
	void SetIFactory(IFactory* val) { m_pFactoy = val; }
	IFactory* GetIFactory() { return m_pFactoy; }
	void SetPart(Part* val) { m_pPart = val; }
	Part* GetPart() { return m_pPart; }
	void SetConfig(Config* val) { m_pConfig = val; }
	Config* GetConfig() { return m_pConfig; }
protected:
	///������ָ��
	IFactory* m_pFactoy;
	///������ָ��
	Part* m_pPart;
	///���ݽṹָ��
	Config* m_pConfig;

};

