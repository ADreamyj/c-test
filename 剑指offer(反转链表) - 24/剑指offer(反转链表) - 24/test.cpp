#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>
using namespace std;

//题目：反转链表 定义一个函数，输入一个链表的头结点，反转
//链表，并且输出反转链表的头结点。链表结点定义如下：
struct ListNode
{
	ListNode * _next;
	int val;
};

//思路：对于这个题而言，在反转链表的时候，需要将反转结点的下一个结点保存
//起来，然后将_next指向前一个结点，这就需要定义一个结点，指向反转结点的
//前一个，然后依次循环，直至链表结束

ListNode* Reverse(ListNode* head)
{
	ListNode* reversenode = head;
	ListNode* node = head;
	ListNode* prev = nullptr;
	while (node)
	{
		ListNode* next = node->_next;
		if (next == nullptr)
			reversenode = node;

		node->_next = prev;
		prev = node;
		node = next;
	}
	return reversenode;
}

int main()
{
	system("pause");
	return 0;
}