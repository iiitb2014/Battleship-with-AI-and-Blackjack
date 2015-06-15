#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int number_to_digits(int x)
{
        return x%10;
}

void guess_easy()
{
        int i,j,k,*generated_num,*guess_num,n,good=0,bad=0;
        generated_num=(int*)malloc(4*sizeof(int));
	guess_num=(int*)malloc(4*sizeof(int));
	srand((unsigned)time(NULL));
        A:generated_num[0]=rand()%9 +1;
        generated_num[1]=rand()%10;
        generated_num[2]=rand()%10;
        generated_num[3]=rand()%10;
        for(i=0;i<3;i++)
        {
                for(j=i+1;j<4;j++)
                {
                        if(generated_num[i]==generated_num[j])
                        {
                                goto A;
                        }
                }
        }
      

        printf("\t\tEnter your 4 digit number\n"); 
        for(i=0;i<10;i++) 
        {
                good=0;bad=0;
                scanf("%d",&n);
                for(j=3;j>=0;j--)
                {
                        guess_num[j]=number_to_digits(n);
                        n=n/10;
                }
		for(j=0;j<4;j++)
                {
                        if(generated_num[j]==guess_num[j])
                                good++;

                }
                for(k=0;k<4;k++)
                {
                        for(j=0;j<4;j++)
                        {
                                if(generated_num[j]==guess_num[k] && j!=k)
                                        bad++;
                        }
                }
                printf("%d GOOD , %d BAD \n",good,bad);

                if(good==4)
                {
                        printf("\nYou have guessed the number.GOOD JOB!!!\n");
                }
        }
        printf("\nThe number was: \n");
        for(i=0;i<4;i++)
                printf("%d",generated_num[i]);
        printf("\n");
}

void guess_medium()
{
        int i,j,k;
        long int n;
        int *generated_num,*guess_num,good=0,bad=0;
        generated_num=(int*)malloc(5*sizeof(int));
	guess_num=(int*)malloc(5*sizeof(int));
	srand((unsigned)time(NULL));
        B:generated_num[0]=rand()%9 +1;
        generated_num[1]=rand()%10;
        generated_num[2]=rand()%10;
        generated_num[3]=rand()%10;
        generated_num[4]=rand()%10;;

        for(i=0;i<4;i++)
        {
                for(j=i+1;j<5;j++)
                {
                        if(generated_num[i]==generated_num[j])
                                goto B;
                }
        }
        printf("\t\tEnter your 5 digit number\n");
        for(i=0;i<10;i++)
        {
                good=0;bad=0;
                scanf("%ld",&n);
                for(j=4;j>=0;j--)
                {
                        guess_num[j]=number_to_digits(n);
                        n=n/10;
                }
                for(j=0;j<5;j++)
                {
                        if(generated_num[j]==guess_num[j])
                                good++;
                }
                for(k=0;k<4;k++)
                {
                        for(j=0;j<5;j++)
			{
				if(generated_num[j]==guess_num[k] && j!=k)
                                        bad++;
                        }
                }
                printf("%d GOOD , %d BAD \n",good,bad);

                if(good==5)
                {
                        printf("\nYou have guessed the number. GOOD JOB!!!\n");
                }
        }
        printf("\nThe number was: \n");
        for(i=0;i<5;i++)
                printf("%d",generated_num[i]);
        printf("\n");
}

void guess_hard()
{
        int i,j,k;
        long int n;
        int *guess_num,*generated_num,good=0,bad=0;
        generated_num=(int*)malloc(6*sizeof(int));
	guess_num=(int*)malloc(6*sizeof(int));
	srand((unsigned)time(NULL));
        C:generated_num[0]=rand()%9 +1;
        generated_num[1]=rand()%10;
        generated_num[2]=rand()%10;
        generated_num[3]=rand()%10;
        generated_num[4]=rand()%10;
        generated_num[5]=rand()%10;

        for(i=0;i<5;i++)
        {
                for(j=i+1;j<6;j++)
                {
                        if(generated_num[i]==generated_num[j])
                        {
                                goto C;
                        }
                }
        }
        printf("\t\tEnter your 6 digit number\n");
        for(i=0;i<10;i++)
        {
                good=0;bad=0;
                scanf("%ld",&n);
                for(j=5;j>=0;j--)
                {
                        guess_num[j]=number_to_digits(n);
                        n=n/10;
                }
                for(j=0;j<6;j++)
                {
                        if(generated_num[j]==guess_num[j])
                                good++;
                }
		for(k=0;k<5;k++)
                {
                        for(j=0;j<6;j++)
                        {
                                if(generated_num[j]==guess_num[k] && j!=k)
                                        bad++;
                        }
                }
                printf("%d GOOD , %d BAD \n",good,bad);

                if(good==6)
                {
                        printf("\nYou have guessed the number.GOOD JOB!!!\n");   
                }
        }
        printf("\nThe number was: \n");
        for(i=0;i<6;i++)
                printf("%d",generated_num[i]);
        printf("\n");
}





void rules()
{
        printf("\t\t\tHEY WORLD\n\tGuess the code is a code breaking game of logic.\n Your aim is to crack the code in the least number of attempts.\nYou can also challenge your friends and can compare the number of attempts.\n\n\tRULES:\n\t You get 10 attempts at breaking the code. If you cannot discover it by then, then you lose that game.\nBut that's alright.You can get a new code and try again.\nThere are three Levels to this game, each corresponding to a different level of difficulty.\nTo win, the number you guess must match the number generated by our friend, #Randomizer#!!.\n After each attempt you will be told how you went.\n\n\t-----> x GOOD : 'x' digit in your code are in the same position as the number you are supposed to guess.\n\t-----> y BAD : 'y' digits in your code are present in the number to be guessed, but not in the right position. \nTo make the game slightly simpler, the digits in a number will be unique.");
}


int g()
{
        int choice;
        /*main_menu_of_game:*/printf("\n\n\t\t\tWELCOME TO GUESS THE CODE\n");
        A:printf("\n\t\t\t1.ABOUT THE GAME\n");
        printf("\t\t\t2.PLAY!!\n");
        printf("\t\t\t3.EXIT GAME\n");
        printf("\t\t\tEnter your choice\n");
        printf("\t\t\t");
	scanf("%d",&choice);
        switch(choice)
        {
                case 1:
                {
                        rules();
                        goto A;
                        break;
                }
                case 2:
                {
                        int choice2=0;
                        play_menu:printf("1.EASY\n");
			printf("2.MEDIUM\n");
                        printf("3.HARD\n");
                        printf("4.Go to main menu of the game\n");
                        printf("\nEnter your choice\n");
                        //code doesnt work from this point onwards
                        scanf("%d",&choice2);
                        switch(choice2)
                        {
                                case 1:
                                {
                                        guess_easy();
                                        goto play_menu;
                                        break;
                                }
                                case 2:
                                {
                                        guess_medium();
                                        goto play_menu;
                                        break;
                                }
                                case 3:
                                {
                                        guess_hard();
                                        goto play_menu;
                                        break;
                                }
                                case 4:
                                {
                                        goto A;
                                        break;
                                }
                        }
                }
        }
        return 0;
}

