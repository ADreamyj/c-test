//1.
//#include<stdio.h>
//int count2(int num)
//{
//	
//	int count = 0;
//	while(num)
//	{
//		if(num%2 == 1)
//		{
//			count++;
//		}
//		num = num/2;
//	}
//	
//	return count ;
//}
//int main()
//{
//	int num = 0;
//	int count1 = 0;
//	scanf("%d",&num);
//	count1 = count2(num);
//	printf("%d",count1);
//	return 0;
//}
//2.
//#include<stdio.h>
//#include<stdlib.h>
//
//void print(int a)
//{
//	int num=0;
//	int b[32]={0};
//    int i = 0;
//	for(i=0;i<32;i++)
//	{
//		b[i] = num%2;
//		num=num/2;
//	}
//	for(i= 1;i<=32;i+=2)
//	{
//		printf("偶数位:%d",b[i]);
//	}
//	printf("\n");
//	for(i=2;i<=32;i+=2)
//	{
//		printf("奇数位:%d",b[i]);
//	}
//}
//int main()
//{
//	int num=0;
//	int a = 0;
//	printf("请输入数字：");
//	scanf("%d",&a);
//	print(num);
//	return 0;
//}
//#include<stdio.h>
//void num(int n)
//{
//	if(n>9)
//	{
//		num(n/10);
//	}
//   printf("%d ",n%10);
//}
//int main()
//{
//	int n;
//	scanf("%d",&n);
//	num(n);
//	return 0;
//
//}
//
//3.
//#include<stdio.h>
//
//void print(int a)
//{
//	if(a>9)
//	{
//		print(a/10);
//	}
//	printf("%d",a%10);
//}
//int main()
//{
//	int a = 0;
//	scanf("%d",&a);
//	print(a);
//	return 0;
//}
//4.
//#include<stdio.h>
//#include<stdlib.h>
//int print(int a,int b)
//{
//	int count = 0;
//	int num = a^b;
//	while(num!=0)
//	{
//		if((num&1)==1)
//		{
//			count++;
//		}
//		num=num>>1;
//	}
//	return count;
//}
//
//int main()
//{
//	int a,b;
//	scanf("%d %d",&a,&b);
//    print(a,b);
//	printf("%d",print(a,b));
//	return 0;
//}
//1.
//#include<stdio.h>
//int print(int a)
//{
//	int count = 0;
//	while(a)
//	{
//		if(a%2==1)
//		{
//			count++;
//		}
//		a=a/2;
//	}
//	return count;
//}
//int main()
//{
//	int a = 0;
//	int ret = 0;
//	scanf("%d",&a);
//	printf("%d",print(a));
//	return 0;
//}
//2.
//#include<stdio.h>
//
//void print(int a)
//{
//	int i = 0;
//	//从最高位开始打印偶数位
//	for(i=31;i>0;i-=2)
//	{
//		printf("%d",(a>>i)&1);
//	}
//	printf("\n");
//	//从最高位开始打印奇数位
//	for(i=30;i>=0;i-=2)
//	{
//		printf("%d",(a>>i)&1);
//	}
//}
//int main()
//{
//	int a = 0;
//	scanf("%d",&a);
//	print(a);
//	return 0;
//}
//3.
//#include<stdio.h>
//void print(int a)
//{
//	if(a>9)
//	{
//		print(a/10);
//	}
//	printf("%d ",a%10);
//  
//}
//int main()
//{
//	int a = 0;
//	scanf("%d",&a);
//    print(a);
//	return 0;
//}
//4.
#include<stdio.h>
int print(int a,int b)
{
	int i = 0;
	int count = 0;
	for(i=0;i<32;i++)
	{
		if(((a>>i)&1)!=((b>>i)&1))
		{
			count++;
		}
	}
	return count;
}
int num(int a,int b)
{
	int c = a^b;
	int count = 0;
	while(c!=0)
	{
		if((c&1)==1)
		{
			count++;
		}
		c=c>>1;
	}
	return count;
}
int main()
{
	int a = 0;
	int b = 0;
	scanf("%d%d",&a,&b);
    print(a,b);
	num(a,b);
	printf("%d和%d中不同位的个数：%d\n",
		a,b,print(a,b));
	printf("%d和%d中不同位的个数：%d\n",
		a,b,num(a,b));
	return 0;

}