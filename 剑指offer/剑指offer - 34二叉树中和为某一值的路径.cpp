#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>
#include<vector>
//题目：输入一颗二叉树和一个整数，打印出二叉树中节点值的和为输入
//整数得所有路径。从更节点开始往下一直到叶节点所经过得节点形成一条
//路径。二叉树的节点定义如下：
struct BinaryTreeNode
{
	int _val;
	BinaryTreeNode* _left;
	BinaryTreeNode* _right;
};


void Find(BinaryTreeNode* root, int num)
{
	if (root == nullptr)
		return;

	std::vector<int> v;
	int sum = 0;

	Find1(root, num, v, sum);
}

void Find1(BinaryTreeNode* root, int num, std::vector<int>v, int sum)
{
	sum += root->_val;
	v.push_back(root->_val);

	bool flag = root->_left == nullptr && root->_right == nullptr;

	if (sum == num && flag)
	{
		printf("A path found:");
		std::vector<int>::iterator it = v.begin();
		for (; it != v.end(); ++it)
			printf("%d", it);
		printf("\n");
	}

	if (root->_left)
		Find1(root->_left, num, v, sum);
	if (root->_right)
		Find1(root->_right, num, v, sum);
	v.pop_back();
}
