#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>
#include<vector>
#include<queue>

//��Ŀ�����д��ϴ�ӡ������
//���ϵ��´�ӡ��������ͬһ��Ľڵ㰴�մ����ҵ�˳����д�ӡ
//ÿһ���ӡһ�С����磬��ӡ��ͼ�Ľ��Ϊ
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