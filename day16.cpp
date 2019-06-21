#define _CRT_SECURE_NO_WARNINGS  1


#include<iostream>
using namespace std;

//int main()
//{
//	int i = 3;
//	printf("%d %d %d", ++i, ++i, i++);
//	system("pause");
//	return 0;
//}

//int i = 1;
//class widget
//{
//public:
//	widget()
//	{
//		cout << "init()" << endl;
//	}
//	widget(const widget&)
//	{
//		cout << i++ << "---copy init" << endl;
//	}
//	
//};
//widget f(widget u)
//{
//	widget v(u);
//	widget w = v;
//	return w;
//}
//int main()
//{
//	widget x;
//	widget y = f(f(x));
//	system("pause");
//	return 0;
//}

//编程题1：完全数
bool check(int date)
{
	int sum = 0;
	int sq = sqrt(date);
	for (int i = 2; i <= sq; ++i)
	{
		if (date%i == 0)
		{
			if (date / i == i)
				sum += i;
			else
				sum += i + (date / i);
		}
	}
	if (sum + 1 == date)
		return true;
	return false;
}

int main()
{
	int a;
	while (cin >> a)
	{
		int ret = 0;
		for (int i = 2; i <= a; i++)
		{
			if (check(i))
				ret++;
		}
		cout << ret << endl;
	}

	system("pause");
	return 0;
}