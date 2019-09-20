#define _CRT_SECURE_NO_WARNINGS  1

//题目：树的子结构
//输入两棵二叉树A和B，判断B是不是A的子结构，二叉树结点的定义如下：

struct BinaryTreeNode
{
	int _val;
	BinaryTreeNode* _left;
	BinaryTreeNode* _right;
};

bool isSubtree(BinaryTreeNode* head1, BinaryTreeNode* head2)
{
	if (head1 == nullptr)
		return false;
	if (head2 == nullptr)
		return true;
	if (head2->_right == head1->_left)
	{
		return isSubtree(head1->_left, head2->_left)
			&& isSubtree(head1->_right, head2->_right);
	}
	else
		return false;
}

bool HasSubtree(BinaryTreeNode* head1, BinaryTreeNode* head2)
{
	if (head1 == nullptr || head2 == nullptr)
		return false;

	return isSubtree(head1, head2)
		|| HasSubtree(head1->_left, head2)
		|| HasSubtree(head1->_right, head2);
}