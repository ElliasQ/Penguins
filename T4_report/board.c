#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include "board.h"
#include "player.h"

char **generate_the_board( int rows,  int columns, int *tiles_with_1_fish)
{

    int i,j,fish_number;
    int fish_1_tiles = 0;
    char **board;

    board = malloc(5*rows*sizeof(char *));
    
    if (board == NULL)
    {
        exit(1);
    }

    for (i = 0; i < rows; i++)
    {
        board[i] = malloc(5*columns*sizeof(char *));
        
        if (board[i] == NULL)
        {
            exit(1);
        }
    }

    srand(time(NULL));

    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < columns; j++)
        {

           if(i == 0 || j == 0 || i == rows-1 || j == columns-1)
            {
                board[i][j] = '.';

                continue;
            }
        
            else
            {
                fish_number = rand()%4 + 1;
                
                if(fish_number == 1)
                {
                    fish_1_tiles++;
                }
            
                board[i][j] = fish_number + '0';
            }
        }
    }

    *tiles_with_1_fish = fish_1_tiles;
    return board;
}

void show_the_board( struct Board board)
{
   int i, j;
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
               printf("P1  ");
               continue;
           }
           else if(board.field[i][j] == 'a')
           {
               printf("P2  ");
               continue;
           }
           if(i == 0 || j == 0 || i == board.rows - 1 || j == board.columns - 1)
            {
                printf("%c   ", board.field[i][j]);
                continue;
            }
           if(board.field[i][j] == '.')
            {
                printf("%c   ", board.field[i][j]);
                continue;
            }

            printf("%c   ", board.field[i][j]);
       }
       printf("\n");

    }
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

void place_penguin(struct Board board,int x,int y, char player, int *player_score)
{
    board.field[y][x] = player;
    *player_score += 1;
}


void remove_floe(struct Board board,int x,int y)
{
    board.field[y][x] = '.';
}

