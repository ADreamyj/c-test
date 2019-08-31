#define _CRT_SECURE_NO_WARNINGS  1


#include<iostream>
#include<vector>
//题目：旋转数组中最小的数字

//把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转，
//输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素，
//例如：数组{3，4，5，1，2}为{1，2，3，4，5}的一个旋转，该数组的最小
//值为1

//解题思路：对于这个题来说，如果用按顺序查找的话，时间复杂度是O(n);

//所以可以使用二分查找的方法：定义三个指针，一个指向begin，
//一个指向end；一个指向mid；然后就按照这样的顺序往下找

//特殊情况：begin == end && begin == mid
//如果遇到这样的情况来说，就必须使用按顺序查找的方法

int Minsort(std::vector<int> v, int begin, int end)
{
	int result = v[begin];
	for (int i = begin + 1; i <= end; ++i)
	{
		if (result < v[i])
			result = v[i];
	}
	return result;
}
int Min(std::vector<int> v, int length)
{
	if (v.empty()|| length <= 0)
		return -1;

	int begin = 0;
	int end = length - 1;
	int mid = begin;
	while (v[begin] >= v[end])
	{
		if (end - begin == 1)
		{
			mid = end;
			break;
		}
		mid = (end + begin )/ 2;

		if (v[begin] == v[end] && v[begin] == v[mid])
			return Minsort(v, begin, end);

		if (v[begin] <= v[mid])
			begin = mid;
		else if (v[mid] <= v[end])
			end = mid;
		
	}
	return v[mid];
}

//int main()
//{
//	std::vector<int> v = { 1, 2, 1, 2, 3 };
//	int length = 5;
//	std::cout << Min(v, length) << std::endl;
//	system("pause");
//	return 0;
//}