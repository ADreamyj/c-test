#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>

struct ListNode
{
	int _val;
	ListNode* _next;
	ListNode(int data)
		:_val(data)
		, _next(nullptr)
	{};
};
void ListNodeDelete(ListNode** _head, ListNode* delete1)
{
	if (*_head == nullptr || delete1 == nullptr)
		return;

	if (delete1->_next != nullptr)
	{
		ListNode* next = delete1->_next;
		delete1->_val = next->_val;
		delete1->_next = next->_next;

		delete next;
		next = nullptr;

	}
	else if (*_head == delete1)
	{
		delete delete1;
		delete1 = nullptr;
		*_head = nullptr;
	}
	else
	{
		ListNode* cur = *_head;
		while (cur->_next)
		{
			cur = cur->_next;
		}
		cur->_next = nullptr;
		delete delete1;
		delete1 = nullptr;
	}
}

//int main()
//{
//	ListNode n1(1);
//	ListNode n2(2);
//	ListNode n3(3);
//	ListNode n4(4);
//	ListNode n5(5);
//	ListNode n6(6);
//	ListNode n7(7);
//	ListNode n8(8);
//
//	n1._next = &n2;
//	n2._next = &n3;
//	n3._next = &n4;
//	n4._next = &n5;
//	n5._next = &n6;
//	n6._next = &n7;
//	n7._next = &n8;
//	system("pause");
//	return 0;
//}