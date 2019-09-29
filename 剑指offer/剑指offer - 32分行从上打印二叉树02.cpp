#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>
#include<vector>
#include<queue>

//题目：分行从上打印二叉树
//从上到下打印二叉树，同一层的节点按照从左到右的顺序进行打印
//每一层打印一行。例如，打印下图的结果为
//8
//6		10
//5		7		9		11

struct TreeNode
{
	int _val;
	TreeNode* _left;
	TreeNode* _right;
	TreeNode(int val)
		:_val(val)
		, _left(nullptr)
		, _right(nullptr)
	{}
};

//std::vector<std::vector<int>> print(TreeNode* root)
//{
//	std::vector<std::vector<int>> ret;
//	if (root == nullptr)
//		return ret;
//	std::queue<TreeNode*> q;
//	q.push(root);
//	while (!q.empty())
//	{
//		std::vector<int> v;
//		int n = q.size();
//		while (n--)
//		{
//			TreeNode* node = q.front();
//			v.push_back(node->_val);
//			if (node->_left)
//				q.push(node->_left);
//			if (node->_right)
//				q.push(node->_right);
//			q.pop();
//		}
//		ret.push_back(v);
//	}
//	return ret;
//}