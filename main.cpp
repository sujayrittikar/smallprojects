#include <cstdlib>
#include <iostream>

using namespace std;

const int X=1, O =-1, EMPTY = 0;
int board[3][3];
int currentPlayer;

void clearBoard()
{
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            board[i][j] = EMPTY;
    currentPlayer = X;
}

void putMark(int i, int j)
{
    board[i][j] = currentPlayer;
    currentPlayer = -currentPlayer;
}

bool isWin(int mark)
{
    int win = 3*mark;

    return ( (board[0][0] + board[0][1] + board[0][2] == win) || (board[1][0] + board[1][1] + board[1][2]== win) ||
                (board[2][0] + board[2][1] + board[2][2]== win) ||   // Rows
                (board[0][0] + board[1][0] + board[2][0]== win) || (board[0][1] + board[1][1] + board[2][1]==win) ||
                (board[0][2] + board[1][2] + board[2][2]== win) || // Columns
                (board[0][0] + board[1][1] + board[2][2]== win) ||
                (board[0][2] + board[1][1] + board[0][1]==win));
}

int getWinner()
{
    if (isWin(X)) return X;
    else if(isWin(O)) return O;
    else return EMPTY;
}

void printBoard()
{
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            switch(board[i][j])
            {
                case X: cout<<"X"; break;
                case O: cout<<"O"; break;
                case EMPTY: cout<<" "; break;
            }

            if (j<2) cout<<"|";
        }

        if(i<2) cout<<"\n-+-+-\n";
    }
}

int isFull()
{
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            if (board[i][j]==EMPTY)
                return O;
        }
    }
    return X;
}

void playGame()
{
    clearBoard();
    int x=0, y=0;
    char player = 'X';
    for(int i=0; i<9; i++)
    {
        printBoard();
        if ((isFull()==X)||(getWinner()==X)||(getWinner()==O))
            break;
        if (currentPlayer==1)
            player = 'X';
        else
            player = 'O';
        cout<<"Player-"<<player<<"'s turn: "<<endl;
        cin>>x>>y;

        if ((x<=2&&x>=0)&&(y<=2&&y>=0))
        {
            if (board[x][y]==EMPTY)
                putMark(x, y);
            else
                {
                    if (i>0)
                        i-=1;
                    else
                        i = 0;
                    cout<<"No cheating allowed."<<endl;
                }
        }

        else
        {
            cout<<"Invalid input"<<endl;
            if (i>0)
                i-=1;
            else
                i = 0;
        }
    }
}

int main()
{
    cout<<"Welcome to Tic Tac Toe! This game starts with the player having X as the symbol. Enter your coordinates as x, y"<<endl;
    playGame();
    cout<<endl<<"The game has ended!"<<endl;
    if ((getWinner()==X)||(getWinner()==O))
    {
        if (getWinner()==X)
            cout<<"The winner for this game is player using X as symbol."<<endl;
        else
            cout<<"The winner for this game is player using O as symbol."<<endl;
    }
    else
    {
        int temp=0;
        cout<<"The board's full. Nobody wins! :)"<<endl;
        cout<<"Enter 1 if you want to play again, enter anything else to exit.";
        cin>>temp;
        if (temp==1)
            playGame();
    }
    return 0;
}
