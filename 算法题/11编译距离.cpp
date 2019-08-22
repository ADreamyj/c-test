#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

//题目描述：
//	给定两个单词word1和word2，找出最小的修改步数，把word1转换为
//	word2，每个操作记为一步。
//	允许在一个word上进行如下3种得操作：
//	1）插入一个字符
//	2）删除一个字符
//	3）替换一个字符

//编译距离：是指两个字串之间，有一个转成另一个所需得最小编译操作次数

//方法：动态规划
//状态：
//		子状态：word1的前1，2，3，。。。m个字符转换为word2的前1，2，3
//		。。。n个字符所需要的编译距离
//		F(i,j)：word1的前i个字符与word2的前j个字符的编译距离
//状态递推：
//		F(i,j) = min{F(i - 1,j) + 1,F(i,j - 1) + 1,F(i - 1,j - 1)
//		+ (w1[i] == w2[j] ? 0 : 1)}
//		上式表达式中从删除，增加和替换中选择一个最小的操作数

//	1.	F(i,j - 1)：w1[1,,,i - 1]与w2[1,,,,j]的编译距离，
//		删除w1[i]的字符串--->F(i,j)
//	2.	F(i,j - 1)：w1[1,,,,i]于w2[1,,,,j - 1]的编译距离，
//		增加一个字符串---->F(i,j)
//	3.	F(i - 1,j - 1)：w1[1,,,,i - 1]于w2[1,,,,j - 1]的编译距离
//		如果w1[i]和w2[j]相同，不做任何的操作，编译距离不变
//		如果w1[i]于w2[j]不同，替换w1[i]与w2[j]---->F(i,j)
//初始化：
//		初始化一定要是确定的值，如果这里不加空串，初始值无法确定
//		F(i,0) = i : word与空串的编译距离，删除操作
//		F(0,i) = i : 空串与word的编译距离，增加操作
//返回结果：F(m,n)

int minDistance(std::string word1, std::string word2)
{
	if (word1.empty() || word2.empty())
		return std::max(word1.size(), word2.size());

	int len1 = word1.size();
	int len2 = word2.size();

	//F(i,j)进行初始化
	std::vector<std::vector<int>> v( 1 + len1, std::vector<int>(1 + len2, 0) );
	for (int i = 0; i <= len1; i++)
	{
		v[i][0] = i;
	}

	for (int j = 0; j <= len2; j++)
	{
		v[0][j] = j;
	}

	for (int i = 1; i <= len1; ++i)
	{
		for (int j = 1; j <= len2; ++j)
		{
			if (word1[i - 1] == word2[j - 1])
			{
				v[i][j] = 1 + std::min(v[i][j - 1], v[i - 1][j]);
				v[i][j] = std::min(v[i][j], v[i - 1][j - 1]);
			}
			else
			{
				v[i][j] = 1 + std::min(v[i][j - 1], v[i - 1][j]);
				v[i][j] = std::min(v[i][j], 1 + v[i - 1][j - 1]);
			}
		}
	}
	return v[len1][len2];
}
int main()
{
	std::string word1 = "hello";
	std::string word2 = "hell";
	std::cout << minDistance(word1, word2) << std::endl;

	system("pause");
	return 0;
}