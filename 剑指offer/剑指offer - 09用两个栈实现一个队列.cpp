#define _CRT_SECURE_NO_WARNINGS  1


#include<iostream>
#include<stack>
using namespace std;
//��Ŀ��������ջʵ��һ������
//������ջʵ�ֶ��У����е��������£���ʵ����������������appendTail
//��deleteHead���ֱ�����ڶ���β������ڵ���ڶ���ͷ��ɾ�����Ĺ���

template<typename T>
class Queue
{
public:
	Queue(void);
	~Queue(void);

	void appendTail(const T& node);
	T deleteHead();

private:
	stack<T> stack1;
	stack<T> stack2;
};

template<typename T>
void Queue<T>::appendTail(const T& node)
{
	stack1.push(node);
}

template<typename T>
T Queue<T>::deleteHead()
{
	if (stack2.size() <= 0)
	{
		while (stack1.size() > 0)
		{
			T& data = stack1.top();
			stack1.pop();
			stack2.push(data);
		}
	}
	
	if (stack2.size() == 0)
		std::cout << false << std::endl;
	T head = stack2.top();
	stack2.pop();

	return head;
}

void Test(char actual, char expected)
{
	if (actual == expected)
		printf("Test passed.\n");
	else
		printf("Test failed.\n");
}

//int main(int argc, char* argv[])
//{
//	Queue<char> queue;
//
//	queue.appendTail('a');
//	queue.appendTail('b');
//	queue.appendTail('c');
//
//	char head = queue.deleteHead();
//	Test(head, 'a');
//
//	head = queue.deleteHead();
//	Test(head, 'b');
//
//	queue.appendTail('d');
//	head = queue.deleteHead();
//	Test(head, 'c');
//
//	queue.appendTail('e');
//	head = queue.deleteHead();
//	Test(head, 'd');
//
//	head = queue.deleteHead();
//	Test(head, 'e');
//
//	system("pause");
//	return 0;
//}















