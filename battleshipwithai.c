#include <stdio.h>
#include <stdlib.h>
#include <time.h>



//Function to convert the integer equivalent to char #used below  for row numbers
char retintval(int a)
	{
	if(a==1)
		return 'a';
	else if(a==2)
		return 'b';
	else if(a==3)
		return 'c';
	else if(a==4)
		return 'd';
	else if(a==5)
		return 'e';
	else if(a==6)
		return 'f';
	else if(a==7)
		return 'g';
	else if(a==8)
		return 'h';
	else if(a==9)
		return 'i';
	else if(a==10)
		return 'j';
	return 0;
	}
//Function to convert char to interger equivalent #used below  for row numbers

int retcharval(char a)
	{
	if(a=='a')
		return 1;
	else if(a=='b')
		return 2;
	else if(a=='c')
		return 3;
	else if(a=='d')
		return 4;
	else if(a=='e')
		return 5;
	else if(a=='f')
		return 6;
	else if(a=='g')
		return 7;
	else if(a=='h')
		return 8;
	else if(a=='i')
		return 9;
	else if(a=='j')
		return 10;
	return 0;
	}
//function creates table
void dots(char **a)
	{
	int i,j;
	for(i=1;i<=10;i++)
		a[i][0]=retintval(i);
	for(i=1;i<=10;i++)
		a[0][i]=i;
	for(i=1;i<=10;i++)
		{
		for(j=1;j<=10;j++)
			a[i][j]='.';
		} 
	}


//converts the dots to o or x depending on whether it is a miss or a hit


char *changetablemiss(char **arr,int i,int j)
	{
	if(j==0 || i==0)
		return *arr;
	arr[i][j]='O';
	
	return *arr;
	}
char *changetablehit(char **arr,int i,int j)
	{
	arr[i][j]='X';
	
	return *arr;
	}
char *dispdots(char **a)
	{
	int i,j;
		
	for(i=0;i<=10;i++)
				{
				for(j=0;j<=10;j++)
					{
					if(i==0&&j==0)
						printf("");
					if(i==0)
						printf("%3d",a[i][j]);
					else
						printf("%3c",a[i][j]);
					}
				printf("\n");
				}
	return 0;
	}


//function to place the ships in the positions,given by the player


char **placeship(int *a,int *b,int *c)
	{
	int i,b1,j1,b2,j2,b3,j3,b4,j4,b5,j5;
	char a1,c1,a2,c2,a3,c3,a4,c4,a5,c5, dustbin;

		

	char **arr=(char **)malloc(20*sizeof(char *));
		for(i=0;i<20;i++)
			arr[i]=(char *)malloc(20*sizeof(char));
	
	dots(arr);
	
	
	LABEL1:printf("Enter the position of ship1 (size 2) and enter vertical(v) or horizontal(h)\n");
	scanf("%c",&dustbin);
	scanf("%c",&a1);
	scanf("%d",&b1);
	scanf("%c",&c1);
	
	if ((b1>10 || b1<1) || (a1>'j' || a1<'a'))
		{
		goto LABEL1;
		}

	j1=retcharval(a1);
	if (c1!='h' && c1!='v')
		{
		goto LABEL1;
		}
	a[0]=j1;
	b[0]=b1;
	
	if(c1=='h')
		{
		
		c[0]=0;
		arr[j1][b1]='-';
		arr[j1][b1+1]='-';
		}
	else if(c1=='v')
		{
		c[0]=1;
		arr[j1][b1]='|';
		arr[j1+1][b1]='|';
		}
	

	LABEL2:printf("Enter the position of ship2 (size 3) and enter vertical(v) or horizontal(h)\n");
	scanf("%c", &dustbin);
	LABEL2a:scanf("%c",&a2);
	scanf("%d",&b2);
	scanf("%c",&c2);
	
	j2=retcharval(a2);

	if ((b2>10 || b2<1) || (a2>'j' || a2<'a'))
		{
		goto LABEL2;
		}
	if (c2!='h' && c2!='v')
		{
		printf("Enter the position of ship2 (size 3) and enter vertical(v) or horizontal(h)\n");
		goto LABEL2a;
		}

	if(c2=='h')
		{
		if (arr[j2][b2]!='.' || arr[j2][b2+1]!='.' ||arr[j2][b2+2]!='.')
			{
			goto LABEL2;
			}
		else if (j2>10 || b2>8)
			{
			goto LABEL2;
			}
		arr[j2][b2]='-';
		arr[j2][b2+1]='-';
		arr[j2][b2+2]='-';
		c[1]=0;
		}
	else if(c2=='v')
		{
		if (arr[j2][b2]!='.' || arr[j2+1][b2]!='.' ||arr[j2+2][b2]!='.')
			{
			goto LABEL2;
			}
		else if ((j2>8) || (b2>10))
			{
			goto LABEL2;
			}
		arr[j2][b2]='|';
		arr[j2+1][b2]='|';
		arr[j2+2][b2]='|';
		c[1]=1;
		}
	a[1]=j2;
	b[1]=b2;
	
	
	LABEL3:printf("Enter the position of ship3 (size 3) and enter vertical(v) or horizontal(h)\n");
	scanf("%c", &dustbin);
	LABEL3a:scanf("%c",&a3);
	scanf("%d",&b3);
	scanf("%c",&c3);
	
	j3=retcharval(a3);

	if((b3>10 || b3<1) || (a3>'j' || a3<'a'))
		{
		goto LABEL3;
		}

	if (c3!='h' && c3!='v')
		{
		printf("Enter the position of ship3 (size 3) and enter vertical(v) or horizontal(h)\n");
		goto LABEL3a;
		}

	if(c3=='h')
		{
		if (arr[j3][b3]!='.' || arr[j3][b3+1]!='.' || arr[j3][b3+2]!='.')
			{	
			goto LABEL3;
			}
		else if (j3>10 ||b3>8)
			{
			goto LABEL3;
			}
		arr[j3][b3]='-';
		arr[j3][b3+1]='-';
		arr[j3][b3+2]='-';
		c[2]=0;		
		}
	else if(c3=='v')
		{
		if (arr[j3][b3]!='.' || arr[j3+1][b3]!='.' || arr[j3+2][b3]!='.')
			{	
			goto LABEL3;
			}
		else if (j3>8 ||b3>10)
			{
			goto LABEL3;
			}
		arr[j3][b3]='|';
		arr[j3+1][b3]='|';
		arr[j3+2][b3]='|';
		c[2]=1;
		}
	a[2]=j3;
	b[2]=b3;
	

	LABEL4:printf("Enter the position of ship4 (size 4) and enter vertical(v) or horizontal(h)\n");
	scanf("%c", &dustbin);
	LABEL4a:scanf("%c",&a4);
	scanf("%d",&b4);
	scanf("%c",&c4);
	
	j4=retcharval(a4);

	if ((b4>10 || b4<1) || (a4>'j' || a3<'a'))
		{
		goto LABEL4;
		}
	if (c4!='h' && c4!='v')
		{
		printf("Enter the position of ship4 (size 4) and enter vertical(v) or horizontal(h)\n");
		goto LABEL4a;
		}

	if(c4=='h')
		{
		if (arr[j4][b4]!='.' || arr[j4][b4+1]!='.' || arr[j4][b4+2]!='.' || arr[j4][b4+3]!='.')
			{	
			goto LABEL4;
			}
		else if (j4>10 ||b4>7)
			{
			goto LABEL4;
			}
		arr[j4][b4]='-';
		arr[j4][b4+1]='-';
		arr[j4][b4+2]='-';
		arr[j4][b4+3]='-';
		c[3]=0;
		}
	if(c4=='v')		
		{
		if (arr[j4][b4]!='.' || arr[j4+1][b4]!='.' || arr[j4+2][b4]!='.' || arr[j4+3][b4]!='.')
			{	
			goto LABEL4;
			}
		else if (j4>7 ||b4>10)
			{
			goto LABEL4;
			}
		arr[j4][b4]='|';
		arr[j4+1][b4]='|';
		arr[j4+2][b4]='|';
		arr[j4+3][b4]='|';
		c[3]=1;		
		}

	a[3]=j4;
	b[3]=b4;
	

	LABEL5:printf("Enter the position of ship5 (size 5) and enter vertical(v) or horizontal(h)\n");
	scanf("%c", &dustbin);
	LABEL5a:scanf("%c",&a5);
	scanf("%d",&b5);
	scanf("%c",&c5);
	
	j5=retcharval(a5);

	if ((b5>10 || b5<1) || (a5>'j' || a5<'a'))
		{
		goto LABEL5;
		}

	if (c5!='h' && c5!='v')
		{
		printf("Enter the position of ship5 (size 5) and enter vertical(v) or horizontal(h)\n");
		goto LABEL5a;
		}

	if(c5=='h')
		{
		if (arr[j5][b5]!='.' || arr[j5][b5+1]!='.' || arr[j5][b5+2]!='.' || arr[j5][b5+3]!='.' || arr[j5][b5+4]!='.')
			{	
			goto LABEL5;
			}
		else if (j5>10 ||b5>6)
			{
			goto LABEL5;
			}

		arr[j5][b5]='-';
		arr[j5][b5+1]='-';
		arr[j5][b5+2]='-';
		arr[j5][b5+3]='-';
		arr[j5][b5+4]='-';
		c[4]=0;		
		}
	else if(c5=='v')
		{
		if (arr[j5][b5]!='.' || arr[j5+1][b5]!='.' || arr[j5+2][b5]!='.' || arr[j5+3][b5]!='.' || arr[j5+4][b5]!='.')
			{	
			goto LABEL5;
			}
		else if (j5>6 ||b5>10)
			{
			goto LABEL5;
			}

		arr[j5][b5]='|';
		arr[j5+1][b5]='|';
		arr[j5+2][b5]='|';
		arr[j5+3][b5]='|';
		arr[j5+4][b5]='|';
		c[4]=1;
		}
	a[4]=j5;
	b[4]=b5;
	
	return arr;
	}

	//Computer places the ships using random function
	char **compplacesships(int *a,int *b,int *c)
		{
		printf("\ncomputer placing its ships\n\n");
		time_t t=0;

		long int retTime;
		retTime = time(0) + 3;
		while (time(0) < retTime);
		printf("Computer has placed\n\n");
	 	printf("Let the action begin!!!!\n\n");
	/* Intializes random number generator */
	srand((unsigned) time(&t));

	int i,b1,j1,b2,j2,b3,j3,b4,j4,b5,j5,c1,c2,c3,c4,c5;
		int a1,a2,a3,a4,a5;
	
	char **arr=(char **)malloc(20*sizeof(char *));
		for(i=0;i<20;i++)
			arr[i]=(char *)malloc(20*sizeof(char));
	
	dots(arr);
	
	
	LABEL1:a1 = 1+(rand() % 9);
	b1=1+(rand() % 10);
	c1=1+(rand() % 2);
	
	

	j1=a1;
	if(c1==1)
		{
		if (b1>9)
			{
			goto LABEL1;
			}
		arr[j1][b1]='-';
		arr[j1][b1+1]='-';
		}
	else if(c1==2)
		{
		if (j1>9)
			{
			goto LABEL1;
			}
		arr[j1][b1]='|';
		arr[j1+1][b1]='|';
		}
	a[0]=j1;b[0]=b1;c[0]=(c1-1);

	LABEL2:a2=1+(rand() % 10);
	b2= 1+(rand()% 10);
	c2=1+(rand() % 2);

	j2=a2;

	

	if(c2==1)
		{
		if (arr[j2][b2]!='.' || arr[j2][b2+1]!='.' ||arr[j2][b2+2]!='.')
			{
			goto LABEL2;
			}
		else if (j2>10 || b2>8)
			{
			goto LABEL2;
			}
		arr[j2][b2]='-';
		arr[j2][b2+1]='-';
		arr[j2][b2+2]='-';
		}
	else if(c2==2)
		{
		if (arr[j2][b2]!='.' || arr[j2+1][b2]!='.' ||arr[j2+2][b2]!='.')
			{
			goto LABEL2;
			}
		else if ((j2>8) || (b2>10))
			{
			goto LABEL2;
			}
		arr[j2][b2]='|';
		arr[j2+1][b2]='|';
		arr[j2+2][b2]='|';
		}
	
	a[1]=j2;b[1]=b2;c[1]=(c2-1);

	LABEL3:a3= 1+(rand() % 10);
	b3= 1+(rand() % 10);
	c3= 1+(rand() % 2);
	
	j3=a3;

	


	if(c3==1)
		{
		if (arr[j3][b3]!='.' || arr[j3][b3+1]!='.' || arr[j3][b3+2]!='.')
			{	
			goto LABEL3;
			}
		else if (j3>10 ||b3>8)
			{
			goto LABEL3;
			}
		arr[j3][b3]='-';
		arr[j3][b3+1]='-';
		arr[j3][b3+2]='-';
		}
	else if(c3==2)
		{
		if (arr[j3][b3]!='.' || arr[j3+1][b3]!='.' || arr[j3+2][b3]!='.')
			{	
			goto LABEL3;
			}
		else if (j3>8 ||b3>10)
			{
			goto LABEL3;
			}
		arr[j3][b3]='|';
		arr[j3+1][b3]='|';
		arr[j3+2][b3]='|';
		}
	
	a[2]=j3;b[2]=b3;c[2]=(c3-1);


	LABEL4:a4= 1+(rand() % 10);
	b4= 1+(rand() % 10);
	c4= 1+(rand() % 2);
	
	j4=a4;

	

	if(c4==1)
		{
		if (arr[j4][b4]!='.' || arr[j4][b4+1]!='.' || arr[j4][b4+2]!='.' || arr[j4][b4+3]!='.')
			{	
			goto LABEL4;
			}
		else if (j4>10 ||b4>7)
			{
			goto LABEL4;
			}
		arr[j4][b4]='-';
		arr[j4][b4+1]='-';
		arr[j4][b4+2]='-';
		arr[j4][b4+3]='-';
		}
	if(c4==2)		
		{
		if (arr[j4][b4]!='.' || arr[j4+1][b4]!='.' || arr[j4+2][b4]!='.' || arr[j4+3][b4]!='.')
			{	
			goto LABEL4;
			}
		else if (j4>7 ||b4>10)
			{
			goto LABEL4;
			}
		arr[j4][b4]='|';
		arr[j4+1][b4]='|';
		arr[j4+2][b4]='|';
		arr[j4+3][b4]='|';
		}


	a[3]=j4;b[3]=b4;c[3]=(c4-1);

	LABEL5:a5= 1+(rand() % 10);
	b5= 1+(rand() % 10);
	c5= 1+(rand() % 2);
	
	j5=a5;

	if(c5==1)
		{
		if (arr[j5][b5]!='.' || arr[j5][b5+1]!='.' || arr[j5][b5+2]!='.' || arr[j5][b5+3]!='.' || arr[j5][b5+4]!='.')
			{	
			goto LABEL5;
			}
		else if (j5>10 ||b5>6)
			{
			goto LABEL5;
			}

		arr[j5][b5]='-';
		arr[j5][b5+1]='-';
		arr[j5][b5+2]='-';
		arr[j5][b5+3]='-';
		arr[j5][b5+4]='-';
		}
	else if(c5==2)
		{
		if (arr[j5][b5]!='.' || arr[j5+1][b5]!='.' || arr[j5+2][b5]!='.' || arr[j5+3][b5]!='.' || arr[j5+4][b5]!='.')
			{	
			goto LABEL5;
			}
		else if (j5>6 ||b5>10)
			{
			goto LABEL5;
			}

		arr[j5][b5]='|';
		arr[j5+1][b5]='|';
		arr[j5+2][b5]='|';
		arr[j5+3][b5]='|';
		arr[j5+4][b5]='|';
		}
	a[4]=j5;b[4]=b5;c[4]=(c5-1);
	return arr; 
		}
void playgame(char **comparr,char **userarr,int *a1,int *b1,int *c1,int *a2,int *b2,int *c2)
		{
		time_t t;
	 
		/* Intializes random number generator */
		srand((unsigned) time(&t));

		int b,i,userhit=0,comphit=0,j,fb=0,fj=0,endb=0,endj=0,playhu=0,backtrack=0,misscount=0;
		char a,dustbin;
		char **comparr1=malloc(sizeof(char *)*20),**userarr1=malloc(sizeof(char *)*20);
		for (i = 0; i < 20; ++i)
			{
			comparr1[i]=malloc(sizeof(char) * 20);
			userarr1[i]=malloc(sizeof(char)*20);
			}
		dots(comparr1);
		dots(userarr1);
		while(1)
			{
			LABEL6:if(userhit==17 || comphit==17)
				break;
			else
				{
				LABEL7:printf("Guess the co-ordinates\n");
				scanf("%c",&dustbin);
				LABEL7a:scanf("%c",&a);
				scanf("%d",&b);


				if((b>10 || b<1 )|| (a>'j' || a<'a'))
					{
					printf("Wrong co-ordinates\nguess the co-ordinates\n");
					goto LABEL7a;
					}

				j=retcharval(a);
				if(comparr1[j][b]=='X' || comparr1[j][b]=='O')
					{
					printf("Already entered!\n");
					goto LABEL7;
					}
				if(comparr[j][b] =='-' || comparr[j][b] == '|')
					{
					printf("HIT!!!\n");
					userhit++;
					changetablehit(comparr1,j,b);
					if(userhit==17)
						goto LABEL6;

					changetablehit(comparr1,j,b);
					dispdots(comparr1);
					goto LABEL7;
					}
				else
					{
					printf("MISS...\n");
					changetablemiss(comparr1,j,b);
					dispdots(comparr1);
					}

			
				b=fb;
				j=fj;
				printf("Computer plays\n");
				long int retTime;
				retTime = time(0) + 2;
				while (time(0) < retTime);
				int zz;
				LABEL8:
				if(playhu==0)
					{
					b= 1 + rand() % 10;
					j= 1 + rand() % 10;
					}
				else
					{
					time_t t=0;
					srand((unsigned) time(&t));
					
					if(!backtrack)
						{
						zz=rand()%4;
						if(zz==0)
						b=b+1;
					else if(zz==1)
						b=b-1;
					else if(zz==2)
						j=j+1;
					else
						j=j-1;
						}
					else if(backtrack)
							{
					if(zz==0)
						b=b-1;
					else if(zz==1)
						b=b+1;
					else if(zz==2)
						j=j-1;
					else
						j=j+1;
							}
					}

				


				if (userarr1[j][b]=='X' || userarr1[j][b]=='O')
					{
					b=fb;j=fj;
					if ((userarr1[j+1][b]=='X' || userarr1[j+1][b]=='O') && (userarr1[j-1][b]=='X' || userarr1[j-1][b]=='O') && (userarr1[j][b+1]=='X' || userarr1[j][b+1]=='O') && (userarr1[j][b-1]=='X' || userarr1[j][b-1]=='O'))
							{
								playhu=0;
							}
					misscount++;
					goto LABEL8;
					}
				LABEL8b:if(userarr[j][b] == '-' || userarr[j][b] == '|')
					{
					printf("Computer HITS !!!!!\n");
					comphit++;
					changetablehit(userarr1,j,b);
					if(playhu==1)
						{
						if(zz==0)
							b=b+1;
						else if(zz==1)
							b=b-1;
						else if(zz==2)
							j=j+1;
						else
							j=j-1;
						if(b>10 || b<1 || j>10 || j<1)
							{
							j=fj;
							b=fb;
							misscount++;
							goto LABEL8;
							}
						goto LABEL8b;
						}
					else
						{
						fb=b;
						fj=j;
						playhu=1;
						}
					if(comphit==17)
						goto LABEL6;

					
					printf("Computer's Table\n");
					dispdots(userarr1);
					
					goto LABEL8;
					}
				else
					{
					misscount++;
					printf("computer misses...\n");
					changetablemiss(userarr1,j,b);
					if(playhu==1 && misscount==1)
						{
						b=fb;
						j=fj;
						backtrack=1;
						}
					else
						{
						backtrack=0;
						playhu=0;
						misscount=0;
						}
					printf("Computer's Table\n");
					dispdots(userarr1);
					//printf("%d %d %d %d\n",endb,endj,b,j);
					}


				}
			}
		if (userhit==17)
			{
			printf("Congrats you have won!!!!!\n");
			}
		else
			{
			printf("Sorry computer has won...\n");
			}
		}






int battleship()
	{
	int i;
	char **arr = (char **)malloc(20 * sizeof(char *));
		for (i=0; i<=10; i++)
			arr[i] = (char *)malloc(20 * sizeof(char));
	char **placearr;          //place the users ships
	char **compplacearr;        //place computer ships
	dots(arr);
	int *a=(int *)malloc(sizeof(int) * 10);
	int *b=(int *)malloc(sizeof(int) * 10);
	int *c=(int *)malloc(sizeof(int) * 10);
	int *d=(int *)malloc(sizeof(int) * 10);
	int *e=(int *)malloc(sizeof(int) * 10);
	int *f=(int *)malloc(sizeof(int) * 10);
	//changetablemiss(arr,3,5);
	//changetablehit(arr,4,5);
	dispdots(arr);
	placearr=placeship(a,b,c);
	dispdots(placearr);
	compplacearr=compplacesships(d,e,f);
	dispdots(compplacearr);
	playgame(compplacearr,placearr,a,b,c,d,e,f);
	return 0;
	}
int bs()
{
		LABEL9:battleship();
		char c,dustbin;
		printf("\nWant to play again????\n Press y to play again");
		scanf("%c",&dustbin);
		scanf("%c",&c);
		printf("%c\n",c);
		if(c=='y')
			{
			printf("Please wait while the game loads!!!\n");
			long int retTime;
			retTime = time(0) + 3;
			while (time(0) < retTime);
			goto LABEL9;
			}

	return 0;
}
