#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>
#include<vector>

//�ص㣺
//1.Ԫ�ؼ���Խ�ӽ�����ֱ�Ӳ��������ʱ��Ч��Խ��
//2.ʱ�临�Ӷ�O(N^2)
//3.�ռ临�Ӷȣ�O(1),����һ���ȶ��������㷨
//4.�ȶ��ԣ��ȶ�
 
//void Print(std::vector<int> v, int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		std::cout << v[i] << " ";
//	}
//	std::cout << std::endl;
//}
//int InsertionSort(std::vector<int> v, int n)//��������
//{
//	int i, j, value;
//	for (int i = 1; i < n; i++)
//	{
//		value = v[i];//i��ʾδΪ���򲿷ֵ��±��������
//		j = i - 1;//j��ʾ���ź���Ĳ��ֵ��±��������
//		while (j >= 0 && value < v[j])//��������ɨ�������������
//			//ֱ��������һ��С�ڵ���value��Ԫ�ء�
//		{
//			v[j + 1] = v[j];
//			j--;
//		}
//		v[j + 1] = value;//��value�������Ԫ�صĺ���
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