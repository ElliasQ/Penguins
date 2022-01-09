#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "input_validation.h"
#include "input.h"
#include "board.h"
#include "Player.h"

/* To-do list:
 *
 * screen cleaning line after 2-3 inputs and one between phases
 * optimizing input_Validation.c file(refactor validate_new_coordinates())
 * unit-tests for all inputs + one separate test to check generation of cells with 1 fish
 * create a "Game" structure and store inside all other structures to keep OOP style
 * create a function that creates a player after user inputs number of penguins
 *
 * ???highlight cells with available penguins in the Movement phase???
 */

int main()
{
    /* Declaring and defining variables */
    
    struct Board board;

	int current_player = 1;

    /* Asking user to type in size of the board */
    
    do
    {
        ask_for_size_of_the_board(&board.columns,&board.rows);
    }while(validate_size_of_the_board(board.rows,board.columns) == false);

    /* Asking user to type in number of penguins */

    do
    {
        ask_for_number_of_penguins(&board.penguins_number);
    }while(validate_number_of_penguins(board.penguins_number) == false);

    int all_penguins = board.penguins_number * 2;

    struct Player p1 = create_new_player(board.penguins_number);
    struct Player p2 = create_new_player(board.penguins_number);

    /* Generating the board with given dimensions and printing it out */

    board.tiles_with_1fish = board.penguins_number * 2;
	
    board.field = generate_the_board(board.rows, board.columns, board.tiles_with_1fish);


    /* Placement Phase */

    printf("\n\nPlacement Phase:\n");

    show_the_board(board);

    for(int i = 0 ; i < board.penguins_number*2; i++)
    {
        int *coordinates;
        do
        {
            coordinates = ask_for_penguin_coordinates(current_player,1);
        }while(validate_penguin_coordinates(board, p1,p2,coordinates[0], coordinates[1], current_player, 1) == false);

        if(current_player == 1)
        {
            place_penguin(board,coordinates[0],coordinates[1],'A', &p1.current_score);

            save_penguin_coordinates(&p1, coordinates[0], coordinates[1]);
        }
        else
        {
            place_penguin(board,coordinates[0],coordinates[1],'a', &p2.current_score);

            save_penguin_coordinates(&p2, coordinates[0], coordinates[1]);
        }

        board.tiles_with_1fish--;
        
        change_player(&current_player);
        
        if(board.tiles_with_1fish == 0)
        {
            break;
        }

        show_the_board(board);
    }

     printf("Movement Phase:\n");

    /* Moving Phase */

    while(can_current_player_move(board,&current_player,p1,p2,1) !=false)
    {
        int *coordinates;

        show_the_board(board);

        do
        {
            coordinates = ask_for_penguin_coordinates(current_player,1);
        }while(validate_penguin_coordinates(board,p1,p2,coordinates[0], coordinates[1],current_player,2) == false);

        struct Penguin selected_penguin;
        selected_penguin.x = coordinates[0];
        selected_penguin.y = coordinates[1];

        int *new_coordinates;
        do
        {
            new_coordinates = ask_for_penguin_coordinates(current_player,2);

        }while(validate_new_coordinates(board,selected_penguin, new_coordinates[0], new_coordinates[1]) == false);

        remove_floe(board, selected_penguin.x, selected_penguin.y);
        
        int fish_collected = move_penguin(board,current_player,new_coordinates[0], new_coordinates[1]);
        if(current_player == 1)
        {
            p1.current_score += fish_collected;

            change_penguin_coordinates(&p1, selected_penguin, new_coordinates[0], new_coordinates[1]);
        }
        else
        {
            p2.current_score += fish_collected;

            change_penguin_coordinates(&p2, selected_penguin, new_coordinates[0], new_coordinates[1]);
        }

        change_player(&current_player);
        
    }

    show_the_board(board);

    determine_winner(p1,p2);
    
    return 0;
}




