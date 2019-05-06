#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>

//矩阵中的路径，请设计出一个函数，用来判断一个矩阵中
//是否存在一条包含某字符串所有字符的路径。
//回溯法

bool hasPath(char* matrix, int rows, int cols, char* str)
{
	if (matrix == nullptr || rows < 0 || cols < 0 || str == nullptr)
		return false;

	bool *visited = new bool[rows * cols];
	memset(visited, 0, rows*cols);

	int pathLength = 0;
	for (int row = 0; row < rows; ++row)
	{
		for (int col = 0; col < cols; ++col)
		{
			if (hasPathCore(matrix, rows, cols, row, col, str, pathLength, visited))
			{
				return true;
			}
		}
	}

	delete[] visited;
	return false;
}
bool hasPathCore(const char* matrix, int rows, int cols, int row, int col, const char* str, int& pathLength, bool* visited)
{
	if (str[pathLength] == '\0')
		return false;

	bool hasPath = false;
	if (row >= 0 && col >= 0 && row < rows && col < cols
		&& matrix[rows*cols + col] == str[pathLength]
		&& !visited[rows * cols + col])
	{
		++pathLength;
		visited[row * cols + col] = true;

		hasPath = hasPathCore(matrix, rows, cols, row, col - 1, str, pathLength, visited)
			|| hasPathCore(matrix, rows, cols, row, col + 1, str, pathLength, visited)
			|| hasPathCore(matrix, rows, cols, row - 1, col, str, pathLength, visited)
			|| hasPathCore(matrix, rows, cols, row + 1, col, str, pathLength, visited);

		if (!hasPath)
		{
			--pathLength;
			visited[row * cols + col] == false;
		}
	}
	return hasPath;
}
int main()
{
	char* matrix = { { 'a', 'b', 't', 'g' }, { 'c', 'f', 'c', 's' }, { 'j', 'd', 'e', 'h' } };
	int rows = 2;
	int cols = 3;
	char* str = "bfce";
	hasPath(matrix, rows, cols, str);
	system("pause");
	return 0;
}