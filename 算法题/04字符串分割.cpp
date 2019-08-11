#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>
#include<string>
#include<unordered_set>
#include<vector>

//��Ŀ���ַ����ָ�
//����һ��s����һ���ǵ�dict��ȷ��s���Էָ��һ�������ֵ�ʵ�
//�ո�ָ����С�

//���磬����
//s = ��leetcode����
//dict = [��leet������code��]��
//
//����true����Ϊ��leetcode�����Էָ�Ϊ��leetcode����

//��������̬�滮
//״̬��
//		��״̬��ǰ1��2��3������n���ַ��ܷ���ݴʵ��еĴʱ��ɹ��ִʡ�
//		F(i)��ǰi���ַ��ܷ���ݴʵ��еĴʱ��ɹ��ִ�
//״̬�ݹ飺
//		F(i)��true{j < i && F(j) && substr[j + 1,i]���ڴʵ����ҵ�}
//		OR false  ��jС��i�У�ֻҪ�ҵ�һ��F(j)Ϊtrue�����Ҵ�j + 1��
//		i֮����ַ������ڴʵ����ҵ�����F(i)Ϊtrue
//��ʼֵ��
//		���ڳ�ʼֵ�޷�ȷ���ġ���������һ��������ʵ������Ŀ�״̬����Ϊ
//		״̬����ʼ��״̬��ֵ��Ҫ��֤״̬�ĵ��ƿ�����ȷ��˳����ִ��
//		����ȡʲôֵ����ͨ���򵥵����ӽ�����֤
//		F(0) = true;
//���ؽ����F(n);


bool wordBreak(std::string s, std::unordered_set <std::string> &dict)
{
	if (s.empty())
		return false;
	if (dict.empty())
		return false;

	int len = s.length();
	std::vector<bool> v(len + 1, false);
	v[0] = true;
	for (int i = 1; i <= len; i++)
	{
		for (int j = 0; j < i; j++)//j = i - 1; j >= 0; j--
		{
			if (v[j] && dict.find(s.substr(j, i - j)) != dict.end())
			{
				v[i] = true;
				break;
			}
		}
	}
	return v[len];
} 


//int main()
//{
//	std::string s = "leetcode";
//	std::unordered_set <std::string> dict = { "leet", "code" };
//	std::cout << wordBreak(s, dict) << std::endl;
//	system("pause");
//	return 0;
//}