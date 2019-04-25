#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>

//题目：给定一颗二叉树和其中的一个结点，如何找出中序遍历的下一个结点
//例如：  a
//	  b       c
//  d   e   f   g
//     h  i

//对于这个题目的分析来说，主要分为以下几种境况
//1.如果这个结点有右子树，那么它的下一个结点就是右子树的最左结点。
//2.如果这个结点没有右子树，并且它是父亲的左结点，那么
//	它的下一个结点就是父亲结点。
//3.如果这个结点没有右子树，并且它是父亲的右结点，那么
//	它的下一个结点就向上遍历，找到找到没有父亲的那个结点。

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