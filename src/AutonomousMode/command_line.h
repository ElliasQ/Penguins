//
// Created by juanm on 11/01/2022.
//

#ifndef COMMAND_LINE_H
#define COMMAND_LINE_H

#include "command_line.h"


/**
 * cmd_line_par_val is the structure that stores the values given by command line parameters.
 *
 * @param gamePhase Stores the game phase specified as integer.
 * @param numPen Stores the number of penguins specified.
 * @param inputBoardName Pointer to the specified name of input board.
 * @param outputBoardName Pointer to the specified name of output board.
 */
struct cmd_line_par_val{
    int gamePhase;
    int numPen;
    char *inputBoardName;
    char *outputBoardName;
};

/**
 * Reads the number of penguins given by command line argument.
 *
 * @param argv2 Pointer to command line argument that specifies the number of penguins.
 * @return Number of penguins.
 */
int num_penguins(char *argv2);

/**
 * Checks the names of the files given by command line argument.
 *
 * @param argv Pointer to the given name of the file.
 */
void chkNameBoardFile(char *argv);

/**
 * Reads the command lime arguments and stores the values given in cmd_line_par_val.
 *
 * @param argc Number of arguments given by command line parameters.
 * @param argv Array of command line arguments.
 */
void command_line_reader(int argc, char *argv[]);

#endif //COMMAND_LINE_H
