#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>
#include<vector>
#include<string>

//题目：替换空格
//请实现一个函数，把字符串的每个空格替换为“%20”。例如，
//输入“Hello World”,则输出“Hello%20World”

void RepalceBlank(std::string s)
{
	int length = s.length();
	if (s.empty())
		return ;

	int begin1 = 0;
	int begin2 = 0;
	int i = 0;
	while (s[i] != '\0')
	{
		++begin1;
		if (s[i] == ' ')
		{
			++begin2;
		}
		++i;
	}

	int newlength = begin1 + begin2 * 2;
	s.append(begin2 * 2, ' ');

	int end = newlength - 1;
	int begin = begin1 - 1;

	while (begin >= 0 && end > begin)
	{
		if (s[begin] == ' ')
		{
			s[end--] = '0';
			s[end--] = '2';
			s[end--] = '%';
		}
		else
		{
			s[end--] = s[begin];
		}
		begin--;
	}
	std::cout << s << std::endl;
}
//int main()
//{
//	std::string s = "hello world ";
//	int length = 20;
//	RepalceBlank(s);
//	for (int i = 0; i < s.size(); ++i)
//	{
//		std::cout << s[i] << " ";
//	}
//	std::cout << std::endl;
//	system("pause");
//	return 0;
//}