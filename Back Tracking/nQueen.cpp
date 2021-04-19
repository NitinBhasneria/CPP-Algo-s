/*
You are given N, and for a given N x N chessboard, find a way to place N queens such that no queen can attack any other queen on the chess board. A queen can be killed when it lies in the same row, or same column, or the same diagonal of any of the other queens. You have to print all such configurations.
Input Format :
Line 1 : Integer N
Output Format :
One Line for every board configuration. 
Every line will have N*N board elements printed row wise and are separated by space
Note : Don't print anything if there isn't any valid configuration.
Constraints :
1<=N<=10
Sample Input 1:
4
Sample Output 1 :
0 1 0 0 0 0 0 1 1 0 0 0 0 0 1 0 
0 0 1 0 1 0 0 0 0 0 0 1 0 1 0 0 
*/
#include<bits/stdc++.h>
using namespace std;
int **board = new int*[11];


bool isPossible(int n, int row, int coloumn){
    for(int i=row-1;i>=0;i--){
        if(board[i][coloumn]==1)
            return false;
    }
    int i=row-1, j= coloumn-1;
    while(i>=0&&j>=0)
        if(board[i--][j--]==1)
            return false;
    i=row-1, j= coloumn+1;
    while(i>=0&&j<n)
        if(board[i--][j++]==1)
            return false;
    
    return true;
}

void backTrack(int n, int row){
    if(row==n){
        // We have reached the solution
        // Print the matrix
        // return

        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cout<<board[i][j]<<" ";
        cout<<endl;
        return;
    }

    // Place the queen to all the possible positions
    // Go to smaller problem 
    for(int i=0;i<n;i++){
        if(isPossible(n,row,i)){
            board[row][i]=1;
            backTrack(n,row+1);
            board[row][i]=0;
        }
    }

    return;
}

void placeNQueens(int n){
    for(int i=0;i<11;i++){
        board[i] = new int[11];
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            board[i][j]=0;

    backTrack(n,0);
}

int main(){

  int n; 
  cin >> n ;
  placeNQueens(n);

}