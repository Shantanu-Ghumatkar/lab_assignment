/*
	Shantanu Dnyaneshwar Ghumatkar
	Roll no :672
	
	Assignment 1
	Polynomial Addition
*/
#include<stdio.h>
#include<ctype.h>
#include"validatio.h"
static int counter=1;
int polyval(int p1[])
{	
		int n,i,fl=1;
		char a[50];
		printf("\nEnter degree of %dth polynomial",counter);
		n=int_Val();
		 p1[n];
		for (i=0;i<n;i++)
		{
			printf("\nEnter coefficient of degree %d =",i);
			p1[i]=int_Val();
			
		}
		counter++;
		return n;
}
void display(int p[],int n)
{
	int i;
	for (i=0;i<n-1;i++)
		{
			printf("%dx^(%d)+",p[i],i);
			
		}
		printf("%dx^(%d)",p[i],i);
	
}
int add(int p1[],int p2[],int p3[],int n1,int n2)
{
		int i;
	if(n1>n2)
	{
		for(i=0;i<n1;i++)
		{
			if(i>=n2)
			{
				
			p3[i]=p1[i];	
			}
			else
			{
				
				p3[i]=p1[i]+p2[i];
			}
		}
			return n1;
	}
	else
	{
		for( i=0;i<n2;i++)
		{
			if(i>=n1)
			{
				
			p3[i]=p2[i];	
			}
			else
			{
			
				p3[i]=p1[i]+p2[i];
			}
		}
			return n2;
	}

}
int main()
{
	int n1,n2,n3;
	int poly1[10], poly2[10],poly3[10];
	 n1=polyval(poly1);
	  n2=polyval(poly2);
	  
	 printf("Addition of two polynomial is\n");
	printf("\n--------------------------------------------------------------------\n");
	printf("	 	");
	  display(poly1,n1); 
	  	printf("\n1	+	");
	 display(poly2,n2); 
	  n3=add(poly1,poly2,poly3,n1,n2);
	printf("\n______________________________________________________________________\n");
 	printf("	 	");
	display(poly3,n3); 
	printf("\n--------------------------------------------------------------------\n");
	
}
