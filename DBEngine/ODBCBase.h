#pragma once
class ODBCBase
{
public:
	ODBCBase();
	~ODBCBase();

	//���������ݿ�����
	virtual int Create();

	//�����ݿ�Ͽ�����
	virtual int DisConnect();

};

