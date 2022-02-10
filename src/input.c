#include "input.h"



/* Asks for board dimensions : x and y */
void ask_for_size_of_the_board(int *x, int *y)
{
	
	int  columns,rows=0;
	
	printf("Type in board dimensions(x y): \n");
	
	int args = scanf("%d %d", &columns, &rows);

    unexpected_input_handler(args, 2);
    
	*x = columns;
    *y = rows;

}

/* Asks for number of penguins : n */
void ask_for_number_of_penguins(int *n)
{
	
	int number;

	printf("Type in number of penguins: ");
	
	int args = scanf("%d", &number);

    unexpected_input_handler(args, 1);
	
	*n = number;
}

/* Asks for penguin coordinates  : x and y */
int* ask_for_penguin_coordinates(int current_player, int stage)
{
	int x,y;
	static int coordinates[2];
	char *p1 = "Player 1"; /* current_player == 1 */
	char *p2 = "Player 2"; /* current_player == 0 */
	if(stage == 1)
	{
		printf("%s,Type in penguin coordinates (x y): ", (current_player==1 ? p1 : p2));
	}
	else
	{
		printf("\n%s,Type in new penguin coordinates (x y): ", (current_player==1 ? p1 : p2));
	}

	int args = scanf("%d %d",&x,&y);

    unexpected_input_handler(args, 2);
  	
	coordinates[0] = x;
	coordinates[1] = y;
	
	return coordinates;
}
	
/* Asks for name of the player */
void player_name(char x)
{
	printf("Give a name: ");
	scanf("%c", &x);
}


