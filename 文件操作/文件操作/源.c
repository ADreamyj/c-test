#include<stdio.h>
#include<stdlib.h>

int main()//��֤���뻺����
{
	int ch;
	char arr[10] = { 0 };
	printf("����������\n");
	scanf_s("%s", arr);
	printf("��ȷ�����루Y/N��\n");
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