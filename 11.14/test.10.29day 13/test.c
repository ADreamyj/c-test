////1.
//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<stdlib.h>
//void num(int arr[],int sz)
//{
//	int *left = arr;
//	int *right = arr + sz -1;
//	int temp = 0;
//	while(left<right)
//	{
//		while((left<right)&&(*left)%2!=0)
//		{
//			left++;
//		}
//		while((left<right)&&(*right)%2==0)
//		{
//			right--;
//		}
//		if(left<right)
//		{
//			temp = *left;
//			*left = *right;
//			*right = temp;
//		}
//	}
//}
//int main()
//{
//	int i = 0;
//	int arr[] = {1,2,3,4,5,6,7};
//	int sz = sizeof(arr)/sizeof(arr[0]);
//	num(arr,sz);
//	for(i=0;i<sz;i++)
//	{
//		printf("%d ",arr[i]);
//	}
//
//	return 0;
//}
//2.
//#include<stdio.h>
//void num(int arr[3][3],int a,int row,int col )
//{
//	int i = 0;
//    int j = col - 1;
//	while((i<row)&&(j>=0))
//	{
//		if(arr[i][j]==a)
//		{
//			printf("找到了%d %d",i,j);
//			break;
//		}
//	   else if(arr[i][j]>a)
//		   j--;
//	   else if(arr[i][j]<a)
//		   i++;
//	}
//	if((i>2)||(j<0))
//	{
//		printf("找不到\n");
//	}
//	
//}
//int main()
//{
//	int arr[3][3] = {1,2,3,4,5,6,7,8,9};
//	int row = 3;
//	int col = 3;
//	int a = 0;
//	scanf("%d",&a);
//    num(arr,a,row,col);
//	return 0;
//}

//1.调整数组使奇数全部都位于偶数前面。 
//
//题目： 
//
//输入一个整数数组，实现一个函数， 
//来调整该数组中数字的顺序使得数组中所有的奇数位于数组的前半部分， 
//所有偶数位于数组的后半部分。 
//1  4  5  7  8  9  10  28  30  11
//分析：
//1.从左往右数取第一个偶数(i)，从右往左数取第一个奇数(j)
//然后将两者进行交换。a[i]<-->a[j]
//2.并以此类推，再寻找偶数和奇数进行交换。。。
//3.当i<j时结束。
//#include<stdio.h>
//int main()
//{
//	int a[] = {1,2,3,4,5,6,7,8,9,10};
//	int i = 0;
//	int j = 9;
//	while(i < j)
//	{
//		//从头开始找第一个偶数
//		while((i < j)&&(a[i] % 2 != 0))
//		{
//			i++;
//		}
//		//从尾开始找第一个奇数
//		while((i < j)&&(a[j] % 2 != 1))
//		{
//			j--;
//		}
//		if(i < j)
//		{
//            //交换找到的从头开始的第一个偶数
//			//与从尾开始的第一个奇数
//			int temp = a[i];
//			a[i] = a[j];
//			a[j] = temp;
//		}
//	}
//	for(i = 0;i < 10;i++)
//	{
//		printf("%d ",a[i]);
//	}
//	return 0;
//}
杨氏矩阵 
有一个二维数组. 
数组的每行从左到右是递增的，每列从上到下是递增的. 
在这样的数组中查找一个数字是否存在。 
时间复杂度小于O(N); 

数组： 
1 2 3 
4 5 6 
7 8 9 
分析：
时间复杂度O(m+n)   N = m*n
 从右上角开始走：
 大于当前元素，向下走；小于当前元素，向左走。
#include<stdio.h>
int search(int a[3][3],int row,int col,int k,int* px,int* py)
{
	int i = 0;
	int j = col -1;
	//在有效的范围里面找元素
	while(i < row && j >=0)
	{
		if(a[i][j] == k)
		{
			*px = i;
			*py = j;
			return 1;
		}
		else if(a[i][j] < k)
		{
			//当前元素小于k,向下走
			i++;
		}
		else
		{
            //当前元素小于k,向左走
			j--;
		}
	}
  *px = -1;
  *py = -1;
  return 0;
}
int main()
{
	int a[3][3] = {1,2,3,4,5,6,7,8,9};
	int px;
	int py;
	search(a,3,3,7,&px,&py);
	printf("%d %d\n",px,py);
	return 0;
}