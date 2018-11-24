#define CRT_SECURE_NO_WARNINGS
回文数
判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。

示例 1:

输入: 121
输出: true
示例 2:

输入: -121
输出: false
解释: 从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。
示例 3:

输入: 10
输出: false
解释: 从右向左读, 为 01 。因此它不是一个回文数。
进阶:

你能不将整数转为字符串来解决这个问题吗？
#include<stdio.h>
int isPalindrome(int a)
{
	int b = 0;
	int c = 0;
	int d = 0;
    	d = a;
	if(a < 0 )
        return -1;
    if(a == 0)
        return 0;
	while(a)
	{
		c = a%10;
		a = a/10;
		b = b*10+c;
	}
	if(b == d)
	{
		return d;
	}
	else
	{
		return -1;
	}
}
int main()
{
	int a = 0;
	scanf("%d",&a);
	printf("%d",isPalindrome(a));
	return 0;
}