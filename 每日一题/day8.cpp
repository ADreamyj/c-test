#define _CRT_SECURE_NO_WARNINGS  1


#include<iostream>
#include<string>
#include<vector>

//编程题1：两种排序方法

//int main()
//{
//	int n;
//	std::cin >> n;
//	std::vector<std::string> v;
//	v.resize(n);
//	for (int i = 0; i < n; ++i)
//	{
//		std::cin >> v[i];
//	}
//	
//	bool flag1 = true;
//	bool flag2 = true;
//
//	//比较字符串的长度
//	for (size_t j = 1; j < n; ++j)
//	{
//		if (v[j - 1].size() >= v[j].size())
//		{
//			flag1 = false;
//			break;
//		}
//	}
//
//	//比较字符串的大小
//	for (size_t k = 1; k < n; ++k)
//	{
//		if (v[k - 1] >= v[k])
//		{
//			flag2 = false;
//			break;
//		}
//	}
//
//	if (flag1 && flag2)
//		std::cout << "both" << std::endl;
//	else if (flag1 && !flag2)
//		std::cout << "lengths" << std::endl;
//	else if (!flag1 && flag2)
//		std::cout << "lexicographically" << std::endl;
//	else if (!flag1 && !flag2)
//		std::cout << "none" << std::endl;
//	system("pause");
//	return 0;
//}

//编程题2：最小公倍数
//
//int git(int a, int b)
//{
//	int c;
//	while (c = a % b)
//	{
//		a = b;
//		b = c;
//	}
//	return b;
//}
//int main()
//{
//	int a, b;
//	while (std::cin >> a >> b)
//	{
//		std::cout << a * b / git(a, b) << std::endl;
//	}
//	system("pause");
//	return 0;
//}