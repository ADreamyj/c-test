#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>

//题目：请设置一个函数用来匹配包含','和'*'的正则表达式。
//模式中的','可以表示任意一个字符，
//模式中的'*'可以表示它前面的字符可以出现任意多次。
//在本题中，匹配是指字符串的所有字符匹配整个模式，
//例如/；字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，
//但是"aa.a"和"ab*a"均不匹配。

//解题思路;
//1.如果字符串和模式的第一个字符相等，那么同时向后面移动一个字符。
//2.如果模式的字符位'.'的话，两者也是同时向后移动一个字符。
//3.如果模式的的第二个字符位'*'的话，可能有以下几种匹配方式。
//	（1）模式向后移动两位，直接跳过前面的字符
//	（2）如果模式的第一个字符和字符串中第一个字符相互匹配的话，
//		字符串向后移动一个字符，而模式可以向后移动两个字符，
//		也可以选择保持不变。

//代码如下
bool matchCore(char* str, char* pattern);
bool match(char* str, char* pattern)
{
	if (str == nullptr || pattern == nullptr)
		return false;
	return matchCore(str, pattern);
}
bool matchCore(char* str, char* pattern)
{
	if (*str == '\0' && *pattern == '\0')
		return true;

	if (*str != '\0' && *pattern == '\0')
		return false;
	if (*(pattern + 1) == '*')
	{
		if (*pattern == *str || (*pattern == '.' && *pattern != '\0'))
		{
			return matchCore(str + 1, pattern + 2)
				|| matchCore(str + 1, pattern)
				|| matchCore(str, pattern + 2);
		}
		else
			return match(str, pattern + 2);
	}

	if (*pattern == *str || (*pattern == '.' && *str != '\0'))
		return matchCore(str + 1, pattern + 1);
}
//int main()
//{
//	char* str = "aaa";
//	char* pattern = "ab*ac*a";
//	char* pattern1 = "ab*a";
//	std::cout << match(str, pattern) <<std::endl;
//	std::cout << match(str, pattern1) << std::endl;
//	system("pause");
//	return 0;
//}