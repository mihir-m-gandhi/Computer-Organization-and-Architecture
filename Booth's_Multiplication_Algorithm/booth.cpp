#include<stdio.h>
#include<conio.h>

void bits(int n);

void main()
{
	clrscr();
	int m,q,nm,n=0,p=0,term1,term2;
	printf("Enter the two numbers: ");
	scanf("%d",&m);
	scanf("%d",&q);
	term1=m;
	term2=q;
	nm=~m+1;
	if(m<0)
	{
	  m=nm;
	}
	if(q<0)
	{
	  q=(~q)+1;
	}
	m=m<<4;
	while(1)
	{
	  if(((q&1)==0 && p==0) || ((q&1)==1 && p==1))
	  {
	  if(n==4)
	  {
	  break;
	  }
	  q = q>>1;
	  n++;
	}
	if(((q&1)==1 && p==0))
	{
	  if(n==4)
	  {
	    break;
	  }
	  q=q-m;
	  q=q>>1;
	  p=1;
	  n++;
	}
	if((q&1)==0 && p==1)
	{
	if(n==4)
	{
	 break;
	}
	q=q+m;
	q=q>>1;
	p=0;
	n++;
	}
       }
	if((term1>0) && (term2>0) || (term1<0 && term2<0))
	{
	 printf("The product in binary form is : ");
	 bits(q);
	 printf("\nThe product in decimal form is : %d\n",q);
	}
	if((term1>0 && term2<0) || (term1<0 && term2>0))
	{
	  q=~q+1;
	  printf("The product in binary form is : ");
	  bits(~q+1);
	  printf("\nThe product in decimal form is : %d\n",q);
	}
getch();
}

void bits(int q) 
{ 
    int r,arr[16],i=0,j,test_q;
    while(q!=0) 
    {
     r=q%2;
     q=q/2;
     arr[i]=r;
     i++;
    }
    j=i;
    while(j<=15)
    {
      arr[j]=0;
      j++;
    }
    for(i=15;i>=0;i--) 
    {
	printf("%d",arr[i]);
    }
}