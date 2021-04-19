#include<bits/stdc++.h>
using namespace std;
#define N 9

 bool isNumPossible(int sud[N][N], int row, int col, int num){
    // row check 
    for(int i=0;i<9;i++){
        if(sud[i][col]==num)
            return false;
    }
    for(int i=0;i<9;i++){
        if(sud[row][i]==num)
            return false;
    }
    int startRow = row/3;
    int startCol = col/3;
    startRow = startRow*3;
    startCol =startCol*3;
    for(int i=startRow;i<startRow+3;i++)
        for(int j=startCol;j<startCol+3;j++)
            if(sud[i][j]==num)
                return false;
    return true;
}

bool ifEmpty(int grid[N][N], int &row, int &col){
	for(row=0;row<N;row++)
		for(col=0;col<N;col++)
			if(grid[row][col]==0)
				return true;

	return false;
}
bool solve(int grid[N][N]){
//	printGrid(grid);
	int row, col, num;
	if(!ifEmpty(grid, row, col))
	 return true;

	for(num=1;num<=9;num++)
	{
		if(isNumPossible(grid,row,col,num)){
		grid[row][col]=num; // tentative assignment
		if(solve(grid)) return true; // successful
		grid[row][col]=0;
	}
	}
	return false; // This triggers back tracking
}
int main(){
    int grid[9][9];
	for(int row=0; row<9; row++){
		for(int col=0; col<9; col++ ){
			cin>>grid[row][col];
		}
	}
    solve(grid);
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++)
            cout<<grid[i][j]<<" ";
        cout<<"\n";
    }
}