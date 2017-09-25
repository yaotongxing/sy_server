#include "OutputLog.h"
#include<time.h>
#include<stdio.h>
#include <iostream> 
#include <fstream> 

OutputLog::OutputLog()
{
}


OutputLog::~OutputLog()
{
}

bool OutputLog::WriteLog(char* szLog,...)
{
	bool isSuccess = false;

	//获取时间
	time_t timer;
	struct tm *tblock;
	timer = time(NULL);
	tblock = localtime(&timer);

	//
	FILE *fp;
	fp = fopen("root/sy_server/log.txt","at");
	if (fp)
	{
		fprintf(fp, "MyLogInfo: %d:%d:%d:%d:%d ", tblock->tm_year, tblock->tm_mon, 
					tblock->tm_mday, tblock->tm_hour,tblock->tm_min);
		fprintf(fp, szLog);

		isSuccess = true;
	}
	fclose(fp);
	return isSuccess;
}
