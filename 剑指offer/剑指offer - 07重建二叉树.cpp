#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>
#include<vector>

//题目：重建二叉树
//输入某二叉树的前序遍历和中序遍历的结果，请重建该二叉树。
//假设输入的前序遍历和中序遍历中都不含重复的数字。例如，输入前序遍历
//序列{1，2，4，7，3，5，6，8}和中序遍历序列{4，7，2，1，5，3，8，6}
//则重建如图2.6所示的二叉树并输出它的头结点。二叉树结点的定义如下：

struct BinaryTreeNode
{
	int _value;
	BinaryTreeNode* _left;
	BinaryTreeNode* _right;

	BinaryTreeNode(int x)
		: _value(x),
		_left(NULL),
		_right(NULL)
	{}
};

BinaryTreeNode* Construct(std::vector<int> pre, std::vector<int> in)
{
	int size = pre.size();
	if (size == 0)
		return nullptr;

	//分别存储先序序列的左子树，先序序列的右子树，中序序列的左子树，中序序列的右子树
	std::vector<int> pre_left, pre_right, in_left, in_right;

	//先序遍历第一个位置是根节点node,取其值
	int val = pre[0];
	BinaryTreeNode* root = new BinaryTreeNode(val);

	//p用于储存中序序列中根节点的位置
	int p = 0;
	for (p; p < size; p++)
	{
		if (in[p] == val)
			break;
	}

	for (int i = 0; i < size; i++)
	{
		if (i < p)
		{
			//建立中序序列的左子树和前序序列的左子树
			pre_left.push_back(pre[i + 1]);
				in_left.push_back(in[i]);
		}
		else if (i > p)
		{
			//建立中序序列的右子树和前序序列的右子树
			in_right.push_back(in[i]);
			pre_right.push_back(pre[i]);
		}
	}

	//取出前序和中序遍历根节点左边和右边的子树
    //递归，再对其进行上述所有步骤，即再区分子树的左、右子子数，直到叶节点
	root->_left = Construct(pre_left, in_left);
	root->_right = Construct(pre_right, in_right);
	return root;
}

void Print(BinaryTreeNode* root)
{
	if (root)
	{
		Print(root->_left);
		Print(root->_right);
		std::cout << root->_value;
	}
	else
	{
		root = nullptr;
	}
}
//int main()
//{
//	std::vector<int> pre = { 1, 2, 4, 7, 3, 5, 6, 8 };
//	std::vector<int> in = { 4, 7, 2, 1, 5, 3, 8, 6 };
//	
//	BinaryTreeNode * T = Construct(pre, in);
//	Print(T);
//	system("pause");
//	return 0;
//}