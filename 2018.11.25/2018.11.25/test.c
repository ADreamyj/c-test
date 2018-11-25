#define _CRT_SECURE_NO_WARNINGS_ 1
//实现 strStr() 函数。
//
//给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1。
//
//示例 1:
//
//输入: haystack = "hello", needle = "ll"
//输出: 2
//示例 2:
//
//输入: haystack = "aaaaa", needle = "bba"
//输出: -1
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