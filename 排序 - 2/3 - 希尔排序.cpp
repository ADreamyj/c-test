#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>
#include<vector>

//希尔排序(缩小增量排序)
//先选定一个整数，把待排序文件中所有记录分成个组，所有距离为gap的记录
//分在同一组内，并对每一组的记录进行排序。然后取重复上述分组和排序
//的工作。当到达gap = 1时，所有记录在统一组内排好序。

//希尔排序的特性总结：
//1.希尔排序是对直接插入排序的优化。
//2.当gap > 1的时候，都是预排序，目的是为了让数组更接近于有序，
//	当gap == 1的时候，数组已经接近于有序了，这样就会很快。
//	对于整体而言，可以达到优化的效果
//3.希尔排序的时间复杂度不好计算，需要进行推导
//	推导处来的平均时间复杂度为O(N^1.3 -- N^2)
//4.稳定性：不稳定

//为什么说希尔排序是不稳定的？
//由于多次插入排序，我们知道一次插入排序是稳定的，不会改变相同元素
//的相对顺序，但在不同的插入排序过程中，相同的元素可能在各自的插入
//排序中移动，最后其稳定性就会被打乱，所以shell排序是不稳定的。对于
//排序算法，所谓的不稳定指的就是相同元素在排序过程中被移动；

//void Print(std::vector<int> v, int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		std::cout << v[i] << " ";
//	}
//	std::cout << std::endl;
//}
//void ShellSort(std::vector<int> v)
//{
//	int n = v.size();
//	int gap = n;
//	while (gap > 1)
//	{
//		gap = gap / 3 + 1;
//		for (int i = 0; i < n - gap; ++i)
//		{
//			int end = i;
//			int temp = v[end + gap];
//			while (end >= 0)
//			{
//				if (v[end] > temp)
//				{
//					v[end + gap] = v[end];
//					end = end - gap;
//				}
//				else
//				{
//					break;
//				}
//				v[end + gap] = temp;//无论数据交换不交换都不影响最后的数据
//			}
//		}
//
//	}
//	Print(v, n);
//}
//int main()
//{
//	std::vector<int> v = { 2, 8, 9, 5, 3, 6, 2, 1 };
//	int n = v.size();
//	Print(v, n);
//	ShellSort(v);
//	
//	system("pause");
//	return 0;
//}