#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>

//��Ŀ������һ�Ŷ����������е�һ����㣬����ҳ������������һ�����
//���磺  a
//	  b       c
//  d   e   f   g
//     h  i

//���������Ŀ�ķ�����˵����Ҫ��Ϊ���¼��־���
//1.���������������������ô������һ���������������������㡣
//2.���������û�����������������Ǹ��׵����㣬��ô
//	������һ�������Ǹ��׽�㡣
//3.���������û�����������������Ǹ��׵��ҽ�㣬��ô
//	������һ���������ϱ������ҵ��ҵ�û�и��׵��Ǹ���㡣

struct BTNode
{
	BTNode* _left;
	BTNode* _right;
	BTNode* _parent;
	int _value;
};
typedef BTNode node;
node* GetNode(node* pnode)
{
	if (pnode == nullptr)
		return nullptr;

	node* next = nullptr;
	if (pnode->_right)
	{
		node* right = pnode->_right;
		while (right->_left)
			right = right->_left;
		next = right;
	}
	else if (pnode->_parent)
	{
		node* cur = pnode;
		node* parent = pnode->_parent;
		while (parent && cur == parent->_right)
		{
			cur = parent;
			parent = parent->_parent;
		}
		next = parent;
	}
	return next;
}
node* Create(int value)
{
	node* newnode = new node();
	newnode->_value = value;
	newnode->_left = nullptr;
	newnode->_right = nullptr;
	newnode->_parent = nullptr;
	return newnode;
}
void PrintTreeNode(node* pNode)
{
	if (pNode != nullptr)
	{
		printf("value of this node is: %d\n", pNode->_value);

		if (pNode->_left != nullptr)
			printf("value of its left child is: %d.\n", pNode->_left->_value);
		else
			printf("left child is null.\n");

		if (pNode->_right != nullptr)
			printf("value of its right child is: %d.\n", pNode->_right->_value);
		else
			printf("right child is null.\n");
	}
	else
	{
		printf("this node is null.\n");
	}

	printf("\n");
}
void PrintTree(node* pRoot)
{
	PrintTreeNode(pRoot);

	if (pRoot != nullptr)
	{
		if (pRoot->_left != nullptr)
			PrintTree(pRoot->_left);

		if (pRoot->_right != nullptr)
			PrintTree(pRoot->_right);
	}
}
int main()
{
	system("pause");
	return 0;
}