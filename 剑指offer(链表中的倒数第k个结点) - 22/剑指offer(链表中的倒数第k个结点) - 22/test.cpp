#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>

//题目；求链表中的倒数第k个结点

//第一种方法，将链表从头到尾遍历一遍，计算出所有链表的结点个数
//然后从头开始找第n - k + 1的结点。
//这种方法需要将链表遍历两次：

//第二种方法，用两个指针，第一个指针走k - 1步，再让两个指针
//一块走，当第一个指针走到末尾的时候，
//第二个指针就走到倒数第k个结点。

struct ListNode
{
	ListNode* _next;
	int _val;
};

ListNode* Find(ListNode* head, int k)
{
	if (head == nullptr || k <= 0)
		return nullptr;

	ListNode* cur1 = head;
	for (int i = 0; i < k - 1; ++i)
	{
		if (cur1->_next != nullptr)
			cur1 = cur1->_next;
		else
			return nullptr;
		
	}
	ListNode* cur2 = head;

	while (cur1->_next)
	{
		cur1 = cur1->_next;
		cur2 = cur2->_next;
	}
	return cur2;
}
int main()
{
	system("pause");
	return 0;
}