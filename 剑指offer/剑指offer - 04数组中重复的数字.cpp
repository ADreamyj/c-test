#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>
#include<vector>

//题目：在一个二维数组中，每一行都按照从左到右的顺序排序，
//每一列都按照从上到下递增的顺序排序，请完成一个函数，输入这样
//的一个二维数组和一个整数，判断数组中是否含有该整数。

//解题方法：对于这个关于数组的问题来说：通常会分为3种情况来进行查找
//1.当数组中要选取的数字与要查找的数字相同时，就结束查找过程
//2.如果选取的数字小于要查找的数字的时候，哪个数字就在选取数字的
//	右边或者是下边
//3.如果选取的数字大于要查找的数字的时候，那么要查找的数字就应该
//	在当前选取数字的上边或者是左边

//基准是选取右上角的数字，

//1.如果该数字是查找的数字，则查找过程结束
//2.如果该数字大于要查找的数字，则剔除这个数字所在的列
//3.如果该数字小于要查找的数字，则剔除这个数字所在的行
int Find(std::vector<std::vector<int>> v, int rows, int columns, int number)
{
	bool found = false;
	if (!v.empty() && rows > 0 && columns > 0)
	{
		int row = 0;
		int column = columns - 1;
		while (row < rows && column >= 0)
		{
			if (v[row][column] == number)
			{
				found = true;
				break;
			}
			else if (v[row][column] > number)
				--column;
			else
				++row;
		}
		return found;
	}
}
//int main()
//{
//	std::vector<std::vector<int>> v = { { 1, 2, 8, 9 }, { 2, 4, 9, 12 },
//	{ 4, 7, 10, 13 }, { 6, 8, 11, 15 } };
//	int rows = 4;
//	int columns = 4;
//	int number = 10;
//	std::cout << Find(v, rows, columns, number) << std::endl;
//	system("pause");
//	return 0;
//}




