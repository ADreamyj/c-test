#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>
using namespace std;

//动态规划 + 贪婪算法
//给你一根长度为n的绳子，请你将绳子剪成m段，(m,n都是整数，并且m > 0,n > 0)
//求可能取得的最大成绩

int MaxLenght1(int lenght)
{
	if (lenght < 2)
		return 0;
	if (lenght == 2)
		return 1;
	if (lenght == 3)
		return 2;
	int* products = new int[lenght + 1];
	products[0] = 1;
	products[1] = 1;
	products[2] = 2;
	products[3] = 3;

	int max = 0;
	for (int i = 4; i <= lenght; ++i)
	{
		max = 0;
		for (int j = 1; j <= i / 2; ++j)
		{
			int product = products[j] * products[i - j];
			if (max < product)
				max = product;

			products[i] = max;
		}
	}
	max = products[lenght];
	delete[] products;
	return max;
}

int MaxLenght2(int lenght)
{
	if (lenght < 2)
		return 0;
	if (lenght == 2)
		return 1;
	if (lenght == 3)
		return 2;

	int l1 = lenght / 3;
	if (lenght - l1 * 3 == 1)
		l1 -= 1;
	int l2 = (lenght - l1 * 3) / 2;

	return (int)(pow(3, l1)) * (int)(pow(2, l2));
}
void test(const char* testName, int length, int expected)
{
	int result1 = MaxLenght1(length);
	if (result1 == expected)
		std::cout << "Solution1 for " << testName << " passed." << std::endl;
	else
		std::cout << "Solution1 for " << testName << " FAILED." << std::endl;

	int result2 = MaxLenght2(length);
	if (result2 == expected)
		std::cout << "Solution2 for " << testName << " passed." << std::endl;
	else
		std::cout << "Solution2 for " << testName << " FAILED." << std::endl;
}
void test1()
{
	int length = 6;
	int expected = 9;
	test("test1", length, expected);
}
int main()
{
	test1();
	system("pause");
	return 0;
}