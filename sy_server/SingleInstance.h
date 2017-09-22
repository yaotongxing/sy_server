#pragma once
#include <iostream>
#include <string.h>

class Context;


class SingleInstance
{
public:
	static SingleInstance* GetInstance();
	~SingleInstance();
	
	bool Start();
	bool Stop();


public:
	void SetNum1(double& val) { m_dNum1 = val; }
	double GetNum1() { return m_dNum1; }

	void SetNum2(double& val) { m_dNum2 = val; }
	double GetNum2() { return m_dNum2; }

	void SetName(char val[]) { strcpy(m_cName, val); }
	char* GetName() { return m_cName; }
private:
	SingleInstance();
	///
	static SingleInstance* m_pS;
	///
	double m_dNum1;
	///
	double m_dNum2;
	///
	char m_cName[206];
	///
	Context* m_pCt;
};

