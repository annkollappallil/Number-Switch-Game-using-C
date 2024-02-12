#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>

void creatematrix(int a[][4]) //creating 4*4 matrix
{
  int i,j=1,k,r,ar[16]={0},arr[15];
  srand(time(0));
  for(k=0;k<15;k++)
  {
     r=1+rand()%15; //generating random values between 1 to 15
     if(!ar[r])
	  arr[j++]=r;
     else
	  k--;
     ar[r]=1;
  }
  for(i=0;i<4;i++)
  {
       for(j=0;j<4;j++)
	  a[i][j]=arr[4*i+j+1];
  }
  a[i-1][j-1]=0;
}

void showmatrix(int a[][4])     //how it looks to user
{
     int i,j;
     printf("\n\n\n---------------------\n");
     for(i=0;i<4;i++)
     {
	  printf("| ");
	  for(j=0;j<4;j++){
  if(a[i][j]!=0)
printf("%2d | ",a[i][j]);//format specifier that checks spacing before printing | between no.s
	       else
		    printf("   | ");
	  }
	  printf("\n");
     }
     printf("---------------------\n");
}

int winner(int a[][4])
{                         //sample of how it should look after finishing
     int i,j,k=1;
     for(i=0;i<4;i++)
     {
	  for(j=0;j<4;j++)
	       if(a[i][j]!=k&&k!=16)
		 break;
	  if(j<4)
	    break;
     }
     if(j<4)
	  return 0;
     else
	  return 1;
}

void swap(int *p , int *q)
{
     *p=*p+*q;
     *q=*p-*q;
     *p=*p-*q;
     printf("");
}

int readEnteredkey()
{
     char c;
     c=getch();
     if(c==-32)     /*arrows are used to move no.s from one
      place to another this works by applyin
      g swapping between indexes user wants to move the no. with   */
	  c=getch();
     return c;
}

int shiftup(int a[][4])
{
     int i,j;
     for(i=0;i<4;i++)
     {
	  for(j=0;j<4;j++)
	       if(a[i][j]==0)
		 break;
	  if(j<4)
	     break;
     }
     if(i==3)
	  return 0;
     else{
	  swap(&a[i][j],&a[i+1][j]);
	  return 1;
     }
}

int shiftdown(int a[][4])
{
     int i,j;
     for(i=0;i<4;i++)
     {
	  for(j=0;j<4;j++)
	       if(a[i][j]==0)
		 break;
	  if(j<4)
	     break;
     }
     if(i==0)
	  return 0;
     else{
	  swap(&a[i][j],&a[i-1][j]);
	  return 1;
     }
}

int shiftleft(int a[][4])
{
     int i,j;
     for(i=0;i<4;i++)
     {
	  for(j=0;j<4;j++)
	       if(a[i][j]==0)
		 break;
	  if(j<4)
	     break;
     }
     if(j==3)
	  return 0;
     else{
	  swap(&a[i][j],&a[i][j+1]);
	  return 1;
     }
}
int shiftright(int a[][4])
{
     int i,j;
     for(i=0;i<4;i++)
     {
	  for(j=0;j<4;j++)
	       if(a[i][j]==0)
		 break;
	  if(j<4)
	     break;
     }
     if(j==0)
	  return 0;
     else{
	  swap(&a[i][j],&a[i][j-1]);
	  return 1;
     }
}
void gamerule(int a[][4])
{
     int i,j,x;
     system("cls");

     printf("instructions are as follows\n");
     printf("Move Up    : By Up arrow key\n");
     printf("Move Down  : By Down arrow key\n");
     printf("Move left  : By Left arrow key\n");
     printf("Move Right : By Right arrow key\n");
     printf("\n2.You can move number at empty position only");
     printf("\n3.For each valid move : your total number of move will decreased by 1");
     printf("\n4.Winning situation : number in a 4*4 matrix should be in order from 1 to 15\n\n");
     printf("              Winning situation\n");
     printf("-------------------\n");
     for(i=0;i<4;i++)
     {
	  printf("|");
	  for(j=0;j<4;j++){
	       if(a[i][j]!=0)
		    printf("%2d | ",(4*i+j+1));
	       else
		    printf("   |");
	  }
	  printf("\n");
     }
     printf("--------------------\n");
     printf("\n5. exit the game by pressing 'E' or 'e'");
     printf(" Good luck\n\n");
     printf("Enter any key to start......");
     x=readEnteredkey();
}
int main()
{

  int a[4][4],key;
  int maxtry=10000;

  char name[20];
  system("cls");
  printf("Enter Your name:");
  gets(name);
  while(1)
  {
       creatematrix(a);
       gamerule(a);

    while(!winner(a))
    {
	 system("cls");//upto date version of clrscr
	 if(!maxtry)
	  break;
	 printf("\tWelcome %s , Move Remaining : %d",name,maxtry);
	 showmatrix(a);

	 key=readEnteredkey();
	switch(key)
	{
	case 69:             //arrow movement based on ascii values

	case 101:
	  printf("\t 'Enter' to exit....");
	  key=readEnteredkey();
	  exit(0);
	case 72:
	  if(shiftup(a))
	  maxtry--;
	  break;
	case 80:
	  if(shiftdown(a))
	  maxtry--;
	  break;
	case 75:
	  if(shiftleft(a))
	  maxtry--;
	  break;
	case 77:
	  if(shiftright(a))
	  maxtry--;
	  break;
	default:
	  printf("\t\tinvalid entry");
	}
    }
    if(!maxtry){
     printf("\n\n\n\you lost");
     break;
    }
    else{
     printf("\n\n\n\t CONGRATULATION ");
     break;
    }

  }
return 0;
}
