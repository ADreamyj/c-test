#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>
#include<cmath>
//�����1�����ѵ�����
//��Ŀ��������⣬ԭ���������λ5��Ӣ���ַ�

//������ĸ��A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
//ԭ����ĸ��V W X Y Z A B C D E F G H I J K L M N O P Q R S T U
//������˼·�������� > 'E'
//
//��ԭ�� = ���� - 5
//���� ԭ�� = ���� + 21
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

//�����2�����Ӹ���
//��Ŀ����һ�����ֵ����ӣ� >= 2����С�����������֣����� 
//������˼·��������С����2�����ֵ���������������ֵ�ƽ������
//��ʼ�ж��Ƿ��ܹ�ȡ��
//
//������ѭ��ȡ��ֱ��ȡ�಻Ϊ0�����Ӹ��� + 1������ʹ����һ�����Ӽ��㣻
//���������˸���������֮��ʣ������ֲ�Ϊ1����Ҳ��һ�����ӣ�
//��������� + 1

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
