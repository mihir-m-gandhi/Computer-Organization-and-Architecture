#include<stdio.h>
#include<conio.h>

void binary(int x,int s[]);	// Function to convert whole number part of a floating point number to binary
void bin(int e, int b[]);	// Function to convert a decimal number to binary
void fbin(float y, int s[]);	// Function to convert fractional number part of a floating point number to binary

int r1[32],r2[64],b1[8],b2[11],s1[24],s2[52];
int i1=0;
int n1=1;
int n2=1;
int c;

void main()
{
  int i,x,j,k,e1=0,e2=0,l;
  float n,y;
  clrscr();
  printf("Enter a floating point number : ");
  scanf("%f",&n);
  if(n>=0)
  {
    r1[0]=0;	// Setting sign bit of positive no. to 0
    r2[0]=0;	   
  }
  else
  {
    r1[0]=1;	// Setting sign bit of negative no. to 0
    r2[0]=1;	   
    n=n*(-1);	// Making the negative no. positive for further operations
  }
  x=(int)n;		// Making x equal to whole part of n
  y=n-(float)x;		// Making y equal to fractional part of n
  binary(x,s1);		// Converting to binary to get significand
  fbin(y,s1);		   
  k=c-1;		// Power of 2 after normalisation
  e1=k+127;		// Calculating Biased exponent of 32 bit
  e2=k+1023;		// Calculating Biased exponent of 64 bit
  bin(e1,b1);		// Converting the bias in decimal form to binary 
  bin(e2,b2);		   
  for(j=0;j<8;j++)  // Compiling the biased exponent and significand of 32 bit together
  {			
    r1[n1]=b1[j];	   
    n1++;
  }
  for(j=1;j<23;j++)
  {
    r1[n1]=s1[j];
    n1++;
  }
  for(j=0;j<11;j++)	// Compiling the biased exponent and significand of 64 bit together
  {			   
    r2[n2]=b2[j];
    n2++;
  }
  for(j=1;j<23;j++)
  {
    r2[n2]=s1[j];
    n2++;
  }
  printf("\nSingle Precision : \n");
  for(j=0;j<32;j++)
  {
    printf("%d ",r1[j]);
  }
  printf("\n\nDouble Precision : \n");
  for(j=0;j<64;j++)
  {
    printf("%d ",r2[j]);
  }
  printf("\n\nProgram by Mihir Gandhi B1 1611077 Logistic Head of Shutterbugs Council");
  getch();
}

void binary(int x, int s[])
{
    int r,z=x,temp[24],i=0,k;
    while(z!=0)
    {
      r=z%2;		// Converting whole number part to binary 
      temp[i]=r;	   
      z=z/2;		   
      i++;		   
    }
    for(k=i-1;k>=0;k--)
    {
      s[i1]=temp[k];
      i1++;
    }
    c=i1;
}

void fbin(float y, int s[])
{
  int z=0;
  do
  {
    y=y*2;		// Converting fractional part to binary 
    s[i1]=(int)y;	   
    z=(int)y;		   
    y=y-(float)z;	   
    i1++;		   
  }while(z!=1);
}

void bin(int e, int b[])
{
  int r,z=e,temp[24],i=0,k,j=0;
    while(z!=0)
    {
      r=z%2;		// Converting decimal to binary
      temp[i]=r;	   
      z=z/2;		   
      i++;		   
    }
    for(k=i-1;k>=0;k--)
    {
      b[j]=temp[k];
      j++;
    }
}