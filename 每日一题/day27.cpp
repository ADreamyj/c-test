#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>
using namespace std;

//编程题1：不用加减乘除做加法
//int main()
//{
//	int a, b;
//	while (cin >> a >> b)
//	{
//		while (b)
//		{
//			int num = a^b; //得到相加后不包含进位的数据
//			int carry = (a & b) << 1;//得到两数相加的进位
//			a = num;//两个结果相加，直到进位为0
//			b = carry;
//		}
//		cout << a << endl;
//	}
//	return 0;
//}

//编程题2：三角形
//写法一
//int main()
//{
//	double a, b, c;
//	while (cin >> a >> b >> c)
//	{
//		if (a + b > c && b + c > a && a + c > b)
//		{
//			cout << "Yes" << endl;
//		}
//		else
//			cout << "No" << endl;
//	}
//	return 0;
//}

//写法二
//#define ADD(x, y) ((x)+(y)) 
//#define CMP(x, y) ((x) > (y)) 
//int main() 
//{
//	double a, b, c;  
//	while (std::cin >> a >> b >> c)  
//	{   
//		//对两边进行求和与第三遍进行比较   
//		if (CMP(ADD(a, b), c) &&  CMP(ADD(b, c), a) && CMP(ADD(a, c), b)) 
//		{      
//			std::cout << "Yes" << std::endl; 
//		}
//		else
//		{   
//			std::cout << "No" << std::endl;   
//		}   
//	}   
//	return 0;
//}
