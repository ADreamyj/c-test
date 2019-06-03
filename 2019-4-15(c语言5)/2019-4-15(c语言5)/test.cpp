#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>
using std::cout;
using std::endl;
using std::cin;
//1.将数组A中的内容与数组B中的内容进行交换

void test1()
{
	int arr1[] = { 1, 2, 3, 4, 5 };
	int arr2[] = { 6, 7, 8, 9, 10 };
	int* p1 = arr1;
	int* p2 = arr2;
	int* t = nullptr;
	t = p1;
	p1 = p2;
	p2 = t;
	for (int i = 0; i < sizeof(arr1) / sizeof(arr1[0]); i++)
	{
		cout << *(p1 + i) << " ";
	}
	for (int i = 0; i < sizeof(arr2) / sizeof(arr2[0]); i++)
	{
		cout << *(p2 + i) << " ";
	}
}
//2.计算1/1-1/2+1/3-1/4+1/5......+1/99-1/100
void test2()
{
	//double num1 = 0;
	/*for (int i = 1; i < 101; i += 2)
	{
		num1 += 1.0 / i;
	}
	double num2 = 0;
	for (int i = 2; i < 101; i += 2)
	{
		num2 += 1.0 / i;
	}*/
	//double num = num1 - num2;
	double sum = 0;
	int flag = 1;
	for (int i = 1; i < 101; i++)
	{
		sum += flag*1.0 / i;
		flag = (-1)*flag;
	}
	cout << sum << endl;
}

//编写程序数一下1到100中出现多少次数字9
void test3()
{
	int count = 0;
	for (int i = 1; i < 101; i++)
	{
		if (i / 10 == 9)
			count++;
		if (i % 10 == 9)
			count++;
	}
	cout << count << endl;
}
//浮点数的比较判断
#define A 0.00000001
void test4()
{
	float f = 3.14f;
	if ((f - 3.14) > -A && (f - 3.14) < A)
	{
		cout << 0<<endl;
	}
}
//求一元二次方程的解
#define EXP 0.000001
void test5()
{
	float a = 5.0, b = 0.0, c = 7.0;
	if (a>-EXP && a < EXP)
	{
		cout << "不是一元二次方程" << endl;
	}
	else
	{
		float disc = b*b - (4 * a*c);
		if (disc>-EXP && disc < EXP)
		{
			cout << "方程有一个解:" << -b / (2 * a) << endl;
		}
		else if (disc > EXP)
		{
			cout << ((-b) + (disc)) / (2 * a) << endl;
			cout << ((-b) - (disc)) / (2 * a) << endl;
		}
		else
		{
			cout << "此方程无解" << endl;
		}
	}
}
void test6()
{
	int n = 1;
	int m = 2;
	switch (n)
	{
	case 1:
		m++;
	case 2:
		n++;
	case 3:
		switch (n)
		{
		case 1:
			n++;
		case 2:
			m++; n++;
			break;
		}
	case 4:
		m++;
		break;
	default:
		break;
	}
	printf("m = %d,n = %d\n", m, n);//5,3
}
//goto语句（关机程序）
//C语言中提供了可以随意滥用的 goto语句和标记跳转的标号。 从理论上 
//goto语句是没有必要的， 实践中没有goto语句也可以很容易的写出代码。
//但是某些场合下goto语句还是用得着的， 最常见的用法就是终止程序在某些
//深度嵌套的结构的处理过程， 例如一次跳出两层或多层循环。这种情况
//使用break是达不到目的的。 它只能从最内层循环退出到上一层的循环

//只能在函数内部进行跳转，不能代码块外进行跳转
void test7()
{
again:
	printf("hehe\n");
	printf("hehe\n");
	printf("hehe\n");
	printf("hehe\n");
	goto again;
}
//关机程序
//void test8()
//{
//	char input[10] = { 0 };
//	system("shutdown -s -t 60");
//again:
//	printf("电脑将在1分钟内关机，如果输入：我是猪，就取消关机!\n请输入:>");
//	scanf("%s", input);
//	if (0 == strcmp(input, "我是猪"))
//	{
//		system("shutdown -a");
//	}
//	else
//	{
//		goto again;
//	}
//}
//文件结束标志
void test9()
{
	int ch = 0;
	while ((ch = getchar()) != EOF)//从输入缓冲区里面拿
	{
		putchar(ch);
	}
}
//输入密码
void test10()
{
	char passwd[10] = {0};
	int ch = 0;
	cout << "请输入密码:>";
	scanf("%s", passwd);
	cout << "请确认:(Y/N)>";
	while ((ch = getchar() != '\n'))
	{
	}
	ch= getchar();
	if ('Y' == ch)
	{
		cout << "确认成功";
	}
	else
	{
		cout << "确认失败";
	}
}
//int main()
//{
//	//test1();
//	//test2();
//	//test3();
//	//test4();
//	//test5();
//	//test6();
//	//test7();
//	//test9();
//	test10();
//	system("pause");
//	return 0;
//}
