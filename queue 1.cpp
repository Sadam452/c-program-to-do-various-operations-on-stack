//by sadam 
//10 sep 20
#include<stdio.h>
#include<stdlib.h>
#define max 6
void check(int);
int Queue[max];
static int count=0;
static int decount=0;
int front=-1,rear=-1;
void enqueue(int item)
{
	if(front==-1 && rear==-1)
	{
		rear++;
		Queue[rear]=item;
		front=0;
		++count;
		printf("hello inserted, count is:.. %d\n",count);
	}
	else if(rear==max-1)
	{
	check(item);// to check whether there is any available space
	}
	else
	{
		rear++;
		Queue[rear]=item;
		++count;
		printf("hello inserted,count is: %d\n",count);
	}
}
int dequeue()
{
	if(front==-1 && rear==-1)
	{
	printf("underflow");	
	}
	else if(front<rear)
	{
			++decount;
		printf("hello deleted,decount: %d\n",decount);
			return Queue[front++];
	}
	else if(front==rear)
	{
		int item;
		item=Queue[front];
		front=rear=-1;
		++decount;
		printf("hello deleted,decount: %d\n",decount);
		return item;
	}
}
void view()
{
	int i;
	for(i=front;i<=rear;i++)
	printf("%d\t",Queue[i]);
}
void check(int item)
{
	if(count>=max-1 && decount>=1)
	{
		for(int i=0;i<=decount;i++)
		{
			front--;
			for(int i=front;i<max-1;i++)
		    {
			Queue[i]=Queue[i+1];
	     	}
	     	rear--;
	    }
	    decount=0;
	    enqueue(item);
	}
	else
	printf("it is really overflow\n");
}
int main()
{
	int ch,item;
		while(1)
	{
		printf("please enter 1 for enqueue\n 2 for dequeue\n 3 for view\n 4 for exit: \n So what is your choice:");
     	scanf("%d",&ch);
		if(ch==1)
		{
			printf("enter element;");
			scanf("%d",&item);
			enqueue(item);
		}
		else if(ch==2)
		{
			dequeue();
		}
		else if(ch==3)
		{
			view();
		}
		else if(ch==4)
		{
			exit(1);
		}
	}
}











