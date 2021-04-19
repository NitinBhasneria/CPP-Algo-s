#include<bits/stdc++.h>
using namespace std;

int dumy[12][12];

void backTrack(int maze[][20], int n, int row, int col){
    if(row==n-1&&col==n-1){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                cout<<dumy[i][j]<<" ";
            // cout<<endl;    
        }
        // cout<<endl;
        cout<<"\n";
    }else if(row==-1||col==-1||col==n||row==n||dumy[row][col]==1||maze[row][col]==0){
        return;
    }
    dumy[row][col]=1;
    backTrack(maze,n,row+1,col);
    backTrack(maze,n,row,col+1);
    backTrack(maze,n,row-1,col);
    backTrack(maze,n,row,col-1);
    dumy[row][col]=0;
}

void ratInAMaze(int maze[][20], int n){

  /* Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Print output as specified in the question
  */
	memset(dumy,0,12*12*sizeof(int));
	backTrack(maze,n,0,0);
}

int main(){

  int n; 
  cin >> n ;
  int maze[20][20];
  for(int i = 0; i < n ;i++){
	for(int j = 0; j < n; j++){
        	cin >> maze[i][j];
        }		
  }
  ratInAMaze(maze, n);
}