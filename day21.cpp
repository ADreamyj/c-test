#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>
#include<vector>
#include<string>
using namespace std;

//�����1��ϴ��
//3
//3 1
//1 2 3 4 5 6
//3 2
//1 2 3 4 5 6
//2 2
//1 1 1 1
//�����1 4 2 5 3 6    1 5 4 3 2 6    1 1 1 1 

//int main()
//{
//	int T, n, k;
//	cin >> T;
//	while (T--)
//	{
//		cin >> n >> k;
//		int num = 2 * n;
//		vector<int> table(num);
//		for (int i = 0; i < num; ++i)
//		{
//			cin >> table[i];
//		}
//		while (k--)
//		{
//			vector<int> v(table.begin(), table.end());
//			for (int i = 0; i < n; ++i)
//			{
//				//�����ǰ��С�ڵ���n���������֣��������´γ��ֵ�λ���� 2*��ǰλ��                
//				//��֮��Ӧ�ĵ�ǰλ�� + n���������֣�����,�����´γ��ֵ�λ���� 2*��ǰλ�� + 1 
//				table[2 * i] = v[i];
//				table[2 * i + 1] = v[i + n];
//			}
//		}
//		for (int i = 0; i < num - 1; ++i)
//			cout << table[i] << " ";
//		cout << table[num - 1] << endl;
//	}
//	system("pause");
//	return 0;
//}

//�����2��MP3���λ��

int main()
{
	//�������� 
	int n;
	//���� 
	string order;
	while (cin >> n >> order)
	{
		//��n�׸������1��n , numΪ��굱ǰ���ڸ����ı��,firstΪ��ǰ��Ļ��ʾҳ�ĵ�һ�׸����ı�� 
		int num = 1, first = 1;
		if (n <= 4)//��������������4ʱ�����и���һҳ������ʾ�꣬���跭ҳ��firstʼ�ղ��� 
		{
			for (int i = 0; i <= n; ++i)
			{
				if (num == 1 && order[i] == 'U')
					num = n;
				else if (num == n && order[i] == 'D')
					num = 1;
				else if (order[i] == 'U')
					num--;
				else
					num++;
			}
			for (int i = 1; i < n - 1; ++i)
			{
				cout << i << " ";
			}
			cout << n << endl;
			cout << num << endl;
		}
		else//������������4ʱ����ʾ��ȫ���и�����Ҫ��ҳ����Ļ������ʾ4�׸��� 
		{
			for (int i = 0; i < order.size(); ++i)
			{
				//���ⷭҳ1 
				if (first == 1 && num == 1 && order[i] == 'U')
				{
					first = n - 3;
					num = n;
				}
				//���ⷭҳ2 
				else if (first == n - 3 && num == n && order[i] == 'D')
				{
					first = 1;
					num = 1;
				}
				//һ�㷭ҳ1 
				else if (first != 1 && num == first && order[i] == 'U')
				{
					first--;
					num--;
				}
				//һ�㷭ҳ2 
				else if (first != n - 3 && num == first + 3 && order[i] == 'D')
				{
					first++;
					num++;
				}
				//�������1 
				else if (order[i] == 'U')
					num--;
				//�������2 
				else
					num++;
			}
			for (int i = first; i < first + 3; i++)            
				cout << i << ' ';         
			cout << first + 3 << endl;       
			cout << num << endl;
		}
	}
	system("pause");
	return 0;
}
