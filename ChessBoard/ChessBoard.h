#include<iostream>
#include<string>
#include<map>
#include<sstream>
#include<vector>

const int CHESSRANK=8;
const int CHESSFILE=8;
const char startFile = 'A';
const char startRank = '1';
const char endFile = 'H';
const char endRank = '8';

class ChessPiece;

typedef std::map<std::string, ChessPiece*> board; //Board map to store ChessPiece* at board locations.

class ChessPiece
{
 public:
  ChessPiece(std::string a, std::string b); //Creates chess pieces and positions them.
  std::string name;
  std::string colour;
  virtual bool possMove(std::string start, std::string end)=0; //Tests if move is possible for subclass piece.
  board* ownedByBoard; //Pointer to board map that the chess piece belongs to.
  //Checks no piece between start square and end square:
  bool checkVerticalEmpty(std::string start, std:: string end);
  bool checkHorizontalEmpty(std::string start, std:: string end);
  bool checkDiagAscendEmpty(std::string start, std:: string end);
  bool checkDiagDescendEmpty(std::string start, std:: string end);
};

std::ostream& operator<<(std::ostream& o, const ChessPiece* cp); //Outputs piece name and colour to console.

class ChessBoard
{
public:
  ChessBoard();
  board* boardPositions; 
  void submitMove(std::string start, std::string end);
  void resetBoard(); //Clears board map and puts the chess pieces back in start locations.
  int turnCount; //Keeps track of player turn. White moves on even, black on odd.
  std::string whiteKingLocation; //Keeps track of king location to test check/checkmate.
  std::string blackKingLocation;
  bool testCheck(std::string kingLocation); //Returns true if king is in check.
  bool testMove(std::string start, std::string end); //Tests if valid move.
  bool testCheckmate(std::string kingLocation); //Returns true if king is in checkmate.

  //Pieces declared here to allow destructor access:
  ChessPiece* WP;
  ChessPiece* WK;
  ChessPiece* WKn;
  ChessPiece* WC;
  ChessPiece* WB;
  ChessPiece* WQ;
  ChessPiece* BP;
  ChessPiece* BK;
  ChessPiece* BKn;
  ChessPiece* BC;
  ChessPiece* BB;
  ChessPiece* BQ;
  board *boardPositionsPtr; //Dynamic pointer to board map.

  ~ChessBoard(); //Deletes the aforementioned dynamic variable pieces.


};

class Pawn : public ChessPiece
{
 public:
 Pawn(std::string a, std::string b) : ChessPiece(a,b) {}
  bool possMove(std::string start, std::string end);
};

class King : public ChessPiece
{
 public:
 King(std::string a, std::string b) : ChessPiece(a,b) {}
  bool possMove(std::string start, std::string end);
};

class Knight : public ChessPiece
{
 public:
 Knight(std::string a, std::string b) : ChessPiece(a,b) {}
  bool possMove(std::string start, std::string end);
};

class Castle : public ChessPiece
{
 public:
 Castle(std::string a, std::string b) : ChessPiece(a,b) {}
 bool possMove(std::string start, std::string end);
};

class Bishop : public ChessPiece
{
 public:
 Bishop(std::string a, std::string b) : ChessPiece(a,b) {}
  bool possMove(std::string start, std::string end);
};

class Queen : public ChessPiece
{
 public:
 Queen(std::string a, std::string b) : ChessPiece(a,b) {}
  bool possMove(std::string start, std::string end);
};

bool checkMove(std::string move); //Returns false if detects erroneous move input.
char rankOfMove(std::string move); //Gets the rank of a move.
char fileOfMove(std::string move); //Gets the file of a move.





