#include<iostream>
using namespace std;

char board[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char token='x';
bool isTie=false;
string player1,player2;

void printboard();
void reset();
void move();
bool winner();
int emptyspace();

int main()
{   
    cout<<" !XOX! Welcome to Tic Tac Toe game !XOX!"<<endl;
    cout<<"Enter the player1[x]: ";
    cin>>player1;
    cout<<"Enter the player2[O]: ";
    cin>>player2;
    string ch;
    
    while(ch!="no")
    {
        reset();
        while(!winner() && emptyspace()!=0)
        {  
            isTie=false;
            printboard();
            move();
        }
        
        if(emptyspace()==0)
        {
            isTie=true;
        }

        if(token=='x' && isTie==false)
        { 
            printboard();
            cout<<player2<<" wins"<<endl;
        }
        else if(token=='O' && isTie==false)
        {
            printboard();
            cout<<player1<<" wins"<<endl;
        }
        else 
        {
            printboard();
            cout<<"It's a draw"<<endl;
        }
        cout<<"Do you want to play again?[yes/no]: ";
        cin>>ch;
    }
    return 0;
} 

void printboard()
{  
    cout<<"  "<<board[0][0]<<" |  "<<board[0][1]<<"  | "<<board[0][2]<<endl;
    cout<<" ___|_____|___"<<endl;
    cout<<"  "<<board[1][0]<<" |  "<<board[1][1]<<"  | "<<board[1][2]<<endl;
    cout<<" ___|_____|___"<<endl;
    cout<<"  "<<board[2][0]<<" |  "<<board[2][1]<<"  | "<<board[2][2]<<endl;
    cout<<"    |     |  "<<endl;
}

void reset()
{
    token='x';
    isTie=false;
    board[0][0]='1';
    board[0][1]='2';
    board[0][2]='3';
    board[1][0]='4';
    board[1][1]='5';
    board[1][2]='6';
    board[2][0]='7';
    board[2][1]='8';
    board[2][2]='9';
}

void move()
{
    int position,row,column;
   
    if(token=='x')
    {
        cout<<player1<<" , enter the position[1-9]: ";
        cin>>position;
    }
    else
    {
         cout<<player2<<" , enter the position[1-9]: ";
         cin>>position;
    }

    if(position < 1 || position > 9)
    {
        cout << "Invalid position. Please enter a number between 1 and 9." << endl;
        move();
        return;
    }

    row = (position - 1) / 3;
    column = (position - 1) % 3;

    if(board[row][column]!='x' && board[row][column]!='O')
    {
        if(token=='x')
        {
            board[row][column]='x';
            token='O';
        }
        else
        {
            board[row][column]='O';
            token='x';
        }
    }
    else
    {
        cout<<"Invalid position"<<endl;
        move();
    }
}

bool winner()
{  
    for(int i=0;i<3;i++)
    {
        if(board[i][0]==board[i][1] && board[i][0]==board[i][2])
        {
            return true;
        }
    }
    for(int j=0;j<3;j++)
    {
        if(board[0][j]==board[1][j] && board[0][j]==board[2][j])
        {
            return true;
        }
    }
    
    if((board[0][0]==board[1][1] && board[0][0]==board[2][2]) || (board[0][2]==board[1][1] && board[0][2]==board[2][0]))
    {
        return true;
    }
    
    return false;
}

int emptyspace()
{
    int count = 0;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(board[i][j]!='x' && board[i][j]!='O')
            {
                count++;
            }
        }
    }
    
    return count;
}
