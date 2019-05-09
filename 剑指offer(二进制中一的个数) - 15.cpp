#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>

using namespace std;

//求一个二进制中一的个数


//只适用于正整数的解法

int num1(int n)
{
	int count = 0;
	while (n)
	{
		if (n & 1)
			count++;
		n = n >> 1;
	}
	cout << count << endl;
	return count;
}

//正规解法
int num2(int n)
{
	int count = 0;
	unsigned int flag = 1;
	while (flag)
	{
		if (n&flag)
			count++;
		flag = flag << 1;
	}
	cout << count << endl;
	return count;
}

//最优解法
int num3(int n)
{
	int count = 0;
	while (n)
	{
		n = n&(n - 1);
		count++;
	}
	cout << count << endl;
	return count;

}
void test()
{
	int n = 10;
	num1(n);
	num2(n);
	num3(n);
}
int main()
{
	test();
	system("pause");
	return 0;
}