#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>

//��ת����
//����һ������������һ�������ͷ��㣬��ת���������
//��ת�������ͷ��㣬������Ķ������£�


//1 -> 2 -> 3 -> 4 -> 5
//1 <- 2 <- 3    4 -> 5
//����ͼ���Է����������3����һ������Ѿ�ָ��������ǰһ����㣬
//�����������������޷����������4����������Ҫ�ڵ������3����һ�����
//֮ǰ�������4����������

//Ҳ����˵�������ڵ������3��_nextָ��ʱ��������Ҫ֪�����3����
//����Ҫ֪��3��ǰһ�����2����Ϊ������Ҫ�ѽ��3��_nextָ��2��
//ͬʱ�����ǻ�Ӧ�ñ�����4����ֹ����Ͽ���

//��ˣ�������Ҫ��������ָ�룬�ֱ�ָ��ǰ�����Ľ�㣬
//ǰһ�����ͺ�һ�����

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