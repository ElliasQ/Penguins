//
// Created by juanm on 12/12/2021.
//

#ifndef PENGUIN_GAME_PLAYER_H
#define PENGUIN_GAME_PLAYER_H

#include "board.h"

/**
 * Structure that selects a penguin.
 *
 * @param x Coordinate x of a penguin.
 * @param y Coordinate y of a penguin.
 */
 struct penguin{
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
 struct player{
    int current_score;
    struct penguin pen;
    int penguin_coordinates[];
};

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
  void save_penguins_coordinates(struct player p, int px, int py);

  /**
   * Adds the fish on the new isle to the score of the current player.
   *
   * @param board Pointer to board.
   * @param p Pointer to structure of the current player.
   * @param px New coordinate x of the penguin.
   * @param py New coordinate y of the penguin.
   */
void collect_fish(struct Board board, struct player p, int px, int py);

  /**
   * Searches if any player can make a move.
   *
   * @param board Structure to the board.
   * @param rows Number of rows of the board.
   * @param columns Number of columns of the board.
   * @return the amount of possible movements.
   */
   int can_any_player_move(struct Board board,int rows, int columns); /* deleted int possibleMovements */

   /**
    * Changes a penguin from position.
    *
    * @param board Pointer to the board.
    * @param currentPlayer Player that moved a penguin.
    * @param px New coordinate x of the penguin.
    * @param py New coordinate y of the penguin.
    */
void move_penguin(struct Board board,int currentPlayer, int px, int py);

/**
 * Determines the winner and shows scores.
 *
 * @param p1 Structure to score of player 1.
 * @param p2 Structure to score of player 2.
 */
void determine_winner(struct player p1, struct player p2);

#endif //PENGUIN_GAME_PLAYER_H
