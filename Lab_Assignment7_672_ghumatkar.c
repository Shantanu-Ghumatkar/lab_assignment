/*
	Shantanu Dnyaneshwar Ghumatkar
	Roll no :672
	
	Assignment 7
	impletation of circular queue
*/
#include<stdio.h>
#include"validatio.h"
#define max 5
int a[max];
int f=-1;
int r=-1;
//f for front and r for rear
void enque(int b)
{
	if((r+1)%max==f)
	{
		printf("\n Queue is full\n");
	}
	else if(f=-1 && r==-1)
	{
		f=r=0;
		a[r]=b;
		printf("\n  1 st f=%d\t r=%d\n",f,r);
	}
	else if(r==max-1 && f!=0)
	{
		r=0;
		a[r]=b;
		printf("\n 2  f=%d\t r=%d\n",f,r);
	}
	else
	{
		r=(r+1)%max;
		a[r]=b;
		printf("\n 3 f=%d\t r=%d\n",f,r);
	}
	
}
int deque()
{   
	int data;
	if(f==-1)
	{
		printf("\n Queue is empty\n");
		printf("\nf=%d\t r=%d\n",f,r);
	}
	else if(f==r)
	{ 
	    data=a[f];	
		printf("element removed successfully !\n");
		f=r=-1;
		printf("\nf=%d\t r=%d\n",f,r);
	}
	else if(f==max-1)
	{
		
	    data=a[f];
		f=0;	
		printf("element removed successfully !\n");
		
		printf("\nf=%d\t r=%d\n",f,r);
	}
	else
	{
		
	    data=a[f];
			f++;	
		printf("element removed successfully !\n");
	
		printf("\nf=%d\t r=%d\n",f,r);
	}
	return data;
	
	
}
void display()
{
	int i;
	if((r==-1 &&f==- 1) )
	{
		printf("\n Queue is empty\n");
	}
	else if(f>r)
	{
	
		for (i=f;i<max;i++)
		{
			printf("\n %d",a[i]);
		}
			i=0;	
			for (i;i<=r;i++)
		{
			printf("\n %d",a[i]);
		}
	}
	else
	{
			for (i=f;i<=r;i++)
		{
			printf("\n %d",a[i]);
		}
	}
		printf("\nf=%d\t r=%d\n",f,r);
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
				enque(a);
				break;
			}
		case 2:
		{
			printf("\ndeque element is %d",deque());
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
