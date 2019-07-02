#define _CRT_SECURE_NO_WARNINGS  1


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


//编程题1：年终奖

class Bonus {
public:
	int getMost(vector<vector<int> > board) {
		int length = board.size();
		int width = board[0].size();

		//给二维数组开空间；

		//方法1
		vector<vector<int>> v(length, vector<int>(width,0));

		//方法2
		for (int i = 0; i < length; i++) 
		{ 
			vector<int> tmp(width, 0);
			v.push_back(tmp);
		}


		v[0][0] = board[0][0];
		for (int i = 0; i < length; ++i)
		{
			for (int j = 0; j < width; ++j)
			{
				if (i == 0 && j == 0)
				{
					continue;
				}
				else if (i == 0)
				{
					v[i][j] = v[i][j - 1] + board[i][j];
				}
				else if (j == 0)
				{
					v[i][j] = v[i - 1][j] + board[i][j];
				}
				else
				{
					v[i][j] = max(v[i - 1][j], v[i][j - 1]) + board[i][j];
				}
			}
		}
		return v[length - 1][width - 1];
	}
};

int m, n;
vector<vector <int>>v;
vector<vector <int>>temp;
vector<vector <int>>past;
void MazeTrack(int i,int j)
{
	v[i][j] = 1;
	temp.push_back({ i, j });
	if (m == i - 1 && n == j - 1)
	{
		if (past.empty == 0 || past.size() > temp.size())
		{
			past = temp;
		}
	}
	
	if (i - 1 >= 0 && v[i - 1][j] == 0)
		MazeTrack(i - 1, j);
	if (i <= n && v[i + 1][j] == 0)
		MazeTrack(i + 1, j);
	if (j - 1 >= 0 && v[i][j - 1] == 0)
		MazeTrack(i, j - 1);
	if (j <= m && v[i][j + 1] == 0)
		MazeTrack(i, j + 1);

	temp[i][j] = 0;
	temp.pop_back();
}
int main()
{
	while (cin >> m >> n)
	{
		v = vector<vector <int>>(m, vector<int>(n, 0));
		for (auto &i : v)
			for (auto &j : i)
			cin >> j;
		MazeTrack(0, 0);//回溯寻找迷宫最短通路   
		for (auto i : past)
			cout << '(' << i[0] << ',' << i[1] << ')' << endl;//输出通路 
	}
	system("pause");
	return 0;
}