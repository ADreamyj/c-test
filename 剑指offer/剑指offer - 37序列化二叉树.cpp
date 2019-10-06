#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>
using namespace std;

//��Ŀ����ʵ�������������ֱ��������л��ͷ����л�������

//���л����ǽ�nullptrֵ�������ķ��������б�ʾ��"#"

#include<iostream>
#include<string>

using namespace std;

struct TreeNode
{
	int _val;
	TreeNode* _left;
	TreeNode* _right;
	TreeNode(int val)
	{
		this->_val = val;
		this->_left = this->_right = nullptr;
	}
};

void SerializeCore(const TreeNode* root, string& stream)
{
	if (root == nullptr)
	{
		stream += "#,";
		return;
	}
	stream += to_string(root->_val);
	stream += ',';
	SerializeCore(root->_left, stream);
	SerializeCore(root->_right, stream);
}

string Serialize(TreeNode* root)//���л�
{
	string str = "{";
	SerializeCore(root, str);
	str += "}";
	return str;
}

TreeNode* deserializeCore(string &data)
{
	if (data.empty())
		return nullptr;

	if ('#' == data.substr(data.find_first_not_of(' '), 1).data()[0])
	{
		data = data.substr(data.find_first_of(',') + 1);
		return nullptr;
	}

	TreeNode* ret = new TreeNode(stoi(data));
	data = data.substr(data.find_first_of(',') + 1);
	ret->_left = deserializeCore(data);
	ret->_right = deserializeCore(data);

	return ret;
}
TreeNode* deserialize(string &data)
{
	if (data.empty())
		return nullptr;

	//substr���ַ����ضϵ���˼��{1��#��2��3}
	//��һ���ַ�'{'�����һ���ַ�'}'ȡ����
	data = data.substr(1, data.length() - 2);
	TreeNode* ret = deserializeCore(data);
	return ret;
}

int main()
{
	TreeNode * root = new TreeNode(1);
	TreeNode *l1 = new TreeNode(2);
	TreeNode *r1 = new TreeNode(3);
	TreeNode *l1l = new TreeNode(4);
	TreeNode *l1r = new TreeNode(5);
	TreeNode *r1l = new TreeNode(6);
	TreeNode *r1r = new TreeNode(7);
	TreeNode *r2l = new TreeNode(8);
	TreeNode *r3r = new TreeNode(9);
	root->_left = l1;
	root->_right = r1;
	l1->_left = l1l;
	l1->_right = l1r;
	r1->_left = r1l;
	r1->_right = r1r;
	r1l->_left = r2l;
	r2l->_right = r3r;

	string str = Serialize(root);
	cout << str << endl;

	//string str("{11, 2, 4, #, #, 5, #, #, 3, 6, 8, #, 9, #, #, #, 7, #, #, }");
	//TreeNode* root = deserialize(str);
	system("pause");
	return 0;
}
