#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>
using std::cout;
using std::endl;
using std::cin;
//1.������A�е�����������B�е����ݽ��н���

void test1()
{
	int arr1[] = { 1, 2, 3, 4, 5 };
	int arr2[] = { 6, 7, 8, 9, 10 };
	int* p1 = arr1;
	int* p2 = arr2;
	int* t = nullptr;
	t = p1;
	p1 = p2;
	p2 = t;
	for (int i = 0; i < sizeof(arr1) / sizeof(arr1[0]); i++)
	{
		cout << *(p1 + i) << " ";
	}
	for (int i = 0; i < sizeof(arr2) / sizeof(arr2[0]); i++)
	{
		cout << *(p2 + i) << " ";
	}
}
//2.����1/1-1/2+1/3-1/4+1/5......+1/99-1/100
void test2()
{
	//double num1 = 0;
	/*for (int i = 1; i < 101; i += 2)
	{
		num1 += 1.0 / i;
	}
	double num2 = 0;
	for (int i = 2; i < 101; i += 2)
	{
		num2 += 1.0 / i;
	}*/
	//double num = num1 - num2;
	double sum = 0;
	int flag = 1;
	for (int i = 1; i < 101; i++)
	{
		sum += flag*1.0 / i;
		flag = (-1)*flag;
	}
	cout << sum << endl;
}

//��д������һ��1��100�г��ֶ��ٴ�����9
void test3()
{
	int count = 0;
	for (int i = 1; i < 101; i++)
	{
		if (i / 10 == 9)
			count++;
		if (i % 10 == 9)
			count++;
	}
	cout << count << endl;
}
//�������ıȽ��ж�
#define A 0.00000001
void test4()
{
	float f = 3.14f;
	if ((f - 3.14) > -A && (f - 3.14) < A)
	{
		cout << 0<<endl;
	}
}
//��һԪ���η��̵Ľ�
#define EXP 0.000001
void test5()
{
	float a = 5.0, b = 0.0, c = 7.0;
	if (a>-EXP && a < EXP)
	{
		cout << "����һԪ���η���" << endl;
	}
	else
	{
		float disc = b*b - (4 * a*c);
		if (disc>-EXP && disc < EXP)
		{
			cout << "������һ����:" << -b / (2 * a) << endl;
		}
		else if (disc > EXP)
		{
			cout << ((-b) + (disc)) / (2 * a) << endl;
			cout << ((-b) - (disc)) / (2 * a) << endl;
		}
		else
		{
			cout << "�˷����޽�" << endl;
		}
	}
}
void test6()
{
	int n = 1;
	int m = 2;
	switch (n)
	{
	case 1:
		m++;
	case 2:
		n++;
	case 3:
		switch (n)
		{
		case 1:
			n++;
		case 2:
			m++; n++;
			break;
		}
	case 4:
		m++;
		break;
	default:
		break;
	}
	printf("m = %d,n = %d\n", m, n);//5,3
}
//goto��䣨�ػ�����
//C�������ṩ�˿����������õ� goto���ͱ����ת�ı�š� �������� 
//goto�����û�б�Ҫ�ģ� ʵ����û��goto���Ҳ���Ժ����׵�д�����롣
//����ĳЩ������goto��仹���õ��ŵģ� ������÷�������ֹ������ĳЩ
//���Ƕ�׵Ľṹ�Ĵ�����̣� ����һ�������������ѭ�����������
//ʹ��break�Ǵﲻ��Ŀ�ĵġ� ��ֻ�ܴ����ڲ�ѭ���˳�����һ���ѭ��

//ֻ���ں����ڲ�������ת�����ܴ�����������ת
void test7()
{
again:
	printf("hehe\n");
	printf("hehe\n");
	printf("hehe\n");
	printf("hehe\n");
	goto again;
}
//�ػ�����
//void test8()
//{
//	char input[10] = { 0 };
//	system("shutdown -s -t 60");
//again:
//	printf("���Խ���1�����ڹػ���������룺��������ȡ���ػ�!\n������:>");
//	scanf("%s", input);
//	if (0 == strcmp(input, "������"))
//	{
//		system("shutdown -a");
//	}
//	else
//	{
//		goto again;
//	}
//}
//�ļ�������־
void test9()
{
	int ch = 0;
	while ((ch = getchar()) != EOF)//�����뻺����������
	{
		putchar(ch);
	}
}
//��������
void test10()
{
	char passwd[10] = {0};
	int ch = 0;
	cout << "����������:>";
	scanf("%s", passwd);
	cout << "��ȷ��:(Y/N)>";
	while ((ch = getchar() != '\n'))
	{
	}
	ch= getchar();
	if ('Y' == ch)
	{
		cout << "ȷ�ϳɹ�";
	}
	else
	{
		cout << "ȷ��ʧ��";
	}
}
//int main()
//{
//	//test1();
//	//test2();
//	//test3();
//	//test4();
//	//test5();
//	//test6();
//	//test7();
//	//test9();
//	test10();
//	system("pause");
//	return 0;
//}
