#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>

//题目：链表中环的入口结点
//如果一个链表中包含环，如何让找出环的入口结点？
//例如：在如下的链表中环的入口结点是3；
//1 -> 2 -> 3 -> 4 -> 5 -> 6
//			|				|
//			-----------------	


//解题思路：
//1.先判断链表中是否有环，我们可以定义两个指针，同时从链表的头结点出发
//一个指针一次走一步，另一个指针一次走两步。如果快指针追上了走的慢的指针
//那么链表中就有环。如果走的快的指针走到了链表的末尾都没有追上第一个指针，
//那么链表就没有环。

//2.找环的入口，也是定义两个指针p1和p2指向链表的头结点，
//如果链表中的环有n个结点，则指针p1先在链表上向前移动n步，
//然后两个指针以相同的速度向前移动，当第二个指针指向环的入口结点的时候
//第一个指针已经围绕着环走了一圈，又回到了入口结点。


struct ListNode
{
	int _val;
	ListNode * _next;
	ListNode (int val)
		: _val(val)
		, _next(nullptr)
	{}
};

//判断是否有环
ListNode * MeetingNode(ListNode* head)
{
	if (head == nullptr)
		return nullptr;

	ListNode* slow = head->_next;
	if (slow == nullptr)
		return nullptr;

	ListNode* fast = slow->_next;
	while (slow && fast)
	{
		if (fast == slow)
			return fast;

		slow = slow->_next;
		fast = fast->_next;
		if (fast)
			fast = fast->_next;
	}
	return nullptr;
}

//找环的入口
ListNode* EntryNodeOfLoop(ListNode* head)
{
	ListNode* node = MeetingNode(head);

	if (node == nullptr)
		return nullptr;

	//得到环中结点的数目
	int count = 1;
	ListNode* node1 = node;
	while (node1->_next != node)
	{
		count++;
		node1 = node1->_next;
	}

	//先移动node1，次数为环中结点的数目
	node1 = head;
	for (int i = 0; i < count; ++i)
	{
		node1 = node1->_next;
	}

	//再移动node1和cur
	ListNode* cur = head;
	while (node1 != cur)
	{
		node1 = node1->_next;
		cur = cur->_next;
	}
	return cur;
}
//int main()
//{
//	system("pause");
//	return 0;
//}