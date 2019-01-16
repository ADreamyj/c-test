#include<iostream>
using namespace std;

//class Date
//{
//public:
//	void print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//	void setdate(int year,int month,int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d1, d2;
//	d1.setdate(2018,5,2);
//	d2.setdate(2019,3,2);
//	d1.print();
//	d2.print();
//	system("pause");
//	return 0;
//}

//class Date
//{
//public:
//	Date()
//	{}
//	Date(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//
//};
//void test()
//{
//	Date d1;
//	Date d2(2015, 5, 18);
//
//	//Date d3();
//}

//class Date {
//public:
//	Date()
//	{
//		_year = 1900;
//		_month = 1;
//		_day = 1;
//	}
//	//Date(int year = 1900, int month = 1, int day = 1)
//	//{
//	//	_year = year;
//	//	_month = month;
//	//	_day = day;
//	//}
//	void print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//// 以下测试函数能通过编译吗？
//int main()
//{
//	Date d1;
//	d1.print();
//	system("pause");
//	return 0;
//}

//class Time
//{
//public:
//	Time()
//	{
//		cout << "Time()" << endl;
//		_hour = 0;
//		_minute = 0;
//		_second = 0;
//	}
//private:
//	int _hour;
//	int _minute;
//	int _second;
//};
//
//class Date 
//{
//private:
//	// 基本类型(内置类型)
//	int _year;
//	int _month;
//	int _day;
//	Time _t;
//};
//
//int main()
//{
//	Date d;
//	system("pause");
//	return 0;
//}

//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	//Date(const Date& d)
//	//{
//	//	_year = d._year;
//	//	_month = d._month;
//	//	_day = d._day;
//	//}
//	void print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	Date d1;
//	d1.print();
//
//	Date d2(d1);
//	d2.print();
//	system("pause");
//	return 0;
//}
//class Date
//{
//public:
//	Date(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;	
//	}
//	bool operator==(const Date& d1, const Date& d2)
//	{
//		return d1._year == d2._year;
//		&& d1._month == d2._month
//			&& d1._day == d2._day
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d1(1997, 8, 25);
//	Date d2(1998, 5, 4);
//	operator==(Date d1, Date d2);
//	system("pause");
//	return 0;
//}
class Date
{
public:
	int GetMonthDay(int year, int month)
	{
		int monthArray[13] = {0, 31, 28, 31, 30, 30, 31, 31, 30, 31, 30, 31, 31};
		if (month == 2 && ((year%4 == 0&& year%100!= 0)||year%400 == 0))
			return 29;
		else
			return monthArray[month];
	}

	Date(int year = 2019, int month = 1, int day = 1)
	{
		if (year > 0 &&
			month > 0 && month < 13 &&
			day > 0 && day <= GetMonthDay(year, month))
		{
			_year = year;
			_month = month;
			_day = day;
		}
		else
		{
			cout << "日期非法" << endl;
		}

	}
	//拷贝构造
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	//复制运算符重载
	Date& operator=(const Date& d)
	{
		if (*this != d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}
	bool operator==(const Date& d)//日期相等
	{
		return _year == d._year
			&& _month == d._month
			&& _day == d._day;
	}
	bool operator!=(const Date& d)//日期不等
	{
		/*return _year != d._year
			|| _month != d._month
			|| _day != d._day;*/
		return !(*this == d);
	}
	bool operator>(const Date& d)//判断日期大于
	{
		if ((_year > d._year) || ((_year == d._year) && (_month > d._month))
			|| ((_year == d._year) && (_month == d._month) && (_day > d._day)))
			return true;
		else
			return false;
	}
	bool operator<(const Date& d)//判断日期小于
	{
		/*if ((_year < d._year) || ((_year == d._year) && (_month < d._month))
			|| ((_year == d._year) && (_month == d._month) && (_day < d._day)))
			return true;
		else
			return false;*/
		return !((*this == d) || (*this > d));
	}
	bool operator>=(const Date& d)//判断日期大于等于
	{
		/*if ((_year > d._year) || ((_year == d._year) && (_month > d._month))
			|| ((_year == d._year) && (_month == d._month) && (_day > d._day))
			|| ((_year == d._year) && (_month == d._month) && (_day == d._day)))
			return true;
		else
			return false;*/
		return !(*this < d);
	}
	bool operator<=(const Date& d)//判断日期小于等于
	{
		/*if((_year < d._year) || ((_year == d._year) && (_month < d._month))
			|| ((_year == d._year) && (_month == d._month) && (_day < d._day))
			|| ((_year == d._year) && (_month == d._month) && (_day == d._day)))
			return true;
		else
			return false;*/
		return !(*this > d);
	}

	//d1 + 10
	Date operator+(int day)//日期加上day
	{
		if (day < 0)
			return (*this) - (-day);
		_day += day;
		while (_day > GetMonthDay(_year, _month))
		{
			_day = _day - GetMonthDay(_year, _month);
			++_month;
			if (_month  > 12)
			{
				++_year;
				_month = 1;
			}
		}
		return *this;
	}
	Date operator+=(int day)//日期+=
	{
		Date arr(*this);
		(*this)  = (*this)+ day;
		return arr;
	}
	Date operator-(int day)//日期减去day
	{
		if (day < 0)
			return (*this) + (-day);
		_day -= day;
		while (_day <= 0)
		{
			--_month;
			if (_month == 0)
			{
				--_year;
				_month = 12;
			}
			_day += GetMonthDay(_year, _month);
		}
		return *this;
	}
	Date operator-=(int day)//日期-=
	{
		Date arr(*this);
		(*this) = (*this) - day;
		return arr;
	}
	// 前置
	Date operator++()//前置++
	{
		/*_day += 1;
		while (_day > GetMonthDay(_year, _month))
		{
			_day = _day - GetMonthDay(_year, _month);
			_month += 1;
			if (_month > 12)
			{
				_year += 1;
				_month = 1;
			}
		}
		return *this;*/
		return (*this) + 1;
	}
	Date operator--()//前置--
	{
		/*_day -= 1;
		if (_day == 0)
		{
			_month -= 1;
			if (_month == 0)
			{
				_year -= 1;
				_month = 12;
			}
			_day = GetMonthDay(_year, _month);
		}
		return *this;*/
		return (*this) - 1;
	}

	// 后置
Date operator++(int)//后置++
	{
		Date arr(*this);
		*this = *this + 1;
		return arr;
	}
Date operator--(int)//后置--
	{
		Date arr(*this);
		*this = *this - 1;
		return arr;
	}
	// d1-d2
	int operator-(const Date& d)//两个日期之间的天数
	{
		Date max(*this);
		Date min(d);
		if (max < min)
		{
			Date temp = max;
			max = min;
			min = temp;
		}
		int count = 0;
		while (max != min)
		{
			count++;
			min = min + 1;
		}
		return count;
	}
	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};

void test1()
{
	Date d1(2019, 2, 28);
	Date d(2019, 1, 1);
	cout << (d1 == d) << endl;//日期相等
	cout << (d1 != d) << endl;//日期不等
	cout << (d1 > d) << endl;//左边大于右边
	cout << (d1 < d) << endl;//左边小于右边
	cout << (d1 >= d) << endl;//左边大于等于右边
	cout << (d1 <= d) << endl;//左边小于等于右边
}
void test2()
{
	Date d2(2019, 1, 20);//日期加上day
	d2.operator+(1000);
	d2.Print();

	Date d3(2019, 5, 6);//日期减去day
	d3.operator-(1000);
	d3.Print();
}
void test3()
{
	Date d2(2019, 1, 20);//日期加上day
	d2.operator+=(1000);
	d2.Print();

	Date d3(2019, 5, 6);//日期减去day
	d3.operator-=(1000);
	d3.Print();
}

void test4()
{
	Date d2(2019, 12, 31);//日期加上day
	d2.operator++();
	d2.Print();
	d2.operator++(1);
	d2.Print();

	Date d3(2019, 1, 1);
	d3.operator--();
	d3.Print();
	d3.operator--(1);
	d3.Print();
}
void test5()
{
	Date d2(2018, 8, 9);
	Date d3(2019, 5, 3);
	cout << (d2 - d3) << endl;

}
int main()
{
	//test1();
	//test2();
	//test3();
	//test4();
	test5();
	system("pause");
	return 0;
}
