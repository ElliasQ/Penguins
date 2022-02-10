#include <stdio.h>
#include <stdbool.h>
#include "board.h"
#include "input.h"
#include "input_validation.h"
#include "player.h"


int main()
{
    /* Declaring and defining variables */

    int input_count=1;
    int clear_after=2;
    char os='w'; //w for windows, l for linux


    struct Board board;
	int current_player = 1; /*Create game parameters*/

    do
    {
        ask_for_size_of_the_board(&board.columns,&board.rows);
    }while(validate_size_of_the_board(board.rows,board.columns) == false);

    do
    {
        ask_for_number_of_penguins(&board.penguins_number);
    }while(validate_number_of_penguins(board.penguins_number) == false);

    int total_penguins = board.penguins_number * 2;

    struct Player p1 = create_new_player(board.penguins_number);
    struct Player p2 = create_new_player(board.penguins_number);

    board.tiles_with_1fish = board.penguins_number * 2;
    board.field = generate_the_board(board.rows, board.columns);

    clear_console(&input_count,clear_after,os);

    printf("\n\nPlacement Phase:\n");

    show_the_board(board);

    for(int i = 0 ; i < total_penguins; i++)
    {
        int *coordinates;
        do
        {
            coordinates = ask_for_penguin_coordinates(current_player,1);
        }while(validate_penguin_coordinates(board,coordinates[0], coordinates[1], current_player, 1) == false);

        int new_x = coordinates[0];
        int new_y = coordinates[1];

        if(current_player == 1)
        {
            place_penguin(board, new_x, new_y, 'A', &p1.current_score);
            save_penguin_coordinates(&p1, new_x, new_y);
        }
        else
        {
            place_penguin(board, new_x, new_y, 'a', &p2.current_score);
            save_penguin_coordinates(&p2, new_x, new_y);
        }

        board.tiles_with_1fish--;

        change_player(&current_player);

        clear_console(&input_count,clear_after,os);

        if(board.tiles_with_1fish == 0)
        {
            printf("End of the Placement Phase\n\n");
            break;
        }

        show_the_board(board);
    }


    while(can_current_player_move(board,&current_player,p1,p2,1) !=false)
    {
        int *coordinates;

        printf("Movement Phase:\n");
        show_the_board(board);

        do
        {
            coordinates = ask_for_penguin_coordinates(current_player,1);
        }while(validate_penguin_coordinates(board,coordinates[0], coordinates[1],current_player,2) == false);

        int current_x = coordinates[0];
        int current_y = coordinates[1];

        int *new_coordinates;

        do
        {
            new_coordinates = ask_for_penguin_coordinates(current_player,2);
        }while(validate_new_coordinates(board, current_x, current_y, new_coordinates[0], new_coordinates[1]) == false);

        remove_floe(board, current_x, current_y);

        int new_x = new_coordinates[0];
        int new_y = new_coordinates[1];

        int fish_collected = collect_fish(board, new_x, new_y);
        move_penguin(board,current_player,new_x, new_y);
        if(current_player == 1)
        {
            p1.current_score += fish_collected;

            change_penguin_coordinates(&p1, current_x, current_y, new_x, new_y);
        }
        else
        {
            p2.current_score += fish_collected;

            change_penguin_coordinates(&p2, current_x, current_y, new_x, new_y);
        }
        change_player(&current_player);

        clear_console(&input_count,clear_after,os);
    }

    clear_console(&input_count,clear_after,os);
    show_the_board(board);

    determine_winner(p1,p2);

    return 0;
}
