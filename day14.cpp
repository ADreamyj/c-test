#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>
using namespace std;

//�����1:
//�������ڵ�������ת��

//int main()
//{
//	int array[12] = { 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };
//	int year, month, day;
//	int sum = 0;
//	while (cin >> year >> month >> day)
//	{
//		sum += array[month - 2];
//		sum += day;
//		if (month > 2)
//		{
//			if (((month % 4 == 0) && (month % 100 != 0)) || (month % 400 == 0))
//			{
//				++sum;
//			}
//		}
//		cout << sum << endl;
//	}
//	system("pause");
//	return 0;
//}
#include<algorithm>
#include<vector>
int getLuckyPacket(vector<int> x, int n, int pos, int sum, int multi)
{
	int count = 0;
	//ѭ����������λ��i��ʼ���п��ܵ���� 
	for (int i = pos; i < n; ++i)
	{
		sum += x[i];
		multi *= x[i];
		if (sum > multi)
		{
			//�ҵ�����Ҫ�����ϣ���1�������ۼӺ�����ֵ�����Ƿ��з���Ҫ��ļ��� 
			count += 1 + getLuckyPacket(x, n, i + 1, sum, multi);
		}
		else if (x[i] == 1)
		{
			//��β�����Ҫ���ҵ�ǰԪ��ֵΪ1�������������� 
			count += getLuckyPacket(x, n, i + 1, sum, multi);
		}
		else
		{
			//���sum����multi,������û�з���Ҫ�������� 
			break;
		}
		//Ҫ������һ��λ��֮ǰ�����Ȼָ�sum��multi 
		sum -= x[i];
		multi /= x[i];
		//������ͬ����û��ʲô���𣬶�ֻ����һ����ϣ�����ֱ������ 
		while ( i < n - 1 && x[i] == x[i + 1])
		{
			i++;
		}
	}
	return count;
}
int main()
{
	vector<int> x;
	int n;
	while (cin >> n)
	{
		x.resize(n);
		for (int i = 0; i < n; ++i)
		{
			cin >> x[i];
		}
		sort(x.begin(),x.end());
		cout << getLuckyPacket(x, n, 0, 0, 1) << endl;
	}
	system("pause");
	return 0;
}