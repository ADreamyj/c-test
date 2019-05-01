#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>
using namespace std;
int fun() 
{ 
	static int count = 1; 
	return ++count;
}
int main() 
{
	int answer;
	answer = fun() - fun() * fun(); 
	printf("%d\n", answer);//输出多少？  
	system("pause");
	return 0;
} 
//int main()
//{
//	int i = 0, a = 0, b = 2, c = 3, d = 4;
//	i = ++b || a++ || d++;
//	cout << i<<" ";
//	system("pause");
//	return 0;
//}