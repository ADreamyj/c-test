                   day 2
#include<stdio.h>
int main()
{
	int i = 0;
	int j = 0;
	int temp = 0;
	scanf("%d %d",&i,&j);
	temp = i;
	i = j;
	j = temp;
	printf("交换后的数为:%d %d\n",i,j);
	return 0;
}
#include<stdio.h>
int main()
{
	int a,b;
	scanf("%d %d",&a,&b);
	a = a^b;
	b = b^a;
	a = a^b;
	printf("交换后的数是:%d %d\n",a,b);
	return 0;
}
#include<stdio.h>
int main()
{
	int arr[10] = {0};
	int i = 0;
	int max = 0;
	for(i=0;i<=9;i++)
	{
		scanf("%d",&arr[i]);
	}
	max = arr[0];
	for(i=1;i<=9;i++)
	{
		if(arr[i]>max)
			max = arr[i];
	}
	printf("最大的数为:%d\n",max);
}
#include<stdio.h>

void swap(int* pi,int* pj)
{
	int tmp = *pi;
	*pi = *pj;
	*pj = tmp;
}
int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	if(a<b)
		swap(&a,&b);
	if(a<c)
		swap(&a,&c);
	if(b<c)
		swap(&b,&c);
	printf("从大到小依次为:%d %d %d\n",a,b,c);
}
#include<stdio.h>
int main()
{
	int a,b,c;
	scanf("%d%d",&a,&b);
    if(a<b)
	{
		c = a;
		a = b;
		b = a;
	}
	while(a%b!=0)
	{
		c = a%b;
		a = b;
		b = c;
	}
	printf("%d",b);
	return 0;
}
