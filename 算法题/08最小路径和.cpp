#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>
#include<vector>
#include<algorithm>
//��Ŀ������һ��m*n�����������÷Ǹ�����䣬�ҵ�һ�������Ͻǵ����½�
//�����·����ÿ��ֻ�����ϻ����������˶�

//��������̬�滮
//״̬��
//		��״̬����(0,0)����(1,0),(1,1)....(m - 1,n - 1)�����·��
//		F(i,j)����(0,0)����F(i,j)�����·��
//״̬�ݹ飺
//		F(i,j) = min{F(i - 1 , j) , F(i,j - 1)} + (i,j);
//��ʼ����
//		F(0,0) = (0,0)
//		�����������0�к͵�0��
//		F(0,i) = F(0,i - 1) + (0,i)
//		F(i,0) = F(i - 1,0) + (i,0)
//���ؽ����
//		F(m - 1,n - 1)

int minPathSum(std::vector<std::vector<int>> &grid)
{
	if (grid.empty() || grid[0].empty())
		return 0;
	
	int m = grid.size();
	int n = grid[0].size();
	std::vector<std::vector<int>> v(m, std::vector<int>(n, 0));

	//F(0,0) F(i,0) �� F(0,i)���г�ʼ��
	v[0][0] = grid[0][0];
	for (int i = 1; i < m; i++)
	{
		v[i][0] = grid[i][0] + v[i - 1][0];
	}

	for (int j = 1; j < n; j++)
	{
		v[0][j] = grid[0][j] + v[0][j - 1];
	}
	
	// F(i,j) = min{F(i-1,j) , F(i,j-1)} + (i,j)
	for (int i = 1; i < m; ++i)
	{
		for (int j = 1; j < n; ++j)
		{
			v[i][j] = std::min(v[i - 1][j], v[i][j - 1]) + grid[i][j];
		}
	}

	return v[m - 1][n - 1];
}
//int main()
//{
//	std::vector<std::vector<int>> v{ { 1, 1, 1 }, { 2, 2, 2 }, { 1, 1, 1 } };
//	std::cout << minPathSum(v) << std::endl;
//	system("pause");
//	return 0;
//}