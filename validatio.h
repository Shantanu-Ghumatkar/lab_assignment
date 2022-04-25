#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int check_int(char a[100]) // return 1 if not integer
{
  int i,len=strlen(a),flag=0;
  for(i=0;i<len;i++)
  {
  	if(a[i]==' ')
  	{
  		return 1;
	}
	
  }
  for(i=0;i<len;i++)
  {
  	if(a[i] >= '0' && a[i] <= '9')
  	{
  		flag++;
	}
	
  }
	
   if(a[0]=='+' || a[0]=='-')
   {
   	flag++;
   }
   if(flag==len)
   {
   	return 0;
   }
   else
   {
   	return 1;
   }
}



int stoi(char a[50])
{
	if(check_int(a))
	{
		return -1;
	}
	int i,j=0,n;
	n=strlen(a);
	for(i=0;i<n;i++)
	{
		if(a[i]=='+'||a[i]=='-')
		{
			continue;
		}
		j=j*10+a[i]-48;
	}
	if(a[0]=='-')
	{
		j=-j;
	}
	return j;
}


int int_Val()
{
	char a[50];
	printf("\nEnter value:");
	gets(a);
	int n;
	if(stoi(a)==-1)
	{
		printf("\n !!! Enter invalid value!!!");
		int_Val();
		
	}
	else
	{
	
	n=stoi(a);
	 return n;
	}
}

int check_float(char a[50])
{
	
	int i,j=0,n,fl1=0,fl2=0,fl3=0;
	n=strlen(a);
	if(n=0)
	{
		return 1;
	}
	if((n==1) && (a[0]=='+' || a[0]=='-' || a[0]=='.') )
	{
		return 1;
	}
	for(i=0;i<n;i++)
	{
		if(!(a[i]>=48 && a[0]<57) && a[0] !='+' && a[0] != '-' && a[i]!='.')
		{
			return 1;
		}
		if(a[i]=='+')
		{
			fl1++;
		}
		if(a[i]=='-')
		{
			fl2++;
		}
		if(a[i]=='.')
	{
		fl3++;
	}
	}
	if(fl3>1)
	{
		return 1;
	}
	if((fl1 ==1 && fl2==0)||(fl2==1 && fl1==0) || (fl1==0 && fl2==0))
	{
		return 0;
		}	
	else return 1;
	
}
	

float sof(char a[50])
{
	if(check_float(a))
	{
		return 0;
	}
	int i,f,n,k=0,fl3=0;
	float j=0;
	n=strlen(a);
	for(i=0;i<n;i++)
	{
		if(a[i]=='+'|| a[i]=='-')
		{
			continue;
		}
		if(a[i]=='.')
		{
			k=i;
			fl3++;
			continue;
		}
		j=j*10+a[i]-48;
	}
	if(fl3==0)
	{
		for(i=0;i<n-k-1;i++)
		{
			j=j/10;
		}
	}
	if(a[0]=='-')
	{
		return -j;
	}
	return j;
}


int check_exp(char a[50])
{
	int n=strlen(a);
	int i,fl,fl2=0;
	for(i=0;i<n;i++)
	{
	if(  isdigit(a[i]) || a[i]=='+' || a[i]=='-' || a[i]=='*' || a[i]=='/' || a[i]=='^' || (65<=a[i] && 90<=a[i]) || (97<=a[i] && 122<=a[i]) || a[i]=='(' || a[i]==')' )
	
	{
		fl=0;
	}
	else 
	{
		fl=1;
		break;
	}
	if(a[i]=='('  ) 
	{
		
		fl2=fl2+1;
	}
	if(a[i]==')')
	{
		
		fl2=fl2-1;
	}
	
	}
	
	if(fl2!=0)
	{
		return 1;
	}

	return fl;
}
