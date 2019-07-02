#define _CRT_SECURE_NO_WARNINGS  1

//1.大小端问题

//概念：
//所谓的大端模式，是指数据的低位保存在内存的高地址中，而数据的高位，保存在内存的低地址中；
//所谓的小端模式，是指数据的低位保存在内存的低地址中，而数据的高位保存在内存的高地址中。

//为什么会有大小端模式之分呢？
//这是因为在计算机系统中，我们是以字节为单位的，
//每个地址单元都对应着一个字节，一个字节为8bit。
//但是在 C语言中除了8bit的char之外，还有16bit的short型，
//32bit的long型（要看具体的编译器），
//另外，对于位数大于8位的处理器，例如16位或者32位的处理器，
//由于寄存器宽度大于一个字节，那么必然存在着一个如果将多个字节安排的问题。
//因此就导致了大端存储模式和小端存储模式。
//例如一个16bit的short型x，在内存中的地址为0x0010，x的值为0x1122，
//那么0x11为高字节，0x22为低字节。
//对于大端模式，就将0x11放在低地址中，
//即0x0010中，0x22放在高地址中，即0x0011中。
//小端模式，刚好相反。我们常用的X86结构是小端模式，
//而KEIL C51则为大端模式。很多的ARM，DSP都为小端模式。
//有些ARM处理器还可以由硬件来选择是大端模式还是小端模式。

#include<iostream>
//union ss
//{
//	short int i;
//	char c[2];
//};
//
//void main()
//{
//	union ss x;
//	x.c[0] = 10;
//	x.c[1] = 1;
//	printf("%d", x.i);
//	system("pause");
//}
//由于定义的共用体ss中的变量i和c共同占有2个字节的地址，而编译器VC是小端模式，

//故字符数组c和短整形ｉ在内存中的分布情况是这样的：  
//                    地址1                        地址0

//c[]:            0000 0001(c[1])               0000 1010（c[0]）

// i :            0000 0001                     0000 1010

//	因此变量i的值为：1 * 256 ^ 1 + 10 * 256 ^ 0 = 266!!


//#include <stdio.h>
//int main(void)
//{
//	short int x;
//	char x0, x1;
//	x = 0x1122;
//
//	x0 = (&x)[0];                   //低地址单元
//	x1 = ((char *)&x)[1];           //高地址单元
//
//	printf("%0x\n", x0);//22
//	printf("%0x\n", x1);//11
//	system("pause");
//	return 0;
//}

//#include <stdio.h>
//union ss
//{
//	short int i;
//	char c[2];
//};
//
//int main(void)
//{
//	union ss x;
//	x.c[0] = 10;
//	x.c[1] = 1;
//
//	printf("%0x\n", x.i);
//	system("pause");
//	return 0;
//}
//内存中为其分配了2个字节的空间所以结果10a前还省略了一个0，
//过完整的结果应该是：010a，高八位01对应着c[1], 低八位0a对应着c[0]!

//1.编程题：二进制的插入

//class Init
//{
//public:
//	int init(int m, int n, int x, int y)
//	{
//		n == n << x;
//		return  m | n;
//	}
//};

//2.编程题：查找组成一个偶数最接近的两个素数
//并且两个素数的差值最小

#include<iostream>
#include<algorithm>
using namespace std;
bool isprime(int n)
{
	int m = sqrt(n);
	for (int i = 2; i <= m; ++i)
	{
		if (n%i == 0)
		{
			return false;
		}
	}
	return true;
}
int main()
{
	int n;
	int i;
	while (cin >> n)
	{
		for ( i = n / 2; i > 0; --i)
		{
			if (isprime(i) && isprime(n - i))
			break;
		}
		cout << i << endl;
		cout << n - i << endl;
	}
	system("psuse");
	return 0;
}