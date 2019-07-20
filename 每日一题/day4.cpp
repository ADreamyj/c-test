#define _CRT_SECURE_NO_WARNINGS  1


#include<iostream>
#include<string>
#include<algorithm>

//编程题1：计算糖果

//四个人手中的糖果的数量分别是A - B;B - C;A + B;B + C
//所以	a = (1 + 3)/2
//		c = (4 - 2)/2;
//		b1 = (3 - 1)/2;
//		b2 = (2 + 4)/2;
//int main()
//{
//	int a, b, c, d;
//	std::cin >> a >> b >> c >> d;
//	int A = (a + c) / 2;
//	int C = (d - b) / 2;
//	int B1 = (c - a) / 2;
//	int B2 = (b + d) / 2;
//	if (B1 != B2)
//		std::cout << "No" << std::endl;
//	else
//		std::cout << A << " " << B1 << " " << C << std::endl;
//	system("pause");
//	return 0;
//}

//编程题2：将十进制转化为n进制

//int main()
//{
//	int a,b;
//	std::string table = "0123456789ABCDEF";
//	std::cin >> a >> b;
//	int flag = false;
//
//	std::string ret;
//
//	if (a < 0)
//	{
//		flag = true;
//		a = 0 - a;
//	}
//	while (a)   
//	{
//		ret += table[a%b];  
//		a /= b;
//	}
//	if (flag)
//	{
//		ret += '-';
//	}
//	
//	std::reverse(ret.begin(), ret.end());
//	std::cout << ret << std::endl;
//	system("pause");
//	return 0;
//}