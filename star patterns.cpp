#include<stdio.h>
int main()
{
	int limit;
	printf("Dear user enter the limit e.g. 5");
	scanf("%d",&limit);
	int tmp=limit;
	for(int i=0;i<limit;i++)
	{
		for(int j=0;j<=tmp;j++)
	{
		printf(" ");
	}
	for(int k=0;k<=2*i;k++)
	{
		printf("*");
	}
	tmp--;
	printf("\n");
	}
	return 0;
}
