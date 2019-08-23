#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>
#include<vector>

//��Ŀ����һ����ά�����У�ÿһ�ж����մ����ҵ�˳������
//ÿһ�ж����մ��ϵ��µ�����˳�����������һ����������������
//��һ����ά�����һ���������ж��������Ƿ��и�������

//���ⷽ��������������������������˵��ͨ�����Ϊ3����������в���
//1.��������Ҫѡȡ��������Ҫ���ҵ�������ͬʱ���ͽ������ҹ���
//2.���ѡȡ������С��Ҫ���ҵ����ֵ�ʱ���ĸ����־���ѡȡ���ֵ�
//	�ұ߻������±�
//3.���ѡȡ�����ִ���Ҫ���ҵ����ֵ�ʱ����ôҪ���ҵ����־�Ӧ��
//	�ڵ�ǰѡȡ���ֵ��ϱ߻��������

//��׼��ѡȡ���Ͻǵ����֣�

//1.����������ǲ��ҵ����֣�����ҹ��̽���
//2.��������ִ���Ҫ���ҵ����֣����޳�����������ڵ���
//3.���������С��Ҫ���ҵ����֣����޳�����������ڵ���
int Find(std::vector<std::vector<int>> v, int rows, int columns, int number)
{
	bool found = false;
	if (!v.empty() && rows > 0 && columns > 0)
	{
		int row = 0;
		int column = columns - 1;
		while (row < rows && column >= 0)
		{
			if (v[row][column] == number)
			{
				found = true;
				break;
			}
			else if (v[row][column] > number)
				--column;
			else
				++row;
		}
		return found;
	}
}
//int main()
//{
//	std::vector<std::vector<int>> v = { { 1, 2, 8, 9 }, { 2, 4, 9, 12 },
//	{ 4, 7, 10, 13 }, { 6, 8, 11, 15 } };
//	int rows = 4;
//	int columns = 4;
//	int number = 10;
//	std::cout << Find(v, rows, columns, number) << std::endl;
//	system("pause");
//	return 0;
//}




