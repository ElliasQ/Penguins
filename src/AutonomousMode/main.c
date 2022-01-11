#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "cmd_arguments_handler.h"
#include "reading_data.h"


void read_dimensions(FILE *dimensions, int *rows,int *columns)
{
    char name[4];
    int coordinates[2];
    for(int i = 0; i <= 1;i++)
    {
        fscanf(dimensions,"%s", name);
        coordinates[i] = atoi(name);
        /*check if atoi(name) sucessfull
         *check length
         * check number
         *
         *
         * */

    }
    *rows = coordinates[0];
    *columns = coordinates[1];
}
int main()
{
    int y = 0;
    int x = 0;
    FILE *file;
    file = fopen("..\\a.txt", "r");
    read_dimensions(file,&y,&x);
    printf("%d %d\n", x, y);
    char name[2];

    for(int i = 0; i <y;i++)
    {
        for(int j =0 ;j <x;j++)
        {
            fscanf(file,"%s", name);
            //check Length, Return and digits-only property
            char fish = name[0];
            char player = name[1];
            //if player >0, create a new player
            printf("%c%c ",fish, player);
        }
        printf("\n");
    }
    return 0;
}