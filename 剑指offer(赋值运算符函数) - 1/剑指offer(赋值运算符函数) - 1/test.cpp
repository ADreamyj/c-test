#define _CRT_SECURE_NO_WARNINGS  
#include<iostream>
#include<ostream>
#include<assert.h>
using namespace std;

//题目：如下为类型CMyString的声明，请为该类型添加赋值运算符函数
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

	//对于第一种方法写出的赋值运算符函数来说，在分配内存前使用了delete函数
	//释放了m_pDate的内存，如果此时内存不够，会导致new char抛出异常，则
	//m_pDate是一个空指针，这样就会导致程序崩溃。
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
	//对于第二种方法写出的赋值运算符重载函数来说，先创建了一个实例
	//temp，接着把temp.m_pDate和m_pDate进行交换。由于temp只是个
	//临时变量，但程序运行到if函数就出了函数的作用域，调用temp的析构函数
	//将temp.p_Date指向的内存释放掉

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
			//如果用CMyString的构造函数里用new分配内存，如果内存不足
			//抛出异常，但并没有修改原来的实例状态。
			//因此实例的状态还是有效的，保证了异常安全性；
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

