#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>
#include<queue>
//��Ŀ�������д��ϵ��´�ӡ������
//���ϵ��´�ӡ����������ÿһ����㣬ͬһ��Ľ�㰴�մ����ҵ�˳���ӡ
//���磬��ͼ�Ķ����������δ�ӡ��8��6��10��5��7��9��11
//���������Ķ�������

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