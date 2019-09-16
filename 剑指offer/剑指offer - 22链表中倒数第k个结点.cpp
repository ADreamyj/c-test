#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>

//题目：输入一个链表，输出该链表中的倒数第k个结点。为了符合大多数
//人的习惯，本题从1开始计数，即链表的尾节点是倒数第1个结点，
//例如：一个链表由6个结点，从头结点开始，他们的值依次是
//1，2，3，4，5，6这个链表的倒数第3个结点是值为4的结点，

//链表的定义如下：
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
		std::cout << p->_val  << "->";
		p = p->_next;
	}
	std::cout << std::endl;
}


ListNode* find(ListNode* &head, unsigned int k)
{
	ListNode* fast = head;
	ListNode* slow = head;
	for (int i = 0; i < k; i++)
	{
		fast = fast->_next;
	}
	while (fast->_next)
	{
		fast = fast->_next;
		slow = slow->_next;
	}
	std::cout << slow->_val << std::endl;
	return slow;
}
int main()
{
	int v[8] = { 1, 2, 3, 4, 5, 6 ,7,8};
	ListNode* head = createEnd(v, 8);
	Print(head);
	find(head, 3);
	system("pause");
	return 0;
}