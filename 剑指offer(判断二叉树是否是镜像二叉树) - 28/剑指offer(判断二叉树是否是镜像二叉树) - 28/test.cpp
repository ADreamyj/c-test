#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>
using namespace std;

//题目：判断一个二叉树是否是镜像二叉树
//可以用二叉树的前序遍历来进行判断，
//然后写出逆置的前序遍历来进行验证。
//测试二叉树是否是镜像二叉树

struct BinaryTreeNode
{
	BinaryTreeNode* _left;
	BinaryTreeNode* _right;
	int _val;
};

bool Judge(BinaryTreeNode* root)
{
	return judge(root, root);
}

bool judge(BinaryTreeNode* root1, BinaryTreeNode* root2)
{
	if (root1 == nullptr && root2 == nullptr)
		return true;
	if (root1 == nullptr || root2 == nullptr)
		return false;

	if (root1->_val != root2->_val)
		return false;

	return judge(root1->_left, root2->_right)
		&& judge(root1->_right, root2->_left);
}
int main()
{

	system("pause");
	return 0;
}