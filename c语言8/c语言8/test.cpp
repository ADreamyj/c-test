#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>
using namespace std;
////1.计算二进制中1的个数
//void num1(int a)
//{
//	/*int count = 0;
//	while (a)
//	{
//		if (a%2 == 1)
//			count++;
//		a = a/2;
//	}
//	cout << count << endl;*/
//
//	/*int count = 0;
//	for (int i = 0; i < 32; i++)
//	{
//		if (((a >> i) & 1) == 1)
//		{
//			count++;
//		}
//	}
//	cout << count << " ";*/
//
//	int count = 0;
//	while (a)
//	{
//		a = a&(a - 1);
//		count ++ ;
//	}
//	cout << count << " ";
//
//}
//void test1()
//{
//	int a = 20;
//	num1(a);
//}
//
////获取一个二进制数列中的所有的偶数位和奇数位，分别输出二进制序列
//void num2(int a)
//{
//	int k = 0;
//	//奇数
//	for (int i = 30; i >= 0; i -= 2)
//	{
//		k = (a >> i) & 1;
//		cout <<  k << " ";
//	}
//	//偶数
//	cout << endl;
//	for (int i = 31; i >= 1; i -= 2)
//	{
//		k = (a >> i) & 1;
//		cout << k << " ";
//	}
//}
//
//void test2()
//{
//	int a = 10;
//	num2(a);
//}
//
////3.输出整数的每一位
//void print(int n)
//{
//	if (n > 9)//1234 123 12 1
//		print(n / 10);
//	printf("%d ", n % 10);
//}
//void test3()
//{
//	int num = 1234;
//	print(num);
//}
//
////4.两个整数有多少个比特位不同
//int num(int temp)
//{
//	int count = 0;
//	while (temp)
//	{
//		count++;
//		temp = temp&(temp - 1);
//	}
//	return count;
//}
//void test4()
//{
//	int i = 1999, j = 2299;
//	int temp = i^j;
//	int ret = num(temp);
//	cout << ret << endl;
//}
//
//void Swap1(int x, int y) 
//{ 
//	int tmp = 0; 
//	tmp = x; 
//	x = y;   
//	y = tmp; 
//} 
//void Swap2(int *px, int *py) 
//{
//	int tmp = 0; 
//	tmp = *px; 
//	*px = *py;  
//	*py = tmp; 
//} 
//void test5()
//{
//	int num1 = 1; 
//	int num2 = 2; 
//	Swap1(num1, num2); 
//	printf("Swap1::num1 = %d num2 = %d\n", num1, num2); 
//	Swap2(&num1, &num2);   
//	printf("Swap2::num1 = %d num2 = %d\n", num1, num2);  
// }
int addDigits(int num)
{
	while (num >= 10)
	{
		num = num / 10 + num % 10;
	}
	return num;
}
int main()
{
	//test1();
	//test2();
	//test3();
	//test4();
	//test5();
	int num = 123;
	printf("%d ",addDigits(num));
	system("pause");
	return 0;
}