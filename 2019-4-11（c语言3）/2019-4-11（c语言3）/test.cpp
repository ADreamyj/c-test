#define _CRT_SECURE_NO_WARNIGS  1

#include<iostream>
//#include<algorithm>
#include<vector>
using std::cout;
using std::endl;
using std::cin;

//1.������������������ֵ��������ֵ�����ݽ��н�����
void test1()
{
	int i, j;
	cin >> i >> j;
	int temp = 0;
	temp = i;
	i = j;
	j = temp;
	cout << i << endl;
	cout << j << endl;
}

//2.����������ʱ���������������������ݡ�
void test2()
{
	int i, j;
	cin >> i >> j;
	j = i^j;
	i = i^j;
	j = i^j;
	cout << i << " " << j << endl;
}
//3.��10�����е����ֵ��
template <class T>
void swap(T& a,T& b)
{
	T c(a);
	a = b;
	b = c;
	
}
void test3()
{
	int a[] = { 12, -2, -3, -4, -5, -6, -7, -8, -9, -10 ,100,200};
	int max = a[0];

	for (int i = 0; i < sizeof(a)/sizeof(int); ++i)
	{
		if (max < a[i])
			max = a[i];
	}
	cout << max << endl;
}
//���������Ӵ�С�����
void test4()
{
	int v[] = { 9, 5, 6, 8, 7, 5, 8, 5, 6, 4 };
	for (int i = 0; i < sizeof(v) / sizeof(int);i++)
	{
		for (int j = 0; j < sizeof(v) / sizeof(int) - i - 1 ; j++)
		{
			if (v[j] > v[j + 1])
				swap(v[j], v[j + 1]);
		}
	}
	for (auto e : v)
	{
		cout << e << endl;
	}


}
//�������������Լ����
//��С������=�����ɻ�/���Լ��
void test5()
{
	int a, b;
	int c = 0;
	cin >> a >> b;
	while (c = a%b)
	{
		a = b;
		b = c;
	}
	cout << b << endl;
}
int main()
{
	//test1();
	//test2();
	//test3();
	//test4();
	test5();
	system("pause");
	return 0;
}