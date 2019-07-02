#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>
#include<vector>
#include<string>
using namespace std;

//int main()
//{
//	char *p = "abc";
//	char *q = "abc123"; 
//	if (*p == *q) 
//		printf("%c %c", *p, *q);
//	system("pause");
//	return 0;
//}

//编程题1
//int main()
//{
//	int n;
//	while (cin >> n)
//	{
//		vector<vector<int>> v(n, vector<int>(2*n - 1,0));
//		v[0][0] = 1;
//		for (int i = 1; i < n; i++)
//		{
			//第一列和最后一列都为1
//			v[i][0] = v[i][2 * i] = 1;
//			for (int j = 1; j < 2 * i; ++j)
//			{
//				if (j == 1)
				//如果是第二列，则只是两个元素之和 
//					v[i][j] = v[i - 1][j - 1] + v[i - 1][j];
//				else
				//第i,j元素等于上一行第j - 2,j - 1,j三列元素之和
//					v[i][j] = v[i - 1][j - 2] + v[i - 1][j - 1] + v[i - 1][j];
//			}
//			int k;
//			for (k = 0; k < (2 * n - 1); k++)
//			{
//				if (v[n - 1][k] % 2 == 0 && v[n - 1][k] != 0)
//				{
//					cout << k + 1 << endl;
//					break;
//				}
//			}
//			if (n < 2)
//				cout << -1 << endl;
//		}
//	}
//	system("pause");
//	return 0;
//}

//编程题2
string addstring(string s1, string s2)
{
	//由低位向高位相加
	int size1 = s1.size() - 1;
	int size2 = s2.size() - 1;
	//当前位的相加结果
	string result = "";
	int carry = 0;
	while (size1 >= 0 || size2 >= 0)
	{
		if (size1 >= 0)
			carry += s1[size1] - '0';
		if (size2 >= 0)
			carry += s2[size2] - '0';

		//当前为的最大值不大于10
		result += (char)(carry % 10 + '0');
		//如果大于10,向上进一位
		carry /= 10;
		size1--;
		size2--;
	}
	//相加完之后，如果还有进位，则再加1
	if (carry == 1)
		result += '1';
	reverse(result.begin(), result.end());
	return result;
}
int main()
{
	string s1, s2;
	while (cin >> s1 >> s2)
	{
		cout << addstring(s1, s2) << endl;
	}
	system("pause");
	return 0;
}