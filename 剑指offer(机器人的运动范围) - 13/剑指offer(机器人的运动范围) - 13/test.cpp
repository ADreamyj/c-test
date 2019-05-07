#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>
using namespace std;
//地上有一个m行n列的方格，一个机器人从坐标（0，0）的格子开始移动，
//它每次可以向左，右，前，后各移动一格，但不能进入行坐标和列坐标
//数位之和大于18的格子，
//例如：（35，37）3 + 5 + 3 + 7 = 18，它可以进入，
//但是：（35，38）3 + 5 + 3 + 8 = 19，它不可以进入

int movingCountCore(int should, int rows, int cols, int row, int col, bool* visited);
int digSum(int n);
int movingCount(int should, int rows, int cols)
{
	if (should < 0 || rows <= 0 || cols <= 0)
		return 0;

	bool *visited = new bool[rows * cols];

	for (int i = 0; i < rows*cols; ++i)
		visited[i] = false;

	int count = movingCountCore(should, rows, cols, 0, 0, visited);

	delete[] visited;
	return count;
}

int movingCountCore(int should, int rows, int cols, int row, int col, bool* visited)
{
	int count = 0;
	if (row >= 0 && row < rows && col >= 0 && col < cols
		&&digSum(row) + digSum(col) <= should
		&& !visited[row * cols + col])
	{
		visited[row * cols + col] = true;

		count = 1 + movingCountCore(should, rows, cols, row, col + 1, visited)
			+ movingCountCore(should, rows, cols, row + 1, col, visited)
			+ movingCountCore(should, rows, cols, row - 1, col, visited)
			+ movingCountCore(should, rows, cols, row, col - 1, visited);

	}
	return count;
}
int digSum(int n)
{
	int sum = 0;
	while (n)
	{
		sum += sum % 10;
		n = n / 10;
	}
	return sum;
}

void test(char* testname, int should, int rows, int cols, int expected)
{
	if (testname != nullptr)
		cout << "begins" << testname << endl;

	if (movingCount(should, rows, cols) == expected)
		cout << "passed" << endl;
	else
		cout << "failed" << endl;
}

void test1()
{
	test("Test1", 15, 10, 1, 10);
}

int main()
{
	test1();
	system("pause");
	return 0;
}