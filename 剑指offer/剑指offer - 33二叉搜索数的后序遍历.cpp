#define _CRT_SECURE_NO_WARNINGS  1

//题目：输入一个整数数组，判断该数组中是不是某二叉搜索树的后序
//遍历结果，如果是则返回true，否则返回false。假设输入的数组的
//任意连个数字都互不相同。例如：输入数组{5，7，6，9，11，10，8}
//则返回true.


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