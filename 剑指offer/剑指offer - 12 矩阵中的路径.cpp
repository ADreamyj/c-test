#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>
#include<vector>

//算是中上难度的题目。
//请设计一个函数，判断一个矩阵中是否存在一条包含某字符串所有字符的路径
//路径可以从字符串的任意一格开始，每一步可以在矩阵中向左，上，下，右
//任意移动一格，如果一条路经经过矩阵中的某一个，那么就不能重复进入。

//a	  b	  t	  g	
//c	  f	  c	  s
//j	  d	  e	  h

//首先在矩阵中任意选取一个格子作为起点。假设矩阵中某个格子的字符为ch，
//并且这个格子对应于路径上的第i个字符。如果路径上的第i个字符不是ch，
//那么这个格子不可能处在路径的第i个位置上。如果路径的第i个字符恰好是ch，
//那么到相邻的格子上寻找第i+1个字符。重复这个过程直到路径上的所有字符
//都在矩阵中找到相应的位置。
//由于回溯法的递归特性，路径可以被看做一个栈。



bool hasPathCore(std::vector<std::vector<char>> v1, int dex, int row,
	int col, std::vector<char> v2, std::vector<std::vector<bool>> v)
{
	if (dex == v2.size())
		return true;

	int rows = v1.size(), cols = v1[0].size();

	if (row < 0 || col < 0 || row >= rows || col >= cols
		|| v[row][col] || v1[row][col] != v2[dex])
		return false;

	v[row][col] = true;
	bool flag = hasPathCore(v1, dex + 1, row, col - 1, v2, v)
		|| hasPathCore(v1, dex + 1, row + 1, col, v2, v)
		|| hasPathCore(v1, dex + 1, row, col + 1, v2, v)
		|| hasPathCore(v1, dex + 1, row - 1, col, v2, v);

	v[row][col] = false;
	return flag;
}
bool hasPath(std::vector<std::vector<char>> v1, int rows, int cols, std::vector<char> v2)
{
	if (v1.empty() || rows < 1 || cols < 1 || v2.empty())
	{
		return false;
	}

	std::vector<std::vector<bool>> v(rows, std::vector<bool>(cols,0));

	int pathlength = 0;
	for (int row = 0; row < rows; ++row)
	{
		for (int col = 0; col < cols; ++col)
		{
			if (hasPathCore(v1, 0, row, col, v2,  v))
				return true;
		}
	}
	return false;
}
int main()
{
	std::vector<std::vector<char>> v1 = { { 'a','b','t','g'}, 
	{'c','f','c','s'}, {'j','d','e','h'} };
	int rows = v1.size(), cols = v1[0].size();
	std::vector<char> v2 = {'b', 'f', 'c', 'e' };
	std::cout << hasPath(v1, rows, cols, v2) << std::endl;
	system("pause");
	return 0;
}