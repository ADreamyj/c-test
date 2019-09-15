#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>
#include<vector>
//题目：输入一个整数数组，实现一个函数用来调整该数组中的顺序，
//使得所有的奇数位于数组的前半部分，所有偶数位于数组的后半部分。

//解题思路：
//用两个指针，一个指针指向数组的第一个数字，它只向后移动；
//另一个指针指向数组的最后一个数字，它只向前移动；
//在两个指针相遇之前，第一个指针总是位于第二个指针的前面
//如果第一个指针指向的是偶数，并且第二个指针指向的是奇数，
//则交换这两个指针。

void ReorderOddEven(std::vector<int> &v)
{
	if (v.size() == 0)
		return;

	int size = v.size();
	int begin = 0;
	int end = size - 1;
	while (begin < end)
	{
		while (begin < end && (v[begin] & 0x1) != 0)
			begin++;
		while (begin < end && (v[end] & 0x1) == 0)
			end--;
		if (begin < end)
		{
			int temp = v[begin];
			v[begin] = v[end];
			v[end] = temp;
		}
	}
	
}
void Print(std::vector<int> v)
{
	for (int i = 0; i < v.size(); i++)
	{
		std::cout << v[i] << " ";
	}
	std::cout << std::endl;
}


//拓展
//如果把题目改成把数组中的数按照大小分为两部分，所有的负数都在非负数的前面
//如果把题目改成把数组中的数按照能否被三整除分为两部分
//。。。。
//对于上述的问题，面试官想要考察的是

//回调函数

void Reorder(std::vector<int> &v, bool(*fun)(int));
bool isEven(int n)
{
	return (n & 1) == 0;
}
void ReorderOddEven2(std::vector<int> &v)
{
	Reorder(v, isEven);
}
void Reorder(std::vector<int> &v, bool (*fun)(int))
{
	if (v.size() == 0)
		return;

	int size = v.size();
	int begin = 0;
	int end = size - 1;
	while (begin < end)
	{
		while (begin < end && !fun(v[begin]))
			begin++;
		while (begin < end &&  fun(v[end]))
			end--;
		if (begin < end)
		{
			int temp = v[begin];
			v[begin] = v[end];
			v[end] = temp;
		}
	}

}
int main()
{
	std::vector<int> v = { 2, 4, 6, 8, 1, 3, 5, 7 };
	ReorderOddEven2(v);
	Print(v);
	system("pause");
	return 0;
}