#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>
using namespace std;
//旋转数组的最小数字
//把一个数组的最开始的若干个元素搬到数组的末尾，
//我们称之为数组的旋转，输入一个递增数组的一个旋转
//输出旋转数组的最小元素，
//例如：{3，4，5，1，2}和{1，2，3，4，5}最小元素是一

//对于这个题而言，可以用二分查找的思想更快的解决

int minsort(int* numbers, int start, int end);

int Min(int* numbers, int length)
{
	if (numbers == nullptr || length == 0)
		cout << "数组出错" << endl;

	int start = 0;
	int end = length - 1;
	int mindex = start;
	while (numbers[start] >= numbers[end])
	{
		if (end - start == 1)
		{
			mindex = end;
			break;
		}

		mindex = start + (end - start)/2;

		//当数组中start,end,和mindex 的值相等时，则需要重新排序
		if (numbers[start] == numbers[end] && numbers[start] == numbers[mindex])
			return minsort(numbers, start, end);


		if (numbers[mindex] >= numbers[start])
			start = mindex;
		else if (numbers[mindex] <= numbers[end])
			end = mindex;
	}
	return numbers[mindex];
}
int minsort(int* numbers, int start, int end)
{
	int result = numbers[start];
	for (int i = start +1; i <= end; i++)
	{
		if (numbers[i] < result)
			result = numbers[i];
	}
	return result;
}

void test1()
{
	int numbers[] = { 1, 1, 1, 0, 1 };
	int lenght = sizeof(numbers) / sizeof(numbers[0]);
	Min(numbers, lenght);
}
int main()
{
	test1();
	system("pause");
	return 0;
}