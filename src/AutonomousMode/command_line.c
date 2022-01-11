//
// Created by juanm on 11/01/2022.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "command_line.h"

int num_penguins(char *argv2){
    int numPen = 0;
    char comp[] = "penguins=";

    size_t n = sizeof(argv2) / sizeof(char);
    char expr[n];
    strcpy( expr, argv2);

    const char *pe, *pc;

    int r = 0;
    for(int i = 0; i < 10 ; i++){
        pe = &expr[i];
        pc = &comp[i];

        if (r == 9){
            numPen = atoi(pe);
        }
        if (i < 9){
            if(strstr(pe, pc) != 0){
                r++;
            }else {
                printf("Error, Typo in second argument.\n");
                exit(-1);
            }
        }

    }

    return numPen;

}


void chkNameBoardFile(char *argv){
    char comp[] = "txt.";

    size_t n = sizeof(argv)/sizeof(char);
    char expr[n];
    strcpy(expr, strrev(argv));

    const char *pe, *pc;

    for(int i = 0; i < 4 ; i++){
        pe = &expr[i];
        pc = &comp[i];

        if(strstr(pe, pc) == 0){
            printf("Error: Wrong name of file.\n");
            exit(-1);
        }

    }

    strrev(argv);
}

void command_line_reader(int argc, char *argv[]) {

    struct cmd_line_par_val clpv;

    if (argc == 1) {

        printf("There are no arguments for running the program.\n");
        exit(-1);

    } else if (argc == 2) {
        printf("%s\n", argv[1]);
        if (strstr(strlwr(argv[1]), "name ") != 0) {
            /* Display Players Names */
            printf("Players Names\n"); // Here the players names should be linked.
        } else {
            printf("Error: Wrong first argument, please write again\n");
            exit(-1);
        }

    } else if (argc == 4) {

        if (strstr(strlwr(argv[1]), "phase=movement") != 0) {
            clpv.gamePhase = 1;
            chkNameBoardFile(argv[2]);
            clpv.inputBoardName = argv[2];
            chkNameBoardFile(argv[3]);
            clpv.outputBoardName = argv[3];
        } else {
            printf("Error: Wrong first argument, please write again\n");
            exit(-1);
        }

    } else if (argc == 5) {

        if (strstr(strlwr(argv[1]), "phase=placement") != 0) {
            clpv.gamePhase = 2;
            clpv.numPen = num_penguins(argv[2]);
            chkNameBoardFile(argv[3]);
            clpv.inputBoardName = argv[3];
            chkNameBoardFile(argv[4]);
            clpv.outputBoardName = argv[4];
        } else {
            printf("Error: Wrong first argument, please write again\n");
            exit(-1);
        }

    } else {
        printf("Error: Incorrect number of arguments\n");
        exit(-1);
    }

}