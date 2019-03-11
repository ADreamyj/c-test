#include<iostream>
#include<stdlib.h>
#include<assert.h>
using std::cout;
using std::endl;

#pragma once

namespace world
{
	template <class T>
	struct _ListNode
	{
		_ListNode <T>* _next;
		_ListNode <T>* _prev;
		T _date;
		
		_ListNode(const T& val = T())
			:_next(nullptr)
			, _prev(nullptr)
			, _date(val)
		{}
	};

	template<class T ,class Ref ,class Ptr>
	struct _ListIterator
	{
		typedef _ListNode <T> Node;
		typedef _ListIterator<T ,Ref,Ptr> Self;
		Node* _node;

		_ListIterator()
			:_node(nullptr)
		{}

		_ListIterator(Node* node)
			:_node(node)
		{}

		Ref operator*()
		{
			return _node->_date;
		}

		Ptr operator->()
		{
			return &_node->_date;
		}
		Self& operator++()
		{
			_node = _node->_next;
			return *this;
		}

		Self& operator++(int)
		{
			Self temp(*this);
			_node = _node->_next;
			return *temp;
		}
		Self& operator--(int)
		{
			Self temp(*this);
			_node = _node->_prev;
			return *temp;
		}
		Self& operator--()
		{
			_node = _node->_prev;
			return *this;
		}

		bool operator!= (const Self& self)
		{
			return _node != self._node;
		}

		bool operator== (const Self& self)
		{
			return _node == self._node;
		}
	};

	template <class T>
	class List
	{
	public:
		typedef _ListNode<T> Node;
		typedef _ListIterator<T,T& ,T*> iterator;
		typedef _ListIterator <T, const T&, const T* >const_iterator;

		iterator begin()
		{
			return iterator(_head->_next);
		}
		iterator end()
		{
			return iterator (_head);
		}
		List()//普通构造函数
		{
			CreateHead();
		}

		

		List(int n, const T& val = T())
		{
			CreateHead();
			for (int i = 0; i < n; ++i)
				PushBack(val);
		}

		template<class iterator>
		List(iterator first, iterator last)
		{
			CreateHead();
			while (first != last)
			{
				PushBack(*first);
				++first;
			}
		}

		List(const List<T>& L)//拷贝构造函数
		{
			CreateHead();

			List <T> temp(L.CBegin(), L.End());
			this->Swap(temp);
		}

		List<T>& operator=(const List<T>& val)//赋值运算符重载
		{
			if (this != &val)
			{
				List<T> temp(val);
				this->Swap(temp);
			}
			return *this;
		}

		~List()
		{
			Clear();
			delete _head;
			_head = nullptr;
		}

		void Swap(List <T>& val)
		{
			swap(_head, val._head);
		}

		void PushBack(const T& val)
		{
			Node* cur = _head->_prev;
			Node* newnode = new Node(val);
			cur->_next = newnode;
			newnode->_prev = cur;
			newnode->_next = _head;
			_head->_prev = newnode;
		}
		void PopBack()
		{
			Node* cur = _head->_prev->_prev;
			cur->_next = _head;
			_head->_prev = cur;
		}
		void PushFront(const T& val)
		{
			Node* cur = _head->_next;
			Node* newnode = new Node(val);
			_head->_next = newnode;
			newnode->_prev = _head;
			newnode->_next = cur;
			cur->_prev = newnode;
		}
		void PopFront()
		{
			Node* cur = _head->_next->_next;
			_head->_next = cur;
			cur->_prev = _head;
		}
		void Insert(iterator pos, const T& val)
		{
			
			Node* newnode = new Node(val);
			Node* cur = pos._node;
			Node* prev = cur->_prev;
			prev->_next = newnode;
			newnode->_next = prev;
			newnode->_next = cur;
			cur->_prev = newnode;
		}

		iterator Erase(iterator pos)
		{
			Node* cur = pos.Node;
			Node* prev = cur->_prev;
			Node* next = cur->_next;
			prev->_next = next;
			next->_prev = prev;
			delete cur;
			return iterator(next);
		}
		void Clear()
		{
			Node* cur = _head->_next;
			while (cur != _head)
			{
				_head->_next = cur->_next;
				delete cur;
				cur = _head->_next;
			}
			_head->_next = _head;
			_head->_prev = _head;
		}
	private:
		void CreateHead()
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;
		}
	private:
		Node* _head;

	};
	template<class T>
	void Print(world::List<T>& l1)
	{
		List <int>::iterator it = l1.begin();
		while (it != l1.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;
	}
	void test1()
	{
		List<int> l1;
		l1.PushBack(1);
		l1.PushBack(2);
		l1.PushBack(3);
		l1.PushBack(4);
		l1.PopBack();

		Print(l1);
	}
	void test2()
	{
		int array[] = { 1, 2, 3, 4, 5 };  
		world::List<int> l(array, array + sizeof(array) / sizeof(array[0]));

		auto pos = l.begin();  
		l.Insert(l.begin(), 0); 
		Print(l);  

		

	}
}



int main()
{
	//world::test1();
	world::test2();

	system("pause");
	return 0;
}