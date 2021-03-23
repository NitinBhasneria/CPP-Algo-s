/*
Miser Man
Send Feedback
Jack is a wise and miser man. Always tries to save his money.
One day, he wants to go from city A to city B. Between A and B, there are N number of cities(including B and excluding A) and in each city there are M buses numbered from 1 to M. And the fare of each bus is different. Means for all N*M busses, fare (K) may be different or same. Now Jack has to go from city A to city B following these conditions:
1. At every city, he has to change the bus.
2. And he can switch to only those buses which have number either equal or 1 less or 1 greater to the previous.
You are to help Jack to go from A to B by spending the minimum amount of money.
N, M, K <= 100.
Input
Line 1:    N M

Line 2:    NxM Grid

Each row lists the fares the M busses to go form the current city to the next city.
Output
Single Line containing the minimum amount of fare that Jack has to give.
Sample Input
5 5
1  3  1  2  6
10 2  5  4  15
10 9  6  7  1
2  7  1  5  3
8  2  6  1  9
Sample Output
10
Explanation:
1 -> 4 -> 1 -> 3 -> 1: 10
This is marked and shown in the following image: 
*/

#include<bits/stdc++.h>
using namespace std;

int solve(int** arr, int n, int m, int si, int sj, int** dp){
    if(si<0||sj<0){
        return INT_MAX;
    }
    if(si==n)
        return 0;
    if(sj == m)   
        return INT_MAX;
    if(dp[si][sj]!=-1)
        return dp[si][sj];
    int ans;
    int option1 = solve(arr, n, m, si+1, sj-1, dp);

    int option2 = solve(arr, n, m, si+1, sj, dp);

    int option3 = solve(arr, n, m, si+1, sj+1, dp);

    int O5 = min(option1, min(option2, option3));

    O5 += arr[si][sj];

    ans = O5;
    dp[si][sj] = ans;
    return ans;
}

int miser(int** arr, int n, int m){
    int** dp = new int*[n+1];
    for(int i=0;i<n+1;i++){
        dp[i] = new int[m+1];
        for(int j=0;j<m+1;j++){
            dp[i][j] = -1;
        }
    }
    int ans = INT_MAX;
    for(int i=0;i<n;i++){
        int ans2 = solve(arr, n, m, 0, i, dp);
        if(ans2<ans) ans = ans2;
    }    
    return ans;
}

int main() {
    int n, m;
    cin>>n>>m;
    int** arr = new int*[n];
    for(int i=0;i<n;i++){
        arr[i] = new int[m];
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    cout<<miser(arr, n, m);
    for(int i=0;i<n;i++){
        delete[] arr[i];
    }
    delete arr;

    return 0;
}