#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>

//��Ŀ��������һ����������ƥ�����','��'*'��������ʽ��
//ģʽ�е�','���Ա�ʾ����һ���ַ���
//ģʽ�е�'*'���Ա�ʾ��ǰ����ַ����Գ��������Ρ�
//�ڱ����У�ƥ����ָ�ַ����������ַ�ƥ������ģʽ��
//����/���ַ���"aaa"��ģʽ"a.a"��"ab*ac*a"ƥ�䣬
//����"aa.a"��"ab*a"����ƥ�䡣

//����˼·;
//1.����ַ�����ģʽ�ĵ�һ���ַ���ȣ���ôͬʱ������ƶ�һ���ַ���
//2.���ģʽ���ַ�λ'.'�Ļ�������Ҳ��ͬʱ����ƶ�һ���ַ���
//3.���ģʽ�ĵĵڶ����ַ�λ'*'�Ļ������������¼���ƥ�䷽ʽ��
//	��1��ģʽ����ƶ���λ��ֱ������ǰ����ַ�
//	��2�����ģʽ�ĵ�һ���ַ����ַ����е�һ���ַ��໥ƥ��Ļ���
//		�ַ�������ƶ�һ���ַ�����ģʽ��������ƶ������ַ���
//		Ҳ����ѡ�񱣳ֲ��䡣

//��������
bool matchCore(char* str, char* pattern);
bool match(char* str, char* pattern)
{
	if (str == nullptr || pattern == nullptr)
		return false;
	return matchCore(str, pattern);
}
bool matchCore(char* str, char* pattern)
{
	if (*str == '\0' && *pattern == '\0')
		return true;

	if (*str != '\0' && *pattern == '\0')
		return false;
	if (*(pattern + 1) == '*')
	{
		if (*pattern == *str || (*pattern == '.' && *pattern != '\0'))
		{
			return matchCore(str + 1, pattern + 2)
				|| matchCore(str + 1, pattern)
				|| matchCore(str, pattern + 2);
		}
		else
			return match(str, pattern + 2);
	}

	if (*pattern == *str || (*pattern == '.' && *str != '\0'))
		return matchCore(str + 1, pattern + 1);
}
//int main()
//{
//	char* str = "aaa";
//	char* pattern = "ab*ac*a";
//	char* pattern1 = "ab*a";
//	std::cout << match(str, pattern) <<std::endl;
//	std::cout << match(str, pattern1) << std::endl;
//	system("pause");
//	return 0;
//}