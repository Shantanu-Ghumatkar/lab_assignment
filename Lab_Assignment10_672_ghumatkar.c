
#include<stdio.h>
#include"validatio.h"
// dubly
void insert();

int delete();

struct node
{
	int val;
	struct node *next,*pre;
};

struct node *head=NULL,*newnode,*temp;

void createnode()
{
	static int counter=0;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("Enter no to be insert\n");
	newnode->val=int_Val();
//	scanf("%d",&newnode->val);
	newnode->next=NULL;
	
	newnode->pre=NULL;
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
		newnode->pre=temp;
		temp=temp->next; //here if i put temp->next instead of newnode it doesn't run some time why
		
		
		i++;
	}
	
}

void display()
{
	if(head==NULL)
	{
		printf("Link list is empty");
	}
	
	else
	{
		printf("Link list is:\n");
	temp=head;
		printf("\n--------------------------------------------------------------------\n");
	while(temp->next!=NULL)
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
}

void insertEnd()
{	
	createnode();
	temp=head;
	int i=0;
	while(temp->next!=NULL)
	{
		temp=temp->next;
		i++;
	}
    temp->next=newnode;
    newnode->pre=(temp->pre)->next;
    
    
	
}

void insertIn()
{
	   int p;
	createnode();
	temp=head;
	int i=1;
	printf("Enter position:");
	p=int_Val();
	printf("\np=%d\n",p);
	while(i<=p-1)
	{
		temp=temp->next;
		i++;
	}
    newnode->next=temp->next;
    temp->next=newnode;
    newnode->pre=(temp->pre)->next;
}


int deleteBeg()
{
	temp=head;
	head=temp->next;
	free(temp);
	temp=NULL;
	head->pre=NULL;
	  
}

int deleteAtPos()
{
    int p;
	struct node *current;
	current=head;
	int i=1;
	printf("Enter position:");
	p=int_Val();
	printf("\np=%d\n",p);
	while(i<=p-1)
	{
		
		current=current->next;
		
		i++;
	}
	(current->next)->pre=current->pre;
	(current->pre)->next=current->next;
	
	free(current);
//	current=NULL;	
  
	
}

int deleteEnd()
{
	struct node *current;
	current=head;
	int i=1;
	while(current->next!=NULL)
	{
		current=current->next;
		i++;
	}
	(current->pre)->next=current->next;
	free(current);
	current=NULL;	
  
	
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
		printf("\n1 First\n2 Inbetween\n3 Last\n0 exit\n");
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
		printf("\n1 First\n2 Inbetween\n3 Last\n0 exit\n");
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
