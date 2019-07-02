#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>
using namespace std;

//编程题1:
//计算日期到天数的转换

//int main()
//{
//	int array[12] = { 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };
//	int year, month, day;
//	int sum = 0;
//	while (cin >> year >> month >> day)
//	{
//		sum += array[month - 2];
//		sum += day;
//		if (month > 2)
//		{
//			if (((month % 4 == 0) && (month % 100 != 0)) || (month % 400 == 0))
//			{
//				++sum;
//			}
//		}
//		cout << sum << endl;
//	}
//	system("pause");
//	return 0;
//}
#include<algorithm>
#include<vector>
int getLuckyPacket(vector<int> x, int n, int pos, int sum, int multi)
{
	int count = 0;
	//循环，搜索以位置i开始所有可能的组合 
	for (int i = pos; i < n; ++i)
	{
		sum += x[i];
		multi *= x[i];
		if (sum > multi)
		{
			//找到符合要求的组合，加1，继续累加后续的值，看是否有符合要求的集合 
			count += 1 + getLuckyPacket(x, n, i + 1, sum, multi);
		}
		else if (x[i] == 1)
		{
			//如何不符合要求，且当前元素值为1，则继续向后搜索 
			count += getLuckyPacket(x, n, i + 1, sum, multi);
		}
		else
		{
			//如何sum大于multi,则后面就没有符合要求的组合了 
			break;
		}
		//要搜索下一个位置之前，首先恢复sum和multi 
		sum -= x[i];
		multi /= x[i];
		//数字相同的球，没有什么区别，都只能算一个组合，所以直接跳过 
		while ( i < n - 1 && x[i] == x[i + 1])
		{
			i++;
		}
	}
	return count;
}
int main()
{
	vector<int> x;
	int n;
	while (cin >> n)
	{
		x.resize(n);
		for (int i = 0; i < n; ++i)
		{
			cin >> x[i];
		}
		sort(x.begin(),x.end());
		cout << getLuckyPacket(x, n, 0, 0, 1) << endl;
	}
	system("pause");
	return 0;
}