#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>

//题目：在一个二维数组中，每一行都是按照从左到右递增的顺序排序；
//每一列都是按照从上到下递增的顺序排序。请完成一个函数，输入
//这样的一个二维数组和一个整数，判断数组中是否含有该整数。

//选取最右上角的数字，如果比目标数字大，那就删除这一列
//否则删除这一行，直到找到为止。
bool Find(int* matrix, int rows, int columns, int number)
{
	if (matrix != nullptr && rows > 0 && columns > 0)
	{
		int row = 0;
		int column = columns - 1;
		while (row < rows && column > 0)
		{
			if (matrix[row * columns + column] == number)
			{
				return true;
			}
			else if (matrix[row * columns + column] > number)
			{
				--column;
			}
			else
				++row;
		}
	}
	return false;
}
void test(char* testName, int* matrix, int rows, int columns, int number, bool expected)
{
	if (testName != nullptr)
		printf("%s begins: ", testName);
	bool result = Find(matrix, rows, columns, number);
	if (result == expected)
		printf("passed.\n");
	else
		printf("Failed.\n");
}
void test1()
{
	int matrix[][4] = { { 1, 2, 8, 9 }, { 2, 4, 9, 12 }, { 4, 7, 10, 13 }, { 6, 8, 11, 15 } };
	test("test1", (int*)matrix, 4, 4, 7, true);
}
int main()
{
	test1();
	system("pause");
	return 0;
}