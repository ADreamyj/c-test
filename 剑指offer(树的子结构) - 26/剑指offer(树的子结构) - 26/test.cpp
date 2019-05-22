#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>

struct BinaryTreeNode
{
	BinaryTreeNode* _left;
	BinaryTreeNode* _right;
	double _val;
};

bool newFind(BinaryTreeNode* head1, BinaryTreeNode* head2);
bool Equal(double num1, double num2);

bool Find(BinaryTreeNode* head1, BinaryTreeNode* head2)
{
	bool flag = false;
	if (head1 != nullptr && head2 != nullptr)
	{
		if (Equal(head1->_val, head2->_val))
			flag = newFind(head1, head2);
		if (!flag)
			flag = Find(head1->_left, head2);
		if (!flag)
			flag = Find(head1->_right, head2);
	}
	return flag;
}

bool newFind(BinaryTreeNode* head1, BinaryTreeNode* head2)
{
	if (head2 == nullptr)
		return true;

	if (head1 == nullptr)
		return false;

	if (!(Equal(head1->_val, head2->_val)))
		return false;
	return newFind(head1->_left, head2->_left) &&
		newFind(head1->_right, head2->_right);
}

bool Equal(double num1,double num2)
{
	if ((num1 - num2 > -0.0000001) && (num1 - num2 < 0.0000001))
		return true;
	else
		return false;
}

BinaryTreeNode* CreateBinaryTreeNode(double dbValue)
{
	BinaryTreeNode* pNode = new BinaryTreeNode();
	pNode->_val = dbValue;
	pNode->_left = nullptr;
	pNode->_right = nullptr;

	return pNode;
}

void ConnectTreeNodes(BinaryTreeNode* pParent, BinaryTreeNode* pLeft, BinaryTreeNode* pRight)
{
	if (pParent != nullptr)
	{
		pParent->_left = pLeft;
		pParent->_right = pRight;
	}
}
void DestroyTree(BinaryTreeNode* pRoot)
{
	if (pRoot != nullptr)
	{
		BinaryTreeNode* pLeft = pRoot->_left;
		BinaryTreeNode* pRight = pRoot->_right;

		delete pRoot;
		pRoot = nullptr;

		DestroyTree(pLeft);
		DestroyTree(pRight);
	}
}
void Test(char* testName, BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2, bool expected)
{
	if (Find(pRoot1, pRoot2) == expected)
		printf("%s passed.\n", testName);
	else
		printf("%s failed.\n", testName);
}
void Test1()
{
	BinaryTreeNode* pNodeA1 = CreateBinaryTreeNode(8);
	BinaryTreeNode* pNodeA2 = CreateBinaryTreeNode(8);
	BinaryTreeNode* pNodeA3 = CreateBinaryTreeNode(7);
	BinaryTreeNode* pNodeA4 = CreateBinaryTreeNode(9);
	BinaryTreeNode* pNodeA5 = CreateBinaryTreeNode(2);
	BinaryTreeNode* pNodeA6 = CreateBinaryTreeNode(4);
	BinaryTreeNode* pNodeA7 = CreateBinaryTreeNode(7);

	ConnectTreeNodes(pNodeA1, pNodeA2, pNodeA3);
	ConnectTreeNodes(pNodeA2, pNodeA4, pNodeA5);
	ConnectTreeNodes(pNodeA5, pNodeA6, pNodeA7);

	BinaryTreeNode* pNodeB1 = CreateBinaryTreeNode(8);
	BinaryTreeNode* pNodeB2 = CreateBinaryTreeNode(9);
	BinaryTreeNode* pNodeB3 = CreateBinaryTreeNode(2);

	ConnectTreeNodes(pNodeB1, pNodeB2, pNodeB3);

	Test("Test1", pNodeA1, pNodeB1, true);

	DestroyTree(pNodeA1);
	DestroyTree(pNodeB1);
}
int main()
{
	Test1();
	system("pause");
	return 0;
}