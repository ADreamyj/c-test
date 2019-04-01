#include<stdio.h>
#include<stdlib.h>

int main()//验证输入缓冲区
{
	int ch;
	char arr[10] = { 0 };
	printf("请输入密码\n");
	scanf_s("%s", arr);
	printf("请确认密码（Y/N）\n");
	ch = getchar();
	if (ch == 'Y')
	{
		printf("y");
	}
	else
	{
		printf("n");
	}
	system("pause");
	return 0;
}