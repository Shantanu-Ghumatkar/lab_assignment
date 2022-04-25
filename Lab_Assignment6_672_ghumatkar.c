/*
	Shantanu Dnyaneshwar Ghumatkar
	Roll no :672
	
	Assignment 6
	implementation of linear queue
*/
#include<stdio.h>
#include"validatio.h"
#define MAX 5
int a[MAX];
int front=-1;
int rear=-1;
void enqueue(int n)
{
	
	if(rear>MAX-2)
	{
		printf("\n Que is full");
		
	}
	else
	{
		if(rear==-1)
		{
			front=0;
			rear=0;
			a[rear]=n;
		}
	   else
	   {
	   	rear++;
	   a[rear]=n;
	   }
	
	}
}
int dequeue()
{
	if(front>rear|| rear==-1)
	{
		printf("\n que is empty");
		
	}
	else
	{	
		return a[front++];	
	}
	return 0;
}
void display()
{
	int i;
	for (i=front;i<=rear;i++)
	{
		printf("\n%d",a[i]);
	}
}
int main()
{
	int choice=1;
	int a;
		while(choice)
	{
		printf("\n--------------------------------------------------------------------\n");
		printf("\n1 Enque\n2 deque\n3 Dispaly\n0 exit\n");
		choice=int_Val();
		printf("\n--------------------------------------------------------------------\n");	
		switch(choice)
		{
		case 1:
			{
				printf("\nEnter element\n");
				a=int_Val();
				enqueue(a);
				break;
			}
		case 2:
		{
			printf("\ndeque element is %d",dequeue());
			break;
		}
		case 3:
			{
				printf("Display Queue");
				display();
				break;
			}
		case 0:
			{
				choice=0;
				break;
			}
		default:
			{
				printf("\nEnter invalid choice");
			}
		}
		printf("\n--------------------------------------------------------------------\n");	
	}
	return 0;
	
}
