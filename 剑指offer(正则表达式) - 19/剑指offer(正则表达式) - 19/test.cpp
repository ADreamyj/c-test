#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>
//对于这个题目而言，求正则表达式，
//判断两个字符串在包含'.'和'*'之后是否继续相等
bool match(const char* str1, const char* str2);
bool matchcore(const char* str1, const char* str2);
bool match(const char* str1, const char* str2)
{
	if (str1 == nullptr || str2 == nullptr)
		return false;
	return matchcore(str1, str2);
}

bool matchcore(const char* str1, const char* str2)
{
	if (*str1 == '\0' && *str2 == '\0')
		return true;
	if (*str1 != '\0' && *str2 == '\0')
		return false;

	if (*(str2 + 1) == '*')
	{
		if (*str2 == *str1 || (*str2 == '.' && *str1 != '\0'))
			return matchcore(str1 + 1, str2 + 2)
			|| matchcore(str1, str2 + 1)
			|| matchcore(str1, str2 + 2);
		else
			return matchcore(str1, str2 + 2);
	}
	if (*str1 == *str2 || (*str2 == '.' && *str1 != '\0'))
		return matchcore(str1 + 1, str2 + 1);
	return false;
}
void Test(const char* testName, const char* str1, const char* str2, bool expected)
{
	if (testName != nullptr)
		printf("%s begins: ", testName);

	if (match(str1, str2) == expected)
		printf("Passed.\n");
	else
		printf("FAILED.\n");
}
void test()
{
	const char* str1 = "aaa";
	const char* str2 = "a.a";
	Test("Test1", str1, str2, true);
}
int main()
{
	test();
	system("pause");
	return 0;
}