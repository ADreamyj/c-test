#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>

//��Ŀ������һ����������������еĵ�����k����㡣Ϊ�˷��ϴ����
//�˵�ϰ�ߣ������1��ʼ�������������β�ڵ��ǵ�����1����㣬
//���磺һ��������6����㣬��ͷ��㿪ʼ�����ǵ�ֵ������
//1��2��3��4��5��6�������ĵ�����3�������ֵΪ4�Ľ�㣬

//����Ķ������£�
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
		std::cout << p->_val  << "->";
		p = p->_next;
	}
	std::cout << std::endl;
}


ListNode* find(ListNode* &head, unsigned int k)
{
	ListNode* fast = head;
	ListNode* slow = head;
	for (int i = 0; i < k; i++)
	{
		fast = fast->_next;
	}
	while (fast->_next)
	{
		fast = fast->_next;
		slow = slow->_next;
	}
	std::cout << slow->_val << std::endl;
	return slow;
}
int main()
{
	int v[8] = { 1, 2, 3, 4, 5, 6 ,7,8};
	ListNode* head = createEnd(v, 8);
	Print(head);
	find(head, 3);
	system("pause");
	return 0;
}