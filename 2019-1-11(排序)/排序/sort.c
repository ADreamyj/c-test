#include"Sort.h"


void _InsertSort(int* a, int n)//插入排序
{
	for (int i = 0; i < n - 1; i++)
	{
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (a[end]> tmp)
			{
				a[end + 1] = a[end];//交换位置
				end--;
			}
			else
			{
				break;
			}	
			a[end + 1] = tmp;
		}
	}	
}
void ShellSort(int* a, int n)//希尔排序
{
	int gas = n;
	while (gas > 1)
	{
		gas = gas/ 3 + 1;
		for (int i = 0; i < n - gas; i++)
		{
			int end = i;
			int tmp = a[end + gas];
			while (end >= 0)
			{
				if (a[end] > tmp)
				{
					a[end + gas] = a[end];
					end = end - gas;
				}
				else
				{
					break;
				}
				a[end + gas] = tmp;
			}
		}
	}
	
}
void swap(int* a, int* b)//交换两个数的位置
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void SelectSort(int* a, int n)//交换排序
{
	int begin = 0;
	int end = n - 1;

	while (begin < end)
	{
		int min = begin;

		int max = end;
		for (int i = begin; i <= end; i++)
		{
			if (a[i] >= a[max])
			{
				max = i;
			}
			if (a[i] <= a[min])
			{
				min = i;
			}
		}
		swap(&a[min], &a[begin]);
		if (max == begin)
		{
			max = min;
		}
		swap(&a[max], &a[end]);
		end--;
		begin++;
	}
}


void AdjustSort(int* a, int n,int parent)//向下调整法
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n && a[child] < a[child + 1])
		{
			child++;
		}
		if (a[parent]< a[child])
		{
			swap(&a[parent], &a[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;
	}
}

void HeapSort(int* a, int n)//堆排
{
	//建堆
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustSort(a, n, i);
	}
	//取数
	int end = n - 1;

	while (end > 0)
	{
		swap(&a[end], &a[0]);
		AdjustSort(a, end, 0);
		end--;
	}
}

void BubbleSort(int* a, int n)//冒泡排序
{
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				swap(&a[j], &a[j + 1]);
			}
		}
	}
}
int MidSort(int* a, int begin, int end)//找出一组数中最中间的数
{
	int mid = begin + ((end - begin) >> 1);
	if (a[begin] < a[mid])
	{
		if (a[mid] < a[end])
		{
			return mid;
		}
		else if (a[begin] > a[end])
		{
			return begin;
		}
		else
			return end;
	}
	else
	{
		if (a[mid] > a[end])
		{
			return mid;
		}
		else if (a[end] > a[begin])
		{
			return begin;
		}
		else
			return end;
	}
}
int past1Sort(int* a, int begin, int end)//快1
{
	int mid = MidSort(a, begin, end);
	swap(&a[begin], &a[mid]);

	int key = a[begin];
	int tmp = begin;
	while (begin < end)
	{
		while (begin < end && a[end] >= key)
			end--;
		while (begin < end && a[begin] <= key)
			begin++;
		swap(&a[begin], &a[end]);
	}
	swap(&a[tmp], &a[end]);
	return end;
}
int past2Sort(int* a, int begin, int end)//快2
{
	int key = a[begin];
	while (begin < end)
	{
		while (begin < end && key <= a[end])
			end--;
			swap(&a[begin], &a[end]);
		while (begin < end && key >= a[begin])
			begin++;
			swap(&a[begin], &a[end]);
	}
	swap(&a[begin], &key);
	return key;
}
int past3Sort(int* a, int begin, int end)//快3
{
	int key = a[begin];
	int cur = begin + 1;
	int prev = begin;
	while (cur <= end)
	{
		if (key > a[cur] && prev++ != cur)
		{
			swap(&a[cur], &a[prev]);
		}
		cur++;
	}
	swap(&a[begin], &a[prev]);
	return prev;
}
void QuickSort1(int * a, int left , int right)
{
	if (left >= right)
		return;

	int div = past1Sort(a, left, right);
	//int div = past2Sort(a, left, right);
	//int div = past3Sort(a, left, right);
	QuickSort1(a, left, div - 1);
	QuickSort1(a, div + 1, right);
}
void _MergeSort(int* a, int begin, int end, int* tmp)
{
	if (begin >= end)
		return;
	int mid = begin + ((end - begin) >> 1);
	_MergeSort(a, begin, mid, tmp);
	_MergeSort(a, mid + 1, end, tmp);

	//合并
	int begin1 = begin; int end1 = mid;
	int begin2 = mid + 1; int end2 = end;
	int cur = 0;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
			tmp[cur++] = a[begin1++];
		else
			tmp[cur++] = a[begin2++];
	}
	while(begin1 <= end1)//左边剩余元素填入tmp中；
		tmp[cur++] = a[begin1++];
	while(begin2 <= end2)//右边剩余元素填入tmp中；
		tmp[cur++] = a[begin2++];
	for (int i = 0; i < cur; i++)
	{
		a[begin + i] = tmp[i];
	}
}
void MergeSort(int* a, int n)//归并排序
{
	int* tmp = (int*)malloc(sizeof(int)*n);
	_MergeSort(a, 0, n - 1, tmp);
	free(tmp);
}

void Sort(int* a, int n)//非比较排序
{
	//开辟空间，找最大数和最小数
	int max = a[0]; int min = a[0];
	for (int i = 0; i < n; i++)
	{
		if (a[i] > max)
			max = a[i];
		if (a[i] < min)
			min = a[i];
	}
	int change = max - min + 1;
	int* tmp = (int*)malloc(sizeof(int)*change);
	memset(tmp, 0, sizeof(int)*change);
	for (int j = 0; j < n; j++)
	{
		tmp[a[j] - min]++;
	}
	int index = 0;
	for (int k = 0; k < change; k++)
	{
		while (tmp[k]--)
		{
			a[index++] = k + min;
		}
	}
}
void QuickSort2(int* a, int left, int right)//非递归快排//好难
{
	Stack st;
	StackInit(&st);

	StackPush(&st, left);
	StackPush(&st, right);

	while (StackEmpty(&st) != 0)
	{
		int end = StackTop(&st);
		StackPop(&st);

		int begin = StackTop(&st);
		StackPop(&st);

		int div = past1Sort(a, begin, end);
		if (begin < div - 1)
		{
			StackPush(&st, begin);
			StackPush(&st, div - 1);
		}

		if (div + 1 < end)
		{
			StackPush(&st, div - 1);
			StackPush(&st, end);
		}

	}
}
void print(int* a, int n)//打印数据
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void test1()
{
	int a[] = { 7, 8, 9, 6, 5, 4, 3, 2, 1, 0 };
	int n = sizeof(a) / sizeof(int);
	//InsertSort(a, n);//插入排序
	//print(a, n);

	//ShellSort(a, n);//希尔排序
	//print(a, n);

	//SelectSort(a, n);//交换排序
	//print(a, n);

	//HeapSort(a, n);//堆排
	//print(a, n);

	//BubbleSort(a, n);//冒泡排序
	//print(a, n);

	//MergeSort(a, n);//归并排序
	//print(a, n);

	Sort(a, n);
	print(a, n);
}

void test2()
{
	int a[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
	int n = sizeof(a) / sizeof(int);
	QuickSort1(a, 0, n - 1);
	print(a, n);

	QuickSort2(a, 0, n - 1);
	print(a, n);
}

