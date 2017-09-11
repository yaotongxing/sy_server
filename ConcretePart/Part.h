#pragma once
class Config;

class Part
{
public:
	Part();
	~Part();

	virtual void CreatePart() = 0;

public:
	void SetCon(Config* val) { m_pCon = val; }
	Config* GetCon() { return m_pCon; }
protected:
	Config* m_pCon;
};

