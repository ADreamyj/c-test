#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

//微信红包，用普通数组的方法来进行运算

//int main()
//{
//	vector<int> v;
//	int n;
//	while (cin >> n)
//	{
//		v.resize(n);
//		for (int i = 0; i < n; ++i)
//		{
//			cin >> v[i];
//		}
//		sort(v.begin(), v.end());
//
//		int count = 0;
//
//		for (int i = 0; i < n; ++i)
//		{
//			if (v[i] == v[n / 2])
//			{
//				count++;
//			}
//		}
//		if (count > n / 2)
//			cout << v[n / 2] << endl;
//		else
//			cout << "-1" << endl;
//	}
//	
//	system("pause");
//	return 0;
//}

int main()
{
	vector<int> v;
	int n;
	while (cin >> n)
	{
		v.resize(n);
		for (int i = 0; i < n;++i)
		{
			cin >> v[i];
		}
		map<int, int> m;

		for (const auto& e : v)
		{
			++m[e];
		}

		for (const auto& e : m)
		{
			if (e.second > n / 2)
				cout << e.first << endl;
		}
	}
	system("pause");
	return 0;
}