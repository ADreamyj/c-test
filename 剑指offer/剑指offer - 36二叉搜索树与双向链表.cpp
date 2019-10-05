#define _CRT_SECURE_NO_WARNINGS  1

//题目：输入一个二叉搜索树，将该二叉搜索数转换成一个排序的双向
//链表。要求不能创建任何新的节点，只能调整树中节点指针的指向。
//比如：输入如下图的二叉搜索数，则输出转换之后的排序双向链表。
//二叉搜索数节点的定义如下：

struct TreeNode
{
	int _val;
	TreeNode* left;
	TreeNode* right;
};


class Solution {
public:
	TreeNode* Convert(TreeNode* pRootOfTree)
	{
		//如果根节点为空，就返回空
		if (pRootOfTree == nullptr) 
			return nullptr;

		TreeNode* pre = nullptr;

		convertHelper(pRootOfTree, pre);

		//循环查找最左节点，最左节点就是链表的头结点。
		TreeNode* res = pRootOfTree;
		while (res->left)
			res = res->left;
		return res;
	}

	void convertHelper(TreeNode* cur, TreeNode*& pre)
	{
		if (cur == nullptr) return;

		convertHelper(cur->left, pre);

		//找左子树的最右节点，根节点指向他
		cur->left = pre;
		if (pre) 
			pre->right = cur;
		pre = cur;

		convertHelper(cur->right, pre);
	}
};
