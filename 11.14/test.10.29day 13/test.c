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
//			printf("�ҵ���%d %d",i,j);
//			break;
//		}
//	   else if(arr[i][j]>a)
//		   j--;
//	   else if(arr[i][j]<a)
//		   i++;
//	}
//	if((i>2)||(j<0))
//	{
//		printf("�Ҳ���\n");
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

//1.��������ʹ����ȫ����λ��ż��ǰ�档 
//
//��Ŀ�� 
//
//����һ���������飬ʵ��һ�������� 
//�����������������ֵ�˳��ʹ�����������е�����λ�������ǰ�벿�֣� 
//����ż��λ������ĺ�벿�֡� 
//1  4  5  7  8  9  10  28  30  11
//������
//1.����������ȡ��һ��ż��(i)������������ȡ��һ������(j)
//Ȼ�����߽��н�����a[i]<-->a[j]
//2.���Դ����ƣ���Ѱ��ż�����������н���������
//3.��i<jʱ������
//#include<stdio.h>
//int main()
//{
//	int a[] = {1,2,3,4,5,6,7,8,9,10};
//	int i = 0;
//	int j = 9;
//	while(i < j)
//	{
//		//��ͷ��ʼ�ҵ�һ��ż��
//		while((i < j)&&(a[i] % 2 != 0))
//		{
//			i++;
//		}
//		//��β��ʼ�ҵ�һ������
//		while((i < j)&&(a[j] % 2 != 1))
//		{
//			j--;
//		}
//		if(i < j)
//		{
//            //�����ҵ��Ĵ�ͷ��ʼ�ĵ�һ��ż��
//			//���β��ʼ�ĵ�һ������
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
���Ͼ��� 
��һ����ά����. 
�����ÿ�д������ǵ����ģ�ÿ�д��ϵ����ǵ�����. 
�������������в���һ�������Ƿ���ڡ� 
ʱ�临�Ӷ�С��O(N); 

���飺 
1 2 3 
4 5 6 
7 8 9 
������
ʱ�临�Ӷ�O(m+n)   N = m*n
 �����Ͻǿ�ʼ�ߣ�
 ���ڵ�ǰԪ�أ������ߣ�С�ڵ�ǰԪ�أ������ߡ�
#include<stdio.h>
int search(int a[3][3],int row,int col,int k,int* px,int* py)
{
	int i = 0;
	int j = col -1;
	//����Ч�ķ�Χ������Ԫ��
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
			//��ǰԪ��С��k,������
			i++;
		}
		else
		{
            //��ǰԪ��С��k,������
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