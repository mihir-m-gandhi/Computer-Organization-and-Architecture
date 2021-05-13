#include<stdio.h>
#include<conio.h>
#include<math.h>

int a[16],m[8],n[8],q[8],count=8,M,Q;

void shift(int y[]);		// Function for left shift
void add(int y[],int z[]);  	// Function for adding 2 binary numbers
void comp(int y[],int z[]);	// Function for finding 2's compliment of a binary number 
void binary(int y,int z[]);	// Function for converting a decimal number to binary

void main()
{
  int i,j=15,r,s,A=0,B=0,g,h;
  clrscr();
  printf("Enter the dividend : ");	// Accepting inputs from user
  scanf("%d",&Q);
  printf("Enter the divisor : ");
  scanf("%d",&M);
  binary(Q,q);		// Converting decimal inputs into binary
  binary(M,m);		  
  comp(m,n);		//Finding 2's compliment of m
  for(i=7;i>=0;i--)
  {
    a[j]=q[i];
    j=j-1;
  }
  while(count!=0)	//Start of non-restoring division steps
  {
    if(a[0]==0)
    {
      shift(a);
      add(n,a);
    }
    else
    {
      shift(a);
      add(m,a);
    }
    if(a[0]==0)
    {
      a[15]=1;
    }
    else
    {
      a[15]=0;
    }
    count=count-1;
  }
  if(a[0]==1)
  {
    add(m,a);
  }			// End of non-restoring division steps
  for(i=15;i>=8;i--)
  {
    g=15-i;		// Converting binary output to decimal
    r=a[i]*pow(2,g);
    A=A+r;
  }
  for(i=7;i>=0;i--)
  {
    h=7-i;		// Converting binary output to decimal
    r=a[i]*pow(2,h);	 
    B=B+r;
  }
  printf("Quotient is ");
  for(i=8;i<16;i++)
  {
    printf("%d",a[i]);
  }
  printf(" i.e. %d",A);
  printf("\nRemainder is ");
  for(i=0;i<8;i++)
  {
    printf("%d",a[i]);
  }
  printf(" i.e. %d",B);
  printf("\n\nProgram by Mihir Gandhi B1 1611077");
  getch();
}

void shift(int y[])
{
  int i;
  for(i=0;i<15;i++)
  {
    y[i]=y[i+1];	//Shifting the array elements to left 
  }
}

void add(int y[],int z[])
{
  int i,t,carnext=0,carlast=0;
  for(i=7;i>=0;i--)
  {
    carlast=carnext;
    t=z[i];
    z[i]=(y[i])^(t)^(carlast);  // Addition of binary numbers using bitwise operators
    carnext=(y[i]&t)|(y[i]&carlast)|(t&carlast);	  
  }
}

void comp(int y[],int z[])
{
  int i,x[8]={0,0,0,0,0,0,0,1};
  for(i=0;i<8;i++)
  {
    if(y[i]==0)		
    {
      z[i]=1;		// Finding 1's compliment of the binary number 
    }			   
    else		   
    {			   
      z[i]=0;		   
    }			   
  }
  add(x,z);		// Adding 1 to 1's compliment to get 2's compliment
}

void binary(int y,int z[])
{
  int t,r,i;
  t=y;
  for(i=7;i>=0;i--)
  {
    r=t%2;		// Converting decimal to binary
    z[i]=r;		  
    t=t/2;
  }
}
