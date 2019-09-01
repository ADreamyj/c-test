#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>
#include<vector>

//���������Ѷȵ���Ŀ��
//�����һ���������ж�һ���������Ƿ����һ������ĳ�ַ��������ַ���·��
//·�����Դ��ַ���������һ��ʼ��ÿһ�������ھ����������ϣ��£���
//�����ƶ�һ�����һ��·�����������е�ĳһ������ô�Ͳ����ظ����롣

//a	  b	  t	  g	
//c	  f	  c	  s
//j	  d	  e	  h

//�����ھ���������ѡȡһ��������Ϊ��㡣���������ĳ�����ӵ��ַ�Ϊch��
//����������Ӷ�Ӧ��·���ϵĵ�i���ַ������·���ϵĵ�i���ַ�����ch��
//��ô������Ӳ����ܴ���·���ĵ�i��λ���ϡ����·���ĵ�i���ַ�ǡ����ch��
//��ô�����ڵĸ�����Ѱ�ҵ�i+1���ַ����ظ��������ֱ��·���ϵ������ַ�
//���ھ������ҵ���Ӧ��λ�á�
//���ڻ��ݷ��ĵݹ����ԣ�·�����Ա�����һ��ջ��



bool hasPathCore(std::vector<std::vector<char>> v1, int dex, int row,
	int col, std::vector<char> v2, std::vector<std::vector<bool>> v)
{
	if (dex == v2.size())
		return true;

	int rows = v1.size(), cols = v1[0].size();

	if (row < 0 || col < 0 || row >= rows || col >= cols
		|| v[row][col] || v1[row][col] != v2[dex])
		return false;

	v[row][col] = true;
	bool flag = hasPathCore(v1, dex + 1, row, col - 1, v2, v)
		|| hasPathCore(v1, dex + 1, row + 1, col, v2, v)
		|| hasPathCore(v1, dex + 1, row, col + 1, v2, v)
		|| hasPathCore(v1, dex + 1, row - 1, col, v2, v);

	v[row][col] = false;
	return flag;
}
bool hasPath(std::vector<std::vector<char>> v1, int rows, int cols, std::vector<char> v2)
{
	if (v1.empty() || rows < 1 || cols < 1 || v2.empty())
	{
		return false;
	}

	std::vector<std::vector<bool>> v(rows, std::vector<bool>(cols,0));

	int pathlength = 0;
	for (int row = 0; row < rows; ++row)
	{
		for (int col = 0; col < cols; ++col)
		{
			if (hasPathCore(v1, 0, row, col, v2,  v))
				return true;
		}
	}
	return false;
}
int main()
{
	std::vector<std::vector<char>> v1 = { { 'a','b','t','g'}, 
	{'c','f','c','s'}, {'j','d','e','h'} };
	int rows = v1.size(), cols = v1[0].size();
	std::vector<char> v2 = {'b', 'f', 'c', 'e' };
	std::cout << hasPath(v1, rows, cols, v2) << std::endl;
	system("pause");
	return 0;
}