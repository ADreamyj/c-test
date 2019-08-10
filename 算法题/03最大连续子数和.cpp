#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>
#include<vector>
//题目：最大连续子数和
//HR偶尔会拿些专业问题来忽悠那些非计算机专业的同学。
//今天测试组开完会后,他又发话了:在古老的一维模式识别中,
//常常需要计算连续子向量的大和,当向量全为正数的时候,问题很好解决。
//但是,如果向量中包含负数,是 否应该包含某个负数,并期望旁边的正数
//会弥补它呢？例如:{6,-3,-2,7,-15,1,2,2},连续子向量的大和为8
//(从第0 个开始,到第3个为止)。给一个数组，返回它的大连续子序列的和
//，你会不会被他忽悠住？(子向量的长度至少 是1)


//方法：动态规划
//状态：
//		子状态：长度为1，2，3。。。n的子数组和的最大值
//		F(i)：长度为i的子数组的最大值，这种定义不能形成递推关系，舍弃
//		F(i)：以array[i]为末尾元素的子数和的最大值。
//状态递归：
//		F(i) = max(F(i - 1) + array[i],array[i])
//		F(i) = ((F(i) > 0) ? F(i - 1) + array[i] : array[i])
//初始值： F(0) = array[0]
//返回结果：
//		maxsum：所有F(i)种的最大值
//		maxsum = max(maxsum,F(i))

int  FindGreatestSumOfSubArray(std::vector<int> array)
{
	if (array.empty())
		return 0;
	int sum = array[0];
	int max = array[0];

	for (int i = 1; i < array.size(); i++)
	{
		sum = (sum > 0) ? sum + array[i] : array[i];
		max = (max > sum) ? max : sum;
	}
	return max;
}

//int main()
//{
//	std::vector<int> v = { 6, -3, -2, 7, -15, 1, 2, 2 };
//	std::cout << FindGreatestSumOfSubArray(v) << std::endl;
//	system("pause");
//	return 0;
//}