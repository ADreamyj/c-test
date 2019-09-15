#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>
#include<vector>
//��Ŀ������һ���������飬ʵ��һ���������������������е�˳��
//ʹ�����е�����λ�������ǰ�벿�֣�����ż��λ������ĺ�벿�֡�

//����˼·��
//������ָ�룬һ��ָ��ָ������ĵ�һ�����֣���ֻ����ƶ���
//��һ��ָ��ָ����������һ�����֣���ֻ��ǰ�ƶ���
//������ָ������֮ǰ����һ��ָ������λ�ڵڶ���ָ���ǰ��
//�����һ��ָ��ָ�����ż�������ҵڶ���ָ��ָ�����������
//�򽻻�������ָ�롣

void ReorderOddEven(std::vector<int> &v)
{
	if (v.size() == 0)
		return;

	int size = v.size();
	int begin = 0;
	int end = size - 1;
	while (begin < end)
	{
		while (begin < end && (v[begin] & 0x1) != 0)
			begin++;
		while (begin < end && (v[end] & 0x1) == 0)
			end--;
		if (begin < end)
		{
			int temp = v[begin];
			v[begin] = v[end];
			v[end] = temp;
		}
	}
	
}
void Print(std::vector<int> v)
{
	for (int i = 0; i < v.size(); i++)
	{
		std::cout << v[i] << " ";
	}
	std::cout << std::endl;
}


//��չ
//�������Ŀ�ĳɰ������е������մ�С��Ϊ�����֣����еĸ������ڷǸ�����ǰ��
//�������Ŀ�ĳɰ������е��������ܷ���������Ϊ������
//��������
//�������������⣬���Թ���Ҫ�������

//�ص�����

void Reorder(std::vector<int> &v, bool(*fun)(int));
bool isEven(int n)
{
	return (n & 1) == 0;
}
void ReorderOddEven2(std::vector<int> &v)
{
	Reorder(v, isEven);
}
void Reorder(std::vector<int> &v, bool (*fun)(int))
{
	if (v.size() == 0)
		return;

	int size = v.size();
	int begin = 0;
	int end = size - 1;
	while (begin < end)
	{
		while (begin < end && !fun(v[begin]))
			begin++;
		while (begin < end &&  fun(v[end]))
			end--;
		if (begin < end)
		{
			int temp = v[begin];
			v[begin] = v[end];
			v[end] = temp;
		}
	}

}
int main()
{
	std::vector<int> v = { 2, 4, 6, 8, 1, 3, 5, 7 };
	ReorderOddEven2(v);
	Print(v);
	system("pause");
	return 0;
}