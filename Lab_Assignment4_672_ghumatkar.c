/*
	Shantanu Dnyaneshwar Ghumatkar
	Roll no :672
	
	Assignment 4
	String reverse
*/
#include<stdio.h>
#include<string.h>
#define max 20
int top=-1;
char st[max];
void push(char c)
  {
  	
  	if(top==max-1)
  	{
  		printf("\nStack is full");
   }
   else
   {
   
   st[++top]=c;	
   }
}
char pop()
{
	if(top==-1)
	{
		printf("\n stack is empty");
	}
	
	return(st[top--]);
	
}
char peek()
{
	return st[top];
}
void display()
{
	int i;
	for (i=top;i>=-1;i--)
	{
		printf("%c",st[i]);
	}
}
int main()
{
	char ch[20];
	printf("Enter string:");
	gets(ch);
	if(strlen(ch)>20)
	{
		printf("\n Enter string of length < 20\n");
		printf("Enter string:");
		gets(ch);
		
	}
	int i;
	for(i=0;i<strlen(ch);i++)
	{
		push(ch[i]);
	}
	
	printf("\nReverse string is:");
	display();
	return 0;
}
