#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>
using namespace std;

//�����1�����üӼ��˳����ӷ�
//int main()
//{
//	int a, b;
//	while (cin >> a >> b)
//	{
//		while (b)
//		{
//			int num = a^b; //�õ���Ӻ󲻰�����λ������
//			int carry = (a & b) << 1;//�õ�������ӵĽ�λ
//			a = num;//���������ӣ�ֱ����λΪ0
//			b = carry;
//		}
//		cout << a << endl;
//	}
//	return 0;
//}

//�����2��������
//д��һ
//int main()
//{
//	double a, b, c;
//	while (cin >> a >> b >> c)
//	{
//		if (a + b > c && b + c > a && a + c > b)
//		{
//			cout << "Yes" << endl;
//		}
//		else
//			cout << "No" << endl;
//	}
//	return 0;
//}

//д����
//#define ADD(x, y) ((x)+(y)) 
//#define CMP(x, y) ((x) > (y)) 
//int main() 
//{
//	double a, b, c;  
//	while (std::cin >> a >> b >> c)  
//	{   
//		//�����߽���������������бȽ�   
//		if (CMP(ADD(a, b), c) &&  CMP(ADD(b, c), a) && CMP(ADD(a, c), b)) 
//		{      
//			std::cout << "Yes" << std::endl; 
//		}
//		else
//		{   
//			std::cout << "No" << std::endl;   
//		}   
//	}   
//	return 0;
//}
