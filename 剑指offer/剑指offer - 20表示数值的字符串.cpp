#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>

//��Ŀ����ʾ��ֵ���ַ���
//������һ�����������ж��ַ������Ƿ��ʾ��ֵ������������С����
//���磺�ַ���"+100","5e2","-123","3.1416"��"-1E-16"����ʾ��ֵ��
//��"12e","1a3.14","1.2.3","+-5"��"12e + 5.4"������

//����˼·��
//��ʾ��ֵ���ַ����ı�ʾ�������£�A.[.[B]][e/E C]����.B[e/E C]
//����A��ʾ�������֣�B�������С�����֣�C�������'e'����'E'Ϊ��ֵ
//��ָ�����֡�

//С�������û���������֣�������Ҳ����û��С������
//��������Ҳ�����໥���ڡ�

//����ǰ����Դ�+-��
//ָ������Ҳ���Դ�+-��

//�������£�
bool panduan1(const char** str);//�з��ŵ�λ������ֵģʽ�е�A��B
bool panduan2(const char** str);//С��������޷�������B

bool isNumeric(const char* str)
{
	if (str == nullptr)
		return false;

	bool flag = panduan1(&str);

	if (*str == '.')
	{
		++str;
		//����һ�д���||�����ã�
		//1.С������û���������֣���.123 = 0.123
		//2.С����������û�����֣���233.==233.0
		//��Ȼ��С����ǰ��ͺ��涼���������֡�
		flag = flag || panduan2(&str);
	}

	if (*str == 'e' || *str == 'E')
	{
		++str;
		//����һ�д���&&������
		//1.��e��Eǰ��û�����ֵ�ʱ�������ַ������ܱ�ʾ���֡�
		//2.��e��E����û��������ʱ�������ַ������ܱ�ʾ���֡�
		flag = flag && panduan1(&str);
	}
	return flag && *str == '\0';
}

bool panduan1(const char** str)//�з��ŵ�λ������ֵģʽ�е�A��B
{
	if (**str == '+' || **str == '-')
		++(*str);
	return panduan2(str);
}

bool panduan2(const char** str)//С��������޷�������B
{
	const char* before = *str;
	while (**str != '\0' && **str >= '0' && **str <= '9')
		++(*str);

	return *str > before;
}

int main()
{
	const char* str = "12e";
	std::cout << isNumeric(str) << std::endl;
	system("pause");
	return 0;
}