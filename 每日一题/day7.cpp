#define _CRT_SECURE_NO_WARNINGS  1


#include<iostream>
#include<string>
#include<stack>
#include<algorithm>
//�����1����һ�����޸�Ϊ쳲�������

//����˼·����������ٽ�������쳲����������ó��������Ӽ��ֱ�
//���бȽϣ��ĸ�����С���ĸ����������Ĵ𰸡�

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


//�����2���Ϸ����������ж�

//����˼·����ջ��������ţ������������ŵ�ʱ�򣬼��ջ���Ƿ��������ţ�
//��������ջ�����û�У���˵����ƥ�䡣

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