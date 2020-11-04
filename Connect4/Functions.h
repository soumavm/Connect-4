//
// Created by Soumav Maiti
//

#ifndef MAIN_CPP_FUNCTIONS_H
#define MAIN_CPP_FUNCTIONS_H
using namespace std;
bool Win;
int Placement=1, Turn = 1, count=0, countRight=0, countLeft=0;

void fillBoard(string Board[6][7])
{
    for(int Row=0; Row<6; Row++)
    {
        for(int Column=0; Column<7; Column++)
        {
            Board[Row][Column] = " - ";
        }
    }
}

void displayBoard(string Board[6][7])
{
    for(int Row=0; Row<6; Row++)
    {
        for(int Column=0; Column<7; Column++)
        {
            cout << Board[Row][Column];
        }
        cout<<endl;
    }
}

void placeInput(string Board[6][7])
{
    cout << "Player " << Turn << "'s Turn"<<endl << "Enter Column Placement:";
    cin>>Placement;
    Turn = Turn%2;

    for(int Row_Placed=6; Row_Placed>0; Row_Placed--)
    {
        if(Board[Row_Placed-1][Placement-1]==" - ")
        {
            if(Turn == 1)
            {
                Board[Row_Placed-1][Placement-1] = " x ";
                break;
            }
            else
            {
                Board[Row_Placed-1][Placement-1] = " o ";
                break;
            }
        }
    }
    Turn++;
}

void checkHorizontal(string Board[6][7])
{
    for(int Row_Check =5; Row_Check>-1; Row_Check--)
    {
        for(int Column=1; Column<7;Column++)
        {
            if((Board[Row_Check][Column-1]==Board[Row_Check][Column]) &&
               (Board[Row_Check][Column]!=" - "))
                count++;
            else
                count=0;
            if(count==3)
            {
                if(Board[Row_Check][Column]==" O ")
                    cout << "Player O has won with Horizontal.";
                else
                    cout << "Player X has won with Horizontal.";
                Win = true;
                break;
            }
        }
        count=0;
    }
}
void checkVertical(string Board[6][7])
{
    for(int Col_Check =6; Col_Check>-1; Col_Check--)
    {
        for(int Row=1; Row<6;Row++)
        {
            if((Board[Row-1][Col_Check]==Board[Row][Col_Check]) && (Board[Row][Col_Check]!=" - "))
                count++;
            else
                count=0;
            if(count==3)
            {
                if(Board[Row][Col_Check]==" O ") cout << "Player O has won with vertical.";
                else cout << "Player X has won with Vertical.";
                Win = true;
                break;
            }
        }
        count=0;
    }
}
void checkDiagonal(string Board[6][7])
{
    for(int Row_Dia_Check =5; Row_Dia_Check>2; Row_Dia_Check--)
    {
        for(int Col_Dia_Check=0; Col_Dia_Check<7;Col_Dia_Check++)
        {
            for(int Diagonal=1; Diagonal<4; Diagonal++)
            {
                if(Board[Row_Dia_Check][Col_Dia_Check]==Board[Row_Dia_Check-Diagonal][Col_Dia_Check+Diagonal] && (Board[Row_Dia_Check][Col_Dia_Check]!=" - "))
                    countRight++;
                else
                    countRight=0;

                if(Board[Row_Dia_Check][Col_Dia_Check]==Board[Row_Dia_Check-Diagonal][Col_Dia_Check-Diagonal] && (Board[Row_Dia_Check][Col_Dia_Check]!=" - "))
                    countLeft++;
                else
                    countLeft=0;

                if(countRight==3 || countLeft==3)
                {
                    if(Board[Row_Dia_Check][Col_Dia_Check]==" O ") cout << "Player O has won with Diagonal";
                    else cout << "Player X has won with Diagonal";
                    Win = true;
                    break;
                }

            }
            countLeft=0;
            countRight=0;
        }
    }
}
#endif //MAIN_CPP_FUNCTIONS_H
