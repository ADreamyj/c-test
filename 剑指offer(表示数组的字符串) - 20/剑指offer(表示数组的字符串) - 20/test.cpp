#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>
using namespace std;

bool scanf1int(const char** str);
bool scanf2int(const char** str);

bool isNumeric(const char* str)
{
	if (str == nullptr)
		return false;

	bool flow = scanf1int(&str);
	if (*str == '.')
	{
		++str;
		flow = scanf1int(&str) || flow;
	}
	if (*str == 'e' || *str == 'E')
	{
		++str;
		flow = flow && scanf2int(&str);
	}
	//cout << "zhengque" << endl;
	return flow && *str == '\0';

}
bool scanf1int(const char** str)
{
	if (**str == '+' || **str == '-')
		++(*str);

	return scanf2int(str);
}
bool scanf2int(const char** str)
{
	const char* before = *str;
	while (*str != '\0' && **str <= '9'&& **str >= '0')
		++(*str);
	return *str > before;
}
void Test(const char* testName, const char* str, bool expected)
{
	if (testName != nullptr)
		printf("%s begins: ", testName);

	if (isNumeric(str) == expected)
		printf("Passed.\n");
	else
		printf("FAILED.\n");
}
void test1()
{
	const char* str = "1a3.14";
	Test("Test1", str, false);
}
int main()
{
	test1();
	system("pause");
	return 0;
}