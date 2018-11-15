1.模拟实现strcpy函数拷贝字符串
#include<stdio.h>
#include<assert.h>
char* my_strcpy(char* dest,const char *src)
{
	char* ret = dest;
  assert(dest != NULL);
	assert(src != NULL);
	while(*dest++ = *src++)
	{
		;
	}
	return ret;

}
int main()
{
	char arr1[10] = "abcdef";
	char arr2[10] = {0};
	printf("%s\n",my_strcpy(arr2,arr1));
	return 0;
}
2.模拟实现strcat函数连接字符串
#include<stdio.h>
#include<assert.h>
char* my_strcat(char* arr1,const char* arr2)
{
	char *ret = arr1;
	assert(arr1 != NULL);
	assert(arr2 != NULL);
	while(*arr1 != '\0')
	{
		*arr1++;
	}
	while(*arr1++ = *arr2++)
	{
		;
	}
	return ret;

}
int main()
{
	char arr1[20] = "hello";
	char arr2[20] = " bit";
	printf("%s\n",my_strcat(arr1,arr2));
	return 0;
}
3.模拟实现strstr查找字符串
#include<stdio.h>
#include<assert.h>
char* my_strstr(const char*str1,const char*str2)
{
	const char *s1 = str1;
	const char *s2 = str2;
    const char *cp = str1;
	assert(str1 != NULL);
	assert(str2 != NULL);

	if(*str2 == '\0')
		return (char*)str1;

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
			return (char *)cp;
		cp++;
	}
	return NULL;
}
int main()
{
	char *p1 = "bbc";
	char *p2 = "abbcdef";
	char *ret = my_strstr(p2,p1);
	printf("%s\n",ret);
	return 0;
}
4.模拟实现strchr，含义是查找字符串s中首次出现c的位置。
#include<stdio.h>
char* my_strchr(char* s,char c)
{
	while(*s != '\0' && *s != 'c')
	{
		s++;
	}
	return *s == c?s:NULL;
}
int main()
{
	char* arr = "abcdefg";
	
	int ret = my_strchr(arr,'c');
	printf("%s\n",ret);
	return 0;
}
5.模拟实现strcmp函数比较两个字符串的大小
#include<stdio.h>
#include<assert.h>
int my_strcmp(const char* str1,const char* str2)
{
	assert(str1 != NULL);
	assert(str2 != NULL);
   while(*str1 == *str2)
   {
	   if(*str1 == '\0')
	   {
		   return 0;
	   }
	   str1++;
	   str2++;
   }
   return *str1 - *str2;
}
int main()
{
	int ret = my_strcmp("abcdef","abc");
	printf("%d",ret);
}
6.模拟实现memcpy拷贝内存
  拷贝的是字节数
#include<stdio.h>
#include<assert.h>
void* my_memcpy(void* dest,void* src ,int count)
{
	void* ret = dest;
	assert(dest != NULL);
	assert(src != NULL);

	while(count--)
	{
		*(char*)dest = *(char*)src;
		((char*)dest)++;
		((char*)src)++;
	}
	return ret;
}
int main()
{
	int arr1[] = {1,2,3,4,5,6};
	int arr2[20] = {0};
	my_memcpy(arr2,arr1,12);
	return 0;
}
7.实现memmove在一个内存中进行拷贝
#include<stdio.h>
#include<assert.h>
void* my_memmove(void* dest,void* src,int count)
{
	void* ret = dest;
	assert(dest);
	assert(src);
    if(dest<src)
    {
		while(count--)
	   {
		   *((char*) dest) =*((char*) src);
		   ((char*) dest)++;
		   ((char*) src)++;
	    }
	}
	else
	{
		while(count--)
		{
			*((char*) dest+count) = *((char*) src+count);
		}
	}
	return ret;
	
}
int main()
{
	int arr1[] = {1,2,3,4,5,6,7};
	my_memmove(arr1,arr1+2,16);
	return 0;
}