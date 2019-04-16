#define _CRT_SECURE_NO_WARNINGS  
#include<iostream>
#include<ostream>
#include<assert.h>
using namespace std;

//��Ŀ������Ϊ����CMyString����������Ϊ��������Ӹ�ֵ���������
class CMyString
{
public:
	CMyString(const char* pDate = " ")
	{
		if (nullptr == pDate)
		{
			assert(pDate);
			return;
		}
		m_pDate = new char(strlen(pDate) + 1);
		strcpy(m_pDate, pDate);
	}

	//���ڵ�һ�ַ���д���ĸ�ֵ�����������˵���ڷ����ڴ�ǰʹ����delete����
	//�ͷ���m_pDate���ڴ棬�����ʱ�ڴ治�����ᵼ��new char�׳��쳣����
	//m_pDate��һ����ָ�룬�����ͻᵼ�³��������
	/*CMyString& operator=(const CMyString& str)//1
	{
		if (this != &str)
		{
			delete [] m_pDate;
			m_pDate = nullptr;

			m_pDate = new char[strlen(str.m_pDate + 1)];
			strcpy(m_pDate, str.m_pDate);
		}
		return *this;
	}*/
	//���ڵڶ��ַ���д���ĸ�ֵ��������غ�����˵���ȴ�����һ��ʵ��
	//temp�����Ű�temp.m_pDate��m_pDate���н���������tempֻ�Ǹ�
	//��ʱ���������������е�if�����ͳ��˺����������򣬵���temp����������
	//��temp.p_Dateָ����ڴ��ͷŵ�

	CMyString(const CMyString& s)
		:m_pDate(new char [strlen(s.m_pDate) + 1])
	{
		strcpy(m_pDate, s.m_pDate);
	}


	CMyString& operator=(const CMyString& str)//2
	{
		if (this != &str)
		{
			CMyString temp(str);
			//�����CMyString�Ĺ��캯������new�����ڴ棬����ڴ治��
			//�׳��쳣������û���޸�ԭ����ʵ��״̬��
			//���ʵ����״̬������Ч�ģ���֤���쳣��ȫ�ԣ�
			char* ptemp = temp.m_pDate;
			temp.m_pDate = m_pDate;
			m_pDate = ptemp;
		}
		return *this;
	}

	~CMyString(void)
	{}
private:
	friend ostream& operator << (ostream& _cout, CMyString& s);
public:
	char* m_pDate;
};
ostream& operator << (ostream& _cout,const CMyString& s)
{
	cout << s.m_pDate;
	return _cout;
}
int main()
{
	CMyString a = "123";
	CMyString b ;
	b = a;
	cout << b << endl;
	system("pause");
	return 0;
}

