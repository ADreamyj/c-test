#define _CRT_SECURE_NO_WARNINGS  1


//组队竞赛
//找最大的那个。
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//int main()
//{
//	int n = 0;
//	cin >> n;
//	vector<long> v(3 * n);
//
//	for (int i = 0; i < 3 * n; ++i)
//	{
//		cin >> v[i];
//	}
//	sort(v.begin(), v.end());
//
//	long sum = 0;
//	for (int i = 1; i <= n; i++)
//	{
//		sum += v[3 * n - i * 2];
//	}
//	cout << sum;
//	system("pause");
//	return 0;
//}

//删除公共字符串
//#include<iostream>
//#include<string>
//using namespace std;
//int main()
//{
//		string str1, str2;
//		getline(cin, str1);
//		getline(cin, str2);
//
//		for (int i = 0; i < str2.size(); ++i)
//		{
//			int index = 0;
//			while ((index = str1.find(str2[i])) != -1)
//			{
//				str1.erase(index, 1);
//			}
//		}
//		cout << str1;
//	system("pause");
//	return 0;
//}
//#include <stdio.h>
//#include <math.h>
//#include <windows.h>
//#include <tchar.h>
//
//float f(float x, float y, float z) {
//	float a = x * x + 9.0f / 4.0f * y * y + z * z - 1;
//	return a * a * a - x * x * z * z * z - 9.0f / 80.0f * y * y * z * z * z;
//}
//
//float h(float x, float z) {
//	for (float y = 1.0f; y >= 0.0f; y -= 0.001f)
//	if (f(x, y, z) <= 0.0f)
//		return y;
//	return 0.0f;
//}
//
//int main() {
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0C);
//	HANDLE o = GetStdHandle(STD_OUTPUT_HANDLE);
//	_TCHAR buffer[25][80] = { _T(' ') };
//	_TCHAR ramp[] = _T(".:-=+*#%@");
//	int count = 0;
//	int count1 = 0;
//	//system("color F4");
//	for (float t = 0.0f;; t += 0.1f) {
//		int sy = 0;
//		float s = sinf(t);
//		float a = s * s * s * s * 0.2f;
//
//		for (float z = 1.3f; z > -1.2f; z -= 0.1f) {
//			_TCHAR* p = &buffer[sy++][0];
//			float tz = z * (1.2f - a);
//			for (float x = -1.5f; x < 1.5f; x += 0.05f) {
//				float tx = x * (1.2f + a);
//				float v = f(tx, 0.0f, tz);
//				if (v <= 0.0f) {
//					float y0 = h(tx, tz);
//					float ny = 0.01f;
//					float nx = h(tx + ny, tz) - y0;
//					float nz = h(tx, tz + ny) - y0;
//					float nd = 1.0f / sqrtf(nx * nx + ny * ny + nz * nz);
//					float d = (nx + ny - nz) * nd * 0.5f + 0.5f;
//					*p++ = ramp[(int)(d * 5.0f)];
//				}
//				else
//					*p++ = ' ';
//			}
//		}
//
//		for (sy = 0; sy < 25; sy++) {
//			COORD coord = { 0, sy };
//			SetConsoleCursorPosition(o, coord);
//			WriteConsole(o, buffer[sy], 79, NULL, 0);
//		}
//		if (count <= 10){
//			printf("I Love You ———.Mua~\n");
//			printf("             ");
//			count++;
//		}
//		else{
//			printf("You Are My Best Lover.\n");
//			printf("              ");
//			count++;
//			if (count >= 20){
//				count = 0;
//			}
//		}
//		Sleep(33);
//	}
//}

//3.排序子序列
//#include<iostream>
//#include<vector>
//using namespace std;
//
//int main()
//{
//	int n = 0;
//	vector<int> v;
//	cin >> n;
//	
//		v.resize(n);
//		for (int i = 0; i < n; ++i)
//		{
//			cin >> v[i];
//		}
//	int sum = 0;
//	int flag = 2;
//
//	for (int i = 0; i < n - 1; ++i)
//	{
//		if (flag == 2)
//		{
//			if (v[i] > v[i + 1])
//				flag = 1;
//			else if (v[i] < v[i + 1])
//				flag = 0;
//		}
//		else if (flag == 0 && v[i] > v[i + 1])
//		{
//			flag = 2;
//			sum++;
//		}
//		else if (flag == 1 && v[i] < v[i + 1])
//		{
//			flag = 2;
//			sum++;
//		}
//	}
//
//	cout << sum + 1 << endl;
//	system("pause");
//	return 0;
//}

//导致字符串
//#include<iostream>
//#include<string>
//#include<vector>
//using namespace std;
//
//vector<string> v;
//int main()
//{
//	string s;
//	while (cin >> s)
//	{
//		v.push_back(s);
//	}
//	for (int i = v.size() - 1; i >= 0; i--)
//	{
//		if (i == 0)
//			cout << v[i] << endl;
//		else
//			cout << v[i] << " ";
//	}
//	return 0;
//}


//#include<iostream>
//using namespace std;
//int func()
//{
//	int i, j, k = 0;
//	for (i = 0, j = -1; j = 0; i++, j++)
//	{
//		k++;
//	}
//	return k;
//}
//int main()
//{
//	cout << func();
//	system("pause");
//}

//#include<iostream>
//#include<vector>
//using namespace std;
//
//int main()
//{
//	vector<int> v;
//	v.resize(7);
//	vector<int> v2;
//	v2.resize(5);
//	for (int i = 0; i < 7; ++i)
//	{
//		cin >> v[i];
//	}
//	int a = (v[0] + v[4]) >> 1;
//	int b = (v[2] + v[6]) >> 1;
//	int c = v[6] - b;
//	if (a >= 0 || b >= 0 || c >= 0)
//	{
//		v2[0] = a;
//		v2[1] = ' ';
//		v2[2] = b;
//		v2[3] = ' ';
//		v2[4] = c;
//		for (int i = 0; i < 5; ++i)
//		{
//			cout << v2[i] << endl;
//		}
//	}
//	else
//		cout << "No" << endl;
//	system("psuse");
//	return 0;
//}

//下面程序的运行结果是什么
//#include<iostream>
//using namespace std;
//class BO
//{
//public:
//	virtual void display()
//	{
//		cout << "BO::display0" << endl;
//	}
//};
//
//class B1 :public BO
//{
//public:
//	void display()
//	{
//		cout << "B1::display0" << endl;
//	}
//};
//
//class D1 :public B1
//{
//public:
//	void display()
//	{
//		cout << "D1::display0" << endl;
//	}
//};
//
//void fun(BO ptr)
//{
//	ptr.display();
//}
//
//int main()
//{
//	BO b0;
//	B1 b1;
//	D1 d1;
//	fun(b0);
//	fun(b1);
//	fun(d1);
//	system("pause");
//}

//#include<iostream>
//#include<string>
//using namespace std;
//bool panduan(string str1)
//{
//	int length = str1.length();
//	for (int i = 0; i < length; i++)
//	{
//		if (str1[i] != str1[length - 1])
//			return false;
//		length = length - 1;
//	}
//	return true;
//}
//int main()
//{
//	string str1, str2, temp;
//	int count, len;
//	while (cin >> str1 >> str2)
//	{
//		count = 0;
//		temp = str1;
//		len = str1.length() + 1;
//		for (int i = 0; i < len; i++)
//		{
//			str1 = temp;
//			str1.insert(i, str2);
//			if (panduan(str1))
//				count++;
//		}
//		cout << count << endl;
//	}
//	system("pause");
//	return 0;
//}
#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> v;
	v.resize(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
	}
	int sum = v[0];
	int max = v[0];
	for (int i = 1; i < n; ++i)
	{
		if (sum >= 0)
		{
			sum += v[i];
		}
		else
		{
			sum = v[i];
		}
		if (max < sum)
			max = sum;
	}
	cout << max << endl;
	return 0;
}