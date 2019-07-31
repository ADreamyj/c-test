#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>
#include<cmath>
#include<algorithm>

//小Q正在攀爬一座高塔，这座宝塔很特别，共有n层，但是每两层之间的净高却不相同
//所有造成了小Q爬过每层的时间也不同，如果某一层的高度为x,那么爬过这一层所用的
//时间也是x，小Q还会用一种魔法，每用一次可以让她直接向上跳一层或者是两层，
//每用一次魔法，都至少爬一层才能使用魔法。

int p[10005], t[10005];
int main()
{
	int n, x;
	while (std::cin >> n)
	{
		for (int i = 1; i <= n; ++i)
		{
			std::cin >> x;
			p[i] = std::min(p[i - 1], t[i - 1]) + x;
			if (i == 1)
				continue;
			t[i] = std::min(p[i - 1], p[i - 2]);
		}
		std::cout << std::min(p[n], t[n]) << std::endl;
	}
		
	return 0;
}