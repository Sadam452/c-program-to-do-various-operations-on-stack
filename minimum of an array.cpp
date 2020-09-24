//how to find minimum element of an array
// sadam; 12 sep
#include<stdio.h>
#include<conio.h>
void scan(int a[],int s)
{
	int i;
	printf("Dear user,enter the elements of an array:");
	for(i=0;i<s;i++)
	{
		scanf("%d",&a[i]);
	}
}
void display(int a[],int s)
{
	int i;
	printf("Dear user your array is:\n");
	for(i=0;i<s;i++)
	printf("Element at %dth index is %d\n",i,a[i]);
}
int min(int a[],int s)
{
	int i,pos,min;
	min=a[0];
	for(i=0;i<s;i++)
	{
		if(a[i]<min)
		min=a[i];
	}
	return min;
}
int main()
{
	int n=100,arr[n],size,min1;
	printf("Dear user please enter size of an array:\n");
	scanf("%d",&size);
	scan(arr,size);
	display(arr,size);
	min1=min(arr,size);
	printf("Dear user MINIMUM element of given array is:%d\t",min1);
	return 0;	
}
