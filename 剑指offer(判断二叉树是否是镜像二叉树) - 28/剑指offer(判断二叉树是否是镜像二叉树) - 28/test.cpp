#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>
using namespace std;

//��Ŀ���ж�һ���������Ƿ��Ǿ��������
//�����ö�������ǰ������������жϣ�
//Ȼ��д�����õ�ǰ�������������֤��
//���Զ������Ƿ��Ǿ��������

struct BinaryTreeNode
{
	BinaryTreeNode* _left;
	BinaryTreeNode* _right;
	int _val;
};

bool Judge(BinaryTreeNode* root)
{
	return judge(root, root);
}

bool judge(BinaryTreeNode* root1, BinaryTreeNode* root2)
{
	if (root1 == nullptr && root2 == nullptr)
		return true;
	if (root1 == nullptr || root2 == nullptr)
		return false;

	if (root1->_val != root2->_val)
		return false;

	return judge(root1->_left, root2->_right)
		&& judge(root1->_right, root2->_left);
}
int main()
{

	system("pause");
	return 0;
}