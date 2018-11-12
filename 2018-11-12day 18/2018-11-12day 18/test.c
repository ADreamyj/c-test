////1.普通方法实现冒泡排序
//#include<stdio.h>
//void bubble_sort(int *arr,int sz)
//{
//	int i = 0;
//	//趟数
//	for(i = 0;i < sz - 1;i++)
//	{
//		//每一趟的处理
//		int j = 0;
//		for(j = 0;j < sz - 1 - i;j++)
//		{
//			if(arr[j] > arr[j+1])
//			{
//				int tmp = arr[j];
//				arr[j] = arr[j+1];
//				arr[j+1] = tmp;
//			}
//		}
//
//	}
//}
//
//int main()
//{
//	int arr[] = {9,8,7,6,5,4,3,2,1};
//	int i = 0;
//	int sz = sizeof(arr)/sizeof(arr[0]);
//    bubble_sort(arr,sz);
//	for(i = 0;i < sz;i++)
//	{
//		printf("%d ",arr[i]);
//	}
//	printf("\n");
//	return 0;
//}
//2.用qsort进行排序比较数字
//#include<stdio.h>
//#include<stdlib.h>
//int num(const void *e1,const void *e2)
//{
//    	return *(int *)e1 > *(int *)e2;
//}
//int main()
//{
//	int arr[] = {9,8,7,6,5,4,3,2,1};
//	int i = 0;
//	int sz = sizeof(arr)/sizeof(arr[0]);
//	qsort(arr,sz,sizeof(arr[0]),num);
//	for(i = 0;i < sz; i++)
//	{
//		printf("%d ",arr[i]);	
//	}
//	printf("\n");
//}
//3.用qsort进行排序比较结构体
//#include<stdio.h>
//#include<stdlib.h>
//struct Stu
//{
//	char name[20];
//	int age;
//};
//int num(const void *e1,const void *e2)
//{
//	return ((struct Stu*)e1)->age - ((struct Stu*)e2)->age;
//}
//void test1()
//{
//	struct Stu s[3] = {{"zhangsan",20},{"lisi",30},{"wangwu",15}};
//	int sz = sizeof(s)/sizeof(s[0]);
//	qsort(s,sz,sizeof(s[0]),num);
//}
//int main()
//{
//	test1();
//	return 0;
//}
//4.自己实现qsort函数
#include<stdio.h>
#include<stdlib.h>
int cmp(const void *e1,const void *e2)
{
    	return *(int *)e1 > *(int *)e2;
}

void Swap(char *e1,char *e2,int width)
{
	int i = 0;
	for(i = 0;i < width;i++)
	{
        char tmp = *e1;
		*e1 = *e2;
		*e2 = tmp;
		e1++;
		e2++;
	}
}
void bubble(void*base,int sz,int width,
			int(*cmp)(const void*e1,const void*e2))
{
	int i = 0;
	int j = 0;
	for(i = 0;i < sz - 1;i++)
	{
		for(j = 0;j <sz - 1 -i;j++)
		{
            if(cmp((char *)base+j*width,(char*)base+(j+1)*width)>0)
			{
                Swap((char*)base+j*width,(char*)base+(j+1)*width,width);
			}
		}
	}
}
int main()
{
	int arr[] = {9,8,7,6,5,4,3,2,1};
	int i = 0;
	int sz = sizeof(arr)/sizeof(arr[0]);
	bubble(arr,sz,sizeof(arr[0]),cmp);
	for(i = 0;i < sz; i++)
	{
		printf("%d ",arr[i]);	
	}
	printf("\n");
	return 0;
}