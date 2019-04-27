#define _CRT_SECURE_NO_WARNINGS  1

//题目一：求斐波那契数列的第n项；
//题目二：青蛙跳台阶问题；
//这两个题都是一个道理
//对于变态青蛙跳台阶问题的话，就是求2的阶乘。
//			0	n = 0
//f(n) =	1	n = 1
//			f(n - 1) + f(n - 2)
#include<iostream>
using namespace std;

long long Fib1(int n)
{
	if (n <= 0)
		return 0;
	if (n == 1)
		return 1;
	return Fib1(n - 1) + Fib1(n - 2);
}
long long Fib2(int n)
{
	if (n <= 0)
		return 0;
	if (n == 1)
		return 1;
	long long s1 = 1;
	long long s2 = 0;
	long long fibn = 0;
	for (int i = 2; i <= n; i++)
	{
		fibn = s1 + s2;
		s2 = s1;
		s1 = fibn;
	}
	return fibn;
}
void test()
{
	int n = 13;
	cout<<Fib1(n)<<endl;
	cout << Fib2(n) << endl;

}
int main()
{
	test();
	system("pause");
	return 0;
}