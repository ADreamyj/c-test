#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>
using namespace std;

struct BSTnode
{
	BSTnode* _left;
	BSTnode* _right;
	int _value;
};
typedef BSTnode node;
//输入某二叉树的前序遍历和中序遍历的结果，请重建该二叉树，
//建设输入的前序遍历和中序遍历中都不包含重复的数字，
//例如：{1，2，4，7，3，5，6，8}
//{4，7，2，1，5，3，8，6}，并输出他的头结点

node* contration(int* preorder, int* preend, int* inorder, int* inend);

node* contrat(int* preorder, int* inorder, int lenght)
{
	if (preorder == nullptr || inorder == nullptr || lenght < 0)
		return nullptr;
	
		return contration(preorder, preorder + lenght - 1,
		inorder, inorder + lenght - 1);
}

node* contration(int* preorder, int* preend, int* inorder, int* inend)
{
	int rootvalue = preorder[0];
	node* root = new node();
	root->_value = rootvalue;
	root->_left = nullptr;
	root->_right = nullptr;

	if (preorder == preend)
	{
		if ((preorder == preend) && (*preorder == *preend))
			return root;
		else
			throw std::exception("Invalid input.");
	}
	int* rootinorder = inorder;
	while ((rootinorder <= inend) && (*rootinorder != *inend))
		++rootinorder;

	if ((rootinorder == inend) && (*rootinorder != *inend))
		throw std::exception("Invalid input.");

	int leftlenght = rootinorder - inorder;
	int* leftlenghtend = preorder + leftlenght;
	if (leftlenght > 0)
	{
		contration(preorder + 1, leftlenghtend, inorder, rootinorder - 1);
	}
	if (leftlenght < inend - inorder)
	{
		contration(leftlenghtend + 1, preend, rootinorder + 1, inend);
	}
	return root;
}
void Test(char* testName, int* preorder, int* inorder, int length)
{
	if (testName != nullptr)
		printf("%s begins:\n", testName);

	printf("The preorder sequence is: ");
	for (int i = 0; i < length; ++i)
		printf("%d ", preorder[i]);
	printf("\n");

	printf("The inorder sequence is: ");
	for (int i = 0; i < length; ++i)
		printf("%d ", inorder[i]);
	printf("\n");

	try
	{
		node* root = contrat(preorder, inorder, length);
		

	}
	catch (std::exception& exception)
	{
		printf("Invalid Input.\n");
	}
}
void test1()
{
	const int lenght = 8;
	int preorder[lenght] = { 1, 2, 4, 7, 3, 5, 6, 8 }; 
	int inorder[lenght] = { 4, 7, 2, 1, 5, 3, 8, 6 };

	Test("test1", preorder, inorder, lenght);
}
int main()
{
	test1();
	system("pause");
	return 0;
}