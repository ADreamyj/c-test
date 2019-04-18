#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//题目一：找出数组中重复的数字
//在一个长度为n的数组里所有数字的范围都是0~n-1的范围内。数组中某个
//数字是重复的，但是不知道有几个数字是重复的了，也不知道每个数字
//重复了几次。请找出数组中任意一个重复的数字。

//例如，如果输出长度为7的数组{2，3，1，0，2，5，3}，那么对应的数组
//是重复的数字2或者3

//对于这道题而言，如果想要提高时间，空间的效率。
//时间复杂度为O(n),空间复杂度为o(1);

//只找出一个相同的数
bool duplicate1(int number[], int length)
{
	if (number == nullptr || length < 0)
	{
		return false;
	}
	for (int i = 0; i < length; ++i)
	{
		if (number[i] < 0 || number[i] > length)
			return false;
	}

	for (int i = 0; i < length; ++i)
	{
		while (number[i] != i)
		{
			if (number[i] == number[number[i]])
			{
				//*duplication = number[i];
				cout << number[i] << endl;
				return number[i];
			}
			else
			{
				int temp = number[i];
				number[i] = number[temp];
				number[temp] = temp;
			}
			
		}
	}
	return false;
}

//int main()
//{
//	int number[] = { 2, 3, 1, 0, 2, 5, 3 };
//	int length = sizeof(number) / sizeof(number[0]);
//	
//	duplicate1(number, length);
//	system("pause");
//	return 0;
//}

bool duplicate2(int number[], int length,vector<int> duplication)
{
	if (number == nullptr || length < 0)
	{
		return false;
	}
	for (int i = 0; i < length; ++i)
	{
		if (number[i] < 0 || number[i] > length)
			return false;
	}

	sort(number, number + length);
	int k = 0, j = 0;
	//拿数组中第k个位置和第j+1个位置的数据相比，只能是number[k] <= number[j + 1]
	while (k < length - 1 && j < length - 1)
	{
		//number[k] < number[j + 1]的时候，只存在两种情况k == j或k < j
		if (number[k] < number[j + 1])
		{
			if (k == j)
			{
				k++;
				j++;
			}
			//k<j时，就让k+1
			else
			{
				k++;
			}
		}
		//number[k] = number[j + 1],就把number[k]插入到集合中，避免出现多次的数据重复出现
		else
		{
			//cout << "重复数字为" << number[k] << endl;    
			duplication.push_back(number[k]);
			j++;
		}
	}
	
	vector<int>::iterator it;
	for (it = duplication.begin(); it != duplication.end(); it++)  //使用迭代器对集合进行遍历
	{
		cout << *it << endl;
	}
	return false;
}

//int main()
//{
//	int number[] = { 2, 3, 1, 0, 2, 5, 3 };
//	int length = sizeof(number) / sizeof(number[0]);
//	vector<int> duplication;
//	duplicate2(number, length,duplication);
//	system("pause");
//	return 0;
//}


