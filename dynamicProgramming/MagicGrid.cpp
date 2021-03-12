/*
Magic Grid Problem
Send Feedback
You are given a magic grid A with R rows and C columns. In the cells of the grid, you will either get magic juice, which increases your strength by |A[i][j]| points, or poison, which takes away |A[i][j]| strength points. If at any point of the journey, the strength points become less than or equal to zero, then you will die.
You have to start from the top-left corner cell (1,1) and reach at the bottom-right corner cell (R,C). From a cell (i,j), you can only move either one cell down or right i.e., to cell (i+1,j) or cell (i,j+1) and you can not move outside the magic grid. You have to find the minimum number of strength points with which you will be able to reach the destination cell.
Input format:
The first line contains the number of test cases T. T cases follow. Each test case consists of R C in the first line followed by the description of the grid in R lines, each containing C integers. Rows are numbered 1 to R from top to bottom and columns are numbered 1 to C from left to right. Cells with A[i][j] < 0 contain poison, others contain magic juice.
Output format:
Output T lines, one for each case containing the minimum strength you should start with from the cell (1,1) to have a positive strength through out his journey to the cell (R,C).
Constraints:
1 ≤ T ≤ 5
2 ≤ R, C ≤ 500
-10^3 ≤ A[i][j] ≤ 10^3
A[1][1] = A[R][C] = 0
Time Limit: 1 second
Sample Input 1:
3
2 3
0 1 -3
1 -2 0
2 2
0 1
2 0
3 4
0 -2 -3 1
-1 4 0 -2
1 -2 -3 0
Sample Output 1:
2
1
2
*/

#include<bits/stdc++.h>
using namespace std;

int answer (int** grid, int ei, int ej, int si, int sj, int** hm) {
    if(ei==si&&sj==ej){
        return 1;
    }
    if(si>ei||sj>ej){
        return INT_MAX;
    }
    
    int option1, option2;
    if(hm[si+1][sj]>0){
        option1 = hm[si+1][sj]; 
    }
    else {
        option1 = answer(grid, ei, ej, si+1, sj, hm);
        hm[si+1][sj] = option1;
    }

    if(hm[si][sj+1]>0){
        option2 = hm[si][sj+1];
    }
    else {
        option2 = answer(grid, ei, ej, si, sj+1, hm);
        hm[si][sj+1] = option2;
    }

    // cout<<si<<" "<<sj<<" "<<min(option1, option2)<<endl;
    int ans = min(option1, option2) - grid[si][sj];

    if(ans<=0)
        return 1;
    return ans;
}


int getMinimumStrength(int** grid,int n,int m){
    int **hm = new int *[n+1];

        for (int i = 0; i < n+1; ++i) {
            hm[i] = new int[m+1];
            for (int j = 0; j < m+1; ++j) {
                hm[i][j] = -1;
            }
        }
    int ans = answer(grid,n-1,m-1,0,0,hm);
    for(int i=0;i<n+1;i++)
        delete[] hm[i];
    delete[] hm;
    // cout<<"AsdASD"<<endl<<endl;
    // for (int i = 0; i < n+1; ++i) {
    //         for (int j = 0; j < m+1; ++j) {
    //             cout<<hm[i][j]<<" ";
    //         }
    //         cout<<endl;
    //     }
    //     cout<<endl;
    return ans;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
        int **grid = new int *[n];

        for (int i = 0; i < n; ++i) {
            grid[i] = new int[m];
            for (int j = 0; j < m; ++j) {
                cin >> grid[i][j];
            }
        }

        cout << getMinimumStrength(grid, n, m) << "\n";

        for (int i = 0; i < n; ++i) {
            delete[] grid[i];
        }

        delete[] grid;
    }
}