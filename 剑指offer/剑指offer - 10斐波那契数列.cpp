#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>

//题目：斐波那契数列
//写出一个函数，输入n，求斐波那契数列的第n项，斐波那契的定义如下：
//			0						n = 0
//	F(n) =  1						n = 1
//			F(n - 1) + F(n - 2)		n > 1

//方法1：递归，但是效率很差O(2^n)
long long Fibonacci1(unsigned int n)
{
	if (n <= 0)
		return 0;
	if (n == 1)
		return 1;
	return Fibonacci1(n - 1) + Fibonacci1(n - 2);
}

//方法2：动态规划，时间复杂度为O(n)
long long Fibonacci2(unsigned int n)
{
	if (n <= 0)
		return 0;
	if (n == 1)
		return 1;

	long long sum;
	long long num1 = 0;
	long long num2 = 1;
	for (unsigned int i = 2; i <= n; ++i)
	{
		sum = num1 + num2;
		num1 = num2;
		num2 = sum;
	}
	return sum;
}

int main()
{
	std::cout << Fibonacci1(15) << std::endl;
	std::cout << Fibonacci2(15) << std::endl;
	system("pause");
	return 0;
}