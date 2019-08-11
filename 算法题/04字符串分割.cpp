#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>
#include<string>
#include<unordered_set>
#include<vector>

//题目：字符串分割
//给出一串s还有一本辞典dict，确定s可以分割成一个或多个字典词的
//空格分隔序列。

//例如，给定
//s = “leetcode”，
//dict = [“leet”，“code”]。
//
//返回true，因为“leetcode”可以分割为“leetcode”。

//方法：动态规划
//状态：
//		子状态：前1，2，3。。。n个字符能否根据词典中的词被成功分词。
//		F(i)：前i个字符能否根据词典中的词被成功分词
//状态递归：
//		F(i)：true{j < i && F(j) && substr[j + 1,i]能在词典中找到}
//		OR false  在j小于i中，只要找到一个F(j)为true，并且从j + 1到
//		i之间的字符都能在词典中找到，则F(i)为true
//初始值：
//		对于初始值无法确定的。可以引入一个不代表实际意义的空状态，作为
//		状态的起始空状态的值需要保证状态的递推可以正确且顺利的执行
//		到底取什么值可以通过简单的例子进行验证
//		F(0) = true;
//返回结果：F(n);


bool wordBreak(std::string s, std::unordered_set <std::string> &dict)
{
	if (s.empty())
		return false;
	if (dict.empty())
		return false;

	int len = s.length();
	std::vector<bool> v(len + 1, false);
	v[0] = true;
	for (int i = 1; i <= len; i++)
	{
		for (int j = 0; j < i; j++)//j = i - 1; j >= 0; j--
		{
			if (v[j] && dict.find(s.substr(j, i - j)) != dict.end())
			{
				v[i] = true;
				break;
			}
		}
	}
	return v[len];
} 


//int main()
//{
//	std::string s = "leetcode";
//	std::unordered_set <std::string> dict = { "leet", "code" };
//	std::cout << wordBreak(s, dict) << std::endl;
//	system("pause");
//	return 0;
//}