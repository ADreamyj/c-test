#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>
#include<vector>

//��Ŀ���ؽ�������
//����ĳ��������ǰ���������������Ľ�������ؽ��ö�������
//���������ǰ���������������ж������ظ������֡����磬����ǰ�����
//����{1��2��4��7��3��5��6��8}�������������{4��7��2��1��5��3��8��6}
//���ؽ���ͼ2.6��ʾ�Ķ��������������ͷ��㡣���������Ķ������£�

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

	//�ֱ�洢�������е����������������е����������������е����������������е�������
	std::vector<int> pre_left, pre_right, in_left, in_right;

	//���������һ��λ���Ǹ��ڵ�node,ȡ��ֵ
	int val = pre[0];
	BinaryTreeNode* root = new BinaryTreeNode(val);

	//p���ڴ������������и��ڵ��λ��
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
			//�����������е���������ǰ�����е�������
			pre_left.push_back(pre[i + 1]);
				in_left.push_back(in[i]);
		}
		else if (i > p)
		{
			//�����������е���������ǰ�����е�������
			in_right.push_back(in[i]);
			pre_right.push_back(pre[i]);
		}
	}

	//ȡ��ǰ�������������ڵ���ߺ��ұߵ�����
    //�ݹ飬�ٶ�������������в��裬��������������������������ֱ��Ҷ�ڵ�
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