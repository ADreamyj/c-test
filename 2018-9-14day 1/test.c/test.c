1.
#include<stdio.h>
#include<math.h>
int main()
{
   int i = 0;
   int count = 0;
   for(i=100;i<=200;i++)
   {
	  int j = 0;
	  for(j = 2;j<sqrt(i);j++)
	  {
		if(i%j == 0)
			break;
	  }
	    if(j>sqrt(i))
	    {
		  count++;
		  printf("%d ",i);
	    }
  }
  printf("\ncount = %d\n",count);
  return 0;
}
2.
#include<stdio.h>
int main()
{
	int i = 0;
	int j = 0;
	for(i=1;i<=9;i++)
	{
		for(j=1;j<=i;j++)
			printf("%d*%d = %d ",i,j,i*j);
	        printf("\n");
	}
	return 0;
}
3.
#include<stdio.h>
int main()
{
	int i = 0;
	int count =0;
	for(i=1000;i<=2000;i++)
	{
		if(((i%4==0)&&(i%100!=0))||(i%400==0))
		{
			count++;
		printf("%d ",i);
        
		}
	}
	printf("\ncount=%d\n",count);
    return 0;
}
