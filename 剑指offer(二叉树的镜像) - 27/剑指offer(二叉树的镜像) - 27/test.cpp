#define _CRT_SECURE_NO_WARNINGS  1

//�������ľ���
//����һ����������������ľ���

#include<iostream>
struct BinaryTreeNode
{
	BinaryTreeNode* _left;
	BinaryTreeNode* _right;
	int _val;
};

BinaryTreeNode* Shot(BinaryTreeNode* root)
{
	if (root == nullptr)
		return;

	if (root->_left == nullptr && root->_right == nullptr)
		return;

	BinaryTreeNode* temp = root->_left;
	root->_left = root->_right;
	root->_right = temp;

	if (root->_left)
		return Shot(root->_left);

	if (root->_right)
		return Shot(root->_right);
}
int main()
{
	system("pause");
	return 0;
}