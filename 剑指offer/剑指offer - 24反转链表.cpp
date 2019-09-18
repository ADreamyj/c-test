#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>

//反转链表
//定义一个函数，输入一个链表的头结点，反转该链表并输出
//反转后链表的头结点，链表结点的定义如下：


//1 -> 2 -> 3 -> 4 -> 5
//1 <- 2 <- 3    4 -> 5
//由上图可以分析出，结点3的下一个结点已经指向了它的前一个结点，
//导致我们再链表中无法遍历到结点4，所以我们要在调整结点3的下一个结点
//之前，将结点4保存下来。

//也就是说，我们在调整结点3的_next指针时，除了需要知道结点3本身
//还需要知道3的前一个结点2，因为我们需要把结点3的_next指向2。
//同时，我们还应该保存结点4，防止链表断开。

//因此，我们需要定义三个指针，分别指向当前遍历的结点，
//前一个结点和后一个结点

struct ListNode
{
	int _val;
	ListNode* _next;
	ListNode(int data)
		:_val(data)
		, _next(nullptr)
	{}
};

ListNode* ReverseList(ListNode* head)
{
	ListNode* prev = nullptr;
	ListNode* rhead = nullptr;
	ListNode* node = head;
	while (node != nullptr)
	{
		ListNode* next = node->_next;

		if (next == nullptr)
			rhead = node;

		prev = node;
		node = next;
	}
}
//int main()
//{
//	system("pause");
//	return 0;
//}