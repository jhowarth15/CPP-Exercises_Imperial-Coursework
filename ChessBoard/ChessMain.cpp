#include "ChessBoard.h"

using namespace std;

int main() {

    cout << "===========================" << endl;
    cout << "Testing the Chess Engine" << endl;
    cout << "===========================" << endl;
    cout << endl;

    ChessBoard cb;

    cout << endl;
    

    //Test invalid move input.
    /*cb.submitMove("M4","D5");
    cb.submitMove("D4","D9");
    cb.submitMove("a4","D8");
    cb.submitMove("A4B","D9");

    cb.submitMove("H2","H3");
    cb.submitMove("H3","H4");
    cb.submitMove("H4","H5");*/

    //cout << cb.turnCount << " is the turn count." << endl;

    //Test knight.
    /*cb.submitMove("B1", "C3");
    cb.submitMove("C3", "E4");
    cb.submitMove("E4", "E5");
    cb.submitMove("E4", "C5");
    cb.submitMove("C5", "B7");
    */
    //Test castle.
    /*cb.submitMove("A2", "B3");
    cb.submitMove("A1", "A4");
    cb.submitMove("E2", "E4");
    cb.submitMove("A4", "H4");
    cb.submitMove("A4", "D7");
    */
    //Test Bishop
    /*cb.submitMove("D2", "D3");
    cb.submitMove("C1", "F4");
    cb.submitMove("F4", "F6");
    cb.submitMove("C7", "C6");
    cb.submitMove("F4", "B8");
    */

    //Test Queen
    /*cb.submitMove("E2", "D3");
    cb.submitMove("E1", "E5");
    cb.submitMove("G7", "G6");
    cb.submitMove("E5", "H8");
    */

    //Test King
    /*cb.submitMove("D2", "D3");
    cb.submitMove("D1", "D4");
    cb.submitMove("D1", "D2");
    cb.submitMove("D2", "F4");
    cb.submitMove("D2", "E3");
    */

    //Test Pawn
    /*cb.submitMove("D2", "D4");
    cb.submitMove("D2", "D3");
    cb.submitMove("D3", "E4");
    cb.submitMove("C7", "C6");
    cb.submitMove("C6", "C7");
    cb.submitMove("C6", "C5");
    cb.submitMove("D3", "D4");
    cb.submitMove("D4", "C5");
    */
   
    //Test check yourself
    /*cb.submitMove("E2", "E3");
    cb.submitMove("H7", "H6");
    cb.submitMove("F1", "B5");
    cb.submitMove("D7", "D6");
    */

    //Test fail to escape check
    /*cb.submitMove("E2", "E4");
    cb.submitMove("E7", "E6");
    cout << endl;

    cb.submitMove("D2", "D4");
    cb.submitMove("D7", "D5");
    cout << endl;

    cb.submitMove("B1", "C3");
    cb.submitMove("F8", "B4");
    cout << endl;

    cb.submitMove("F1", "D3");
    cb.submitMove("B4", "C3");
    cout << endl;

    cb.submitMove("H2", "H3");
    */



    
    cb.submitMove("D7", "D6");
    cout << endl;

    cb.submitMove("D4", "H6");
    cout << endl;

    cb.submitMove("D2", "D4");
    cout << endl;

    cb.submitMove("F8", "B4");
    cout << endl;
    

    
    cout << "===========================" << endl;
    cout << "Alekhine vs. Vasic (1931)" << endl;
    cout << "===========================" << endl;
    cout << endl;

    cb.resetBoard();
    cout << endl;

    cb.submitMove("E2", "E4");
    cb.submitMove("E7", "E6");
    cout << endl;

    cb.submitMove("D2", "D4");
    cb.submitMove("D7", "D5");
    cout << endl;

    cb.submitMove("B1", "C3");
    cb.submitMove("F8", "B4");
    cout << endl;

    cb.submitMove("F1", "D3");
    cb.submitMove("B4", "C3");
    cout << endl;

    cb.submitMove("B2", "C3");
    cb.submitMove("H7", "H6");
    cout << endl;

    cb.submitMove("C1", "A3");
    cb.submitMove("B8", "D7");
    cout << endl;

    cb.submitMove("D1", "E2");
    cb.submitMove("D5", "E4");
    cout << endl;

    cb.submitMove("D3", "E4");
    cb.submitMove("G8", "F6");
    cout << endl;

    cb.submitMove("E4", "D3");
    cb.submitMove("B7", "B6");
    cout << endl;

    cb.submitMove("E2", "E6");
    cb.submitMove("F7", "E6");
    cout << endl;

    cb.submitMove("D3", "G6");
    cout << endl;
    
    
    return 0;
}
