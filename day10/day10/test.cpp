#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>
#include<vector>
using namespace std;
//1.井字棋，判断当前玩家是否获胜
class Board {
public:
	bool checkWon(vector<vector<int> > a) {
		if (a[0][0] + a[1][1] + a[2][2] == 3)
			return true;
		if (a[0][2] + a[1][1] + a[2][0] == 3)
			return true;
		for (int i = 0; i < 3; ++i)
		{
			if (a[i][0] + a[i][1] + a[i][2] == 3)
				return true;
			if (a[0][i] + a[1][i] + a[2][i] == 3)
				return true;
		}
		return false;
	}
};
//2.密码强度等级
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int  get(string str)
{
	int sum = 0, a1 = 0, a2 = 0, a3 = 0, a4 = 0, a5 = 0;
	vector<char> s1, s2, s3, s4;

	int len = str.size();
	if (len <= 4)
		a1 = 5;
	else if (len >= 8)
		a1 = 25;
	else
		a1 = 10;

	for (int i = 0; i < len; i++)
	{
		if (str[i] <= 'z' && str[i] >= 'a')
			s1.push_back(str[i]);
		else if (str[i] <= 'Z' && str[i] >= 'A')
			s2.push_back(str[i]);
		else if (str[i] <= '9' && str[i] >= '0')
			s3.push_back(str[i]);
		else
			s4.push_back(str[i]);
	}
	int l1 = s1.size(), l2 = s2.size(), l3 = s3.size(), l4 = s4.size();

	if (l1 != 0 && l2 != 0)
		a2 = 20;
	else if (l1 == 0 && l2 == 0)
		a2 = 0;
	else
		a2 = 10;

	if (l3 == 0)
		a3 = 0;
	else if (l3 == 1)
		a3 = 10;
	else
		a3 = 20;

	if (l4 == 0)
		a4 = 0;
	else if (l4 == 1)
		a4 = 10;
	else
		a4 = 25;

	if (l1&&l2&&l3&&l4)
		a5 = 5;
	else if ((l1 || l2) && l3 && l4)
		a5 = 3;
	else if ((l1 || l2) && l3)
		a5 = 2;
	else
		a5 = 0;

	sum = a1 + a2 + a3 + a4 + a5;
	return sum;
}
int main()
{
	string str;
	while (cin >> str)
	{
		int sum = get(str);
		switch (sum / 10)
		{
		case 9:
			cout << "VERY_SECURE" << endl; break;
		case 8:
			cout << "SECURE" << endl; break;
		case 7:
			cout << "VERY_STRONG" << endl; break;
		case 6:
			cout << "STRONG" << endl; break;
		case 5:
			cout << "AVERAGE" << endl; break;
		default:
		{
				   if (sum >= 25)
					   cout << "WEAK" << endl;
				   else
					   cout << "VERY_WEAK" << endl;
		}
		}

	}
	return 0;
}