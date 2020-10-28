/*
 Soumav Maiti
*/
#include <iostream>
#include <cstdlib>
#include <array>

using namespace std;
string Board[6][7];
bool Win = false;
int Placement=0, Turn = 1, count=0;

/*
string* Update_Board()
{
}
*/
int main()
{

    //fills game Board with blanks
    for(int Row=0; Row<6; Row++)
    {
        for(int Column=0; Column<7; Column++)
        {
            Board[Row][Column] = " - ";
        }
    }

    for(int Row=0; Row<6; Row++)
    {
        for(int Column=0; Column<7; Column++)
        {
            cout << Board[Row][Column];
        }
        cout<<endl;
    }

}
