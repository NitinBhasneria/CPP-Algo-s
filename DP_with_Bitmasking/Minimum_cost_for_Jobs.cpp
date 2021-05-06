#include<bits/stdc++.h>
using namespace std;

int minCost(int cost[4][4], int n, int p, int mask, int* dp) {
     if(p>=n){
         return 0;
     }

     if(dp[mask]!=INT_MAX){
         return dp[mask];
     }
     int min = INT_MAX;
     for(int j=0;j<n;j++) {
         if(!(mask&(1<<j))){
            int ans = minCost(cost, n, p+1, (mask|(1<<j)), dp) + cost[p][j];
            if(ans<min) {
                min = ans;
            }
         }
     }
     dp[mask] = min;
     return min;
}

int main() {
    int cost[4][4] = {{10,2,6,5}, {1,15,12,8},{7,8,9,3},{15,13,4,10}};
    int* dp = new int[1<<4];
    for(int i=0;i<(1<<4);i++) {
        dp[i] = INT_MAX;
    }
    cout<<minCost(cost,4,0,0,dp)<<endl;
    return 0;
}