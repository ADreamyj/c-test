#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>
using namespace std;

//合并两个有序的链表，使合并之后的链表也是有序的

//对于这个题来说，可以定义两个指针，一个指向1链表的
//头结点，另一个指向2链表的头结点。
//然后比较两个链表的结点。

struct ListNode
{
	ListNode* _next;
	int _val;
};

ListNode* Merge(ListNode* head1, ListNode* head2)
{
	if (head1 == nullptr)
		return head2;
	if (head2 == nullptr)
		return head1;

	ListNode* cur = nullptr;
	if (head1->_val < head2->_val)
	{
		cur = head1;
		cur->_next = Merge(head1->_next, head2);
	}
	else
	{
		cur = head2;
		cur->_next = Merge(head1, head2->_next);
	}
	return cur;
}
int main()
{
	system("pause");
	return 0;
}