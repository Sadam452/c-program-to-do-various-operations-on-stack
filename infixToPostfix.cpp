#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define size 100
char stack[size];
int top=-1;
void push(char item)
{
	if(top>=size-1)
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
		return stack[top--];
	}
}
int operator_chk(char exm)
{
	if(exm=='^' || exm=='*' || exm=='/' || exm=='+' || exm=='-')
	{
		return 1;
	}
	else
	{
		return 0;
	}
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
void InfixToPostfix(char inf[],char post[])
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
		else if(isdigit(item) || isalpha(item))
		{
			post[j]=item;
			j++;
		}
		else if(operator_chk(item)==1)
		{
			x=pop();
			while(operator_chk(x)==1 && order(item)<=order(x))
			{
				post[j]=x;
				j++;
				x=pop();
			}
			push(x);
			push(item);
		}
		else if(item==')')
		{
			x=pop();
			while(x!='(')
			{
				post[j]=x;
				j++;
				x=pop();
			}
		}
		else
		{
			printf("\n Invalid infix expression\n");
			getchar();
			exit(1);
		}
		i++;
		item=inf[i];
	}
	if(top>0)
	{
		printf("\n Invalid infix exp");
		getchar();
		exit(1);
	}
	post[j]='\0';
	
}
int main()
{
	char infix[size],postfix[size];
	printf("ASSUMPTION: SINGLE LETTER AND SIMGLE DIGITS CHARACTERS ONLY:");
	printf("\nEnter infix expression:");
	gets(infix);
	InfixToPostfix(infix,postfix);
	printf("POSTFIX EXPRESSION IS:");
	puts(postfix);
	return 0;
}
