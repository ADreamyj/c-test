#define CRT_SECURE_NO_WARNINGS
������
�ж�һ�������Ƿ��ǻ���������������ָ���򣨴������ң��͵��򣨴������󣩶�����һ����������

ʾ�� 1:

����: 121
���: true
ʾ�� 2:

����: -121
���: false
����: �������Ҷ�, Ϊ -121 �� ���������, Ϊ 121- �����������һ����������
ʾ�� 3:

����: 10
���: false
����: ���������, Ϊ 01 �����������һ����������
����:

���ܲ�������תΪ�ַ�����������������
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