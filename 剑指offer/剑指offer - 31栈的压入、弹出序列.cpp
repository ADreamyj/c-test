#define _CRT_SECURE_NO_WARNINGS  1

#pragma once
#include<iostream>
#include<vector>
#include<stack>

//题目：输入两个整数序列，第一个序列表示栈的压入顺序，请判断第
//二个序列是否为该栈的弹出顺利。假设压入栈的所以数字均不相等。
//例如：序列{1，2，3，4，5}是某个栈的压栈序列，序列{4，5，3，2，1}
//是该压栈序列对应的一个弹出序列，但{4，3，5，1，2}就不可能是
//该压栈序列的弹出序列。



//bool IsPopOrder(std::vector<int> pushV, std::vector<int> popV) 
//{
//	if (pushV.size() == 0) 
//		return false;
//	std::vector<int> stack;
//	for (int i = 0, j = 0; i < pushV.size();i++)
//	{
//		stack.push_back(pushV[i]);
//
//		while (j < popV.size() && stack.back() == popV[j])
//		{
//			stack.pop_back();
//				j++;
//		}
//	}
//	return stack.empty();
//}

bool IsPopOrder2(std::vector<int> pushV, std::vector<int> popV) 
{
	if (pushV.empty() || popV.empty() || pushV.size() != popV.size())
		return false;
	std::stack<int> s;
	int j = 0;
	for (int i = 0; i<pushV.size(); ++i)
	{
		s.push(pushV[i]);
		while (!s.empty() && s.top() == popV[j])
		{
			s.pop();
			++j;
		}
	}
	return s.empty();
}

void Test(const char* testName, std::vector<int> pushV, std::vector<int> popV, int nLength, bool expected)
{
	if (testName != nullptr)
		printf("%s begins: ", testName);

	if (IsPopOrder2(pushV, popV) == expected)
		printf("Passed.\n");
	else
		printf("failed.\n");
}

void Test1()
{
	std::vector<int> pushV = { 1, 2, 3, 4, 5 };
	std::vector<int> popV = { 1,2,3,4,5};

	const int length = 5;
	Test("Test1", pushV, popV, length, true);
}
//int main()
//{
//	Test1();
//	system("pause");
//	return 0;
//}
