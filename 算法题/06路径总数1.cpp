#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>
#include<vector>

//��Ŀ��·������
//��һ��m*n����������Ͻ���һ�������ˣ����������κ������ֻ������
//���������ƶ�����������Ҫ������������½ǣ��ж�����·����

//��������̬�滮
//״̬��
//		��״̬����(0,0)����(1,0)(1,1)(2,1)...(m - 1,n - 1)��·����
//		F(i,j)����(0,0)����F(i,j)��·����
//״̬�ݹ飺
//		F(i,j) = F(i - 1,j) + F(i,j - 1)
//��ʼ����
//		�����������0�к͵�0��
//		F(0,i) = 1;
//		F(i,0) = 1;
//���ؽ����
//		F(m - 1,n - 1)

int uniquePaths(int m, int n)
{
	if (m < 1 || n < 1)
		return 0;
	std::vector<std::vector<int>> v(m, std::vector<int>(n,1));
	int i;
	int j;
	for ( i = 1; i < m; i++)
	{
		for ( j = 1; j < n; j++)
		{
			v[i][j] = v[i - 1][j] + v[i][j - 1];
		}
	}
	return v[i - 1][j - 1];
}

//int main()
//{
//	std::cout << uniquePaths(3, 3);
//
//	system("pause");
//	return 0;
//}