#include <iostream>
using namespace std;

int N;

// Function to print solution
void printSolution(int board[20][20])
{
    cout << "\nSolution Matrix:\n";
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
            cout<<board[i][j]<<" ";
        cout<<endl;
    }
}

// Function to check safe position
bool isSafe(int board[20][20], int row, int col)
{
    int i,j;

    // Check row on left side
    for(i=0;i<col;i++)
        if(board[row][i]==1)
            return false;

    // Check upper diagonal
    for(i=row,j=col;i>=0 && j>=0;i--,j--)
        if(board[i][j]==1)
            return false;

    // Check lower diagonal
    for(i=row,j=col;i<N && j>=0;i++,j--)
        if(board[i][j]==1)
            return false;

    return true;
}

// Backtracking function
bool solveNQueen(int board[20][20], int col)
{
    if(col>=N)
        return true;

    for(int i=0;i<N;i++)
    {
        if(isSafe(board,i,col))
        {
            board[i][col]=1;

            if(solveNQueen(board,col+1))
                return true;

            board[i][col]=0; // Backtrack
        }
    }

    return false;
}

int main()
{
    cout<<"Enter number of queens: ";
    cin>>N;

    int board[20][20]={0};

    if(!solveNQueen(board,0))
        cout<<"Solution does not exist";
    else
        printSolution(board);

    return 0;
}