#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>
#include<cstdio>

//�����2��쳲���������β

//����쳲�����������100000���ڵ�ÿһ��ĺ���λ��
//Ȼ����Ҫ��ʱ��ֱ�����������Ķ�Ӧֵ���ɡ�

int main()
{
	int v[100001];
	v[0] = 1;
	v[1] = 1;
	//��ǰ����쳲��������У�ֻ������6λ 
	for (int i = 2; i < 100001; ++i)
	{
		v[i] = v[i - 1] + v[i - 2];
		//��������ӣ�����ֻҪ����λ��Ӱ����һ�����Ľ�� 
		v[i] = v[i] % 1000000;
	}
	int n;
	while (std::cin >> n)
	{
		if (n < 29)
			//쳲���������С��6λ
			printf("%d\n", v[n]);
		else
			printf("%06d\n", v[n]);
	}
	system("pause");
	return 0;
}