//
// Created by juanm on 12/12/2021.
//

#include "stdio.h"
#include "input.h"
#include "player.h"
#include "board.h"

void change_player(int *currentPlayer){

    if (*currentPlayer == 0){
        *currentPlayer = 1;
    }else if(*currentPlayer == 1){
        *currentPlayer = 0;
    }
}

void save_penguins_coordinates(struct player p, int px, int py){
    struct player* pp = &p;

    pp->pen.x = px;
    pp->pen.y = py;
}

void collect_fish(struct Board board, struct player p, int px, int py){

    struct player* ps = &p;
    char **arr = board.field;

    ps->current_score += *(*(arr+px) + py) - '0';
}

int can_any_player_move(struct Board board, int rows, int columns){

    int move = 0;
    int possibleMovements = 0;
    char **arr = board.field;

    for(int i = 0; i < rows ; i++){

        for(int j = 0; j < columns ; j++){

            if(*(*(arr+i)+j) == 'a' || *(*(arr+i)+j) == 'A'){ // Finds the penguins.

                for(int ii = 0; ii < rows ; ii++){ // Checks movements on rows.

                    move = *(*(arr+ii) + j) - '0';
                    if( move > 0 && move < 4){
                        possibleMovements++;
                    }

                }

                for(int jj = 0; jj < columns ; jj++){ // Checks movements on columns.

                    move = *(*(arr + i) + jj) - '0';
                    if( move > 0 && move < 4){
                        possibleMovements++;
                    }

                }
            }

        }
    }

    return possibleMovements;
}

void move_penguin(struct Board board,int currentPlayer, int px, int py){

    char **arr = board.field;

    if(currentPlayer == 0){
        *(*(arr+py) + px) = 'a';
    }
    if (currentPlayer == 1){
        *(*(arr+py) + px) = 'A';
    }

}

void determine_winner(struct player p1, struct player p2){

    int scoreP1 = p1.current_score;
    int scoreP2 = p1.current_score;

    printf("\nPlayer 1 score: %d", scoreP1);
    printf("\nPlayer 2 score: %d", scoreP2);

    if(scoreP1 > scoreP2){
        printf("\nPlayer 1 was the winner!!!\n");
    }else if(scoreP1 < scoreP2){
        printf("\nPlayer 2 was the winner!!!\n");
    }else{
        printf("\nIt was a draw!!\n");
    }
}
