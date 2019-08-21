#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>
using namespace std;

//��Ŀ����һ������Ϊn + 1�������У����е����ֶ�����1 - n���ķ�Χ�ڣ�
//����������������һ�����ظ��ģ����ҳ��ظ������֣��������޸� �����
//���飬���磺������볤��Ϊ8������{2��3��5��4��3��2��6��7}����ô��
//Ӧ������ظ����־���2����3

//����1�����ֲ��ҷ������ǲ��ܱ�֤�ҳ����е�����
//ʱ�临�Ӷ�ΪO(n(logn))���ռ临�Ӷ�ΪO(1);

//����2�����������ռ���㷨�������ҳ����е�����
//�ռ临�Ӷ�ΪO(n),ʱ�临�Ӷ�O(n)

//�÷���1�Ļ�������ʱ�任�ռ�
int countRange(const int* numbers, int length, int start, int end);
int getDuplication(const int* numbers, int length)
{
	if (numbers == nullptr || length <= 0)
		return -1;

	int start = 1;
	int end = length - 1;

	while (end >= start)
	{
		int middle = ((end - start) >> 1) + start;
		int count = countRange(numbers,length,start,middle);
		if (end == start)
		{
			if (count > 1)
				return start;
			else
				break;
		}
		if (count > (middle - start + 1))
			end = middle;
		else
			start = middle + 1;
	}
	return -1;
}

int countRange(const int* numbers, int length, int start, int end)
{
	if (numbers == nullptr)
		return 0;
	int count = 0;

	for (int i = 0; i < length; i++)
	{
		if (numbers[i] >= start && numbers[i] <= end)
			++count;
	}
	return count;
}

void test(const char* testName, int* numbers, int length, int* duplications, int dupLength)
{
	int result = getDuplication(numbers, length);
	for (int i = 0; i < dupLength; ++i)
	{
		if (result == duplications[i])
		{
			std::cout << testName << " passed." << std::endl;
			return;
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

// һ���ظ�������
void test2()
{
	int numbers[] = { 3, 2, 1, 4, 4, 5, 6, 7 };
	int duplications[] = { 4 };
	test("test2", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int));
}
// ��Ч������
void test3()
{
	int* numbers = nullptr;
	int duplications[] = { -1 };
	test("test10", numbers, 0, duplications, sizeof(duplications) / sizeof(int));
}

//void main()
//{
//	test1();
//	test2();
//	test3();
//	system("pause");
//}
