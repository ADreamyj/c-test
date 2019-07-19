#define _CRT_SECURE_NO_WARNINGS  1


#include<iostream>
#include<vector>
#include<string>

//编程题1：两数之和
//class Solution {
//public:
//	std::vector<int> twoSum(std::vector<int>& nums, int target)
//	{
//		int n = nums.size();
//		std::vector<int> result;
//		for (int i = 0; i < n - 1; i++)
//		{
//			for (int j = i + 1; j < n; j++)
//			{
//				if (nums[i] + nums[j] == target)
//				{
//					result.push_back(i);
//					result.push_back(j);
//					break;
//				}
//			}
//		}
//		return result;
//	}
//
//};
////编程题2：大写转小写
//int main()
//{
//	std::string s;
//	while (std::cin >> s)
//	{
//		for (int i = 0; i < s.size(); ++i)
//		{
//			if ('A' <= s[i] && s[i] <= 'Z')
//				s[i] = char(s[i] + 32);
//		}
//		std::cout << s << std::endl;
//	}
//	return 0;
//}
//
//
////编程题3：空瓶子问题
//
//int main()
//{
//	int n;
//	while (std::cin >> n)
//	{
//		if (n == 1)
//			break;
//		int num = 0;
//		while (n > 2)
//		{
//			num += n / 3;
//			n = n % 3 + n / 3;
//		}
//		if (n == 2)
//			num++;
//		std::cout << num << std::endl;
//	}
//	return 0;
//}
////编程题4：倒置字符串
//int main()
//{
//	std::vector<std::string> v;
//	std::string s;
//	while (std::cin >> s)
//	{
//		v.push_back(s);
//	}
//	for (int i = v.size() - 1; i > 0; --i)
//	{
//		std::cout << v[i] << " ";
//	}
//	std::cout << v[0] <<std::endl;
//	system("pause");
//	return 0;
//}



//编程题1：找出字符串中最大的数字串

//int main()
//{
//	std::string str1, cur, ret;
//	std::cin >> str1;
//	for (int i = 0; i <= str1.size(); ++i)
//	{
//		if (str1[i] <= '9' && str1[i] >= '0')
//		{
//			cur += str1[i];
//		}
//		else
//		{
//			if (ret.size() < cur.size())
//				ret = cur;
//			else
//				cur.clear();
//		}
//	}
//	std::cout << ret << std::endl;
//	system("pause");
//	return 0;
//
//}

//编程题2：n个数字中出现大于等于n/2的数

//int main()
//{
//	int n;
//	std::vector<int> v;
//	while (std::cin >> n)
//	{
//		v.push_back(n);
//	}
//
//		int temp = v[0];
//		int count = 1;
//		for (int i = 1; i < v.size(); i++)
//		{
//			if (temp == v[i])
//				count++;
//			else
//				count--;
//
//			if (count == 0)
//			{
//				temp = v[i];
//				count++;
//			}
//				
//		}
//		std::cout << temp << std::endl;
//
//	system("pause");
//	return 0;
//}
