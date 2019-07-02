#define _CRT_SECURE_NO_WARNINGS  1

//编程题1.参数解析

//#include<iostream>
//#include<string>
//using namespace std;
//int main()
//{
//	string str;
//	while (getline(cin,str))
//	{
//		//先算出参数的个数
//		int count = 0;
//		for (int i = 0; i < str.size(); ++i)
//		{
//			if (str[i] == ' ')
//				count++;
//			if (str[i] == '"')
//			{
//				do
//				{
//					i++;
//				} while (str[i] != '"');
//			}
//		}
//		cout << count+1 << endl;
//		//然后打印出每个参数的值。
//		//用flag表示是否包含双引号，0表示有双引号 
//		//双引号中的空格要打印出来
//		//用异或改变flag的值，两个双引号可以使flag复原 
//		int flag = 1;
//		for (int i = 0; i < str.size(); i++)
//		{
//			//有双引号，flag通过异或变为0，下一次再遇到双引号，flag置为1 
//			if (str[i] == '"')
//				flag ^= 1;
//			//双引号和普通空格不打印
//			if (str[i] != ' ' && str[i] != '"')
//				cout << str[i];
//			//双引号中的空格要打印 
//			if (str[i] == ' ' && (!flag))
//				cout << str[i];
//			//遇到双引号之外的空格就换行 
//			if (str[i] == ' ' && flag)
//				cout << endl;
//		}
//		cout << endl;
//	}
//	system("pause");
//	return 0;
//}

//编程题2：跳石阶


//
//采用动态规划思想求解。创建一个vector容器steps，
//steps[i]表示到达i号石板所需的最小步数。
//初始化为steps容器为INT_MAX。从序号N的石板开始逐个遍历，
//若steps[i]为INT_MAX，表示该点不可到达，直接开始下次循环。
//若steps[i]不为INT_MAX，表示该点可以到达，
//下面求解编号i的约数，进行动态规划。动态规划的转移方程为
//
//steps[i + j] = min(steps[i] + 1, steps[i + j])   //i为石板编号，j为i的约束
//steps[N] = 0

#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <algorithm>
using namespace std;

int main(){
	int N, M;
	while (cin >> N >> M){
		vector<int> steps(M + 1, INT_MAX);
		steps[N] = 0;
		for (int i = N; i <= M; i++){
			if (steps[i] == INT_MAX){
				continue;
			}
			for (int j = 2; (j*j) <= i; j++){
				if (i%j == 0){
					if (i + j <= M){
						steps[i + j] = min(steps[i] + 1, steps[i + j]);
					}
					if (i + (i / j) <= M){
						steps[i + (i / j)] = min(steps[i] + 1, steps[i + (i / j)]);
					}

				}

			}
		}
		if (steps[M] == INT_MAX){
			steps[M] = -1;
		}
		cout << steps[M] << endl;
	}
	system("pause");
	return 0;
}