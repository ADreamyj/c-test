#define _CRT_SECURE_NO_WARNINGS  1


#include<iostream>
#include<vector>
//��Ŀ����ת��������С������

//��һ�������ʼ�����ɸ�Ԫ�ذᵽ�����ĩβ�����ǳ�֮Ϊ�������ת��
//����һ����������������һ����ת�������ת�������СԪ�أ�
//���磺����{3��4��5��1��2}Ϊ{1��2��3��4��5}��һ����ת�����������С
//ֵΪ1

//����˼·�������������˵������ð�˳����ҵĻ���ʱ�临�Ӷ���O(n);

//���Կ���ʹ�ö��ֲ��ҵķ�������������ָ�룬һ��ָ��begin��
//һ��ָ��end��һ��ָ��mid��Ȼ��Ͱ���������˳��������

//���������begin == end && begin == mid
//������������������˵���ͱ���ʹ�ð�˳����ҵķ���

int Minsort(std::vector<int> v, int begin, int end)
{
	int result = v[begin];
	for (int i = begin + 1; i <= end; ++i)
	{
		if (result < v[i])
			result = v[i];
	}
	return result;
}
int Min(std::vector<int> v, int length)
{
	if (v.empty()|| length <= 0)
		return -1;

	int begin = 0;
	int end = length - 1;
	int mid = begin;
	while (v[begin] >= v[end])
	{
		if (end - begin == 1)
		{
			mid = end;
			break;
		}
		mid = (end + begin )/ 2;

		if (v[begin] == v[end] && v[begin] == v[mid])
			return Minsort(v, begin, end);

		if (v[begin] <= v[mid])
			begin = mid;
		else if (v[mid] <= v[end])
			end = mid;
		
	}
	return v[mid];
}

//int main()
//{
//	std::vector<int> v = { 1, 2, 1, 2, 3 };
//	int length = 5;
//	std::cout << Min(v, length) << std::endl;
//	system("pause");
//	return 0;
//}