/*
Square Brackets
Send Feedback
You are given:
a positive integer n,
an integer k, 1<=k<=n,
an increasing sequence of k integers 0 < s1 < s2 < ... < sk <= 2n.
What is the number of proper bracket expressions of length 2n with opening brackets appearing in positions s1, s2,...,sk?
Illustration
Several proper bracket expressions:
[[]][[[]][]] 
[[[][]]][][[]]
An improper bracket expression:
[[[][]]][]][[]]
There is exactly one proper expression of length 8 with opening brackets in positions 2, 5 and 7.
Task
Write a program which for each data set from a sequence of several data sets:
1. reads integers n, k and an increasing sequence of k integers from input,
2. computes the number of proper bracket expressions of length 2n with opening brackets appearing at positions s1,s2,...,sk,
3. writes the result to output.
Input
The first line of the input file contains one integer d, 1 <= d <= 10, which is the number of data sets. The data sets follow. Each data set occupies two lines of the input file. The first line contains two integers n and k separated by single space, 1 <= n <= 19, 1 <= k <= n. The second line contains an increasing sequence of k integers from the interval [1;2n] separated by single spaces.
Output
The i-th line of output should contain one integer - the number of proper bracket expressions of length 2n with opening brackets appearing at positions s1, s2,...,sk.
Sample Input
5 
1 1 
1 
1 1 
2 
2 1 
1 
3 1 
2 
4 2 
5 7 
Sample Output
1 
0 
2 
3 
2 
*/
#include<bits/stdc++.h>
using namespace std;

int solve2 (int n, bool* pos, int x, int** dp, int curr){
    if(dp[n][x] != -1){ 
        return dp[n][x];
    }
    if(x==0&&n==0){
        // cout<<"true"<<" "<<n<<" "<<x<<endl;
        return 1;
    }
    if(x!=0&&n==0){

        // cout<<"false"<<" "<<n<<" "<<x<<endl;
        return 0;
    }
    if(pos[curr]==1 || x<=0){
        //  cout<<n<<" "<<x<<endl;
        return solve2(n-1, pos, x+1, dp, curr+1);
    }
    // cout<<n<<" as "<<x<<endl;
    int option1 = solve2(n-1, pos, x-1, dp, curr+1);

    int option2 = solve2(n-1, pos, x+1, dp, curr+1);
    
    int ans = option1 + option2;
    // cout<<option1<<" a "<<option2<<endl;
    dp[n][x] = ans;

    return ans;
}

int solve(int n, bool* pos){
    int** dp = new int*[n+1];
    for(int i=0;i<=n;i++){
        dp[i] = new int[n+1];
        for(int j=0;j<=n;j++){
            dp[i][j] = -1;
        }
    }
    int x = 0; //differnce of opening ans closing bracket
    int ans = solve2(n, pos, x, dp, 0);
    for(int i=0;i<=n;i++){
        delete[] dp[i];
    }
    delete[] dp;
    return ans;
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n, k;
        cin>>n>>k;
        int* s = new int[k];
        bool pos[2*n+1] = {0};
        for(int i=0;i<k;i++){
            cin>>s[i];
            pos[s[i]-1] = true;
        }
        cout<<solve(2*n, pos)<<endl;

        delete[] s;
    }
}