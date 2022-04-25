/*
	Shantanu Dnyaneshwar Ghumatkar
	Roll no :672
	
	Assignment 3
	evaluation of Postfix expression
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include"validatio.h"
int i,num;
int top=-1;
int st[100];
char post[100];
void push(int n)
{
	int n1=strlen(post);
	if(top==n-1)
	{
		printf("stack is full");
	}
	else
	{
		top++;
		st[top]=n;
	}
}
int pop()
{
	if(top==-1)
	{
		printf("stack is empty");
		exit(0);
	}
	return(st[top--]);
}
int eval()
{
	int val1,val2,val;
	int n=strlen(post);
	for(i=0;i<n;i++)
	{
		if(isdigit(post[i]))
		{
			push(post[i]-48);
		}
		else
		{
			val1=pop();
			val2=pop();
			switch(post[i])
			{
				case '+':
					val=val1+val2;
					break;
				case '-':
					val=val1-val2;
					break;
					
				case '*': val=val1*val2;
					break;
				case '/': val=val1/val2;
					break;
				case '^': val=pow(val1,val2);
					break;	
			}
			push(val);
		}
		
	}
	num=pop();
	return num;
}
void expr()
{
	printf("\nEnter expression:");
	gets(post);
	if(check_exp(post))
	{
		printf("\n!!Invalid expression!!");
		expr();
	}
}

int main()
{
	printf("enter the Postfix expression:");
	expr();
	eval();
	printf("The Postfix evalution is:%d",num);
	return 0;
}
