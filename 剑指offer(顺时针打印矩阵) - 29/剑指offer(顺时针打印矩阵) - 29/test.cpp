#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>
using namespace std;

//输出一个数组，顺时针打印数组的每个数
//void Print(int number);
//void PrintClockwise(int** numbers, int cols, int rows, int start);
//
//void Clockwise(int** numbers, int cols, int rows)
//{
//	if (numbers == nullptr || rows <= 0 || cols <= 0)
//		return;
//
//	int start = 0;
//
//	if (rows > start * 2 && cols > start * 2)
//	{
//		PrintClockwise(numbers, cols, rows, start);
//		++start;
//	}
//}
//void PrintClockwise(int** numbers, int cols, int rows, int start)
//{
//	int endx = cols - 1 - start;
//	int endy = rows - 1 - start;
//	//从左到右打印第一行
//	for (int i = start; i <= endx; ++i)
//	{
//		int number = numbers[start][i];
//		Print(number);
//	}
//	//从上到下打印第一列
//	if (start < endy)
//	{
//		for (int i = start + 1; i <= endy; ++i)
//		{
//			int number = numbers[i][endx];
//			Print(number);
//		}
//	}
//	//从右到左打印一行
//	if (start < endx && start < endy)
//	{
//		for (int i = endx - 1; i >= start; --i)
//		{
//			int number = numbers[endy][i];
//			Print(number);
//
//		}
//	}
//
//	if (start < endx && start < endy - 1)
//	{
//		for (int i = endy - 1; i >= start + 1; --i)
//		{
//			int number = numbers[i][start];
//			Print(number);
//		}
//	}
//}
//void Print(int number)
//{
//	printf("%d\t", number);
//}
void PrintMatrixInCircle(int** numbers, int columns, int rows, int start);
void printNumber(int number);

void PrintMatrixClockwisely(int** numbers, int columns, int rows)
{
	if (numbers == nullptr || columns <= 0 || rows <= 0)
		return;

	int start = 0;

	while (columns > start * 2 && rows > start * 2)
	{
		PrintMatrixInCircle(numbers, columns, rows, start);

		++start;
	}
}

void PrintMatrixInCircle(int** numbers, int columns, int rows, int start)
{
	int endX = columns - 1 - start;
	int endY = rows - 1 - start;

	// 从左到右打印一行
	for (int i = start; i <= endX; ++i)
	{
		int number = numbers[start][i];
		printNumber(number);
	}

	// 从上到下打印一列
	if (start < endY)
	{
		for (int i = start + 1; i <= endY; ++i)
		{
			int number = numbers[i][endX];
			printNumber(number);
		}
	}

	// 从右到左打印一行
	if (start < endX && start < endY)
	{
		for (int i = endX - 1; i >= start; --i)
		{
			int number = numbers[endY][i];
			printNumber(number);
		}
	}

	// 从下到上打印一行
	if (start < endX && start < endY - 1)
	{
		for (int i = endY - 1; i >= start + 1; --i)
		{
			int number = numbers[i][start];
			printNumber(number);
		}
	}
}

void printNumber(int number)
{
	printf("%d\t", number);
}
void Test(int columns, int rows)
{
	printf("Test Begin: %d columns, %d rows.\n", columns, rows);

	if (columns < 1 || rows < 1)
		return;

	int** numbers = new int*[rows];
	for (int i = 0; i < rows; ++i)
	{
		numbers[i] = new int[columns];
		for (int j = 0; j < columns; ++j)
		{
			numbers[i][j] = i * columns + j + 1;
		}
	}

	PrintMatrixClockwisely(numbers, columns, rows);
	printf("\n");

	for (int i = 0; i < rows; ++i)
		delete[](int*)numbers[i];

	delete[] numbers;
}
int main()
{
	Test(4, 3);
	system("pause");
	return 0;
}