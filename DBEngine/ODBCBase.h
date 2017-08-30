#pragma once
class ODBCBase
{
public:
	ODBCBase();
	~ODBCBase();

	//创建和数据库连接
	virtual int Create();

	//和数据库断开连接
	virtual int DisConnect();

};

