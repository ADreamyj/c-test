#define _CRT_SECURE_NO_WARNINGS  1


#include<iostream>
#include<vector>
#include<queue>
//题目：之字行从上打印二叉树

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
std::vector<std::vector<int>> print1(TreeNode* root)
{
	std::vector<std::vector<int>> ret;
	if (root == nullptr)
		return ret;
	std::queue<TreeNode*> q;
	q.push(root);
	int flag = 0;

	while (!q.empty())
	{
		std::vector<int> v;
		int n = q.size();
		for (int i = 0; i < n; ++i)
		{
			TreeNode* node = q.front();
			v.push_back(node->_val);

			q.pop();

			if (node->_left)
				q.push(node->_left);

			if (node->_right)
				q.push(node->_right);
		}
		if (flag % 2 == 1)
		{
			reverse(v.begin(), v.end());
		}

		ret.push_back(v);
		flag++;
	}
	return ret;
}
