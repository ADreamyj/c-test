#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>
using namespace std;

//�ϲ��������������ʹ�ϲ�֮�������Ҳ�������

//�����������˵�����Զ�������ָ�룬һ��ָ��1�����
//ͷ��㣬��һ��ָ��2�����ͷ��㡣
//Ȼ��Ƚ���������Ľ�㡣

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