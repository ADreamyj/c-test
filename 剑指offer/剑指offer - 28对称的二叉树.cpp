#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>

//题目：请实现一个函数，用来判断一颗二叉树是不是对称的，
//如果一颗二叉树和它的镜像一样的话，那么它就是对称的。

struct BinaryTreeNode
{
	int _val;
	BinaryTreeNode* _left;
	BinaryTreeNode* _right;
};
bool iTreeNode(BinaryTreeNode* root1, BinaryTreeNode* root2);
bool isTreeNode(BinaryTreeNode* root)
{
	return iTreeNode(root, root);
}
bool iTreeNode(BinaryTreeNode* root1, BinaryTreeNode* root2)
{
	if (root1 == nullptr && root2 == nullptr)
		return true;
	if (root1 == nullptr || root2 == nullptr)
		return false;
	if (root2->_val != root1->_val)
		return false;
	return iTreeNode(root1->_left, root2->_right)
		&& iTreeNode(root1->_right, root2->_left);
}