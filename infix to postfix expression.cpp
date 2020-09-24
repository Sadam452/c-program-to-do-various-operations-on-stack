#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define max 100
char stack[max];
int top=-1;
void push(char item)
{
	if(top>=max-1)
	{
		printf("\nSTACK OVERFLOW");
	}
	else
	{
		top=top+1;
		stack[top]=item;
	}
}
char pop()
{
	char item;
	if(top<0)
	{
	printf("STACK UNDER FLOW");
	getchar();
	exit(1);
	}
	else
	{
		item=stack[top];
		top=top-1;
		return(item);
	}
}
int operator_chk(char item)
{
	if(item=='^'||item=='*'||item=='-'||item=='+'||item=='/')
{
		return 1;}
	else
	{
	return 0;}
}
int order(char opr)
{
	if(opr=='^')
	{
		return(3);
	}
	else if(opr=='*' || opr=='/')
	{
		return(2);
	}
	else if(opr=='+' || opr=='-')
	{
		return(1);
	}
	else
	{
		return(0);
	}
	
}
void infixToPostfix(char inf[],char post[])
{
	int i=0,j=0;
	char item,x;
	push('(');
	strcat(inf,")");
	item=inf[i];
	while(item!='\0')
	{
		if(item=='(')
		{
		push(item);
	}
		else if(isdigit(item)||isalpha(item))
		{
			post[j]=item;
			j++;
		}
		else if(operator_chk(item)==1)
		{
		x=pop();
		while(operator_chk(item)==1 && order(x)>=order(item))
		{
			post[j]=x;
			j++;
			x=pop();
			}
			push(x);
			push(item);	
		
		}
		else if(item=')')
		{
			x=pop();
			while(item!='(')
			{
			post[j]=x;
			j++;
			x=pop();
	     	}
		
		}
		else
		printf("invalid expression");
		i++;
		item=inf[i];
	}
	if(top>0)
	{
		printf("invalid exp");
		getchar();
		exit(1);
	}
	post[j]='\0';
}
int main()
{
	char str[max],post[max];
	printf("ENTER ANY INNFIX EXPRESSION: ASSUME SINGLE DIGIT AND ALPHABETS ONLY");
	gets(str);
	infixToPostfix(str,post);
	printf("YOUR ANSWER IS:");
	puts(post);
	return 0;
	
}
























