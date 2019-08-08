#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>
using namespace std;
//DP定义：
//动态规划是分治思想的延伸，通俗一点来说就是大事化小，小事化无的艺术

//在将大问题化解为小问题的分治过程中，保存对这些小问题已经处理好的结果
//，并供后面处理更大规模的问题时直接使用这些结果。

//动态规划具备了以下三个特点
//1. 把原来的问题分解成了几个相似的子问题。
//2. 所有的子问题都只需要解决一次。
//3. 储存子问题的解。

//动态规划的本质，是对问题状态的定义和状态转移方程的定义
//(状态以及状态之间的递推关系)
//动态规划问题一般从以下四个角度考虑：
//1. 状态定义
//2. 状态间的转移方程定义
//3. 状态的初始化
//4. 返回结果

//状态定义的要求：定义的状态一定要形成递推关系。
//一句话概括：三特点四要素两本质
//适用场景：最大值 / 最小值, 可不可行, 是不是，方案个数


//题目：输入一个整数n，求出fibonacci的第n项

//方法1：递归

//递归方法的时间复杂度为O(2^n),随着n的增长，效率低下
//当输入的数比较大时，可能会导致栈溢出

int fibonacci1(int n)
{
	if (n <= 0)
		return 0;
	if (n == 1 || n == 2)
		return 1;
	return fibonacci1(n - 1) + fibonacci1(n - 2);
}



//方法二：动态规划
//申请一个数组，大小为n + 1，需要留下一个初始化的值。

//状态：F(n)
//状态递推：F(n) = F(n - 1) + F(n - 2)
//初始值：F(1) = F(2) = 1
//返回结果：F(N)

//时间复杂度为O(n)
int fibonacci2(int n)
{
	if (n <= 0)
		return  0;
	if (n == 1 || n == 2)
		return 1;

	int* v = new int[n + 1];
	v[0] = 0;
	v[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		v[i] = v[i - 1] + v[i - 2];
	}

	return v[n];
	delete[] v;
}

//方法3：
//上述解法的空间复杂度为O(n)
//其实F(n)只与它相邻的前两项有关，所以没有必要保存所有子问题的解
//只需要保存两个子问题的解就可以
//下面方法的空间复杂度将为O(1)

int fibonacci3(int n)
{
	if (n < 0)
		return 0;
	if (n == 1 || n == 2)
		return 1;
	int f1 = 1;
	int f2 = 1;
	int result = 0;
	for (int i = 3; i <= n; i++)
	{
		result = f1 + f2;
		f1 = f2;
		f2 = result;
	}
	return result;
}

//int main()
//{
//	int n = 10;
//	for (int i = 1; i <= n; i++)
//	{
//		cout << fibonacci1(i) << " ";
//	}
//	cout << endl;
//
//	for (int i = 1; i <= n; i++)
//	{
//		cout << fibonacci2(i) << " ";
//	}
//	cout << endl;
//
//	for (int i = 1; i <= n; i++)
//	{
//		cout << fibonacci2(i) << " ";
//	}
//	cout << endl;
//	system("pause");
//}