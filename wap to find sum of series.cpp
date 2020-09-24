//wap to find sum of the series 1/1-1/2+1/3-1/4+1/5-1/6+...+1/n
#include<stdio.h>
int main()
{
	int limit;
	float sum=0.0;
	printf("Dear user enter the limit\n");
	scanf("%d",&limit);
	for(int i=1;i<=limit;i++)
	{
		if(i%2==0)
		sum=sum-(float)1/i;
		else if(i%2!=0)
		sum=sum+(float)1/i;
	}
	printf("sum of given series upto provided limit is: %f\n",sum);
	return 0;
}
