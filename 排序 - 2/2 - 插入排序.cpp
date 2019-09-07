#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>
#include<vector>

//特点：
//1.元素集合越接近有序，直接插入排序的时间效率越高
//2.时间复杂度O(N^2)
//3.空间复杂度：O(1),它是一种稳定的排序算法
//4.稳定性：稳定
 
//void Print(std::vector<int> v, int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		std::cout << v[i] << " ";
//	}
//	std::cout << std::endl;
//}
//int InsertionSort(std::vector<int> v, int n)//插入排序
//{
//	int i, j, value;
//	for (int i = 1; i < n; i++)
//	{
//		value = v[i];//i表示未为排序部分的下标进行索引
//		j = i - 1;//j表示已排好序的部分的下标进行索引
//		while (j >= 0 && value < v[j])//从右向左扫描有序的子数组
//			//直到遇到第一个小于等于value的元素。
//		{
//			v[j + 1] = v[j];
//			j--;
//		}
//		v[j + 1] = value;//将value插在这个元素的后面
//	}
//	Print(v, n);
//	return 0;
//}

//void InsertionSort(std::vector<int> v, int n)
//{
//	for (int i = 0; i < n - 1; ++i)
//	{
//		int end = i;
//		int temp = v[end + 1];
//		while (end >= 0)
//		{
//			if (v[end] > temp)
//			{
//				v[end + 1] = v[end];
//				end--;
//			}
//			else
//			{
//				break;
//			}
//			v[end + 1] = temp;
//		}
//	}
//}
//int main()
//{
//	std::vector<int> v = { 2, 8, 9, 5, 3, 6, 2, 1 };
//	int n = 8;
//	Print(v, n);
//	InsertionSort(v, n);
//	
//	system("pause");
//	return 0;
//}