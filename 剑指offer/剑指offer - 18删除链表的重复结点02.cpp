#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>

//题目：在一个排序的链表中，删除重复的结点。

struct ListNode
{
	int _val;
	ListNode* _next;
	ListNode(int x)
		:_val(x)
		, _next(nullptr)
	{}

};
ListNode *createEnd(int* v, int len)
{
	ListNode *head = (ListNode *)malloc(sizeof(ListNode)); // 生成头节点
	head->_next = nullptr;
	ListNode *end = head;  // 尾指针初始化

	for (int i = 0; i < len; i++) {

		ListNode *p = (ListNode *)malloc(sizeof(ListNode)); // 为每个数组元素建立一个节点
		p->_val = v[i];
		end->_next = p;  // 将节点p插入到终端节点之后
		end = p;
	}

	end->_next = nullptr;  // 单链表建立完毕，将终端节点的指针域置空

	return head;
}
void Print(ListNode* head)
{
	if (head == nullptr)
		return;
	ListNode* p = head->_next;
	while (p)
	{
		std::cout << p->_val << std::endl;
		p = p->_next;
	}
	std::cout << std::endl;
}

ListNode* delete1(ListNode* head)//删除排序链表的重复结点
{
	if (head == nullptr || head->_next == nullptr)
		return head;

	ListNode* newHead = new ListNode(-1);
	newHead->_next = head;
	ListNode* pre = newHead;
	ListNode* p = head;
	ListNode* next = nullptr;
	while (p != nullptr && p->_next != nullptr)
	{
		next = p->_next;
		if (p->_val == next->_val)//如果当前节点的值和下一个节点的值相等
		{
			while (next != nullptr && next->_val == p->_val)//向后重复查找
				next = next->_next;
			pre->_next = next;//指针赋值，就相当于删除
			p = next;
		}
		else//如果当前节点和下一个节点值不等，则向后移动一位
		{
			pre = p;
			p = p->_next;
		}
	}
		return newHead->_next;
}

//int main()
//{
//	int v[8] = { 1, 1, 2, 2, 3, 3 ,3,4};
//	ListNode* head = createEnd(v, 8);
//	
//	Print(head);
//	delete1(head);
//	Print(head);
//
//	system("pause");
//	return 0;
//}