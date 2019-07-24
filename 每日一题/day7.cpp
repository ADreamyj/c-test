#define _CRT_SECURE_NO_WARNINGS  1


#include<iostream>
#include<string>
#include<stack>
#include<algorithm>
//编程题1：将一个数修改为斐波那契数

//解题思路：将这个数临近的两个斐波那契额数拿出来经过加减分别
//进行比较，哪个数较小，哪个数就是最后的答案。

//int main()
//{
//	int n;
//	int f = 0, f1 = 0, f2 = 1;
//	int r = 0, h = 0;
//	std::cin >> n;
//	while (1)
//	{
//		f = f1 + f2;
//		f1 = f2;
//		f2 = f;
//
//		if (f < n)
//		{
//			r = n - f;
//		}
//		else
//		{
//			h = f - n;
//			break;
//		}
//	}
//	std::cout << std::min(r, h) << std::endl;
//	system("pause");
//	return 0;
//}


//编程题2：合法括号序列判断

//解题思路：用栈存放左括号，当遇到右括号的时候，检查栈中是否有左括号，
//如果有则出栈，如果没有，则说明不匹配。

//class Parenthesis{
//public:
//	bool chkParenthesis(std::string A, int n)
//	{
//		std::stack<char> st;
//		for (auto& i : A)
//		{
//			switch (i)
//			{
//			case'(':
//				st.push(i);
//				break;
//			case')':
//
//			{
//				if (st.empty() || st.top != '(')
//					return false;
//				else
//					st.pop();
//			}
//				break;
//
//			default:
//				return false;
//			}
//		}
//		return true;
//	}
//};