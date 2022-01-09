#include <stdio.h>
#include <ctype.h>
#include "input_validation.h"
#include <stdbool.h>
#include "board.h"



 bool validate_size_of_the_board(int x,  int y)
{

    if ((x >= 4 && y >= 4) && (x <= 30 && y <= 30) )
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
    return true;
}



bool validate_penguin_coordinates(struct Board board, struct Player p1, struct Player p2,int x, int y,int current_player,int stage)
{
    bool result = inside_board(board, x , y);

    if(result)
    {
        if(stage == 1)
        {
            if(board.field[y][x] == 'A' || board.field[y][x] == 'a' )
            {
                printf("\nThis position is already occupied!\n\n");
                return false;
            }
            else if (board.field[y][x] != '1')
            {
                printf("\nYou can only place penguins on the floes with one fish\n\n");
                return false;
            }
        }
        else if(stage == 2)
        {
            if(board.field[y][x] == 'A')
            {
                if(current_player != 1)
                {
                    printf("\nInvalid coordinates!\n\n");
                    return false;
                }
                else if(!check_selected_penguin(board,x,y))
                {
                    printf("\nInvalid coordinates!\n\n");
                    return false;
                }
            }
            else if(board.field[y][x] == 'a')
            {
                if(current_player != 0)
                {
                    printf("\nInvalid coordinates!\n\n");
                    return false;
                }
                else if(!check_selected_penguin(board,x,y))
                {
                    printf("\nInvalid coordinates!\n\n");
                    return false;
                }
            }
            else
            {
                printf("\nInvalid coordinates!\n\n");
                return false;
            }
        }
    }
    return result;
}
bool check_selected_penguin(struct Board board, int x, int y)
{
    if (y == 0)
    {
        if (x == 0)
        {
            return IsMovable(board, x, y, 0, 0, 1, 1);
        }
        else if(x == board.columns - 1)
        {
            return IsMovable(board, x, y, 1, 0, 0, 1);
        }
        else
        {
            return IsMovable(board, x, y, 1, 0, 1, 1);
        }
    }
    else if (y == board.rows - 1)
    {
        if (x == 0)
        {
            return IsMovable(board, x, y, 0, 1, 1, 0);
        }
        else if(x == board.columns-1)
        {
            return IsMovable(board, x, y, 1, 1, 0, 0);
        }
        else
        {
            return IsMovable(board, x, y, 1, 1, 1, 0);
        }
    }
    if(x == 0)
    {
        return IsMovable(board, x, y, 0, 1, 1, 1);
    }
    else if(x == board.columns -1)
    {
        return IsMovable(board, x, y, 1, 1, 0, 1);
    }
    else
    {
        return IsMovable(board, x, y, 1, 1, 1, 1);
    }
}
bool IsMovable(struct Board board, int x, int y, int left, int up, int right, int bottom)
{
    if(left == 1)
    {
        if (isdigit(board.field[y][x-1]) != 0)
        {
            return true;
        }
    }
    if(up == 1)
    {
        if(isdigit(board.field[y-1][x]) != 0)
        {
            return true;
        }
    }
    if(right == 1)
    {
        if(isdigit(board.field[y][x+1]) != 0)
        {
            return true;
        }
    }
    if(bottom==1)
    {
        if(isdigit(board.field[y+1][x]) != 0)
        {
            return true;
        }
    }
    return false;

}

bool validate_new_coordinates(struct Board board, struct Penguin p, int x, int y)
{
    bool valid_new_tile = !(board.field[y][x] == 'A' || board.field[y][x] == 'a' || board.field[y][x] == '.');
    if(inside_board(board, x, y) && valid_new_tile)
    {
        if (p.x == x)
        {
            bool upwards = p.y < y ? true : false;
            if(upwards)
            {
                return search_for_obstacles(board, x,y-1, p.y, 'x');
            }
            else
            {
                return search_for_obstacles(board, x, p.y-1, y + 1, 'x');
            }
        }
        else if(p.y == y)
        {
            bool leftwards = p.x > x ? true : false;
            if(leftwards)
            {
                return search_for_obstacles(board, y, p.x - 1, x + 1, 'y');
            }
            else
            {
                return search_for_obstacles(board, y,x - 1, p.x + 1, 'y');
            }
        }
    }
    printf("\nInvalid Coordinates!\n");
    return false;
}

bool search_for_obstacles(struct Board board, int  coordinate,int start, int finish,char key)
{
     if(key == 'x')
     {
         while(start>finish)
         {
             if(board.field[start][coordinate] == 'A' || board.field[start][coordinate] == 'a' || board.field[start][coordinate] == '.')
             {
                 printf("\nThere's an obstacle between positions!\n");
                 return false;
             }
             start--;
         }
     }
     else if(key == 'y')
     {
         while(start>finish)
         {
             printf("VALUE OF THE TILE - %c\n", board.field[coordinate][start]);
             if(board.field[coordinate][start] == 'A' || board.field[coordinate][start] == 'a' || board.field[coordinate][start] == '.')
             {
                 printf("\nThere's an obstacle between positions!\n");
                 return false;
             }
             start--;
         }
     }
     return true;
}

void unexpected_input_handler(int args, int expected_args)
{
    if(args < expected_args)
  	{
    	fflush(stdin);
  	}
}
