#define _CRT_SECURE_NO_WARNINGS  1
#include<iostream>
using namespace std;

//快排
void swap(int* begin, int* end)
{
	int tmp = *begin;
	*begin = *end;
	*end = tmp;
}
int passSort(int arr[], int  start, int end)
{
	int cur = start + 1;
	int prev = start;
	while (cur <= end)
	{
		if (arr[start] > arr[cur])
		{
			++prev;
			swap(&arr[prev], &arr[cur]);
		}
		cur++;
	}
	swap(&arr[prev], &arr[start]);
	return prev;
}
void QuickSort(int arr[], int start, int end)
{
	if (start >= end)
		return;

	int index = passSort(arr, start, end);
		QuickSort(arr, start, index - 1);
		QuickSort(arr, index + 1, end);
}
void print(int* a, int n)//打印数据
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
//实现一个算法，将某公司所有员工的年龄进行排序
void SortAges(int ages[], int length)
{
	if (ages == nullptr || length < 0)
		return;
	const int num = 99;
	int arr[num + 1];

	//将数组的所有元素初始化为0
	for (int i = 0; i <= num; i++)
	{
		arr[i] = 0;
	}

	for (int i = 0; i < length; i++)
	{
		int age = ages[i];
		++arr[age];
	}

	int index = 0;
	for (int i = 0; i <= num; i++)
	{
		for (int j = 0; j < arr[i]; j++)
		{
			ages[index] = i;
			++index;
		}
	}

}
int main()
{
	/*int arr[] = { 8, 5, 9, 3, 4, 7, 1, 5, 9, 6 };
	int n = sizeof(arr) / sizeof(arr[0]);
	QuickSort(arr, 0, n-1);
	print(arr, n);*/
	int arr[] = { 8, 5, 26, 45, 82, 35, 71, 24, 52, 58 };
	int n = sizeof(arr) / sizeof(arr[0]);
	SortAges(arr, n);
	print(arr, n);
	system("pause");
	return 0;
}