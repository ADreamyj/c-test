#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>
#include<vector>
//��Ŀ���������������
//HRż������Щרҵ������������Щ�Ǽ����רҵ��ͬѧ��
//��������鿪����,���ַ�����:�ڹ��ϵ�һάģʽʶ����,
//������Ҫ���������������Ĵ��,������ȫΪ������ʱ��,����ܺý����
//����,��������а�������,�� ��Ӧ�ð���ĳ������,�������Աߵ�����
//���ֲ����أ�����:{6,-3,-2,7,-15,1,2,2},�����������Ĵ��Ϊ8
//(�ӵ�0 ����ʼ,����3��Ϊֹ)����һ�����飬�������Ĵ����������еĺ�
//����᲻�ᱻ������ס��(�������ĳ������� ��1)


//��������̬�滮
//״̬��
//		��״̬������Ϊ1��2��3������n��������͵����ֵ
//		F(i)������Ϊi������������ֵ�����ֶ��岻���γɵ��ƹ�ϵ������
//		F(i)����array[i]ΪĩβԪ�ص������͵����ֵ��
//״̬�ݹ飺
//		F(i) = max(F(i - 1) + array[i],array[i])
//		F(i) = ((F(i) > 0) ? F(i - 1) + array[i] : array[i])
//��ʼֵ�� F(0) = array[0]
//���ؽ����
//		maxsum������F(i)�ֵ����ֵ
//		maxsum = max(maxsum,F(i))

int  FindGreatestSumOfSubArray(std::vector<int> array)
{
	if (array.empty())
		return 0;
	int sum = array[0];
	int max = array[0];

	for (int i = 1; i < array.size(); i++)
	{
		sum = (sum > 0) ? sum + array[i] : array[i];
		max = (max > sum) ? max : sum;
	}
	return max;
}

//int main()
//{
//	std::vector<int> v = { 6, -3, -2, 7, -15, 1, 2, 2 };
//	std::cout << FindGreatestSumOfSubArray(v) << std::endl;
//	system("pause");
//	return 0;
//}