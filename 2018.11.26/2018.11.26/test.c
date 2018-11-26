#define CRT_SECURE_NO_WARNINGS_  1
//给定一个排序数组，你需要在原地删除重复出现的元素，
//使得每个元素只出现一次，返回移除后数组的新长度。
//
//不要使用额外的数组空间，你必须在原地修改输入数组并
//在使用 O(1) 额外空间的条件下完成。
//
//示例 1:
//
//给定数组 nums = [1,1,2], 
//
//函数应该返回新的长度 2, 并且原数组 nums 的前两个元素
//被修改为 1, 2。 
//
//你不需要考虑数组中超出新长度后面的元素。
//示例 2:
//
//给定 nums = [0,0,1,1,1,2,2,3,3,4],
//
//函数应该返回新的长度 5, 并且原数组 nums 的前五个元素
//被修改为 0, 1, 2, 3, 4。
//
//你不需要考虑数组中超出新长度后面的元素。
#include<stdio.h>
#include<string.h>
int print(int* arr, int sz)
{
  int i = 0;
  int j = 0;
  if(sz == 0)
	  return 0;
  for(j = 1;j < sz;j++)
  {
	  if(arr[i] != arr[j])
	  {
		  i++;
		  arr[i] = arr[j];
	  }
  }
  return i+1;
}
int main()
{
	int arr[10] = {1,2,3,4,5,2,1,4,5,};
	int i = 0;
	int sz = sizeof(arr)/sizeof(arr[0]);
	print(arr,sz);
	for(i = 0; i < print(arr,sz) ;i++)
	{
		printf("%d ",arr[i]);
	}
	return 0;
}