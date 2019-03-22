#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;
class Person
{
public:
	void Print()
	{
		cout << "name:" << _name << endl;
		cout << "age:" << _age << endl;
	}
protected:
	string _name = "qingchun";
	int _age = 19;
};

class Student:public Person
{
protected:
	int _stuid;
};
int main()
{
	Student s;
	s.Print();
	system("pause");
}