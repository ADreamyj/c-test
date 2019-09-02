#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>
#include<vector>

//��Ŀ��������һ��m��n�еķ���һ�������˴����꣨0��0����λ�ÿ�ʼ�ƶ�
//��ÿ�ο��������ң��ϣ����ƶ�һ�񣬵����ܽ�������������������λ
//֮�ʹ���k�ĸ��ӡ����磺��kΪ18��ʱ�򣬻������ܹ����뷽��35��37����
//��Ϊ3 + 5 + 3 + 7 = 18,���������ܽ��뷽��35��38������Ϊ
//3 + 5 + 3 + 9 = 19�����ʸû����˿��Ե�����ٸ����ӣ�


int getnum(int n)
{
	int sum = 0;
	while (n > 0)
	{
		sum += n % 10;
		n /= 10;
	}
	return sum;
}
bool check(int num, int rows, int cols, int row, int col, bool * v)
{
	if (row >= 0 && row < rows && col >= 0 && col < cols
		&& getnum(row) + getnum(col) <= num
		&& !v[row * cols + col])
		return true;
	
	return false;
}

int movingCountCore(int num, int rows, int cols, int row,
	int col, bool*  v)
{
	int count = 0;
	if (check(num, rows, cols, row, col, v))
	{
		v[row * cols + col] = true;
		count = 1 + movingCountCore(num, rows, cols, row + 1, col, v)
			+ movingCountCore(num, rows, cols, row, col + 1, v)
			+ movingCountCore(num, rows, cols, row - 1, col, v)
			+ movingCountCore(num, rows, cols, row, col - 1, v);
	}
	return count;
}
int movingCount(int num, int rows, int cols)
{
	if (num < 0 || rows < 1 || cols < 1)
		return false;

	bool*  v = new bool [rows * cols];
	for (int i = 0; i < rows * cols; ++i)
	{
		v[i] = false;
	}

	int count = movingCountCore(num, rows, cols, 0, 0, v);

	std::cout << count << std::endl;

	delete[]v;
	return count;
}

int main()
{
	int num = 5;
	int rows = 10;
	int cols = 10;
	movingCount(num, rows, cols);
	system("pause");
	return 0;
}
