#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>
#include<cmath>
#include<algorithm>

//СQ��������һ�������������������ر𣬹���n�㣬����ÿ����֮��ľ���ȴ����ͬ
//���������СQ����ÿ���ʱ��Ҳ��ͬ�����ĳһ��ĸ߶�Ϊx,��ô������һ�����õ�
//ʱ��Ҳ��x��СQ������һ��ħ����ÿ��һ�ο�������ֱ��������һ����������㣬
//ÿ��һ��ħ������������һ�����ʹ��ħ����

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