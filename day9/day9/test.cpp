#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>

using namespace std;

//1.不使用现成的操作符，进行加法运算

//void num(int a, int b)
//{
//	int sum = a, array = 0;
//	while (b != 0)
//	{
//		sum = a^b;
//		array = (a&b) << 1;
//		a = sum;
//		b = array;
//	}
//	cout << sum;
//}
//int main()
//{
//	int a, b;
//	while (cin >> a >> b)
//	{
//		num(a, b);
//	}
//	system("pauae");
//	return 0;
//}

//2.求取路径总数

int path(int a, int b)
{
	if (a > 1 && b > 1)
		return path(a - 1, b) + path(a, b - 1);
	else if ((a == 1 && b >= 1) || (a >= 1 && b == 1))
		return a + b;
	else
		return 0;
}

int main()
{
	int a, b;
	while (cin >> a >> b)
	{
		cout << path(a, b) << endl;
	}
	system("pause");
	return 0;
}