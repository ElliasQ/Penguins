#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>
#include "input_validation.h"
#include "input.h"
#include "board.h"
#include "player.h"

int main()
{
    /* Declaring and defining variables */
    
    struct Board board;
    struct player p1;
    struct player p2;
    p1.current_score = 0;
    p2.current_score = 0;
	int current_player = 1;

    /* Asking user to type in size of the board */
    
    do
    {
        ask_for_size_of_the_board(&board.columns,&board.rows);
    }while(validate_size_of_the_board(board.rows,board.columns) == false);
    
    /* Generating the board with given dimensions and printing it out */
	
    board.field = generate_the_board(board.rows, board.columns, &board.tiles_with_1fish); 

    show_the_board(board);

    /* Asking user to type in number of penguins */
    
    do
    {
        ask_for_number_of_penguins(&board.penguins_number);
    }while(validate_number_of_penguins(board.penguins_number) == false);

    /* Placement Phase */

    printf("\n\nPlacement Phase:\n\n");
    
    for(int i = 0 ; i < board.penguins_number*2; i++)
    {
        int *coordinates;
        do
        {
            coordinates = ask_for_penguin_coordinates(current_player,1);
        }while(validate_penguin_coordinates(board, coordinates[0], coordinates[1], 1, current_player) == false);

        if(current_player == 1)
        {
            place_penguin(board,coordinates[0],coordinates[1],'A', &p1.current_score);

            save_penguins_coordinates(p1,coordinates[0],coordinates[1]); 
        }
        else
        {
            place_penguin(board,coordinates[0],coordinates[1],'a', &p2.current_score);

            save_penguins_coordinates(p2,coordinates[0],coordinates[1]); 
        }

        board.tiles_with_1fish--;
        
        change_player(&current_player);
        
        if(board.tiles_with_1fish == 0)
        {
            printf("\nNo more tiles with one fish!\n\n");
            
            break;
        }
        
        show_the_board(board);      
    }

    printf("Movement Phase:\n");
    
    /* Moving Phase */

    while(can_any_player_move(board, board.columns, board.rows) !=0)
    {
        int *coordinates;
        
        show_the_board(board);  
        
        do
        {
            coordinates = ask_for_penguin_coordinates(current_player,1);
        }while(validate_penguin_coordinates(board,coordinates[0], coordinates[1],2,current_player) == false);

        
        struct penguin selected_penguin;
        selected_penguin.x = coordinates[0];
        selected_penguin.y = coordinates[1];

        int *new_coordinates;
        do
        {
            new_coordinates = ask_for_penguin_coordinates(current_player,2);

        }while(validate_new_coordinates(board,selected_penguin, new_coordinates[0], new_coordinates[1]) == false);
        
        

        remove_floe(board, selected_penguin.x, selected_penguin.y);
        
        move_penguin(board,current_player,new_coordinates[0], new_coordinates[1]);
        if(current_player == 1)
        {
            collect_fish(board, p1, new_coordinates[0], new_coordinates[1]);
        }
        else
        {
            collect_fish(board, p2, new_coordinates[0], new_coordinates[1]);
        }
        save_penguins_coordinates(p1, coordinates[0], coordinates[1]);

        change_player(&current_player);
        
    }
    

    /* Determining the winner */
    
    determine_winner(p1,p2);
    
    return 0;
}




