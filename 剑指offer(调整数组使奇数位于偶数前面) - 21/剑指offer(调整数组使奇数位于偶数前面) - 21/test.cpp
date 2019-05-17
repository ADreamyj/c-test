#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>
using namespace std;

//输入一个整数数组，实现一个函数使所有的奇数在数组的前面，
//所有的偶数在数组的后面。

//第一种方法，如果是初学者的话，他会这样做，从前往后遍历，
//找到一个偶数，先将它保存起来，然后将后面所有的数向前面移动一位
//然后将保存的数放在最后一位，时间复杂度为O(n^2);

//第二种方法是，创建两个指针，分别指向数组的头和尾；
//从头找第一个偶数，如果是奇数则++；
//从后找第一个奇数，如果是偶数则--；
//当头指针和尾指针相等的时候，循环结束，
//此时的数组就是创建后的数组。时间复杂度尾O(n);


void ReorderOddEven1(int* str,  int length)
{
	if (str == nullptr || length <= 0)
		return;

	int* start = str;
	int* end = str + length - 1;
	while (start < end)
	{
		while (start < end && (*start & 0x1) == 1)
			++start;
		while (start < end && (*end & 0x1) == 0)
			--end;
		if (start < end)
		{
			int temp = *start;
			*start = *end;
			*end = temp;
		}
	}
}
//第三种解法，其实和第二种解法有相同点，将判断的标准用一个函数
//来实现，这样的话无论标准是什么都可以尽快的修改。

bool Judje(int* num)
{
	return *num & 0x1 == 0;
		 
}
void ReorderOddEven2(int str[], int length)
{
	if (str == nullptr || length <= 0)
		return;
	int* start = str;
	int* end = str + length - 1;
	while (start < end)
	{
		while (start < end && (!Judje(start)))
			++start;
		while (start < end && (Judje(start)))
			--end;
		if (start < end)
		{
			int temp = *start;
			*start = *end;
			*end = temp;
		}
	}
}
void PrintArray(int numbers[], int length)
{
	if (length < 0)
		return;

	for (int i = 0; i < length; ++i)
		printf("%d ", numbers[i]);

	printf("\n");
}
void Test(char* test1, int* str,int length)
{
	if (test1 != nullptr)
		cout << test1 << endl;

	PrintArray(str, length);
	ReorderOddEven1(str, length);
	
	PrintArray(str, length);
	ReorderOddEven2(str, length);

	PrintArray(str, length);

}
void test()
{
	int str[] = { 2, 4, 6, 8, 1, 3, 5, 7};
	int length = sizeof(str) / sizeof(str[0]);
	Test("test1", str,length);
}
int main()
{
	test();
	system("pause");
	return 0;
}