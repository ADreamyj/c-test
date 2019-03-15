#include<iostream>
#include<vector>
#include<list>
#include<functional>
using namespace std;

template<class T, class Container = vector<T>,class Compare = less<T>>

class Priority_queue
{
public:
	void Adjustup(int child)
	{
		int parent = (child - 1) >> 1;
		while (child > 0)
		{
			Compare com;
			if (com(_con[parent], _con[child]))
			{
				swap(_con[parent], _con[child]);
				child = parent;
				parent = (child - 1) >> 1;
			}
			else
			{
				break;
			}
		}
	}
	void Adjustdown(int parent)
	{
		int child = parent * 2 + 1;
		while (child < _con.size())
		{
			Compare com;
			if (child + 1 < _con.size() && com(_con[child], _con[child + 1]))
			{
				++child;
			}
			if (com(_con[parent] , _con[child]))
			{
				swap(_con[parent], _con[child]);
				parent = child;
				child = parent * 2 + 1; 
			}
			else
			{
				break;
			}
		}
	}
	void push(const T& x)
	{
		_con.push_back(x);
		Adjustup(_con.size() - 1);
	}

	void pop()
	{
		swap(_con[0], _con[_con.size() - 1]);
		_con.pop_back();
		Adjustdown(0);
	}

	const T& top()
	{
		return _con[0];
	}

	size_t Size()
	{
		return _con.size();
	}

	bool Empty()
	{
		return _con.empty();
	}
private:
	Container _con;
};
void test1()
{
	Priority_queue<int,vector<int>, greater <int>> st;
	st.push(1);
	st.push(5);
	st.push(6);
	st.push(2);
	st.push(3);
	while (!st.Empty())
	{
		cout << st.top() << " ";
		st.pop();
	}
	cout << endl;

}










