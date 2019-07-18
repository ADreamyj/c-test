#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

//1.编程题1：组队竞赛

//队伍的水平值等于该队伍队员中第二高水平值，为了所有队伍的水平值
//总和最大的解法，也就是说每个队伍 的第二个值是尽可能大的值。
//所以实际值把最大值放到最右边，最小是放到最左边

//int main()
//{
//	std::vector<int> v;
//	int n;
//	
//	while (std::cin >> n)
//	{
//		long long sum = 0;
//		v.resize(3 * n);
//		for (int i = 0; i < 3 * n; ++i)
//		{
//			std::cin >> v[i];
//		}
//		/* 排序，然后取下标为3n - 2，3n - 4 ，3n - 4... n+2，
//		n位置的元素累加即可,相当下标为[0,n-1]的n个数做每组的最
//		左边的数，剩下的2个数据两个为一组，
//		大的值做最右边的数，次大的做中间值，
//		这里就是把这个次大的值加起来       
//		*/
//		std::sort(v.begin(), v.end());
//		for (int j = n; j <= 3 * n - 2; j += 2)
//		{
//			sum += v[j];
//		}
//		std::cout << sum << std::endl;
//	}
//	return 0;
//}

//编程题2：删除公共字符串

int main()
{
	std::string s1;
	std::string s2;
	std::getline(std::cin, s1);
	std::getline(std::cin, s2);

	int v[256] = { 0 };
	for (int i = 0; i < s2.size(); ++i)
	{
		v[s2[i]]++;
	}

	std::string ret;
	for (int j = 0; j < s1.size(); ++j)
	{
		if (v[s1[j]] == 0)
			ret += s1[j];
	}

	std::cout << ret << std::endl;
	system("pause");
	return 0;
}