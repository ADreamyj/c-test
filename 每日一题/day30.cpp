#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>
#include<cmath>
//编程题1：最难的问题
//题目很容易理解，原文与密码错位5个英文字符

//密码字母：A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
//原文字母：V W X Y Z A B C D E F G H I J K L M N O P Q R S T U
//【解题思路】：密码 > 'E'
//
//则：原文 = 密码 - 5
//否则： 原文 = 密码 + 21
//int main()
//{
//	char c;
//	while ((c = getchar()) != EOF)
//	{
//		if (c >= 'A' && c <= 'Z')
//			c = (c > 'E') ? c - 5 : c + 21;
//		putchar(c);
//	}
//	return 0;
//}

//编程题2：因子个数
//题目：求一个数字的因子（ >= 2的最小不能整除数字）个数 
//【解题思路】：从最小因子2到数字的最大因子数（数字的平方根）
//开始判断是否能够取余
//
//可以则循环取余直到取余不为0，因子个数 + 1；否则使用下一个因子计算；
//最终整除了各个因子数之后剩余的数字不为1则本身也是一个因子，
//因此因子数 + 1

//int main()
//{
//	int i, n, count;
//	while (std::cin >> n)
//	{
//		count = 0;
//		for (i = 2; i < sqrt(n); ++i)
//		{
//			if (n % i == 0)
//			{
//				while (n % i == 0)
//				{
//					n = n / i;
//				}
//				count++;
//			}
//			
//		}
//		if (n != 1)
//			count++;
//		std::cout << count << std::endl;
//	}
//	return 0;
//}
