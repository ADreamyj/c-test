#define _CRT_SECURE_NO_WARNINGS  1


#include<iostream>
#include<string>
#include<vector>
using namespace std;

//�����1����ˮƿ���⣬

//������һ�������⣺��ĳ�̵�涨����������ˮƿ���Ի�һƿ��ˮ��
//С��������ʮ������ˮƿ���������Ի� ����ƿ��ˮ�ȣ�������5ƿ
//���������£�����9����ƿ�ӻ�3ƿ��ˮ���ȵ�3ƿ���ģ������Ժ�4����
//ƿ�ӣ���3 ���ٻ�һƿ���ȵ���ƿ���ģ���ʱ��ʣ2����ƿ�ӡ�Ȼ������
//�ϰ��Ƚ����һƿ��ˮ���ȵ���ƿ���ģ������� ����3����ƿ�ӻ�һƿ
//���Ļ����ϰ塣���С��������n������ˮƿ�������Ի�����ƿ��ˮ�ȣ�

//int sum(int n)
//{
//	int num = 0;
//	int result = 0;
//	while (n > 1)
//	{
//		result = n / 3;
//		int reminder = n % 3;
//		num = num + result;
//		n = result + reminder;
//		if (n == 2)
//		{
//			++num;
//			break;
//		}
//	}
//	return num;
//}
//int main()
//{
//	int n;
//	while (cin >> n)
//	{
//		cout << sum(n) << endl;
//	}
//	system("pause");
//	return 0;
//}

//�����2�������ַ����е�������ַ���

int main()
{
	string str1, str2;
	while (cin >> str1 >> str2)
	{
		// ����̵��ַ�����Ϊs1
		if (str1.size() > str2.size())
			swap(str1, str2);
		int start = 0;
		int max = 0;
		vector<vector<int>> v(str1.size() + 1, vector<int>(str2.size() + 1, 0));

		for (int i = 1; i <= str1.size(); ++i)
		{
			for (int j = 1; j <= str2.size(); ++j)
			{
				if (str1[i - 1] == str2[j - 1])
				{
					v[i][j] = v[i - 1][j - 1] + 1;
				}
				//����и����Ĺ����Ӵ������³��� 
				if (v[i][j] > max)
				{
					max = v[i][j];
					//��i��β����󳤶�Ϊmax, ���Ӵ�����ʼλ��Ϊi - max 
					start = i - max;
				}
			}
		}
		cout << str1.substr(start, max) << endl;

	}
	system("pause");
	return 0;
}