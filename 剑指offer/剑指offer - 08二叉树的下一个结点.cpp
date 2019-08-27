#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>
#include<vector>
//��Ŀ������һ�ö����������е�һ����㣬����ҳ�����������е�
//��һ����㣿���еĽ������������ֱ�ָ�������ӽ���ָ��
//����һ��ָ�򸸽ڵ��ָ��


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