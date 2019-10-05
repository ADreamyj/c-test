#define _CRT_SECURE_NO_WARNINGS  1

//��Ŀ������һ�����������������ö���������ת����һ�������˫��
//����Ҫ���ܴ����κ��µĽڵ㣬ֻ�ܵ������нڵ�ָ���ָ��
//���磺��������ͼ�Ķ����������������ת��֮�������˫������
//�����������ڵ�Ķ������£�

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
		//������ڵ�Ϊ�գ��ͷ��ؿ�
		if (pRootOfTree == nullptr) 
			return nullptr;

		TreeNode* pre = nullptr;

		convertHelper(pRootOfTree, pre);

		//ѭ����������ڵ㣬����ڵ���������ͷ��㡣
		TreeNode* res = pRootOfTree;
		while (res->left)
			res = res->left;
		return res;
	}

	void convertHelper(TreeNode* cur, TreeNode*& pre)
	{
		if (cur == nullptr) return;

		convertHelper(cur->left, pre);

		//�������������ҽڵ㣬���ڵ�ָ����
		cur->left = pre;
		if (pre) 
			pre->right = cur;
		pre = cur;

		convertHelper(cur->right, pre);
	}
};
