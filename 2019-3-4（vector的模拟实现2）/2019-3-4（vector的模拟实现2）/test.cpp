
#include<iostream>
#include<stdlib.h>
#include<algorithm>
#include<string>
#include<assert.h>

namespace world
{
	template <class T>
	class Vector
	{
	public:
		typedef  T* iterator;
		typedef  const T*  const_iterator;

		size_t Size()const{ return _finish - _start; }
		size_t Capacity()const{ return _end_of_stroage - _start; }
		iterator begin()
		{
			return _start;
		}

		iterator end()
		{
			return _finish;
		}

		const_iterator cbegin() const
		{
			return _start;
		}

		const_iterator cend() const
		{
			return _finish;
		}

		T& operator[](size_t pos)
		{
			assert(pos < Size());
			return _start[pos];
		}
		//const T& operator[](size_t pos)const
		//{
		//	assert(pos < Size());
		//	return _start[pos];
		//}

		Vector()
			:_start(nullptr)
			, _finish(nullptr)
			, _end_of_stroage(nullptr)
		{}
		//s1(s2);
		Vector(const Vector<T>& v)
		{
			_start = new char[v.Capacity()];
			//memcpy(_start, v._start, sizeof(T)*v.Size())//Ç³¿½±´
			for (size_t i = 0; i < size; i++)
			{
				v._start[i] = _start[i];
			}
			_finish = _start + v.Size();
			_end_of_stroage = _start + v.Capacity();
		}
		//s1 = s2;
		Vector <T>& operator=(const Vector <T>& value )
		{
			if (this != &value)
			{
				delete[] _start;
				_start = new char[value.Capacity()];
				for (size_t i = 0; i < size; i++)
				{
					value._start[i] = _start[i];
				}
				_finish = _start + value.Size();
				_end_of_stroage = _start + value.Capacity();
			}
			return *this;
		}
		void Reserve(size_t n)
		{
			if (n > Capacity())
			{
				size_t size = Size();
				T* temp = new T [n];
				if (_start)
				{
					for (size_t i = 0; i < size; i++)
					{
						temp[i] = _start[i];
					}
					delete[] _start;
				}
				_start = temp;
				_finish = _start + size;
				_end_of_stroage = _start + n;
			}
		}
		void Resize(size_t n, const T& value = T())
		{
			if (n <= Size())
			{
				_finish = _start + n;

			}
			else
			{
				if (n > Capacity())
					Reserve(n);
					while (_finish != _start + n)
					{
						*_finish = value;
						++_finish;
					}
			}
		}
		void PushBack(const T& x)
		{
			if (_finish == _end_of_stroage)
			{
				size_t newcapacity = Capacity() == 0 ? 2 : Capacity() * 2;
				Reserve(newcapacity);
			}
			*_finish = x;
			++_finish;
		}
		void Insert(iterator pos, const T& x)
		{
			assert(pos <= _finish);
			size_t index = _finish - _start;
			if (pos == _end_of_stroage)
			{
				size_t newcapacity = Capacity() == 0 ? 2 : Capacity() * 2;
				Reserve(newcapacity);
				pos = _start + index;
			}
			iterator end = _finish;
			while (end > pos)
			{
				*end = *(end - 1);
				--end;
			}
			*pos = x;
			++_finish;
		}
		iterator Erase(iterator pos)
		{
			assert(pos < _finish);
			iterator next = pos;
			while (_finish> pos)
			{
				*(pos - 1) = *pos;
				++pos;
			}
			--_finish;
			return next;
		}
		~Vector()
		{
			if (_start)
			{
				delete[] _start;
				_start = _finish = _end_of_stroage = nullptr;
			}
		}
	private:
		iterator _start;
		iterator _finish;
		iterator _end_of_stroage;
	};
	void test1()
	{
		Vector <std::string> v;
		v.PushBack("111");
		v.PushBack("222");
		v.PushBack("333");
		v.PushBack("444");
		v.PushBack("555");

		for (size_t i = 0; i < v.Size(); ++i)
		{
			std::cout << v[i] << " ";
		}

	}
	void test2()
	{
		Vector <int> v2;
		v2.PushBack(1);
		v2.PushBack(2);
		v2.PushBack(3);
		v2.PushBack(4);
		v2.PushBack(5);

		auto pos = std::find(v2.begin(), v2.end(), 3);
		if (pos != v2.end())
		{
			v2.Insert(pos, 30);
		}
		for (size_t i = 0; i < v2.Size(); ++i)
		{
			std::cout << v2[i] << " ";
		}
		std::cout << std::endl;
		pos = std::find(v2.begin(), v2.end(), 3);
		v2.Erase(pos);
		for (size_t i = 0; i < v2.Size(); ++i)
		{
			std::cout << v2[i] << " ";
		}
		std::cout << std::endl;

		v2.Resize(10,5);
		for (size_t i = 0; i < v2.Size(); ++i)
		{
			std::cout << v2[i] << " ";
		}
	}
}
int main()
{
	//world::test1();
	world::test2();
	system("pause");
	return 0;
}