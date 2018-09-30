#include "header.h"

int main(void) {
	int reroll_decider, number_holds, dice_keep_decision, one_dice, two_dice, three_dice, four_dice, five_dice, target, continue_reroll;
	srand(time(NULL));
	//print_game_board(print_game_rules);
	int dice[5] = { 0 };
	int pos1, pos2, pos3, pos4, pos5, temp, temp1, temp2, player1, player2, choice, input, roll_it, score1 = 0, score2 = 0;
	do {
		printf("Press 1 For Game Rules\nPress 2 To Start Game\nPress 3 To Exit\n");
		scanf("%d", &input);
		game_menu(input);
		if (input == 3) {
			printf("\nGoodbye\n\n");
			return 0;
		}
	} while (input != 2);
	system("cls");
	//Play the game 28 times for 14 rounds
	for (int i = 1; i < 46; i++) {
		
		//If The Iterations Is Odd Player 1 Goes
		if (i % 2 != 0) {
			player1 = 1;
			player2 = 0;
			printf("Player Ones Turn\n");
		}
		//If the Iterations is Even Player 2 Goes
		else if (i % 2 == 0) {
			player1 = 0;
			player2 = 1;
			printf("Player Two Turn\n");
		}

		//Array assigns 5 dice values
		system("pause");
		for (int i = 0; i < 5;) {
			dice[i] = rand() % 6 + 1;
			printf("Die %d: %d\n", i + 1, dice[i]);
			i++;
		}
		//See if they want to change dice or not
		printf("Would you like to reroll any dice? Press 1 To Reroll, 0 To Keep All\n");
		scanf("%d", &dice_keep_decision);
		//If they choose to reroll it will ask how many die they want to hold then execute the function to do so 
		if (dice_keep_decision == 1) {
			//This is the Base Case for the player to pick the die they want to reroll
			printf("How many die would you like to hold? 0-4\n");
			scanf("%d", &number_holds);
			printf("This is your first reroll\n");
			hold_dice(dice, number_holds);
			//This is the loop to allow them to do it two more times, They can now pick to keep 
			for (int n = 0; n < 2; n++) {
				printf("Would you like to reroll again? Press 1 to Reroll, 0 To Keep\n");
				scanf("%d", &continue_reroll);
				if (continue_reroll == 1) {
					printf("How many die would you like to hold? 0-4\n");
					scanf("%d", &number_holds);
					printf("This is your %d/3 rerolls\n", n + 2);
					hold_dice(dice, number_holds);
				}
			}
		}
		print_scoreboard_options();
		//If Player 1, Use Player 1 Scoreboard
		if (player1 == 1) {
			printf("Hey Player 1! What combination would you like to choose? 1-12\n");
			scanf("%d", &choice);
			score1 = score1 + scoreboard1(dice, choice);
			printf("PLAYER ONE: Current Score Is %d\n", score1);
		}
		//If Player 2, Use Player 2 Scoreboard
		else if (player2 == 1) {
			printf("Hey Player 2! What combination would you like to choose? 1-12\n");
			scanf("%d", &choice);
			score2 = score2 + scoreboard2(dice, choice);
			printf("PLAYER TWO: Current Score Is %d\n", score2);
		}
		if (i >= 28) {
			if (score1 >= 63) {
				for (int w = 0; w < 10; w++) {
					printf("Player One Wins!");
				}
				
			}
			else if (score2 >= 63) {
				for (int w = 0; w < 10; w++) {
					printf("Player Two Wins!");
				}
			}
		}
	}

	return 0;
}
//Code Step 10, After For Loop