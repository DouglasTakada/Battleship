#include "functions.h"

/*
	Name: DT
	Function: void welcome_message(void)
	date: 11/11/2021
	Input parameters: void
	Returns: Nothing
	Description: This function prints a welcome message and prints the rules of the game
	Preconditions: The preconditions that are needed are the start of the program
	Postconditions: The message prints
*/
void welcome_message(void) {
	printf("\t\t***** Welcome to Battleship! *****\n");
	printf("\tHere is how you play:\n");
	printf("\tThis game is a two player game\n");
	printf("\tPlayer 1 is you and Player 2 is the computer\n");
	printf("\tThe object of the game is to sink your opponents ships\n");
	printf("\tbefore they do\n");
	printf("\tThe player who starts first is chosen randomly\n");
	printf("\tOnce it is your turn you can choose where you would like to\n");
	printf("\tplace your five battle ships on your 10X10 board\n");
	printf("\tYou are given five ships with differing size\n");
	printf("\tHere are the five different ships you are given:\n\n");
	printf("\t________________________________________\n");
	printf("\t|1. Carrier: Takes up five spaces       |\n");
	printf("\t|2. Battleship: Takes up four spaces    |\n");
	printf("\t|3. Cruiser: Takes up three spaces      |\n");
	printf("\t|4. Submarine: Takes up three spaces    |\n");
	printf("\t|5. Destroyer: takes up two spaces      |\n");
	printf("\t|_______________________________________|\n\n");
	printf("\tYou will be given these ships to place in this order\n");
	printf("\tOnce the ships are placed the game will begin\n");
	printf("\tYou will choose what cell to hit by inputting\n");
	printf("\tthe row number and column number\n\n");
	printf("\t\t Press Enter to start the game!\n");
	system("pause");
	system("cls");
}


/*
	Name: DT
	Function: initialize_game_board(char board[][11])
	date: 11/11/2021
	Input parameters: char board
	Returns: Nothing
	Description: This function initializes the board that gets passed in as a parameter
	Preconditions: The preconditions that are needed are the start of the program
	Postconditions: The board that was passed is initialized
*/
void initialize_game_board(char board[][11]) {
	int row = 0, col = 0;
	for (; row < 11; row++) {
		col = 0;
		board[row][col] = row;
		for (; col < 11; col++) {
			board[row][col] = '-';
		}
	}
	board[0][0] = 'X';
	board[0][1] = '0';
	board[0][2] = '1';
	board[0][3] = '2';
	board[0][4] = '3';
	board[0][5] = '4';
	board[0][6] = '5';
	board[0][7] = '6';
	board[0][8] = '7';
	board[0][9] = '8';
	board[0][10] = '9';

	board[1][0] = '0';
	board[2][0] = '1';
	board[3][0] = '2';
	board[4][0] = '3';
	board[5][0] = '4';
	board[6][0] = '5';
	board[7][0] = '6';
	board[8][0] = '7';
	board[9][0] = '8';
	board[10][0] = '9';
}


/*
	Name: DT
	Function: select_who_starts_first
	date: 11/11/2021
	Input parameters: void
	Returns: a randome integer either 1 or 2 for player 1 or player 2
	Description: This function randomly determines which player goes first
	Preconditions: The preconditions that are needed are the start of the program
	Postconditions: A integer is returned
*/
int select_who_starts_first(void) {
	return (rand() % 2) + 1;
}


/*
	Name: DT
	Function: option(void)
	date: 11/11/2021
	Input parameters: void
	Returns: returns an integer which is the option that the user input
	Description: This function asks for a input from the user and returns its option number
	Preconditions: The preconditions that are needed are the start of the program
	Postconditions: Returns the number the user entered
*/
int option(void) {
	int temp = 0;
	printf("\t\tPlease enter an option the following Menu:\n");
	printf("\t1. Enter positions of ships manually\n");
	printf("\t2. Allow the program to randomly select positions of ships\n");
	scanf("%d", &temp);
	return temp;
}


/*
	Name: DT
	Function: invalid_option(poption, board)
	date: 11/11/2021
	Input parameters: poption, board
	Returns: Returns an integer to determine if the user has input a valid option
	Description: This function is a part of a while loop that makes sure the user inputs valid options
	Preconditions: The preconditions that are needed are the start of the program
	Postconditions: returns the option value to the main function
*/
int invalid_option(poption, board) {
	printf("\tYou have entered a invalid option.\n");
	printf("\tPlease try again.\n");
	system("pause");
	system("cls");
	display_board(board);
	return option();
}


/*
	Name: DT
	Function: p1_manual_ships
	date: 11/11/2021
	Input parameters: board
	Returns: Nothing
	Description: This function calls the manually_place_ships to have the user place their ships
	Preconditions: The preconditions that are needed are the start of the program
	Postconditions: all of the ships are placed on the board
*/
void p1_manual_ships(board) {
	char letter = '\0';
	letter = 'C';
	printf("Enter the coordinates of where you would like to place your Carrier Ship (5 spaces)\n");
	manually_place_ships(board, Carrier, letter);
	letter = 'B';
	printf("Enter the coordinates of where you would like to place your Battle ship (4 spaces)\n");
	manually_place_ships(board, Battleship, letter);
	letter = 'c';
	printf("Enter the coordinates of where you would like to place your Cruiser ship (3 spaces)\n");
	manually_place_ships(board, Cruiser, letter);
	letter = 'S';
	printf("Enter the coordinates of where you would like to place your Submarine (3 spaces)\n");
	manually_place_ships(board, Submarine, letter);
	letter = 'D';
	printf("Enter the coordinates of where you would like to place your Destroyer ship (2 spaces)\n");
	manually_place_ships(board, Destroyer, letter);
}


/*
	Name: DT
	Function: random_ships
	date: 11/11/2021
	Input parameters: board
	Returns: Nothing
	Description: This function calls the randomly_place_ships to randomly places ships on the board that
			was passed as the parameter
	Preconditions: The preconditions that are needed are the start of the program
	Postconditions: The ships are randomly placed
*/
void random_ships(board) {
	char letter = '\0';
	letter = 'C';
	randomly_place_ships(board, Carrier, letter);
	letter = 'B';
	randomly_place_ships(board, Battleship, letter);
	letter = 'c';
	randomly_place_ships(board, Cruiser, letter);
	letter = 'S';
	randomly_place_ships(board, Submarine, letter);
	letter = 'D';
	randomly_place_ships(board, Destroyer, letter);
}


/*
	Name: DT
	Function: manually_place_ships
	date: 11/11/2021
	Input parameters: board, size, letter
	Returns: Nothing
	Description: This function manually places each individual ships and checks for invalid input
	Preconditions: The preconditions that are needed are the start of the program
	Postconditions: The ships are properly placed
*/
void manually_place_ships(char board[][11], int size, char letter) {
	int row = 0, col = 0, count = 0;
	printf("Enter it in the order of row and then column\n");

	for (; count <= size - 1; count++) {
		printf("Enter the row number then the column\n");
		scanf("%d", &row);
		scanf("%d", &col);
		row++, col++;
		row = check_ship_placement(board, row, col, letter);
		while (row > 10 || col > 10 || board[row][col] != '-') {
			display_board(board);
			printf("You entered a invalid cell, try again.\n");
			printf("Enter the coordinates of where you would like to place your ship\n");
			printf("Enter it in the order of ROW and then COLUMN\n");
			scanf("%d", &row);
			scanf("%d", &col);
			row++, col++;
			row = check_ship_placement(board, row, col, letter);
		}
		system("cls");
		board[row][col] = letter;
		display_board(board);
	}
}


/*
	Name: DT
	Function: randomly_place_ships
	date: 11/11/2021
	Input parameters: board, size, letter
	Returns: Nothing
	Description: This function does the logic and the actual placing of each ships
	Preconditions: The preconditions that are needed are the start of the program
	Postconditions: The ships would be placed randomly in valid positions
*/
void randomly_place_ships(char board[][11], int size, char letter) {
	int rand_dir = (rand() % 3) + 1;
	int rand_row = 0, rand_col = 0, checker_num = 0, temp2 = 0;
	char temp = '\0';
	switch (rand_dir) {
	case 1:
		while (checker_num != 1) {
			checker_num = 0, temp2 = 0;
			rand_row = (rand() % 9);
			rand_col = (rand() % 9);
			for (int a = 0; a < size; a++) {
				temp = board[rand_row + a][rand_col];
				if (temp == '-') {
					temp2++;
				}
				else {
					checker_num = -1;
				}
			}
			if (temp2 == size) {
				checker_num = 1;
			}
		}
		for (int a = 0; a < size; a++) {
			board[rand_row + a][rand_col] = letter;
		}
		break;
	case 2:
		while (checker_num != 1) {
			checker_num = 0, temp2 = 0;
			rand_row = (rand() % 9);
			rand_col = (rand() % 9);
			for (int a = 0; a < size; a++) {
				temp = board[rand_row][rand_col + a];
				if (temp == '-') {
					temp2++;
				}
				else {
					checker_num = -1;
				}
			}
			if (temp2 == size) {
				checker_num = 1;
			}
		}
		for (int a = 0; a < size; a++) {
			board[rand_row][rand_col + a] = letter;
		}
		break;
	case 3:
		while (checker_num != 1) {
			checker_num = 0, temp2 = 0;
			rand_row = (rand() % 9);
			rand_col = (rand() % 9);
			for (int a = 0; a < size; a++) {
				temp = board[rand_row - a][rand_col];
				if (temp == '-') {
					temp2++;
				}
				else {
					checker_num = -1;
				}
			}
			if (temp2 == size) {
				checker_num = 1;
			}
		}
		for (int a = 0; a < size; a++) {
			board[rand_row - a][rand_col] = letter;
		}
		break;
	case 4:
		while (checker_num != 1) {
			checker_num = 0, temp2 = 0;
			rand_row = (rand() % 9);
			rand_col = (rand() % 9);
			for (int a = 0; a < size; a++) {
				temp = board[rand_row][rand_col - a];
				if (temp == '-') {
					temp2++;
				}
				else {
					checker_num = -1;
				}
			}
			if (temp2 == size) {
				checker_num = 1;
			}
		}
		for (int a = 0; a < size; a++) {
			board[rand_row][rand_col - a] = letter;
		}
	}

}


/*
	Name: DT
	Function: check_ship_placement(board, row, col, letter)
	date: 11/11/2021
	Input parameters: board, row, col, letter
	Returns: returns an integer
	Description: This function checks the ship placement of each ship placement
	Preconditions: The preconditions that are needed are the start of the program
	Postconditions: checks to make sure the input is valid
*/
int check_ship_placement(char board[][11], int row, int col, char letter) {
	if (row > 11 || col > 11 || board[row - 1][col - 1] == letter || board[row + 1][col + 1] == letter) {
		return -1;
	}
	return row;
}

/*
	Name: DT
	Function: first_round
	date: 11/11/2021
	Input parameters: starts board h_or_m, infile, row, col
	Returns: nothing
	Description: This functions runs through the first round of the game
	Preconditions: The preconditions that are needed are the start of the program
	Postconditions: The first round of the game executes
*/
void first_round(int starts, char board[][11], char h_or_m, FILE** infile, int row, int col) {
	if (starts != 1) {// make the computer shoot first
		printf("\tPlayer 2 has been randomly selected to go first\n");
		fprintf(infile, "Player 2 has been randomly selected to go first\n");
		row = rand() % 9 + 1;
		col = rand() % 9 + 1;
		check_shot(row, col, board, h_or_m);

	}
	else {
		printf("\tPlayer 1 has been randomly selected to go first\n");
		fprintf(infile, "Player 1 has been randomly selected to go first\n");
	}
}


/*
	Name: DT
	Function: check_shot
	date: 11/12/2021
	Input parameters: row, col, board, arr
	Returns: retruns an integer that represents if the input is valid
	Description: This function determines whether the player input is valid or not
	Preconditions: The preconditions that are needed are the start of the program
	Postconditions: The value that corrosponds to a valid or invalid input is returned
*/
int check_shot(int row, int col, char board[][11], char ar[]) {
	if (row < 0 || col < 0) {
		return -1;
	}
	if (row > 10 || col > 10) {
		return -1;
	}
	if (board[row][col] == 'm' || board[row][col] == '*') {
		return -1;
	}
	return 1;
}


/*
	Name: DT
	Function: display_board
	date: 11/12/2021
	Input parameters: board
	Returns: Nothing
	Description: This function prints the board that is passed through its parameter
	Preconditions: The preconditions that are needed are the start of the program
	Postconditions: The players board will be printed
*/
void display_board(char board[][11]) {
	int r = 0, c = 0;
	for (; r < 11; r++) {
		c = 0;
		printf("\t");
		for (; c < 11; c++) {
			printf(" %c", board[r][c]);
		}
		printf("\n");
	}
	printf("\n");

}


/*
	Name: DT
	Function: check_if_ship_sunk
	date: 11/12/2021
	Input parameters:board, sunk, infile
	Returns: Nothing
	Description: This funcion does the logic to determine what ship has sunk most recently
		and prints which ship has sunk to the file and the command prompt
	Preconditions: The preconditions that are needed are the start of the program
	Postconditions: The proper messages should be displayed according to the logic
*/
void check_if_sunk_ship(char board[][11], int sunk[], FILE** infile) {
	int C = 0, c = 0, B = 0, S = 0, D = 0;
	//sunk[0] = 0;

	for (int a = 1; a < 11; a++) {
		for (int b = 1; b < 11; b++) {
			if (board[a][b] == 'C') {
				C++;
			}
			if (board[a][b] == 'c') {
				c++;
			}
			if (board[a][b] == 'S') {
				S++;
			}
			if (board[a][b] == 'B') {
				B++;
			}
			if (board[a][b] == 'D') {
				D++;
			}
		}
	}
	if (C == 0 && sunk[1] == 0) {
		printf("\tThe Carrier ship has sunk\n");
		fprintf(infile, "The Carrier ship has sunk\n");
		sunk[1] = 1;
	}
	if (B == 0 && sunk[2] == 0) {
		printf("\tThe Battle ship has sunk\n");
		fprintf(infile, "The Battle ship has sunk\n");
		sunk[2] = 1;
	}
	if (c == 0 && sunk[3] == 0) {
		printf("\tThe Cruiser ship has sunk\n");
		fprintf(infile, "The Cruiser ship has sunk\n");
		sunk[3] = 1;
	}
	if (S == 0 && sunk[4] == 0) {
		printf("\tThe Submarine has sunk\n");
		fprintf(infile, "The Submarine has sunk\n");
		sunk[4] = 1;
	}
	if (D == 0 && sunk[5] == 0) {
		printf("\tThe Destoryer has sunk\n");
		fprintf(infile, "The Destoryer ship has sunk\n");
		sunk[5] = 1;
	}
	if (C == 0 && B == 0 && c == 0 && S == 0 && D == 0) {
		sunk[0] = 1;
	}
}

/*
	Name: DT
	Function: determine_winner
	date: 11/12/2021
	Input parameters: p1, p2
	Returns: Nothing
	Description: This funcion prints who was the winner based on the parameters
	Preconditions: The preconditions that are needed are the start of the program
	Postconditions: The proper message should be printed based on the passed parameters
*/
void determine_winner(int p1[], int p2[]) {
	if (p1[0] == 1) {
		printf("\tCongrats Player 1 you won!\n");
	}
	else {
		printf("\tDarn you lost\n");
	}
}

/*
	Name: DT
	Function: output_stats
	date: 11/12/2021
	Input parameters: p1, p2, infile
	Returns: Nothing
	Description: This function outputs the stats to the file and to the command line
	Preconditions: The preconditions that are needed are the start of the program
	Postconditions: The proper calculations and messages will be displayed on the commandline and the logfile
*/
void output_stats(Stats p1, Stats p2, FILE** infile) {
	if (infile == NULL) {
		printf("Statistics unable to be outputted to logfile\n");
	}
	else {
		printf("Statistics outputted to logfile successfully!\n");
	}
	p1.ave = 100 * ((double)p1.hit / (p1.total + p1.miss));
	printf("\t\tHere are the player 1 stats:\n");
	printf("\tNumber of Hits: %d\n\tNumber of Misses: %d\n\tTotal number of shots: %d\n\tHit to miss ratio: %.2f\n\n",
		p1.hit, p1.miss, p1.total, p1.ave);
	fprintf(infile, "\t\tHere are the player 1 stats:\n");
	fprintf(infile, "\tNumber of Hits: %d\n\tNumber of Misses: %d\n\tTotal number of shots: %d\n\tHit to miss ratio: %.2f\n\n",
		p1.hit, p1.miss, p1.total, p1.ave);

	p2.ave = 100 * ((double)p2.hit / (p2.total + p2.miss));
	printf("\t\tHere are the player 2 stats:\n");
	printf("\tNumber of Hits: %d\n\tNumber of Misses: %d\n\tTotal number of shots: %d\n\tHit to miss ratio: %.2f",
		p2.hit, p2.miss, p2.total, p2.ave);
	fprintf(infile, "\t\tHere are the player 2 stats:\n");
	fprintf(infile, "\tNumber of Hits: %d\n\tNumber of Misses: %d\n\tTotal number of shots: %d\n\tHit to miss ratio: %.2f",
		p2.hit, p2.miss, p2.total, p2.ave);
}

