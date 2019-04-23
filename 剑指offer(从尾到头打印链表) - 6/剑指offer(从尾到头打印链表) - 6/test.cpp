#define _CRT_SECURE_NO_WARNINGS  1

#include"Node.h"
//从尾到头打印链表的每一个结点
void print1(ListNode* pHead)
{
	stack<ListNode*> s;
	ListNode* cur = pHead;
	while (cur)
	{
		s.push(cur);
		cur = cur->_next;
	}
	if (!s.empty())
	{
		cur = s.top();
		printf("%d ", cur->_value);
		s.pop();
	}
}
void print2(ListNode* pHead)
{
	if (pHead != nullptr)
	{
		if (pHead->_next)
		{
			print2(pHead->_next);
		}
		printf("%d ", pHead->_value);
	}
}
void Test(ListNode* pHead)
{
	print1(pHead);
	printf("\n");
	print2(pHead);
}

// 1->2->3->4->5
void Test1()
{
	
}
int main()
{
	system("pause");
	return 0;
}