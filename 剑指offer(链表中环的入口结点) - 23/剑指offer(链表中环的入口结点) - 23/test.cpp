#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>
using namespace std;

//题目:如果一个链表中包含环，如何找到环的入口结点。

//第一步：先判断这个链表中是否有环，定义两个指针，指向头结点
//一个指针每次走一步，另一个指针每次走两步，
//如果快指针追上慢指针，则证明链表有环。

//第二部：计算出环中结点的个数，从相遇的结点出发，如果再回到
//这个结点，计算出每次走的个数n。

//第三部，定义两个指针，指向头结点，第一个指针先走n部，在让第二个
//指针开始走，相交结点就是入口结点。

struct ListNode
{
	ListNode* _next;
	int _val;
};

ListNode* Meet(ListNode* head)
{
	if (head == nullptr)
		return nullptr;

	ListNode* slow = head->_next;
	if (slow == nullptr)
		return nullptr;

	ListNode* fast = slow->_next;
	while (fast && slow)
	{
		if (fast == slow)
			return fast;
		slow = slow->_next;
		fast = fast->_next;
		if (fast != nullptr)
			fast = fast->_next;
	}
	return nullptr;

}
ListNode* Find(ListNode* head)
{
	ListNode* meet = Meet(head);
	if (meet == nullptr)
		return nullptr;

	ListNode* node1 = meet;
	int num = 1;
	while (node1->_next != meet)
	{
		node1 = node1->_next;
		++num;
	}
	node1 = head;
	for (int i = 0; i < num; ++i)
	{
		node1 = node1->_next;
	}
	ListNode* node2 = head;
	while (node1 != node2)
	{
		node1 = node1->_next;
		node2 = node2->_next;
	}
	return node1;
}
int main()
{
	system("pause");
	return 0;
}