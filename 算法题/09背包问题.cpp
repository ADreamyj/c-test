#define _CRT_SECURE_NO_WARNINGS  1


#include<iostream>
#include<vector>
#include<algorithm>

//题目：背包问题
//有n个物品和一个大小为m的背包，给定数组A来表示每个物品的大小和数组
//V来表示每个物品的价值，问最多能装入背包的价值是多少？

//方法：动态规划，将一个问题分解为好多的子问题

//状态：
//		F(i,j)：第i个物品放入大小为j的背包所获得的最大价值。
//状态递归：
//		对于第i个商品，有一种例外，装不下，两种选择放还是不放
//		如果装不下：此时的价值与前i - 1个的价值是一样的
//		F(i,j) = F(i - 1.j)
//		如果可以装下：需要在两种选择中找到最大的
//		F(i,j) = max{F(i - 1,j), F(i - 1,j - A[i]) + V[i]}
//		F(i - 1,j)：表示不把第i个物品放入背包中，所以它的价值就是
//			前i - 1个物品放入大小为j的背包的最大价值
//		F(i - 1,j - A[i]) + V[i]：表示把第i个物品放入背包中，价值增加
//			x[i]，但是需要腾出j - A[i]的大小放第i个商品
//初始化：
//		第0行和第0列都为0，表示没有装物品时的价值为0
//		F(0,j) = F(i.0) = 0
//返回值：F(n,m)

int BackPack1(int m, std::vector<int> A, std::vector<int> V)
{
	if (A.empty() || V.empty() || m < 0)
		return -1;

	//多加一行一列，用于设置初始条件
	const int M = m + 1;
	const int N = A.size() + 1;
	//初始化所有位置为0，第一行和第一列都为0，初始条件
	std::vector<std::vector<int>> v(N, std::vector<int>(M, 0));

	for (int i = 1; i < N; ++i)
	{
		for (int j = 1; j < M; ++j)
		{
			//第i个商品在A中对应的索引为i-1: i从1开始
			//如果第i个商品大于j,说明放不下， 所以(i,j)的最大价值和(i-1,j)相同
			if (A[i - 1] > j)
			{
				v[i][j] = v[i - 1][j];
			}
			//如果可以装下，分两种情况，装或者不装
			//如果不装，则即为(i-1, j)
			//如果装，需要腾出放第i个物品大小的空间：
			//j - A[i-1],装入之后的最大价值即为(i - 1, 
			//j - A[i - 1]) + 第i个商品的价值V[i - 1]
			//最后在装与不装中选出最大的价值
			else
			{
				int newvalue = v[i - 1][j - A[i - 1]] + V[i - 1];
				v[i][j] = std::max(newvalue, v[i - 1][j]);
			}
		}
	}
	return v[N - 1][m];
}


//方法2：优化算法：
//		上面的算法在计算第i行的元素时，只用到第i - 1行的元素，
//		所以二维空间可以优化为一维空间
//		但是，如果是一维向量，需要从后面向前面计算，因为后面的
//		元素更新要依靠前面的元素未更新（模拟二维矩阵的上一行的值）

int BackPack2(int m, std::vector<int> A, std::vector<int> V)
{
	if (A.empty() || V.empty() || m < 1)
		return 0;

	const int N = A.size();
	const int M = m + 1;
	std::vector<int> v(M, 0);
	//这里商品的索引位置不需要偏移，要和未优化的方法区分开
	//这里的i-1理解为上一行，或者未更新的一维数组值
	for (int i = 0; i != N; ++i) 
	{
		for (int j = M - 1; j > 0; --j) 
		{
			//如果第i个商品大于j,说明放不下， 所以(i,j)的最大价值和(i-1,j)相同
			if (A[i] > j) 
			{
				v[j] = v[j];
			}
			//如果可以装下，分两种情况，装或者不装
			//如果不装，则即为(i-1, j)
			//如果装，需要腾出放第i个物品大小的空间：
			//j - A[i],装入之后的最大价值即为(i - 1, j 
			//-A[i - 1]) + 第i个商品的价值V[i]
				//最后在装与不装中选出最大的价值
			else
			{
				int newValue = v[j - A[i]] + V[i];
				v[j] = std::max(newValue, v[j]);
			}
		}
	}
	//返回装入前N个商品，物品大小为m的最大价值
	return v[m];
}
//int main()
//{
//	int m = 12;
//	std::vector<int> A = { 4, 1, 13, 8, 2 };
//	std::vector<int> V = { 20, 100, 1000, 1, 500 };
//	std::cout << BackPack1(m, A, V) << std::endl;
//	std::cout << BackPack2(m, A, V) << std::endl;
//	system("pause");
//	return 0;
//}


