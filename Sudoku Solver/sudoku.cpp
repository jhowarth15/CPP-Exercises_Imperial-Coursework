#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cassert>
#include "sudoku.h"

using namespace std;

/* You are pre-supplied with the functions below. Add your own 
   function definitions to the end of this file. */

/* pre-supplied function to load a Sudoku board from a file */
void load_board(const char *filename, char board[9][9]) {

  cout << "Loading Sudoku board from file '" << filename << "'... ";

  ifstream in(filename);
  if (!in)
    cout << "Failed!" << endl;
  assert(in);

  char buffer[512];

  int row = 0;
  in.getline(buffer,512);
  while (in && row < 9) {
    for (int n=0; n<9; n++) {
      assert(buffer[n] == '.' || isdigit(buffer[n]));
      board[row][n] = buffer[n];
    }
    row++;
    in.getline(buffer,512);
  }

  cout << ((row == 9) ? "Success!" : "Failed!") << endl;
  assert(row == 9);
}

/* internal helper function */
void print_frame(int row) {
  if (!(row % 3))
    cout << "  +===========+===========+===========+" << endl;
  else
    cout << "  +---+---+---+---+---+---+---+---+---+" << endl;
}

/* internal helper function */
void print_row(const char *data, int row) {
  cout << (char) ('A' + row) << " ";
  for (int i=0; i<9; i++) {
    cout << ( (i % 3) ? ':' : '|' ) << " ";
    cout << ( (data[i]=='.') ? ' ' : data[i]) << " ";
  }
  cout << "|" << endl;
}

/* pre-supplied function to display a Sudoku board */
void display_board(const char board[9][9]) {
  cout << "    ";
  for (int r=0; r<9; r++) 
    cout << (char) ('1'+r) << "   ";
  cout << endl;
  for (int r=0; r<9; r++) {
    print_frame(r);
    print_row(board[r],r);
  }
  print_frame(9);
}

/* add your functions here */


/* Question 1 - function to check if sudoku is complete.
   This function just cycles through rows and columns with 
   for loops returning false if it finds a full stop.*/

bool is_complete(char board[9][9])
{
  for (int row=0; row<9; row++)
    {
      for (int col=0; col<9; col++)
	{
	  if (board[row][col]=='.')
	    return 0;
	}
    }

  return 1;
}

/* Question 2 - binary index representing characters from 1 to 9 
is created called number_check[] with which you check whether value
occurs more than once in row/column/box.*/

bool check_row(char board[9][9], int row)
{

  int number_check[9];
  for (int n=0; n<9; n++)
    number_check[n]=0;

  for (int col=0; col<9; col++)
    {
      if (board[row][col]!='.')
	{
	  int number = board[row][col]-49; 
	  //convert char into number using ascii.

	  if (number_check[number]==1)
	    return 0;
	  else 
	    number_check[number]=1;
	}
    }
  return 1;
}

bool check_col(char board[9][9], int col)
{
  
  int number_check[9];
  for (int n=0; n<9 ;n++)
    number_check[n]=0;

  for (int row=0; row<9; row++)
    {
      if (board[row][col]!='.')
	{
	  int number = board[row][col]-49; 

	  if (number_check[number]==1)
	    return 0;
	  else 
	    number_check[number]=1;
	}
    }
  return 1;
}

bool check_box(char board[9][9], int row, int col)
{

  int number_check[9];
  for (int n=0; n<9; n++)
    number_check[n]=0;

  // row and column must be set to that at the top left of current box.

  if (row<=2)
    row = 0;
  else if (row>=3 && row<=5)
    row = 3;
  else
    row = 6;

  if (col<=2)
    col = 0;
  else if (row>=3 && row<=5)
    col = 3;
  else
    col = 6;

  for (int across=0; across<3; across++)
    {
      for (int down=0; down<3; down++)
	{
	  if (board[row+across][col+down]!='.')
	    {
	      int number = board[row+across][col+down]-49; 

	      if (number_check[number]==1)
		return 0;
	      else 
		number_check[number]=1;
	    }
	}

    }
  return 1;
}

bool make_move(char position[], char digit, char board[9][9])
{
  int r=position[0]-65;
  int c=position[1]-49;

  if (r<0 || r>8 || c<0 || c>8) //Ascii values outside grid limits.
    {
      cout << endl << "Entry is not valid. ";
      cout << "Position must lie within grid." << endl;
      return 0;
    }   
  if (!board[r][c]=='.')
    {
      cout << "Entry not valid. There is already an entry in that grid position.";
      return 0;
    }

  board[r][c] = digit;

  if (check_row(board,r) && check_col(board,c) && check_box(board,r,c)) 
    return 1;
  else
    {
      board[r][c]='.';
      cout << "Not a correct answer towards the solution, try again.";
      return 0;      
    }
}


/* Question 3 */

bool save_board(const char *filename, char board[9][9])
{
  ofstream out_stream;
  out_stream.open(filename);

  if (!out_stream)
    {
      cout << "Failed!" << endl;
      return 0;
    }

  for (int r=0; r<9; r++)
    {
      for (int c=0; c<9; c++)
	  out_stream.put(board[r][c]);
      out_stream.put('\n');
    }

  out_stream.close();

  return 1;
}

/* Question 4 */

bool solve_board(char board[9][9])
{
  
  //Move over characters that are not dots and stop when reach dot.
  int row=0, col=0;

  while (row<=8 && board[row][col]!='.')
    {
      col++;
      if (col==9)
	{
	  row++;
	  col=0;   //reset column
	}
    }

  //Base Case, where it moves through a complete board.
  if (row==9)
    return 1;

  /*Test each value in empty space with check row, col and box functions.
    Also call the solver recursively which will then test the next empty board space. 
    It returns true if it makes it through all recursions.*/

  for (char test='1'; test<='9'; test++)
    {
      board[row][col]=test;

      if (check_row(board,row) 
          && check_col(board,col)
	  && check_box(board,row,col)
	  && solve_board(board))
	return 1;
    }

  /*If it doesn't make it through, the entry is reset to '.' and 
   the function returns false so it can fall back into previous 
   function and try other values.*/

  board[row][col]='.';
  return 0;

}


/* Question 5 - adding a count input reference parameter for the total number of recursions
as some approximation of difficulty.*/

bool solve_board(char board[9][9], int& count)
{
  count++;

  //Move over characters that are not dots and stop when reach dot.
  int row=0, col=0;

  while (row<=8 && board[row][col]!='.')
    {
      col++;
      if (col==9)
	{
	  row++;
	  col=0;   //reset column
	}
    }

  //Base Case, where it moves through a complete board.
  if (row==9)
    return 1;

  //cout << "First blank at row:" << row << " column:" << col << endl;

  //Test each value in empty space with check row, col and box.
  //Also call the solver recursively which will then test the next empty board space. 
  //It returns true if it makes it through all recursions.
  for (char test='1'; test<='9'; test++)
    {
      board[row][col]=test;

      if (check_row(board,row) 
          && check_col(board,col)
	  && check_box(board,row,col)
	  && solve_board(board, count))
	return 1;
    }

  /*If it doesn't make it through, the entry is reset to '.' and 
   the function returns false so it can fall back into previous 
   function and try other values.*/

  //display_board(board);

  board[row][col]='.';
  return 0;

}
