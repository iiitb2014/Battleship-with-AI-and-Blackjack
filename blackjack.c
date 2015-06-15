#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int cardvalue(char x)
{
    if(x == 'K' || x == 'Q' || x == 'J' || x == ':') return 10;
    else if(x == 'A') return 1;
    else if(x == '2') return 2;
    else if(x == '3') return 3;
    else if(x == '4') return 4;
    else if(x == '5') return 5;
    else if(x == '6') return 6;
    else if(x == '7') return 7;
    else if(x == '8') return 8;
    else return 9;
}

char cardsymbol()
{
    int x;
    x = rand() % 13;
    if(x == 9) return ':';
    else if(x == 10) return 'K';
    else if(x == 11) return 'Q';
    else if(x == 12) return 'J';
    else if(x == 0) return 'A';
    else if(x == 1) return '2';
    else if(x == 2) return '3';
    else if(x == 3) return '4';
    else if(x == 4) return '5';
    else if(x == 5) return '6';
    else if(x == 6) return '7';
    else if(x == 7) return '8';
    else if(x == 8) return '9';
}

int blackjack(int *ptr)
{
    //Players gets his/her cards
    time_t t1 = 0;
    srand((unsigned) time(&t1));
    int playersum = 0, card1val, card2val, cardxval;
    int money = 500, bet = 0;
    char playercard1, playercard2, playercardx;
    playercard1 = cardsymbol();
    playercard2 = cardsymbol();
    card1val = cardvalue(playercard1);
    card2val = cardvalue(playercard2);
    playersum = card1val + card2val;


    //Dealer gets his cards
    time_t t = 0;
    srand((unsigned) time(&t));
    char dealercard1, dealercard2, dealercardx;
    int dealercard1val, dealercard2val, dealercardxval, dealersum = 0;
    dealercard1 = cardsymbol();
    dealercard2 = cardsymbol();
    dealercard1val = cardvalue(dealercard1);
    dealercard2val = cardvalue(dealercard2);
    dealersum = dealercard1val + dealercard2val;


    //Initial condition
    printf("Your account: $%d\n", *ptr);
    printf("Enter your bet: $");
    scanf("%d", &bet);
    while(bet > *ptr)
    {
        printf("You can't bet more than how much you own! Try again!\n");
        scanf("%d", &bet);
    }
    if(card1val == 10)
        printf("Your cards are 10 and %c\n", playercard2);
    else if(card2val == 10)
        printf("Your cards are %c and 10\n", playercard1);
    else
        printf("Your cards are %c and %c\n", playercard1, playercard2);
    printf("Your total is %d\n", playersum);

    char choice = 'Y', finalchoice = 'Y', dustbin = 'A';


    //Loop is run until player 'stays'
    while(choice != 'S' || choice != 's')
    {
        printf("What do you want to do? Hit or Stay?\n");
        printf("H - Hit\nS - Stay\n");
        scanf("%c %c", &dustbin, &choice);
        if(choice == 'H' || choice == 'h')
        {
            //Player gets a new card
            playercardx = cardsymbol();
            cardxval = cardvalue(playercardx);
            playersum = playersum + cardxval;
            if(cardxval == 10)
                printf("Your new card is 10\n");
            else
                printf("Your new card is %c\n", playercardx);
            if(playersum > 21)
            {
                printf("Busted! Over 21! You lose $%d\n", bet);
                *ptr = *ptr - bet;
                printf("Money left: $%d\n", *ptr);
                printf("Want to play again?\n");
                printf("Y - Play Again\nN - Exit\n");
                scanf("%c %c", &dustbin, &finalchoice);
                if(finalchoice == 'Y' || finalchoice == 'y')
                    return 1;
                else
                    return 0;
            }
            else
            {
                printf("Your total is %d\n", playersum);
                sleep(1);
            }
            if(dealersum < 17)
            {
                printf("The dealer hits\n");
                sleep(1);
                dealercardx = cardsymbol();
                dealercardxval = cardvalue(dealercardx);
                dealersum = dealersum + dealercardxval;
                if(dealersum > 21)
                {
                    printf("The dealer goes over! You win $%d!\n", bet);
                    *ptr = *ptr + bet;
                    printf("Money left: $%d\n", *ptr);
                    printf("Want to play again?\n");
                    printf("Y - Yes\nN - No\n");
                    scanf("%c %c", &dustbin, &finalchoice);
                    if(finalchoice == 'y' || finalchoice == 'Y')
                        return 1;
                    else if(finalchoice == 'n' || finalchoice == 'N')
                        return 0;
                    else
                        printf("Wrong character! Try again!\n");

                }
            }
            else
            {
                printf("The dealer stays\n");
                sleep(1);
            }
        }
        else if(choice == 'S' || choice == 's')
        {
            printf("Your total is %d\n", playersum);
            sleep(1);
            while(dealersum < 17)
            {
                dealercardx = cardsymbol();
                dealercardxval = cardvalue(dealercardx);
                dealersum = dealersum + dealercardxval;
                if(dealersum > 21)
                {
                    printf("The dealer goes over! You win!\n");
                    *ptr = *ptr + bet;
                    printf("Money left: $%d\n", *ptr);
                    printf("Want to play again?\n");
                    printf("Y - Yes\nN - No\n");
                    scanf("%c %c", &dustbin, &finalchoice);
                    if(finalchoice == 'Y' || finalchoice == 'y')
                        return 1;
                    else if(finalchoice == 'n' || finalchoice == 'N')
                        return 0;
                    else
                        printf("Wrong character! Try again!\n");
                }
                if(dealersum >= 17)
                {
                    printf("The dealer sum is %d\n", dealersum);
                    sleep(1);
                    break;
                }
            }
            printf("The dealer stays\n");
            sleep(1);
            break;
        }
        else
            printf("Wrong character! Try Again\n");
    }


    if(dealersum <= 21)
    {
        if(playersum >= dealersum && playersum <= 21)
        {
            printf("Congratulations! You win $%d\n", bet);
            *ptr = *ptr + bet;
            printf("Money left: $%d\n", *ptr);
            printf("Want to play again?\n");
            printf("Y - Yes\nN - No\n");
            scanf("%c %c", &dustbin, &finalchoice);
            if(finalchoice == 'Y' || finalchoice == 'y')
                return 1;
            else if(finalchoice == 'n' || finalchoice == 'N')
                return 0;
            else
                printf("Wrong character! Try again!\n");
        }
        else
        {
            printf("The dealer wins! You lose $%d\n", bet);
            *ptr = *ptr - bet;
            printf("Money left: $%d\n", *ptr);
            printf("Want to play again?\n");
            printf("Y - Yes\nN - No\n");
            scanf("%c %c", &dustbin, &finalchoice);
            if(finalchoice == 'Y' || finalchoice == 'y')
                return 1;
            else if(finalchoice == 'n' || finalchoice == 'N')
                return 0;
            else
                printf("Wrong character! Try again!\n");
        }
    }
}



int bj()
{
    printf("Welcome to Blackjack\n");
    int x = 1, money = 500;
    int *ptr;
    ptr = &money;
    while(x != 0)
    {
        x = blackjack(ptr);
        sleep(1);
    }
    if(money > 500)
        printf("Congratulations! You have exited the game with a profit of %d. Come back and continue your streak!\n", money - 500);
    else if(money < 500)
        printf("Too bad! You have exited the game with a loss of %d. Play again to win back your money! :P\n", 500 - money);
    else
        printf("You haven't won or lost anything! Boring!\n");

}

