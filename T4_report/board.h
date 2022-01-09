#ifndef BOARD
#define BOARD

#include "board.h"
 /**
 * Board is the structure that represents the board object.
 *
 * @param field is the data structure that represents the game board
 * @param columns is width of the game board
 * @param rows is length of the game board
 * @param isles_with_1fish is the amount of isles with one fish on the game board
 * @param penguins_number is the total amount of penguins on the game board
 */

 struct Board{

   char **field;

   int columns;

   int rows;

   int tiles_with_1fish;

   int penguins_number;


};


/**
* Creates a data structure of the board
*
* @param columns is width of the game board
* @param rows is length of the game board
* @param isles_with_1fish is the amount of isles with one fish on the game board
* @return dynamically allocated data structure that represents the game board
*/
char **generate_the_board( int columns,  int rows, int tiles_with_1fish);

/**
* Prints out the game board.The function is called by show_the_board function
*
* @param board is an object of the board structure
*/
void print_out_board(struct Board board);

/**
* Prints out the board and its components
*
* @param board is an object of the board structure
*/
void show_the_board(struct Board board);

/*
 * Generates random amount of fish from 1 - 4
 *
 * @param columns current column
 * @param rows current rows
 * @param tiles amount of tiles that must contain 1 fish (number depends on the user input)
 * @param key generating tiles with 1 fish depending on the user input
 * @param placed number of start_tiles(1 fish tiles)
 */

/**
* Places the penguin on the board
*
* @param board is an object of the board structure
* @param x is the coordinate of the floe
* @param y is the coordinate of the floe
* @param player is current player
* @param player_score is current player's score
*/
void place_penguin(struct Board board,int x,int y, char player, int *player_score);

/**
* Removes floe after the movement of a penguin
*
* @param board is an object of the board structure
* @param x is the coordinate of the floe
* @param y is the coordinate of the floe
*/
void remove_floe(struct Board board, int x, int y);

#endif // BOARD
