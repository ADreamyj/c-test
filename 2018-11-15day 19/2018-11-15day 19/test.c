1.模拟实现strncpy
#include<stdio.h>
char* my_strncpy(char* dest,const char* src,int count)
{
    char* ret = dest;
	while(count && (*dest++ = *src++))
	{
		count--;
	}
	if(count)
		while(--count)
			*dest = '\0';
    return ret;
}
int main()
{
     char arr[20] = "abcdefghi"; 
	 printf("%s",my_strncpy(arr,"hello",3));
	 return 0;
}
模拟实现strncat
#include<stdio.h>
char* my_strncat(char* dest,char* src,int count)
{
   char* ret = dest;
	while(*dest != '\0')
	{
		*dest++;
	}
	while(count--&&(*dest++ = *src++))
	{
		;
	}
	return ret;

}
int main()
{
	char arr[20] = "hello ";
	my_strncat(arr,"world 555",5);
	printf("%s",arr);
	return 0;
}
模拟实现strncmp
#include<stdio.h>
#include<assert.h>
int my_strncmp(const char* dest,const char* src,int count)
{
	assert(dest);
	assert(src);
	while(count--&&(*dest == *src))
		if(*dest == '\0')
		{
			return 0;
		}
    return *dest-*src;
}
int main()
{
	char arr1[20] = "aaahello";
	char arr2[20] = "aaaworld";
	printf("%d\n",my_strncmp(arr1,arr2,3));
	return 0;
}