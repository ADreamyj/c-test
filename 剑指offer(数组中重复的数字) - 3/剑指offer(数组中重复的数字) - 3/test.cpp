#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//��Ŀһ���ҳ��������ظ�������
//��һ������Ϊn���������������ֵķ�Χ����0~n-1�ķ�Χ�ڡ�������ĳ��
//�������ظ��ģ����ǲ�֪���м����������ظ����ˣ�Ҳ��֪��ÿ������
//�ظ��˼��Ρ����ҳ�����������һ���ظ������֡�

//���磬����������Ϊ7������{2��3��1��0��2��5��3}����ô��Ӧ������
//���ظ�������2����3

//�����������ԣ������Ҫ���ʱ�䣬�ռ��Ч�ʡ�
//ʱ�临�Ӷ�ΪO(n),�ռ临�Ӷ�Ϊo(1);

//ֻ�ҳ�һ����ͬ����
bool duplicate1(int number[], int length)
{
	if (number == nullptr || length < 0)
	{
		return false;
	}
	for (int i = 0; i < length; ++i)
	{
		if (number[i] < 0 || number[i] > length)
			return false;
	}

	for (int i = 0; i < length; ++i)
	{
		while (number[i] != i)
		{
			if (number[i] == number[number[i]])
			{
				//*duplication = number[i];
				cout << number[i] << endl;
				return number[i];
			}
			else
			{
				int temp = number[i];
				number[i] = number[temp];
				number[temp] = temp;
			}
			
		}
	}
	return false;
}

//int main()
//{
//	int number[] = { 2, 3, 1, 0, 2, 5, 3 };
//	int length = sizeof(number) / sizeof(number[0]);
//	
//	duplicate1(number, length);
//	system("pause");
//	return 0;
//}

bool duplicate2(int number[], int length,vector<int> duplication)
{
	if (number == nullptr || length < 0)
	{
		return false;
	}
	for (int i = 0; i < length; ++i)
	{
		if (number[i] < 0 || number[i] > length)
			return false;
	}

	sort(number, number + length);
	int k = 0, j = 0;
	//�������е�k��λ�ú͵�j+1��λ�õ�������ȣ�ֻ����number[k] <= number[j + 1]
	while (k < length - 1 && j < length - 1)
	{
		//number[k] < number[j + 1]��ʱ��ֻ�����������k == j��k < j
		if (number[k] < number[j + 1])
		{
			if (k == j)
			{
				k++;
				j++;
			}
			//k<jʱ������k+1
			else
			{
				k++;
			}
		}
		//number[k] = number[j + 1],�Ͱ�number[k]���뵽�����У�������ֶ�ε������ظ�����
		else
		{
			//cout << "�ظ�����Ϊ" << number[k] << endl;    
			duplication.push_back(number[k]);
			j++;
		}
	}
	
	vector<int>::iterator it;
	for (it = duplication.begin(); it != duplication.end(); it++)  //ʹ�õ������Լ��Ͻ��б���
	{
		cout << *it << endl;
	}
	return false;
}

//int main()
//{
//	int number[] = { 2, 3, 1, 0, 2, 5, 3 };
//	int length = sizeof(number) / sizeof(number[0]);
//	vector<int> duplication;
//	duplicate2(number, length,duplication);
//	system("pause");
//	return 0;
//}


