#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>
#include<queue>
//题目：不分行从上到下打印二叉树
//从上到下打印出二叉树的每一个结点，同一层的结点按照从左到右的顺序打印
//例如，下图的二叉树，依次打印出8，6，10，5，7，9，11
//二叉树结点的定义如下

struct BinaryTreeNode
{
	int _value;
	BinaryTreeNode* _left;
	BinaryTreeNode* _right;
};

void Print(BinaryTreeNode* root)
{
	if (root == nullptr)
		return;

	std::deque<BinaryTreeNode*> dp;
	
	dp.push_back(root);
	while (dp.size())
	{
		BinaryTreeNode* node = dp.front();
		dp.pop_front();

		printf("%d ", node->_value);

		if (node->_left)
			Print(node->_left);
		if (node->_right)
			Print(node->_right);
	}
}