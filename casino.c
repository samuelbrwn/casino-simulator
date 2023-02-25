/*Casino Style Games Run on the CMD*/
#include <stdio.h>
#include <time.h>
#include <games.h>

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

void game_selection(int x) {
	if (x == 1)
	{
		dice();
	}
}

int main () {
	int selection = welcome();
	game_selection(selection);
    return 0;
}