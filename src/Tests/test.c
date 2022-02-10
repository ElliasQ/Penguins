#include "unity.h"
#include <ctype.h>
#include "input_validation.h"
#include <stdbool.h>
#include "board.h"
#include "player.h"




void test_AskForBoardSize(void)
{
TEST_ASSERT(true, validate_size_of_the_board(6, 6));
TEST_ASSERT(false, validate_size_of_the_board(1, 1));
TEST_ASSERT(true, validate_size_of_the_board(7, 8));
TEST_ASSERT(false, validate_size_of_the_board(2, 3));
}

void test_AskForNumberOfpenguins(void)
{
TEST_ASSERT(true, validate_number_of_penguins(4));
TEST_ASSERT(false, validate_number_of_penguins(0));
TEST_ASSERT(true, validate_number_of_penguins(2));
TEST_ASSERT(false, validate_number_of_penguins(7));
}

void test_InsideBoard(void)
{
TEST_ASSERT(true, inside_board(board,0,0));
TEST_ASSERT(false, inside_board(board,9,9));
TEST_ASSERT(true, inside_board(board,1,1));
TEST_ASSERT(false, inside_board(board,11,2));
}

void test_AskForPenguinCoordinates(void)
{
TEST_ASSERT(false, validate_penguin_coordinates(board, p1,p2,22, 22, 1, 1));
TEST_ASSERT(false, validate_penguin_coordinates(board, p1,p2,1, 0, 0, 1));
TEST_ASSERT(false, validate_penguin_coordinates(board, p1,p2,1, 3, 1, 2));
}

void test_IsMovable(void)
{
TEST_ASSERT(false, IsMovable(board, 0, 0, 1, 0, 0, 0));
TEST_ASSERT(true, IsMovable(board, 0, 2, 0, 0, 1, 0));
TEST_ASSERT(false, IsMovable(board, 0, 0, 0, 1, 0, 0));
}

void test_CheckSelectedPenguin(void)
{
TEST_ASSERT(false, check_selected_penguin(board, 0,0));
TEST_ASSERT(false, check_selected_penguin(board, 2, 0));
}

void test_NewCoordinates(void)
{
TEST_ASSERT(true, validate_new_coordinates(board, p1,1,2));
TEST_ASSERT(false, validate_new_coordinates(board, p2,2,2));
}

void test_SearchForObstacles(void)
{
TEST_ASSERT(false, search_for_obstacles(board, 1,0,3,'x'));
TEST_ASSERT(false, search_for_obstacles(board, 2,1,3,'y'));
}


int main(void)
{
	//example array
	struct Board board;
	board.columns=3;
	board.rows =3;
	board.tiles_with_1fish=3;
    board.penguins_number=2;
    board.field[3][3] = { 
						{1, A, 3},
    					{., 1, a},
   						{3, 2, 3}
						};
						
	struct Penguin p1;
	p1.x = 1;
	p1.y = 0;
	struct Penguin p2;
	p2.x =2;
	p2.y = 1;
 		
UNITY_BEGIN();
RUN_TEST(test_AskForBoardSize);
RUN_TEST(test_AskForNumberOfpenguins);
RUN_TEST(test_InsideBoard);
RUN_TEST(test_AskForPenguinCoordinates);
RUN_TEST(test_IsMovable);
RUN_TEST(test_CheckSelectedPenguin);
RUN_TEST(test_NewCoordinates);
RUN_TEST(test_SearchForObstacles);
return UNITY_END();
}
