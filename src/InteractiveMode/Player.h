//
// Created by juanm on 12/12/2021.
//

#ifndef PENGUIN_GAME_PLAYER_H
#define PENGUIN_GAME_PLAYER_H
#include "board.h"
#include "input_validation.h"
#include <stdbool.h>

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
 struct Player{
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
  void save_penguin_coordinates(struct Player* p, int px, int py);

void change_penguin_coordinates(struct Player *p, struct Penguin penguin, int x, int y);

/**
 * Adds the fish on the new isle to the score of the current player.
 *
 * @param board Pointer to board.
 * @param p Pointer to structure of the current player.
 * @param px New coordinate x of the penguin.
 * @param py New coordinate y of the penguin.
 */
void collect_fish(struct Board board, struct Player *p, int x, int y);

  /**
   * Searches if any player can make a move.
   *
   * @param board Structure to the board.
   * @param rows Number of rows of the board.
   * @param columns Number of columns of the board.
   * @return the amount of possible movements.
   */

bool can_current_player_move(struct Board board, int *current_player,struct Player p1, struct Player p2,int key) ;

   /**
    * Changes a penguin from position.
    *
    * @param board Pointer to the board.
    * @param currentPlayer Player that moved a penguin.
    * @param px New coordinate x of the penguin.
    * @param py New coordinate y of the penguin.
    */
int move_penguin(struct Board board,int currentPlayer, int px, int py);

/**
 * Determines the winner and shows scores.
 *
 * @param p1 Structure to score of player 1.
 * @param p2 Structure to score of player 2.
 */

bool check_penguins(struct Board board, struct  Player *p);

void determine_winner(struct Player p1, struct Player p2);

#endif //PENGUIN_GAME_PLAYER_H
