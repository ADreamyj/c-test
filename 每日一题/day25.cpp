#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>
#include<string>
using namespace std;


/*矩阵是   |1 1|^2=|1 1|*|1 1|=|2 1|
//         |1 0|   |1 0| |1 0| |1 1|

n的取值：1 2 3 4 5 6 ....
左上角值：1 2 3 5 8 13 ....

又是变式的斐波那契！！！！！！！！！！！
*/

//int main()
//{
//	int n, fib[10001], i, x;
//	fib[0] = 1; fib[1] = 1;
//	for (i = 2; i<10001; i++) 
//		fib[i] = (fib[i - 1] % 10000 + fib[i - 2] % 10000) % 10000;
//	while (cin >> n)
//	{
//		while (n--)
//		{
//			cin >> x;
//			printf("%04d", fib[x]);
//		}
//		cout << endl;
//	}
//	return 0;
//}

//编程题2:求树根
int num(int sum)
{
	int n = 0;
	while (sum > 0)
	{
		n  += sum % 10;
		sum = sum / 10;
	}
	while (n > 9)
	{
		 n = num(n);
	}
	return n;
}
int main()
{
	string s;
	while (cin >> s)
	{
		int sum = 0;
		for (int i = 0; i < s.length(); ++i)
		{
			sum += s[i] - '0';
		}
		cout << num(sum) << endl;
	}

}