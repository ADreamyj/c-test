#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>
using namespace std;

//��Ŀ����ת���� ����һ������������һ�������ͷ��㣬��ת
//�������������ת�����ͷ��㡣�����㶨�����£�
struct ListNode
{
	ListNode * _next;
	int val;
};

//˼·�������������ԣ��ڷ�ת�����ʱ����Ҫ����ת������һ����㱣��
//������Ȼ��_nextָ��ǰһ����㣬�����Ҫ����һ����㣬ָ��ת����
//ǰһ����Ȼ������ѭ����ֱ���������

ListNode* Reverse(ListNode* head)
{
	ListNode* reversenode = head;
	ListNode* node = head;
	ListNode* prev = nullptr;
	while (node)
	{
		ListNode* next = node->_next;
		if (next == nullptr)
			reversenode = node;

		node->_next = prev;
		prev = node;
		node = next;
	}
	return reversenode;
}

int main()
{
	system("pause");
	return 0;
}