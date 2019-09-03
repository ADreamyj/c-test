 #define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>
#include<vector>
#include<algorithm>

//题目：剪绳子
//给你一根长度为n的绳子，请把绳子剪成m段，每段绳子的长度为K[0]
//K[1]....K[m];请问K[0]*K[1]*......K[m]可能的最大乘积是多少？


//方法1：动态规划

int MaxProduct1(int length)
{
	if (length < 2)
		return 0;
	if (length == 2)
		return 1;
	if (length == 3)
		return 2;
	
	std::vector<int> v(length + 1);
	v[0] = 0;
	v[1] = 1;
	v[2] = 2;
	v[3] = 3;

	for (int i = 4; i <= length; ++i)
	{
		int max = 0;
		for (int j = 1; j <= i / 2; ++j)
		{
			int temp = v[j] * v[i - j];
			if (temp > max)
				max = temp;

			v[i] = max;
		}
	}
	std::cout << v[length] << std::endl;
	return v[length];
}
int MaxProduct2(int length)
{
	if (length < 2)
		return 0;
	if (length == 2)
		return 1;
	if (length == 3)
		return 2;

	std::vector<int> v{ 0, 1, 2, 3 };


	for (int i = 4; i <= length; ++i)
	{
		int max = 0;
		for (int j = 1; j <= i / 2; ++j)
		{
			int temp = v[j] * v[i - j];
			if (temp > max)
				max = temp;

			
		}
		v.push_back(max);
	}
	std::cout << v[length] << std::endl;
	return v[length];
}
int MaxProduct3(int length)
{
	if (length < 2)
		return 0;
	if (length == 2)
		return 1;
	if (length == 3)
		return 2;

	int length1 = length / 3;
	if (length - length1 * 3 == 1)
	{
		--length1;
	}
	int length2 = (length - length1 * 3) << 1;

	std::cout << pow(3,length1) * pow(2,length2) << std::endl;

}
int main()
{
	MaxProduct1(18);
	MaxProduct2(18);
	MaxProduct3(18);
	system("pause");
}