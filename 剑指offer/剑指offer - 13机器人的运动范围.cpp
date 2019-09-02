#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>
#include<vector>

//题目：地上有一个m行n列的方格，一个机器人从坐标（0，0）的位置开始移动
//它每次可以向左，右，上，下移动一格，但不能进入行坐标和列坐标的数位
//之和大于k的格子。例如：当k为18的时候，机器人能够进入方格（35，37），
//因为3 + 5 + 3 + 7 = 18,但是它不能进入方格（35，38），因为
//3 + 5 + 3 + 9 = 19；请问该机器人可以到达多少个格子？


int getnum(int n)
{
	int sum = 0;
	while (n > 0)
	{
		sum += n % 10;
		n /= 10;
	}
	return sum;
}
bool check(int num, int rows, int cols, int row, int col, bool * v)
{
	if (row >= 0 && row < rows && col >= 0 && col < cols
		&& getnum(row) + getnum(col) <= num
		&& !v[row * cols + col])
		return true;
	
	return false;
}

int movingCountCore(int num, int rows, int cols, int row,
	int col, bool*  v)
{
	int count = 0;
	if (check(num, rows, cols, row, col, v))
	{
		v[row * cols + col] = true;
		count = 1 + movingCountCore(num, rows, cols, row + 1, col, v)
			+ movingCountCore(num, rows, cols, row, col + 1, v)
			+ movingCountCore(num, rows, cols, row - 1, col, v)
			+ movingCountCore(num, rows, cols, row, col - 1, v);
	}
	return count;
}
int movingCount(int num, int rows, int cols)
{
	if (num < 0 || rows < 1 || cols < 1)
		return false;

	bool*  v = new bool [rows * cols];
	for (int i = 0; i < rows * cols; ++i)
	{
		v[i] = false;
	}

	int count = movingCountCore(num, rows, cols, 0, 0, v);

	std::cout << count << std::endl;

	delete[]v;
	return count;
}

int main()
{
	int num = 5;
	int rows = 10;
	int cols = 10;
	movingCount(num, rows, cols);
	system("pause");
	return 0;
}
