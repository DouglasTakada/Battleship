#define _CRT_SECURE_NO_WARNINGS
#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#define Carrier 5
#define Battleship 4
#define Cruiser 3
#define Submarine 3
#define Destroyer 2

typedef struct stats {
	int total, hit, miss;
	double ave;
}Stats;


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
void welcome_message(void);


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
void initialize_game_board(char board[][11]);


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
int select_who_starts_first(void);


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
int option(void);


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
int invalid_option(poption, board);


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
void p1_manual_ships(board);


/*
	Name: DT
	Function: random_ship
	date: 11/11/2021
	Input parameters: board
	Returns: Nothing
	Description: This function calls the randomly_place_ships to randomly places ships on the board that
			was passed as the parameter
	Preconditions: The preconditions that are needed are the start of the program
	Postconditions: The ships are randomly placed
*/
void random_ship(board);


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
void manually_place_ships(char p1_board[][11], int size, char letter);


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
void randomly_place_ships(char p1_board[][11], int size, char letter);


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
int check_ship_placement(char p1_board[][11], int row, int col, char letter);


/*
	Name: DT
	Function: first_round
	date: 11/11/2021
	Input parameters: starts, board h_or_m, infile, row, col
	Returns: nothing
	Description: This functions runs through the first round of the game
	Preconditions: The preconditions that are needed are the start of the program
	Postconditions: The first round of the game executes
*/
void first_round(int starts, char board[][11], char h_or_m, FILE** infile, int row, int col);


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
int check_shot(int row, int col, char board[][11], char ar[]);

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
void display_board(char board[][11]);

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
void check_if_sunk_ship(char board[][11], int sunk[], FILE** infile);


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
void determine_winner(int p1[], int p2[]);


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
void output_stats(Stats p1, Stats p2, FILE** infile);

#endif