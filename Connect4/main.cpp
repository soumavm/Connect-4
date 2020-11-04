/*
 Soumav Maiti
*/
#include <iostream>
#include <cstdlib>
#include "Functions.h"
using namespace std;

int main()
{
    string Board[6][7];
    //fills game Board with blanks & Displays it
    fillBoard(Board);
    displayBoard(Board);

    while(!Win)
    {
        //Places down user inputs & displays Board
        placeInput(Board);
        displayBoard(Board);
        //checks for horizontal win
        checkHorizontal(Board);
        //checks for vertical win
        checkVertical(Board);
        //Diagonal Win
        checkDiagonal(Board);
    }

}
