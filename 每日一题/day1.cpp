#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

//1.�����1����Ӿ���

//�����ˮƽֵ���ڸö����Ա�еڶ���ˮƽֵ��Ϊ�����ж����ˮƽֵ
//�ܺ����Ľⷨ��Ҳ����˵ÿ������ �ĵڶ���ֵ�Ǿ����ܴ��ֵ��
//����ʵ��ֵ�����ֵ�ŵ����ұߣ���С�Ƿŵ������

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
//		/* ����Ȼ��ȡ�±�Ϊ3n - 2��3n - 4 ��3n - 4... n+2��
//		nλ�õ�Ԫ���ۼӼ���,�൱�±�Ϊ[0,n-1]��n������ÿ�����
//		��ߵ�����ʣ�µ�2����������Ϊһ�飬
//		���ֵ�����ұߵ������δ�����м�ֵ��
//		������ǰ�����δ��ֵ������       
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

//�����2��ɾ�������ַ���

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