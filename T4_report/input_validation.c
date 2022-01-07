#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "input_validation.h"



 bool validate_size_of_the_board(int x,  int y)
{

    if ((x >= 6 && y >= 6) && (x <= 23 && y <= 23) )
    {

        return true;
    }
    else
    {
        printf("The coordinates are invalid:\n"
               "Both coordinates must be greater than 6 and no greater than 23! \n\n");
    }
    return false;
}



bool validate_number_of_penguins(int penguins_number)
{
    /*
        Handles unexpected input and
        checks if the number of penguins is OK
    */
    if(penguins_number >= 1 && penguins_number <= 5)
    {
        return true;
    }
    else
    {
        printf("\nThe number of penguins is invalid:\n"
               "The number must be at least 1 and no greater than 5\n\n");
    }
    return false;
}



bool inside_board(struct Board board, int x, int y)
{
    if (x < 0 || y < 0 || x >= board.rows || y >= board.columns)
    {
        printf("There's no floe with the given coordinates\n");
        return false;
    }
    else if(x == 0 || y == 0 || x == board.rows-1 || y == board.columns - 1)
    {
        printf("\nInvalid coordinates! \n\n");
        return false;
    }
    return true;
}



bool validate_penguin_coordinates(struct Board board, int x, int y, int stage, int current_player)
{
    bool result = inside_board(board, x , y);
    //check position

    if(result==false)
    {
        return result;
    }
    else
    {
        if(stage==1)
        {
            if(board.field[y][x] == 'A' || board.field[y][x] == 'a' )
            {
                printf("\nThis position is already occupied!\n\n");
                result = false;
            }
            else if (board.field[y][x] != '1')
            {
                printf("\nYou can only place penguins on the floes with one fish\n\n");
                result = false;
            }
        }
        else if(stage==2)
        {
           
            if(board.field[y][x] == 'A')
            {
                if(current_player == 1)
                {
                    result = true;
                }
                else
                {
                    printf("\nInvalid coordinates!\n\n");

                    result = false;
                }
            }
            else if(board.field[y][x] == 'a')
            {
                if(current_player == 0)
                {
                    result = true;
                }
                else
                {
                    printf("\nInvalid coordinates!\n\n");
                    
                    result = false;
                }
            }
            else
            {
                printf("\nInvalid coordinates!\n\n");
                result = false;
            }
            if(isdigit(board.field[y-1][x]) == 0 && isdigit(board.field[y+1][x]) == 0 && isdigit(board.field[y][x-1]) == 0 && isdigit(board.field[y][x+1]) == 0)
            {
                printf("\n This penguin can't move\n\n");
                result = false;
            }
        }
    }
    
    return result;
}



bool validate_new_coordinates(struct Board board, struct penguin penguin, int x, int y)
{
    bool result = inside_board(board, x, y);
    //check position

    if(result==false)
    {
        return result;
    }
    else
    {
        if(board.field[y][x] == 'A' || board.field[y][x] == 'a' || board.field[y][x] == '.' )
        {
            printf("\nThis position is invalid!\n");
            result = false;
        }
        else if(y==penguin.y)
        {
            for(int i=1;i<=abs(penguin.x-x);i++)
            {
                if(board.field[y][penguin.x+i]=='A' || board.field[y][penguin.x+i]=='a' || board.field[y][penguin.x+i]=='.')
                {
                     printf("\nThere are obstacles between these positions!\n");
                     result = false;
                }
            }
        }
        else if(x==penguin.x)
        {
            for(int i=1;i<=abs(penguin.y-y);i++)
            {
                if(board.field[penguin.y+i][x]=='A' || board.field[penguin.y+i][x]=='a' || board.field[penguin.y+i][x]=='.')
                {
                     printf("\nThere are obstacles between these positions!\n");
                     result = false;
                }
            }
        }
        return result;
    }
}

void scanf_check(int args,int expected_args)
{
    if(args < expected_args)
  	{
    	fflush(stdin);
  	}
}
