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


    while(!Win)
    {
        //Places down user inputs
        cout << "Player " << Turn << "'s Turn"<<endl << "Enter Row Placement: ";
        cin>>Placement;
        Turn = Turn%2;

        for(int Row_Placed=6; Row_Placed>0; Row_Placed--)
        {
            if(Board[Row_Placed-1][Placement-1]==" - ")
            {
                if(Turn == 1)
                {
                    Board[Row_Placed-1][Placement-1] = " X ";
                    break;
                }
                else
                {
                    Board[Row_Placed-1][Placement-1] = " O ";
                    break;
                }
            }

        }

        Turn++;

        //Displays Board
        for(int Row=0; Row<6; Row++)
        {
            for(int Column=0; Column<7; Column++)
            {
                cout << Board[Row][Column];
            }
            cout<<endl;
        }

        //checks for horizontal win
        for(int Row_Check =5; Row_Check>-1; Row_Check--)
        {
            for(int i=1; i<7;i++)
            {
                if((Board[Row_Check][i-1]==Board[Row_Check][i]) &&
                   (Board[Row_Check][i]!=" - "))
                {
                    count++;
                }

                else
                    count=0;

                if(count==3)
                {
                    if(Board[Row_Check][i]==" O ") cout << "Player O has won.";
                    else cout << "Player X has won.";
                    Win = true;
                    break;
                }

            }
            count=0;
        }

        //checks for vertical win
        for(int Col_Check =6; Col_Check>-1; Col_Check--)
        {
            for(int j=1; j<6;j++)
            {
                if((Board[j-1][Col_Check]==Board[j][Col_Check]) &&
                   (Board[j][Col_Check]!=" - "))
                    count++;

                else
                    count=0;

                if(count==3)
                {
                    if(Board[j][Col_Check]==" O ") cout << "Player O has won.";
                    else cout << "Player X has won.";
                    Win = true;
                    break;
                }

            }
            count=0;
        }
        /*
        //Diagonal Win

        for(int Dia_Check =6; Dia_Check>-1; Dia_Check--)
        {
            for(int j=1; j<6;j++)
            {
                if((Board[j-1][Dia_Check]==Board[j][Col_Check]) && (Board[j][Col_Check]!=" - "))
                    count++;

                else
                    count=0;

                if(count==3)
                {
                    if(Board[j][Col_Check]==" O ") cout << "Player O has won.";
                    else cout << "Player X has won.";
                    Win = true;
                    break;
                }

            }
            count=0;

        }
         */
    }

}