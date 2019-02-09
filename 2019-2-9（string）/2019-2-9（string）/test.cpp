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
	cout << s1.size() << endl;//元素个数是13
	cout << s1.capacity() << endl;//为什么这里的容量是15
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

	s1.reserve(50);//reserve 只能增加空间，不能减少空间
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
	str.push_back(' '); //在str后面加入空格
	str.append("hello");//在str后面追加一个字符"hello"
	str += "friends";
	cout << str << endl;
	cout << str.c_str() << endl;//以c语言的形式打印字符串

	//获取file的后缀
	string file("string.cpp");
	size_t pos = file.rfind('.');
	string suffix(file.substr(pos, file.size() - pos));
	cout << suffix << endl;

	// npos是string里面的一个静态成员变量 
	// static const size_t npos = -1; 
	// 取出url中的域名 
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
	
	//删除url的协议前缀
	pos = url.find("://");
	url.erase(0, pos + 3);
	cout << url << endl;
}
// 利用reserve提高插入数据的效率，避免增容带来的开销 
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
