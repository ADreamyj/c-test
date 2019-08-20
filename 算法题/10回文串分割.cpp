#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

//题目：回文串分割
//		给定一个字符串s，把s分割为一系列的子串，分割的每一个子串都为
//		回文串。
//		返回最小的分割次数
//		比如：给定s = “aab”，
//		返回1，因为一次cut就可以产生回文分割["aa","b"]


//方法1：动态分割
//状态：
//		子状态：到第1，2，3.。。。n个字符需要的最小分割数
//		上式表示如果从j + 1到i判断为回文串字符，且已经知道从第一个字符
//		到第j个字符的最小切割数，那么只需要再且一次，就可以保证
//		1--》j，j + 1--->i都为回文串
//初始化：
//		F(i) = i - 1
//		上式表示到第i个字符需要的最大分割数
//		比如单个字符只需要切割0次，因为单个字符都是回文串
//		2个字符最大需要1次，3个两次。。。
//发牛结果：
//		F(n)；
//遗留问题：如何判断一个字符串为回文串
//		循环判断首位元素是否相同，如果全部相同，则为回文串
bool isPalindrome(std::string s, int i, int j);
int minCut(std::string s)
{
	if (s.empty())
		return 0;

	int len = s.size() + 1;
	std::vector<int> cut;
	//对F(i)进行初始化
	//F(0) = -1;必要项，如果没有这一项，对于字符串“aaaaa”会产生
	//错误的效果
	for (int i = 0; i < len; ++i)
	{
		cut.push_back(i - 1);
	}

	for (int i = 1; i < len; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			// F(i) = min{F(i), 1 + F(j)}, where j<i && j+1到i是回文串
			// 从最长串判断，如果从第j+1到i为回文字符串
			// 则再加一次分割，从1到j，j+1到i的字符就全部分成了回文字符串
			if (isPalindrome(s, j, i - 1))
			{
				cut[i] = std::min(cut[i], 1 + cut[j]);
			}
		}
	}
	return cut[len - 1];
}

bool isPalindrome(std::string s, int i,int j)
{
	while (i < j)
	{
		if (s[i] != s[j])
			return false;
		i++;
		j--;
	}
	return true;
}

//上述方法两次循环的时间复杂度为O(n^2)
//判断回文串的时间复杂度为O(n);
//所以总的时间复杂度为O(n^3)
//对于过长的字符串，会出现执行错误的情况

//判断字符串的方法可以优化，使得总的时间复杂度变为O(n^2)
//判断回文串；这是一个“是不是”的问题，所以也可以用动态规划来实现

//判断回文串：动态规划
//状态：
//		子状态：从第一个字符到第二个字符是不是回文串，第1-3，第2-5.。。。
//		F(i,j)：字符区间[i,j]是否为回文串
//状态递推：
//		F(i,j)：true--》{s[i] == s[j] && F(i + 1,j - 1)} OR false
//		上述表示如果字符串区间首尾字符相同且在去掉区间首尾字符后
//		字符区间仍为回文串，则上述字符区间为回文串
//		从递推公式中可以看到第i处需要用到第i + 1处的信息，
//		所以应该从字符串末尾进行遍历
//初始化：
//		F(i,j) = false;
//返回结果：
//		矩阵(n,n),只更新一半的值(i <= j) ,n^2/2
int main()
{
	std::string s = "abab";
	std::cout << minCut(s) << std::endl;
	system("pause");
	return 0;
}