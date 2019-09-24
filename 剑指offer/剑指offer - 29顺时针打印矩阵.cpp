#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>
#include<vector>
//��Ŀ������һ�����󣬰��մ���������˳ʱ���˳�����δ�ӡ��ÿһ�����֡�
//���磬�����������
//1		2	3	4
//5		6	7	8
//9		10	11	12
//13	14	15	16

//����˼·���������ܿ������ǳ��ļ򵥣�����Ҫ�ж��ܶ�ı߽�������
//	 - - - -
//	|		|
//	|		|
//	  - - - |

//��ͼ��ʽ�����ǿ��Կ���ÿһȦ���Ͻǵ������к��ж�����ͬ�����֡�
//���ǣ����Եó����Ͻ�Ϊ���Ƿ�����Ŀ�ꡣ

//����һ��5*5�ľ�����˵�����һȦֻ��һ�����֣���Ӧ������Ϊ��2��2��
//���Ƿ���5 > 2*2��Ȼ���������������ľ���Ҳ����ˡ�
//���ǣ����ǿ��Եó�ѭ��������������columns > startX*2
//����rows > startY*2��

void PrintCircle(int** numbers, int columns, int rows, int start);
void Print(int** numbers, int columns, int rows)
{
	if (numbers == 0 || columns < 0 || rows < 0)
		return;

	int start = 0;
	while (columns > start * 2 && rows > start * 2)
	{
		PrintCircle(numbers, columns, rows, start);
		++start;
	}
}

void PrintCircle(int** numbers, int columns, int rows, int start)
{
	int x = columns - 1 - start;
	int y = rows - 1 - start;

	for (int i = start; i <= x; ++i) //�����Ҵ�ӡһ��
	{
		int number = numbers[start][i];
		std::cout << number << " ";
	}

	if (start < y)//���ϵ��´�ӡһ��
	{
		for (int i = start + 1; i <= y; i++)
		{
			int number = numbers[i][x];
			std::cout << number << " ";
		}
	}

	if (start < x && start < y)//���ҵ����ӡһ��
	{
		for (int i = x - 1; i >= start; --i)
		{
			int number = numbers[y][i];
			std::cout << number << " ";
		}
	}

	if (start < x && start < y - 1)//���µ��ϴ�ӡһ��
	{
		for (int i = y - 1; i >= start+1; --i)
		{
			int number = numbers[i][start];
			std::cout << number << " ";
		}
	}
}

void Test(int columns, int rows)
{
	printf("Test Begin: %d columns, %d rows.\n", columns, rows);

	if (columns < 1 || rows < 1)
		return;

	int** numbers = new int*[rows];
	for (int i = 0; i < rows; ++i)
	{
		numbers[i] = new int[columns];
		for (int j = 0; j < columns; ++j)
		{
			numbers[i][j] = i * columns + j + 1;
		}
	}

	Print(numbers, columns, rows);
	printf("\n");

	for (int i = 0; i < rows; ++i)
		delete[](int*)numbers[i];

	delete[] numbers;
}
//int main()
//{
//	Test(4, 4);
//	system("pause");
//}
