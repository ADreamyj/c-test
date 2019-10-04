#define _CRT_SECURE_NO_WARNINGS  1

//题目:请实现函数ComplexListNode* clone(ComplexListNode* pHead)，
//复制一个复杂链表。在复杂链表中，每一个节点除了有一个m_pNext指针
//指向下一个节点，还有一个m_pSibling指针指向链表中任意节点或者nullptr
//节点的C++定义如下：

struct ComplexListNode
{
	int _value;
	ComplexListNode* _next;
	ComplexListNode* _sibling;
};

//方法：
//对于这个问题来说，想要不使用额外的空间，将时间复杂度尽可能地优化
//就要注意以下的三点

//1.在每个节点的后面复制当前节点。
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

//2.复制_sibling节点
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

//3.进行链表拆分

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