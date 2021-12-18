#include "functions.h"

int main(void) {
	// Before the game
	FILE* infile;
	infile = fopen("logfile.txt", "w");
	int main = 0, p1_sunk[] = { 0, 0, 0, 0 ,0, }, p2_sunk[] = { 0, 0, 0, 0, 0, 0 },// create all boards and variables for game
		p1_option = 0, who_starts = 0, check = 0, row = 0, col = 0, valid = 0;
	char p1_board[11][11] = { '\0' }, p2_board[11][11] = { '\0' },
		p2_actual_board[11][11] = { '\0' }, letter = '\0', hit_or_miss[] = { '\0' };
	Stats p1 = { 0, 0, 0, 0.0 }; //creates struct variables to keep track of stats
	Stats p2 = { 0, 0, 0, 0.0 };
	srand(time(0)); // Calls this function so I can use the random function
	welcome_message();//Welcome message
	initialize_game_board(p1_board);//initialzes for the board that gets passed through the parameter
	initialize_game_board(p2_board);
	initialize_game_board(p2_actual_board);
	display_board(p1_board); // displays empty board
	p1_option = option(); //Asks user input
	while (p1_option != 1 && p1_option != 2) {// Goes through the loop until the input is valid
		p1_option = invalid_option(p1_option, p1_board);
	}
	switch (p1_option) {// Either the player wants to manually place the corrdinates or have their ship be randomly placed

	case 1:
		p1_manual_ships(p1_board);// Asks for user to input points for each point for the ships
		break;

	case 2:
		random_ships(p1_board); //randomly places ships for player 1
		break;
	}
	random_ships(p2_actual_board); // randomly places ships for player 2

	system("cls");
	who_starts = select_who_starts_first(); //Randomly decides who should start first; player 1 or player 2
	first_round(who_starts, p1_board, hit_or_miss, infile, row, col); //This function goes through the logic and computation of
			//the first round depending on who is chosen to go first
	display_board(p1_board);//displays boards
	display_board(p2_board);
	system("pause");
	system("cls");
	while (p2_sunk[0] == 0 || p1_sunk[0] == 0) {//Goes through the loop of players taking turns until all of the opposing ships sink
		printf("\t\t>>Your Board<<\n");
		display_board(p1_board);
		printf("\t\t||Player 2s Board||\n");
		display_board(p2_board);
		printf("\tIt is your turn\n");
		printf("\tEnter a target: ");
		scanf("%d", &row);
		scanf("%d", &col);
		row++, col++;
		system("cls");
		valid = check_shot(row, col, p2_actual_board, hit_or_miss);//checks to see if the input was valid
		while (valid != 1) {//goes through loop until valid input is entered
			system("cls");
			printf("\tYou have entered a invalid target, try again\n");
			printf("\t\t>>Your Board<<\n");
			display_board(p1_board);
			printf("\t\t||Player 2s Board||\n");
			display_board(p2_board);//
			scanf("%d", &row);
			scanf("%d", &col);
			row++, col++;
			valid = check_shot(row, col, p2_actual_board, hit_or_miss);
		}
		if (row == 1 || row == 2 || row == 3 || row == 4 || row == 5 || row == 6 || row == 7 || row == 8 || row == 9) {// logic for the first row becasue of the layout of the board
			p2_board[row][col] = hit_or_miss[0];
		}
		if (col == 1 || col == 2 || col == 3 || col == 4 || col == 5 || col == 6 || col == 7 || col == 8 || col == 9) {
			p2_board[row][col] = hit_or_miss[0];
		}
		if (p2_actual_board[row][col] != '-') {// logics of if the user got a hit
			p2_board[row][col] = '*';
			p2_actual_board[row][col] = '*';
			printf("\Player 1 chose (%d, %d) and got a hit!\n", row - 1, col - 1);
			fprintf(infile, "Player 1 chose (%d, %d) and got a hit!\n", row - 1, col - 1);
			p1.total++;
			p1.hit++;
		}
		else if (p2_actual_board[row][col] == '-') {// logics for when the user misses
			p2_board[row][col] = 'm';
			p2_actual_board[row][col] = 'm';
			printf("\tPlayer 1 chose (%d, %d) and missed\n", row - 1, col - 1);
			fprintf(infile, "Player 1 chose (%d, %d) and missed\n", row - 1, col - 1);
			p1.total++;
			p1.miss++;
		}
		check_if_sunk_ship(p2_actual_board, p2_sunk, infile);//checks if any ships have sunk on this round
		if (p2_sunk[0] == 1 || p1_sunk[0] == 1) {
			break;
		}
		printf("\t\t>>Your Board<<\n");
		display_board(p1_board);//
		printf("\t\t||Player 2s Board||\n");
		display_board(p2_board);
		system("pause");
		system("cls");
		printf("\tIt is now Plyer 2s turn\n");
		valid = 0;
		while (valid != 1) {// Goes through the logic of player 2
			row = rand() % 9 + 1;
			col = rand() % 9 + 1;
			valid = check_shot(row, col, p1_board, hit_or_miss);
		}
		if (p1_board[row][col] != '-') {// Logic of if player 2 got a hit
			p1_board[row][col] = '*';
			printf("\player 2 chose (%d, %d) and got a hit!\n", row - 1, col - 1);
			fprintf(infile, "Player 2 chose (%d, %d) and got a hit!\n", row - 1, col - 1);
			p1_board[row][col] = '*';
			p2.total++;
			p2.hit++;
		}
		else if (p1_board[row][col] == '-') {// Logic of if player 2 missed 
			p1_board[row][col] = 'm';
			printf("\tPlayer 2 chose (%d, %d) and missed\n", row - 1, col - 1);
			fprintf(infile, "Player 2 chose (%d, %d) and missed\n", row - 1, col - 1);
			p2.total++;
			p2.miss++;
		}
		check_if_sunk_ship(p1_board, p1_sunk, infile); //Check if any ships sunk
		if (p2_sunk[0] == 1 || p1_sunk[0] == 1) {
			break;
		}
		printf("\t\t>>Your Board<<\n");
		display_board(p1_board);
		printf("\t\t||Player 2s Board||\n");
		display_board(p2_board);
		system("pause");
		system("cls");
	}
	system("pause");
	system("cls");
	determine_winner(p2_sunk, p1_sunk); //prints the winner
	output_stats(p1, p2, infile); //prints the stats of the two players
	fclose(infile);
	return 0;
}