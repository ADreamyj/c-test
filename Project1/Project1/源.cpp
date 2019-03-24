#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;

//class Person
//{
//public:
//	void Print()
//	{
//		cout << "name:" << _name << endl;
//		cout << "age:" << _age << endl;
//	}
//protected:
//	string _name = "qingchun";
//	int _age = 19;
//};
//
//class Student :public Person
//{
//protected:
//	int _stuid;
//};

//class Person
//{
//protected:
//	string _name;//姓名
//	string _sex;//性别
//	int _age;//年龄
//};
//
//class Student : public Person
//{
//public:
//	int _No;//学号
//};
//
//void Test()
//{
//	Student s;
//	Person p = s;
//	Person* pp = &s;
//	Person& rp = s;
//
//	pp = &s;
//	Student* ps1 = (Student*)pp;
//	ps1->_No = 10;
//
//	pp = &p;
//	Student* ps2 = (Student*)pp;
//	ps2->_No = 10;
//}

//class Person 
//{
//public:
//	Person(const char* name = "peter") 
//		: _name(name)  
//	{
//		cout << "Person()" << endl; 
//	}  
//
//	Person(const Person& p) 
//		: _name(p._name)  
//	{ 
//		cout << "Person(const Person& p)" << endl;
//	}   
//
//	Person& operator=(const Person& p)   
//	{ 
//		cout << "Person operator=(const Person& p)" << endl; 
//		if (this != &p)   
//			_name = p._name;      
//		return *this; 
//	} 
//
//	~Person()
//	{
//		cout << "~Person()" << endl;
//	}
//protected:   
//	string _name; // 姓名
//};
//
//class Student : public Person 
//{
//public:  
//	Student(const char* name, int num) 
//		: Person(name)
//		, _num(num)    
//	{ 
//		cout << "Student()" << endl;
//	}  
//
//	Student(const Student& s) 
//		: Person(s)
//		, _num(s._num)   
//	{ 
//		cout << "Student(const Student& s)" << endl;
//	}      
//
//	Student& operator = (const Student& s)   
//	{ 
//		cout << "Student& operator= (const Student& s)" << endl;
//		if (this != &s) 
//		{ 
//			_num = s._num; 
//			Person::operator =(s);
//
//		}    
//		return *this;
//	}   
//
//	~Student()   
//	{ 
//		cout << "~Student()" << endl; 
//	}
//protected: 
//	int _num; //学号
//};
//class Student;

class Person
{
public:
	friend void Display(const Person& p);
protected:
	string _name;
};

//class Student : public Person
//{
//protected:
//	int _stuNum;
//};
void Display(const Person& p)
{
	cout << p._name << endl;
	//cout << s._stuNum << endl;
}
//class Person {
//public: 
//	Person()
//	{ 
//		++_count; 
//	} 
//protected: 
//	string _name;// 姓名
//public :  
//	static int _count; // 统计人的个数。
//};
//
//int Person :: _count = 0; 
//
//class Student : public Person 
//{ 
//protected : 
//	int _stuNum ; // 学号 
//}; 
//
//class Graduate : public Student 
//{ 
//protected : 
//	string _seminarCourse ; // 研究科目 
//}; 
//
//void TestPerson() 
//{  
//	Student s1 ; 
//	Student s2 ;				
//	Student s3 ;  
//	Graduate s4 ;  
//	cout <<" 人数 :"<< Person ::_count << endl; 
//	Student ::_count = 0; 
//	cout <<" 人数 :"<< Person ::_count << endl; 
//} 
class A
{
public:
	int a;
};

class B :  virtual public A
{
public:
	int b;
};

class C : virtual  public A
{
public:
	int c;
};

class D : public B, public C
{
public:
	int d;
};

void Test()
{
	D s;
	//s.B::a = 1;
	//s.C::a = 2;
	s.a = 1;
	s.b = 3;
	s.c = 4;
	s.d = 5;
}
int main()
{
	//Test();
	//Student s;
	//s.Print();
	/*Student s1("qingchun",20);
	Student s2(s1);
	Student s3("laofu", 20);
	s1 = s3;*/
	//Person p;
	//Student s;
	//Display(p);
	//TestPerson();
	Test();
	system("pause");
	return 0;

}