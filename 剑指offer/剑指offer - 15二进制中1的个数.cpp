#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>

//��Ŀ����������1�ĸ���
//��ʵ��һ������������һ�������������������1�ĸ�����
//���磺��9��ʾΪ��������1001������λ��1�������2


//����1����1��n����&���㣬����1��1������0Ϊ0��ѭ��32��
int Number1(int n)
{
	int count = 0;
	unsigned int flag = 1;
	while (flag)
	{
		if (n & flag)
			count++;
		flag = flag << 1;
	}
	std::cout << count << std::endl;
	return count;
}

//����2��ѭ��1�ĸ�����
int Number2(int n)
{
	int count = 0;
	while (n)
	{
		n = (n - 1) & n;
		++count;
	}
	std::cout << count << std::endl;
	return count;
}

//int main()
//{
//	Number1(9);
//	Number2(9);
//	system("pause");
//	return 0;
//}