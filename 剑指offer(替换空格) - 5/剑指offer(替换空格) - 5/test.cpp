#define _CRT_SECURE_NO_WARNINGS  1
#include<iostream>
using std::cout;
using std::endl;

//��Ŀ����ʵ��һ�����������ַ����е�ÿ���ո��滻�ɡ�%20����
//���磬���롰we are happy��,�������we%20are%20happy����


//�����������ԣ��кܶ��ֽ���ķ��������ǿ��ǵ�ʱ�临�ӶȵĻ�
//���ǿ��Զ�������ָ�룬�ȼ���ԭ������+�ո�ĳ���*2
//Ȼ����Ǹ��㿪ʼ��' 'ת��Ϊ'%20';
//�ٽ����ǿո����ԭ�ⲻ���ķŵ����档

void test(char string[], int lenght)
{
	if (string == nullptr || lenght <= 0)
		return ;
	int firstlenght = 0;
	int endlenght = 0;
	for (int i = 0; i < lenght; i++)
	{
		++firstlenght;
		if (string[i] == ' ')
			++endlenght;
	}
	endlenght = firstlenght + 2 * endlenght;
	while (firstlenght >= 0 && endlenght > firstlenght)
	{
		if (string[firstlenght] == ' ')
		{
			string[endlenght--] = '0';
			string[endlenght--] = '2';
			string[endlenght--] = '%';
		}
		else
		{
			string[endlenght--] = string[firstlenght];
		}
		--firstlenght;
	}
	for (int i = 0; i < 50; i++)
	{
		cout << string[i] << " ";
	}
}
int main()
{
	char string[] = "  we are  happy  ";
	test(string, 50);
	system("pause");
	return 0;
}