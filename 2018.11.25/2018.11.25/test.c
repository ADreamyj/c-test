#define _CRT_SECURE_NO_WARNINGS_ 1
//ʵ�� strStr() ������
//
//����һ�� haystack �ַ�����һ�� needle �ַ������� haystack �ַ������ҳ� needle �ַ������ֵĵ�һ��λ�� (��0��ʼ)����������ڣ��򷵻�  -1��
//
//ʾ�� 1:
//
//����: haystack = "hello", needle = "ll"
//���: 2
//ʾ�� 2:
//
//����: haystack = "aaaaa", needle = "bba"
//���: -1
#include<stdio.h>
int strStr(char* str1,char* str2)
{
    char* ret = str1;
	char* s1 = str1;
	char* s2 = str2;
	char* cp = str1;
    if(str2 == NULL || strlen(str2) == 0)
        return 0;
	while(*cp)
	{
		s1 = cp;
		s2 = str2;
		while(*s1 && *s2 && *s1 == *s2)
		{
			s1++;
			s2++;
		}
		if(*s2 == '\0')
        {
		return s1 - ret - strlen(str2);
        }
		cp++;
	}
return -1;
}
int main()
{
    char arr1 = "hello";
	char arr2 = "ll";
	printf("%d",strStr(arr1,arr2));
	return 0;
}