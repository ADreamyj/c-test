#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>

//��Ŀ��ʵ�ֺ���double Power(double base,int exponent),
//��base��exponse�η�������ʹ�ÿ⺯����ͬʱ����Ҫ���Ǵ�������

//����1��ֻ�ܴ��������ָ���������������

double Power1(double base, int exponent)
{
	double result = 1.0;
	for (int i = 1; i <= exponent; ++i)
	{
		result *= base;
	}
	return result;
}

//����2��������������
bool flag = false;

bool equal(double A)
{
	bool result = false;
	if (A >= -0.00001 && A <= 0.00001)
	{
		result = true;
	}
	return result;
}
double Power2(double base, int exponent)
{
	flag = false;
	if (equal(base) && exponent < 0)
	{
		flag = true;
		return 0.0;
	}

	unsigned int abs = unsigned int(exponent);
	if (exponent < 0)
		abs = unsigned int(-exponent);

	double result = Power1(base, exponent);

	if (exponent < 0)
		result = 1.0 / result;

	std::cout << result << std::endl;
	return result;
}

//���ڹ�ʽ���ݹ�ʵ�� ����ֵ�������η���Ч�ʸ��ߣ�
//���룺base����, exponent ָ��
//���أ����
//(5,3)101^11 = 101^01 * 101^10;

double Power3(double base, int exponent)
{
	//2.�ع�����
	if (exponent == 0)
		return 1;
	if (exponent == 1)
		return base;

	//1.���ƹ�ʽ
	double result = Power3(base, exponent >> 1);

	//3.�ع���㹫ʽ
	result *= result;
	if (exponent & 0x1 == 1)
		result *= base;

	std::cout << result << std::endl;
	return result;
}
int main()
{
	Power2(5.0, 3);
	std::cout << Power3(5.0, 3) << std::endl;
	system("pause");
	return 0;
}