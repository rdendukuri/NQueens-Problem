#include <stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<unistd.h>
#include<malloc.h>
#include<time.h>
#define MAXSIZE 100
void initBoard(int* b,int n);
void printBoard(int* a,int n);
int generateRandomNum();
int solveNQueensUtil(int* b,int i);
void  solveNQueens(int n);
int isSafe(int* b,int i,int j);
void  clearRow(int* b,int i);
int isSafe(int* b,int i,int j)
{
	int row4=i;
	int col4=j;
	int k=0;
	while(k<8)
	{
		if(*(b+8*4*k+j)==1)
			return 0;
		k++;
	}
	 int row1=i;
        int col1=j;
	 int row2=i;
        int col2=j;
	 int row3=i;
        int col3=j;
	int flag;
	while(1)
	{
		flag=0;
		row1++;
		row2++;
		row3--;
		row4--;
		col1++;
		col2++;
		col3--;	
		col4--;
		if(row1<8 && col1<8)
		{
			flag=1;
			if(*(b+8*4*row1+col1)==1)
				return 0;
		}
		if(row2<8 && col3>-1)		
		{
			flag=1;
			if(*(b+8*4*row2+col3)==1)
                                return 0;

		}
		if(row3>-1 && col4>-1)
                {
			flag=1;
                        if(*(b+8*4*row3+col4)==1)
                                return 0;

                }
		if(row4>-1 && col2<8)
                {
			flag=1;
                        if(*(b+8*4*row4+col2)==1)
                                return 0;

                }
		if(flag==0)
			break;		

	}
	return 1;
}

int generateRandomNum()
{
	time_t t;
 srand((unsigned)time(0)); 
    unsigned int random_integer; 
    int lowest = 0, highest = 7; 
    int range = (highest - lowest) + 1;


    random_integer = lowest + (range * rand() / (RAND_MAX + 1.0));

    return random_integer;
//	return 2;
}
//void  solveNQueens(int n);
void solveNQueens(int n)
{
	 int* board=     (int*) malloc(64*4);
	initBoard(board,8);
//	int k=generateRandomNum();
        printBoard(board,8);
	if(solveNQueensUtil(board,0)==1)
	{
		printf("Solution Exists\n");
//		printBoard(board,8);
	}
	else
		printf("Solution doesn't exist\n");
	 printBoard(board,8);
	
}
int solveNQueensUtil(int* b,int i)
{
	int k=generateRandomNum();
//	printf("fe %d\n",i);
	int j=k;
	do
	{
		if(isSafe(b,i,j)==1 && *(b+8*4*i+j)!=1)
		{
//			  printf("entering value at  (%d,%d)\n",i,j);
//			printf(" value at  (0,6) is %d\n",*(b+8*4*0+6));
			clearRow(b,i);
			*(b+8*4*i+j)=1;
			if(i==7)
				return 1;
			else
				return solveNQueensUtil(b,i+1);
				
		}
		else if(*(b+8*4*i+j)==1 && isSafe(b,i,j)==0)
		{
			 *(b+8*4*i+j)=0;	
			j++;
			 if(j==8)
                                j=0;
		}
		else
		{
			j++;
			if(j==8)
				j=0;
		
		}
//		j++;
	}while(j!=k);	
	if(i>0)
		return solveNQueensUtil(b,i-1);
	return 0;
}
void  clearRow(int* b,int i)
{
	int j=0;
	while(i<8)
	{
		*(b+4*8*i+j)=0;
		i++;
	}
	
}
int main()
{
	int* board=	(int*) malloc(64*4);
	solveNQueens(8);
//	initBoard(board,8);
//	printBoard(board,8);
//	solveNQueens(board);
	return 0;
	
}
void initBoard(int* b,int n)
{
//	int size=sizeof(b)/4;
	int i,j;
	int count=0;
	for(i=0;i<8;i++)
	{
//		int* t;
//		t=b;
		for(j=0;j<8;j++)
		{
			*(b+8*4*i+j)=0;
//			 printf("%d", *(b+j));
			//b++;
		}
		
//	b=b+4*(i+1);
	//	printf("%d",*(b));
	//	b++;
	}
	




}
void printBoard(int* a,int n)
{
	//int size=sizeof(a)/4;
	int i=0;
	int j;
	for(i=0;i<8;i++)
	{
		for(j=0;j<8;j++)
		{
			//printf("---\n");
			printf("| %d |",*(a+8*4*i+j)); 
		}
		
	//	i++;
	//	if(i%n==0)
			printf("\n");
	}

}



