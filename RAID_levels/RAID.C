#include<stdio.h>
#include<conio.h>

void binham(int x);

void main()
{
  int n,a[10][4],r,i,j;
  clrscr();
  printf("Enter the no. of elements: ");
  scanf("%d",&n);
  r=n/4;
  for(i=0;i<r;i++)
  {
    for(j=0;j<4;j++)
    {
      printf("Enter a[%d][%d]: ",i+1,j+1);
      scanf("%d",&a[i][j]);
    }
  }
  printf("\nRaid Level 0\n\n");
  for(i=0;i<r;i++)
  {
    for(j=0;j<4;j++)
    {
      printf("%d ",a[i][j]);
    }
    printf("\n");
  }
  printf("\n\nRaid Level 1\n\n");
  for(i=0;i<r;i++)
  {
    for(j=0;j<4;j++)
    {
      printf("%d ",a[i][j]);
    }
    printf("    ");
    for(j=0;j<4;j++)
    {
      printf("%d ",a[i][j]);
    }
    printf("\n");
  }
  printf("\n\nRaid Level 2\n\n");
  for(i=0;i<r;i++)
  {
    for(j=0;j<4;j++)
    {
      binham(a[i][j]);
      printf("\n");
    }
  }
  printf("\n\nProgram by Mihir Gandhi B1 1611077");
  getch();
}

void binham(int x)
{
  int bin[4]={0},ham[3]={0},k;
  for(k=3;x!=0;k--)
  {
    bin[k]=x%2;
    x=x/2;
  }
  for(k=0;k<4;k++)
  {
    printf("%d",bin[k]);
  }
  ham[0]=bin[0]^bin[1]^bin[2];
  ham[1]=bin[0]^bin[1]^bin[3];
  ham[2]=bin[0]^bin[3]^bin[3];
  for(k=0;k<3;k++)
  {
    printf("%d",ham[k]);
  }
}
