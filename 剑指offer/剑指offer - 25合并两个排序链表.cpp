#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>

//��Ŀ���ϲ��������������
//�����������������������ϲ�����������ʹ�������еĽ��
//��Ȼ�ǵ����������磺������ͼ������1������2����ϲ�֮��
//��������������ͼ��ʾ��������Ľ�����£�

// 1 -> 3 -> 5 -> 7
// 2 -> 4 -> 6 -> 8
// 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8


//����1���ݹ�
//�Ƚ��׽��Ĵ�С��Ȼ�����������еݹ�

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

//����2:�ǵݹ鷽��
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