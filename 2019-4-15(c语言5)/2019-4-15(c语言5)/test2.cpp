#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>
#include<Windows.h>

using namespace std;
//1.在屏幕上打印一个菱形
void test11()
{
	int n = 0;
	scanf("%d", &n);

	for ( int i = 0; i < n; i++)
	{
		for ( int j = 0; j < n - i -1; j++)
		{
			printf(" ");
		}
		for ( int j = 0; j < 2 * i + 1; j++)
		{
			printf("*");
		}
		cout << endl;
	}
	for ( int i = 0; i < n - 1; i++)
	{
		for (int  j = 0; j < i + 1; j++)
		{
			printf(" ");
		}
		for ( int j = 0; j < 2 * (n - 1 - i) - 1; j++)
		{
			printf("*");
		}
		cout << endl;
	}
}
//2.求出0~999之间的“水仙花数”并输出
//153 = 1^3 + 5^3 + 3^3
void test12()
{
	for (int i = 0; i < 100000; i++)
	{
		//先判断是几位数；
		//再计算数的大小
		//判断
		int temp = i;
		int n = 0;
		while (temp)
		{
			n++;
			temp = temp / 10;
		}
		temp = i;
		int sum = 0;
		while (temp)
		{
			sum += pow(temp % 10, n);
			temp = temp / 10;
		}
		if (sum == i)
			cout << i << endl;
	}
}
//3.正向打印数的每一位
void test13()
{
	char num[100];
	scanf("%s", num);
	int len = strlen(num);
	for (int i = 0; i <= len - 1; i++)
	{
		printf("%c\n", num[i]);
	}
	if (num[0] != 45)
	{
		printf("位数为:%d\n", len);
	}
	else
	{
		len = len - 1;
		printf("位数为:%d\n", len);
	}
}
//4.递归实现打印数的每一位
void print(int num)
{
	if (num > 9)
	{
		print(num / 10);
	}
	printf("%d ",num % 10);
}
void test14()
{
	int num = 0;
	scanf("%d", &num);
	print(num);
}
//5.求Sn = a+aa+aaa+aaaa+aaaaa的前5项的和，其中a是一个数字
void test15()
{
	int a = 0;
	int n = 0;
	scanf("%d%d", &a,&n);
	int sum = 0; 
	int k = 0;
	for (int i = 0; i < n; i++)
	{
		k = k * 10 + a;
		sum = sum + k;
	}
	cout << sum << endl;
}
//6.编写一个程序，它从标准输入读取C源代码，
//并验证所有的花括号都正确的成对出现。
void test16()
{
	int ch = 0;
	int count = 0;
	while ((ch = getchar()) != EOF)
	{
		if ('{' == ch)
			count++;
		else if (('}' == ch) && (count != 0))
			count--;
		else if (('}' == ch) && (count == 0))
		{
			printf("不匹配\n");
		}
	}
	if (count == 0)
		cout << "匹配" << endl;
	else
		cout << "不匹配" << endl;
}
void test17()
{
	int i = 1;   
	while (i <= 10)
	{ 
		if (i == 5)    
			continue;  
		printf("%d ", i);  
		i = i + 1; 
	}
}
void test18()
{
	int i = 1;  
	while (i <= 10)  
	{
		i = i + 1;  
		if (i == 5)    
			continue; 
		printf("%d ", i);
	}
}
void test19()
{
	int i = 0;
	int j = 0;
	for (i = 0, j = 0; j = 0; j++, i++)
	{
		j++;
		cout << j << " ";
	}
}
//编写代码，演示多个字符从两端移动，向中间汇聚
void test20()
{
	char arr1[] = "hello world";
	char arr2[] = "###########";
	int len = strlen(arr1);
	int left = 0;
	int right = len - 1;
	while (left <= right)
	{
		Sleep(1000);
		arr2[left] = arr1[left];
		arr2[right] = arr1[right];
		system("cls");

		printf("%s\n", arr2);

		++left;
		--right;
	}
}
//编写代码，模拟用户登录的场景。
void test21()
{
	char a[] = "123456";
	int i = 0;
	int j = 0;
	for (i = 0; i < 3; i++)
	{
		printf("请输入密码\n");
		scanf("%s", a);
		if (strcmp(a, "123456") == 0)
		{
			printf("输入正确\n");
			break;
		}
		else
			cout << "密码错误" << endl;
	}
	if (i == 3)
		cout << "三次密码错误，exit" << endl;
}
//计算1！+2！+......+10!
void test22()
{
	int ret = 1;
	int sum = 0;
	for (int i = 1; i <= 3; i++)
	{
		/*int ret = 1;
		for (int j = 1; j <= i; j++)
		{*/
			ret = ret * i;
	//}
			sum = sum + ret;
	}
	cout << sum << endl;
}
int main()
{
	//test11();
	//test12();
	//test13();
	//test14();
	//test15();0
	//test17();
	//test18();
	//test19();
	//test20();
	//test21();
	test22();
	system("pause");
	return 0;
}