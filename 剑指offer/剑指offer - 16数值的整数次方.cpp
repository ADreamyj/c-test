#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>

//题目：实现函数double Power(double base,int exponent),
//求base的exponse次方，不得使用库函数，同时不需要考虑大数问题

//方法1，只能处理底数和指数都是正数的情况

double Power1(double base, int exponent)
{
	double result = 1.0;
	for (int i = 1; i <= exponent; ++i)
	{
		result *= base;
	}
	return result;
}

//方法2：处理更多种情况
bool flag = false;

bool equal(double A)
{
	bool result = false;
	if (A >= -0.00001 && A <= 0.00001)
	{
		result = true;
	}
	return result;
}
double Power2(double base, int exponent)
{
	flag = false;
	if (equal(base) && exponent < 0)
	{
		flag = true;
		return 0.0;
	}

	unsigned int abs = unsigned int(exponent);
	if (exponent < 0)
		abs = unsigned int(-exponent);

	double result = Power1(base, exponent);

	if (exponent < 0)
		result = 1.0 / result;

	std::cout << result << std::endl;
	return result;
}

//基于公式，递归实现 求数值的整数次方（效率更高）
//输入：base底数, exponent 指数
//返回：结果
//(5,3)101^11 = 101^01 * 101^10;

double Power3(double base, int exponent)
{
	//2.回归条件
	if (exponent == 0)
		return 1;
	if (exponent == 1)
		return base;

	//1.递推公式
	double result = Power3(base, exponent >> 1);

	//3.回归计算公式
	result *= result;
	if (exponent & 0x1 == 1)
		result *= base;

	std::cout << result << std::endl;
	return result;
}
int main()
{
	Power2(5.0, 3);
	std::cout << Power3(5.0, 3) << std::endl;
	system("pause");
	return 0;
}