#define _CRT_SECURE_NO_WARNINGS  1

#pragma once
#include<iostream>
#include<vector>
#include<stack>

//��Ŀ�����������������У���һ�����б�ʾջ��ѹ��˳�����жϵ�
//���������Ƿ�Ϊ��ջ�ĵ���˳��������ѹ��ջ���������־�����ȡ�
//���磺����{1��2��3��4��5}��ĳ��ջ��ѹջ���У�����{4��5��3��2��1}
//�Ǹ�ѹջ���ж�Ӧ��һ���������У���{4��3��5��1��2}�Ͳ�������
//��ѹջ���еĵ������С�



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
