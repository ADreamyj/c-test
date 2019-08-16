#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>
#include<vector>

//题目：路径总数
//在一个m*n的网格的左上角有一个机器人，机器人在任何情况下只能向左
//或者向右移动，机器人想要到达网格的右下角，有多少种路径。

//方法：动态规划
//状态：
//		子状态：从(0,0)到达(1,0)(1,1)(2,1)...(m - 1,n - 1)的路径数
//		F(i,j)：从(0,0)到达F(i,j)的路径数
//状态递归：
//		F(i,j) = F(i - 1,j) + F(i,j - 1)
//初始化：
//		特殊情况：第0行和第0列
//		F(0,i) = 1;
//		F(i,0) = 1;
//返回结果：
//		F(m - 1,n - 1)

int uniquePaths(int m, int n)
{
	if (m < 1 || n < 1)
		return 0;
	std::vector<std::vector<int>> v(m, std::vector<int>(n,1));
	int i;
	int j;
	for ( i = 1; i < m; i++)
	{
		for ( j = 1; j < n; j++)
		{
			v[i][j] = v[i - 1][j] + v[i][j - 1];
		}
	}
	return v[i - 1][j - 1];
}

//int main()
//{
//	std::cout << uniquePaths(3, 3);
//
//	system("pause");
//	return 0;
//}