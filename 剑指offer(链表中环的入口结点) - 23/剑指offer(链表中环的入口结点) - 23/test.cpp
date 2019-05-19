#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>
using namespace std;

//��Ŀ:���һ�������а�����������ҵ�������ڽ�㡣

//��һ�������ж�����������Ƿ��л�����������ָ�룬ָ��ͷ���
//һ��ָ��ÿ����һ������һ��ָ��ÿ����������
//�����ָ��׷����ָ�룬��֤�������л���

//�ڶ�������������н��ĸ������������Ľ�����������ٻص�
//�����㣬�����ÿ���ߵĸ���n��

//����������������ָ�룬ָ��ͷ��㣬��һ��ָ������n�������õڶ���
//ָ�뿪ʼ�ߣ��ཻ��������ڽ�㡣

struct ListNode
{
	ListNode* _next;
	int _val;
};

ListNode* Meet(ListNode* head)
{
	if (head == nullptr)
		return nullptr;

	ListNode* slow = head->_next;
	if (slow == nullptr)
		return nullptr;

	ListNode* fast = slow->_next;
	while (fast && slow)
	{
		if (fast == slow)
			return fast;
		slow = slow->_next;
		fast = fast->_next;
		if (fast != nullptr)
			fast = fast->_next;
	}
	return nullptr;

}
ListNode* Find(ListNode* head)
{
	ListNode* meet = Meet(head);
	if (meet == nullptr)
		return nullptr;

	ListNode* node1 = meet;
	int num = 1;
	while (node1->_next != meet)
	{
		node1 = node1->_next;
		++num;
	}
	node1 = head;
	for (int i = 0; i < num; ++i)
	{
		node1 = node1->_next;
	}
	ListNode* node2 = head;
	while (node1 != node2)
	{
		node1 = node1->_next;
		node2 = node2->_next;
	}
	return node1;
}
int main()
{
	system("pause");
	return 0;
}