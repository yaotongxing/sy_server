#pragma once
class RawSocket
{
public:
	RawSocket();
	~RawSocket();

	////���ͻ���
	/*********************************************************************
	* @brief : ��������
	* @author : yaotongxing
	* @date : 2017/8/30 20:12
	* @version : ver 1.0
	* @inparam : 
	* @outparam : 
	**********************************************************************/
	int Create();

	/*********************************************************************
	* @brief : ��������
	* @author : yaotongxing
	* @date : 2017/8/30 20:14
	* @version : ver 1.0
	* @inparam : 
	* @outparam : 
	**********************************************************************/
	int Connent();

	/*********************************************************************
	* @brief : �Ͽ�����
	* @author : yaotongxing
	* @date : 2017/8/30 20:15
	* @version : ver 1.0
	* @inparam : 
	* @outparam : 
	**********************************************************************/
	int Close();


	////�������
	/*********************************************************************
	* @brief : �����׽��ֵ�ַ
	* @author : yaotongxing
	* @date : 2017/8/30 20:15
	* @version : ver 1.0
	* @inparam : 
	* @outparam : 
	**********************************************************************/
	int Bind(const char* ip,int iPort);

	/*********************************************************************
	* @brief : ��������
	* @author : yaotongxing
	* @date : 2017/8/30 21:18
	* @version : ver 1.0
	* @inparam : 
	* @outparam : 
	**********************************************************************/
	int Listen(const int iNum);
	/*********************************************************************
	* @brief : ������Ϣ,��ñ������ͻ��˵�ip��port
	* @author : yaotongxing
	* @date : 2017/8/30 23:10
	* @version : ver 1.0
	* @inparam : 
	* @outparam : 
	**********************************************************************/
	int Accept(char* pIp,int& iPort);
	/*********************************************************************
	* @brief : ��ȡ�ͻ���/����˵���Ϣ
	* @author : yaotongxing
	* @date : 2017/8/30 23:52
	* @version : ver 1.0
	* @inparam : ����ָ��ĵ�ַ�����ݳ��ȵĵ�ַ������ѡ��
	* @outparam : 
	**********************************************************************/
	int Receive(void *pData,int *pLen,unsigned int iFlag);
	/*********************************************************************
	* @brief : ������Ϣ���ͻ��ˡ������
	* @author : yaotongxing
	* @date : 2017/8/31 0:11
	* @version : ver 1.0
	* @inparam : 
	* @outparam : 
	**********************************************************************/
	int Send(const void* pData,int iLen, unsigned int uiFlag);


public:
	void SetSocket(int val) { m_iSocket = val; }
	int GetSocket() { return m_iSocket; }
private:
	///socket���
	int m_iSocket;
};

