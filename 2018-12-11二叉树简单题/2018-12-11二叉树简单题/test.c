#define  CRT_SECURE_NO_WARNINGS

1.����һ������������������ǰ�������

ʾ�� :

���� : [1, null, 2, 3]
	1
	\
	2
	/
	3

���:[1, 2, 3]

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
int treeSize(struct TreeNode* root)//������������еĽ��
{
	if (root == NULL)
		return 0;
	else
		return treeSize(root->left) + treeSize(root->right) + 1;
}

void numpreorder(struct TreeNode* root, int* preorder, int* pnum)//�����ȸ��������ҵ�˳����б���
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

2.����һ���������������������������

���� : [1, null, 2, 3]
	1
	\
	2
	/
	3

���:[1, 3, 2]
//ʾ�� :

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
int treeSize(struct TreeNode* root)//������������н��
{
	if (root == NULL)
		return 0;
	else
		return treeSize(root->left) + treeSize(root->right) + 1;
}

void inordernum(struct TreeNode* root, int* inorder, int* pnum)//����������������ٸ�
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

//4.������������������дһ�����������������Ƿ���ͬ��
//
//����������ڽṹ����ͬ�����ҽڵ������ͬ��ֵ������Ϊ��������ͬ�ġ�
//
//ʾ�� 1:
//
//���� : 1         1
//	/ \ / \
//	2   3     2   3
//
//	[1, 2, 3], [1, 2, 3]
//
//���: true
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
5.��һ����������
���������ǿն����� s �� t������ s ���Ƿ������ t ������ͬ�ṹ�ͽڵ�ֵ��������s ��һ���������� s ��һ���ڵ������ڵ���������s Ҳ���Կ����������һ��������

ʾ�� 1:
�������� s :

3
/ \
4   5
/ \
1   2
�������� t��

4
/ \
1   2
���� true����Ϊ t �� s ��һ������ӵ����ͬ�Ľṹ�ͽڵ�ֵ��

ʾ�� 2:
�������� s��

3
/ \
4   5
/ \
1   2
/
0
�������� t��

4
/ \
1   2
���� false��
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