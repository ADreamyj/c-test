#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>

//题目：合并两个排序的链表
//输入两个递增的排序链表，合并这两个链表并使新链表中的结点
//仍然是递增排序。例如：输入下图的链表1和链表2，则合并之后
//的升序链表如下图所示，链表定义的结点如下：

// 1 -> 3 -> 5 -> 7
// 2 -> 4 -> 6 -> 8
// 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8


//方法1：递归
//比较首结点的大小，然后依次向后进行递归

struct ListNode
{
	int _val;
	ListNode * _next;
	ListNode(int data)
		:_val(data)
		, _next(nullptr)
	{}
};

ListNode* Merge1(ListNode* head1, ListNode* head2)
{
	if (head1 == nullptr)
		return head2;
	else if (head2 == nullptr)
		return head1;

	ListNode* merge = nullptr;
	if (head1->_val < head2->_val)
	{
		merge = head1;
		merge->_next = Merge1(head1->_next, head2);
	}
	else 
	{
		merge = head2;
		merge->_next = Merge1(head1, head2->_next);
	}
	return merge;
}

//方法2:非递归方法
ListNode* Merge2(ListNode* head1, ListNode* head2)
{
	if (head1 == nullptr)
		return head2;
	if (head2 == nullptr)
		return head1;
	if (head1 == nullptr && head2 == nullptr)
		return nullptr;

	ListNode * newlist = new ListNode(0);
	ListNode * first = newlist;

	while (head1 && head2)
	{
		if (head1->_val <= head2->_val)
		{
			newlist->_next = head1;
			head1 = head1->_next;
		}
		else
		{
			newlist->_next = head2;
			head2 = head2->_next;
		}
		newlist = newlist->_next;
	}

	newlist->_next = head1 ? head1 : head2;
	return first->_next;
}

int main()
{
	system("pause");
	return 0;
}