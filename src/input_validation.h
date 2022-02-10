#ifndef INPUT_VALIDATION
#define INPUT_VALIDATION

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include "player.h"
#include "board.h"

/**
* Checks if the given coordinates are sufficient
* to create a board
*
* @param x width of the board
* @param y length of the board
* @return true if the board can be created, otherwise - false
*/
bool validate_size_of_the_board(int x,  int y);



/**
* Checks if the given penguin number is valid
*
* @param number of penguins
* @return true if the number is valid, otherwise - false
*/
bool validate_number_of_penguins(int penguins_number);

/**
* Used in validate_penguin_coordinates and validate_new_coordinates to simplify the code
* checks if the given coordinates of the penguin are inside of the board
* checks if that position on the board is available
*
* @param structure board
* @param x position of penguin in row
* @param y position of penguin in column
* @return true if the cordinates are inside the board and not in water, otherwise - false
*/

bool inside_board( struct Board board, int x, int y);



/**
* Checks if the given coordinates of the penguin are inside of the board
* checks if that position on the board is available
* checks if a penguin with given cordinates can move
*
* @param structure board
* @param x position of penguin in row
* @param y position of penguin in column
* @param current_player used to differentiate penguins of two players
* @param stage of the game(placement phase or movement phase)
* @return true if the coordinates are valid, otherwise - false
*/

bool validate_penguin_coordinates(struct Board board,int x, int y, int current_player, int stage);

bool check_selected_penguin( struct Board board, int x, int y);

/*
* Checks if selected penguin can move
*
* @param structure board
* @param x position of penguin in row
* @param y position of penguin in column
* @param left
* @param up
* @param right
* @param bottom
*/
bool is_movable( struct Board board, int x, int y, int left, int up, int right, int bottom);

/**
* Checks if the given coordinates of the penguin are inside of the board
* checks if that position on the board is available
* checks if a penguin with given cordinates can move to the new cordinates
*
* @param structure board
* @param structure penguin
* @param x new position of penguin in row
* @param y new position of penguin in column
* @return true if the penguin can move, otherwise - false
*/
bool validate_new_coordinates( struct Board board, int current_x, int current_y, int new_x, int new_y);


/**
* Checks if scanf function read expected data
* to avoid unexpected behavior of scanf
* 
*
* @param args - number of arguments that have been read by scanf
* @param expected_args - number of arguments that we expect
*/
void unexpected_input_handler(int args, int expected_args);




bool search_for_obstacles( struct Board board, int  coordinate,int start, int finish, char key);

#endif // INPUT_VALIDATION
