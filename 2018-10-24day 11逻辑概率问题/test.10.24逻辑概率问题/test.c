1.
#include<stdio.h>
void print()
{
	int a,b,c,d,e;
	for(a=1;a<=5;a++)
	{
		for(b=1;b<=5;b++)
		{
			for(c=1;c<=5;c++)
			{
				for(d=1;d<=5;d++)
				{
					for(e=1;e<=5;e++)
					{
						if(((b==2 && a!=3)||(b!=2 && a==3))&&
						((b==2 && e!=4)||(b!=2 && e==4))&&
						((c==1 && d!=2)||(c!=1 && d==2))&&
						((c==5 && d!=3)||(c!=3 && d==5))&&
						((e==4 && a!=1)||(e!=4 && a==1)))
						{
							if((a*b*c*d*e)==120)
							{
								printf("a=%d,b=%d,c=%d,d=%d,e=%d",a,b,c,d,e);
							}
						}
					}
				}
			}
		}
	}
}
int main()
{
	print();
	return 0;
}
2.
#include<stdio.h>
void print()
{
	char killer= '0';
	for(killer='a';killer<='d';killer++)
	{
		if((killer!='a')+(killer=='c')+
			(killer=='d')+(killer!='d')==3)
		{
			printf("说谎话的人是：%c\n",killer);
		}
	}
}
int main()
{
	print();
	return 0;
}

3.
#include<stdio.h>
#define n  10
int main()
{
	int i,j,a[n][n];
	for(i = 0;i<n;i++)
	{
		a[i][i] = 1;
		a[i][0] = 1;
	}
	for(i = 2;i<n;i++)
		for(j = 1;j<=i-1;j++)
			a[i][j] = a[i-1][j-1]+a[i-1][j];
	for(i = 0;i<n;i++)
	{
        for(j = 0;j <3*(n-i)/2; j++)
		{
			printf(" ");
		}
		for(j = 0;j<=i;j++)
		{
			printf("%3d ",a[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
