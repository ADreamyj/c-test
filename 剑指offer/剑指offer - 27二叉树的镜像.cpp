#define _CRT_SECURE_NO_WARNINGS  1

//题目：请完成一个函数，输入一颗二叉树，该函数输出二叉树的镜像
//二叉树的结点定义如下

struct BinaryTreeNode
{
	int _val;
	BinaryTreeNode* _left;
	BinaryTreeNode* _right;
};

//求一颗二叉树镜像的方法，交换二叉树的左右节点，二叉树后面的结点
//的位置也会跟着交换，然后一直往下遍历结点，遍历一次交换一次
//遍历完所有的非页结点的话，二叉树就变成了镜像二叉树。

void MirrorRecursively(BinaryTreeNode* head)
{
	if (head == nullptr)
		return;
	if (head->_left == nullptr && head->_right == nullptr)
		return;

	BinaryTreeNode* temp = head->_right;
	head->_right = head->_left;
	head->_left = temp;

	if (head->_left)
		MirrorRecursively(head->_left);
	if (head->_right)
		MirrorRecursively(head->_right);
}