//how to insert an element in an array
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
void insert(int a[],int *s)
{
	int target,item,i,pos;
	printf("Dear user please enter the target element at which u want to insert the element:\n");
	scanf("%d",&target);
	printf("Dear user please enter the item u want to insert:\n");
	scanf("%d",&item);
	for(i=0;i<*s;i++)
	{
		if(a[i]==target)
		{pos=i;
		break;
		}
	}
	for(i=*s+1;i>pos;i--)
	{
		a[i]=a[i-1];
	}
	a[pos]=item;
	*s=*s+1;
}
int main()
{
	int n=100,arr[n],size;
	printf("Dear user please enter size of an array:\n");
	scanf("%d",&size);
	scan(arr,size);
	display(arr,size);
	insert(arr,&size);
	display(arr,size);
	return 0;
}
