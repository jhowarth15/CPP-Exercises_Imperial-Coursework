#include "ChessBoard.h"

using namespace std;

//ChessBoard class

ChessBoard::ChessBoard()
  {

    cout << "A new chess game is started!" << endl;
    turnCount = 0;

    //Pointer to this ChessBoard class's board to label pieces.
    boardPositionsPtr = new board;

    //Create instances of pieces.
    // White pieces.
    WP = new Pawn("Pawn","White's");
    WK = new King("King","White's");
    WKn = new Knight("Knight","White's");
    WC = new Castle("Castle","White's");
    WB = new Bishop("Bishop","White's");
    WQ = new Queen("Queen","White's");


    //Black pieces.
    BP = new Pawn("Pawn","Black's");
    BK = new King("King","Black's");
    BKn = new Knight("Knight","Black's");
    BC = new Castle("Castle","Black's");
    BB = new Bishop("Bishop","Black's");
    BQ = new Queen("Queen","Black's");



    //Initialise board positions
    char r;
    string position;

    //White pawn locations.
    string pawnName;
    r = '2';
    for (int f='A'; f<='H'; f++)
      {
	    char chFile = f;

	    stringstream sstm;
	    sstm << chFile << r;
	    position = sstm.str();

	    (*boardPositionsPtr)[position] = WP;
	    //cout << "White pawn placed at:" << endl << position << endl;
      }

    //Black pawn locations.
    r = '7';
    for (int f='A'; f<='H'; f++)
      {
	    char chFile = f;

	    stringstream sstm;
	    sstm << chFile << r;
	    position = sstm.str();

	    (*boardPositionsPtr)[position] = BP;
	    //cout << "Black pawn placed at:" << endl << position << endl;
      }

    //King locations.
    (*boardPositionsPtr)["E1"] = WK;
    (*boardPositionsPtr)["E8"] = BK;

    //Knights.
    (*boardPositionsPtr)["B1"] = WKn;
    (*boardPositionsPtr)["G1"] = WKn;
    (*boardPositionsPtr)["B8"] = BKn;
    (*boardPositionsPtr)["G8"] = BKn;

    //Castles.
    (*boardPositionsPtr)["A1"] = WC;
    (*boardPositionsPtr)["H1"] = WC;
    (*boardPositionsPtr)["A8"] = BC;
    (*boardPositionsPtr)["H8"] = BC;

    //Bishops.
    (*boardPositionsPtr)["C1"] = WB;
    (*boardPositionsPtr)["F1"] = WB;
    (*boardPositionsPtr)["C8"] = BB;
    (*boardPositionsPtr)["F8"] = BB;

    //Queens.
    (*boardPositionsPtr)["D1"] = WQ;
    (*boardPositionsPtr)["D8"] = BQ;    


    //Label the chessboard and the chesspieces with the pointer to the map.
    this->boardPositions = boardPositionsPtr;
    //cout << "Pointer: " << boardPositionsPtr << endl;
    WC->ownedByBoard = boardPositions;
    //cout << "Pointer: " << WC->ownedByBoard << endl;
    BC->ownedByBoard = boardPositions;
    WK->ownedByBoard = boardPositions;
    BK->ownedByBoard = boardPositions;
    WKn->ownedByBoard = boardPositions;
    BKn->ownedByBoard = boardPositions;
    WP->ownedByBoard = boardPositions;
    BP->ownedByBoard = boardPositions;
    WB->ownedByBoard = boardPositions;
    BB->ownedByBoard = boardPositions;
    WQ->ownedByBoard = boardPositions;
    BQ->ownedByBoard = boardPositions;

    //Mark where the kings are.
    whiteKingLocation = "E1";
    blackKingLocation = "E8";


  }


ostream& operator<<(ostream& o, const ChessPiece* cp)
{
  return o << cp->colour << " " << cp->name;
}

void ChessBoard::submitMove (string start, string end)
{
  //Check start and end lie within board.
  if (checkMove(start)==false || checkMove(end)==false)
    {
      return;
    }

  //See what piece is to be moved and targeted.
  ChessPiece* chosen;
  ChessPiece* target;

  if(boardPositions->find(start) == boardPositions->end())
    {
      cout<<"There is no piece at position " << start << "!"<<endl;
      return;
    }

  chosen = (*boardPositions)[start];

  
  //Check that the piece being moved corresponds to the person's colour.
  string mover = chosen->colour;
  if (mover=="White's" && turnCount%2==1)
    {
      cout << "It is not White's turn to move!" << endl;
      return;
    }

  if (mover=="Black's" && turnCount%2==0)
    {
      cout << "It is not Black's turn to move!" << endl;
      return;
    }
  

  //Check if there's a piece there about to be taken.
  bool combat = false;

  //Check if the player is already under check.
  int blackUnderCheck = 0;
  int whiteUnderCheck = 0;

  if(testCheck(blackKingLocation)==true)
    {
      blackUnderCheck = 1;
    }

  if(testCheck(whiteKingLocation)==true)
    {
      whiteUnderCheck = 1;
    } 

  if(boardPositions->find(end) != boardPositions->end())
    {
      target = (*boardPositions)[end];
      combat = true;
    }

  //Check target is not same colour.
    if (combat==true && target->colour==chosen->colour)
    {
      cout << "Target piece " << target << " is same colour as " << chosen << "!" << endl;
      return;
    }

  //Check that the move meets piece criteria with piece class.
      if (chosen->possMove(start, end)==false)
    {
      cout << chosen << " cannot move to " << end << "!" << endl;
      return;
    }

  //Change kingLocation string marker
      if (start==whiteKingLocation)
	{
	  whiteKingLocation=end;
	}    
      if (start==blackKingLocation)
	{
	  blackKingLocation=end;
	}


  //Move the piece.
  (*boardPositions)[end] = chosen;

  //Delete where it started.
  boardPositions->erase(start);
  
  //Output move.
  cout << chosen << " moves from " << start << " to " << end;
  //Ouput if target.
  if (combat==true)
    {
      cout << " taking " << target;
    }
  cout << endl;

  //If you don't escape check then reverse.
  if((blackUnderCheck==1 && testCheck(blackKingLocation)==true)
     ||(whiteUnderCheck==1 && testCheck(whiteKingLocation)==true))
    {
      //Move the piece back.
      (*boardPositions)[start] = chosen;

      //Delete where it ended.
      boardPositions->erase(end);

      //Put any target back.
      if (combat==true)
	{
	  (*boardPositions)[end] = target;
	}

      //Put king location back.
      if (end==whiteKingLocation)
	{
	  whiteKingLocation=start;
	}    
      if (end==blackKingLocation)
	{
	  blackKingLocation=start;
	}

      cout << "Move reversed. You did not escape check - try again." << endl;
      return;
    }

  //If you put yourself in check then reverse.
  if((testCheck(whiteKingLocation)==true && turnCount%2==0)
     || (testCheck(blackKingLocation)==true && turnCount%2==1))
    {
      //Move the piece back.
      (*boardPositions)[start] = chosen;

      //Delete where it ended.
      boardPositions->erase(end);

      //Put any target back.
      if (combat==true)
	{
	  (*boardPositions)[end] = target;
	}

      //Put king location back.
      if (end==whiteKingLocation)
	{
	  whiteKingLocation=start;
	}    
      if (end==blackKingLocation)
	{
	  blackKingLocation=start;
	}

      cout << "Move reversed. You cannot put yourself in check - try again." << endl;
      return;
    }


  //Test if king is in check.
  if(testCheck(whiteKingLocation)==true && testCheckmate(whiteKingLocation)==false)
    {
      cout << "White is in check" << endl;
    }
  if(testCheck(blackKingLocation)==true && testCheckmate(blackKingLocation)==false)
    {
      cout << "Black is in check" << endl;
    }


  //See if opponent's king is in checkmate.
  
  if(testCheck(whiteKingLocation)==true && testCheckmate(whiteKingLocation)==true)
    {
      cout << "White is in checkmate" << endl;
      return;
    }

  if(testCheck(blackKingLocation)==true && testCheckmate(blackKingLocation)==true)
    {
      cout << "Black is in checkmate" << endl;
      return;
    }

  //See if stalemate - in checkmate but not check.
  if(testCheck(whiteKingLocation)==false && testCheckmate(whiteKingLocation)==true)
    {
      cout << "White is in stalemate" << endl;
    }
  if(testCheck(blackKingLocation)==false && testCheckmate(blackKingLocation)==true)
    {
      cout << "Black is in stalemate" << endl;
    }

  turnCount++;

  return;
}

void ChessBoard::resetBoard()
{
  //Clear board.
  boardPositions->clear();

    char r;
    string position;

  //Put the pieces back in the correct places.
    string pawnName;
    r = '2';
    for (int f='A'; f<='H'; f++)
      {
	    char chFile = f;

	    stringstream sstm;
	    sstm << chFile << r;
	    position = sstm.str();

	    (*boardPositionsPtr)[position] = WP;
	    //cout << "White pawn placed at:" << endl << position << endl;
      }

    //Black pawn locations.
    r = '7';
    for (int f='A'; f<='H'; f++)
      {
	    char chFile = f;

	    stringstream sstm;
	    sstm << chFile << r;
	    position = sstm.str();

	    (*boardPositionsPtr)[position] = BP;
	    //cout << "Black pawn placed at:" << endl << position << endl;
      }

    //King locations.
    (*boardPositionsPtr)["E1"] = WK;
    (*boardPositionsPtr)["E8"] = BK;

    //Knights.
    (*boardPositionsPtr)["B1"] = WKn;
    (*boardPositionsPtr)["G1"] = WKn;
    (*boardPositionsPtr)["B8"] = BKn;
    (*boardPositionsPtr)["G8"] = BKn;

    //Castles.
    (*boardPositionsPtr)["A1"] = WC;
    (*boardPositionsPtr)["H1"] = WC;
    (*boardPositionsPtr)["A8"] = BC;
    (*boardPositionsPtr)["H8"] = BC;

    //Bishops.
    (*boardPositionsPtr)["C1"] = WB;
    (*boardPositionsPtr)["F1"] = WB;
    (*boardPositionsPtr)["C8"] = BB;
    (*boardPositionsPtr)["F8"] = BB;

    //Queens.
    (*boardPositionsPtr)["D1"] = WQ;
    (*boardPositionsPtr)["D8"] = BQ;

    //Reset turn count
    turnCount = 0;

    cout << "A new chess game is started!" << endl;

}

bool checkMove(std::string move)
{
 int length = move.length();

 if (length!=2)
   {
   cout << "Incorrect number of characters in move specification " << move << endl;
   return false;
   }

  char f = move[0]; 
  char r = move[1]; 

  if (f<'A' || f>'H')
    {
      cout << "File " << f << " does not lie within the board range A-H" << endl;
      return false;
    }

  if (r<'1' || r>'8')
    {
      cout << "Rank " << r << " does not lie within the board range 1-8" << endl;
      return false;
    }

  else return true;
}

char rankOfMove(std::string move)
{
  char r = move[1]; 
  //cout << r;
  return r;
}

char fileOfMove(std::string move)
{
  char f = move[0]; 
  //cout << f;
  return f;
}


bool ChessBoard::testCheck(std::string kingLocation)
{
  board myBoard = *boardPositions;

  //Check:
  //If there exists a testmove(x, kingLocation) by colour that just made move and fn returns true then it is check

  int startF = startFile;
  int startR = startRank;
  int endF = endFile;
  int endR = endRank;
  string tryMove;

  for (startF; startF<=endF; startF++)
    {
      startR = startRank;
      for (startR; startR<=endR; startR++)
	{
	  stringstream sstm;
	  char testR = startR;
	  char testF = startF;
	  sstm << testF << testR;
	  tryMove = sstm.str();

	  //cout << "Try to check from: " << tryMove << endl;

	  if(testMove(tryMove, kingLocation)==true)
	    {
	      return true;
	    }
	}
    }

  return false;
}

bool ChessBoard::testMove (string start, string end)
{
  //Check start and end lie within board.
  if (checkMove(start)==false || checkMove(end)==false)
    {
      return false;
    }

  //See what piece is to be moved and targeted.
  ChessPiece* chosen;
  ChessPiece* target;

  if(boardPositions->find(start) == boardPositions->end())
    {
      return false;
    }

  chosen = (*boardPositions)[start];
  
  //Check that the piece being moved corresponds to the person's colour.
  string mover = chosen->colour;

  //Check if there's a piece there about to be taken.
  bool combat = false;
  //If it's the king then disallow.

  if(boardPositions->find(end) != boardPositions->end())
    {
      target = (*boardPositions)[end];
      combat = true;
    }

  //Check target is not same colour.
    if (combat==true && target->colour==chosen->colour)
    {
      return false;
    }

  //Check that the move meets piece criteria with piece class.
      if (chosen->possMove(start, end)==false)
    {
      return false;
    }
  
  //Output move.
  //cout << chosen << " could check from " << start << " to " << end;
  //Ouput if target.
  /*if (combat==true)
    {
      cout << " taking " << target;
    }
    cout << endl;*/


  return true;
}


bool ChessBoard::testCheckmate(std::string kingLocation)
{

  //Checkmate:
  //If there does not exist any testmove() by next colour that removes them from check and also returns true
  board myBoard = *boardPositions;
  ChessPiece *king = myBoard[kingLocation];

  string colour = king->colour;

  int startF;
  int startR;
  string tryMove;

  int startF2;
  int startR2;
  string endMove;

  int escapeCheck = 0;

  ChessPiece *mover;
  ChessPiece *target;
  int targetPresent = 0;

  //Cycle through all board squares as both potential start and end move squares.
  for (startF2 = startFile; startF2<=endFile; startF2++)
    {
      for (startR2 = startRank; startR2<=endRank; startR2++)
	{
	  stringstream sstm2;
	  char testR2 = startR2;
	  char testF2 = startF2;
	  sstm2 << testF2 << testR2;
	  endMove = sstm2.str();
  
	  for (startF = startFile; startF<=endFile; startF++)
	    {
	      for (startR = startRank; startR<=endRank; startR++)
		{
		  stringstream sstm;
		  char testR = startR;
		  char testF = startF;
		  sstm << testF << testR;
		  tryMove = sstm.str();
		  
		  //cout << tryMove << endMove << endl;

		  //Check if the test move is valid.
		  if(testMove(tryMove, endMove)==true)
		    {
  		      mover = (*boardPositions)[tryMove];		  

		      //It is the defendant's piece
		      if(colour==mover->colour)
			{

			  //If its the king then move kinglocation.
			  if (mover->name=="King")
			    {
			      kingLocation = endMove;
			    }

			  //If target piece is taken store it.
			  if (boardPositions->find(endMove) != boardPositions->end())
			    {		      
			      target = (*boardPositions)[endMove];
			      targetPresent = 1;
			    }

			  //Move the mover piece temporarily.
			  (*boardPositions)[endMove] = mover;

			  //Delete where it started.
			  boardPositions->erase(tryMove);

			  //Test if the king is in check.
			  if(testCheck(kingLocation)==false)
			    {
			      escapeCheck = 1;
			    }

			  //Once done putback mover to start position.
			  (*boardPositions)[tryMove] = mover;

			  //Delete where it ended.
			  boardPositions->erase(endMove);

			  //Put back any piece taken.
			  if (targetPresent==1)
			    {		      
			      (*boardPositions)[endMove] = target;
			      target=0;
			    }

			  //If it was the king put back its location
			  if (mover->name=="King")
			    {
			      kingLocation = tryMove;
			    }

			  //If the king escaped check then return false.
			  if(escapeCheck==1)
			    {
			      return false;
			    }


			}


		    }
		
		}
	    }
	}
    }
  
  return true;

}


ChessBoard::~ChessBoard()
{
    //Delete dynamic variables.
    delete WP;
    delete WK;
    delete WKn;
    delete WC;
    delete WB;
    delete WQ;

    delete BP;
    delete BK;
    delete BKn;
    delete BC;
    delete BB;
    delete BQ;

    delete boardPositionsPtr;
}

