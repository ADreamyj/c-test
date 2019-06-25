#define _CRT_SECURE_NO_WARNINGS  1


#include<iostream>
#include<string>
#include<vector>
using namespace std;

//编程题1：汽水瓶问题，

//有这样一道智力题：“某商店规定：三个空汽水瓶可以换一瓶汽水。
//小张手上有十个空汽水瓶，她最多可以换 多少瓶汽水喝？”答案是5瓶
//，方法如下：先用9个空瓶子换3瓶汽水，喝掉3瓶满的，喝完以后4个空
//瓶子，用3 个再换一瓶，喝掉这瓶满的，这时候剩2个空瓶子。然后你让
//老板先借给你一瓶汽水，喝掉这瓶满的，喝完以 后用3个空瓶子换一瓶
//满的还给老板。如果小张手上有n个空汽水瓶，最多可以换多少瓶汽水喝？

//int sum(int n)
//{
//	int num = 0;
//	int result = 0;
//	while (n > 1)
//	{
//		result = n / 3;
//		int reminder = n % 3;
//		num = num + result;
//		n = result + reminder;
//		if (n == 2)
//		{
//			++num;
//			break;
//		}
//	}
//	return num;
//}
//int main()
//{
//	int n;
//	while (cin >> n)
//	{
//		cout << sum(n) << endl;
//	}
//	system("pause");
//	return 0;
//}

//编程题2：两个字符串中的最长公共字符串

int main()
{
	string str1, str2;
	while (cin >> str1 >> str2)
	{
		// 以最短的字符串作为s1
		if (str1.size() > str2.size())
			swap(str1, str2);
		int start = 0;
		int max = 0;
		vector<vector<int>> v(str1.size() + 1, vector<int>(str2.size() + 1, 0));

		for (int i = 1; i <= str1.size(); ++i)
		{
			for (int j = 1; j <= str2.size(); ++j)
			{
				if (str1[i - 1] == str2[j - 1])
				{
					v[i][j] = v[i - 1][j - 1] + 1;
				}
				//如果有更长的公共子串，更新长度 
				if (v[i][j] > max)
				{
					max = v[i][j];
					//以i结尾的最大长度为max, 则子串的起始位置为i - max 
					start = i - max;
				}
			}
		}
		cout << str1.substr(start, max) << endl;

	}
	system("pause");
	return 0;
}