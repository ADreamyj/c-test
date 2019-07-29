#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>
#include<string>

//编程题1：NowCoder每天要给许多客户写电子邮件。
//正如你所知，如果一封邮件中包含多个收件人，收件人姓名之间 
//会用一个逗号和空格隔开；如果收件人姓名也包含空格或逗号，
//则姓名需要用双引号包含。
//现在给你一组收件人姓名，请你帮他生成相应的收件人列表。

//输入 3 
//Joe Quan, 
//William Letendre,
//Bruce

//输出
//Joe, "Quan,William", "Letendre,Bruce"

//int main()
//{
//	int n;
//	while (std::cin >> n)
//	{
//		std::cin.get();//处理回车
//		std::string s;
//		for (int i = 0; i < n; ++i)
//		{
//			getline(std::cin, s);
//			bool flag = false;
//
//			if (s.find(' ') != -1 || s.find(',') != -1)
//			{
//				flag = true;
//			}
//
//			if (flag)
//			{
//				std::cout << '\"' << s << '\"' << std::endl;
//			}
//			else
//			{
//				std::cout << s;
//			}
//
//			if (i < n - 1)
//				std::cout << ", ";
//		}
//		std::cout << std::endl;
//	}
//	system("pause");
//	return 0;
//}

//编程题2：养兔子

//一只成熟的兔子每天能产下一胎兔子。每只小兔子的成熟期是一天。
//某人领养了一只小兔子，请问第N天以 后，他将会得到多少只兔子。


//解题思路：这个题很像斐波那契数列 1 1 2 3 5 8 13 21...
//本题的兔子第二天就开始下小兔了，所以这个是从第二项开始的斐波那契数列。
//前90组的数据恰好还在 long long的范围内，所以不需要高精度，
//直接long long求

//int main()
//{
//	long long  v[90] = { 1, 2 };
//	for (int i = 2; i <= 90; ++i)
//	{
//		v[i] = v[i - 1] + v[i - 2];
//	}
//	int n;
//	while (std::cin >> n)
//	{
//		printf("%lld\n", v[n - 1]);
//	}
//	system("pause");
//	return 0;
//}
