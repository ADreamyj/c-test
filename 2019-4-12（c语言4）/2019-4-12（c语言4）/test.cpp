#define _CRT_SECURE_NO_WARNIGS  1

#include<iostream>
using std::cout;
using std::endl;

template <class T>
void swap(T& a, T& b)
{
	T c(a); a = b; b = c;
}

void test1()
{
	int i = 43;
	printf("%d\n", printf("%d", printf("%d", i)));//4321
	//printf��ʼ��ӡ����i����������43��
	//printf�ڶ��δ�ӡ�������ֵĸ���2��
	//printf�����δ�ӡ�������ֵĸ���1��
}

void test2() 
{ 
	int a = 0;
	int b = 2;
	if (a == 1)
		if (b == 2)
			printf("hehe\n");
		else
			printf("haha\n");//else������ĵ�if���
}
//���100~200֮�������
void test3()
{
	for (int i = 1; i < 101; i++)
	{
		if (i % 2 == 1)
			printf("%d ", i);
		else
			continue;
	}
}
//�ж�������������û����ͬ��Ԫ��
void test4()
{
	int arr1[] = { 1, 2, 3, 4, 5 };
	int arr2[] = { 6,7 };
	int i = 0;
	int j = 0;
	for (i = 0; i < sizeof(arr1) / sizeof(arr1[0]); i++)
	{
		//�����ܴ�С�ֽ�/��һ��Ԫ�صĴ�С
		for (j = 0; j < sizeof(arr2) / sizeof(arr2[0]); j++)
		{
			if (arr1[i] == arr2[j])
			{
				printf("��\n");
				break;
			}
		}
		if (arr1[i] == arr2[j])
		{
			break;
		}
	}	
	if (i == sizeof(arr1) / sizeof(arr1[0]))
		printf("û��\n");
}
//�����ͺ�0���бȽ�
void test5()
{
	double i = 20.0;
	double j = i / 7.0;
	if (j * 7.0 == i)
		printf("equal\n");
	else
		printf("not eaual\n");
}

//������A�е����ݺ�����B�е����ݽ��н�����
//void test6()
//{
//	int a1[] = { 1, 2, 3, 4, 5 };
//	int a2[] = { 6, 7, 8, 9, 10 };
//	int *p1 = a1;
//	int *p2 = a2;
//	swap(*p1, *p2);
//	for (auto e : a1)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	for (auto e : a2)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//}
int main()
{
	//test1();
	//test2();
	//test3();
	//test4();
	//test5();
	test6();
	system("pause");
	return 0;
}