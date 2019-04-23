#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>
#include<stack>
using namespace std;

struct ListNode
{
	int _value;
	ListNode* _next;
};
struct List
{
	ListNode* pHead;
};
void ListInit(List* plist)//初始化链表
{
	plist->pHead = NULL;
	//assert(plist);//判断指针是否为空，指向一个地址
}
void Insert(ListNode** pHead, int value)
{
	ListNode* newnode = new ListNode();
	newnode->_value = value;
	newnode->_next = nullptr;
	if (*pHead == nullptr)
	{
		*pHead = newnode;
	}
	else
	{
		ListNode* cur = *pHead;
		while (cur->_next)
		{
			cur = cur->_next;
		}
		cur->_next = newnode;
	}
}
void Erase(ListNode** pHead, int value)
{
	if (pHead == nullptr || *pHead == nullptr)
		return;
	ListNode* cur = nullptr;
	if ((*pHead)->_value == value)
	{
		cur = *pHead;
		*pHead = (*pHead)->_next;
	}
	else
	{
		ListNode* node = *pHead;
		while (node->_next && node->_next->_value != value)
			node = node->_next;

		if (node->_next && node->_next->_value == value)
		{
			cur = node->_next;
			node->_next = node->_next->_next;
		}
	}
	if (cur != nullptr)
	{
		delete cur;
		cur = nullptr;
	}
}


