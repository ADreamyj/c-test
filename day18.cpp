#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>
#include<string>
using namespace std;

//编程题1：兔子问题
//int main()
//{
//	int month;
//	while (cin >> month)
//	{
//		int first = 1;
//		int second = 1;
//		int result = 1;
//		for (int i = 3; i <= month; ++i)
//		{
//			result = first + second;
//			first = second;
//			second = result;
//		}
//		cout << result << endl;
//	}
//	system("pause");
//	return 0;
//}
//编程题2：通配字符串

//bool match(const char*  s1,const char* s2)
//{
//	if (*s1 == '\0' &&  *s2 == '\0')
//		return true;
//	if (*s1 == '\0' || *s2 == '\0')
//		return false;
//
//	if (*s1 == '?')
//	{
//		return match(s1 + 1, s2 + 1);
//	}
//	else if (*s1 == '*')
//	{
//		return match(s1 + 1, s2) ||
//			match(s1 + 1, s2 + 1) ||
//			match(s1, s2 + 1);
//	}
//	else if (*s1 == *s2)
//	{
//		return match(s1 + 1, s2 + 1);
//	}
//	return false;
//}
//int main()
//{
//	string s1, s2;
//	while (cin >> s1 >> s2)
//	{
//		bool ret = match(s1.c_str(), s2.c_str());
//		if (ret)
//			cout << "true" << endl;
//		else
//			cout << "false" << endl;
//
//	}
//	system("pause");
//	return 0;
//}

bool match(char *str1, char *str2)
{
	if (*str1 == '\0'  && *str2 == '\0')
		return true;
	else if (*str1 == '\0' || *str2 == '\0')
		return false;
	if (*str1 == '?')
		return match(str1 + 1, str2 + 1);
	else if (*str1 == '*')
		return match(str1 + 1, str2) || match(str1 + 1, str2 + 1) || match(str1, str2 + 1);
	else if (*str1 == *str2)
		return match(str1 + 1, str2 + 1);
	return false;
}

int main()
{
	char str1[100], str2[100];
	while (cin >> str1 >> str2)
	{
		if (match(str1, str2))
			cout << "true" << endl;
		else
			cout << "false" << endl;
	}

	return 0;
}