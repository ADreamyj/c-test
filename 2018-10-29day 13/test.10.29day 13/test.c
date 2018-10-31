//1.
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
2.
#include<stdio.h>
int num(int* arr[][3],int a,int row,int col )
{
	int i = 0;
    int j = col - 1;
	while((i<row)&(j>0))
	{
       if(arr[i][j]>n)
		   j--;
	   else if(arr[i][j]<n)
		   i++;
	   else
		   return 1;
	}
	return 2;
}
int main()
{
	int arr[][3] = {1,2,3,4,5,6,7,8,9}
	int row = 3;
	int col = 3;
	int a = 0;
	int ret = 0;
	scanf("%d",&a);
    ret = num(arr,a,row,col);
	if(ret == 1)
	{
		printf("找到了\n");
	}
	else
	{
		printf("找不到\n");
	}
	return 0;
}