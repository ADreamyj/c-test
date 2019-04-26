#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>
using namespace std;
//#include<stack>
#include<queue>
//������ջʵ��һ�����У����е��������£���ʵ��������������
//appendTail��deleteHead���ֱ�����ڶ���β��������ڶ���ͷ��ɾ��
//���Ĺ���

//template<class T>
//class myqueue
//{
//public:
//	//myqueue(void);
//	//~myqueue(void);
//
//	void appendTail(const T& node);
//	T deleteHead();
//
//private:
//	stack<T> s1;
//	stack<T> s2;
//
//};
//template<class T> void myqueue<T>::appendTail(const T& node)
//{
//	s1.push(node);
//}
//template<class T>  T myqueue<T>::deleteHead()
//{
//	if (s1.size() >= 0)
//	{
//		while (s1.size() > 0)
//		{
//			T& top = s1.top();
//			s1.pop();
//			s2.push(top);
//		}
//	}
//	if (s2.size() == 0)
//		throw new exception("queue is empty");
//
//	T head = s2.top();
//	s2.pop();
//
//	return head;
//}

//����������ʵ��һ��ջ
template<class T>
class mystack
{
public:
	void append(const T& node);
	T deletele();
private:
	queue<T> q1;
	queue<T> q2;
};

template<class T> void mystack<T>::append(const T& node)
{
	if (q1.empty())
		q1.push(node);
	else
		q2.push(node);
}
template<class T> T mystack<T>::deletele()
{
	int top = 0;
	if (!q1.empty())
	{
		while (q1.size() > 1)
		{
			int date = q1.front();
			q1.pop();
			q2.push(date);
		}
		top = q1.front();
		q1.pop();
	}
	else
	{
		while (q2.size() > 1)
		{
			int date = q2.front();
			q2.pop();
			q1.push(date);
		}
		top = q2.front();
		q2.pop();
	}
	return top;
}