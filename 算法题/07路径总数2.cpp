#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>
#include<vector>

//��Ŀ������
//		�����˴�����������Ͻ��ߵ������½ǣ��������������ϰ���
//		�ϰ�����1�����б�ʾ��

//��������̬�滮
//״̬��
//		��״̬����(0,0)����(1,0),(1,1)...(m - 1)(n - 1)��·����
//		F(i,j)����(0,0)����F(i,j)��·����
//״̬�ݹ飺
//		F(i,j) = {F(i - 1,j) + F(i,j - 1)} or
//				{0,if obstacleGrid(i,j) = 1}
//��ʼ����
//		�����������0�к͵�0��
//		F(0,i) = {1} or {0, if obstacleGrid(0,j) = 1 , j <= i}
//		F(i,0) = {1} or {0, if obstaclegrid(j,0) = 1 , j <= i}
//���ؽ����
//		F(m - 1,n - 1)

int uniquePathsWithObstacles(std::vector<std::vector<int> > &obstacleGrid)
{
	if (obstacleGrid.empty() || obstacleGrid[0].empty())
	{
		return 0;
	}
	// ����F(i,j)�ռ䣬��ʼֵΪ0
	int m = obstacleGrid.size();
	int n = obstacleGrid[0].size();
	std::vector<std::vector<int>> v(m, std::vector<int>(n, 0));

	for (int i = 0; i < m; i++)
	{// ��0����ֻҪǰ�����ϰ������涼�޷�����
		if (obstacleGrid[i][0] != 1)
			v[i][0] = 1;
		else
			break;
	}

	for (int i = 0; i < n; i++)
	{// ��0����ֻҪǰ�����ϰ������涼�޷�����
		if (obstacleGrid[0][i] != 1)
			v[0][i] = 1;
		else
			break;
	}

	for (int i = 1; i < m; i++)
	{
		for (int j = 1; j < n; j++)
		{// obstacleGrid[i][j] = 1 ʱ��F(i,j)�޷�����
			if (obstacleGrid[i][j] == 1)
				v[i][j] = 0;
			else
				//F(i,j) = F(i-1,j) + F(i,j-1)
				v[i][j] = v[i - 1][j] + v[i][j - 1];
		}
	}

	return v[m - 1][n - 1];
}

//int main()
//{
//	std::vector<std::vector<int>> v{ { 1, 0, 0 }, { 0, 1, 0 }, { 0, 0, 0 } };
//	std::cout << uniquePathsWithObstacles(v) << std::endl;
//	system("pause");
//	//return 0;
//}