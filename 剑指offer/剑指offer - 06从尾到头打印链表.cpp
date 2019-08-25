#define _CRT_SECURE_NO_WARNINGS  1


#include<iostream>
#include<stack>

//��Ŀ����β��ͷ��ӡ����
//������������ͷ��㣬��β��ͷ��������ӡ�����е�ÿһ������ֵ

struct ListNode
{
	int _value;
	ListNode* _next;
};

//����1��������ı�����Ľṹ�Ļ���������ջ��ʵ��
//��ÿһ��������ջ�У�Ȼ���ٽ�����ӡ������

void Print1(ListNode* head)
{
	std::stack<ListNode*> st;

	ListNode* cur = head;
	while (cur != nullptr)
	{
		st.push(cur);
		cur = cur->_next;
	}

	while (!st.empty())
	{
		cur = st.top();
		std::cout << cur->_value << " ";
		st.pop();
	}
}

//����2���ݹ�����ÿһ�����

void Print2(ListNode* head)
{
	if (head != nullptr)
	{
		if (head->_next != nullptr)
		{
			Print2(head->_next);
		}
		std::cout << head->_value << " ";
	}
}
//int main()
//{
//	system("pause");
//	return 0;
//}