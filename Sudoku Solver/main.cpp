#include <iostream>
#include <cstdio>
#include "sudoku.h"

using namespace std;

int main() {

  char board[9][9];

  /* This section illustrates the use of the pre-supplied helper functions. */
  cout << "============== Pre-supplied functions ==================" << endl << endl;

  cout << "Calling load_board():" << endl;
  load_board("easy.dat", board);

  cout << endl << "Displaying Sudoku board with display_board():" << endl;
  display_board(board);
  cout << "Done!" << endl << endl;

  cout << "====================== Question 1 ======================" << endl << endl;
  
  load_board("easy.dat", board);
  cout << "Board is ";
  if (!is_complete(board))
    cout << "NOT ";
  cout << "complete." << endl << endl;

  load_board("easy-solution.dat", board);
  cout << "Board is ";
  if (!is_complete(board))
    cout << "NOT ";
  cout << "complete." << endl << endl;
  
  cout << "====================== Question 2 ======================" << endl << endl;
 
  load_board("easy.dat", board);

  
  // Should be OK

  cout << "Row 1 is ";
  if (!check_row(board, 1))
    cout << "NOT ";
  cout << "valid." << endl << endl;

  cout << "Putting '1' into I8 is ";

  if (!make_move("I8", '1', board)) 
    cout << "NOT ";
  cout << "a valid move. The board is:" << endl;
  display_board(board);

  cout << "Putting '1' into F8 is ";

  if (!make_move("F8", '1', board)) 
    cout << "NOT ";
  cout << "a valid move. The board is:" << endl;
  display_board(board);

  cout << "Putting '4' into E3  is ";

  if (!make_move("E3", '4', board)) 
    cout << "NOT ";
  cout << "a valid move. The board is:" << endl;
  display_board(board);

  cout << "Putting '4' into H1  is ";

  if (!make_move("H1", '4', board)) 
    cout << "NOT ";
  cout << "a valid move. The board is:" << endl;
  display_board(board);

  cout << "Putting '2' into A2  is ";

  if (!make_move("A2", '2', board)) 
    cout << "NOT ";
  cout << "a valid move. The board is:" << endl;
  display_board(board);

  cout << "Putting '3' into B8  is ";

  if (!make_move("B8", '3', board)) 
    cout << "NOT ";
  cout << "a valid move. The board is:" << endl;
  display_board(board);

	// write more tests

  cout << "====================== Question 3 ======================" << endl << endl;
  
  load_board("easy.dat", board);
  if (save_board("easy-copy.dat", board))
    cout << "Save board to 'easy-copy.dat' successful." << endl;
  else
    cout << "Save board failed." << endl;
  cout << endl;

  cout << "====================== Question 4 ======================" << endl << endl;
  
  load_board("easy.dat", board);
  if (solve_board(board)) {
    cout << "The 'easy' board has a solution:" << endl;
    display_board(board);
  } else 
    cout << "A solution cannot be found." << endl;
    cout << endl;

  load_board("medium.dat", board);
  if (solve_board(board)) {
    cout << "The 'medium' board has a solution:" << endl;
    display_board(board);
  } else 
    cout << "A solution cannot be found." << endl;
    cout << endl;


	// write more tests

  cout << "====================== Question 5 ======================" << endl << endl;
  
	// write more tests
  
  int count_1 = 0;
  load_board("mystery1.dat", board);
  if (solve_board(board, count_1)) {
    cout << "The 'mystery 1' board has a solution:" << endl;
    display_board(board);
    cout << "Number of recursions: " << count_1;
  } else 
    cout << "A solution cannot be found." << endl;
    cout << endl;
    
  int count_2 = 0;
  load_board("mystery2.dat", board);
  if (solve_board(board, count_2)) {
    cout << "The 'mystery 2' board has a solution:" << endl;
    display_board(board);
    cout << "Number of recursions: " << count_2;
  } else 
    cout << "A solution cannot be found." << endl;
    cout << endl;
  
  int count_3 = 0;
  load_board("mystery3.dat", board);
  if (solve_board(board, count_3)) {
    cout << "The 'mystery 3' board has a solution:" << endl;
    display_board(board);
    cout << "Number of recursions: " << count_3;
  } else 
    cout << "A solution cannot be found." << endl;
    cout << endl;

    int count_4 = 0;
  load_board("easy.dat", board);
  if (solve_board(board, count_4)) {
    cout << "The 'easy' board has a solution:" << endl;
    display_board(board);
    cout << "Number of recursions: " << count_4;
  } else 
    cout << "A solution cannot be found." << endl;
    cout << endl;

    int count_5 = 0;
  load_board("medium.dat", board);
  if (solve_board(board, count_5)) {
    cout << "The 'medium' board has a solution:" << endl;
    display_board(board);
    cout << "Number of recursions: " << count_5;
  } else 
    cout << "A solution cannot be found." << endl;
    cout << endl;
   
  return 0;
}
