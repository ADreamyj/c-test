#define _CRT_SECURE_NO_WARNINGS  1

//��Ŀ�������һ������������һ�Ŷ��������ú�������������ľ���
//�������Ľ�㶨������

struct BinaryTreeNode
{
	int _val;
	BinaryTreeNode* _left;
	BinaryTreeNode* _right;
};

//��һ�Ŷ���������ķ��������������������ҽڵ㣬����������Ľ��
//��λ��Ҳ����Ž�����Ȼ��һֱ���±�����㣬����һ�ν���һ��
//���������еķ�ҳ���Ļ����������ͱ���˾����������

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