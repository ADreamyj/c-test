#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>
using namespace std;
//���⣺��һ��ӡ������nλ����
//�����һ��3�����ӡ��1��999��nλ��

//��һ������
//��������������˵�����ܱ�֤n�����ֵ���������ĳ������
//��ô�������Ͳ���������ȥ

void Print1(int n)
{
	int number = 1;
	for (int i = 0; i < n; i++)
	{
		number *= 10;
	}
	for (int i = 1; i < number; i++)
	{
		cout << i << " ";
	}
	cout << endl;
}
bool Insert(char* numbers);
void Prints(char* numbers);
void Print2(int n)
{
	if (n <= 0)
		return;

	char* numbers = new char[n + 1];
	memset(numbers, '0', n);
	numbers[n] = '\0';

	while (!Insert(numbers))
	{
		Prints(numbers);
	}
	delete[] numbers;
}
bool Insert(char* numbers)
{
	bool flow = false;
	int takes = 0;
	int len = strlen(numbers);
	for (int i = len - 1; i >= 0; --i)
	{
		int num = numbers[i] - '0' + takes;
		if (i == len - 1)
			num++;

		if (num >= 10)
		{
			if (i == 0)
				flow = true;
			else
			{
				num -= 10;
				takes= 1;
				numbers[i] = '0' + num;
			}
		}
		else
		{
			numbers[i] = '0' + num;
			break;
		}
	}
	return flow;
}

void Prints(char* numbers)
{
	bool flow = true;
	int len = strlen(numbers);

	for (int i = 0; i < len; ++i)
	{
		if (flow && numbers[i] != '0')
			flow = false;

		if (!flow)
		{
			cout << numbers[i] << " ";
		}
	}
	cout << endl;
}
int main()
{
	//Print1(2);
	Print2(2);
	system("pause");
	return 0;
}