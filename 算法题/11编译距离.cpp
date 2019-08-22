#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

//��Ŀ������
//	������������word1��word2���ҳ���С���޸Ĳ�������word1ת��Ϊ
//	word2��ÿ��������Ϊһ����
//	������һ��word�Ͻ�������3�ֵò�����
//	1������һ���ַ�
//	2��ɾ��һ���ַ�
//	3���滻һ���ַ�

//������룺��ָ�����ִ�֮�䣬��һ��ת����һ���������С�����������

//��������̬�滮
//״̬��
//		��״̬��word1��ǰ1��2��3��������m���ַ�ת��Ϊword2��ǰ1��2��3
//		������n���ַ�����Ҫ�ı������
//		F(i,j)��word1��ǰi���ַ���word2��ǰj���ַ��ı������
//״̬���ƣ�
//		F(i,j) = min{F(i - 1,j) + 1,F(i,j - 1) + 1,F(i - 1,j - 1)
//		+ (w1[i] == w2[j] ? 0 : 1)}
//		��ʽ���ʽ�д�ɾ�������Ӻ��滻��ѡ��һ����С�Ĳ�����

//	1.	F(i,j - 1)��w1[1,,,i - 1]��w2[1,,,,j]�ı�����룬
//		ɾ��w1[i]���ַ���--->F(i,j)
//	2.	F(i,j - 1)��w1[1,,,,i]��w2[1,,,,j - 1]�ı�����룬
//		����һ���ַ���---->F(i,j)
//	3.	F(i - 1,j - 1)��w1[1,,,,i - 1]��w2[1,,,,j - 1]�ı������
//		���w1[i]��w2[j]��ͬ�������κεĲ�����������벻��
//		���w1[i]��w2[j]��ͬ���滻w1[i]��w2[j]---->F(i,j)
//��ʼ����
//		��ʼ��һ��Ҫ��ȷ����ֵ��������ﲻ�ӿմ�����ʼֵ�޷�ȷ��
//		F(i,0) = i : word��մ��ı�����룬ɾ������
//		F(0,i) = i : �մ���word�ı�����룬���Ӳ���
//���ؽ����F(m,n)

int minDistance(std::string word1, std::string word2)
{
	if (word1.empty() || word2.empty())
		return std::max(word1.size(), word2.size());

	int len1 = word1.size();
	int len2 = word2.size();

	//F(i,j)���г�ʼ��
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