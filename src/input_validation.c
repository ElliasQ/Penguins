#include "input_validation.h"


int input_count=1;
int clear_after=3;
char os='w'; //w for windows, l for linux

bool validate_size_of_the_board(int x,  int y)
{

    if ((x >= 4 && y >= 4) && (x <= 30 && y <= 30) )
    {

        return true;
    }
    else
    {
        clear_console(&input_count, clear_after, os);
        printf("The coordinates are invalid:\n"
               "Both coordinates must be greater than 4 and no greater than 30! \n\n");
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
        clear_console(&input_count, clear_after, os);
        printf("\nThe number of penguins is invalid:\n"
               "The number must be at least 1 and no greater than 5\n\n");
    }
    return false;
}



bool inside_board( struct Board board, int x, int y)
{
    if (x < 0 || y < 0 || y >= board.rows || x >= board.columns)
    {
        if(clear_console(&input_count, clear_after, os) == true)
        {
            show_the_board(board);
        }
        printf("There's no floe with the given coordinates\n");
        return false;
    }
    return true;
}



bool validate_penguin_coordinates(struct Board board, int x, int y, int current_player, int stage)
{
        bool result = inside_board(board, x , y);

    if(result)
    {
        if(stage == 1)
        {
            if(board.field[y][x] == 'A' || board.field[y][x] == 'a' )
            {
                if(clear_console(&input_count, clear_after, os) == true)
                {
                    show_the_board(board);
                }
                printf("\nThis position is already occupied!\n\n");
                return false;
            }
            else if (board.field[y][x] != '1')
            {
                if(clear_console(&input_count, clear_after, os) == true)
                {
                    show_the_board(board);
                }
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
                    if(clear_console(&input_count, clear_after, os) == true)
                    {
                        show_the_board(board);
                    }
                    printf("\nInvalid coordinates!\n\n");
                    return false;
                }
                else if(!check_selected_penguin(board,x,y))
                {
                    if(clear_console(&input_count, clear_after, os) == true)
                    {
                        show_the_board(board);
                    }
                    printf("\nInvalid coordinates!\n\n");
                    return false;
                }
            }
            else if(board.field[y][x] == 'a')
            {
                if(current_player != 0)
                {
                    if(clear_console(&input_count, clear_after, os) == true)
                    {
                        show_the_board(board);
                    }
                    printf("\nInvalid coordinates!\n\n");
                    return false;
                }
                else if(!check_selected_penguin(board,x,y))
                {
                    if(clear_console(&input_count, clear_after, os) == true)
                    {
                        show_the_board(board);
                    }
                    printf("\nInvalid coordinates!\n\n");
                    return false;
                }
            }
            else
            {
                if(clear_console(&input_count, clear_after, os) == true)
                {
                    show_the_board(board);
                }
                printf("\nInvalid coordinates!\n\n");
                return false;
            }
        }
    }

    if(stage == 2){
        printf("\nThe penguin has been selected!\n");
    }

    return result;
}
bool check_selected_penguin( struct Board board, int x, int y)
{
    if (y == 0)
    {
        if (x == 0)
        {
            return is_movable(board, x, y, 0, 0, 1, 1);
        }
        else if(x == board.columns - 1)
        {
            return is_movable(board, x, y, 1, 0, 0, 1);
        }
        else
        {
            return is_movable(board, x, y, 1, 0, 1, 1);
        }
    }
    else if (y == board.rows - 1)
    {
        if (x == 0)
        {
            return is_movable(board, x, y, 0, 1, 1, 0);
        }
        else if(x == board.columns-1)
        {
            return is_movable(board, x, y, 1, 1, 0, 0);
        }
        else
        {
            return is_movable(board, x, y, 1, 1, 1, 0);
        }
    }
    if(x == 0)
    {
        return is_movable(board, x, y, 0, 1, 1, 1);
    }
    else if(x == board.columns -1)
    {
        return is_movable(board, x, y, 1, 1, 0, 1);
    }
    else
    {
        return is_movable(board, x, y, 1, 1, 1, 1);
    }
}
bool is_movable( struct Board board, int x, int y, int left, int up, int right, int bottom)
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

bool validate_new_coordinates( struct Board board, int current_x, int current_y, int new_x, int new_y)
{
    bool valid_new_tile = !(board.field[new_y][new_x] == 'A' || board.field[new_y][new_x] == 'a' || board.field[new_y][new_x] == '.');
    if(inside_board(board, new_x, new_y) && valid_new_tile)
    {
        if (current_x == new_x)
        {

            bool upwards = current_y < new_y ? true : false;
            if(upwards)
            {
                return search_for_obstacles(board, new_x, new_y - 1, current_y, 'y');
            }
            else
            {
                return search_for_obstacles(board, new_x, current_y - 1, new_y, 'y');
            }
        }
        else if(current_y == new_y)
        {
            bool leftwards = current_x > new_x ? true : false;
            if(leftwards)
            {
                return search_for_obstacles(board, new_y, current_x - 1, new_x, 'x');
            }
            else
            {
                return search_for_obstacles(board, new_y, new_x - 1, current_x, 'x');
            }
        }
    }

    if(clear_console(&input_count, clear_after, os) == true)
    {
        show_the_board(board);
    }

    printf("\nInvalid Coordinates!\n");
    return false;
}

bool search_for_obstacles( struct Board board, int  coordinate, int start, int finish, char key)
{
    if(key == 'x')
    {
        int y = coordinate;
        
        while(start>finish)
        {
            if(board.field[y][start] == 'A' || board.field[y][start] == 'a' || board.field[y][start] == '.')
            {
                if(clear_console(&input_count, clear_after, os) == true){
                    show_the_board(board);
                }
                 printf("\nThere's an obstacle between positions!\n");
                 return false;
            }
            start--;
        }
    }
    else if(key == 'y')
    {
        int x = coordinate;
        
        while(start>finish)
        {

            if(board.field[start][x] == 'A' || board.field[start][x] == 'a' || board.field[start][x] == '.')
            {
                if(clear_console(&input_count, clear_after, os) == true)
                {
                    show_the_board(board);
                }
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
