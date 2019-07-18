#define _CRT_SECURE_NO_WARNINGS  1


#include<iostream>
#include<vector>
#include<stack>
using namespace std;

//1.ÅÅÐò×ÓÐòÁÐ

//int main()
//{
//	int n;
//	std::cin >> n;
//	std::vector<int> v;
//	v.resize(n);
//	for (int i = 0; i < n; ++i)
//	{
//		std::cin >> v[i];
//	}
//
//	int sum = 0;
//	int flag = 2;
//	for (int j = 0; j < n - 1; j++)
//	{
//		if (flag == 2)
//		{
//			if (v[j] > v[j + 1])
//				flag = 1;
//			else if (v[j] < v[j + 1])
//				flag = 0;
//		}
//		else if (flag == 1 && v[j] < v[j + 1])
//		{
//			flag = 2;
//			++sum;
//		}
//		else if (flag == 0 && v[j] > v[j + 1])
//		{
//			flag = 2;
//			++sum;
//		}
//	}
//	std::cout << sum + 1 << std::endl;
//	system("pause");
//	return 0;
//}


//±à³ÌÌâ2£ºµ¹ÖÃ×Ö·û´®


//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//int main()
//{
//	vector<string> v;
//	string s;
//	while (cin >> s){
//		v.push_back(s);
//	}
//	for (int i = v.size() - 1; i>0; i--)
//		cout << v[i] << " ";
//	cout << v[0] << endl;
//	return 0;
//}