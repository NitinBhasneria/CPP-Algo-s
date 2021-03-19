/*
Knapsnack - Problem
Send Feedback
A thief is robbing a store and can carry a maximal weight of W into his knapsack. There are N items and ith item weighs wi and is of value vi. Considering the constraints of maximum weight that knapsack can carry, you have to find and return the maximum value that thief can generate by stealing items.
Note
Space complexity should be O(W).
Input Format :
The first line contains an integers, that denote the value of N. The following line contains N space separated integers, that denote the values of weight of items. The following line contains N space separated integers, that denote the values associated with the items. The following line contains an integer that denote the value of W. W denotes maximum weight that thief can carry.
Output Format :
The first and only line of output contains the maximum value that thief can generate, as described in the task. 
Constraints
1 <= N <= 10^4
1<= wi <= 100
1 <= vi <= 100
Time Limit: 1 second
Sample Input 1 :
4
1 2 4 5
5 4 8 6
5
Sample Output 1 :
13
*/

#include<bits/stdc++.h>
using namespace std;

int solve (int* weight, int* value, int n, int maxWeight, int** dp) {
    if(n==0) 
        return 0;
    if(maxWeight < 0)   
        return 0;
    if(dp[n][maxWeight] > -1)   
        return dp[n][maxWeight];
    int ans;
    // cout<<n<<" \n";
    
    int option1 = 0;
    if((maxWeight - weight[n-1]) >= 0)
        option1 = value[n-1] + solve(weight, value, n-1,  maxWeight-weight[n-1], dp);
    int option2 = solve(weight, value, n-1, maxWeight, dp);
    // cout<<option1<<" "<<option2<<endl;   
    ans = max(option1, option2);
    dp[n][maxWeight] = ans;
    return ans;
}

int knapsack(int* weight, int* value, int n, int maxWeight) {
	// Write your code here
    int** dp = new int*[n+1];
    for(int i=0;i<=n;i++){
        dp[i] = new int[maxWeight];
        for(int j=0;j<=maxWeight;j++)
            dp[i][j] = -1;
    } 
    int ans = solve(weight, value, n, maxWeight, dp);
    // for(int i=0;i<=n;i++){
    //     // dp[i] = new int[maxWeight];
    //     for(int j=0;j<=maxWeight;j++)
    //         cout<<dp[i][j]<<" ";
    //     cout<<endl;
    // } 
    for(int i=0;i<=n;i++){
        delete [] dp[i];
    } 
    delete[] dp;
    return ans;
}

int main() {
    int n;
    cin >> n;
    int* wt = new int[n];
    int* val = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> wt[i];
    }

    for (int j = 0; j < n; j++) {
        cin >> val[j];
    }

    int w;
    cin >> w;

    cout << knapsack(wt, val, n, w) << "\n";

    delete[] wt;
    delete[] val;
}