#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>
#include<Windows.h>

using namespace std;
//1.����Ļ�ϴ�ӡһ������
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
//2.���0~999֮��ġ�ˮ�ɻ����������
//153 = 1^3 + 5^3 + 3^3
void test12()
{
	for (int i = 0; i < 100000; i++)
	{
		//���ж��Ǽ�λ����
		//�ټ������Ĵ�С
		//�ж�
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
//3.�����ӡ����ÿһλ
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
		printf("λ��Ϊ:%d\n", len);
	}
	else
	{
		len = len - 1;
		printf("λ��Ϊ:%d\n", len);
	}
}
//4.�ݹ�ʵ�ִ�ӡ����ÿһλ
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
//5.��Sn = a+aa+aaa+aaaa+aaaaa��ǰ5��ĺͣ�����a��һ������
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
//6.��дһ���������ӱ�׼�����ȡCԴ���룬
//����֤���еĻ����Ŷ���ȷ�ĳɶԳ��֡�
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
			printf("��ƥ��\n");
		}
	}
	if (count == 0)
		cout << "ƥ��" << endl;
	else
		cout << "��ƥ��" << endl;
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
//��д���룬��ʾ����ַ��������ƶ������м���
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
//��д���룬ģ���û���¼�ĳ�����
void test21()
{
	char a[] = "123456";
	int i = 0;
	int j = 0;
	for (i = 0; i < 3; i++)
	{
		printf("����������\n");
		scanf("%s", a);
		if (strcmp(a, "123456") == 0)
		{
			printf("������ȷ\n");
			break;
		}
		else
			cout << "�������" << endl;
	}
	if (i == 3)
		cout << "�����������exit" << endl;
}
//����1��+2��+......+10!
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