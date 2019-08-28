#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>
#include<queue>

class MyStack
{
public:
	/** Initialize your data structure here. */
	MyStack()
	{

	}

	/** Push element x onto stack. */
	void push(int x) 
	{
		if (!q1.empty())
			q1.push(x);
		else
			q2.push(x);
	}

	/** Removes the element on top of the stack and returns that element. */
	int pop()
	{
		int pop;
		if (!q1.empty())
		{
			while (q1.size() > 1)
			{
				q2.push(q1.front());
				q1.pop();
			}
			pop = q1.front();
			q1.pop();
		}
		else
		{
			while (q2.size() > 1)
			{
				q1.push(q2.front());
				q2.pop();
			}
			pop = q2.front();
			q2.pop();
		}
		return pop;
	}

	/** Get the top element. */
	int top() 
	{
		int top;
		if (!q1.empty())
		{
			while (q1.size() > 1)
			{
				q2.push(q1.front());
				q1.pop();
			}
			top = q1.front();
			q2.push(q1.front());
			q1.pop();
		}
		else
		{
			while (q2.size() > 1)
			{
				q1.push(q2.front());
				q2.pop();
			}
			top = q2.front();
			q1.push(q2.front());
			q2.pop();
		}
		return top;
	}

	/** Returns whether the stack is empty. */
	bool empty() 
	{
		return q1.empty() && q2.empty();
	}
	std::queue<int> q1;
	std::queue<int> q2;
};

/**
* Your MyStack object will be instantiated and called as such:
* MyStack* obj = new MyStack();
* obj->push(x);
* int param_2 = obj->pop();
* int param_3 = obj->top();
* bool param_4 = obj->empty();
*/