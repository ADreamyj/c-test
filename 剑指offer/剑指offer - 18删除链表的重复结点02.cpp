#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>

//��Ŀ����һ������������У�ɾ���ظ��Ľ�㡣

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
	ListNode *head = (ListNode *)malloc(sizeof(ListNode)); // ����ͷ�ڵ�
	head->_next = nullptr;
	ListNode *end = head;  // βָ���ʼ��

	for (int i = 0; i < len; i++) {

		ListNode *p = (ListNode *)malloc(sizeof(ListNode)); // Ϊÿ������Ԫ�ؽ���һ���ڵ�
		p->_val = v[i];
		end->_next = p;  // ���ڵ�p���뵽�ն˽ڵ�֮��
		end = p;
	}

	end->_next = nullptr;  // ����������ϣ����ն˽ڵ��ָ�����ÿ�

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

ListNode* delete1(ListNode* head)//ɾ������������ظ����
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
		if (p->_val == next->_val)//�����ǰ�ڵ��ֵ����һ���ڵ��ֵ���
		{
			while (next != nullptr && next->_val == p->_val)//����ظ�����
				next = next->_next;
			pre->_next = next;//ָ�븳ֵ�����൱��ɾ��
			p = next;
		}
		else//�����ǰ�ڵ����һ���ڵ�ֵ���ȣ�������ƶ�һλ
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