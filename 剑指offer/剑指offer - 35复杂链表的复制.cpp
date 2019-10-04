#define _CRT_SECURE_NO_WARNINGS  1

//��Ŀ:��ʵ�ֺ���ComplexListNode* clone(ComplexListNode* pHead)��
//����һ�����������ڸ��������У�ÿһ���ڵ������һ��m_pNextָ��
//ָ����һ���ڵ㣬����һ��m_pSiblingָ��ָ������������ڵ����nullptr
//�ڵ��C++�������£�

struct ComplexListNode
{
	int _value;
	ComplexListNode* _next;
	ComplexListNode* _sibling;
};

//������
//�������������˵����Ҫ��ʹ�ö���Ŀռ䣬��ʱ�临�ӶȾ����ܵ��Ż�
//��Ҫע�����µ�����

//1.��ÿ���ڵ�ĺ��渴�Ƶ�ǰ�ڵ㡣
void clonenode(ComplexListNode* root)
{
	ComplexListNode* node = root;
	while (node)
	{
		ComplexListNode* clone = new ComplexListNode();
		clone->_value = node->_value;
		clone->_next = node->_next;
		clone->_sibling = nullptr;

		node->_next = clone;
		node = clone->_next;
	}
}

//2.����_sibling�ڵ�
void siblingnode(ComplexListNode* root)
{
	ComplexListNode* node = root;
	while(node)
	{
		ComplexListNode* clone = node->_next;
		if (node->_sibling)
		{
			clone->_sibling = node->_sibling->_next;
		}
		node = clone->_next;
	}
}

//3.����������

ComplexListNode* reconnectnodes(ComplexListNode* root)
{
	ComplexListNode* node = root;
	ComplexListNode* clonehead = nullptr;
	ComplexListNode* clone = nullptr;
	if (node)
	{
		clonehead = clone = node->_next;
		node->_next = clone->_next;
		node = node->_next;
	}
	while (node)
	{
		clone->_next = node->_next;
		clone = clone->_next;
		node->_next = clone->_next;
		node = node->_next;
	}
	return clonehead;
}

ComplexListNode* Clone(ComplexListNode* root)
{
	clonenode(root);
	siblingnode(root);
	reconnectnodes(root);
}