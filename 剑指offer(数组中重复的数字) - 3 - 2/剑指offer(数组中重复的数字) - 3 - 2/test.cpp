#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>
using namespace std;
//��Ŀ�������޸������ҵ��ظ�������
//��һ������Ϊn+1�����������е����ֶ���1~n�ķ�Χ�ڣ�����������
//������һ���������ظ��ģ����ҳ�����������һ���ظ������֣�������
//�޸���������顣
//���磺������볤��Ϊ8������{2��3��5��4��3��2��6��7}����ô
//��Ӧ��������ظ�����2����3

int pcount(const int* numbers, int length, int start, int end);

int Duplication(const int* numbers, int length)
{
	if (numbers == nullptr || length <= 0)
	{
		return -1;
	}
	int start = 1;
	int end = length - 1;
	while (start <= end)
	{
		int middle = ((end - start) >> 1 )+ start;
		int count = pcount(numbers, length, start, middle);

		if (start == end)
		{
			if (count > 1)
				return start;
			else
				break;
		}
		if (count > (middle - start + 1))
		{
			end = middle;
		}
		else
			start = middle + 1;
	}
	return -1;
}

int pcount(const int* numbers, int length, int start, int end)
{
	if (numbers == nullptr)
		return 0;

	int count = 0;
	for (int i = 0; i < length; i++)
	{
		if (numbers[i] >= start && numbers[i] <= end)
			count++;
	}
	return count;
}
void test(const char* testName, int* numbers, int length, int* duplications, int dupLength)
{
	int result = Duplication(numbers, length);
	for (int i = 0; i < dupLength; ++i)
	{
		if (result == duplications[i])
		{
			std::cout << testName << " passed." << std::endl;
			//return;
		}
	}
	std::cout << testName << " FAILED." << std::endl;
}

// ����ظ�������
void test1()
{
	int numbers[] = { 2, 3, 5, 4, 3, 2, 6, 7 };
	int duplications[] = { 2, 3 };
	test("test1", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int));
}

int main()
{
	test1();
	system("pause");
	return 0;
}