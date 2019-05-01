#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>
#include<stdlib.h>
#include<vector>
#include<time.h>
using namespace std;

//int bin_serch(int* arr,  int k,int sz)
//{
//	int left = 0;
//	int right = sz - 1;
//	while (left <= right)
//	{
//		int mid = (right + left) >> 1;
//		if (arr[mid] > k)
//		{
//			right = mid - 1;
//		}
//		else if (arr[mid] < k)
//		{
//			left = mid + 1;
//		}
//		else
//		{
//			return mid;
//		}
//	}
//	return -1;
//}
//void test1()
//{
//	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int k = 9;
//	int ret = bin_serch(arr, k,sz);
//	if (ret == -1)
//	{
//		cout << "找不到" << endl;
//	}
//	else
//	{
//		cout <<"找到了"<< ret << endl;
//	}
//}
//
////猜数字游戏
//void game()
//{
//	int ret = rand() % 101;
//	int input = 0;
//	while (1)
//	{
//		printf("请输入猜的数字\n");
//		scanf("%d", &input);
//		if (input > ret)
//		{
//			cout << "猜大了" << endl;
//		}
//		else if (input < ret)
//		{
//			cout << "猜小了" << endl;
//		}
//		else
//		{
//			cout << "恭喜你，猜对了" << endl;
//			break;
//		}
//	}
//}
//void menu()
//{
//	cout << "*****************" << endl;
//	cout << "***** 1.play ****" << endl;
//	cout << "***** 0.exit ****" << endl;
//	cout << "*****************" << endl;
//
//}
//void test2()
//{
//	int input = 0;
//	srand((unsigned)time(nullptr));
//	do
//	{
//		menu();
//		printf("请输入数字\n");
//		scanf("%d\n", &input);
//		switch (input)
//		{
//		case 1:
//			game();
//			break;
//		case 0:
//			printf("程序退出\n");
//			break;
//		default:
//			printf("选择错误\n");
//			break;
//		}
//	} while (input);
//}
////编写一个程序，可以一直接收键盘字符，
////如果是小写字符就输出对应的大写字符；
////如果是大写字符就输出对应的小写字符；
////如果是数字就不输出。
//void test3()
//{
//	int ch = 0;
//	while ((ch == getchar()) != EOF)
//	{
//		if (ch >= 'a' && ch <= 'z')
//			putchar(ch - 32);
//		else if (ch >= 'A' && ch <= 'Z')
//			putchar(ch + 32);
//		else if (ch >= '0' && ch <= '9')
//		{
//			;
//		}
//		else
//			putchar(ch);
//	}
//}

//int getValue(vector<int> gifts, int n);
//
//int getValue(vector<int> gifts, int n)
//{
//	for(int i = 0;i < n;i++)
//	{
//		for(int j = 0;j < n-i-1;j++)
//		{
//			if (gifts[i] > gifts[j])
//				swap(gifts[i], gifts[j]);
//			else
//			{
//				break;
//			}
//				
//		}
//	}
//	for (int i = 0; i < n; i++)
//	{
//		cout << gifts[i] << " ";
//	}
//	n = n >> 1;
//	cout << gifts[n] << endl;
//	return gifts[n];
//}
int main()
{
	//test1();
	//test2();
	//test3();
	/*vector<int> gifts = {2,2,2,2,5,5,5,3,2,3,2,3,2,3,2,2,2,2};
	int n = gifts.size();
	getValue(gifts, n);*/
	system("pause");

	return 0;
}