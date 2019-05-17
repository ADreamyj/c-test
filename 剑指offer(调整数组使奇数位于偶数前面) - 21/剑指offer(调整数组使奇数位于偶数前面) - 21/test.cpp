#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>
using namespace std;

//����һ���������飬ʵ��һ������ʹ���е������������ǰ�棬
//���е�ż��������ĺ��档

//��һ�ַ���������ǳ�ѧ�ߵĻ�����������������ǰ���������
//�ҵ�һ��ż�����Ƚ�������������Ȼ�󽫺������е�����ǰ���ƶ�һλ
//Ȼ�󽫱�������������һλ��ʱ�临�Ӷ�ΪO(n^2);

//�ڶ��ַ����ǣ���������ָ�룬�ֱ�ָ�������ͷ��β��
//��ͷ�ҵ�һ��ż���������������++��
//�Ӻ��ҵ�һ�������������ż����--��
//��ͷָ���βָ����ȵ�ʱ��ѭ��������
//��ʱ��������Ǵ���������顣ʱ�临�Ӷ�βO(n);


void ReorderOddEven1(int* str,  int length)
{
	if (str == nullptr || length <= 0)
		return;

	int* start = str;
	int* end = str + length - 1;
	while (start < end)
	{
		while (start < end && (*start & 0x1) == 1)
			++start;
		while (start < end && (*end & 0x1) == 0)
			--end;
		if (start < end)
		{
			int temp = *start;
			*start = *end;
			*end = temp;
		}
	}
}
//�����ֽⷨ����ʵ�͵ڶ��ֽⷨ����ͬ�㣬���жϵı�׼��һ������
//��ʵ�֣������Ļ����۱�׼��ʲô�����Ծ�����޸ġ�

bool Judje(int* num)
{
	return *num & 0x1 == 0;
		 
}
void ReorderOddEven2(int str[], int length)
{
	if (str == nullptr || length <= 0)
		return;
	int* start = str;
	int* end = str + length - 1;
	while (start < end)
	{
		while (start < end && (!Judje(start)))
			++start;
		while (start < end && (Judje(start)))
			--end;
		if (start < end)
		{
			int temp = *start;
			*start = *end;
			*end = temp;
		}
	}
}
void PrintArray(int numbers[], int length)
{
	if (length < 0)
		return;

	for (int i = 0; i < length; ++i)
		printf("%d ", numbers[i]);

	printf("\n");
}
void Test(char* test1, int* str,int length)
{
	if (test1 != nullptr)
		cout << test1 << endl;

	PrintArray(str, length);
	ReorderOddEven1(str, length);
	
	PrintArray(str, length);
	ReorderOddEven2(str, length);

	PrintArray(str, length);

}
void test()
{
	int str[] = { 2, 4, 6, 8, 1, 3, 5, 7};
	int length = sizeof(str) / sizeof(str[0]);
	Test("test1", str,length);
}
int main()
{
	test();
	system("pause");
	return 0;
}