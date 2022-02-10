#include "board.h"
#include "player.h"

char** generate_the_board( int rows,  int columns)
{
    int i,j,fish_number;
    char **board;
    board = malloc(rows*sizeof(char *));

    if (board == NULL)
    {
        printf("Error: Unable to allocate memory for the board.");
        exit(1);
    }

    for (i = 0; i < rows; i++)
    {
        board[i] = malloc(columns*sizeof(char *));

        if (board[i] == NULL)
        {
            printf("Error: Unable to allocate memory for the board!");
            exit(1);
        }
    }

    srand(time(NULL));


    for(i = 0; i < rows; i++)
    {
        int position_for_1_fish = rand() % (columns+1);

        for(j = 0; j < columns; j++)
        {
                fish_number = rand()%3 + 2;
                board[i][j] = fish_number + '0';
        }

    }
    for(i = 0; i < rows;i++)
    {
        int key = rand() % columns;
        board[i][key] = '1';
    }
    return board;
}

void print_out_board( struct Board board)
{
    int i,j;

    printf("\n");

    for( i = 0; i < board.rows; i++)
    {
        if(i<10)
        {
            printf("%d |    ",i);
        }
        else
        {
            printf("%d|    ", i);
        }

        for(j = 0; j < board.columns; j++)
        {
            if(board.field[i][j] == 'A')
            {
                printf("\033[41;5;30mP1  \033[m");
                continue;
            }
            else if(board.field[i][j] == 'a')
            {
                printf("\033[42;5;30mP2  \033[m");
                continue;
            }

            if(board.field[i][j] == '.')
            {
                printf("\033[46;5;30m.   \033[m");
                continue;
            }

            printf("%c   ", board.field[i][j]);
        }
        printf("\n");
    }
}

void show_the_board( struct Board board)
{
   int i, j;

   print_out_board(board);

   for(i = 0; i < 2; i++)
   {
       if(i==0)
       {
           printf("y      ");
       }
       else
       {
           printf("    x  ");
       }
       for(j = 0; j < board.columns; j++)
       {
            if(i==0)
            {
                if(j >=10)
                {
                    printf("__  ");
                    continue;
                }
                printf("_   ");
            }
            else
            {
                if(j >=10)
                {
                    printf("%d  ",j);
                    continue;
                }
                printf("%d   ",j);
            }
        }
        printf("\n");
   }
   printf("\n\n");
}

void place_penguin( struct Board board,int x,int y, char player, int *player_score)
{
    board.field[y][x] = player;
    *player_score += 1;
}

void remove_floe( struct Board board,int x,int y)
{
    board.field[y][x] = '.';
}

bool clear_console(int *check,int clear_after,char os)
{
    if(*check == clear_after)
    {
        if(os=='w')
        {
            system("cls");
            return true;
        }
        else if(os=='l')
        {
            printf("\x1b[H\x1b[J");
            return true;
        }
        *check = 1;
    }
    else
    {
        *check = *check+1;
        return false;
    }
}


