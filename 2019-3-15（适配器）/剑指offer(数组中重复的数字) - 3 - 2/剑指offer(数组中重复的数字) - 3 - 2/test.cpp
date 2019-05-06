#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>
using namespace std;
//题目二：不修改数组找到重复的数字
//在一个长度为n+1的数组里所有的数字都是1~n的范围内，所以数组中
//至少有一个数字是重复的，请找出数组中任意一个重复的数字，但不能
//修改输入的数组。
//例如：如果输入长度为8的数组{2，3，5，4，3，2，6，7}，那么
//对应的输出是重复数组2或者3

int pcount(const int* numbers, int length, int start, int end);

int Duplication(const int* numbers, int length)
{
	if (numbers == nullptr || length <= 0)
	{
		return -1;
	}
	int start = 1;
	int end = length - 1;
	while (start <= end)
	{
		int middle = ((end - start) >> 1 )+ start;
		int count = pcount(numbers, length, start, middle);

		if (start == end)
		{
			if (count > 1)
				return start;
			else
				break;
		}
		if (count > (middle - start + 1))
		{
			end = middle;
		}
		else
			start = middle + 1;
	}
	return -1;
}

int pcount(const int* numbers, int length, int start, int end)
{
	if (numbers == nullptr)
		return 0;

	int count = 0;
	for (int i = 0; i < length; i++)
	{
		if (numbers[i] >= start && numbers[i] <= end)
			count++;
	}
	return count;
}
void test(const char* testName, int* numbers, int length, int* duplications, int dupLength)
{
	int result = Duplication(numbers, length);
	for (int i = 0; i < dupLength; ++i)
	{
		if (result == duplications[i])
		{
			std::cout << testName << " passed." << std::endl;
			//return;
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

int main()
{
	test1();
	system("pause");
	return 0;
}