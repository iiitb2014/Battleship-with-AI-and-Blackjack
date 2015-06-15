#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	X:printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tWELCOME TO THE GAME CENTER\n");
	printf("\n\n\t\t\t\t\t\t\t\t\t1.BLACKJACK\n");
	printf("\t\t\t\t\t\t\t\t\t2.BATTLESHIP\n");
	printf("\t\t\t\t\t\t\t\t\t3.GUESS THE CODE\n");
	printf("\t\t\t\t\t\t\t\t\t4.EXIT GAME CENTER\n");
	printf("\n\t\t\t\t\t\t\t\tWhich game do you want to play!? \n");
	int option;
	printf("\t\t\t\t\t\t\t\t");
	scanf("%d",&option);
	switch(option)
	{
		case 1:
		{	
			bj();
			goto X;
			break;
		}
		
		case 2:
		{
			bs();
			goto X;
			break;
		}
		
		case 3:
		{
			g();
			goto X;
			break;	
		}
		
		case 4:
		{
			exit(0);
		}
	}
	return 0;
}
