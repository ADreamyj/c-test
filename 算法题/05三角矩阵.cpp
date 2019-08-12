#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>
#include<vector>
#include<algorithm>


//题目：三角矩阵
//给定一个三角矩阵，找出自顶向下的短路径和，每一步可以移动到
//下一行的相邻数字。  比如给定下面一个三角矩阵，自顶向下的短路径
//和为11

//[ 
//		 [2], 
//		[3,4],
//	   [6,5,7], 
//	  [4,1,8,3] 
//]

//方法1：动态规划
//状态：
//		子状态：从(0,0)到(0,1)(1,1)(2,0),...(n,n)的最短路径和
//		F(i,j):从(0,0)到(i,j)的最短路径和
//状态递归：
//		F(i,j) = min(F(i - 1,j - 1),F(i - 1,j)) + triangle[i][j]
//初始值：
//		F(0,0) = triangle[0][0]
//返回结果：
//		min(F(n - 1),i)

int minimumTotal1(std::vector<std::vector<int>> &triangle)
{
	if (triangle.empty())
		return 0;
	std::vector<std::vector<int>> v(triangle);
	int len = v.size();

	for (int i = 1; i < len; ++i)
	{
		for (int j = 0; j <= i; ++j)
		{
			if (j == 0)
			{
				v[i][j] = v[i - 1][j];
			}
			else if (j == i)
			{
				v[i][j] = v[i - 1][j - 1];
			}
			else
			{
				v[i][j] = std::min(v[i - 1][j], v[i - 1][j - 1]);
			}
			v[i][j] = v[i][j] + triangle[i][j];
		}
	}

	int result = v[len - 1][0];
	for (int i = 1; i < len; ++i)
	{
		result = std::min(v[len - 1][i], result);
	}
	return result;
}

//方法2：动态规划(反向思维)
//状态：
//自状态：从(n.n),(n,n - 1),...,(1,0),(1,1)(0,0)到最后一行的最短路径和
//		F(i,j):从(i,j)到最后一行的最短路径和
//状态递归：
//		F(i,j) = min(F(i + 1,j) , F(i + 1),(j + 1)) + triangle[i][j];
//初始值：
//		F(n - 1,0) = triangle[n - 1][0],
//		F(n - 1,1) = triangle[n - 1][1],
//		F(n - 1,n - 1) = triangle[n - 1][n - 1];
//返回结果：
//		F(0,0);

//这种逆向思维不需要考虑边界，也不需要最后寻找最小值，直接返回F(0,0)即可

int  minimumTotal2(std::vector<std::vector<int>> &triangle)
{
	if (triangle.empty())
		return 0;
	std::vector<std::vector<int>> v(triangle);
	
	int len = v.size();

	for (int i = len - 2; i >= 0; i--)
	{
		for (int j = 0; j <= i; j++)
		{
			v[i][j] = std::min(v[i + 1][j], v[i + 1][j + 1]) + triangle[i][j];
		}
	}
	return v[0][0];
}
//int main()
//{
//	std::vector<std::vector<int>> triangle = { { 2 }, { 3, 4 },
//	{ 6, 5, 7 }, { 4, 1, 8, 3 } };
//
//	std::cout << minimumTotal1(triangle);
//	std::cout << minimumTotal2(triangle);
//
//	system("pause");
//	return 0;
//}