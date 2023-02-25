/*Casino Style Games Run on the CMD*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

/*Prototype functions*/
void dice(int x);

/*Functions*/

//Time Delay Function, mostly for animating.
void delay(double seconds) {

	double milli_seconds = 1000 * seconds;

	clock_t start_time = clock();

	while (clock() < start_time + milli_seconds);

}

int welcome() {
	int choice = 0;

	printf("*******************************WELCOME*******************************\n");
	printf("Here we have a selection of games!\n");
	delay(.5);
	printf("Your starting balance is $20.\n");
	delay(.5);
	printf("All games have a minimum bet of $1.\n\n");
	printf("Here's our current selection of games: \n");
	printf("Dice [enter 1 to play]\n");
	scanf("%d", &choice);

	return choice;
}

void game_selection(int x, int y) {
	if (x == 1)
	{
		dice(y);
	}
}

void dice(int x) {

	int die = rand()%6+1;
	int player_bet = 0;
	int player_guess = 0;
	int player_balance = x;
	int play_again = 0;
	int game_count = 0;

	if (game_count == 0) {
		system("cls");
		printf("You are betting on the outcome of the roll. If you're right, you double your bet!\n\n");
	}
	
	system("cls");
	delay(.5);
	printf("Your balance is: $%d\n", player_balance);
	printf("Bet [1 for $1] || [2 for $2 (Max Bet)]\n\n");
	scanf("%d", &player_bet);
	printf("Enter a number 1-6!\n");
	scanf("%d", &player_guess);

	printf("Ready? Press ENTER to play!\n");
	getchar();

	system("cls");

	printf("Your bet: %d\n", player_guess);
	printf("Rolling! ");
	for(int i=0; i<20;i++)
	{
		printf("%d", rand()%6+1);
		delay(.3);
		printf("\b");
	}

	printf("\n");

	printf("The lucky number is: %d", die);

	printf("\n");

	if(player_guess == die) 
	{
		printf("Congratulations!\n");
		if (player_bet == 1) 
		{
			player_balance = player_balance + 2;
			printf("Your new balance is: $%d", player_balance);
		}
		else
		{
			player_balance = player_balance + 4;
			printf("Your new balance is: $%d", player_balance);
		}
	} 
	else
	{ 
		printf("Better luck next time!\n");
		if (player_bet == 1) 
		{
			player_balance = player_balance - 1;
			printf("Your new balance is: $%d", player_balance);
		}
		else
		{
			player_balance = player_balance - 2;
			printf("Your new balance is: $%d", player_balance);
		}
	}

	printf("\nPlay again? [1 for yes || 2 for no]\n");
	scanf("%d", &play_again);

	if (play_again == 1) {
		dice(player_balance);
	}

}

int main () {
	int selection = welcome();
	game_selection(selection, 20);
    return 0;
}