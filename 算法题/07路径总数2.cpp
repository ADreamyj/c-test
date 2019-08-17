#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>
#include<vector>

//题目描述：
//		机器人从网格的最左上角走到最右下角，网格中设置了障碍物
//		障碍物用1来进行表示。

//方法：动态规划
//状态：
//		子状态：从(0,0)到达(1,0),(1,1)...(m - 1)(n - 1)的路径数
//		F(i,j)：从(0,0)到达F(i,j)的路径数
//状态递归：
//		F(i,j) = {F(i - 1,j) + F(i,j - 1)} or
//				{0,if obstacleGrid(i,j) = 1}
//初始化：
//		特殊情况：第0行和第0列
//		F(0,i) = {1} or {0, if obstacleGrid(0,j) = 1 , j <= i}
//		F(i,0) = {1} or {0, if obstaclegrid(j,0) = 1 , j <= i}
//返回结果：
//		F(m - 1,n - 1)

int uniquePathsWithObstacles(std::vector<std::vector<int> > &obstacleGrid)
{
	if (obstacleGrid.empty() || obstacleGrid[0].empty())
	{
		return 0;
	}
	// 申请F(i,j)空间，初始值为0
	int m = obstacleGrid.size();
	int n = obstacleGrid[0].size();
	std::vector<std::vector<int>> v(m, std::vector<int>(n, 0));

	for (int i = 0; i < m; i++)
	{// 第0列中只要前面有障碍，后面都无法到达
		if (obstacleGrid[i][0] != 1)
			v[i][0] = 1;
		else
			break;
	}

	for (int i = 0; i < n; i++)
	{// 第0行中只要前面有障碍，后面都无法到达
		if (obstacleGrid[0][i] != 1)
			v[0][i] = 1;
		else
			break;
	}

	for (int i = 1; i < m; i++)
	{
		for (int j = 1; j < n; j++)
		{// obstacleGrid[i][j] = 1 时，F(i,j)无法到达
			if (obstacleGrid[i][j] == 1)
				v[i][j] = 0;
			else
				//F(i,j) = F(i-1,j) + F(i,j-1)
				v[i][j] = v[i - 1][j] + v[i][j - 1];
		}
	}

	return v[m - 1][n - 1];
}

//int main()
//{
//	std::vector<std::vector<int>> v{ { 1, 0, 0 }, { 0, 1, 0 }, { 0, 0, 0 } };
//	std::cout << uniquePathsWithObstacles(v) << std::endl;
//	system("pause");
//	//return 0;
//}