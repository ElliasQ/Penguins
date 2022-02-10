#ifndef INPUT
#define INPUT

#include <stdio.h>
#include "input_validation.h"

/**
* Asks for board coordinates : x and y 
* @param x is a a pointer to width of the board
* @param y is a pointer to length of the board
*/

void ask_for_size_of_the_board(int *x, int *y);

/**
* Asks for number of penguins : n 
* @param n is a pointer to number of penguins
*/
void ask_for_number_of_penguins(int *n);

/** 
* Asks for penguin coordinates  : x and y
* @param x is a first coordinate x of a width of the board
* @param stage is the phase of the game (placement,movement)
* @return the array that stores given (x,y) coordinates
*/
int* ask_for_penguin_coordinates(int current_player, int stage);

/** 
* Asks for name of the player
* @param x is a player's name
*/
void player_name(char x);


#endif 
