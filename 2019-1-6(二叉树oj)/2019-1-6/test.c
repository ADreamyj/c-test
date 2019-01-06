
1.���ݶ����������ַ���
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/
void _tree2str(struct TreeNode* t, char* str)
{
	if (t == NULL)
		return;

	char buff[12];
	sprintf(buff, "%d", t->val);
	strcat(str, buff);

	//������
	if (t->left == NULL)
	{
		if (t->right == NULL)
			return;
		else
			strcat(str, "()");
	}
	else
	{
		strcat(str, "(");
		_tree2str(t->left, str);
		strcat(str, ")");
	}

	//������
	if (t->right == NULL)
	{
		return;
	}
	else
	{
		strcat(str, "(");
		_tree2str(t->right, str);
		strcat(str, ")");
	}
}
char* tree2str(struct TreeNode* t)
{
	char* str = (char*)malloc(1024 * 1024);
	_tree2str(t, str);
	return str;
}
3.�������������������
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/

int FindNode(struct TreeNode* tree, struct TreeNode* node)
{
	if (tree == NULL)
		return 0;
	if (tree == node)
		return 1;
	//�������ҵ�����1��
	if (FindNode(tree->left, node) == 1)
		return 1;
	//�������ҵ�����1��
	else if (FindNode(tree->right, node) == 1)
		return 1;
	//�����������Ҳ�������0��
	else
		return 0;

}
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
	if (root == NULL)
		return NULL;

	//1.���ڵ���ǹ�������
	if (root == p || root == q)
		return root;

	//2.��������
	//3.��������
	//4.һ����������һ��������

	int pleftnode = FindNode(root->left, p);
	int qleftnode = FindNode(root->left, q);

	if (pleftnode == 1 && qleftnode == 1)
		return lowestCommonAncestor(root->left, p, q);
	else if (pleftnode == 0 && qleftnode == 0)
		return lowestCommonAncestor(root->right, p, q);
	else
		return root;
}
4.������������˫������
/*
struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) :
val(x), left(NULL), right(NULL) {
}
};*/
class Solution {
public:
	TreeNode* prev = NULL;
	void _Convert(TreeNode* cur)
	{
		if (cur == NULL)
			return;
		_Convert(cur->left);
		cur->left = prev;

		if (prev)
			prev->right = cur;
		prev = cur;

		_Convert(cur->right);

	}
	TreeNode* Convert(TreeNode* pRootOfTree)
	{
		_Convert(pRootOfTree);
		TreeNode* head = pRootOfTree;
		while (head && head->left)
		{
			head = head->left;
		}
		return head;
	}
};
