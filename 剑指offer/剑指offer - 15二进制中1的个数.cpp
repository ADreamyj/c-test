#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>

//题目：二进制中1的个数
//请实现一个函数，输入一个整数，输出该整数中1的个数，
//例如：把9表示为二进制是1001，有两位是1；则输出2


//方法1：将1和n进行&运算，遇见1得1，遇见0为0；循环32次
int Number1(int n)
{
	int count = 0;
	unsigned int flag = 1;
	while (flag)
	{
		if (n & flag)
			count++;
		flag = flag << 1;
	}
	std::cout << count << std::endl;
	return count;
}

//方法2：循环1的个数次
int Number2(int n)
{
	int count = 0;
	while (n)
	{
		n = (n - 1) & n;
		++count;
	}
	std::cout << count << std::endl;
	return count;
}

//int main()
//{
//	Number1(9);
//	Number2(9);
//	system("pause");
//	return 0;
//}