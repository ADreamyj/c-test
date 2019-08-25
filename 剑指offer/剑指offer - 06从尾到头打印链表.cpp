#define _CRT_SECURE_NO_WARNINGS  1


#include<iostream>
#include<stack>

//题目：从尾到头打印链表
//输入宇哥链表的头结点，从尾到头反过来打印链表中的每一个结点的值

struct ListNode
{
	int _value;
	ListNode* _next;
};

//方法1：如果不改变链表的结构的话，可以用栈来实现
//将每一个结点存入栈中，然后再将结点打印出来。

void Print1(ListNode* head)
{
	std::stack<ListNode*> st;

	ListNode* cur = head;
	while (cur != nullptr)
	{
		st.push(cur);
		cur = cur->_next;
	}

	while (!st.empty())
	{
		cur = st.top();
		std::cout << cur->_value << " ";
		st.pop();
	}
}

//方法2：递归的输出每一个结点

void Print2(ListNode* head)
{
	if (head != nullptr)
	{
		if (head->_next != nullptr)
		{
			Print2(head->_next);
		}
		std::cout << head->_value << " ";
	}
}
//int main()
//{
//	system("pause");
//	return 0;
//}