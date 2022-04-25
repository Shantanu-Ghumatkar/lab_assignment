/*
	Shantanu Dnyaneshwar Ghumatkar
	Roll no :672
	
	Assignment 7
	impletation of circular dequeue
*/
#include<stdio.h>
#include"validatio.h"
#define max 5
int a[max];
int f=-1;
int r=-1;
//f for front and r for rear
void enqueueFront(int b)
{
	if(f==(r+1)%max)
	{
		printf("\n Dequeue is full\n");
		printf("\nr=%d , f=%d\n",r,f);
	}
	else if(f==-1 && r==-1)
	{
		f=r=0;
		a[f]=b;
		printf("\nr=%d , f=%d\n",r,f);
	}
	else if(f==0 && r!=max-1)
	{
		f=max-1;
		a[f]=b;
		
		printf("\nr=%d , f=%d\n",r,f);
	}
	else
	{
		f--;
		a[f]=b;
		
		printf("\nr=%d , f=%d\n",r,f);
	}
	
}

void enqueueRear(int b)
{
	if(f==(r-1)%max || (r==max-1 && f==0))
	{
		printf("\n Dequeue is full\n");
			printf("\n1i\nr=%d , f=%d\n",r,f);
	}
	else if(f==-1 && r==-1)
	{
		
		f=r=0;
		a[r]=b;
			printf("\n1e\nr=%d , f=%d\n",r,f);
	}
	else if(f!=0 && r==max-1)
	{
		r=0;
		a[r]=b;
		printf("\n2e\nr=%d , f=%d\n",r,f);
	}
	else
	{
		r=r+1;
		a[r]=b;
		printf("\n3e\nr=%d , f=%d\n",r,f);
	}
	
}

int dequeueFront()
{   
	int data;
	if(f==-1)
	{
		printf("\n Dequeue is empty\n");
	}
	else if(f==r)
	{ 
	    data=a[f];	
		printf("element removed successfully !\n");
		f=r=-1;
	}
	else if(f==max-1)
	{
		
	    data=a[f];
		f=0;
		printf("element removed successfully !\n");
		
	}
	else
	{
		
	    data=a[f];
			f++;	
		printf("element removed successfully !\n");
	
	}
	return data;
	
	
}

int dequeueRear()
{   
	int data;
	if(f==-1)
	{
		printf("\n Dequeue is empty\n");
	}
	else if(f==r)
	{ 
	    data=a[r];	
		printf("element removed successfully !\n");
		f=r=-1;
	}
	else if(r==0)
	{
		
	    data=a[r];
		r=max-1;
		printf("element removed successfully !\n");
		
	}
	else
	{
		
	    data=a[f];
			r--;	
		printf("element removed successfully !\n");
	
	}
	return data;
	
	
}
void display()
{
	int i;
	if((r==-1 &&f==- 1) )
	{
		printf("\n Dequeue is empty\n");
	}
	else if(f>r)
	{
	
		for (i=f;i<max;i++)
		{
			printf("\n %d",a[i]);
		}
			
			for (i=0;i<=r;i++)
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
}
int main()
{
	int choice=1,choice2=1;
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
				choice2=1;
				while(choice2)
				{
					printf("\n--------------------------------------------------------------------\n");
				printf("\n1 Enque Front\n2 Enqueue Rear\n");
				choice2=int_Val();
				printf("\n--------------------------------------------------------------------\n");	
				switch(choice2)
				{
				case 1:
					{
						printf("\nEnter element\n");
						a=int_Val();
						enqueueFront(a);
						choice2=0;
						break;
					}
				case 2:
				{
					printf("\nEnter element\n");
						a=int_Val();
						enqueueRear(a);
						choice2=0;
					break;
				}
				default:
					{
						printf("\nEnter invalid choice");
					}
				}
				printf("\n--------------------------------------------------------------------\n");
						break;
					}
						break;
				}
		case 2:
		{
//			printf("\ndeque element is %d",deque());
//			break;
    		choice2=1;
			while(choice2)
				{
					printf("\n--------------------------------------------------------------------\n");
				printf("\n1 Enque Front\n2 Enqueue Rear\n");
				choice2=int_Val();
				printf("\n--------------------------------------------------------------------\n");	
				switch(choice2)
				{
				case 1:
					{
						printf("\ndeque element is %d",dequeueFront());
						break;
					}
				case 2:
				{
					printf("\ndeque element is %d",dequeueRear());
						choice2=0;
					break;
				}
				default:
					{
						printf("\nEnter invalid choice");
					}
				}
				printf("\n--------------------------------------------------------------------\n");
						break;
					}	break;
					
				}
		
		case 3:
			{
				printf("Display Dequeue");
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
