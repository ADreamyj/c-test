#define _CRT_SECURE_NO_WARNINGS  1

//��Ŀ������һ���������飬�жϸ��������ǲ���ĳ�����������ĺ���
//���������������򷵻�true�����򷵻�false����������������
//�����������ֶ�������ͬ�����磺��������{5��7��6��9��11��10��8}
//�򷵻�true.


//#include<iostream>
//#include<vector>
//
//
//
//	bool judge(std::vector<int>& a, int l, int r)
//	{
//		if (l >= r) return true;
//		int i = r;
//		while (i > l && a[i - 1] > a[r]) 
//			--i;
//		for (int j = i - 1; j >= l; --j)
//		{
//			if (a[j] > a[r])
//				return false;
//		}
//		
//		return judge(a, l, i - 1) && (judge(a, i, r - 1));
//	}
//
//	bool VerifySquenceOfBST(std::vector<int> a) {
//		if (!a.size()) return false;
//		return judge(a, 0, a.size() - 1);
//	}
//
//	int main()
//	{
//		std::vector<int> v = { 5, 7, 6, 9, 11, 10, 8 };
//		VerifySquenceOfBST(v);
//		system("pause");
//		return 0;
//	}