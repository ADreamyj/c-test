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

//�����1
//int main()
//{
//	int n;
//	while (cin >> n)
//	{
//		vector<vector<int>> v(n, vector<int>(2*n - 1,0));
//		v[0][0] = 1;
//		for (int i = 1; i < n; i++)
//		{
			//��һ�к����һ�ж�Ϊ1
//			v[i][0] = v[i][2 * i] = 1;
//			for (int j = 1; j < 2 * i; ++j)
//			{
//				if (j == 1)
				//����ǵڶ��У���ֻ������Ԫ��֮�� 
//					v[i][j] = v[i - 1][j - 1] + v[i - 1][j];
//				else
				//��i,jԪ�ص�����һ�е�j - 2,j - 1,j����Ԫ��֮��
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

//�����2
string addstring(string s1, string s2)
{
	//�ɵ�λ���λ���
	int size1 = s1.size() - 1;
	int size2 = s2.size() - 1;
	//��ǰλ����ӽ��
	string result = "";
	int carry = 0;
	while (size1 >= 0 || size2 >= 0)
	{
		if (size1 >= 0)
			carry += s1[size1] - '0';
		if (size2 >= 0)
			carry += s2[size2] - '0';

		//��ǰΪ�����ֵ������10
		result += (char)(carry % 10 + '0');
		//�������10,���Ͻ�һλ
		carry /= 10;
		size1--;
		size2--;
	}
	//�����֮��������н�λ�����ټ�1
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