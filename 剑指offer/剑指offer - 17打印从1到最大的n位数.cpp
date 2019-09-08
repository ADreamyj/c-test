#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>
#include<vector>
//��ӡ��1������nλ��
//��Ŀ����������n����˳���ӡ����1������nλʮ��������
//�������3�����ӡ��1��2��3һֱ��������λ��999��

//����1������ͨ��д������û�п��ǵ��������
void Print1(int n)
{
	int num = 1;
	for (int i = 0; i < n; ++i)
	{
		num *= 10;
	}
	for (int i = 1; i < num; ++i)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;
}

//����2�����ַ������洢���ֿ��Խ����һ����
bool panduan(char* v);
void Print(char* v);

void Print2(int n)
{
	if (n <= 0)
		return;

	char* v = new char[n + 1];
	memset(v, '0', n);
	v[n] = '\0';

	while (!panduan(v))
	{
		Print(v);
	}
	delete[]v;
}
bool panduan(char* v)
{
	bool flag = false;
	int take = 0;        //��ʾ��λ
	int size = strlen(v);      //��ʾ���ָ���
	for (int i = size - 1; i >= 0; --i)
	{
		int num = v[i] - '0' + take;
		if (i == size - 1)
			num++;

		if (num >= 10)//��λ
		{
			if (i == 0)//��ʾ��һ���������˽�λ��ѭ������
				flag = true;
			else
			{
				num -= 10;
				take = 1;
				v[i] = '0' + num;
			}
		}
		else//����λ
		{
			v[i] = '0' + num;
			break;
		}
	}
	return flag;
}
void Print(char* v)
{
	int flag2 = true;
	int size2 = strlen(v);

	for (int i = 0; i < size2; ++i)
	{
		if (flag2 && v[i] != '0')
			flag2 = false;

		if (!flag2)
		{
			std::cout << v[i];
		}
	}
	std::cout << " ";

}
int main()
{
	Print1(2);
	Print2(2);
	system("pause");
	return 0;