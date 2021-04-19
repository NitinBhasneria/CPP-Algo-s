/*
Maximum Sum Rectangle
Send Feedback
Given a 2D array, find the maximum sum rectangle in it. In other words find maximum sum over all rectangles in the matrix.
Input
First line contains 2 numbers n and m denoting number of rows and number of columns. Next n lines contain m space separated integers denoting elements of matrix nxm.
Output
Output a single integer, maximum sum rectangle.
Constraints
1<=n,m<=100
Sample Input
4 5
1 2 -1 -4 -20
-8 -3 4 2 1
3 8 10 1 3
-4 -1 1 7 -6
Sample Output
29
*/

#include <bits/stdc++.h>
using namespace std;

int answer(int** grid, int n, int m, int si, int sj, int** dp){
    if(si==n-1&&sj==m-1){
        return grid[si][sj];
    }
    if(si>n-1||sj>m-1){
        return 0;
    }
    int one, two, three;
    if(dp[si+1][sj]>0){
        one = dp[si+1][sj];
    }
    else {
        one = answer(grid,n,m,si+1,sj,dp);
        dp[si+1][sj] = one;
    }
    if(dp[si][sj+1]>0){
        two = dp[si][sj+1];
    }
    else {
        two = answer(grid,n,m,si,sj+1,dp);
        dp[si][sj+1] = two;
    }
    if(dp[si+1][sj+1]>0){
        three = dp[si+1][sj+1];
    }
    else {
        three = answer(grid,n,m,si+1,sj+1,dp);
        dp[si+1][sj+1] = three;
    }
    
    return grid[si][sj]+one+two-three;
}

int maxRecSum (int** grid, int n, int m){
    int** dp = new int*[n+1];
    for(int i=0;i<n+1;i++){
        dp[i] = new int[m+1];
        for(int j=0;j<m+1;j++)
            dp[i][j]=-1;
    }
    answer(grid, n, m ,0, 0, dp);
    int max = INT_MIN;
    dp[0][0]=dp[1][0]+dp[0][1]-dp[1][1]+grid[0][0];
    dp[n][m]=0;
    // for(int i=0;i<n+1;i++){
    //     for(int j=0;j<m+1;j++)
    //         cout<<dp[i][j]<<" ";
    //         cout<<endl;
    // }
    // cout<<endl;
    for(int si=0;si<n;si++){
        for(int sj=0;sj<m;sj++){
            for(int ei=si;ei<n;ei++){
                for(int ej=sj;ej<n;ej++){
                    int sum = dp[si][sj] - dp[si][ej+1] - dp[ei+1][sj] + dp[ei+1][ej+1];
                    
                    // cout<<si<<" "<<sj<<" "<<ei<<" "<<ej<<" "<<sum<<endl;
                    if(sum>max)
                        max = sum;
                }
                // cout<<endl;
            }
        }
    }
    for(int i=0;i<n;i++){
        delete[] dp[i];
    }
    delete[] dp;
    return max;
}

int main()
{
    int n,m;
    cin>>n>>m;
    int** grid = new int*[n];
    for(int i=0;i<n;i++){
        grid[i] = new int[m];
        for(int j=0;j<m;j++)
            cin>>grid[i][j];
    }
    cout<<maxRecSum(grid,n,m);
    for(int i=0;i<n;i++){
        delete[] grid[i];
    }
    delete[] grid;
    return 0;
}

// Time complexity = O(n^4) 