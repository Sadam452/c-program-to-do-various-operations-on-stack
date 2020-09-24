//how to delete an element in array 
//by sadam; 12 sep
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
void delete_ele(int a[],int *s)
{
	int i,tmp,pos;
	printf("Dear user, please enter the element you want to delete:");
	scanf("%d",&tmp);
	for(i=0;i<*s;i++)
	{
		if(a[i]==tmp)
		{
		pos=i;
		break;}
	}
	for(i=pos;i<*s-1;i++)
	{
		a[i]=a[i+1];
	}
	*s=*s-1;
}
int main()
{
	int n=100,arr[n],size;
	printf("Dear user, please enter the size of an array:");
	scanf("%d",&size);
	scan(arr,size);
	display(arr,size);
	delete_ele(arr,&size);
	display(arr,size);
	return 0;
}
