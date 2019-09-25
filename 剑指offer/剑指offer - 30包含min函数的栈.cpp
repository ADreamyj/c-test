#define _CRT_SECURE_NO_WARNINGS  1

#pragma once

#include<iostream>
#include<stack>
#include<assert.h>
//题目：定义栈的数据结构，请在该类型中实现一个能够得到栈的最小
//元素的min函数，在该栈中，调用min,push,pop的时间复杂度都为O(1)


template<typename T>
class StackMin
{
public:
	StackMin(){}
	virtual ~StackMin(){}

	T& top();
	const T& top() const;

	void push(const T& value);
	void pop();

	const T& min()const;

	bool empty() const;
	size_t size() const;

private:
	std::stack<T> m_data;	//数据栈，存放栈的所有元素
	std::stack<T> m_min;	//辅助栈，存放栈的最小元素
};

template <typename T>
void StackMin<T>::push(const T& value)
{
	m_data.push(value);

	if (m_min.empty() || m_min.top() > value)
		m_min.push(value);
	else
		m_min.push(m_min.top());
}

template <typename T>
void StackMin<T>::pop()
{
	assert(m_data.size() > 0 && m_min.size() > 0);

	m_data.pop();
	m_mmin.pop();
}

template <typename T> const T& StackMin<T>::min() const
{
	assert(m_data.size() > 0 && m_min.size() > 0);

	return m_min.top();
}

template <typename T> 
T& StackMin<T>::top()
{
	return m_data.top();
}

template <typename T> 
const T& StackMin<T>::top() const
{
	return m_data.top();
}

template <typename T>
bool StackMin<T>::empty() const
{
	return m_data.empty();
}

template <typename T> 
size_t StackMin<T>::size() const
{
	return m_data.size();
}
void Test(const char* testName, const StackMin<int>& stack, int expected)
{
	if (testName != nullptr)
		printf("%s begins: ", testName);

	if (stack.min() == expected)
		printf("Passed.\n");
	else
		printf("Failed.\n");
}
//int main()
//{
//	StackMin<int> stack;
//
//	stack.push(3);
//	Test("Test1", stack, 3);
//
//	stack.push(4);
//	Test("Test2", stack, 3);
//
//	stack.push(2);
//	Test("Test3", stack, 2);
//
//	stack.push(3);
//	Test("Test4", stack, 2);
//	system("pause");
//
//	return 0;
//}