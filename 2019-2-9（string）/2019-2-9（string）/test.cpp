#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;

void test1()
{
	string s1;
	string s2("hello friends");
	string s3(10, 'a');
	string s4(s2);
	string s5(s3, 5);
	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4 << endl;
	cout << s5 << endl;
}
void test2()
{
	string s1("hello friends");
	cout << s1.length() << endl;
	cout << s1.size() << endl;//Ԫ�ظ�����13
	cout << s1.capacity() << endl;//Ϊʲô�����������15
	cout << s1 << endl;

	s1.clear();
	cout << s1.size() << endl;
	cout << s1.capacity() << endl;

	s1.resize(10, 'a');
	cout << s1.size() << endl;
	cout << s1.capacity() << endl;

	s1.resize(15);
	cout << s1.size() << endl; // "aaaaaaaaaa\0\0\0\0\0" 
	cout << s1.capacity() << endl;
	cout << s1 << endl;

	s1.resize(5);
	cout << s1.size() << endl; 
	cout << s1.capacity() << endl;
	cout << s1 << endl;
}
void test3()
{
	string s1;
	cout << s1.capacity() << endl;

	s1.reserve(100);
	cout << s1.size() << endl;
	cout << s1.capacity() << endl;

	s1.reserve(50);//reserve ֻ�����ӿռ䣬���ܼ��ٿռ�
	cout << s1.size() << endl;
	cout << s1.capacity() << endl;
}

void test4()
{
	string s1("hello friends");
	const string s2("hello friends");
	cout << s1 << " " << s2 << endl;
	cout << s1[0] << " " << s2 <<endl;

	s1[0] = 'H';
	cout << s1 << endl;

	for (size_t i = 0; i < s1.size(); ++i)
	{
		cout << s1[i] << endl;
	}
	for (size_t i = 0; i < s1.size(); i++)
	{
		cout << s1[i] << endl;
	}
}

void test5()
{
	string str;
	str.push_back(' '); //��str�������ո�
	str.append("hello");//��str����׷��һ���ַ�"hello"
	str += "friends";
	cout << str << endl;
	cout << str.c_str() << endl;//��c���Ե���ʽ��ӡ�ַ���

	//��ȡfile�ĺ�׺
	string file("string.cpp");
	size_t pos = file.rfind('.');
	string suffix(file.substr(pos, file.size() - pos));
	cout << suffix << endl;

	// npos��string�����һ����̬��Ա���� 
	// static const size_t npos = -1; 
	// ȡ��url�е����� 
	string url("http://www.cplusplus.com/reference/string/find");
	cout << url << endl;
	size_t start = url.find("://");
	if (start == string::npos)
	{
		cout << "invalid url" << endl;
		return;
	}
	start += 3;
	size_t finish = url.find('/', start);
	string address = url.substr(start, finish - start);
	cout << address << endl;
	
	//ɾ��url��Э��ǰ׺
	pos = url.find("://");
	url.erase(0, pos + 3);
	cout << url << endl;
}
// ����reserve��߲������ݵ�Ч�ʣ��������ݴ����Ŀ��� 
void TestPushBack()
{
	string s;
	size_t sz = s.capacity();
	cout << "making s grow:\n";
	for (int i = 0; i < 100; i++)
	{
		s += 'c';
		if (sz != s.capacity())
		{
			sz = s.capacity();
			cout << "capacity changed:" << sz << '\n';
		}
	}
}
void TestPushBack_p()
{
	string s;
	s.reserve(100);
	size_t sz = s.capacity();
	cout << "making s grow:\n";
	for (int i = 0; i < 100; ++i)
	{
		s += 'c';
		if (sz != s.capacity())
		{
			sz = s.capacity();
			cout << "capacity changed:" << sz << '\n';
		}
	}
}
int main()
{
	//test1();
	//test2();
	//test3();
	//test4();
	//test5();
	//TestPushBack();
	TestPushBack_p();
	system("pause");
	return 0;
}
