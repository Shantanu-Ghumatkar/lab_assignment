/*
	Shantanu Dnyaneshwar Ghumatkar
	Roll no :672
	
	Assignment 1
	infix to postfix
*/
#include<stdio.h>
#include<string.h>
#include"validatio.h"
#define MAX 20
char infix[20];
int top=-1;
char st[20];
int isoperator(char a)
{
	if(a=='+'||a== '-'||a=='*'|| a=='/'|| a=='^'||a=='('||a==')')
	return 1;
	else return 0;
}
int prcd(char a)
{
	if (a=='+'||a== '-')
	return 1;
	else if(a=='*'|| a=='/')
	return 2;
	else if(a=='^')
	return 3;
	else 
	return 0;
}

char pop()
{
	if(top==-1)
	{
	printf("\nStack is empty\n");
	return 0;
	}
	else
	return (st[top--]);
}
void push(char a)
{
	if(top==MAX-1)
	{
		printf("stack is full");
	}
	else st[++top]=a;
	
}

void InfixToPos(char Inf[20],char Posf[20])
{
	int i,j=0;
	char sy;
	
	st[++top]='$';	 
	for(i=0;i<strlen(Inf);i++)
	{
		sy=Inf[i];
		if(isoperator(sy)==0)
		{
			Posf[j]=sy;
			j++;
			
			
		}
		else 
		{
			if(sy=='(') 
			{
				push(sy);
			}
			else if(sy==')')
			{
				while(st[top]!='(')	
				{
					Posf[j]=pop();
					j++;
				}
				pop();
			}
			else 
			{
				if(prcd(st[top])<=prcd(sy))
				{
					push(sy);
				}
				else
				{
					while(prcd(st[top])>=prcd(sy))
					{
						Posf[j]=pop();
						j++;
					}
					push(sy);
					
				}//end of else
				
			} //end of else
			
		} //end of else
	}//end of for
	while(st[top]!='$')
	{
		Posf[j]=pop();
		j++;
	}
	Posf[j]='\0';
}


void expr()
{
	char a[20];
	printf("\nEnter expression:");
	gets(infix);
	if(check_exp(infix))
	{
		printf("\n!!Invalid expression!!");
		expr();
	}
}
int main()
{
	char Inf[20],Posf[20];
	printf("\nEnter infix exoression:");
	expr();
	 InfixToPos(infix,Posf);
	 puts(Posf);
}

