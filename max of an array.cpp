//how to find max element of an array
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
int max(int a[],int s)
{
	int i,pos,max;
	max=a[0];
	for(i=0;i<s;i++)
	{
		if(a[i]>max)
		max=a[i];
	}
	return max;
}
int main()
{
	int n=100,arr[n],size,max1;
	printf("Dear user please enter size of an array:\n");
	scanf("%d",&size);
	scan(arr,size);
	display(arr,size);
	max1=max(arr,size);
	printf("Dear user MAXIMUM element of given array is:%d\t",max1);
	return 0;	
}
