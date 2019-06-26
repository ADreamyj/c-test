#define _CRT_SECURE_NO_WARNINGS  1


#include<iostream>
#include<string>
#include<vector>
using namespace std;

//编程题1：反转字符串
//int main()
//{
//	string str;
//	while (cin >> str)
//	{
//		int size = str.size();
//		int begin = 0;
//		int end = str.size() - 1;
//		while (begin < end)
//		{
//			int temp = str[begin];
//			str[begin] = str[end];
//			str[end] = temp;
//			++begin;
//			--end;
//		}
//		cout << str << endl;
//	}
//	system("pause");
//	return 0;
//}

//编程题2：字符串的公共字符串的长度

int main()
{
	string str1, str2;
	while (cin >> str1 >> str2)
	{
		if (str1.size() > str2.size())
			swap(str1, str2);

		int max = 0;
		vector<vector<int>> v(str1.size() + 1, (vector<int>(str2.size() + 1)));
		for (int i = 0; i < str1.size(); ++i)
		{
			for (int j = 0; j < str2.size(); ++j)
			{
				if (str1[i] != str2[j])
					v[i][j]= 0;
				else if (i == 0 || j == 0)
				{
					v[i][j] = 1;
					if (max < 1)
						max = 1;
				}
				else
				{
					v[i][j] = v[i - 1][j - 1] + 1;
					if (v[i][j] > max)
						max = v[i][j];
				}
			}
		}
		//cout << str1.substr(start,max)<< endl;
		cout << max << endl;

	}
	system("pause");
	return 0;
}
//#include <iostream>
//#include <string.h>
//#include <stdlib.h>
//#include <vector>
//#include<algorithm>
//using namespace std;
//int main()
//{
//
//	string str1, str2;
//	while (cin >> str1)
//	{
//		cin >> str2;
//		vector<vector<int> > matrix(str1.size(), vector<int>(str2.size()));
//		int max_num = 0;
//		for (int i = 0; i<str1.size(); i++)
//		{
//			for (int j = 0; j<str2.size(); j++)
//			{
//				if (str1[i] != str2[j])
//					matrix[i][j] = 0;
//				else if (i == 0 || j == 0)
//				{
//					matrix[i][j] = 1;
//					if (max_num<1)
//						max_num = 1;
//				}
//				else
//				{
//					matrix[i][j] = matrix[i - 1][j - 1] + 1;
//					if (matrix[i][j]>max_num)
//						max_num = matrix[i][j];
//				}
//			}
//		}
//		cout << max_num << endl;
//
//	}
//	system("pause");
//	return 0;
//}