#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>
using namespace std;
#include <algorithm> 

//模拟实现double pow,不能使用库函数

//对于这个题而言，如果在不考虑指数为负数的前提下，
//我们可以很快的写出以下的代码
double power1(double base, int exponent)
{
	double result = 1.0;
	while (exponent)
	{
		result *= base;
		exponent--;
	}
	cout << result << endl;
	return result;
}

//代码提升，在考虑指数为负数的情况，取指数的绝对值，和基数的乘积的
//倒数，
bool equal(double num1, double num2)
{
	if ((num1 - num2 > -0.0000001) && (num1 - num2 < 0.0000001))
		return true;
	else
		return false;
}
bool input = false;
bool power2(double base, int exponent)
{
	input = false;
	if (equal(base, 0.0) && exponent < 0)
	{
		input = true;
		return 0.0;
	}

	unsigned int abs = (unsigned int)exponent;
	if (exponent < 0)
		abs = (unsigned int)(-exponent);
	double result = power1(base, abs);

	if (exponent < 0)
		result = 1.0 / result;
	cout << result << endl;
	return result;
}
void test()
{
	double base = 10;
	int exponent = -3;
	power2(base, exponent);
}
int main()
{
	test();
	system("pause");
	return 0;
}