#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>
#include<cstdio>

//编程题2：斐波那契数凤尾

//先求斐波那契数列在100000以内的每一项的后六位，
//然后需要的时候直接输出数组里的对应值即可。

int main()
{
	int v[100001];
	v[0] = 1;
	v[1] = 1;
	//提前计算斐波那契数列，只保留后6位 
	for (int i = 2; i < 100001; ++i)
	{
		v[i] = v[i - 1] + v[i - 2];
		//由于是相加，所以只要后六位不影响下一个数的结果 
		v[i] = v[i] % 1000000;
	}
	int n;
	while (std::cin >> n)
	{
		if (n < 29)
			//斐波那契数列小于6位
			printf("%d\n", v[n]);
		else
			printf("%06d\n", v[n]);
	}
	system("pause");
	return 0;
}