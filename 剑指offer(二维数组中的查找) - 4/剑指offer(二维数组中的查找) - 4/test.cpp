#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>

//��Ŀ����һ����ά�����У�ÿһ�ж��ǰ��մ����ҵ�����˳������
//ÿһ�ж��ǰ��մ��ϵ��µ�����˳�����������һ������������
//������һ����ά�����һ���������ж��������Ƿ��и�������

//ѡȡ�����Ͻǵ����֣������Ŀ�����ִ��Ǿ�ɾ����һ��
//����ɾ����һ�У�ֱ���ҵ�Ϊֹ��
bool Find(int* matrix, int rows, int columns, int number)
{
	if (matrix != nullptr && rows > 0 && columns > 0)
	{
		int row = 0;
		int column = columns - 1;
		while (row < rows && column > 0)
		{
			if (matrix[row * columns + column] == number)
			{
				return true;
			}
			else if (matrix[row * columns + column] > number)
			{
				--column;
			}
			else
				++row;
		}
	}
	return false;
}
void test(char* testName, int* matrix, int rows, int columns, int number, bool expected)
{
	if (testName != nullptr)
		printf("%s begins: ", testName);
	bool result = Find(matrix, rows, columns, number);
	if (result == expected)
		printf("passed.\n");
	else
		printf("Failed.\n");
}
void test1()
{
	int matrix[][4] = { { 1, 2, 8, 9 }, { 2, 4, 9, 12 }, { 4, 7, 10, 13 }, { 6, 8, 11, 15 } };
	test("test1", (int*)matrix, 4, 4, 7, true);
}
int main()
{
	test1();
	system("pause");
	return 0;
}