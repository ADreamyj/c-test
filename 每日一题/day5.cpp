#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>
#include<string>
#include<vector>

//�����1��ͳ�ƻ���

//��B�ַ������β���A�ַ����У��ж�A�ַ����Ƿ���ġ�

//int isprime(std::string s)
//{
//	int begin = 0;
//	int end = s.size() - 1;
//	while (begin < end)
//	{
//		if (s[begin] != s[end])
//			return false;
//
//		++begin;
//		--end;
//	}
//	return true;
//}
//int main()
//{
//	std::string str1, str2;
//	getline(std::cin, str1);
//	getline(std::cin, str2);
//	int count = 0;
//	for (int i = 0; i <= str1.size(); ++i)
//	{
//		std::string s = str1;
//		s.insert(i, str2);
//		if (isprime(s))
//			count++;
//	}
//	std::cout << count << std::endl;
//	system("pause");
//	return 0;
//}


//�����2����������������

int main()
{
	int n;
	std::cin >> n;
	std::vector<int> v(n);
	int sum = 0, max = 0;
	for (int i = 0; i < n; i++)
	{
		std::cin >> v[i];
		sum += v[i];
		if (sum > max)
			max = sum;
		if (sum < 0)
			sum = 0;
	}
	std::cout << max << std::endl;
	system("pause");
	return 0;
}