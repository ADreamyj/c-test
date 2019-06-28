#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>
#include<vector>
#include<string>
using namespace std;


//编程题1：小易的升级之路
//测试用例
//3 50
//50 105 200
//5 20
//30 20 15 40 100

//求最大公约数的解法
int getnum(int a, int b)
{
	int c;
	while (c = a%b)
	{
		a = b;
		b = c;
	}
	return b;
}

//int main()
//{
//	int num, power;
//	vector<int> v;
//	while (cin >> num >> power)
//	{
//		v.resize(num);
//		for (int i = 0; i < num; ++i)
//		{
//			cin >> v[i];
//		}
//
//		for (int j = 0; j < num; ++j)
//		{
//			if (power > v[j])
//				power += v[j];
//			else
//				power += getnum(v[j], power);
//		}
//		cout << power << endl;
//	}
//	system("pause");
//	return 0;
//}

int main()
{
	string s;
	while (getline(cin,s))
	{
		int table[256] = {0};
		for (auto e : s)
		{
			++table[e];
		}
		int i;
		for (i = 0; i < s.size(); ++i)
		{
			if (table[s[i]] == 1)
			{
				cout << s[i] << endl;
				break;
			}
		}
		if (i >= s.size())
		{
			cout << "-1" << endl;
		}
	}
	system("pause");
	return 0;
}