#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>
using namespace std;
//��ת�������С����
//��һ��������ʼ�����ɸ�Ԫ�ذᵽ�����ĩβ��
//���ǳ�֮Ϊ�������ת������һ�����������һ����ת
//�����ת�������СԪ�أ�
//���磺{3��4��5��1��2}��{1��2��3��4��5}��СԪ����һ

//�����������ԣ������ö��ֲ��ҵ�˼�����Ľ��

int minsort(int* numbers, int start, int end);

int Min(int* numbers, int length)
{
	if (numbers == nullptr || length == 0)
		cout << "�������" << endl;

	int start = 0;
	int end = length - 1;
	int mindex = start;
	while (numbers[start] >= numbers[end])
	{
		if (end - start == 1)
		{
			mindex = end;
			break;
		}

		mindex = start + (end - start)/2;

		//��������start,end,��mindex ��ֵ���ʱ������Ҫ��������
		if (numbers[start] == numbers[end] && numbers[start] == numbers[mindex])
			return minsort(numbers, start, end);


		if (numbers[mindex] >= numbers[start])
			start = mindex;
		else if (numbers[mindex] <= numbers[end])
			end = mindex;
	}
	return numbers[mindex];
}
int minsort(int* numbers, int start, int end)
{
	int result = numbers[start];
	for (int i = start +1; i <= end; i++)
	{
		if (numbers[i] < result)
			result = numbers[i];
	}
	return result;
}

void test1()
{
	int numbers[] = { 1, 1, 1, 0, 1 };
	int lenght = sizeof(numbers) / sizeof(numbers[0]);
	Min(numbers, lenght);
}
int main()
{
	test1();
	system("pause");
	return 0;
}