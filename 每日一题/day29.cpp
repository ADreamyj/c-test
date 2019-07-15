#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>
#include<vector>
using namespace std;
//编程题1：难题：求正整数组的最小不可组成和

//arr = {3,2,5} arr的min为2，max为10，在区间[2,10]上，
//4是不能被任何一个子集相加得到的值中最小的，
//所以4是arr的最小不可组成和；


//这是一个动态规划的01背包问题；
//根据承重和已有的重量种类阶段性计算当前承重时能够放入的重量

//当数组中只有2重量的时候，背包承重从2 - 10都可以放入2的数值 
//当数组中放入2和3重量的时候，背包承重从5 - 10 可以放入5，
//3 - 4放入3，2只能放入2   当数组中放入2，3，5重量时
//，背包承重10放入10，8 - 9放入8，7放入7，5 - 6 放入5...
//w 2 3 4 5 6 7 8 9 10

//2 2 2 2 2 2 2 2 2 2   3 2 3 3 5 5 5 5 5 5   5 2 3 3 5 5 7 8 8 10
//最终当每个承重与放入的重量不同时，

//int main()
//{
//	int n;
//	vector<int> v;
//	while (cin >> n)
//	{
//		v.resize(n);
//		for (int i = 0; i < n; i++)
//		{
//			cin >> v[i];
//		}
//
//		int sum = 0, min = v[0]; 
//		int i, j;    
//		for (int i = 0; i < n; i++)    
//		{ 
//			sum += v[i];    
//			min = v[i] < min ? v[i] : min;
//		}
//
//		vector<int> s(sum + 1, 0);
//		for (i = 0; i < n; i++)
//		{
//			for (j = sum; j >= v[i]; j--)
//			{
//				if (s[j] < s[j - v[i]] + v[i])//对每个承重计算当前最大能放置重量 
//					s[j] = s[j - v[i]]+ v[i];//更新背包中能够放入的最大值      
//				else        
//					s [j] = s[j]; 
//			}
//		}
//		for (i = min; i <= sum; i++)    
//		{ 
//			if (i != s[i])
//				cout << i << endl;
//		}             
//		cout << sum + i << endl;
//	}
//	return 0;
//}

//编程题2：有假币
int main()
{
	long long n;
	int sum;
	while (cin >> n)
	{
		if (n == 0)
			break;
		sum = 0;
		while (n >= 2)
		{
			if (n % 3)
			{
				//不可以整除则取最差情况：最重的一份是 n/3 + 1个金币 
				n = n / 3 + 1;
			}
			else
			{
				// 可以整除在直接整除，能够获取到最重的一份
				n /= 3;
			}
			sum++;
		}
		cout << sum << endl;
	}
	return 0;
}