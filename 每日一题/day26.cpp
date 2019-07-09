#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>
using namespace std;

//1.青蛙跳台阶问题
int fib(int n)
{
	if (n == 1)
		return 1;
	if (n == 2)
		return 1;
	else
		return fib(n - 1) + fib(n - 2);
}
//int main()
//{
//	int n;
//	int m;
//	while (cin >> n)
//	{
//		//cout << fib(n) << endl;
//		m = 1 << (n - 1);
//		cout << m << endl;
//	}
//	return 0;
//}

//2.快到碗里来
int main()
{
	double n, r;   
	while (cin >> n >> r)
	{    
		//周长：2*r*3.1415     
		//身长：n   
		if(n > (2*r*3.1415))  
			cout<<"No"<<endl;    
		else 
			cout << "Yes" << endl;
	}
	return 0;
}