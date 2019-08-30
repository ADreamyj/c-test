#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>

//��Ŀ��쳲���������
//д��һ������������n����쳲��������еĵ�n�쳲������Ķ������£�
//			0						n = 0
//	F(n) =  1						n = 1
//			F(n - 1) + F(n - 2)		n > 1

//����1���ݹ飬����Ч�ʺܲ�O(2^n)
long long Fibonacci1(unsigned int n)
{
	if (n <= 0)
		return 0;
	if (n == 1)
		return 1;
	return Fibonacci1(n - 1) + Fibonacci1(n - 2);
}

//����2����̬�滮��ʱ�临�Ӷ�ΪO(n)
long long Fibonacci2(unsigned int n)
{
	if (n <= 0)
		return 0;
	if (n == 1)
		return 1;

	long long sum;
	long long num1 = 0;
	long long num2 = 1;
	for (unsigned int i = 2; i <= n; ++i)
	{
		sum = num1 + num2;
		num1 = num2;
		num2 = sum;
	}
	return sum;
}

int main()
{
	std::cout << Fibonacci1(15) << std::endl;
	std::cout << Fibonacci2(15) << std::endl;
	system("pause");
	return 0;
}