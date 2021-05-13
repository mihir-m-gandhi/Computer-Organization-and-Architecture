#include<stdio.h>
#include<conio.h>

int in[16];
int status[16]={0};
int status2[16]={0};
int dir[4][4];
int asso[4][4];
int sa1[4][4];
int sa2[4][4];

void main()
{
  int i,op,j,random=0;
  clrscr();
  printf("Enter 16 elements: ");
  for(i=0;i<16;i++)
  {
    scanf("%d",&in[i]);
  }
  do
  {
    printf("\nMain Menu");
    printf("\n1.Direct \n2.Associative \n3.Set Associative \n4.Exit");
    printf("\nEnter your choice: ");
    scanf("%d",&op);
    switch(op)
    {
      case 1:
      {
	for(i=0;i<4;i++)
	{
	  for(j=0;j<4;j++)
	  {
	    dir[j][i]=in[4*i+j];
	  }
	}
	printf("\nDIRECT MAPPING\n");
	for(i=0;i<4;i++)
	{
	  for(j=0;j<4;j++)
	  {
	    printf("%d ",dir[i][j]);
	  }
	  printf("\n");
	}
	break;
      }
      case 2:
      {
	for(i=0;i<4;i++)
	{
	  for(j=0;j<4;j++)
	  {
	    random=rand()%16;
	    while(status[random]!=0)
	    {
	      random=rand()%16;
	    }
	    asso[i][j]=in[random];
	    status[random]=1;
	  }
	}
	printf("\nASSOCIATIVE MAPPING\n");
	for(i=0;i<4;i++)
	{
	  for(j=0;j<4;j++)
	  {
	    printf("%d ",asso[i][j]);
	  }
	  printf("\n");
	}
	break;
      }
      case 3:
      {
	for(i=0;i<4;i++)
	{
	  for(j=0;j<4;j++)
	  {
	    random=rand()%16;
	    while(status2[random]!=0)
	    {
	      random=rand()%16;
	    }
	    sa1[i][j]=in[random];
	    sa2[i][j]=in[random];
	    status2[random]=1;
	  }
	}
	printf("\nSET ASSOCIATIVE MAPPING\n");
	for(i=0;i<4;i++)
	{
	  for(j=0;j<4;j++)
	  {
	    printf("%d ",sa1[i][j]);
	  }
	  printf("    ");
	  for(j=0;j<4;j++)
	  {
	    printf("%d ",sa2[i][j]);
	  }
	  printf("\n");
	}
	break;
      }
    }
  }while(op!=4);
  printf("\nProgram by Mihir Gandhi B1 1611077");
  getch();
}