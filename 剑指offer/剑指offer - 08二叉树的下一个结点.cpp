#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>
#include<vector>
//题目：给定一棵二叉树和其中的一个结点，如何找出中序遍历序列的
//下一个结点？树中的结点除了有两个分别指向左，右子结点的指针
//还有一个指向父节点的指针


struct BinaryTreeNode
{
	int _val;
	BinaryTreeNode* _left;
	BinaryTreeNode* _right;
	BinaryTreeNode* _parent;

	BinaryTreeNode(int x)
		:_val(x)
		, _left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
	{}
};

BinaryTreeNode* GetNext(BinaryTreeNode* node)
{
	if (node == nullptr)
		return nullptr;

	BinaryTreeNode* next = nullptr;
	if (node->_right != nullptr)
	{
		BinaryTreeNode* pright = node->_right;
		while (pright->_left)
		{
			pright = pright->_left;
		}
		next = pright;
	}
	else if (node->_parent != nullptr)
	{
		BinaryTreeNode* cur = node;
		BinaryTreeNode* parent = node->_parent;
		while (parent != nullptr && cur == node->_right)
		{
			cur = parent;
			parent = parent->_parent;
		}
		next = parent;
	}
	return next;
}
//int main()
//{
//	std::vector<int> v = { 1, 2, 4, 7, 3, 5, 6, 8 };
//	
//	system("pause");
//	return 0;
//}