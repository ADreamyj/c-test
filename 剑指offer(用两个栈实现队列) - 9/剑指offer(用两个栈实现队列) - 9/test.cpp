#define _CRT_SECURE_NO_WARNINGS  1

#include"test.h"

void Test(char actual, char expected)
{
	if (actual == expected)
		cout << "¶ÔµÄ" << endl;
	else
		cout << "´íµÄ" << endl;
}
int main()
{
	/*myqueue<char> queue;
	queue.appendTail('a');
	queue.appendTail('b');
	queue.appendTail('c');

	char head = queue.deleteHead();
	Test(head, 'a');*/
	mystack<char> stack;
	stack.append('a');
	stack.append('b');
	stack.append('c');

	char front = stack.deletele();
	Test(front, 'a');
	system("pause");
	return 0;
}