#pragma once
#include <stdio.h>
#include <math.h>

int game_menu(int input);

int *hold_dice(int dice[], int number_holds);

void print_scoreboard_options(void);

int scoreboard1(int dice[], int choice);

int scoreboard2(int dice[], int choice);