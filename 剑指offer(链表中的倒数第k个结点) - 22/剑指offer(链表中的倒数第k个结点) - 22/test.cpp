#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>

//��Ŀ���������еĵ�����k�����

//��һ�ַ������������ͷ��β����һ�飬�������������Ľ�����
//Ȼ���ͷ��ʼ�ҵ�n - k + 1�Ľ�㡣
//���ַ�����Ҫ������������Σ�

//�ڶ��ַ�����������ָ�룬��һ��ָ����k - 1������������ָ��
//һ���ߣ�����һ��ָ���ߵ�ĩβ��ʱ��
//�ڶ���ָ����ߵ�������k����㡣

struct ListNode
{
	ListNode* _next;
	int _val;
};

ListNode* Find(ListNode* head, int k)
{
	if (head == nullptr || k <= 0)
		return nullptr;

	ListNode* cur1 = head;
	for (int i = 0; i < k - 1; ++i)
	{
		if (cur1->_next != nullptr)
			cur1 = cur1->_next;
		else
			return nullptr;
		
	}
	ListNode* cur2 = head;

	while (cur1->_next)
	{
		cur1 = cur1->_next;
		cur2 = cur2->_next;
	}
	return cur2;
}
int main()
{
	system("pause");
	return 0;
}