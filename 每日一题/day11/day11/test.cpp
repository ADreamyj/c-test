#define _CRT_SECURE_NO_WARNINGS  1
#include<iostream>
using namespace std;

//5.����Ĵ�����ͼ��ӡ����1-9��ȫ�������

//#include<iostream>
//#define N 9
//int x[N];
//int count = 0;
//
//void dump()
//{
//	int i = 0;
//	for (i = 0; i < N; i++)
//	{
//		printf("%d", x[i]);
//	}
//	printf("\n");
//}
//
//void swap(int a, int b)
//{
//	int t = x[a];
//	x[a] = x[b];
//	x[b] = t;
//}
//
//void run(int n)
//{
//	int i;
//	if (N - 1 == n)
//	{
//		dump();
//		count++;
//		return;
//	}
//	for (i = n; i < N; i++)
//	{
//		swap(n, i);
//		run(n + 1);
//		swap(n, i);
//	}
//}
//int main()
//{
//	int i;
//	for (i = 0; i < N; i++)
//	{
//		x[i] = i + 1;
//	}
//	run(0);
//	printf("%d\n", count);
//}

//�����1-�����������
//��˳�����α��1-2-3-4-5-6-7

//˼·:���ڵ����Ҷ�ӽ�����2��

class LAC
{
public:
	int getLAC(int a, int b)
	{
		while (a != b)
		{
			if (a > b)
				a = a / 2;
			else
				b = b / 2;
		}
		cout << a << endl;
	}
};

//�����2-�����������bitλ

#include<algorithm>
int main()
{
	int n;
	while (cin >> n)
	{
		int count = 0, maxcount = 0;
		while (n)
		{
			if (n & 1)
			{
				++count;
				maxcount = max(count, maxcount);
			}
			else
			{
				count = 0;
			}
			n = n >> 1;
		}
		cout << maxcount << endl;
	}
	return 0;
}