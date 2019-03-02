#define CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<stdlib.h>
#include<string>
#include<assert.h>

using namespace std;

namespace world
{
	template<class T>
	class Vector
	{
	public:
		typedef T* Iterator;
		typedef const T* ConstIterator;

		Iterator Begin(){ return _start; }
		Iterator End(){ return _finish; }

		ConstIterator CBegin() const { return _start; }
		ConstIterator CEnd()  const{ return _finish; }

		size_t Size() const{ return _finish - _start; }
		size_t Capacity()const{ return _endOfStorage - _start; }

		Vector()//无参拷贝
			:_start(nullptr)
			, _finish(nullptr)
			, _endOfStorage(nullptr)
		{}

		Vector(int n, const T& value = T())//构造并初始化n个val
			:_start(nullptr)
			, _finish(nullptr)
			, _endOfStorage(nullptr)
		{
			Reserve(n);
			while (n--)
			{
				PushBack(value);
			}
		}

		Vector(const Vector<T>& v)//拷贝构造
			:_start(nullptr)
			, _finish(nullptr)
			, _endOfStorage(nullptr)
		{
			Reserve(v.Capacity());

			Iterator it = Begin();
			ConstIterator vit = v.CBegin();
			while (vit != v.CEnd())
			{
				*it++ = *vit++;
			}
			_finish = _start + v.Size();
			_endOfStorage = _start + v.Capacity();

		}

		template<class con>
		Vector(con first, con last)//使用迭代器进行初始化构造
		{
			Reserve(last - first);
			while (first != last)
			{
				PushBack(*first);
				++first;
			}
		}

		Vector<T>& operator=(Vector <T> v)//赋值运算符重载
		{
			Swap(v);
			return *this;
		}
		void Swap(Vector <T>& v)
		{
			swap(_start, v._start);
			swap(_finish, v._finish);
			swap(_endOfStorage; v._endOfStorage);
		}

		void Resize(size_t n, const T& value = T())
		{
			if (n <= Size())
			{
				_finish = _start + n;
				return;
			}
			else
			{
				Reserve(n);
			}
			Iterator it = _finish;
			Iterator _finish = _start + n;
			while (it != _finish)
			{
				*it = value;
				++it;
			}
		}

		void Reserve(size_t n)
		{
			if (n > Capacity())
			{
				size_t size = Size();
				T* tmp = new T[n];
				if (_start)
				{
					for (size_t i = 0; i < size; ++i)
						tmp[i] = _start[i];
				}
				_start = tmp;
				_finish = _start + size;
				_endOfStorage = _start + n;
			}
		}

		void PushBack(const T& val)
		{
			Insert(End(), val);
		}

		void PopBack()
		{
			Erase(--End());
		}

		Iterator Insert(Iterator pos, const T& val)
		{
			assert(pos <= _finish);
			if (_finish == _endOfStorage)
			{
				size_t size = Size();
				size_t newcapacity = Capacity() == 0 ? 1 : Capacity() * 2;
				Reserve(newcapacity);
				pos = _start + size;
			}
			Iterator end = _finish - 1;
			while (end >= pos)
			{
				*(end + 1) = *end;
				--end;
			}
			*pos = val;
			++_finish;
			return pos;
		}

		Iterator Erase(Iterator pos)
		{
			Iterator begin = pos + 1;
			while (begin != _finish)
			{
				*(begin - 1) = *begin;
				++begin;
			}
			--_finish;
			return pos;
		}

		T& operator[](size_t pos)
		{
			return _start[pos];
		}

		~Vector()
		{
			delete[] _start;
			_start = _finish = _endOfStorage = nullptr;
		}
	private:
		Iterator _start;
		Iterator _finish;
		Iterator _endOfStorage;
	};
}
void test1()
{
	world::Vector<int> s1;
	world::Vector<int> s2(4, 10);
	for (size_t i = 0; i < s2.Size(); i++)
	{
		cout << s2[i] << " ";

	}
		cout << endl;

	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	world::Vector<int> s3(arr, arr + sizeof(arr) / sizeof(int));
	for (world::Vector<int>::Iterator it = s3.Begin(); it != s3.End(); it++)
		cout << *it << " ";
	cout << endl;

	world::Vector<int> s4(s2);
	for (size_t i = 0; i < s4.Size(); ++i)
	{
		cout << s4[i] << " ";
	}
	cout << endl;

	world::Vector<string> s5;
	s5.PushBack("1234");
	s5.PushBack("1234");
	s5.PushBack("1234");
	s5.PushBack("1234");
	for (size_t i = 0; i < s5.Size(); ++i)
	{
		cout << s5[i] << " ";
	}
	cout << endl;
}

void Print(const world::Vector<int> &v)//使用const迭代器进行遍历打印
{
	world::Vector<int>::ConstIterator it = v.CBegin();
	while (it != v.CEnd())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

void test2()//使用迭代器进行修改
{
	world::Vector<int> v;
	v.PushBack(1);
	v.PushBack(2);
	v.PushBack(3);
	v.PushBack(4);
	world::Vector<int>::Iterator it = v.Begin();
	while (it != v.End())
	{
		*it *= 2 ;
		++it;
	}
	cout << endl;
	Print(v);
}

void test3()
{
	size_t sz;
	world::Vector<int> foo;
	sz = foo.Capacity();
	for (int i = 0; i < 100; i++)
	{
		foo.PushBack(i);
		if (sz != foo.Capacity())
		{
			sz = foo.Capacity();
			cout << sz << endl;
		}
	}
}

void test4()
{
	int arr[] = { 2, 3, 4, 5, 6 };
	world::Vector<int> v(arr, arr + sizeof(arr) / sizeof(int));
	world::Vector<int>::Iterator pos = find(v.Begin(), v.End(), 5);
	v.Insert(pos, 20);
	Print(v);

}
int main()
{
	//test1();
	//test2();
	//test3();
	test4();
	system("pause");
	return 0;
}