#ifndef PENGUIN_GAME_PLAYER_H
#define PENGUIN_GAME_PLAYER_H

#include "stdio.h"
#include <stdlib.h>
#include <stdbool.h>
#include "board.h"
#include "input_validation.h"



/**
 * Structure that selects a penguin.
 *
 * @param x Coordinate x of a penguin.
 * @param y Coordinate y of a penguin.
 */

struct Penguin{
    int x;
    int y;
};

/**
 * Structure that defines the attributes of a player.
 *
 * @param current_score Stores the amount of fish collected by the player.
 * @param pen selects a penguin of the player.
 * @param penguin_coordinates Stores the coordinates of a penguin.
 */
struct Player {
    int current_score;
    struct Penguin* penguins;
    struct Penguin* wasted_penguins; // for debugging
    int penguins_size;
    int wasted_penguins_size; // for debugging
};

struct Player create_new_player(int penguins);

/**
 * Changes the current player.
 *
 * @param currentPlayer pointer to current player.
 */
 void change_player(int *currentPlayer);


 /**
  * Stores the new coordinates for a penguin.
  *
  * @param p Pointer to the attributes to the current player.
  * @param px New coordinate x for a penguin.
  * @param py New coordinate y for a penguin.
  */
 void save_penguin_coordinates( struct Player* p, int px, int py);


/**
 * Saves the new penguin coordinates into the corresponding structure of the player.
 *
 * @param p Pointer to the structure of current player.
 * @param current_x Previous coordinate x of the penguin.
 * @param current_y Previous coordinate y of the penguin.
 * @param new_x New coordinate x of the penguin.
 * @param new_y New coordinate y of the penguin.
 */
 void change_penguin_coordinates( struct Player *p,  int current_x, int current_y, int new_x, int new_y);

/**
 * Returns the number of fish of an isle.
 *
 * @param board Pointer to board.
 * @param px New coordinate x of the penguin.
 * @param py New coordinate y of the penguin.
 * @return Number of fish on that isle.
 */
int collect_fish( struct Board board, int x, int y);

/**
 * Checks if any player can make a move.
 *
 * @param board Pointer to the structure of the board.
 * @param current_player Pointer to current player.
 * @param p1 Pointer to structure of player 1.
 * @param p2 Pointer to structure of player 2.
 * @param key number of times the functions has been called.
 * @return true if any player can make, otherwise false
 */
bool can_current_player_move(struct Board board, int *current_player, struct Player p1, struct Player p2, int key) ;

   /**
    * Changes a penguin from position.
    *
    * @param board Pointer to the board.
    * @param currentPlayer Player that moved a penguin.
    * @param px New coordinate x of the penguin.
    * @param py New coordinate y of the penguin.
    */
void move_penguin( struct Board board,int currentPlayer, int px, int py);

/**
 * Checks if a penguin of a player can move.
 *
 * @param board Pointer to the structure of the board.
 * @param p Pointer to the structure of current player.
 * @return true if a penguin of the player can move, otherwise false.
 */
bool check_penguins( struct Board board,   struct Player *p);

/**
 * Determines the winner and displays the results.
 
 * @param p1 Structure to score of player 1.
 * @param p2 Structure to score of player 2.
 */
void determine_winner( struct Player p1,  struct Player p2);

#endif //PENGUIN_GAME_PLAYER_H
