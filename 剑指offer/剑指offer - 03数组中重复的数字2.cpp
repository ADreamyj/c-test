#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>
using namespace std;

//题目：在一个长度为n + 1的数组中，所有的数字都是在1 - n，的范围内，
//所以数字中至少有一个是重复的，请找出重复的数字，但不能修改 输入的
//数组，例如：如果输入长度为8的数组{2，3，5，4，3，2，6，7}，那么对
//应输出的重复数字就是2或者3

//方法1：二分查找法，但是不能保证找出所有的数字
//时间复杂度为O(n(logn))，空间复杂度为O(1);

//方法2：借助辅助空间的算法，可以找出所有的数字
//空间复杂度为O(n),时间复杂度O(n)

//用方法1的话就是用时间换空间
int countRange(const int* numbers, int length, int start, int end);
int getDuplication(const int* numbers, int length)
{
	if (numbers == nullptr || length <= 0)
		return -1;

	int start = 1;
	int end = length - 1;

	while (end >= start)
	{
		int middle = ((end - start) >> 1) + start;
		int count = countRange(numbers,length,start,middle);
		if (end == start)
		{
			if (count > 1)
				return start;
			else
				break;
		}
		if (count > (middle - start + 1))
			end = middle;
		else
			start = middle + 1;
	}
	return -1;
}

int countRange(const int* numbers, int length, int start, int end)
{
	if (numbers == nullptr)
		return 0;
	int count = 0;

	for (int i = 0; i < length; i++)
	{
		if (numbers[i] >= start && numbers[i] <= end)
			++count;
	}
	return count;
}

void test(const char* testName, int* numbers, int length, int* duplications, int dupLength)
{
	int result = getDuplication(numbers, length);
	for (int i = 0; i < dupLength; ++i)
	{
		if (result == duplications[i])
		{
			std::cout << testName << " passed." << std::endl;
			return;
		}
	}
	std::cout << testName << " FAILED." << std::endl;
}

// 多个重复的数字
void test1()
{
	int numbers[] = { 2, 3, 5, 4, 3, 2, 6, 7 };
	int duplications[] = { 2, 3 };
	test("test1", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int));
}

// 一个重复的数字
void test2()
{
	int numbers[] = { 3, 2, 1, 4, 4, 5, 6, 7 };
	int duplications[] = { 4 };
	test("test2", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int));
}
// 无效的输入
void test3()
{
	int* numbers = nullptr;
	int duplications[] = { -1 };
	test("test10", numbers, 0, duplications, sizeof(duplications) / sizeof(int));
}

//void main()
//{
//	test1();
//	test2();
//	test3();
//	system("pause");
//}
