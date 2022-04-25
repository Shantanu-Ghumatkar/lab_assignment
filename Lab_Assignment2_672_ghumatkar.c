


/*
	Shantanu Dnyaneshwar Ghumatkar
	Roll no :672
	
	Assignment 2
	infix to prefix
*/
#include<stdio.h>
#include<string.h>
#define MAX 20

#include"validatio.h"
int top=-1;
char st[20];
char infix[20];
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

void InfixToPre(char inf[20],char pref[20])
{
	int i,j=0;
	char sy;
	
	st[++top]='$';
	strrev(inf);
	

	 
	for(i=0;i<strlen(inf);i++)
	{
		sy=inf[i];
		if(isoperator(sy)==0)
		{
			pref[j]=sy;
			j++;			
		}
		else 
		{
			if(sy==')') 
			{
				push(sy);
			}
			else if(sy=='(')
			{
				while(st[top]!=')')	
				{
					pref[j]=pop();
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
						pref[j]=pop();
						j++;
					}
					push(sy);
					
				}//end of else
				
			} //end of else
			
		} //end of else
	}//end of for
	while(st[top]!='$')
	{
		pref[j]=pop();
		j++;
	}
	pref[j]='\0';
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
	char inf[20],pref[20];
	printf("\nEnter infix expression");
	expr();
//	puts(infix);
	InfixToPre(infix,pref);
	printf("Prefix expression:");
	strrev(pref);
	puts(pref);
}

