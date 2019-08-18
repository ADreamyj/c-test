#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>
#include<vector>
#include<algorithm>
//题目：给定一个m*n的网格，网格用非负数填充，找到一条从左上角到右下角
//的最短路径，每次只能向上或者是向下运动

//方法：动态规划
//状态：
//		子状态：从(0,0)到达(1,0),(1,1)....(m - 1,n - 1)的最短路径
//		F(i,j)：从(0,0)到达F(i,j)的最短路径
//状态递归：
//		F(i,j) = min{F(i - 1 , j) , F(i,j - 1)} + (i,j);
//初始化：
//		F(0,0) = (0,0)
//		特殊情况：第0行和第0列
//		F(0,i) = F(0,i - 1) + (0,i)
//		F(i,0) = F(i - 1,0) + (i,0)
//返回结果：
//		F(m - 1,n - 1)

int minPathSum(std::vector<std::vector<int>> &grid)
{
	if (grid.empty() || grid[0].empty())
		return 0;
	
	int m = grid.size();
	int n = grid[0].size();
	std::vector<std::vector<int>> v(m, std::vector<int>(n, 0));

	//F(0,0) F(i,0) 和 F(0,i)进行初始化
	v[0][0] = grid[0][0];
	for (int i = 1; i < m; i++)
	{
		v[i][0] = grid[i][0] + v[i - 1][0];
	}

	for (int j = 1; j < n; j++)
	{
		v[0][j] = grid[0][j] + v[0][j - 1];
	}
	
	// F(i,j) = min{F(i-1,j) , F(i,j-1)} + (i,j)
	for (int i = 1; i < m; ++i)
	{
		for (int j = 1; j < n; ++j)
		{
			v[i][j] = std::min(v[i - 1][j], v[i][j - 1]) + grid[i][j];
		}
	}

	return v[m - 1][n - 1];
}
//int main()
//{
//	std::vector<std::vector<int>> v{ { 1, 1, 1 }, { 2, 2, 2 }, { 1, 1, 1 } };
//	std::cout << minPathSum(v) << std::endl;
//	system("pause");
//	return 0;
//}