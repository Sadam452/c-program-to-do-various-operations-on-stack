//program to pop push peep
//by sadam 12 sep
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define size 50
int stack[size],top=-1;
void push(int item)
{
	if(top==size-1)
	printf("sorry! stack is already full\n");
	else
	stack[++top]=item;
}
int pop()
{
	if(top==-1)
	{
	printf("sorry! you can't delete an element from an empty stack\n");
	exit(1);}
	else
	return stack[top--];
}
int view()
{
	int i;
	if(top==-1)
	printf("sorry!, nothing to print\n");
	for(i=0;i<=top;i++)
	printf("element at %dth position is %d\n",i,stack[i]);
}
int peep()
{
	printf("top element is %d\n",stack[top]);
}
int main()
{
	int ch,item;
	printf("Dear user please 1 for push, 2 for pop, 3 for view, 4 for peep, 5 for exit\n");
	while(1)
	{
		printf("Dear user, what is your choice now:");
		scanf("%d",&ch);
		if(ch==1)
		{
			printf("please enter the element u want to push:");
			scanf("%d",&item);
			push(item);
		}
		else if(ch==2)
		{
			item=pop();
			printf("deleted element is %d\n",item);
		}
		else if(ch==3)
		{
			view();
		}
		else if(ch==4)
		{
			peep();
		}
		else if(ch==5)
		{
			exit(1);
		}
		else
		{
	    printf("wrong choice entered, program is terminating!");
		exit(1);}
	}
return 0;	
}
