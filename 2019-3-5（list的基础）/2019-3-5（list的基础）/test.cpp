#include<iostream>
#include<list>
#include<stdlib.h>
using namespace std;
void test1()
{
	list<int> l1;
	list<int> l2(4, 100);
	list<int> l3(l2.begin(), l2.end());
	list<int> l4(l3);

	int array[] = { 1, 2, 3, 4, 5, 6 };
	list<int> l5(array, array + sizeof(array)/sizeof(int));

	for (list<int>::iterator it = l5.begin(); it != l5.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	for (auto & e : l5)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test2()
{
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	list<int> l1(array, array + sizeof(array) / sizeof(int));

	for (list<int>::iterator it = l1.begin(); it != l1.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	for (list<int>::reverse_iterator lit = l1.rbegin(); lit != l1.rend(); lit++)
	{
		cout << *lit << " ";
	}
	cout << endl;
}

void test3()
{
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	list<int> l2(array, array + sizeof(array) / sizeof(array[0]));

	cout << l2.size() << endl;

	if (l2.empty())
	{
		cout << "¿ÕµÄlist" << " ";
	}
	else
	{
		for (const auto& e : l2)
			cout << e << " ";
		cout << endl;
	}
}
void test4()
{
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	list<int> l3(array, array + sizeof(array) / sizeof(int));

	for (auto & e : l3)
	{
		cout << e << " ";
	}
	cout << endl;
	
	l3.front() = 10;
	l3.back() = 10;

	for (auto & e : l3)
	{
		cout << e << " ";
	}
	cout << endl;

	//const list<int> l4(array, array + sizeof(array) / sizeof(int));
	//const int & ca = l4.front();
}
void Print(list<int> & it)
{
	for (auto& e : it)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test5()
{
	int array[] = { 1, 2, 3 };
	list<int> l1(array, array + sizeof(array) / sizeof(array[0]));

	l1.push_back(4);
	l1.push_front(0);
	Print(l1);

	l1.pop_back();
	l1.pop_front();
	Print(l1);
}

class Date 
{
public: 
	Date(int year = 1900, int month = 1, int day = 1)
		: _year(year), _month(month), _day(day)
	{ 
		cout << "Date(int, int, int):" << this << endl;
	}

	Date(const Date& d)
		: _year(d._year)
		, _month(d._month)
		, _day(d._day)
	{ 
		cout << "Date(const Date&):" << this << endl;
	}

private: 
	int _year;
	int _month; 
	int _day;
};

void test6()
{
	list<Date> l;  
	Date d(2018, 10, 20);  
	l.push_back(d);  
	l.emplace_back(2018, 10, 21); 
	l.emplace_front(2018, 10, 19);
}

int main()
{
	//test1();
	//test2();
	//test3();
	//test4();
	//test5();
	test6();
	system("pause");
	return 0;
}