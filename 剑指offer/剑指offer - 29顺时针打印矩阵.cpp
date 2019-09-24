#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>
#include<vector>
//题目：输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。
//例如，输入下面矩阵
//1		2	3	4
//5		6	7	8
//9		10	11	12
//13	14	15	16

//解题思路：这个题可能看起来非常的简单，但是要判定很多的边界条件。
//	 - - - -
//	|		|
//	|		|
//	  - - - |

//如图所式，我们可以看出每一圈左上角的数字行和列都是相同的数字。
//于是，可以得出左上角为我们分析的目标。

//对于一个5*5的矩阵来说，最后一圈只有一个数字，对应的坐标为（2，2）
//我们发现5 > 2*2依然成立。对于其他的矩阵也是如此。
//于是，我们可以得出循环继续的条件是columns > startX*2
//并且rows > startY*2。

void PrintCircle(int** numbers, int columns, int rows, int start);
void Print(int** numbers, int columns, int rows)
{
	if (numbers == 0 || columns < 0 || rows < 0)
		return;

	int start = 0;
	while (columns > start * 2 && rows > start * 2)
	{
		PrintCircle(numbers, columns, rows, start);
		++start;
	}
}

void PrintCircle(int** numbers, int columns, int rows, int start)
{
	int x = columns - 1 - start;
	int y = rows - 1 - start;

	for (int i = start; i <= x; ++i) //从左到右打印一行
	{
		int number = numbers[start][i];
		std::cout << number << " ";
	}

	if (start < y)//从上到下打印一行
	{
		for (int i = start + 1; i <= y; i++)
		{
			int number = numbers[i][x];
			std::cout << number << " ";
		}
	}

	if (start < x && start < y)//从右到左打印一行
	{
		for (int i = x - 1; i >= start; --i)
		{
			int number = numbers[y][i];
			std::cout << number << " ";
		}
	}

	if (start < x && start < y - 1)//从下到上打印一行
	{
		for (int i = y - 1; i >= start+1; --i)
		{
			int number = numbers[i][start];
			std::cout << number << " ";
		}
	}
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

	Print(numbers, columns, rows);
	printf("\n");

	for (int i = 0; i < rows; ++i)
		delete[](int*)numbers[i];

	delete[] numbers;
}
//int main()
//{
//	Test(4, 4);
//	system("pause");
//}
