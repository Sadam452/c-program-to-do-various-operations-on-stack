#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define max 100
float stack[max];
int top=-1;
void push(float item)
{
	if(top>=max-1)
	{
		printf("\nSTACK OVERFLOW");
		getchar();
		exit(1);
	}
	else
	{
		top=top+1;
		stack[top]=item;
	}
}
float pop()
{
	if(top<0)
	{
	printf("STACK UNDER FLOW");
	getchar();
	exit(1);
	}
	else
	{
		return stack[top--];
	}
}
int operator(char x)
{
	if(x=='^' || x=='*' || x=='/' || x=='+' || x=='-')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
float postfixToSol(char str,float a,float b)
{
	if(str=='+')
	return b+a;
	else if(str=='-')
	return b-a;
	else if(str=='*')
	return b*a;
	else if(str=='/')
	return b/a;
	else if(str=='^')
	return pow(b,a);
	
}
int main()
{
	float a,b,c,result;
	char str[max];
	printf("ENTER ANY POST FIX EXPRESSION TO GET SOLUTION:");
	gets(str);
	int i=0;
	while(str[i]!='\0')
	{
		if(operator(str[i])==0)
		{
		push(str[i]-48);
     	}
     	else if(operator(str[i])==1)
     	{
     		a=pop();
     		b=pop();
     		c=postfixToSol(str[i],a,b);
     		push(c);
		 }
		 i++;
	}
	result=pop();
	printf("YOUR ANSWER IS BEING CLCULATED AS:%f\n",result);
	puts("Dear user hit any key to exit program: ");
	getchar();
	exit(1);
	puts("BYE!!!");
}












