#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;

void test1()
{
	
	//std::vector<int> first;
	//std::vector<int> second(4, 100);
	//std::vector<int> third(second.begin(), second.end());
	//std::vector<int> fourth(third);

	int a[] = { 1, 2, 3, 4 };
	vector <int> v(a, a + sizeof(a) / sizeof(int));

	v[0] = 10;
	cout << v[0] << endl;

	for (size_t i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " ";//10，2，3，4
	}
	cout << endl;

	vector<int> swapv;
	swapv.swap(v);//交换两个数的值 

	cout << "v data:";
	for (size_t i = 0; i < v.size(); ++i) 
	{
		cout << v[i] << " "; //空
	}  
	cout << endl;

	cout << "swapv data:"; 
	for (size_t i = 0; i < swapv.size(); ++i)
	{
		cout << swapv[i] << " "; //10，2，3，4
	} 
	cout << endl;

}
void test2()//resize在开空间的时候进行初始化，影响size;
{
	std::vector<int> v;
	for (int i = 0; i < 10; ++i)
	{
		v.push_back(i);
		cout << v[i] << endl;
	}
	v.resize(5);

	for (size_t i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " ";
	}
	cout << endl;

	v.resize(8, 100);
	for (size_t i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " ";
	}
	cout << endl;

	v.resize(12);
	for (size_t i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}
void test3()
{
	int a[] = { 1, 2, 3, 4 }; 
	vector<int> v(a, a + sizeof(a) / sizeof(int));

	// 实现删除v中的所有偶数
	// 下面的程序会崩溃掉，如果是偶数，erase导致it失效  
	// 对失效的迭代器进行++it，会导致程序崩溃 
	vector<int>::iterator it = v.begin(); 
	while (it != v.end()) 
	{      
		if (*it % 2 == 0)
		{
			it = v.erase(it);
		}
		else
			++it;
	}
	for (auto a : v)
	{
		cout << a << " ";
	}
	cout << endl;
}
int main()
{
	//test1();
	//test2();
	test3();
	system("pause");
	return 0;
}