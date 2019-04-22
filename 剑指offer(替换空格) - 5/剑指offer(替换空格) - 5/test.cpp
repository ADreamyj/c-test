#define _CRT_SECURE_NO_WARNINGS  1
#include<iostream>
using std::cout;
using std::endl;

//题目：请实现一个函数，把字符串中的每个空格替换成“%20”。
//例如，输入“we are happy”,则输出“we%20are%20happy”。


//对于这个题而言，有很多种解决的方法，但是考虑到时间复杂度的话
//我们可以定义两个指针，先计算原来长度+空格的长度*2
//然后从那个点开始将' '转化为'%20';
//再将不是空格的数原封不动的放到后面。

void test(char string[], int lenght)
{
	if (string == nullptr || lenght <= 0)
		return ;
	int firstlenght = 0;
	int endlenght = 0;
	for (int i = 0; i < lenght; i++)
	{
		++firstlenght;
		if (string[i] == ' ')
			++endlenght;
	}
	endlenght = firstlenght + 2 * endlenght;
	while (firstlenght >= 0 && endlenght > firstlenght)
	{
		if (string[firstlenght] == ' ')
		{
			string[endlenght--] = '0';
			string[endlenght--] = '2';
			string[endlenght--] = '%';
		}
		else
		{
			string[endlenght--] = string[firstlenght];
		}
		--firstlenght;
	}
	for (int i = 0; i < 50; i++)
	{
		cout << string[i] << " ";
	}
}
int main()
{
	char string[] = "  we are  happy  ";
	test(string, 50);
	system("pause");
	return 0;
}