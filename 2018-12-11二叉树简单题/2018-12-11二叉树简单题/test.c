#define  CRT_SECURE_NO_WARNINGS

1.给定一个二叉树，返回它的前序遍历。

示例 :

输入 : [1, null, 2, 3]
	1
	\
	2
	/
	3

输出:[1, 2, 3]

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/
/**
* Return an array of size *returnSize.
* Note: The returned array must be malloced, assume caller calls free().
*/
int treeSize(struct TreeNode* root)//求二叉树中所有的结点
{
	if (root == NULL)
		return 0;
	else
		return treeSize(root->left) + treeSize(root->right) + 1;
}

void numpreorder(struct TreeNode* root, int* preorder, int* pnum)//依据先根再左再右的顺序进行遍历
{
	if (root == NULL)
		return;
	preorder[*pnum] = root->val;
	++(*pnum);
	numpreorder(root->left, preorder, pnum);
	numpreorder(root->right, preorder, pnum);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize)
{
	*returnSize = treeSize(root);
	int *preorder = (int*)malloc(*returnSize*sizeof(int));
	int num = 0;
	numpreorder(root, preorder, &num);
	return preorder;
}

2.给定一个二叉树，返回它的中序遍历。

输入 : [1, null, 2, 3]
	1
	\
	2
	/
	3

输出:[1, 3, 2]
//示例 :

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/
/**
* Return an array of size *returnSize.
* Note: The returned array must be malloced, assume caller calls free().
*/
int treeSize(struct TreeNode* root)//求二叉树的所有结点
{
	if (root == NULL)
		return 0;
	else
		return treeSize(root->left) + treeSize(root->right) + 1;
}

void inordernum(struct TreeNode* root, int* inorder, int* pnum)//中序遍历先左再右再根
{
	if (root == NULL)
		return;
	inordernum(root->left, inorder, pnum);

	inorder[*pnum] = root->val;
	++(*pnum);

	inordernum(root->right, inorder, pnum);

}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
	*returnSize = treeSize(root);
	int* inorder = (int*)malloc((*returnSize)*sizeof(int));
	int num = 0;
	inordernum(root, inorder, &num);
	return inorder;
}

//4.给定两个二叉树，编写一个函数来检验它们是否相同。
//
//如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。
//
//示例 1:
//
//输入 : 1         1
//	/ \ / \
//	2   3     2   3
//
//	[1, 2, 3], [1, 2, 3]
//
//输出: true
	/**
	* Definition for a binary tree node.
	* struct TreeNode {
	*     int val;
	*     struct TreeNode *left;
	*     struct TreeNode *right;
	* };
	*/
	bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
		if (p == NULL && q == NULL)
		{
			return true;
		}
		else if (p != NULL && q != NULL)
		{
			return p->val == q->val&&
				isSameTree(p->left, q->left) &&
				isSameTree(p->right, q->right);
		}
		else
		{
			return false;
		}

	}
5.另一个树的子树
给定两个非空二叉树 s 和 t，检验 s 中是否包含和 t 具有相同结构和节点值的子树。s 的一个子树包括 s 的一个节点和这个节点的所有子孙。s 也可以看做它自身的一棵子树。

示例 1:
给定的树 s :

3
/ \
4   5
/ \
1   2
给定的树 t：

4
/ \
1   2
返回 true，因为 t 与 s 的一个子树拥有相同的结构和节点值。

示例 2:
给定的树 s：

3
/ \
4   5
/ \
1   2
/
0
给定的树 t：

4
/ \
1   2
返回 false。
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/

bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
	if (p == NULL && q == NULL)
	{
		return true;
	}
	else if (p != NULL && q != NULL)
	{
		return p->val == q->val&&
			isSameTree(p->left, q->left) &&
			isSameTree(p->right, q->right);
	}
	else
	{
		return false;
	}

}

bool isSubtree(struct TreeNode* s, struct TreeNode* t) {
	if (s == NULL)
		return false;
	if (s->val == t->val)
	{
		if (isSameTree(s, t))
		{
			return true;
		}
	}

	if (isSubtree(s->left, t))
	{
		return true;
	}
	if (isSubtree(s->right, t))
	{
		return true;
	}

	return false;
}