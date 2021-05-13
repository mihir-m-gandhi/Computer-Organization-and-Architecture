#include<stdio.h>
#include<conio.h>

void main()
{
  int in[100],stk[3]={-1,-1,-1},x=0,y=1,z=2,t,i,k,n;
  clrscr();
  printf("FIFO Page Replacement Algorithm \n\n");
  printf("How many pages? ");
  scanf("%d",&n);
  printf("Enter the pages: ");		//Accepting pages from user
  for(i=0;i<n;i++)
  {
    scanf("%d",&in[i]);
  }
  printf("Entered pages are: ");	//Displaying the entered pages
  for(i=0;i<n;i++)
  {
    printf("%d ",in[i]);
  }
  printf("\n");
  for(i=0;i<n;i++)
  {
    if(in[i]!=stk[x]&&in[i]!=stk[y]&&in[i]!=stk[z])	//Checking for page fault
    {
      stk[x]=in[i];
      t=x;
      x=y;
      y=z;
      z=t;
    }
    printf("\n%d\t",in[i]);
    for(k=0;k<3;k++)		//Displaying the stack
    {
      printf("%d ",stk[k]);
    }
  }
  printf("\n\nProgram by Mihir Gandhi B1 1611077");
  getch();
}