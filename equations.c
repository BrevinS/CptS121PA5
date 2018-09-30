#include "header.h"

int game_menu(int input) {
	if (input == 1) {
		printf("The scorecard used for Yahtzee is composed of two sections. A upper section and a lower section. A total of thirteen boxes or thirteen scoring combinations are divided amongst the sections. The upper section consists of boxes that are scored by summing the value of the dice matching the faces of the box. If a player rolls four 3's, then the score placed in the 3's box is the sum of the dice which is 12. Once a player has chosen to score a box, it may not be changed and the combination is no longer in play for future rounds. If the sum of the scores in the upper section is greater than or equal to 63, then 35 more points are added to the players overall score as a bonus. The lower section contains a number of poker like combinations.\n");
	}
	else if (input == 2) {
		return 1;
	}
	else if (input == 3) {
		return 0;
	}

}
int *hold_dice(int dice[], int number_holds) {
	int temp1, temp2, temp3, temp4, temp5, pos1, pos2, pos3, pos4, pos5;
	
	if (number_holds == 0) {
		for (int i = 0; i < 5; i++) {
			dice[i] = rand() % 6 + 1;
			printf("Die %d: %d\n", i + 1, dice[i]);
		}
	}
	//When the player holds one dice
	if (number_holds == 1) {
		printf("What ONE dice would you like to hold? 1-5\n");
		scanf("%d", &pos1);

		for (int j = 0; j < 5; j++) {
			if (j + 1 == pos1) {
				temp1 = dice[pos1 - 1];
			}
		}

		//Randomizes all die
		for (int i = 0; i < 5; i++) {
			dice[i] = rand() % 6 + 1;
		}

		dice[pos1 - 1] = temp1;
		//Prints finished array
		for (int i = 0; i < 5;) {
			printf("Die %d: %d\n", i + 1, dice[i]);
			i++;
		}
	}
	//When the player holds two die
	if (number_holds == 2) {
		printf("What TWO dice would you like to hold? 1-5\n");
		scanf("%d%d", &pos1, &pos2);

		for (int j = 0; j < 5; j++) {
			if (j + 1 == pos1) {
				temp1 = dice[pos1 - 1];
			}
			if (j + 1 == pos2) {
				temp2 = dice[pos2 - 1];
			}
		}

		//Randomizes all die
		for (int i = 0; i < 5; i++) {
			dice[i] = rand() % 6 + 1;
		}

		dice[pos1 - 1] = temp1;
		dice[pos2 - 1] = temp2;
		//Prints finished array
		for (int i = 0; i < 5;) {
			printf("Die %d: %d\n", i + 1, dice[i]);
			i++;
		}
	}
	//When the player holds three die
	if (number_holds == 3) {
		printf("What THREE dice would you like to hold? 1-5\n");
		scanf("%d%d%d", &pos1, &pos2, &pos3);

		for (int j = 0; j < 5; j++) {
			if (j + 1 == pos1) {
				temp1 = dice[pos1 - 1];
			}
			if (j + 1 == pos2) {
				temp2 = dice[pos2 - 1];
			}
			if (j + 1 == pos3) {
				temp3 = dice[pos3 - 1];
			}
		}

		//Randomizes all die
		for (int i = 0; i < 5; i++) {
			dice[i] = rand() % 6 + 1;
		}

		dice[pos1 - 1] = temp1;
		dice[pos2 - 1] = temp2;
		dice[pos3 - 1] = temp3;
		//Prints finished array
		for (int i = 0; i < 5;) {
			printf("Die %d: %d\n", i + 1, dice[i]);
			i++;
		}
	}
	//When the player holds four die
	if (number_holds == 4) {
		printf("What FOUR dice would you like to hold? 1-5\n");
		scanf("%d%d%d%d", &pos1, &pos2, &pos3, &pos4);

		for (int j = 0; j < 5; j++) {
			if (j + 1 == pos1) {
				temp1 = dice[pos1 - 1];
			}
			if (j + 1 == pos2) {
				temp2 = dice[pos2 - 1];
			}
			if (j + 1 == pos3) {
				temp3 = dice[pos3 - 1];
			}
			if (j + 1 == pos4) {
				temp4 = dice[pos4 - 1];
			}
		}

		//Randomizes all die
		for (int i = 0; i < 5; i++) {
			dice[i] = rand() % 6 + 1;
		}

		dice[pos1 - 1] = temp1;
		dice[pos2 - 1] = temp2;
		dice[pos3 - 1] = temp3;
		dice[pos4 - 1] = temp4;
		//Prints finished array
		for (int i = 0; i < 5;) {
			printf("Die %d: %d\n", i + 1, dice[i]);
			i++;
		}
	}
	
	return dice;
}

void print_scoreboard_options(void) {
	printf("Enter 1 For Sum Of Ones\n");
	printf("Enter 2 For Sum Of Twos\n");
	printf("Enter 3 For Sum Of Threes\n");
	printf("Enter 4 For Sum Of Fours\n");
	printf("Enter 5 For Sum Of Fives\n");
	printf("Enter 6 For Sum Of Sixes\n");
	printf("Enter 7 For Three Of A Kind\n");
	printf("Enter 8 For Four Of A Kind\n");
	printf("Enter 9 For A Full House\n");
	printf("Enter 10 For A Small Straight\n");
	printf("Enter 11 For A Large Straight\n");
	printf("Enter 12 For A Yahtzee\n");
	printf("Enter 13 For Chance\n");
}

int scoreboard1(int dice[], int choice) {
	int score = 0, temp = 0;
	//For Option 1-6 Works
	if (choice <= 6) {
		for (int i = 1; i < 6; i++) {
			if (dice[i - 1] == choice) {
				temp = temp + 1;
			}
		}
		if (temp == 0) {
			score = 0;
		}
		else if (temp != 0) {
			//scorelist[choice] = temp * choice;
			score = temp * choice;
		}
	}

	//Three Of A Kind Option 7 Meh
	if (choice == 7) {
		int temp = 0, score = 0;
		for (int i = 0; i < 5; i++) {
			if (dice[i] == dice[i + 1]) {
				temp += 1;
			}
		}

		int sum_array = 0;
		for (int i = 0; i < 5; i++) {
			sum_array += dice[i];
		}
		if (temp > 2) {
			//scorelist[7] = sum_array;
			//score = sum_array;
			score = sum_array;
		}
		else if (temp != 3) {
			//scorelist[7] = 0;
			score = 0;
		}
	}

	//Four Of A Kind Option 8 Works
	if (choice == 8) {
			int temp = 0, score = 0;
			for (int i = 0; i < 5; i++) {
				if (dice[i] == dice[i + 1]) {
					temp += 1;
				}
			}

			int sum_array = 0;
			for (int i = 0; i < 5; i++) {
				sum_array += dice[i];
			}
			if (temp == 4) {
				//scorelist[7] = sum_array;
				//score = sum_array;
				score = sum_array;
			}
			else if (temp != 4) {
				//scorelist[7] = 0;
				score = 0;
			}
		}

	//Full House Option 9 Meh
	if (choice == 9) {
		int temp = 0, score = 0;
		for (int i = 0; i < 5; i++) {
			if (dice[i] == dice[i + 1]) {
				temp += 1;
			}
		}
		if (temp == 3) {
			//scorelist[7] = sum_array;
			//score = sum_array;
			score = 25;
		}
		else if (temp != 3) {
			//scorelist[7] = 0;
			score = 0;
		}
	}

	//Small Straight Option 10 Works
	if (choice == 10) {
		for (int i = 1; i < 5; i++) {
			if (dice[i] = dice[i - 1] + 1) {
				temp = temp + 1;
			}
		}
		if (temp != 2) {
			score = 0;
		}else if (temp == 2) {
			score = 30;
		}
	}

	//Large Straight Option 11 Works
	if (choice == 11) {
		for (int i = 1; i < 5; i++) {
			if (dice[i] = dice[i - 1] + 1) {
				temp = temp + 1;
			}
		}
		if (temp != 4) {
			score = 0;
		}else if (temp == 4) {
			score = 40;
		}
	}

	//YAHTZEE Option 12 Works
	if (choice == 12) {
		int temp = 0, score = 0;
		for (int i = 0; i < 5; i++) {
			if (dice[i] == dice[i + 1]) {
				temp += 1;
			}
		}
		if (temp == 4) {
			//scorelist[7] = sum_array;
			//score = sum_array;
			score = 50;
		}
		else if (temp != 4) {
			//scorelist[7] = 0;
			score = 0;
		}
	}

	//Chance Option 13 Works
	if (choice == 13) {
		int sum_array = 0;
		for (int i = 0; i < 5; i++) {
			sum_array += dice[i];
		}
		score = sum_array;
	}

	return score;
}

int scoreboard2(int dice[], int choice) {
	int score = 0, temp = 0;
	//For Option 1-6 Works
	if (choice <= 6) {
		for (int i = 1; i < 6; i++) {
			if (dice[i - 1] == choice) {
				temp = temp + 1;
			}
		}
		if (temp == 0) {
			score = 0;
		}
		else if (temp != 0) {
			//scorelist[choice] = temp * choice;
			score = temp * choice;
		}
	}

	//Three Of A Kind Option 7 Meh
	if (choice == 7) {
		int temp = 0, score = 0;
		for (int i = 0; i < 5; i++) {
			if (dice[i] == dice[i + 1]) {
				temp += 1;
			}
		}

		int sum_array = 0;
		for (int i = 0; i < 5; i++) {
			sum_array += dice[i];
		}
		if (temp > 2) {
			//scorelist[7] = sum_array;
			//score = sum_array;
			score = sum_array;
		}
		else if (temp != 3) {
			//scorelist[7] = 0;
			score = 0;
		}
	}

	//Four Of A Kind Option 8 Works
	if (choice == 8) {
		int temp = 0, score = 0;
		for (int i = 0; i < 5; i++) {
			if (dice[i] == dice[i + 1]) {
				temp += 1;
			}
		}

		int sum_array = 0;
		for (int i = 0; i < 5; i++) {
			sum_array += dice[i];
		}
		if (temp == 4) {
			//scorelist[7] = sum_array;
			//score = sum_array;
			score = sum_array;
		}
		else if (temp != 4) {
			//scorelist[7] = 0;
			score = 0;
		}
	}

	//Full House Option 9 Meh
	if (choice == 9) {
		int temp = 0, score = 0;
		for (int i = 0; i < 5; i++) {
			if (dice[i] == dice[i + 1]) {
				temp += 1;
			}
		}
		if (temp == 3) {
			//scorelist[7] = sum_array;
			//score = sum_array;
			score = 25;
		}
		else if (temp != 3) {
			//scorelist[7] = 0;
			score = 0;
		}
	}

	//Small Straight Option 10 Works
	if (choice == 10) {
		for (int i = 1; i < 5; i++) {
			if (dice[i] = dice[i - 1] + 1) {
				temp = temp + 1;
			}
		}
		if (temp != 2) {
			score = 0;
		}
		else if (temp == 2) {
			score = 30;
		}
	}

	//Large Straight Option 11 Works
	if (choice == 11) {
		for (int i = 1; i < 5; i++) {
			if (dice[i] = dice[i - 1] + 1) {
				temp = temp + 1;
			}
		}
		if (temp != 4) {
			score = 0;
		}
		else if (temp == 4) {
			score = 40;
		}
	}

	//YAHTZEE Option 12 Works
	if (choice == 12) {
		int temp = 0, score = 0;
		for (int i = 0; i < 5; i++) {
			if (dice[i] == dice[i + 1]) {
				temp += 1;
			}
		}
		if (temp == 4) {
			//scorelist[7] = sum_array;
			//score = sum_array;
			score = 50;
		}
		else if (temp != 4) {
			//scorelist[7] = 0;
			score = 0;
		}
	}

	//Chance Option 13 Works
	if (choice == 13) {
		int sum_array = 0;
		for (int i = 0; i < 5; i++) {
			sum_array += dice[i];
		}
		score = sum_array;
	}

	return score;
}