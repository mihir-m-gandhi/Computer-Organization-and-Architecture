#include<stdio.h>
#include<conio.h>

void main()
{
  int in[100],stk[3]={-1,-1,-1},x=0,y=1,z=2,t,i,j,k,n;
  clrscr();
  printf("LRU Page Replacement Algorithm \n\n");
  printf("How many pages? ");
  scanf("%d",&n);
  printf("Enter the pages : ");		//Accepting the pages from user
  for(i=0;i<n;i++)
  {
    scanf("%d",&in[i]);
  }
  printf("Entered pages are : ");	//Displaying the entered pages
  for(i=0;i<n;i++)
  {
    printf("%d ",in[i]);
  }
  printf("\n");
  for(i=0;i<n;i++)		
  {
      if(in[i]==stk[x])		//Checking if the page is already present in stack i.e. page fault
      {
	t=x;
	x=y;
	y=z;
	z=t;
      }
      else if(in[i]==stk[y])
      {
	t=y;
	y=z;
	z=t;
      }
      else if(in[i]!=stk[x]&&in[i]!=stk[y]&&in[i]!=stk[z])	//if the page is not present in stack
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