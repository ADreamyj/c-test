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
void test2()
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
int main()
{
	test1();

	
	//test2();
	system("pause");
	return 0;
}