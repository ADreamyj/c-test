//#define _CRT_SECURE_NO_WARNINGS
////1.模拟实现strclen--求字符串长度
//#include<assert.h>
//char* my_strlen(const char* arr)
//{
//	int count = 0;
//    assert(arr);
//	while(*arr != '\0')
//	{
//		arr++;
//		count++;
//	}
//	return (char*)count;
//   
//}
//#include<stdio.h>
//int main()
//{
//   char* arr = "abcdefg";
//   printf("%d\n",my_strlen(arr));
//   return 0;
//}
//2.模拟实现strcpy--字符串拷贝
//#include<stdio.h>
//#include<assert.h>
//char* my_strcpy(char* arr1,const char* arr2)
//{
//	char* ret = arr1;
//	assert(arr1);
//	assert(arr2);
//	while(*arr1++ = *arr2++)
//	{
//		;
//	}
//	return ret;
//}
//int main()
//{
//	char arr1[20] = {0};
//	char arr2[20] = "hello";
//	printf("%s\n",my_strcpy(arr1,arr2));
//	return 0;
//}
//3.模拟实现strcat--字符串连接
//#include<stdio.h>
//#include<assert.h>
//char* my_strcat(char* arr1,const char* arr2)
//{
//	char* ret = arr1;
//   assert(arr1);
//   assert(arr2);
//   while(*arr1 != '\0')
//   {
//	   arr1++;
//   }
//   while(*arr1++ = *arr2++)
//   {
//	   ;
//   }
//   return ret;
//}
//int main()
//{
//	char arr1[10] = "hello";
//	char arr2[10] = " world";
//	printf("%s\n",my_strcat(arr1,arr2));
//	return 0;
//}
//4.模拟实现strcmp--字符串大小进行比较
//#include<stdio.h>
//#include<assert.h>
//char* my_strcmp(const char* arr1,const char* arr2)
//{
//	assert(arr1);
//	assert(arr2);
//	while(*arr1 == *arr2)
//	{
//		if(*arr1 == '\0')
//		{
//			return 0;
//		}
//		arr1++;
//		arr2++;
//	}
//	return  *arr1 - *arr2;
//}
//int main()
//{
//	char* arr1 = "abcdefgh";
//	char* arr2 = "abcdhjiu";
//	int ret = (int)my_strcmp(arr1,arr2);
//	if(ret > 0)
//		printf("arr1大于arr2");
//	else if(ret < 0)
//		printf("arr1小于arr2");
//	else
//		printf("arr1等于arr2");
//	return 0;
//}
//5.模拟实现strstr--字符串查找
//#include<stdio.h>
//#include<assert.h>
//char* my_strstr(const char* arr1,const char*arr2)
//{
//	const char* str1 = arr1;
//	const char* str2 = arr2;
//	const char* cp = arr1;
//	assert(arr1);
//	assert(arr2);
//	if(str2 == '\0')
//		return (char*)str1;
//    while(*cp)
//	{
//		str1 = cp;
//		str2 = arr2;
//		while(*str1 && *str2 && *str1 == *str2)
//		{
//			str1++;
//			str2++;
//		}
//		if(*str2 == '\0')
//			return (char*)cp;
//		cp++;	
//	}
//	return NULL;
//
//}
//int main()
//{
//	char* arr1 = "abcdefg";
//	char* arr2 = "bcd";
//	printf("%s\n",my_strstr(arr1,arr2));
//	return 0;
//}
//6.模拟实现strchr--字符串查找
//#include<stdio.h>
//char* my_strchr(char* arr,char c)
//{
//	while(*arr != '\0' && *arr != 'c')
//	{
//		arr++;
//	}
//	//如果找到c返回arr,找不到返回NULL;
//	return *arr == c?arr:NULL;
//}
//int main()
//{
//	char* arr = "abcdefg";
//	printf("%s\n",my_strchr(arr,'c'));
//	return 0;
//}
//7.模拟实现memcpy--内存拷贝
//1.
//#include<stdio.h>
//#include<assert.h>
//void* my_memcpy(char* arr1,char* arr2,int count )
//{
//	assert(arr1);
//	assert(arr2);
//	while(count--)
//	{
//       *arr1++ = *arr2++;
//	}
//	return arr1;
//}
//int main()
//{
//	int arr1[] = {1,2,5,4,8,9,6,7,8,5,4,5,4};
//	int arr2[] = {1,2,3,4,5,6,7,8,9};
//    int sz = sizeof(arr2)/sizeof(arr2[0]);
//	int i = 0;
//	my_memcpy(arr1,arr2,sizeof(arr2));
//	for(i = 0;i < sz ;i++)
//	{
//		printf("%d ",arr1[i]);
//	}
//	return 0;
//}
//2.
//#include<stdio.h>
//#include<assert.h>
//void* my_memcpy(void* arr2,const void* arr1,int count)
//{
//	void* ret = arr2;
//	assert(arr1);
//	assert(arr2);
//	while(count--)
//	{
//        *(char*)arr2 = *(char*)arr1;
//		((char*)arr1)++;
//        ((char*)arr2)++;
//	}
//	return ret;
//}
//int main()
//{
//	int arr1[] = {1,2,3,4,5};
//	int arr2[20] = {0};
//	my_memcpy(arr2,arr1,12);
//	return 0;
//}
//8.模拟实现内存拷贝memmove--在一个内存中
//#include<stdio.h>
//#include<assert.h>
//void* my_memmove(void* dest,void* src,int count)
//{
//	void* ret = dest;
//	assert(dest);
//	assert(src);
//    if(dest<src)
//    {
//		while(count--)
//	   {
//		   *((char*) dest) =*((char*) src);
//		   ((char*) dest)++;
//		   ((char*) src)++;
//	    }
//	}
//	else
//	{
//		while(count--)
//		{
//			*((char*) dest+count) = *((char*) src+count);
//		}
//	}
//	return ret;
//	
//}
//int main()
//{
//	int arr1[] = {1,2,3,4,5,6,7};
//	my_memmove(arr1,arr1+2,16);
//	return 0;
//}
