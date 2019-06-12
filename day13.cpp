#define _CRT_SECURE_NO_WARNINGS  1

//�����1.��������

//#include<iostream>
//#include<string>
//using namespace std;
//int main()
//{
//	string str;
//	while (getline(cin,str))
//	{
//		//����������ĸ���
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
//		//Ȼ���ӡ��ÿ��������ֵ��
//		//��flag��ʾ�Ƿ����˫���ţ�0��ʾ��˫���� 
//		//˫�����еĿո�Ҫ��ӡ����
//		//�����ı�flag��ֵ������˫���ſ���ʹflag��ԭ 
//		int flag = 1;
//		for (int i = 0; i < str.size(); i++)
//		{
//			//��˫���ţ�flagͨ������Ϊ0����һ��������˫���ţ�flag��Ϊ1 
//			if (str[i] == '"')
//				flag ^= 1;
//			//˫���ź���ͨ�ո񲻴�ӡ
//			if (str[i] != ' ' && str[i] != '"')
//				cout << str[i];
//			//˫�����еĿո�Ҫ��ӡ 
//			if (str[i] == ' ' && (!flag))
//				cout << str[i];
//			//����˫����֮��Ŀո�ͻ��� 
//			if (str[i] == ' ' && flag)
//				cout << endl;
//		}
//		cout << endl;
//	}
//	system("pause");
//	return 0;
//}

//�����2����ʯ��


//
//���ö�̬�滮˼����⡣����һ��vector����steps��
//steps[i]��ʾ����i��ʯ���������С������
//��ʼ��Ϊsteps����ΪINT_MAX�������N��ʯ�忪ʼ���������
//��steps[i]ΪINT_MAX����ʾ�õ㲻�ɵ��ֱ�ӿ�ʼ�´�ѭ����
//��steps[i]��ΪINT_MAX����ʾ�õ���Ե��
//���������i��Լ�������ж�̬�滮����̬�滮��ת�Ʒ���Ϊ
//
//steps[i + j] = min(steps[i] + 1, steps[i + j])   //iΪʯ���ţ�jΪi��Լ��
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