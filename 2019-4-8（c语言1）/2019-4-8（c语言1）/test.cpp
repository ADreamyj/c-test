#include<iostream>
#include<stdlib.h>
#include<math.h>


void test1()
{
	printf("%d\n", sizeof(char));// 1
	printf("%d\n", sizeof(short));// 2
	printf("%d\n", sizeof(int)); //4
	printf("%d\n", sizeof(long)); // 32--4/64--8
	printf("%d\n", sizeof(long long));//8
	printf("%d\n", sizeof(float));//4
	printf("%d\n", sizeof(double));//8
	printf("%d\n", sizeof(long double));//8
}
//int main() 
//{ 
//	printf("%d\n", strlen("abcdef"));//6
//	printf("%d\n", sizeof("abcdef"));//7
//
//	system("pause");
//	return 0; 
//}

//打印100~200之间的素数
void test2()
{
	for (int i = 100; i <= 200; i++)
	{
		int j = 0;
		for (j = 2; j <= i - 1; j++)
		{
			if (i%j == 0)
			{
				break;
			}
		}
		if (j == i)
		{
			printf("%d ", i);
		}
	}
}
//优化后
void test3()
{
	int count = 0;
	for (int i = 101; i <= 200; i+=2)
	{
		int j = 0;
		for (j = 2; j <= sqrt(i); ++j)
		{
			if (i%j == 0)
				break;
		}
		if (j > sqrt(i))
		{
			printf("%d ", i);
			count++;
		}
	}
	printf("\n%d ", count);
}


//打印乘法口诀表

void test4()
{
	for (int i = 1; i <= 9; ++i)
	{
		for (int j = 1; j <= i; ++j)
		{
			printf("%d*%d = %-2d ", i, j, i*j);
		}
		printf("\n");
	}
}

//判断1000~2000之间的闰年

void test5()
{
	int count = 0;
	for (int year = 1000; year <= 2000; ++year)
	{
		if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
		{
			count++;
			printf("%d ", year);
		}
	}
	printf("\ncount == %d\n", count);
}
int main()
{
	//test1();
	//test2();
	//test3();
	//test4();
	test5();
	system("pause");
	return 0;
}