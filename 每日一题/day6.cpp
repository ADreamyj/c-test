#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>
#include<vector>
#include<string>

//编程题1：不要二
//如果(x1,y1)放了蛋糕，则满足 ( (x1-x2) * (x1-x2) + (y1-y2) * (y1-y2) ) == 4的(x2,y2)不能放蛋 糕。

//((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)) == 4
//看起来是一个无解的表达式。
//但是可以进行加法表达式分解：
//1 + 3 = 4 
//3 + 1 = 4
//2 + 2 = 4 
//0 + 4 = 4
//4 + 0 = 4

//仔细分析前三个表达式是不可能的，因为(x1 - x2) * (x1 - x2)表达式结果不能
//等于2或3。 也就是说((x1 - x2) * (x1 - x2) 和(y1 - y2) * (y1 - y2))两个
//表达式一个等于0，一个等于4.
//可以看出：假设放蛋糕的位置是(x1, y1)，则不能放蛋糕的位置(x2, y2)，
//满足x1 == x2, y1 - y2 == 2或者x1x2 == 2, y1 == y2.

//仔细读理解了上面的题目解读，本题就非常简单了，使用vector<vector<int>>
//定义一个二维数组，resize开空间并初始化，每个位置初始化为1，表示当蛋糕
//，a[i][j]位置放蛋糕，则可以标记处a[i][j + 2]和a[i + 2][j]位置 不能放蛋糕
//，遍历一遍二维数组，标记处不能放蛋糕的位置，统计也就统计出了当蛋糕的
//位置数。

//int main()
//{
//	std::vector<std::vector<int>> v;
//	int x, y, ret = 0;
//	std::cin >> x >> y;
//	v.resize(x);
//	for (auto& a : v)
//	{
//		a.resize(y, 1);
//	}
//	for (int i = 0; i < x; ++i)
//	{
//		for (int j = 0; j < y; ++j)
//		{
//			if (v[i][j] == 1)
//			{
//				//ret++的意思是统计出位置为一的个数，为一就是有蛋糕
//				ret++;
//				//在满足i + 2全都在表格里的前提下，让i+ 2和j + 2的位置为0
//				if (i + 2 < x)
//					v[i + 2][j] = 0;
//				if (j + 2 < y)
//					v[i][j + 2] = 0;
//			}
//			
//		}
//	}
//	std::cout << ret << std::endl;
//	system("pause");
//	return 0;
//}

//编程题2：字符串转整数
//class Solution{
//public:
//	int StrToInt(std::string str)
//	{
//		if (str.empty())
//			return 0;
//
//		int flag = 1;
//		if (str[0] == '+')
//		{
//			flag = 1;
//			str[0] = '0';
//		}
//
//		if (str[0] == '-')
//		{
//			flag = -1;
//			str[0] = '0';
//		}
//
//		int sum = 0;
//		for (int i = 0; i < str.size(); i++)
//		{
//			if (str[i] < '0' || str[i] > '9')
//			{
//				sum = 0;
//				break;
//			}
//
//			sum = sum * 10 + str[i] - '0';
//		}
//		return flag * sum;
//	}
//};