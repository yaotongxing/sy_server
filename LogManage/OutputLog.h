#pragma once
class OutputLog
{
public:
	OutputLog();
	~OutputLog();

	bool WriteLog(char* szLog,...);
};

