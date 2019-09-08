#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>
#include<vector>
//打印从1到最大的n位数
//题目：输入数字n，按顺序打印出从1到最大的n位十进制数，
//比如输出3，则打印出1，2，3一直到最大的三位数999。

//方法1：最普通的写法，并没有考虑到大数情况
void Print1(int n)
{
	int num = 1;
	for (int i = 0; i < n; ++i)
	{
		num *= 10;
	}
	for (int i = 1; i < num; ++i)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;
}

//方法2，用字符串来存储数字可以解决这一问题
bool panduan(char* v);
void Print(char* v);

void Print2(int n)
{
	if (n <= 0)
		return;

	char* v = new char[n + 1];
	memset(v, '0', n);
	v[n] = '\0';

	while (!panduan(v))
	{
		Print(v);
	}
	delete[]v;
}
bool panduan(char* v)
{
	bool flag = false;
	int take = 0;        //表示进位
	int size = strlen(v);      //表示数字个数
	for (int i = size - 1; i >= 0; --i)
	{
		int num = v[i] - '0' + take;
		if (i == size - 1)
			num++;

		if (num >= 10)//进位
		{
			if (i == 0)//表示第一个数产生了进位，循环结束
				flag = true;
			else
			{
				num -= 10;
				take = 1;
				v[i] = '0' + num;
			}
		}
		else//不进位
		{
			v[i] = '0' + num;
			break;
		}
	}
	return flag;
}
void Print(char* v)
{
	int flag2 = true;
	int size2 = strlen(v);

	for (int i = 0; i < size2; ++i)
	{
		if (flag2 && v[i] != '0')
			flag2 = false;

		if (!flag2)
		{
			std::cout << v[i];
		}
	}
	std::cout << " ";

}
int main()
{
	Print1(2);
	Print2(2);
	system("pause");
	return 0;