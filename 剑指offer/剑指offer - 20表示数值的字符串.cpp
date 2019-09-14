#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>

//题目：表示数值的字符串
//请事先一个函数用来判断字符串中是否表示数值（包括整数和小数）
//例如：字符串"+100","5e2","-123","3.1416"及"-1E-16"都表示数值，
//但"12e","1a3.14","1.2.3","+-5"及"12e + 5.4"都不是

//解题思路：
//表示数值的字符串的表示规则如下：A.[.[B]][e/E C]或者.B[e/E C]
//其中A表示整数部分，B后面跟着小数部分，C后面跟着'e'或者'E'为数值
//的指数部分。

//小数里可以没有整数部分，整数里也可以没有小数部分
//他们两者也可以相互存在。

//整数前面可以带+-号
//指数后面也可以带+-号

//代码如下：
bool panduan1(const char** str);//有符号的位数，数值模式中的A和B
bool panduan2(const char** str);//小数后面的无符号整数B

bool isNumeric(const char* str)
{
	if (str == nullptr)
		return false;

	bool flag = panduan1(&str);

	if (*str == '.')
	{
		++str;
		//下面一行代码||的作用：
		//1.小数可以没有整数部分，如.123 = 0.123
		//2.小数点厚民可以没有数字，如233.==233.0
		//当然，小数点前面和后面都可以有数字。
		flag = flag || panduan2(&str);
	}

	if (*str == 'e' || *str == 'E')
	{
		++str;
		//下面一行代码&&的作用
		//1.当e和E前面没有数字的时候，整个字符串不能表示数字。
		//2.当e和E后面没有整数的时候，整个字符串不能表示数字。
		flag = flag && panduan1(&str);
	}
	return flag && *str == '\0';
}

bool panduan1(const char** str)//有符号的位数，数值模式中的A和B
{
	if (**str == '+' || **str == '-')
		++(*str);
	return panduan2(str);
}

bool panduan2(const char** str)//小数后面的无符号整数B
{
	const char* before = *str;
	while (**str != '\0' && **str >= '0' && **str <= '9')
		++(*str);

	return *str > before;
}

int main()
{
	const char* str = "12e";
	std::cout << isNumeric(str) << std::endl;
	system("pause");
	return 0;
}