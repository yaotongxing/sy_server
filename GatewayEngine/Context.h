#pragma once
class RawSocket;

/********************************************************************
* @brief : ����Ϊ���ع��̵Ľӿ��࣬�ⲿ���ݽ������ǵ��ø���ĺ���
* @author : yaotongxing
* @date : 2017/9/1 10:47
* @version : ver 1.0
*********************************************************************/
class Context
{
public:
	Context();
	~Context();

public:
	/*********************************************************************
	* @brief : ����˿ڣ�׼������
	* @author : yaotongxing
	* @date : 2017/9/1 10:49
	* @version : ver 1.0
	* @inparam : 
	* @outparam : 
	**********************************************************************/
	void* Start();

public:
	void SetIport(int val) { m_iPort = val; }
	int GetIport() { return m_iPort; }

private:


private:
	///
	RawSocket* m_pRawSock;

	///
	int m_iPort;

};