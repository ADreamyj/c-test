#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>
#include<string>

//�����1��NowCoderÿ��Ҫ�����ͻ�д�����ʼ���
//��������֪�����һ���ʼ��а�������ռ��ˣ��ռ�������֮�� 
//����һ�����źͿո����������ռ�������Ҳ�����ո�򶺺ţ�
//��������Ҫ��˫���Ű�����
//���ڸ���һ���ռ����������������������Ӧ���ռ����б�

//���� 3 
//Joe Quan, 
//William Letendre,
//Bruce

//���
//Joe, "Quan,William", "Letendre,Bruce"

//int main()
//{
//	int n;
//	while (std::cin >> n)
//	{
//		std::cin.get();//����س�
//		std::string s;
//		for (int i = 0; i < n; ++i)
//		{
//			getline(std::cin, s);
//			bool flag = false;
//
//			if (s.find(' ') != -1 || s.find(',') != -1)
//			{
//				flag = true;
//			}
//
//			if (flag)
//			{
//				std::cout << '\"' << s << '\"' << std::endl;
//			}
//			else
//			{
//				std::cout << s;
//			}
//
//			if (i < n - 1)
//				std::cout << ", ";
//		}
//		std::cout << std::endl;
//	}
//	system("pause");
//	return 0;
//}

//�����2��������

//һֻ���������ÿ���ܲ���һ̥���ӡ�ÿֻС���ӵĳ�������һ�졣
//ĳ��������һֻС���ӣ����ʵ�N���� ��������õ�����ֻ���ӡ�


//����˼·����������쳲��������� 1 1 2 3 5 8 13 21...
//��������ӵڶ���Ϳ�ʼ��С���ˣ���������Ǵӵڶ��ʼ��쳲��������С�
//ǰ90�������ǡ�û��� long long�ķ�Χ�ڣ����Բ���Ҫ�߾��ȣ�
//ֱ��long long��

//int main()
//{
//	long long  v[90] = { 1, 2 };
//	for (int i = 2; i <= 90; ++i)
//	{
//		v[i] = v[i - 1] + v[i - 2];
//	}
//	int n;
//	while (std::cin >> n)
//	{
//		printf("%lld\n", v[n - 1]);
//	}
//	system("pause");
//	return 0;
//}
