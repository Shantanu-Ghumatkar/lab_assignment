
#include<stdio.h>
#include"validatio.h"
//circular
void insert();

int delete();
int deleteEnd();
	static int counter=0;
struct node
{
	int val;
	struct node *next;
};

struct node *head=NULL,*newnode,*tail;

void createnode()
{

	newnode=(struct node*)malloc(sizeof(struct node*));
	printf("Enter no to be insert\n");
	newnode->val=int_Val();
	newnode->next=NULL;
	counter++;

}

void creatlink(int n)
{
	struct node *temp;
	int i=1;
	
//	printf("in creatlink\n");
	createnode();
	if(head==NULL)
	{
		head=newnode;
		
	}
	temp=head;
	while(i<n)
	{
		createnode();
		temp->next=newnode;
		temp=temp->next;
		i++;
	}
	temp->next=head;
	tail=temp;
	
}

void display()
{
	struct node *temp;
	if(head==NULL)
	{
		printf("Link list is empty");
	}
	
	else
	{
		printf("Link list is:\n");
	temp=head;
		printf("\n--------------------------------------------------------------------\n");
	while(temp->next!=head)
	{
		printf("%d->",temp->val);
		temp=temp->next;
	}
		printf("%d\n--------------------------------------------------------------------\n",temp->val);
	}
}

void insertBeg()
{	
	createnode();
    newnode->next=head;
	head=newnode;
	tail->next=head;
}

void insertEnd()
{	
	struct node * temp;
	createnode();
	temp=head;
	int i=0;
    tail->next=newnode;
    newnode->next=head;
	
}

void insertIn()
{
	   int p;
	struct node * temp;
	createnode();
	temp=head;
	int i=1;
	printf("Enter position:");
	p=int_Val();
	printf("\np=%d\n",p);
	while(i<p-1)
	{
		temp=temp->next;
		i++;
	}
    newnode->next=temp->next;
    temp->next=newnode;
}


int deleteBeg()
{
	struct node *temp;
	temp=head;
	head=temp->next;
	free(temp);
	temp=NULL;
	tail->next=head;
	  
}

int deleteAtPos()
{
    int p;
	struct node *current;
	struct node *pre;
	current=head;
	int i=1;
	printf("Enter position:");
	p=int_Val();
	printf("\np=%d\n",p);
	if(p==1)
	{
		return (deleteBeg());
	}
	else 
	{
		if(p==counter)
		{
		return (deleteEnd());
		}
		else
		{
			while(i<=p-1)
			{
				
					pre=current;
					current=current->next;
					
					i++;
			}
				pre->next=current->next;
				free(current);
			}
	}	
  
	
}

int deleteEnd()
{
	
	struct node *current;
	struct node *pre;
	current=head;
	
	while(current->next!=head)
	{
		pre=current;
		current=current->next;
		
	}
	pre->next=current->next;
	free(current);
	current=NULL;
	tail=pre;	
	tail->next=head;
  
	
}


int main()
{
	int n1,n2,n3,choice;
	printf("Enter size of linklist:\n");
    n1=int_Val();
	creatlink(n1);
	while(choice)
	{
	
		
		printf("\n--------------------------------------------------------------------\n");
		printf("Enter choise");
		printf("\n1 insert\n2 delete\n3 Display\n0 exit\n");
	 choice=int_Val();
		printf("\n--------------------------------------------------------------------\n");	
		switch(choice)
		{
			case 1:
				{         
					
					insert();
					break;
				}
			case 2:
				{
					n2=delete();
					break;
				}
			case 3:
				{
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
				printf("\nEnter valid choise\n");				
				}	
		}
	}
}


void insert()
{
	int choice,n;
	if(head==NULL)
	{
		createnode();
		head=newnode;
	}
	else
	{
	while(choice)
	{
    	printf("\n--------------------------------------------------------------------\n");
 	    printf("Enter choise");
		printf("\n1 First\n2 At Position\n3 Last\n0 exit\n");
		choice=int_Val();
		printf("\n--------------------------------------------------------------------\n");	
		switch(choice)
		{
			case 1:
				{
					insertBeg();
					choice=0;
					break;
				}
			case 2:
				{
					insertIn();
					choice=0;
					break;
				}
			case 3:
				{
					insertEnd();
					choice=0;
					break;
				}
				
			case 0:
				{
					choice=0;
					break;
				}
	     	default:
			    {
				printf("\nEnter valid choise\n");				
				}
		}
	}
	}
	
	
}


int delete()
{
	int choice,n;
	if(head==NULL)
	{
		printf("\nLink is empty\n");
	}
	else
	{
	while(choice)
	{
    	printf("\n--------------------------------------------------------------------\n");
 	    printf("Enter choise");
		printf("\n1 First\n2 At Position\n3 Last\n0 exit\n");
		choice=int_Val();
		printf("\n--------------------------------------------------------------------\n");	
		switch(choice)
		{
			case 1:
				{
					int n= deleteBeg();
					choice=0;
					break;
				}
			case 2:
				{
				     n=deleteAtPos();
					choice=0;
					break;
				}
			case 3:
				{
					n=deleteEnd();
					choice=0;
					break;
				}
				
			case 0:
				{
					choice=0;
					break;
				}
	     	default:
			    {
				printf("\nEnter valid choise\n");				
				}
		}
	}
	return n;
	}
	
	
}
