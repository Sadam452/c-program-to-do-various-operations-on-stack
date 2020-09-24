//by sadam hussain
//dt: 14 sep 2020
#include<stdio.h>
#include<stdlib.h> //for exit(1) to work
#include<math.h>
#include<string.h>
#define max 100
double stack[max];
int top=-1;
void push(double item)
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
double pop()
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
int operator_chk(char x)
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
float prefixSol(char str,double a,double b)
{
	if(str=='+')
	return (a+b);
	else if(str=='-')
	return (a-b);
	else if(str=='*')
	return (a*b);
	else if(str=='/')
	return (a/b);
	else if(str=='^')
	return pow(a,b);
	
}
int main()
{
	int i=0,l=0;
	double result=0,c=0,a,b;
	char str[max];
	printf("Dear user , please enter any valid prefix expression to get solution\n");
	gets(str);
	l=strlen(str); //finds length of string
	printf("length of entered string is= %d\n",l);
	//strrev(str);
	//puts(str);
	for(i=l-1;i>=0;i--)
	{
		if(operator_chk(str[i])==0)
		{
			push(str[i]-48);
		}
		else if(operator_chk(str[i])==1)
		{
			a=pop();
			b=pop();
			c=prefixSol(str[i],a,b);
			push(c);
		}
	}
	result=pop();
	printf("wow! here is the solution %lf\n",result);
	return 0;
}
