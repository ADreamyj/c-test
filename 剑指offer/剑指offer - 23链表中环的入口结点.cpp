#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>

//��Ŀ�������л�����ڽ��
//���һ�������а�������������ҳ�������ڽ�㣿
//���磺�����µ������л�����ڽ����3��
//1 -> 2 -> 3 -> 4 -> 5 -> 6
//			|				|
//			-----------------	


//����˼·��
//1.���ж��������Ƿ��л������ǿ��Զ�������ָ�룬ͬʱ�������ͷ������
//һ��ָ��һ����һ������һ��ָ��һ���������������ָ��׷�����ߵ�����ָ��
//��ô�����о��л�������ߵĿ��ָ���ߵ��������ĩβ��û��׷�ϵ�һ��ָ�룬
//��ô�����û�л���

//2.�һ�����ڣ�Ҳ�Ƕ�������ָ��p1��p2ָ�������ͷ��㣬
//��������еĻ���n����㣬��ָ��p1������������ǰ�ƶ�n����
//Ȼ������ָ������ͬ���ٶ���ǰ�ƶ������ڶ���ָ��ָ�򻷵���ڽ���ʱ��
//��һ��ָ���Ѿ�Χ���Ż�����һȦ���ֻص�����ڽ�㡣


struct ListNode
{
	int _val;
	ListNode * _next;
	ListNode (int val)
		: _val(val)
		, _next(nullptr)
	{}
};

//�ж��Ƿ��л�
ListNode * MeetingNode(ListNode* head)
{
	if (head == nullptr)
		return nullptr;

	ListNode* slow = head->_next;
	if (slow == nullptr)
		return nullptr;

	ListNode* fast = slow->_next;
	while (slow && fast)
	{
		if (fast == slow)
			return fast;

		slow = slow->_next;
		fast = fast->_next;
		if (fast)
			fast = fast->_next;
	}
	return nullptr;
}

//�һ������
ListNode* EntryNodeOfLoop(ListNode* head)
{
	ListNode* node = MeetingNode(head);

	if (node == nullptr)
		return nullptr;

	//�õ����н�����Ŀ
	int count = 1;
	ListNode* node1 = node;
	while (node1->_next != node)
	{
		count++;
		node1 = node1->_next;
	}

	//���ƶ�node1������Ϊ���н�����Ŀ
	node1 = head;
	for (int i = 0; i < count; ++i)
	{
		node1 = node1->_next;
	}

	//���ƶ�node1��cur
	ListNode* cur = head;
	while (node1 != cur)
	{
		node1 = node1->_next;
		cur = cur->_next;
	}
	return cur;
}
//int main()
//{
//	system("pause");
//	return 0;
//}